// MESSAGE MISSION_CLEAR_ALL PACKING

#define MAVLINK_MSG_ID_AIRLINE_CLEAR 225

typedef struct _mavlink_airline_clear_t
{
 uint8_t target_system; /*< System ID*/
 uint8_t target_component; /*< Component ID*/
 int8_t airline_index;
 
} mavlink_airline_clear_t;

#define MAVLINK_MSG_ID_AIRLINE_CLEAR_LEN 3
#define MAVLINK_MSG_ID_195_LEN 3

#define MAVLINK_MSG_ID_AIRLINE_CLEAR_CRC 232
#define MAVLINK_MSG_ID_195_CRC 232



#define MAVLINK_MESSAGE_INFO_AIRLINE_CLEAR { \
	"AIRLINE_CLEAR", \
	3, \
	{ \
       { "target_system",    NULL, MAVLINK_TYPE_UINT8_T, 0, 0,    offsetof(mavlink_airline_clear_t, target_system) }, \
       { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_airline_clear_t, target_component) }, \
       { "airline_index",    NULL, MAVLINK_TYPE_UINT8_T, 0, 2,	offsetof(mavlink_airline_clear_t, airline_index) }, \
} \
}



// MESSAGE MISSION_CLEAR_ALL UNPACKING


/**
 * @brief Get field target_system from mission_clear_all message
 *
 * @return System ID
 */
static inline uint8_t mavlink_msg_airline_clear_get_target_system(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field target_component from mission_clear_all message
 *
 * @return Component ID
 */
static inline uint8_t mavlink_msg_airline_clear_get_target_component(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  1);
}

static inline uint8_t mavlink_msg_airline_clear_get_airline_index(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Decode a mission_clear_all message into a struct
 *
 * @param msg The message to decode
 * @param mission_clear_all C-struct to decode the message contents into
 */
static inline void mavlink_msg_airline_clear_decode(const mavlink_message_t* msg, mavlink_airline_clear_t* airline_clear)
{
#if MAVLINK_NEED_BYTE_SWAP
	airline_clear->target_system = mavlink_msg_airline_clear_get_target_system(msg);
	airline_clear->target_component = mavlink_msg_airline_clear_get_target_component(msg);
	airline_clear->airline_index = mavlink_msg_airline_clear_get_airline_index(msg);
#else
	memcpy(airline_clear, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_AIRLINE_CLEAR_LEN);
#endif
}
