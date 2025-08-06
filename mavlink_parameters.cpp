/**
 * @file mavlink_parameters.cpp
 * Mavlink parameters manager implementation.
 *
 * @author Anton Babushkin <anton.babushkin@me.com>
 * @author Lorenz Meier <lorenz@px4.io>
 */

#include <stdio.h>

#include "mavlink_parameters.h"
#include "print/print.h"
#include "mavlink_main.h"

MavlinkParametersManager::MavlinkParametersManager(Mavlink *mavlink) : MavlinkStream(mavlink),
	_send_all_index(-1),
	_rc_param_map_pub(nullptr)
{
}

unsigned
MavlinkParametersManager::get_size()
{
	if (_send_all_index >= 0) {
		return MAVLINK_MSG_ID_PARAM_VALUE_LEN + MAVLINK_NUM_NON_PAYLOAD_BYTES;

	} else {
		return 0;
	}
}

void
MavlinkParametersManager::handle_message(const mavlink_message_t *msg)
{
//	warnx("msgid:%d", msg->msgid);
	switch (msg->msgid) {
	case MAVLINK_MSG_ID_PARAM_REQUEST_LIST: {
		
		printf_vx("request all parameters\n");
			/* request all parameters */
			mavlink_param_request_list_t req_list;
			mavlink_msg_param_request_list_decode(msg, &req_list);

			//if (req_list.target_system == mavlink_system.sysid &&
			   // (req_list.target_component == mavlink_system.compid || req_list.target_component == MAV_COMP_ID_ALL)) {
		//	if(msg->compid == mavlink_system.sysid){ 
				_send_all_index = 0;
		//	}
			break;
		}

	case MAVLINK_MSG_ID_PARAM_SET: {
		
			/* set parameter */
			if (msg->msgid == MAVLINK_MSG_ID_PARAM_SET) {
				mavlink_param_set_t set;
				mavlink_msg_param_set_decode(msg, &set);

				//if (set.target_system == mavlink_system.sysid &&
				  //  (set.target_component == mavlink_system.compid || set.target_component == MAV_COMP_ID_ALL)) {
								
			//	if(msg->sysid == mavlink_system.sysid){ 
								
					/* local name buffer to enforce null-terminated string */
					char name[MAVLINK_MSG_PARAM_VALUE_FIELD_PARAM_ID_LEN + 1];
					strncpy(name, set.param_id, MAVLINK_MSG_PARAM_VALUE_FIELD_PARAM_ID_LEN);
					/* enforce null termination */
					name[MAVLINK_MSG_PARAM_VALUE_FIELD_PARAM_ID_LEN] = '\0';
					/* attempt to find parameter, set and send it */
					param_t param = param_find_no_notification(name);

					if(9 == (set.param_type))
					{
						printf_vx("name = %s, param_value = %.2f, param_type = %d\n", name, set.param_value, set.param_type);
					}else if(6 == (set.param_type)){
						printf_vx("name = %s, param_value = %d, param_type = %d\n", name, *(int32_t*)(&set.param_value), set.param_type);
					}
					
					if (param == PARAM_INVALID) {
						char buf[MAVLINK_MSG_STATUSTEXT_FIELD_TEXT_LEN];
						sprintf(buf, "[pm] unknown param: %s", name);
						_mavlink->send_statustext_info(buf);
						
						printf_vx("unknown parameter \n");

					} else {
						/* set and send parameter */
						param_set(param, &(set.param_value));
						param_save_default();
						send_param(param);
						
						printf_vx("set parameter success\n");
					}
				
			}
			break;
		}

	case MAVLINK_MSG_ID_PARAM_REQUEST_READ: {
		printf_vx("request one parameter\n");
			/* request one parameter */
			mavlink_param_request_read_t req_read;
			mavlink_msg_param_request_read_decode(msg, &req_read);

			//if (req_read.target_system == mavlink_system.sysid &&
			//    (req_read.target_component == mavlink_system.compid || req_read.target_component == MAV_COMP_ID_ALL)) {
			if(msg->compid == mavlink_system.sysid){ 
				
				/* when no index is given, loop through string ids and compare them */
				if (req_read.param_index < 0) {
					/* local name buffer to enforce null-terminated string */
					char name[MAVLINK_MSG_PARAM_VALUE_FIELD_PARAM_ID_LEN + 1];
					strncpy(name, req_read.param_id, MAVLINK_MSG_PARAM_VALUE_FIELD_PARAM_ID_LEN);
					/* enforce null termination */
					name[MAVLINK_MSG_PARAM_VALUE_FIELD_PARAM_ID_LEN] = '\0';
					/* attempt to find parameter and send it */
					send_param(param_find_no_notification(name));

				} else {
					/* when index is >= 0, send this parameter again */
					int ret = send_param(param_for_used_index(req_read.param_index));

					if (ret == 1) {
						char buf[MAVLINK_MSG_STATUSTEXT_FIELD_TEXT_LEN];
						sprintf(buf, "[pm] unknown param ID: %u", req_read.param_index);
						_mavlink->send_statustext_info(buf);
					} else if (ret == 2) {
						char buf[MAVLINK_MSG_STATUSTEXT_FIELD_TEXT_LEN];
						sprintf(buf, "[pm] failed loading param from storage ID: %u", req_read.param_index);
						_mavlink->send_statustext_info(buf);
					}
				}
			}
			break;
		}

	default:
		break;
	}
}

void
MavlinkParametersManager::send(const hrt_abstime t)
{
	/* send all parameters if requested, but only after the system has booted */
	if (_send_all_index >= 0 && _mavlink->boot_complete()) {

		/* look for the first parameter which is used */
		param_t p;
		do {
			/* walk through all parameters, including unused ones */
			p = param_for_index(_send_all_index);
			_send_all_index++;
		} while (p != PARAM_INVALID && !param_used(p));

		if (p != PARAM_INVALID) {
			send_param(p);
		}

		if ((p == PARAM_INVALID) || (_send_all_index >= (int) param_count())) {
			_send_all_index = -1;
		}
	} else if (_send_all_index == 0 && hrt_absolute_time() > 20 * 1000 * 1000) {
		/* the boot did not seem to ever complete, warn user and set boot complete */
		_mavlink->send_statustext_critical("WARNING: SYSTEM BOOT INCOMPLETE. CHECK CONFIG.");
		_mavlink->set_boot_complete();
	}
}


int
MavlinkParametersManager::send_param(param_t param)
{
	if (param == PARAM_INVALID) {
		return 1;
	}
	mavlink_param_value_t msg;

	/*
	 * get param value, since MAVLink encodes float and int params in the same
	 * space during transmission, copy param onto float val_buf
	 */
	if (param_get(param, &msg.param_value) != OK) {
		return 2;
	}

	msg.param_count = param_count_used();
	msg.param_index = param_get_used_index(param);

	/* copy parameter name */
	strncpy(msg.param_id, param_name(param), MAVLINK_MSG_PARAM_VALUE_FIELD_PARAM_ID_LEN);

	/* query parameter type */
	param_type_t type = param_type(param);

	/*
	 * Map onboard parameter type to MAVLink type,
	 * endianess matches (both little endian)
	 */
	if (type == PARAM_TYPE_INT32) {
		msg.param_type = MAVLINK_TYPE_INT32_T;

	} else if (type == PARAM_TYPE_FLOAT) {
		msg.param_type = MAVLINK_TYPE_FLOAT;

	} else {
		msg.param_type = MAVLINK_TYPE_FLOAT;
	}

	_mavlink->send_message(MAVLINK_MSG_ID_PARAM_VALUE, &msg, 0xFC);
//	printf_vx("---send parameter---\n");

	return 0;
}
