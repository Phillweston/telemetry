/**
 * @file mavlink_mission.h
 * MAVLink mission manager interface definition.
 *
 * @author Lorenz Meier <lm@inf.ethz.ch>
 * @author Julian Oes <joes@student.ethz.ch>
 * @author Anton Babushkin <anton.babushkin@me.com>
 */

#pragma once

#include "uORB.h"

#include "mavlink_bridge_header.h"
#include "mavlink_stream.h"

enum MAVLINK_AIRLINE_STATE {
	MAVLINK_AIRLINE_STATE_IDLE = 0,
	MAVLINK_AIRLINE_STATE_UPLOAD,
	MAVLINK_AIRLINE_STATE_STORED
};

enum MAVLINK_WPM_STATES {
	MAVLINK_WPM_STATE_IDLE = 0,
	MAVLINK_WPM_STATE_SENDLIST,
	MAVLINK_WPM_STATE_GETLIST,
	MAVLINK_WPM_STATE_ACTIVE,
	MAVLINK_WPM_STATE_ENUM_END
};

enum MAVLINK_WPM_CODES {
	MAVLINK_WPM_CODE_OK = 0,
	MAVLINK_WPM_CODE_ERR_WAYPOINT_ACTION_NOT_SUPPORTED,
	MAVLINK_WPM_CODE_ERR_WAYPOINT_FRAME_NOT_SUPPORTED,
	MAVLINK_WPM_CODE_ERR_WAYPOINT_OUT_OF_BOUNDS,
	MAVLINK_WPM_CODE_ERR_WAYPOINT_MAX_NUMBER_EXCEEDED,
	MAVLINK_WPM_CODE_ENUM_END
};



enum{
	MAVLINK_CMD_IDLE = 0,
	MAVLINK_CMD_ACTIVE_GROUP = 1,
	MAVLINK_CMD_CUSTOM_0 = 0,
	MAVLINK_CMD_CUSTOM_1 = 1,
	MAVLINK_CMD_CUSTOM_2 = 2,
	MAVLINK_CMD_ACTIVE_ALL = 4,
	MAVLINK_CMD_NAV_WAYPOINT = 16,
	MAVLINK_CMD_NAV_LOITER_UNLIM = 17,
	MAVLINK_CMD_NAV_LOITER_TURNS = 18,
	MAVLINK_CMD_NAV_LOITER_TIME = 19,
	MAVLINK_CMD_NAV_RETURN_TO_LAUNCH = 20,
	MAVLINK_CMD_NAV_LAND = 21,
	MAVLINK_CMD_NAV_TAKEOFF = 22,
	MAVLINK_CMD_NAV_ROI = 80,
	MAVLINK_CMD_NAV_PATHPLANNING = 81,
	MAVLINK_CMD_NAV_GUIDED_LIMITS = 90,
	MAVLINK_CMD_NAV_GUIDED_MASTER = 91,
	MAVLINK_CMD_NAV_GUIDED_ENABLE = 92,
	MAVLINK_CMD_NAV_LAST = 95,
	MAVLINK_CMD_NAV_MC_ACTIVE = 101, /* add by  caojiangzhi 2016.8.30*/
	MAVLINK_CMD_CONDITION_DELAY = 112,
	MAVLINK_CMD_CONDITION_CHANGE_ALT = 113,
	MAVLINK_CMD_CONDITION_DISTANCE = 114,
	MAVLINK_CMD_CONDITION_YAW = 115,
	MAVLINK_CMD_CONDITION_LAST = 159,
	MAVLINK_CMD_DO_SET_MODE = 176,
	MAVLINK_CMD_DO_JUMP = 177,
	MAVLINK_CMD_DO_CHANGE_SPEED = 178,
	MAVLINK_CMD_DO_SET_HOME = 179,
	MAVLINK_CMD_DO_SET_PARAMETER = 180,
	MAVLINK_CMD_DO_SET_RELAY = 181,
	MAVLINK_CMD_DO_REPEAT_RELAY = 182,
	MAVLINK_CMD_DO_SET_SERVO = 183,
	MAVLINK_CMD_DO_REPEAT_SERVO = 184,
	MAVLINK_CMD_DO_FLIGHTTERMINATION = 185,
	MAVLINK_CMD_DO_CONTROL_VIDEO = 200,
	MAVLINK_CMD_DO_MOUNT_CONFIGURE = 204,
	MAVLINK_CMD_DO_MOUNT_CONTROL = 205,
	MAVLINK_CMD_DO_SET_CAM_TRIGG_DIST = 206,
	MAVLINK_CMD_DO_FENCE_ENABLE = 207,
	MAVLINK_CMD_DO_PARACHUTE = 208,
	MAVLINK_CMD_DO_INVERTED_FLIGHT = 210,
	MAVLINK_CMD_DO_MOUNT_CONTROL_QUAT = 220,
	MAVLINK_CMD_DO_GUIDED_MASTER = 221,
	MAVLINK_CMD_DO_GUIDED_LIMITS = 222,
	MAVLINK_CMD_DO_LAST = 240,
	MAVLINK_CMD_PREFLIGHT_CALIBRATION = 241,
	MAVLINK_CMD_PREFLIGHT_SET_SENSOR_OFFSETS = 242,
	MAVLINK_CMD_PREFLIGHT_STORAGE = 245,
	MAVLINK_CMD_PREFLIGHT_REBOOT_SHUTDOWN = 246,
	MAVLINK_CMD_OVERRIDE_GOTO = 252,
	MAVLINK_CMD_MISSION_START = 300,
	MAVLINK_CMD_COMPONENT_ARM_DISARM = 400,
	MAVLINK_CMD_START_RX_PAIR = 500,
	MAVLINK_CMD_PAYLOAD_PREPARE_DEPLOY = 30001,
	MAVLINK_CMD_PAYLOAD_CONTROL_DEPLOY = 30002
};


#define MAVLINK_MISSION_PROTOCOL_TIMEOUT_DEFAULT 2000000    ///< Protocol communication action timeout in us
#define MAVLINK_MISSION_RETRY_TIMEOUT_DEFAULT 500000        ///< Protocol communication retry timeout in us


class MavlinkMissionManager : public MavlinkStream {
public:
	~MavlinkMissionManager();

	const char *get_name() const
	{
		return MavlinkMissionManager::get_name_static();
	}

	static const char *get_name_static()
	{
		return "MISSION_ITEM";
	}

	uint8_t get_id()
	{
		return MAVLINK_MSG_ID_MISSION_ITEM;
	}

	static MavlinkStream *new_instance(Mavlink *mavlink)
	{
		return new MavlinkMissionManager(mavlink);
	}

	unsigned get_size() { return 0; };
	
	void handle_message(const mavlink_message_t *msg);

	void set_verbose(bool v) { _verbose = v; }

private:
	enum MAVLINK_WPM_STATES _state;					///< Current state
	enum MAVLINK_WPM_STATES _airline_state; 				///< Current state

	uint64_t		_time_last_recv;
	uint64_t		_time_last_sent;

	uint32_t		_action_timeout;
	uint32_t		_retry_timeout;
	unsigned		_max_count;				///< Maximum number of mission items

	int			_dataman_id;				///< Dataman storage ID for active mission
	unsigned		_count;					///< Count of items in active mission
	int			_current_seq;				///< Current item sequence in active mission

	int			_transfer_dataman_id;			///< Dataman storage ID for current transmission
	unsigned		_transfer_count;			///< Items count in current transmission
	unsigned		_transfer_seq;				///< Item sequence in current transmission
	unsigned		_transfer_current_seq;			///< Current item ID for current transmission (-1 means not initialized)
	unsigned		_transfer_partner_sysid;		///< Partner system ID for current transmission
	unsigned		_transfer_partner_compid;		///< Partner component ID for current transmission

	uint8_t  _transfer_airline_index;
	uint8_t  _transfer_airline_id;
	uint16_t _transfer_airline_seq;   /*存储航路点的编号*/	
	uint16_t _transfer_airline_count;
	uint8_t  _transfer_airline_sysid;		///< Partner system ID for current transmission
	uint8_t	 _transfer_airline_compid;		///< Partner component ID for current transmission
	
	struct air_line _store_airline[MAVLINK_AIRLINE_MAX];

	int			_offboard_mission_sub;
	int			_mission_result_sub;
	orb_advert_t		_offboard_mission_pub;

	bool _verbose;

	/* do not allow top copying this class */
	MavlinkMissionManager(MavlinkMissionManager &);
	MavlinkMissionManager& operator = (const MavlinkMissionManager &);

	void init_offboard_mission();

	int update_active_mission(int dataman_id, unsigned count, int seq,int active = MAVLINK_CMD_ACTIVE_ALL);/*默认值是全部激活*/
	int airline_to_mission_first_seq(uint8_t airline_index, uint8_t run_id);

	/**
	 *  @brief Sends an waypoint ack message
	 */
	void send_mission_ack(uint8_t sysid, uint8_t compid, uint8_t type);

	/**
	 *  @brief Broadcasts the new target waypoint and directs the MAV to fly there
	 *
	 *  This function broadcasts its new active waypoint sequence number and
	 *  sends a message to the controller, advising it to fly to the coordinates
	 *  of the waypoint with a given orientation
	 *
	 *  @param seq The waypoint sequence number the MAV should fly to.
	 */
	void send_mission_current(uint16_t seq);

	void send_mission_count(uint8_t sysid, uint8_t compid, uint16_t count);

	void send_mission_item(uint8_t sysid, uint8_t compid, uint16_t seq);

	void send_mission_request(uint8_t sysid, uint8_t compid, uint16_t seq);

	/**
	 *  @brief emits a message that a waypoint reached
	 *
	 *  This function broadcasts a message that a waypoint is reached.
	 *
	 *  @param seq The waypoint sequence number the MAV has reached.
	 */
	void send_mission_item_reached(uint16_t seq);

	void handle_mission_ack(const mavlink_message_t *msg);

	void handle_mission_set_current(const mavlink_message_t *msg);

	void handle_mission_request_list(const mavlink_message_t *msg);

	void handle_mission_request(const mavlink_message_t *msg);

	void handle_mission_count(const mavlink_message_t *msg);

	void handle_mission_item(const mavlink_message_t *msg);

	void handle_mission_clear_all(const mavlink_message_t *msg);

	/**
	 * Parse mavlink MISSION_ITEM message to get mission_item_s.
	 */
	int parse_mavlink_mission_item(const mavlink_mission_item_t *mavlink_mission_item, struct mission_item_s *mission_item);

	/**
	 * Format mission_item_s as mavlink MISSION_ITEM message.
	 */
	int format_mavlink_mission_item(const struct mission_item_s *mission_item, mavlink_mission_item_t *mavlink_mission_item);

	/**/

	void send_airline_info(uint8_t sysid, uint8_t compid);	
	void handle_airline_request_list(const mavlink_message_t *msg);	
	void send_airline_item(uint8_t sysid, uint8_t compid,uint8_t airline_index, uint16_t seq);
	void handle_airline_request(const mavlink_message_t *msg);
	void handle_airline_item(const mavlink_message_t *msg);	
 	void send_airline_request(uint8_t sysid, uint8_t compid, uint8_t line_inx,uint16_t seq);
	void handle_airline_info(const mavlink_message_t *msg);
	void handle_airline_clear(const mavlink_message_t *msg);
	int update_airline_state(int index,int airline_id, unsigned count, int active, int cmd);	
 	int parse_mavlink_airline_item(const mavlink_airline_item_t *mavlink_airline_item, struct mission_item_s *mission_item);
	int format_mavlink_airline_item(const struct mission_item_s *mission_item, mavlink_airline_item_t *mavlink_airline_item);
	void clean_airline_active_status();
	void handle_airline_active(const mavlink_message_t *msg);	
    int airline_to_mission(uint8_t airline_index,uint16_t start_seq, uint16_t count, uint8_t run_id, uint16_t run_seq,int active);
    

protected:
	explicit MavlinkMissionManager(Mavlink *mavlink);

	void send(const hrt_abstime t);
};
