// MESSAGE MISSION_REQUEST_LIST PACKING

#define MAVLINK_MSG_ID_AIRLINE_REQUEST_LIST 223

typedef struct __mavlink_airline_request_list_t
{
 uint8_t target_system; /*< System ID*/
 uint8_t target_component; /*< Component ID*/
} mavlink_airline_request_list_t;

#define MAVLINK_MSG_ID_AIRLINE_REQUEST_LIST_LEN 2
#define MAVLINK_MSG_ID_43_LEN 2

#define MAVLINK_MSG_ID_AIRLINE_REQUEST_LIST_CRC 132
#define MAVLINK_MSG_ID_43_CRC 132



#define MAVLINK_MESSAGE_INFO_AIRLINE_REQUEST_LIST { \
	"AIRLINE_REQUEST_LIST", \
	2, \
	{  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_airline_request_list_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_airline_request_list_t, target_component) }, \
         } \
}





/**
 * @brief Get field target_system from mission_request_list message
 *
 * @return System ID
 */
static inline uint8_t mavlink_msg_airline_request_list_get_target_system(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field target_component from mission_request_list message
 *
 * @return Component ID
 */
static inline uint8_t mavlink_msg_airline_request_list_get_target_component(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Decode a mission_request_list message into a struct
 *
 * @param msg The message to decode
 * @param mission_request_list C-struct to decode the message contents into
 */
static inline void mavlink_msg_airline_request_list_decode(const mavlink_message_t* msg, mavlink_airline_request_list_t* airline_request_list)
{
#if MAVLINK_NEED_BYTE_SWAP
	airline_request_list->target_system = mavlink_msg_airline_request_list_get_target_system(msg);
	airline_request_list->target_component = mavlink_msg_airline_request_list_get_target_component(msg);
#else
	memcpy(airline_request_list, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_AIRLINE_REQUEST_LIST_LEN);
#endif
}
