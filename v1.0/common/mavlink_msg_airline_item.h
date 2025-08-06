// MESSAGE MISSION_ITEM PACKING

#define MAVLINK_MSG_ID_AIRLINE_ITEM 219

typedef struct _mavlink_airline_item_t
{
 float param1; /*< PARAM1, see MAV_CMD enum*/
 float param2; /*< PARAM2, see MAV_CMD enum*/
 float param3; /*< PARAM3, see MAV_CMD enum*/
 float param4; /*< PARAM4, see MAV_CMD enum*/
 float x; /*< PARAM5 / local: x position, global: latitude*/
 float y; /*< PARAM6 / y position: global: longitude*/
 float z; /*< PARAM7 / z position: global: altitude (relative or absolute, depending on frame.*/
 uint16_t seq; /*< Sequence*/
 uint16_t command; /*< The scheduled action for the MISSION. see MAV_CMD in common.xml MAVLink specs*/
 uint8_t target_system; /*< System ID*/
 uint8_t target_component; /*< Component ID*/
 uint8_t frame; /*< The coordinate system of the MISSION. see MAV_FRAME in mavlink_types.h*/
 uint8_t current; /*< false:0, true:1*/
 uint8_t autocontinue; /*< autocontinue to next wp*/
 uint8_t  airline_index;
} mavlink_airline_item_t;

#define MAVLINK_MSG_ID_AIRLINE_ITEM_LEN 38
#define MAVLINK_MSG_ID_219_LEN 38

#define MAVLINK_MSG_ID_AIRLINE_ITEM_CRC 254
#define MAVLINK_MSG_ID_219_CRC 254



#define MAVLINK_MESSAGE_INFO_AIRLINE_ITEM { \
	"AIRLINE_ITEM", \
	15, \
	{  { "param1", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_mission_item_t, param1) }, \
         { "param2", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_mission_item_t, param2) }, \
         { "param3", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_mission_item_t, param3) }, \
         { "param4", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_mission_item_t, param4) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_mission_item_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_mission_item_t, y) },\
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_mission_item_t, z) },\
         { "seq", NULL, MAVLINK_TYPE_UINT16_T, 0, 28, offsetof(mavlink_mission_item_t, seq) }, \
         { "command", NULL, MAVLINK_TYPE_UINT16_T, 0, 30, offsetof(mavlink_mission_item_t, command) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_mission_item_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 33, offsetof(mavlink_mission_item_t, target_component) }, \
         { "frame", NULL, MAVLINK_TYPE_UINT8_T, 0, 34, offsetof(mavlink_mission_item_t, frame) }, \
         { "current", NULL, MAVLINK_TYPE_UINT8_T, 0, 35, offsetof(mavlink_mission_item_t, current) }, \
         { "autocontinue", NULL, MAVLINK_TYPE_UINT8_T, 0, 36, offsetof(mavlink_mission_item_t, autocontinue) }, \
         { "airline_index", NULL, MAVLINK_TYPE_UINT8_T, 0, 37, offsetof(mavlink_mission_item_t, airline_index) }, \
         } \
}


// MESSAGE MISSION_ITEM UNPACKING


/**
 * @brief Get field target_system from mission_item message
 *
 * @return System ID
 */
static inline uint8_t mavlink_msg_airline_item_get_target_system(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  32);
}

/**
 * @brief Get field target_component from mission_item message
 *
 * @return Component ID
 */
static inline uint8_t mavlink_msg_airline_item_get_target_component(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  33);
}

static inline uint16_t mavlink_msg_airline_item_get_airline_index(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  37);
}

/**
 * @brief Get field seq from mission_item message
 *
 * @return Sequence
 */
static inline uint16_t mavlink_msg_airline_item_get_seq(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  28);
}

/**
 * @brief Get field frame from mission_item message
 *
 * @return The coordinate system of the MISSION. see MAV_FRAME in mavlink_types.h
 */
static inline uint8_t mavlink_msg_airline_item_get_frame(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  34);
}

/**
 * @brief Get field command from mission_item message
 *
 * @return The scheduled action for the MISSION. see MAV_CMD in common.xml MAVLink specs
 */
static inline uint16_t mavlink_msg_airline_item_get_command(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  30);
}

/**
 * @brief Get field current from mission_item message
 *
 * @return false:0, true:1
 */
static inline uint8_t mavlink_msg_airline_item_get_current(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  35);
}

/**
 * @brief Get field autocontinue from mission_item message
 *
 * @return autocontinue to next wp
 */
static inline uint8_t mavlink_msg_airline_item_get_autocontinue(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  36);
}

/**
 * @brief Get field param1 from mission_item message
 *
 * @return PARAM1, see MAV_CMD enum
 */
static inline float mavlink_msg_airline_item_get_param1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field param2 from mission_item message
 *
 * @return PARAM2, see MAV_CMD enum
 */
static inline float mavlink_msg_airline_item_get_param2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field param3 from mission_item message
 *
 * @return PARAM3, see MAV_CMD enum
 */
static inline float mavlink_msg_airline_item_get_param3(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field param4 from mission_item message
 *
 * @return PARAM4, see MAV_CMD enum
 */
static inline float mavlink_msg_airline_item_get_param4(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field x from mission_item message
 *
 * @return PARAM5 / local: x position, global: latitude
 */
static inline float mavlink_msg_airline_item_get_x(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field y from mission_item message
 *
 * @return PARAM6 / y position: global: longitude
 */
static inline float mavlink_msg_airline_item_get_y(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field z from mission_item message
 *
 * @return PARAM7 / z position: global: altitude (relative or absolute, depending on frame.
 */
static inline float mavlink_msg_airline_item_get_z(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Decode a mission_item message into a struct
 *
 * @param msg The message to decode
 * @param mission_item C-struct to decode the message contents into
 */
static inline void mavlink_msg_airline_item_decode(const mavlink_message_t* msg, mavlink_airline_item_t* airline_item)
{
#if MAVLINK_NEED_BYTE_SWAP
	airline_item->param1 = mavlink_msg_airline_item_get_param1(msg);
	airline_item->param2 = mavlink_msg_airline_item_get_param2(msg);
	airline_item->param3 = mavlink_msg_airline_item_get_param3(msg);
	airline_item->param4 = mavlink_msg_airline_item_get_param4(msg);
	airline_item->x = mavlink_msg_airline_item_get_x(msg);
	airline_item->y = mavlink_msg_airline_item_get_y(msg);
	airline_item->z = mavlink_msg_airline_item_get_z(msg);	
	airline_item->seq = mavlink_msg_airline_item_get_seq(msg);
	airline_item->command = mavlink_msg_airline_item_get_command(msg);
	airline_item->target_system = mavlink_msg_airline_item_get_target_system(msg);
	airline_item->target_component = mavlink_msg_airline_item_get_target_component(msg);
	airline_item->frame = mavlink_msg_airline_item_get_frame(msg);
	airline_item->current = mavlink_msg_airline_item_get_current(msg);
	airline_item->autocontinue = mavlink_msg_airline_item_get_autocontinue(msg);
	airline_item->airline_id = mavlink_msg_airline_item_get_airline_index(msg);
#else
	memcpy(airline_item, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_AIRLINE_ITEM_LEN);
#endif
}
