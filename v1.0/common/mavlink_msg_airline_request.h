// MESSAGE MISSION_REQUEST PACKING

#define MAVLINK_MSG_ID_AIRLINE_REQUEST 220

typedef struct __mavlink_airline_request_t
{
 uint16_t seq; /*< Sequence*/
 uint8_t target_system; /*< System ID*/
 uint8_t target_component; /*< Component ID*/
 uint8_t airline_index;
} mavlink_airline_request_t;

#define MAVLINK_MSG_ID_AIRLINE_REQUEST_LEN 5
#define MAVLINK_MSG_ID_190_LEN 5

#define MAVLINK_MSG_ID_AIRLINE_REQUEST_CRC 230
#define MAVLINK_MSG_ID_190_CRC 230



#define MAVLINK_MESSAGE_INFO_AIRLINE_REQUEST { \
	"AIRLINE_REQUEST", \
	4, \
	{ \
	{ "seq", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_airline_request_t, seq) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_airline_request_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_airline_request_t, target_component) }, \
         { "airline_index", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_airline_request_t, airline_index) }, \
         } \
}


// MESSAGE MISSION_REQUEST UNPACKING


/**
 * @brief Get field target_system from mission_request message
 *
 * @return System ID
 */
static inline uint8_t mavlink_msg_airline_request_get_target_system(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field target_component from mission_request message
 *
 * @return Component ID
 */
static inline uint8_t mavlink_msg_airline_request_get_target_component(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field seq from mission_request message
 *
 * @return Sequence
 */
static inline uint16_t mavlink_msg_airline_request_get_seq(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  0);
}

static inline uint8_t mavlink_msg_airline_request_get_airline_index(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Decode a mission_request message into a struct
 *
 * @param msg The message to decode
 * @param mission_request C-struct to decode the message contents into
 */
static inline void mavlink_msg_airline_request_decode(const mavlink_message_t* msg, mavlink_airline_request_t* airline_request)
{
#if MAVLINK_NEED_BYTE_SWAP
	airline_request->index = mavlink_msg_airline_request_get_airline_index(msg);
	airline_request->seq = mavlink_msg_airline_request_get_seq(msg);
	airline_request->target_system = mavlink_msg_airline_request_get_target_system(msg);
	airline_request->target_component = mavlink_msg_airline_request_get_target_component(msg);
#else
	memcpy(airline_request, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_AIRLINE_REQUEST_LEN);
#endif
}
