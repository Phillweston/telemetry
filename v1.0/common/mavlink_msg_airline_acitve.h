// MESSAGE MISSION_CLEAR_ALL PACKING

#define MAVLINK_MSG_ID_AIRLINE_ACTIVE 226
#pragma pack(push,1)
typedef struct _mavlink_airline_active_t
{
   	uint8_t index1;  /*	起飞航线序号*/
    uint16_t cmd1 ;  //   起飞航线类型
    uint8_t index2;  //	导航航线序号
    uint16_t cmd2 ;  //   导航航线类型
    uint8_t index3;  //	降落航线序号
    uint16_t cmd3 ;  //  降落航线类型 
    uint8_t target_system; /*< System ID*/
    uint8_t target_component; /*< Component ID*/
    
} mavlink_airline_active_t; 
#pragma pack(pop)


#define MAVLINK_MSG_ID_AIRLINE_ACTIVE_LEN 11
#define MAVLINK_MSG_ID_226_LEN 11

#define MAVLINK_MSG_ID_AIRLINE_ACTIVE_CRC 232
#define MAVLINK_MSG_ID_226_CRC 232



#define MAVLINK_MESSAGE_INFO_AIRLINE_ACTIVE { \
	"AIRLINE_ACTIVE", \
	8,\
	{\
	   { "index1", NULL, MAVLINK_TYPE_UINT8_T, 0, 0,    offsetof(mavlink_airline_active_t, index1) }, \
       { "cmd1", NULL, MAVLINK_TYPE_UINT16_T, 0, 1, offsetof(mavlink_airline_active_t, cmd1) }, \
       { "index2",NULL, MAVLINK_TYPE_UINT8_T, 0, 3,	  offsetof(mavlink_airline_active_t, index2) }, \
	   { "cmd2", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_airline_active_t, cmd2) }, \
	   { "index3",NULL, MAVLINK_TYPE_UINT8_T, 0, 6,	  offsetof(mavlink_airline_active_t, index3) }, \
	   { "cmd3", NULL, MAVLINK_TYPE_UINT16_T, 0, 7, offsetof(mavlink_airline_active_t, cmd3) }, \
       { "target_system",  NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_airline_active_t, target_system) }, \
	   { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_airline_active_t, target_component) }, \
      } \
}



// MESSAGE AIRLINE_ACITVE_ALL UNPACKING

/**
 * @brief Get field target_system from mission_clear_all message
 *
 * @return System ID
 */
static inline uint8_t mavlink_msg_airline_acitve_get_target_system(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Get field target_component from mission_clear_all message
 *
 * @return Component ID
 */
static inline uint8_t mavlink_msg_airline_acitve_get_target_component(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  10);
}
static inline uint8_t mavlink_msg_airline_acitve_get_index1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}


static inline uint8_t mavlink_msg_airline_active_get_cmd1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  1);
}

static inline uint8_t mavlink_msg_airline_acitve_get_index2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  3);
}


static inline uint8_t mavlink_msg_airline_active_get_cmd2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  4);
}

static inline uint8_t mavlink_msg_airline_acitve_get_index3(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  6);
}


static inline uint8_t mavlink_msg_airline_active_get_cmd3(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  7);
}


/**
 * @brief Decode a mission_clear_all message into a struct
 *
 * @param msg The message to decode
 * @param mission_clear_all C-struct to decode the message contents into
 */
static inline void mavlink_msg_airline_active_decode(const mavlink_message_t* msg, mavlink_airline_active_t* airline_active)
{
#if MAVLINK_NEED_BYTE_SWAP
	airline_active->target_system = mavlink_msg_airline_acitve_get_target_system(msg);
	airline_active->target_component = mavlink_msg_airline_acitve_get_target_component(msg);
	airline_active->index1= mavlink_msg_airline_acitve_get_index1(msg);
	airline_active->cmd1= mavlink_msg_airline_active_get_cmd1(msg);
	airline_active->index2= mavlink_msg_airline_acitve_get_index2(msg);
	airline_active->cmd2= mavlink_msg_airline_active_get_cmd2(msg);
	airline_active->index3= mavlink_msg_airline_acitve_get_index3(msg);
	airline_active->cmd3= mavlink_msg_airline_active_get_cmd3(msg);
#else
	memcpy(airline_active, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_AIRLINE_ACTIVE_LEN);
#endif
}
