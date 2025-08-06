#include "mavlink_mission.h"
#include "math.h"
#include "mathlib/mathlib.h"
#include "mavlink_main.h"
#include <stdio.h>
#include <math.h>
#include "geo/geo.h"
#include "hrt/hrt.h"
#include "print/print.h"
#include "../dataman/dataman.h"
#include "topics/mission.h"
#include "topics/mission_result.h"
#include "../navigator/navigator_main.h"

/* oddly, ERROR is not defined for c++ */
#ifdef ERROR
# undef ERROR
#endif
static const int ERROR = -1;

typedef enum MAV_AIRLINE_RESULT
{
	MAV_AIRLINE_ACTIVE_OK = 20, /*  */		
	MAV_AIRLINE_ACTIVE_FAILED = 30, /**/

	
	MAV_AIRLINE_UPLOAD_OK = 40, /**/	
	MAV_AIRLINE_UPLOAD_FAILED = 50, /**/
	
	MAV_AIRLINE_DELETE_OK = 60, /**/	
	MAV_AIRLINE_DELETE_FAILED = 61, /**/
	
	MAV_AIRLINE_ACTIVE_CLEAR_OK = 70,
	MAV_AIRLINE_ACTIVE_CLEAR_FAILED = 71
	
} MAV_AIRLINE_RESULT;

#define CHECK_SYSID_COMPID_MISSION(_msg) true //航线装载、激活指令广播发送至所有飞机

MavlinkMissionManager::MavlinkMissionManager(Mavlink *mavlink) : MavlinkStream(mavlink),
	_state(MAVLINK_WPM_STATE_IDLE),
	_airline_state(MAVLINK_WPM_STATE_IDLE),
	_time_last_recv(0),
	_time_last_sent(0),
	_action_timeout(MAVLINK_MISSION_PROTOCOL_TIMEOUT_DEFAULT),
	_retry_timeout(MAVLINK_MISSION_RETRY_TIMEOUT_DEFAULT),
	_max_count(DM_KEY_WAYPOINTS_OFFBOARD_0_MAX),
	_dataman_id(0),
	_count(0),
	_current_seq(0),
	_transfer_dataman_id(0),
	_transfer_count(0),
	_transfer_seq(0),
	_transfer_current_seq(0),
	_transfer_partner_sysid(0),
	_transfer_partner_compid(0),
	_transfer_airline_index(0),
	_transfer_airline_id (0),
	_transfer_airline_seq(0),
	_transfer_airline_count(0),
	_transfer_airline_sysid(0),
	_transfer_airline_compid(0),
   	_offboard_mission_sub(-1),
	_mission_result_sub(-1),
	_offboard_mission_pub(nullptr),
	_verbose(true)
	
{
	set_verbose(1);
    memset(_store_airline, 0, sizeof(struct air_line) * MAVLINK_AIRLINE_MAX );
    for(uint8_t id = 0; id < MAVLINK_AIRLINE_MAX; id++ )
    {
        _store_airline[id].id = id;
    }
   
 	//_offboard_mission_sub = orb_subscribe(ORB_ID(offboard_mission));
	_mission_result_sub = orb_subscribe(ORB_ID(mission_result));
  
	init_offboard_mission();
}

MavlinkMissionManager::~MavlinkMissionManager()
{

}

void
MavlinkMissionManager::init_offboard_mission()
{
	mission_s mission_state;
	if (dm_read(DM_KEY_MISSION_STATE, 0, &mission_state, sizeof(mission_s)) == sizeof(mission_s)) {
		_dataman_id = mission_state.dataman_id;
		_count = mission_state.count;
		_current_seq = mission_state.current_seq;

	} else {
		_dataman_id = 0;
		_count = 0;
		_current_seq = 0;
		warn_vx("offboard mission init: ERROR..");
	}

    struct airline_s airline_state;

    for(uint8_t inx = 0; inx < MAVLINK_AIRLINE_MAX; inx++ )
    {   
         
        if (dm_read(DM_KEY_AIRLINE_STATE, inx, &airline_state, sizeof(struct airline_s)) == sizeof(struct airline_s)) 
        {
           _store_airline[inx].id     = airline_state.dataman_store_id;
           _store_airline[inx].active = airline_state.active;
           _store_airline[inx].count  = airline_state.count;
           _store_airline[inx].cmd    = airline_state.cmd;
           if(airline_state.count > 0)
              _store_airline[inx].upload = MAVLINK_AIRLINE_STATE_STORED;  /*航线存在*/
           else            
             _store_airline[inx].upload = MAVLINK_AIRLINE_STATE_IDLE;  /*航线不存在*/
        }
        else 
        {

            warn_vx("读取航线第%u条信息失败",inx);
             _store_airline[inx].id     = inx;
             _store_airline[inx].upload  = MAVLINK_AIRLINE_STATE_IDLE;
        }
    }
    
}

/**
 * Write new mission state to dataman and publish offboard_mission topic to notify navigator about changes.
 */
int
MavlinkMissionManager::update_active_mission(int dataman_id, unsigned count, int seq,int active)
{
    struct mission_s mission;

    if (dm_read(DM_KEY_MISSION_STATE, 0, &mission, sizeof(mission_s)) == sizeof(mission_s)) 
    {
	    mission.dataman_id = dataman_id;
	    mission.count = count;
	    mission.current_seq = seq;
	    
	    warn_vx("[update_active] offboard mission init: success");
    }
    else 
    {
	    mission.dataman_id = dataman_id;
	    mission.count = 0;
	    mission.current_seq = 0;
	    warn_vx("[update_active] offboard mission init: ERROR");
    }


    switch(active)
    {
    case MAVLINK_CMD_NAV_MC_ACTIVE:	
	case MAVLINK_CMD_ACTIVE_GROUP:
        mission.takeoff_active = true;    
        mission.nav_active = true; 
        mission.land_active = true;
        break;
    case MAVLINK_CMD_NAV_TAKEOFF:
        mission.takeoff_active = true;
        break;
    case MAVLINK_CMD_NAV_WAYPOINT:
        mission.nav_active = true;
        break;
    case MAVLINK_CMD_NAV_LAND:
        mission.land_active = true;
        break;
      case MAVLINK_CMD_IDLE:
        mission.takeoff_active = false;    
        mission.nav_active = false; 
        mission.land_active = false;
        break;
    }
	/* update mission state in dataman */
	int res = dm_write(DM_KEY_MISSION_STATE, 0, DM_PERSIST_POWER_ON_RESET, &mission, sizeof(mission_s));

	if (res == sizeof(mission_s)) 
    {
		/* update active mission state */
		_dataman_id = mission.dataman_id;
		_count = mission.count ;
		_current_seq = mission.current_seq;
		
		/* mission state saved successfully, publish offboard_mission topic */
		if (_offboard_mission_pub == nullptr) {
			_offboard_mission_pub = orb_advertise(ORB_ID(offboard_mission), &mission);
		
		} else {
		if (_verbose) warn_vx("takeoff= %u, nav =%u , land =%u",(int)mission.takeoff_active,(int)mission.nav_active,(int)mission.land_active);
			orb_publish(ORB_ID(offboard_mission), _offboard_mission_pub, &mission);
		}
        _mavlink->send_statustext(MAV_SEVERITY_INFO, "save mission state");
		return OK;

	} 
    else
    {
		warn_vx("ERROR: can't save mission state");
		_mavlink->send_statustext(MAV_SEVERITY_CRITICAL, "ERROR: can't save mission state");

		return ERROR;
	}
}

void
MavlinkMissionManager::send_mission_ack(uint8_t sysid, uint8_t compid, uint8_t type)
{
	mavlink_mission_ack_t wpa;

	wpa.target_system = sysid;
	wpa.target_component = compid;
	wpa.type = type;

	_mavlink->send_message(MAVLINK_MSG_ID_MISSION_ACK, &wpa);

	if (_verbose) { warn_vx("**********WPM: Send MISSION_ACK type %u to ID %u**********", wpa.type, wpa.target_system); }
}


void
MavlinkMissionManager::send_mission_current(uint16_t seq)
{
	if (seq < _count)
    {
		mavlink_mission_current_t wpc;

		wpc.seq = seq;

		_mavlink->send_message(MAVLINK_MSG_ID_MISSION_CURRENT, &wpc);

	} else if (seq == 0 && _count == 0) {
		/* don't broadcast if no WPs */

	} else {
		if (_verbose) { warn_vx("WPM: Send MISSION_CURRENT ERROR: seq %u out of bounds", seq); }

		_mavlink->send_statustext_critical("ERROR: wp index out of bounds");
	}
}


void
MavlinkMissionManager::send_mission_count(uint8_t sysid, uint8_t compid, uint16_t count)
{
	_time_last_sent = hrt_absolute_time();

	mavlink_mission_count_t wpc;

	wpc.target_system = sysid;
	wpc.target_component = compid;
	wpc.count = _count;

	_mavlink->send_message(MAVLINK_MSG_ID_MISSION_COUNT, &wpc);

	if (_verbose) { warn_vx("----Send MISSION_COUNT %u to ID %u----", wpc.count, wpc.target_system); }
}


void
MavlinkMissionManager::send_mission_item(uint8_t sysid, uint8_t compid, uint16_t seq)
{
	dm_item_t dm_item = DM_KEY_MISSION_WAYPOINTS(_dataman_id);
	struct mission_item_s mission_item;

	if (dm_read(dm_item, seq, &mission_item, sizeof(struct mission_item_s)) == sizeof(struct mission_item_s)) {
		_time_last_sent = hrt_absolute_time();

		/* create mission_item_s from mavlink_mission_item_t */
		mavlink_mission_item_t wp;
		format_mavlink_mission_item(&mission_item, &wp); //进行航点数据的处理

		wp.target_system = sysid;
		wp.target_component = compid;
		wp.seq = seq;
		wp.current = (_current_seq == seq) ? 1 : 0;

		_mavlink->send_message(MAVLINK_MSG_ID_MISSION_ITEM, &wp);

		if (_verbose) { warn_vx("----Send MISSION_ITEM seq %u to ID %u----", wp.seq, wp.target_system); }

	} else {
		send_mission_ack(_transfer_partner_sysid, _transfer_partner_compid, MAV_MISSION_ERROR);
		_mavlink->send_statustext_critical("Unable to read from micro SD");

		if (_verbose) { warn_vx("----Send MISSION_ITEM ERROR: could not read seq %u from dataman ID %i----", seq, _dataman_id); }
	}
}


void
MavlinkMissionManager::send_mission_request(uint8_t sysid, uint8_t compid, uint16_t seq)
{
	if (seq < _max_count) {
		_time_last_sent = hrt_absolute_time();

		mavlink_mission_request_t wpr;
		wpr.target_system = sysid;
		wpr.target_component = compid;
		wpr.seq = seq;

		_mavlink->send_message(MAVLINK_MSG_ID_MISSION_REQUEST, &wpr);

		if (_verbose) { warn_vx("WPM: Send MISSION_REQUEST seq %u to ID %u", wpr.seq, wpr.target_system); }

	} else {
		_mavlink->send_statustext_critical("ERROR: Waypoint index exceeds list capacity");

		if (_verbose) { warn_vx("WPM: Send MISSION_REQUEST ERROR: seq %u exceeds list capacity", seq); }
	}
}


void
MavlinkMissionManager::send_mission_item_reached(uint16_t seq)
{
	mavlink_mission_item_reached_t wp_reached;

	wp_reached.seq = seq;

	_mavlink->send_message(MAVLINK_MSG_ID_MISSION_ITEM_REACHED, &wp_reached);

	if (_verbose) { warn_vx("WPM: Send MISSION_ITEM_REACHED reached_seq %u", wp_reached.seq); }
}


void
MavlinkMissionManager::send(const hrt_abstime now)
{
	

	//TODO：后续"目标航点编号"放在下行遥测信息中发出
	bool updated = false;
	orb_check(_mission_result_sub, &updated);

	if (updated) {
		mission_result_s mission_result;
		orb_copy(ORB_ID(mission_result), _mission_result_sub, &mission_result);

		_current_seq = mission_result.seq_current;

		if (_verbose) { warn_vx("WPM: got mission result, new current_seq: %d", _current_seq); }

		if (mission_result.reached) {
			send_mission_item_reached((uint16_t)mission_result.seq_reached);
		}

		send_mission_current(_current_seq);

		if (mission_result.item_do_jump_changed) {
			/* send a mission item again if the remaining DO_JUMPs has changed */
			send_mission_item(_transfer_partner_sysid, _transfer_partner_compid,
					  (uint16_t)mission_result.item_changed_index);
		}

	}

	/* check for timed-out operations */
	if (_state != MAVLINK_WPM_STATE_IDLE && hrt_elapsed_time(&_time_last_recv) > _action_timeout) 
	 {
		_mavlink->send_statustext_critical("mission Operation timeout");

		if (_verbose) { warn_vx("mission: Last operation (state=%u) timed out, changing state to MAVLINK_WPM_STATE_IDLE", _state); }

		_state = MAVLINK_WPM_STATE_IDLE;

	}
    else if (_state == MAVLINK_WPM_STATE_GETLIST && hrt_elapsed_time(&_time_last_sent) > _retry_timeout) 
    {
		/* try to request item again after timeout */
		send_mission_request(_transfer_partner_sysid, _transfer_partner_compid, _transfer_seq);

	} 
    else if (_state == MAVLINK_WPM_STATE_SENDLIST && hrt_elapsed_time(&_time_last_sent) > _retry_timeout) 
    {
		if (_transfer_seq == 0) 
        {
			/* try to send items count again after timeout */
			send_mission_count(_transfer_partner_sysid, _transfer_partner_compid, _transfer_count);

		} else {
			/* try to send item again after timeout */
			send_mission_item(_transfer_partner_sysid, _transfer_partner_compid, _transfer_seq - 1);
		}
	}

	
    /* airline条目的超时操作 */
	if (_airline_state != MAVLINK_WPM_STATE_IDLE && hrt_elapsed_time(&_time_last_recv) > _action_timeout) 
	{
		_mavlink->send_statustext_critical("airline Operation timeout");

		if (_verbose) { warn_vx("airline: Last operation (state=%u) timed out, changing state to MAVLINK_WPM_STATE_IDLE", _airline_state); }

		_airline_state = MAVLINK_WPM_STATE_IDLE;

	}
	else if (_airline_state == MAVLINK_WPM_STATE_GETLIST && hrt_elapsed_time(&_time_last_sent) > _retry_timeout) 
	{
		/* try to request item again after timeout */
		send_airline_request(_transfer_airline_sysid, _transfer_airline_compid, _transfer_airline_id, _transfer_airline_seq);

	} 
	#if 0
	else if (_airline_state == MAVLINK_WPM_STATE_SENDLIST && hrt_elapsed_time(&_time_last_sent) > _retry_timeout)
	{

		if (_transfer_airline_seq == 0) {
			/* try to send items count again after timeout */
			send_airline_info(_transfer_airline_sysid, _transfer_airline_compid);
			
		} else {
			/* try to send item again after timeout */
			send_airline_item(_transfer_airline_sysid, _transfer_airline_compid, _transfer_airline_id, _transfer_airline_seq -1);
		}

	} 
    #endif
}


void
MavlinkMissionManager::handle_message(const mavlink_message_t *msg)
{
	switch (msg->msgid) 
	{
	/* 最终飞行任务 */
	case MAVLINK_MSG_ID_MISSION_ACK:
		handle_mission_ack(msg);
		break;
	case MAVLINK_MSG_ID_MISSION_SET_CURRENT:
		handle_mission_set_current(msg);
		break;
	case MAVLINK_MSG_ID_MISSION_REQUEST_LIST: //请求任务信息-【大表】：获得任务航点数 -->后续由地面站再次请求任务航点
		printf_vx("handle_mission_request_list\n");
		handle_mission_request_list(msg);
		break;

	case MAVLINK_MSG_ID_MISSION_REQUEST: //请求任务航点信息 
		printf_vx("handle_mission_request\n");
		handle_mission_request(msg);
		break;
		
	case MAVLINK_MSG_ID_MISSION_COUNT:
		handle_mission_count(msg);
		break;

	case MAVLINK_MSG_ID_MISSION_ITEM:
		handle_mission_item(msg);
		break;

	case MAVLINK_MSG_ID_MISSION_CLEAR_ALL:
		handle_mission_clear_all(msg);
		break;

        /*暂时不用*/
	case 191://MAVLINK_MSG_ID_MISSION_SET_LINE_CURRENT:
		//handle_mission_set_current(msg);    
		break;
	case MAVLINK_MSG_ID_AIRLINE_REQUEST_LIST:  /*请求航线信息-【大表】：前飞航线、任务区域、降落区域 */
		printf_vx("请求航线信息表--%d\n",MAVLINK_MSG_ID_AIRLINE_REQUEST_LIST);
		handle_airline_request_list(msg);
		break;

	case MAVLINK_MSG_ID_AIRLINE_REQUEST:   /*请求航线上的航点信息 */
		printf_vx("航点信息请求--%d\n",MAVLINK_MSG_ID_AIRLINE_REQUEST);
		handle_airline_request(msg);        
		break;

	case MAVLINK_MSG_ID_AIRLINE_INFO:   /*需要装订的航线信息， 任务机回应航线获取请求*/
		printf_vx("装订航线信息--%d\n",MAVLINK_MSG_ID_AIRLINE_INFO);
		handle_airline_info(msg);
		break;

	case MAVLINK_MSG_ID_AIRLINE_ITEM:  /*需要装订的航线上的航路点信息*/
		printf_vx("航点信息--%d\n",MAVLINK_MSG_ID_AIRLINE_ITEM);
		handle_airline_item(msg);
		break;

	case MAVLINK_MSG_ID_AIRLINE_CLEAR:  /*根据参数清除航线状态【也会清除任务状态】*/
		printf_vx("清除航线--%d\n",MAVLINK_MSG_ID_AIRLINE_CLEAR);
		handle_airline_clear(msg);
		break;
		
    case MAVLINK_MSG_ID_AIRLINE_ACTIVE:  /*激活航线*/
		printf_vx("激活航线--%d\n",MAVLINK_MSG_ID_AIRLINE_ACTIVE);
    	handle_airline_active(msg);
        break;

	default:
		break;
	}
}


void
MavlinkMissionManager::handle_mission_ack(const mavlink_message_t *msg)
{
	mavlink_mission_ack_t wpa;
	mavlink_msg_mission_ack_decode(msg, &wpa);

	if (CHECK_SYSID_COMPID_MISSION(wpa)) 
    {
		if ((msg->sysid == _transfer_partner_sysid && msg->compid == _transfer_partner_compid)) 
        {
			if (_state == MAVLINK_WPM_STATE_SENDLIST) 
            {
				_time_last_recv = hrt_absolute_time();

				if (_transfer_seq == _count) 
                {
					if (_verbose) { warn_vx("WPM: MISSION_ACK OK all items sent, switch to state IDLE"); }

				} 
                else 
			    {
					_mavlink->send_statustext_critical("WPM: ERR: not all items sent -> IDLE");

					if (_verbose) { warn_vx("WPM: MISSION_ACK ERROR: not all items sent, switch to state IDLE anyway"); }
				}

				_state = MAVLINK_WPM_STATE_IDLE;
			}

            if (_airline_state == MAVLINK_WPM_STATE_SENDLIST) 
            {
				_time_last_recv = hrt_absolute_time();

				_airline_state = MAVLINK_WPM_STATE_IDLE;
			}

		}
        else 
        {
		
			_mavlink->send_statustext_critical("REJ. WP CMD: partner id mismatch");

			if (_verbose) { warn_vx("WPM: MISSION_ACK ERROR: rejected, partner ID mismatch"); }
		}
	}
}


void
MavlinkMissionManager::handle_mission_set_current(const mavlink_message_t *msg)
{
	mavlink_mission_set_current_t wpc;
	mavlink_msg_mission_set_current_decode(msg, &wpc);

	if (CHECK_SYSID_COMPID_MISSION(wpc)) {
		if (_state == MAVLINK_WPM_STATE_IDLE) {
			_time_last_recv = hrt_absolute_time();

			if (wpc.seq < _count) {
				if (update_active_mission(_dataman_id, _count, wpc.seq) == OK) {
					if (_verbose) { warn_vx("WPM: MISSION_SET_CURRENT seq=%d OK", wpc.seq); }
                    char ss[48];  
                    sprintf(ss,"WPM: MISSION_SET_CURRENT seq=%d OK", wpc.seq);
                    _mavlink->send_statustext_critical(ss);
                    
				} else {
					if (_verbose) { warn_vx("WPM: MISSION_SET_CURRENT seq=%d ERROR", wpc.seq); }
                   	_mavlink->send_statustext_critical("WPM: WP CURR CMD: Error setting ID");
				}

			} else {
				if (_verbose) { warn_vx("WPM: MISSION_SET_CURRENT seq=%d ERROR: not in list", wpc.seq); }

				_mavlink->send_statustext_critical("WPM: WP CURR CMD: Not in list");
			}

		} else {
			if (_verbose) { warn_vx("WPM: MISSION_SET_CURRENT ERROR: busy"); }

			_mavlink->send_statustext_critical("WPM: IGN WP CURR CMD: Busy");
		}
	}
}


void
MavlinkMissionManager::handle_mission_request_list(const mavlink_message_t *msg)
{
	mavlink_mission_request_list_t wprl;
	mavlink_msg_mission_request_list_decode(msg, &wprl);

	if (CHECK_SYSID_COMPID_MISSION(wprl)) {
		if (_state == MAVLINK_WPM_STATE_IDLE || _state == MAVLINK_WPM_STATE_SENDLIST) {
			_time_last_recv = hrt_absolute_time();

			if (_count > 0) {
				_state = MAVLINK_WPM_STATE_SENDLIST;
				_transfer_seq = 0;
				_transfer_count = _count;
				_transfer_partner_sysid = msg->sysid;
				_transfer_partner_compid = msg->compid;

				if (_verbose) { warn_vx("WPM: MISSION_REQUEST_LIST OK, %u mission items to send", _transfer_count); }

			} else {
				if (_verbose) { warn_vx("WPM: MISSION_REQUEST_LIST OK nothing to send, mission is empty"); }

				_mavlink->send_statustext_info("WPM: mission is empty");
			}

			send_mission_count(msg->sysid, msg->compid, _count);

		} else {
			if (_verbose) { warn_vx("WPM: MISSION_REQUEST_LIST ERROR: busy"); }

			_mavlink->send_statustext_critical("IGN REQUEST LIST: Busy");
		}
	}
}


void
MavlinkMissionManager::handle_mission_request(const mavlink_message_t *msg)
{
	mavlink_mission_request_t wpr;
	mavlink_msg_mission_request_decode(msg, &wpr);

	if (CHECK_SYSID_COMPID_MISSION(wpr)) {
		if (msg->sysid == _transfer_partner_sysid && msg->compid == _transfer_partner_compid) {
			if (_state == MAVLINK_WPM_STATE_SENDLIST) {
				_time_last_recv = hrt_absolute_time();
				
				//printf_vx("----wpr.seq = %d----\n", wpr.seq);
				
				/* _transfer_seq contains sequence of expected request */
				if (wpr.seq == _transfer_seq && _transfer_seq < _transfer_count) {
					if (_verbose) { warn_vx("WPM: MISSION_ITEM_REQUEST seq %u from ID %u", wpr.seq, msg->sysid); }

					_transfer_seq++;

				} else if (wpr.seq == _transfer_seq - 1) {
					if (_verbose) { warn_vx("WPM: MISSION_ITEM_REQUEST seq %u from ID %u (again)", wpr.seq, msg->sysid); }

				} else {
					if (_transfer_seq > 0 && _transfer_seq < _transfer_count) {
						if (_verbose) { warn_vx("WPM: MISSION_ITEM_REQUEST ERROR: seq %u from ID %u unexpected, must be %i or %i", wpr.seq, msg->sysid, _transfer_seq - 1, _transfer_seq); }

					} else if (_transfer_seq <= 0) {
						if (_verbose) { warn_vx("WPM: MISSION_ITEM_REQUEST ERROR: seq %u from ID %u unexpected, must be %i", wpr.seq, msg->sysid, _transfer_seq); }

					} else {
						if (_verbose) { warn_vx("WPM: MISSION_ITEM_REQUEST ERROR: seq %u from ID %u unexpected, must be %i", wpr.seq, msg->sysid, _transfer_seq - 1); }
					}

					_state = MAVLINK_WPM_STATE_IDLE;

					send_mission_ack(_transfer_partner_sysid, _transfer_partner_compid, MAV_MISSION_ERROR);
					_mavlink->send_statustext_critical("WPM: REJ. CMD: Req. WP was unexpected");
					return;
				}

				/* double check bounds in case of items count changed */
				if (wpr.seq < _count) {
					send_mission_item(_transfer_partner_sysid, _transfer_partner_compid, wpr.seq); //发送请求的任务航点

				}else{
					if (_verbose) { ("WPM: MISSION_ITEM_REQUEST ERROR: seq %u out of bound [%u, %u]", (unsigned)wpr.seq, (unsigned)wpr.seq, (unsigned)_count - 1); }

					_state = MAVLINK_WPM_STATE_IDLE;

					send_mission_ack(_transfer_partner_sysid, _transfer_partner_compid, MAV_MISSION_ERROR);
					_mavlink->send_statustext_critical("WPM: REJ. CMD: Req. WP was unexpected");
				}

			} else if (_state == MAVLINK_WPM_STATE_IDLE) {
				if (_verbose) { warn_vx("WPM: MISSION_ITEM_REQUEST ERROR: no transfer"); }

				_mavlink->send_statustext_critical("IGN MISSION_ITEM_REQUEST: No active transfer");

			} else { //去除了get_list, 应该不会达到这里
				
				if (_verbose) { warn_vx("WPM: MISSION_ITEM_REQUEST ERROR: busy (state %d)", _state); }

				_mavlink->send_statustext_critical("WPM: REJ. CMD: Busy");
			}

		} else {
			_mavlink->send_statustext_critical("WPM: REJ. CMD: partner id mismatch");

			if (_verbose) { warn_vx("WPM: MISSION_ITEM_REQUEST ERROR: rejected, partner ID mismatch"); }
		}
	}
}


void
MavlinkMissionManager::handle_mission_count(const mavlink_message_t *msg)
{
	mavlink_mission_count_t wpc;
	mavlink_msg_mission_count_decode(msg, &wpc);

	if (CHECK_SYSID_COMPID_MISSION(wpc)) {
		if (_state == MAVLINK_WPM_STATE_IDLE) {
			_time_last_recv = hrt_absolute_time();

			if (wpc.count > _max_count) {
				if (_verbose) { warn_vx("WPM: MISSION_COUNT ERROR: too many waypoints (%d), supported: %d", wpc.count, _max_count); }

				send_mission_ack(_transfer_partner_sysid, _transfer_partner_compid, MAV_MISSION_NO_SPACE);
				return;
			}

			if (wpc.count == 0) {
				if (_verbose) { warn_vx("WPM: MISSION_COUNT 0, clearing waypoints list and staying in state MAVLINK_WPM_STATE_IDLE"); }

				/* alternate dataman ID anyway to let navigator know about changes */
				update_active_mission(_dataman_id == 0 ? 1 : 0, 0, 0);
				_mavlink->send_statustext_info("WPM: COUNT 0: CLEAR MISSION");

				// TODO send ACK?
				return;
			}

			if (_verbose) { warn_vx("WPM: MISSION_COUNT %u from ID %u, changing state to MAVLINK_WPM_STATE_GETLIST", wpc.count, msg->sysid); }

			_state = MAVLINK_WPM_STATE_GETLIST;
			_transfer_seq = 0;
			_transfer_partner_sysid = msg->sysid;
			_transfer_partner_compid = msg->compid;
			_transfer_count = wpc.count;
			_transfer_dataman_id = _dataman_id == 0 ? 1 : 0;	// use inactive storage for transmission
			_transfer_current_seq = -1;

		} else if (_state == MAVLINK_WPM_STATE_GETLIST) {
			_time_last_recv = hrt_absolute_time();

			if (_transfer_seq == 0) {
				/* looks like our MISSION_REQUEST was lost, try again */
				if (_verbose) { warn_vx("WPM: MISSION_COUNT %u from ID %u (again)", wpc.count, msg->sysid); }

				_mavlink->send_statustext_info("WP CMD OK TRY AGAIN");

			} else {
				if (_verbose) { warn_vx("WPM: MISSION_COUNT ERROR: busy, already receiving seq %u", _transfer_seq); }

				_mavlink->send_statustext_critical("WPM: REJ. CMD: Busy");
				return;
			}

		} else {
			if (_verbose) { warn_vx("WPM: MISSION_COUNT ERROR: busy, state %i", _state); }

			_mavlink->send_statustext_critical("WPM: IGN MISSION_COUNT: Busy");
			return;
		}

		send_mission_request(_transfer_partner_sysid, _transfer_partner_compid, _transfer_seq);
	}
}


void
MavlinkMissionManager::handle_mission_item(const mavlink_message_t *msg)
{
	mavlink_mission_item_t wp;
	mavlink_msg_mission_item_decode(msg, &wp);

	if (CHECK_SYSID_COMPID_MISSION(wp)) {
		if (_state == MAVLINK_WPM_STATE_GETLIST) {
			_time_last_recv = hrt_absolute_time();

			if (wp.seq != _transfer_seq) {
				if (_verbose) { warn_vx("WPM: MISSION_ITEM ERROR: seq %u was not the expected %u", wp.seq, _transfer_seq); }

				/* don't send request here, it will be performed in eventloop after timeout */
				return;
			}

		} else if (_state == MAVLINK_WPM_STATE_IDLE) {
			if (_verbose) { warn_vx("WPM: MISSION_ITEM ERROR: no transfer"); }

			_mavlink->send_statustext_critical("IGN MISSION_ITEM: No transfer");
			return;

		} else {
			if (_verbose) { warn_vx("WPM: MISSION_ITEM ERROR: busy, state %i", _state); }

			_mavlink->send_statustext_critical("IGN MISSION_ITEM: Busy");
			return;
		}

		struct mission_item_s mission_item;
		int ret = parse_mavlink_mission_item(&wp, &mission_item);

		if (ret != OK) {
			if (_verbose) { warn_vx("WPM: MISSION_ITEM ERROR: seq %u invalid item", wp.seq); }

			_mavlink->send_statustext_critical("IGN MISSION_ITEM: Busy");

			send_mission_ack(_transfer_partner_sysid, _transfer_partner_compid, ret);
			_state = MAVLINK_WPM_STATE_IDLE;
			return;
		}

		dm_item_t dm_item = DM_KEY_MISSION_WAYPOINTS(_transfer_dataman_id);

		if (dm_write(dm_item, wp.seq, DM_PERSIST_POWER_ON_RESET, &mission_item, sizeof(struct mission_item_s)) != sizeof(struct mission_item_s)) {
			if (_verbose) { warn_vx("WPM: MISSION_ITEM ERROR: error writing seq %u to dataman ID %i", wp.seq, _transfer_dataman_id); }

			send_mission_ack(_transfer_partner_sysid, _transfer_partner_compid, MAV_MISSION_ERROR);
			_mavlink->send_statustext_critical("Unable to write on micro SD");
			_state = MAVLINK_WPM_STATE_IDLE;
			return;
		}

		/* waypoint marked as current */
		if (wp.current) {
			_transfer_current_seq = wp.seq;
		}

		if (_verbose) { warn_vx("WPM: MISSION_ITEM seq %u received", wp.seq); }

		_transfer_seq = wp.seq + 1;

		if (_transfer_seq == _transfer_count) {
			/* got all new mission items successfully */
			if (_verbose) { warn_vx("WPM: MISSION_ITEM got all %u items, current_seq=%u, changing state to MAVLINK_WPM_STATE_IDLE", _transfer_count, _transfer_current_seq); }

			_mavlink->send_statustext_info("WPM: Transfer complete.");

			_state = MAVLINK_WPM_STATE_IDLE;

			if (update_active_mission(_transfer_dataman_id, _transfer_count, _transfer_current_seq) == OK) 
            {
				send_mission_ack(_transfer_partner_sysid, _transfer_partner_compid, MAV_MISSION_ACCEPTED);

			}
            else
			{
				send_mission_ack(_transfer_partner_sysid, _transfer_partner_compid, MAV_MISSION_ERROR);
			}

		}
        else 
		{
			/* request next item */
			send_mission_request(_transfer_partner_sysid, _transfer_partner_compid, _transfer_seq);
		}
	}
}


void
MavlinkMissionManager::handle_mission_clear_all(const mavlink_message_t *msg)
{
	mavlink_mission_clear_all_t wpca;
	mavlink_msg_mission_clear_all_decode(msg, &wpca);

	if (CHECK_SYSID_COMPID_MISSION(wpca)) {

		if (_state == MAVLINK_WPM_STATE_IDLE) {
			/* don't touch mission items storage itself, but only items count in mission state */
			_time_last_recv = hrt_absolute_time();

			if (update_active_mission(_dataman_id == 0 ? 1 : 0, 0, 0) == OK) {
				if (_verbose) { warn_vx("WPM: CLEAR_ALL OK"); }
				send_mission_ack(_transfer_partner_sysid, _transfer_partner_compid, MAV_MISSION_ACCEPTED);

			} else {
				send_mission_ack(_transfer_partner_sysid, _transfer_partner_compid, MAV_MISSION_ERROR);
			}

		} else {
			_mavlink->send_statustext_critical("WPM: IGN CLEAR CMD: Busy");

			if (_verbose) { warn_vx("WPM: CLEAR_ALL IGNORED: busy"); }
		}
	}
}

int
MavlinkMissionManager::parse_mavlink_mission_item(const mavlink_mission_item_t *mavlink_mission_item, struct mission_item_s *mission_item)
{
	/* only support global waypoints for now */
	switch (mavlink_mission_item->frame) {
	case MAV_FRAME_GLOBAL:
		mission_item->lat = (double)mavlink_mission_item->x;
		mission_item->lon = (double)mavlink_mission_item->y;
		mission_item->altitude = mavlink_mission_item->z;
		mission_item->altitude_is_relative = false;
		break;

	case MAV_FRAME_GLOBAL_RELATIVE_ALT:
		mission_item->lat = (double)mavlink_mission_item->x;
		mission_item->lon = (double)mavlink_mission_item->y;
		mission_item->altitude = mavlink_mission_item->z;
		mission_item->altitude_is_relative = true;
		break;

	case MAV_FRAME_LOCAL_NED:
	case MAV_FRAME_LOCAL_ENU:
		return MAV_MISSION_UNSUPPORTED_FRAME;

	case MAV_FRAME_MISSION:
	default:
		return MAV_MISSION_ERROR;
	}

	switch (mavlink_mission_item->command) {
	case MAV_CMD_NAV_TAKEOFF:
		mission_item->pitch_min = mavlink_mission_item->param1;
		break;
	case MAV_CMD_DO_JUMP:
		mission_item->do_jump_mission_index = mavlink_mission_item->param1;
		mission_item->do_jump_current_count = 0;
		mission_item->do_jump_repeat_count = mavlink_mission_item->param2;
		break;
	default:
		mission_item->acceptance_radius = mavlink_mission_item->param2;
		mission_item->time_inside = mavlink_mission_item->param1;
		break;
	}

   if(mavlink_mission_item->frame == MAV_CMD_NAV_WAYPOINT)
  	{
		mission_item->vx = mavlink_mission_item->param4;
   	}
	else
	  mission_item->yaw = _wrap_pi(mavlink_mission_item->param4 * M_DEG_TO_RAD_F);
	
	mission_item->loiter_radius = fabs(mavlink_mission_item->param3);
	mission_item->loiter_direction = (mavlink_mission_item->param3 > 0) ? 1 : -1; /* 1 if positive CW, -1 if negative CCW */
	mission_item->nav_cmd = (NAV_CMD)mavlink_mission_item->command;

	mission_item->autocontinue = mavlink_mission_item->autocontinue;
	// mission_item->index = mavlink_mission_item->seq;
	mission_item->origin = ORIGIN_MAVLINK;

	/* reset DO_JUMP count */
	mission_item->do_jump_current_count = 0;

	//mission_item->flag_attack = fabs(mavlink_mission_item->param1-255)<0.5f ? 1 : 0;
	//mission_item->attack_yaw_deg = mavlink_mission_item->param2;
	//warn_vx("flag_attack[%d], attack_yaw_deg[%.2f] \n", mission_item->flag_attack, (double)mission_item->attack_yaw_deg);

	return MAV_MISSION_ACCEPTED;
}


int
MavlinkMissionManager::format_mavlink_mission_item(const struct mission_item_s *mission_item, mavlink_mission_item_t *mavlink_mission_item)
{
	if (mission_item->altitude_is_relative) {
		mavlink_mission_item->frame = MAV_FRAME_GLOBAL_RELATIVE_ALT;

	} else {
		mavlink_mission_item->frame = MAV_FRAME_GLOBAL;
	}

	switch (mission_item->nav_cmd) {
	case NAV_CMD_TAKEOFF:
		mavlink_mission_item->param1 = mission_item->pitch_min;
		break;

	case NAV_CMD_DO_JUMP:
		mavlink_mission_item->param1 = mission_item->do_jump_mission_index;
		mavlink_mission_item->param2 = mission_item->do_jump_repeat_count - mission_item->do_jump_current_count;
		break;

	default:
		mavlink_mission_item->param2 = mission_item->acceptance_radius;
		mavlink_mission_item->param1 = mission_item->time_inside;
		break;
	}

	mavlink_mission_item->x = (float)mission_item->lat;
	mavlink_mission_item->y = (float)mission_item->lon;
	mavlink_mission_item->z = mission_item->altitude;

	if(mavlink_mission_item->frame == MAV_CMD_NAV_WAYPOINT)
  	{
		mavlink_mission_item->param4 = mission_item->vx;
   	}
	else
		mavlink_mission_item->param4 = mission_item->yaw * M_RAD_TO_DEG_F;
	
	mavlink_mission_item->param3 = mission_item->loiter_radius * (float)mission_item->loiter_direction;
	mavlink_mission_item->command = mission_item->nav_cmd;
	mavlink_mission_item->autocontinue = mission_item->autocontinue;
	
	return OK;
}

int
MavlinkMissionManager::update_airline_state(int index, int airline_id, unsigned count, int active, int cmd)
{
	struct airline_s airline_state;

    if(airline_id < 0 || airline_id >= MAVLINK_AIRLINE_MAX || airline_id >= DM_KEY_AIRLINE_STATE_MAX) 
    {
        return ERROR;
    }
    
	airline_state.dataman_store_id = airline_id;
	airline_state.count = count;
    airline_state.active = active;
    airline_state.cmd = cmd;

	/* update mission state in dataman */
	int res = dm_write(DM_KEY_AIRLINE_STATE, index, DM_PERSIST_POWER_ON_RESET, &airline_state, sizeof(struct airline_s));

	if (res == sizeof(airline_s)) 
	{
		/* update active mission state */
		_store_airline[index].id = airline_id;
		_store_airline[index].count = count;
		_store_airline[index].active = active;
		 _store_airline[index].cmd = cmd;
		_mavlink->send_statustext(MAV_SEVERITY_INFO, "save airline state");
		return OK;
	}else {       
		warn_vx("ERROR: can't save airline state");
		_mavlink->send_statustext(MAV_SEVERITY_CRITICAL, "ERROR: can't save airline state");
		return ERROR;
	}
}



void
MavlinkMissionManager::handle_airline_clear(const mavlink_message_t *msg)
{
   int ret = OK;
    mavlink_airline_clear_t wpca;
    mavlink_msg_airline_clear_decode(msg, &wpca);

    if (CHECK_SYSID_COMPID_MISSION(wpca))
    {
	if (_airline_state == MAVLINK_WPM_STATE_IDLE) 
	{
			_time_last_recv = hrt_absolute_time();
			
			_transfer_partner_sysid = msg->compid;
			_transfer_partner_compid = msg->sysid;
			
	    if(wpca.airline_index == -1)
	    {
		for(uint8_t inx = 0; inx < MAVLINK_AIRLINE_MAX; inx++)
		{
		   ret |= update_airline_state(inx, inx, 0, 0, 0);
		   _store_airline[inx].upload = MAVLINK_AIRLINE_STATE_IDLE;
		}
		
	    }else{
		
	       ret = update_airline_state(wpca.airline_index,_store_airline[wpca.airline_index].id,0, 0, 0);
	       _store_airline[wpca.airline_index].upload = MAVLINK_AIRLINE_STATE_IDLE;
	    }
	    
	    if (update_active_mission(0, 0, 0, MAVLINK_CMD_IDLE) == OK) 
	    {
	       if (_verbose) { warn_vx("WPM: CLEAR_MISSION"); }
	       send_mission_ack(_transfer_partner_sysid, _transfer_partner_compid,MAV_AIRLINE_ACTIVE_CLEAR_OK + wpca.airline_index);
	    } 
	    else
	    {
	      send_mission_ack(_transfer_partner_sysid, _transfer_partner_compid, MAV_AIRLINE_ACTIVE_CLEAR_FAILED + wpca.airline_index);
	    }
	    
        if( ret == OK) 
        {
			if (_verbose) { warn_vx("WPM: CLEAR_ALL_AIRLINE OK"); }
			send_mission_ack(_transfer_partner_sysid, _transfer_partner_compid, MAV_AIRLINE_DELETE_OK+wpca.airline_index);
		} 
        else
		{
			send_mission_ack(_transfer_partner_sysid, _transfer_partner_compid, MAV_AIRLINE_DELETE_FAILED+wpca.airline_index);
		}
	} 
    else 
    {
			_mavlink->send_statustext_critical("WPM: IGN CLEAR CMD: Busy");

			if (_verbose) { warn_vx("WPM: CLEAR_ALL IGNORED: busy"); }
		}
	}
}

void
MavlinkMissionManager::handle_airline_info(const mavlink_message_t *msg)
{
	int8_t use_index = -1;
	mavlink_airline_info_t wpc;
	memset(&wpc,0, sizeof(mavlink_airline_info_t));
	
	mavlink_msg_airline_info_decode(msg, &wpc); 
//	for(int i=0;i<10;i++)
//	printf_vx("id = %d,  upload = %d,  active = %d,  count = %d,  cmd = %d---\n", wpc.airline[i].id,wpc.airline[i].upload,wpc.airline[i].active, wpc.airline[i].count, wpc.airline[i].cmd); 

	if (_verbose) { warn_vx("recv airline msg schedule"); }

	if (CHECK_SYSID_COMPID_MISSION(wpc)) 
	{
		printf_vx("[mavlink_mission]SYSID_COMPID  IS  OK\n");
		printf_vx("[mavlink_mission]_airline_state = %d\n\n",_airline_state);
		if (_airline_state == MAVLINK_WPM_STATE_IDLE) 
        {
			_time_last_recv = hrt_absolute_time();  

			_airline_state = MAVLINK_WPM_STATE_GETLIST;
			
			_transfer_airline_sysid = msg->compid;
			_transfer_airline_compid = msg->sysid;

			//warn_vx("_transfer_airline_sysid = %d, _transfer_airline_compid = %d",_transfer_airline_sysid, _transfer_airline_compid);
			//warn_vx("target_system = %d, target_component = %d", wpc.target_system, wpc.target_component);
			
            for(int8_t inx = MAVLINK_AIRLINE_MAX - 1; inx >= 0 ; inx-- ) 
            {
            //	warn_vx("id = %d, upload = %d, active = %d, count = %d, cmd = %d", wpc.airline[inx].id, wpc.airline[inx].upload, wpc.airline[inx].active, wpc.airline[inx].count, wpc.airline[inx].cmd); 
            	
               if((wpc.airline[inx].upload == MAVLINK_AIRLINE_STATE_UPLOAD) && (wpc.airline[inx].count > 0) && (wpc.airline[inx].count < NUM_MISSIONS_SUPPORTED))
               {
                   _store_airline[inx].upload = wpc.airline[inx].upload;
                   _store_airline[inx].id = wpc.airline[inx].id;
                   _store_airline[inx].count = wpc.airline[inx].count;
                   _store_airline[inx].cmd = wpc.airline[inx].cmd;
                   use_index = inx;
                   warn_vx("---use_index = %d, id = %d, count = %d, cmd = %d---", use_index, _store_airline[inx].id, _store_airline[inx].count, _store_airline[inx].cmd); 
               }
            }              
            //warn_vx("set airline msg schedule"); 
		} 
        else 
        {
		    _mavlink->send_statustext_critical("WPM: IGN MISSION_COUNT: Busy");
		    return;
	   }

       
       if(use_index >= 0)
       {
          _transfer_airline_index = use_index;
          _transfer_airline_id    = _store_airline[use_index].id;
          _transfer_airline_count = _store_airline[use_index].count;
          _transfer_airline_seq = 0;
          send_airline_request(_transfer_airline_sysid, _transfer_airline_compid,_transfer_airline_index, _transfer_airline_seq); //从最小的航线开始发送航点请求
       } 
       else
        {
           _airline_state = MAVLINK_WPM_STATE_IDLE;
           
           if (_verbose) { warn_vx("无航线装订"); }
        }
       
    }
}


void
MavlinkMissionManager::send_airline_request(uint8_t sysid, uint8_t compid, uint8_t line_inx,uint16_t seq)
{
    if(seq < _max_count) 
    {
        _time_last_sent = hrt_absolute_time();
        mavlink_airline_request_t wpr;
        wpr.target_system = sysid;
        wpr.target_component = compid;
        wpr.airline_index= line_inx;
        wpr.seq = seq;
        _mavlink->send_message(MAVLINK_MSG_ID_AIRLINE_REQUEST, &wpr);
        if (_verbose) { warn_vx("request airline id : %u - seq : %u", wpr.airline_index, wpr.seq); }
    }
    else
    {
        _mavlink->send_statustext_critical("ERROR: Waypoint index exceeds list capacity");
        if(_verbose) { warn_vx("ERROR:  airline_id%u - seq %u beyond",line_inx,seq); }
    }
}

void
MavlinkMissionManager::handle_airline_item(const mavlink_message_t *msg)
{
	mavlink_airline_item_t wp;
	mavlink_msg_airline_item_decode(msg, &wp);
    printf_vx("seq=%d、frame=%d、command=%d、X=%f、Y=%f、Z=%f\n",wp.seq,wp.frame,wp.command,wp.x,wp.y,wp.z);
    
	if (CHECK_SYSID_COMPID_MISSION(wp)) 
    {
	   if (_airline_state == MAVLINK_WPM_STATE_GETLIST) 
        {
			_time_last_recv = hrt_absolute_time();
            if(wp.airline_index != _transfer_airline_index) 
            {
               if (_verbose) { warn_vx("航线序号错误:need %u recv %u", _transfer_airline_index,wp.airline_index); }
				return;            
            }
			if (wp.seq != _transfer_airline_seq) 
            { /* don't send request here, it will be performed in eventloop after timeout */
				if (_verbose) { warn_vx("航路点序号错误airline %u: need seq %u  recv seq %u", wp.airline_index,_transfer_airline_seq,wp.seq); }
				return;
			}
		} 
		else
        {
           if (_verbose) { warn_vx("WPM: MISSION_ITEM ERROR: busy, airline_state %i", _airline_state); }
			_mavlink->send_statustext_critical("IGN AIRLINE_ITEM: Busy");
			return;
		}

         /*解析航点*/
		struct mission_item_s mission_item;
		int ret = parse_mavlink_airline_item(&wp, &mission_item);

		printf_vx("mission item****seq=%d、X=%f、Y=%f、Z=%f\n",mission_item.seq,mission_item.lat,mission_item.lon,mission_item.altitude);
		if (ret != OK) 
        {
			if (_verbose) { warn_vx("WPM: [航路点解析错误]airline %u: seq %u", wp.airline_index,wp.seq); }

			_mavlink->send_statustext_critical("IGN MISSION_ITEM: Busy");
			send_mission_ack(_transfer_airline_sysid, _transfer_airline_compid, ret);
			_airline_state = MAVLINK_WPM_STATE_IDLE;
			return;
		}

		 dm_item_t dm_item = DM_KEY_AIRLINE(_store_airline[wp.airline_index].id);  //接收到的航线序号从0开始 
         /*向emmc写航点*/
		if (dm_write(dm_item, wp.seq, DM_PERSIST_POWER_ON_RESET, &mission_item, sizeof(struct mission_item_s)) != sizeof(struct mission_item_s)) 
        {
			if (_verbose) { warn_vx("向emmc写航点失败: 航线号 %u: 航点号 %u", wp.airline_index,wp.seq); }

			send_mission_ack(_transfer_airline_sysid, _transfer_airline_compid, MAV_MISSION_ERROR);
			_mavlink->send_statustext_critical("Unable to write on emmc");
			_airline_state = MAVLINK_WPM_STATE_IDLE;
			return;
		}

		if (_verbose) { warn_vx("WPM: 写航路点完成 :airline %u seq %u", wp.airline_index,wp.seq); }

        /*下一个点*/
		_transfer_airline_seq = wp.seq + 1; //接收到的航点序号从0开始 

		if (_transfer_airline_seq == _transfer_airline_count) //所有航点都读取完成
        {
            uint8_t inx = _transfer_airline_index;
            /*完成一个航线后，刷新和存储航线信息表*/
            if (update_airline_state(inx,_transfer_airline_id, _transfer_airline_count, 0, _store_airline[inx].cmd) == OK)
            {
                _store_airline[inx].upload = MAVLINK_AIRLINE_STATE_STORED;
                if (_verbose) { warn_vx("航线信息更新成功:airline %u",_transfer_airline_index); }				
				send_mission_ack(_transfer_airline_sysid, _transfer_airline_compid, MAV_AIRLINE_UPLOAD_OK+_transfer_airline_index);
			} 
            else 
            {
                _store_airline[inx].upload = MAVLINK_AIRLINE_STATE_IDLE;
                if (_verbose) { warn_vx("航线信息更新失败:airline %u",_transfer_airline_index);}
				send_mission_ack(_transfer_airline_sysid, _transfer_airline_compid, MAV_AIRLINE_UPLOAD_FAILED + _transfer_airline_index);
			}

         
            for(inx = _transfer_airline_index + 1; inx < MAVLINK_AIRLINE_MAX; inx++ ) 
            {   /*选择下一个要装订的航线*/
                if((_store_airline[inx].upload == MAVLINK_AIRLINE_STATE_UPLOAD)&&(_store_airline[inx].count > 0)&&(_store_airline[inx].count < NUM_MISSIONS_SUPPORTED))
                {
                    _transfer_airline_index = inx;
                    _transfer_airline_id    = _store_airline[inx].id;
                    _transfer_airline_count = _store_airline[inx].count;
                    _transfer_airline_seq   = 0;
                    break;
                }           
            }

            if(inx < MAVLINK_AIRLINE_MAX)
            {
               send_airline_request(_transfer_airline_sysid, _transfer_airline_compid, _transfer_airline_index, _transfer_airline_seq);
            }
	        else
            {
               _airline_state = MAVLINK_WPM_STATE_IDLE;
               _mavlink->send_statustext_info("WPM: Transfer complete.");                
               //send_mission_ack(_transfer_partner_sysid, _transfer_partner_compid, MAV_AIRLINE_UPLOAD_OK);
               if (_verbose) { warn_vx("装订航线列表完成");}
            }
		} 
        else 
        {   /* request next item */
			send_airline_request(_transfer_airline_sysid, _transfer_airline_compid, _transfer_airline_index,_transfer_airline_seq);
		}
	}
}


void
MavlinkMissionManager::handle_airline_request(const mavlink_message_t *msg)
{
	mavlink_airline_request_t wpr;
	mavlink_msg_airline_request_decode(msg, &wpr);

	if (CHECK_SYSID_COMPID_MISSION(wpr)) 
    {
        uint8_t line_inx = wpr.airline_index;	//航线号
        
        if (_verbose) { warn_vx("收到航路点请求:airline%u - seq%u", wpr.airline_index,wpr.seq); }
        
	//	if (msg->sysid == _transfer_airline_sysid && msg->compid == _transfer_airline_compid) 
        {
            if ((_airline_state == MAVLINK_WPM_STATE_IDLE )  || (_airline_state == MAVLINK_WPM_STATE_SENDLIST)) 
            {
				_time_last_recv = hrt_absolute_time();
                _airline_state = MAVLINK_WPM_STATE_SENDLIST;
				
				if (wpr.seq < _store_airline[line_inx].count) 
                {
                
					 if (_verbose) { warn_vx("航线请求:航线号%u - 航点号%u", wpr.airline_index,wpr.seq); }
					 /* 发送航线信息 */	
					 _transfer_airline_id = wpr.airline_index;
					 _transfer_airline_seq = wpr.seq;
					 send_airline_item(_transfer_partner_sysid, _transfer_partner_compid, line_inx, wpr.seq);

				}
                else 
                {
					_airline_state = MAVLINK_WPM_STATE_IDLE;
					send_mission_ack(_transfer_partner_sysid, _transfer_partner_compid, MAV_MISSION_ERROR);					
                    if (_verbose) { warn_vx("----airline seq beyond error:airline%u - seq%u----", line_inx,wpr.seq); }
				}
			}             
            else
            {
				if (_verbose) { warn_vx("WPM: AIRLINE_ITEM_REQUEST ERROR: busy (state %d)", _airline_state); }

				_mavlink->send_statustext_critical("WPM: REJ. CMD: Busy");
			}
		} 
	}
}

void
MavlinkMissionManager::send_airline_item(uint8_t sysid, uint8_t compid,uint8_t airline_index, uint16_t seq)
{
	struct mission_item_s mission_item;
    uint8_t airline_id = _store_airline[airline_index].id;
    dm_item_t dm_item = DM_KEY_AIRLINE(airline_id);
 	
    /*从emmc 读取航点信息 */
	if (dm_read(dm_item, seq, &mission_item, sizeof(struct mission_item_s)) == sizeof(struct mission_item_s)) 
    {
		printf_vx("从emmc中读取数据\n");
		printf_vx("seq = %d, lat = %f, lon = %f, altitude = %.7f\r\n", \
				mission_item.seq, mission_item.lat,mission_item.lon, mission_item.altitude);
        
		_time_last_sent = hrt_absolute_time();

		/* create mission_item_s from mavlink_mission_item_t */
		mavlink_airline_item_t wp;
	 	format_mavlink_airline_item(&mission_item, &wp);

		wp.target_system = sysid;
		wp.target_component = compid;
		wp.seq = seq;
		wp.current = 0; //无用的变量，先保留
		//wp.current = (_current_seq == seq) ? 1 : 0; /* 是否为当前目标点 */
        wp.airline_index = airline_index;
        
        printf_vx("从emmc中读取数据\n");
        printf_vx("seq = %d, lat = %f, lon = %f, altitude = %.7f, altitude_is_relative = %d",wp.seq, wp.x, wp.y, wp.z, wp.frame);
        taskDelay(60);
		_mavlink->send_message(MAVLINK_MSG_ID_AIRLINE_ITEM, &wp);
        if (_verbose) { warn_vx("航路点已发送:airline%u - seq%u",airline_index,seq); }

	} 
    else 
    {
		send_mission_ack(_transfer_partner_sysid, _transfer_partner_compid, MAV_MISSION_ERROR);
		_mavlink->send_statustext_critical("Unable to read from emmc");

		if (_verbose) {warn_vx("航路点读取错误 :airline%u - seq%u----",airline_index,seq);}
	}
}

void
MavlinkMissionManager::handle_airline_request_list(const mavlink_message_t *msg)
{
	mavlink_airline_request_list_t wprl;
	mavlink_msg_airline_request_list_decode(msg, &wprl);
    
    if (_verbose) { warn_vx("recv airline request list msg.."); }

	if (CHECK_SYSID_COMPID_MISSION(wprl)) 
    {
    	if (_verbose) { warn_vx("收到航线列表请求信息"); }
		if ((_airline_state == MAVLINK_WPM_STATE_IDLE )  || (_airline_state == MAVLINK_WPM_STATE_SENDLIST)) 
        {
			_time_last_recv = hrt_absolute_time(); 
			
             _airline_state = MAVLINK_WPM_STATE_SENDLIST;
             
			_transfer_airline_seq = 0;
			
			_transfer_airline_sysid = msg->sysid;
			_transfer_airline_compid = msg->compid;
            
            if (_verbose) { warn_vx("航线列表请求确认"); }

		}       
		send_airline_info(msg->sysid, msg->compid);
	}
    else 
    {
	   if (_verbose) { warn_vx("WPM: MISSION_REQUEST_LIST ERROR: busy"); }
		_mavlink->send_statustext_critical("IGN REQUEST LIST: Busy");
	}
}

void
MavlinkMissionManager::send_airline_info(uint8_t sysid, uint8_t compid)
{
	_time_last_sent = hrt_absolute_time();

	mavlink_airline_info_t wpc;

	wpc.target_system = sysid;
	wpc.target_component = compid;
	memcpy(wpc.airline,_store_airline,sizeof(struct air_line)*MAVLINK_AIRLINE_MAX); //一次发送全部航线状态
   
	for(int i = 0; i<10 ;i++){
	    warn_vx("---id = %d, cmd = %d, count = %d, upload = %d, active = %d---", _store_airline[i].id, _store_airline[i].cmd, _store_airline[i].count , _store_airline[i].upload, _store_airline[i].active);
	}

	_mavlink->send_message(MAVLINK_MSG_ID_AIRLINE_INFO, &wpc);
	taskDelay(60);
	if (_verbose) { warn_vx("airline list send success");}
}

//TODO：后续将mavlink读取到的airline信息，转换到emmc存储的航点信息上

int
MavlinkMissionManager::parse_mavlink_airline_item(const mavlink_airline_item_t *mavlink_airline_item, struct mission_item_s *mission_item)
{
	/* only support global waypoints for now */
	switch (mavlink_airline_item->frame) 
	{
	case MAV_FRAME_GLOBAL:
		mission_item->lat = (double)mavlink_airline_item->x;
		mission_item->lon = (double)mavlink_airline_item->y;
		mission_item->altitude = mavlink_airline_item->z;
		mission_item->altitude_is_relative = false;
		break;

	case MAV_FRAME_GLOBAL_RELATIVE_ALT:
		mission_item->lat = (double)mavlink_airline_item->x;
		mission_item->lon = (double)mavlink_airline_item->y;
		mission_item->altitude = mavlink_airline_item->z;
		mission_item->altitude_is_relative = true;
		break;

	case MAV_FRAME_LOCAL_NED:
	case MAV_FRAME_LOCAL_ENU:
		return MAV_MISSION_UNSUPPORTED_FRAME;

	case MAV_FRAME_MISSION:
	default:
		return MAV_MISSION_ERROR;
	}

	switch (mavlink_airline_item->command) {
	case MAV_CMD_NAV_TAKEOFF:
		mission_item->pitch_min = mavlink_airline_item->param1;        
		mission_item->acceptance_radius = mavlink_airline_item->param2;
		break;
	case MAV_CMD_DO_JUMP:
		mission_item->do_jump_mission_index = mavlink_airline_item->param1;
		mission_item->do_jump_current_count = 0;
		mission_item->do_jump_repeat_count = mavlink_airline_item->param2;
		break;
	default:
#if 0
		mission_item->acceptance_radius = mavlink_airline_item->param2;
		mission_item->time_inside = mavlink_airline_item->param1;

#else
		/*modified by lxt, May1,2018.for formFly by GPS time*/
		mission_item->acceptance_radius = mavlink_airline_item->param2;
		mission_item->time_inside = -0.0f;
		mission_item->deltaTime_arrive = (uint32_t)mavlink_airline_item->param1;
		//printf_vx("dtArrive=%d\n",mission_item->deltaTime_arrive);
#endif

		break;
	}

	mission_item->seq = mavlink_airline_item->seq;/*added by lxt, May1,2018.for formFly by GPS time*/
	
	mission_item->deltaTime_arrive_corr_sec = mavlink_airline_item->param4;/*added by lxt, May19,2018.for formFly by GPS time*/
	mission_item->yaw = _wrap_pi(mavlink_airline_item->param4 * M_DEG_TO_RAD_F);
	
	mission_item->loiter_radius = fabs(mavlink_airline_item->param3);
	mission_item->loiter_direction = (mavlink_airline_item->param3 > 0) ? 1 : -1; /* 1 if positive CW, -1 if negative CCW */
	mission_item->nav_cmd = (NAV_CMD)mavlink_airline_item->command;

	mission_item->autocontinue = mavlink_airline_item->autocontinue;
	// mission_item->index = mavlink_mission_item->seq;
	mission_item->origin = ORIGIN_MAVLINK;

	/* reset DO_JUMP count */
	mission_item->do_jump_current_count = 0;

	mission_item->flag_attack = fabs(mavlink_airline_item->param3-12345)<0.5f ? 1 : 0;
	mission_item->attack_yaw_deg = mavlink_airline_item->param4;
	mission_item->loiter_round_num = mavlink_airline_item->param4;
	//warn_vx("flag_attack[%d], attack_yaw_deg[%.2f],loiter_round_num[%d] \n", mission_item->flag_attack, (double)mission_item->attack_yaw_deg,mission_item->loiter_round_num);


	return MAV_MISSION_ACCEPTED;
}

//TODO：后续将emmc读取到的airline信息，转换到mavlink发送的航点信息上
int
MavlinkMissionManager::format_mavlink_airline_item(const struct mission_item_s *mission_item, mavlink_airline_item_t *mavlink_airline_item)
{
	if (mission_item->altitude_is_relative) {
		mavlink_airline_item->frame = MAV_FRAME_GLOBAL_RELATIVE_ALT;

	} else {
		mavlink_airline_item->frame = MAV_FRAME_GLOBAL;
	}

	switch (mission_item->nav_cmd) {
	case NAV_CMD_TAKEOFF:
		mavlink_airline_item->param1 = mission_item->pitch_min;        
		mavlink_airline_item->param2 = mission_item->acceptance_radius;
		break;

	case NAV_CMD_DO_JUMP:
		mavlink_airline_item->param1 = mission_item->do_jump_mission_index;
		mavlink_airline_item->param2 = mission_item->do_jump_repeat_count - mission_item->do_jump_current_count;
		break;

	default:
		mavlink_airline_item->param2 = mission_item->acceptance_radius;
		//mavlink_airline_item->param1 = mission_item->time_inside;
		mavlink_airline_item->param1 = mission_item->deltaTime_arrive;
		break;
	}

	mavlink_airline_item->x = (float)mission_item->lat;
	mavlink_airline_item->y = (float)mission_item->lon;
	mavlink_airline_item->z = mission_item->altitude;


	mavlink_airline_item->param3 = mission_item->loiter_radius * (float)mission_item->loiter_direction;
	mavlink_airline_item->param4 = 0;
			
	mavlink_airline_item->command = mission_item->nav_cmd;
	mavlink_airline_item->autocontinue = mission_item->autocontinue;

	return OK;
}

void
MavlinkMissionManager::clean_airline_active_status()
{
	 struct airline_s airline_state;
	         
	 for(uint8_t inx = 0; inx < MAVLINK_AIRLINE_MAX; inx++) 
	 {
		 airline_state.dataman_store_id = _store_airline[inx].id;
		 airline_state.count  = _store_airline[inx].count;
		 
		 airline_state.active = 0; //写入emmc active = 0
		 _store_airline[inx].active = 0; //修改_store_airline激活状态为0
		 
		 airline_state.cmd    = _store_airline[inx].cmd;
		 if(dm_write(DM_KEY_AIRLINE_STATE, inx, DM_PERSIST_POWER_ON_RESET, &airline_state, sizeof(struct airline_s)) !=  sizeof(struct airline_s))
		 {
			 //if (_verbose) { warn_vx("airline_status write error, inx = %d", inx);}
		 }else{
			 //if (_verbose) { warn_vx("airline_status write success, inx = %d", inx);}
		 }
		 
	 }  
}


void
MavlinkMissionManager::handle_airline_active(const mavlink_message_t *msg)
{
	
   int seq = 0;
   mavlink_airline_active_t wact;
   
   memset(&wact,0,sizeof(mavlink_airline_active_t));
 
   mavlink_msg_airline_active_decode(msg, &wact);

	_transfer_partner_sysid = msg->compid;
	_transfer_partner_compid = msg->sysid;
   
   if (_verbose) 
   {
	   printf_vx("[激活航线命令]:%u, %u, %u, %u, %u, %u\n", \
			 wact.index1, wact.cmd1, wact.index2, wact.cmd2, wact.index3, wact.cmd3);}
  
  if (_verbose) { warn_vx("收到激活指令");}

  if(_airline_state !=  MAVLINK_WPM_STATE_IDLE)
  {
     if (_verbose) { warn_vx("WPM: AIRLINE_ITEM_ACTIVE REQUEST ERROR: busy (state %d)", _airline_state); }
      _mavlink->send_statustext_critical("WPM: REJ. CMD: Busy");
     return;
  }
  
  if(CHECK_SYSID_COMPID_MISSION(wact))
   {
     if (_verbose) { warn_vx("激活确认");}
     
     _time_last_recv = hrt_absolute_time();
     _airline_state =  MAVLINK_WPM_STATE_ACTIVE;
    
     update_active_mission(0,0,0,MAVLINK_CMD_IDLE);
     
     for(uint8_t clr = 0; clr < MAVLINK_AIRLINE_MAX; clr++)
     {
       _store_airline[clr].active = false;
     }
     
     _time_last_recv = hrt_absolute_time();

     if(wact.cmd1 == MAVLINK_CMD_NAV_MC_ACTIVE)
     { /*MC 激活一条航线*/
     
         if(ERROR == airline_to_mission_first_seq(wact.index1,0))
         {     
             if (_verbose) { warn_vx("ERROR: airline first seq "); }         
         } 
		 
         if(OK == airline_to_mission(wact.index1,0,_store_airline[wact.index1].count,0,1,MAVLINK_CMD_NAV_MC_ACTIVE))
         {
            seq = _store_airline[wact.index1].count;
            _store_airline[wact.index1].active = true;		   
		    send_mission_ack(_transfer_partner_sysid, _transfer_partner_compid, MAV_AIRLINE_ACTIVE_OK+wact.index1);
         }
		 else
         {     
             if (_verbose) { warn_vx("ERROR: airline: %u store_cmd %u != rec_cmd %u",\
                                    wact.index1, _store_airline[wact.index1].cmd,  wact.cmd1);}         
    	      send_mission_ack(_transfer_partner_sysid, _transfer_partner_compid, MAV_AIRLINE_ACTIVE_FAILED+wact.index1);
         } 
     }
          
     if((_store_airline[wact.index1].cmd == wact.cmd1)&&(wact.cmd1 == MAVLINK_CMD_NAV_TAKEOFF))
     {   /*FW 激活起飞航线*/        
         if(OK == airline_to_mission(wact.index1,0,_store_airline[wact.index1].count,0,0,MAVLINK_CMD_NAV_TAKEOFF))
         {
            seq = _store_airline[wact.index1].count;
           _store_airline[wact.index1].active = true;		   
		   send_mission_ack(_transfer_partner_sysid, _transfer_partner_compid, MAV_AIRLINE_ACTIVE_OK+wact.index1);
         }
		 else
         {     
             if (_verbose) { warn_vx("ERROR: airline: %u store_cmd %u != rec_cmd%u",\
                                    wact.index1, _store_airline[wact.index1].cmd,  wact.cmd1);}         
			 send_mission_ack(_transfer_partner_sysid, _transfer_partner_compid, MAV_AIRLINE_ACTIVE_FAILED+wact.index1);
         }
     }  
     
     _time_last_recv = hrt_absolute_time();
     if((_store_airline[wact.index2].cmd == wact.cmd2)&&(wact.cmd2 == MAVLINK_CMD_NAV_WAYPOINT))
     { /*FW 激活导航航线*/     
      if(OK == airline_to_mission(wact.index2, 0,_store_airline[wact.index2].count, 0,seq,MAVLINK_CMD_NAV_WAYPOINT))
      {
        seq += _store_airline[wact.index2].count;
        _store_airline[wact.index2].active = true;		   
        send_mission_ack(_transfer_partner_sysid, _transfer_partner_compid, MAV_AIRLINE_ACTIVE_OK+wact.index2);
      }
      else
      {     
          if (_verbose) { warn_vx("ERROR: airline: %u store_cmd %u != rec_cmd%u",\
                                 wact.index2, _store_airline[wact.index2].cmd,  wact.cmd2);}
     	 send_mission_ack(_transfer_partner_sysid, _transfer_partner_compid, MAV_AIRLINE_ACTIVE_FAILED+wact.index2);
      }
     }
     

      
      _time_last_recv = hrt_absolute_time();
      if((_store_airline[wact.index3].cmd == wact.cmd3) 
        &&  ((wact.cmd3 == MAVLINK_CMD_NAV_LAND)||(wact.cmd3 == MAVLINK_CMD_NAV_LAND)) )
      { /*FW 激活降落航线*/     
           if(OK == airline_to_mission(wact.index3, 0 ,_store_airline[wact.index3].count,0 ,seq,MAVLINK_CMD_NAV_LAND))
            {
               _store_airline[wact.index3].active = true;			   
			   send_mission_ack(_transfer_partner_sysid, _transfer_partner_compid, MAV_AIRLINE_ACTIVE_OK+wact.index3);
            }
		   else
    	   {				
    			if (_verbose) { warn_vx("ERROR: airline: %u store_cmd %u != rec_cmd%u",\
    								   wact.index3, _store_airline[wact.index3].cmd,  wact.cmd3);}		   
				send_mission_ack(_transfer_partner_sysid, _transfer_partner_compid, MAV_AIRLINE_ACTIVE_FAILED+wact.index3);
    		}
      }
      
     struct airline_s airline_state;
     for(uint8_t inx = 0; inx < MAVLINK_AIRLINE_MAX; inx++) 
     {
         airline_state.dataman_store_id = _store_airline[inx].id;
         airline_state.count  = _store_airline[inx].count;
         airline_state.active = _store_airline[inx].active;
         airline_state.cmd    = _store_airline[inx].cmd;
         dm_write(DM_KEY_AIRLINE_STATE, inx,DM_PERSIST_POWER_ON_RESET, &airline_state, sizeof(struct airline_s));
     }  
	   _airline_state =  MAVLINK_WPM_STATE_IDLE;
         
  }    
}

int 
MavlinkMissionManager::airline_to_mission(uint8_t airline_index, uint16_t start_seq, 
                                              uint16_t count_airline, uint8_t run_id,
                                              uint16_t mission_seq, int active)
{
    uint8_t airline_id = _store_airline[airline_index].id;
    dm_item_t dm_mission_item = DM_KEY_AIRLINE(airline_id);
	dm_item_t dm_run_item = DM_KEY_MISSION_WAYPOINTS(0);
    struct mission_item_s mission_item;

    
    for(uint16_t seq = start_seq ; seq < start_seq + count_airline; seq++,mission_seq++)
    {
	   if(dm_read(dm_mission_item, seq, &mission_item, sizeof(struct mission_item_s)) == sizeof(struct mission_item_s)) 
       { 
  
          if(dm_write(dm_run_item, mission_seq, DM_PERSIST_POWER_ON_RESET, &mission_item, sizeof(struct mission_item_s)) != sizeof(struct mission_item_s)) 
          {         
            if (_verbose) 
            {
               warn_vx("airline %u seq %u to mission 写入错误",run_id,mission_seq);
            }
            _mavlink->send_statustext_emergency("preAWMsg:write error");
            return ERROR;
          }
    } 
       else
       {          
           if (_verbose)
           { 
              warn_vx("airline %u seq %u  读取错误",airline_index,seq);          
           } 
           _mavlink->send_statustext_emergency("preAWMsg:write error");
           return ERROR;
         
       }   
    }
    
    if (update_active_mission(run_id,mission_seq,0,active) == OK) 
    {
        if (_verbose) { warn_vx("airline %u to mission 完成",airline_index);}        
    }
    return OK;
}


int 
MavlinkMissionManager::airline_to_mission_first_seq(uint8_t airline_index, uint8_t run_id)
{
	uint8_t airline_id      = _store_airline[airline_index].id;
	dm_item_t dm_store_item = DM_KEY_AIRLINE(airline_id);
	dm_item_t dm_run_item   = DM_KEY_MISSION_WAYPOINTS(0);
	struct mission_item_s mission_item;
	
    if(dm_read(dm_store_item,0, &mission_item, sizeof(struct mission_item_s)) == sizeof(struct mission_item_s)) 
    { 
          mission_item.nav_cmd = NAV_CMD_TAKEOFF;		  
    	  if(dm_write(dm_run_item, 0, DM_PERSIST_POWER_ON_RESET, &mission_item, sizeof(struct mission_item_s)) != sizeof(struct mission_item_s)) 
    	  { 		
     		if (_verbose) 
     		{
     		   warn_vx("airline first seq to mission 写入错误");
     		}
     		_mavlink->send_statustext_emergency("preAWMsg:write error");
     		return ERROR;
    	  }
    } 
    else
    {		  
        if (_verbose)
        { 
     	  warn_vx("airline first seq	读取错误");		   
        } 
        _mavlink->send_statustext_emergency("preAWMsg:write error");
        return ERROR;
    }   
	
	return OK;
}

