// MESSAGE MISSION_COUNT PACKING

#define MAVLINK_MSG_ID_AIRLINE_INFO 224

#define MAVLINK_AIRLINE_MAX 10

#pragma pack(push,1)
struct air_line
{
 uint8_t id;     /*航线编号*/
 uint8_t upload; /*保存这个航线*/
 uint8_t active; /* 使用这个航线*/
 uint16_t count; /*航线包含航路点的个数*/
 uint16_t cmd;   /*航线类型*/
};


typedef struct __mavlink_airline_info_t
{
  uint8_t target_system; /*< System ID*/
  uint8_t target_component; /*< Component ID*/
  struct air_line  airline[MAVLINK_AIRLINE_MAX];
  
} mavlink_airline_info_t;
#pragma pack(pop)

#define MAVLINK_MSG_ID_AIRLINE_INFO_LEN MAVLINK_AIRLINE_MAX * sizeof(struct air_line) + 2
#define MAVLINK_MSG_ID_194_LEN MAVLINK_AIRLINE_MAX * sizeof(struct air_line) + 2

#define MAVLINK_MSG_ID_AIRLINE_INFO_CRC 221
#define MAVLINK_MSG_ID_194_CRC 221



#define MAVLINK_MESSAGE_INFO_AIRLINE_INFO { \
	"AIRLINE_INFO", \
	3, \
	{  \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_mission_count_t, target_system) },\
		 { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0,1, offsetof(mavlink_mission_count_t, target_component) }, \
         { "airline", NULL, struct air_line, 0, 2, offsetof(mavlink_mission_count_t, airline)}, \
         } \
}


// MESSAGE MISSION_COUNT UNPACKING


/**
 * @brief Get field target_system from mission_count message
 *
 * @return System ID
 */
static inline uint8_t mavlink_msg_airline_info_get_target_system(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field target_component from mission_count message
 *
 * @return Component ID
 */
static inline uint8_t mavlink_msg_airline_info_get_target_component(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field count from mission_count message
 *
 * @return Number of mission items in the sequence
 */
static inline void mavlink_msg_airline_info_get_airline_info(const mavlink_message_t* msg,mavlink_airline_info_t* airline_info)
{
	memcpy(airline_info->airline, _MAV_PAYLOAD(msg)+2, MAVLINK_MSG_ID_MISSION_COUNT_LEN-2);
}

/**
 * @brief Decode a mission_count message into a struct
 *
 * @param msg The message to decode
 * @param mission_count C-struct to decode the message contents into
 */
static inline void mavlink_msg_airline_info_decode(const mavlink_message_t* msg, mavlink_airline_info_t* airline_info)
{
#if MAVLINK_NEED_BYTE_SWAP
	mavlink_msg_airline_info_get_airline_info(msg, airline_info);
	airline_info->target_system = mavlink_msg_airline_info_get_target_system(msg);
	airline_info->target_component = mavlink_msg_airline_info_get_target_component(msg);
#else
	memcpy(airline_info, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_AIRLINE_INFO_LEN);
#endif
}
