// MESSAGE TEAM_INIT PACKING

#define MAVLINK_MSG_ID_TEAM_INIT 182

typedef struct __mavlink_team_init_t {
 int32_t Lat_asmb; /*< Marshalling point Latitude*/
 int32_t Lon_asmb; /*< Marshalling point Longitude*/
 int32_t Lat_dism; /*< Break up point Latitude*/
 int32_t Lon_dism; /*< Break up point Longitude*/
 int16_t Alt_asmb; /*< Marshalling point Altitude*/
 uint16_t psiInit_rad_asmb; /*< Team Yaw*/
 int16_t Alt_dism; /*< Break up point Altitude*/
 uint16_t psiInit_rad_dism; /*< Team Yaw*/
 int16_t formation_param1; /*< empty*/
 int16_t formation_param2; /*< empty*/
 int16_t formation_param3; /*< empty*/
 int16_t formation_param4; /*< empty*/
 int16_t formation_param5; /*< empty*/
 uint8_t formationTypeNo; /*< Team serial number*/
} mavlink_team_init_t;

#define MAVLINK_MSG_ID_TEAM_INIT_LEN 35
#define MAVLINK_MSG_ID_TEAM_INIT_MIN_LEN 35
#define MAVLINK_MSG_ID_182_LEN 35
#define MAVLINK_MSG_ID_182_MIN_LEN 35

#define MAVLINK_MSG_ID_TEAM_INIT_CRC 211
#define MAVLINK_MSG_ID_182_CRC 211



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TEAM_INIT { \
	182, \
	"TEAM_INIT", \
	14, \
	{  { "Lat_asmb", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_team_init_t, Lat_asmb) }, \
         { "Lon_asmb", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_team_init_t, Lon_asmb) }, \
         { "Lat_dism", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_team_init_t, Lat_dism) }, \
         { "Lon_dism", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_team_init_t, Lon_dism) }, \
         { "Alt_asmb", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_team_init_t, Alt_asmb) }, \
         { "psiInit_rad_asmb", NULL, MAVLINK_TYPE_UINT16_T, 0, 18, offsetof(mavlink_team_init_t, psiInit_rad_asmb) }, \
         { "Alt_dism", NULL, MAVLINK_TYPE_INT16_T, 0, 20, offsetof(mavlink_team_init_t, Alt_dism) }, \
         { "psiInit_rad_dism", NULL, MAVLINK_TYPE_UINT16_T, 0, 22, offsetof(mavlink_team_init_t, psiInit_rad_dism) }, \
         { "formation_param1", NULL, MAVLINK_TYPE_INT16_T, 0, 24, offsetof(mavlink_team_init_t, formation_param1) }, \
         { "formation_param2", NULL, MAVLINK_TYPE_INT16_T, 0, 26, offsetof(mavlink_team_init_t, formation_param2) }, \
         { "formation_param3", NULL, MAVLINK_TYPE_INT16_T, 0, 28, offsetof(mavlink_team_init_t, formation_param3) }, \
         { "formation_param4", NULL, MAVLINK_TYPE_INT16_T, 0, 30, offsetof(mavlink_team_init_t, formation_param4) }, \
         { "formation_param5", NULL, MAVLINK_TYPE_INT16_T, 0, 32, offsetof(mavlink_team_init_t, formation_param5) }, \
         { "formationTypeNo", NULL, MAVLINK_TYPE_UINT8_T, 0, 34, offsetof(mavlink_team_init_t, formationTypeNo) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TEAM_INIT { \
	"TEAM_INIT", \
	14, \
	{  { "Lat_asmb", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_team_init_t, Lat_asmb) }, \
         { "Lon_asmb", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_team_init_t, Lon_asmb) }, \
         { "Lat_dism", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_team_init_t, Lat_dism) }, \
         { "Lon_dism", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_team_init_t, Lon_dism) }, \
         { "Alt_asmb", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_team_init_t, Alt_asmb) }, \
         { "psiInit_rad_asmb", NULL, MAVLINK_TYPE_UINT16_T, 0, 18, offsetof(mavlink_team_init_t, psiInit_rad_asmb) }, \
         { "Alt_dism", NULL, MAVLINK_TYPE_INT16_T, 0, 20, offsetof(mavlink_team_init_t, Alt_dism) }, \
         { "psiInit_rad_dism", NULL, MAVLINK_TYPE_UINT16_T, 0, 22, offsetof(mavlink_team_init_t, psiInit_rad_dism) }, \
         { "formation_param1", NULL, MAVLINK_TYPE_INT16_T, 0, 24, offsetof(mavlink_team_init_t, formation_param1) }, \
         { "formation_param2", NULL, MAVLINK_TYPE_INT16_T, 0, 26, offsetof(mavlink_team_init_t, formation_param2) }, \
         { "formation_param3", NULL, MAVLINK_TYPE_INT16_T, 0, 28, offsetof(mavlink_team_init_t, formation_param3) }, \
         { "formation_param4", NULL, MAVLINK_TYPE_INT16_T, 0, 30, offsetof(mavlink_team_init_t, formation_param4) }, \
         { "formation_param5", NULL, MAVLINK_TYPE_INT16_T, 0, 32, offsetof(mavlink_team_init_t, formation_param5) }, \
         { "formationTypeNo", NULL, MAVLINK_TYPE_UINT8_T, 0, 34, offsetof(mavlink_team_init_t, formationTypeNo) }, \
         } \
}
#endif

/**
 * @brief Pack a team_init message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param Lat_asmb Marshalling point Latitude
 * @param Lon_asmb Marshalling point Longitude
 * @param Alt_asmb Marshalling point Altitude
 * @param psiInit_rad_asmb Team Yaw
 * @param Lat_dism Break up point Latitude
 * @param Lon_dism Break up point Longitude
 * @param Alt_dism Break up point Altitude
 * @param psiInit_rad_dism Team Yaw
 * @param formationTypeNo Team serial number
 * @param formation_param1 empty
 * @param formation_param2 empty
 * @param formation_param3 empty
 * @param formation_param4 empty
 * @param formation_param5 empty
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_team_init_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       int32_t Lat_asmb, int32_t Lon_asmb, int16_t Alt_asmb, uint16_t psiInit_rad_asmb, int32_t Lat_dism, int32_t Lon_dism, int16_t Alt_dism, uint16_t psiInit_rad_dism, uint8_t formationTypeNo, int16_t formation_param1, int16_t formation_param2, int16_t formation_param3, int16_t formation_param4, int16_t formation_param5)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TEAM_INIT_LEN];
	_mav_put_int32_t(buf, 0, Lat_asmb);
	_mav_put_int32_t(buf, 4, Lon_asmb);
	_mav_put_int32_t(buf, 8, Lat_dism);
	_mav_put_int32_t(buf, 12, Lon_dism);
	_mav_put_int16_t(buf, 16, Alt_asmb);
	_mav_put_uint16_t(buf, 18, psiInit_rad_asmb);
	_mav_put_int16_t(buf, 20, Alt_dism);
	_mav_put_uint16_t(buf, 22, psiInit_rad_dism);
	_mav_put_int16_t(buf, 24, formation_param1);
	_mav_put_int16_t(buf, 26, formation_param2);
	_mav_put_int16_t(buf, 28, formation_param3);
	_mav_put_int16_t(buf, 30, formation_param4);
	_mav_put_int16_t(buf, 32, formation_param5);
	_mav_put_uint8_t(buf, 34, formationTypeNo);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TEAM_INIT_LEN);
#else
	mavlink_team_init_t packet;
	packet.Lat_asmb = Lat_asmb;
	packet.Lon_asmb = Lon_asmb;
	packet.Lat_dism = Lat_dism;
	packet.Lon_dism = Lon_dism;
	packet.Alt_asmb = Alt_asmb;
	packet.psiInit_rad_asmb = psiInit_rad_asmb;
	packet.Alt_dism = Alt_dism;
	packet.psiInit_rad_dism = psiInit_rad_dism;
	packet.formation_param1 = formation_param1;
	packet.formation_param2 = formation_param2;
	packet.formation_param3 = formation_param3;
	packet.formation_param4 = formation_param4;
	packet.formation_param5 = formation_param5;
	packet.formationTypeNo = formationTypeNo;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TEAM_INIT_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TEAM_INIT;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id,  MAVLINK_MSG_ID_TEAM_INIT_LEN, MAVLINK_MSG_ID_TEAM_INIT_CRC);
#else
	return mavlink_finalize_message(msg, system_id, component_id,  MAVLINK_MSG_ID_TEAM_INIT_LEN);
#endif

}

/**
 * @brief Pack a team_init message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param Lat_asmb Marshalling point Latitude
 * @param Lon_asmb Marshalling point Longitude
 * @param Alt_asmb Marshalling point Altitude
 * @param psiInit_rad_asmb Team Yaw
 * @param Lat_dism Break up point Latitude
 * @param Lon_dism Break up point Longitude
 * @param Alt_dism Break up point Altitude
 * @param psiInit_rad_dism Team Yaw
 * @param formationTypeNo Team serial number
 * @param formation_param1 empty
 * @param formation_param2 empty
 * @param formation_param3 empty
 * @param formation_param4 empty
 * @param formation_param5 empty
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_team_init_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           int32_t Lat_asmb,int32_t Lon_asmb,int16_t Alt_asmb,uint16_t psiInit_rad_asmb,int32_t Lat_dism,int32_t Lon_dism,int16_t Alt_dism,uint16_t psiInit_rad_dism,uint8_t formationTypeNo,int16_t formation_param1,int16_t formation_param2,int16_t formation_param3,int16_t formation_param4,int16_t formation_param5)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TEAM_INIT_LEN];
	_mav_put_int32_t(buf, 0, Lat_asmb);
	_mav_put_int32_t(buf, 4, Lon_asmb);
	_mav_put_int32_t(buf, 8, Lat_dism);
	_mav_put_int32_t(buf, 12, Lon_dism);
	_mav_put_int16_t(buf, 16, Alt_asmb);
	_mav_put_uint16_t(buf, 18, psiInit_rad_asmb);
	_mav_put_int16_t(buf, 20, Alt_dism);
	_mav_put_uint16_t(buf, 22, psiInit_rad_dism);
	_mav_put_int16_t(buf, 24, formation_param1);
	_mav_put_int16_t(buf, 26, formation_param2);
	_mav_put_int16_t(buf, 28, formation_param3);
	_mav_put_int16_t(buf, 30, formation_param4);
	_mav_put_int16_t(buf, 32, formation_param5);
	_mav_put_uint8_t(buf, 34, formationTypeNo);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TEAM_INIT_LEN);
#else
	mavlink_team_init_t packet;
	packet.Lat_asmb = Lat_asmb;
	packet.Lon_asmb = Lon_asmb;
	packet.Lat_dism = Lat_dism;
	packet.Lon_dism = Lon_dism;
	packet.Alt_asmb = Alt_asmb;
	packet.psiInit_rad_asmb = psiInit_rad_asmb;
	packet.Alt_dism = Alt_dism;
	packet.psiInit_rad_dism = psiInit_rad_dism;
	packet.formation_param1 = formation_param1;
	packet.formation_param2 = formation_param2;
	packet.formation_param3 = formation_param3;
	packet.formation_param4 = formation_param4;
	packet.formation_param5 = formation_param5;
	packet.formationTypeNo = formationTypeNo;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TEAM_INIT_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TEAM_INIT;
#if MAVLINK_CRC_EXTRA
		return mavlink_finalize_message_chan(msg, system_id, component_id, chan,  MAVLINK_MSG_ID_TEAM_INIT_LEN, MAVLINK_MSG_ID_TEAM_INIT_CRC);
#else
		return mavlink_finalize_message_chan(msg, system_id, component_id, chan,  MAVLINK_MSG_ID_TEAM_INIT_LEN);
#endif

}

/**
 * @brief Encode a team_init struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param team_init C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_team_init_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_team_init_t* team_init)
{
	return mavlink_msg_team_init_pack(system_id, component_id, msg, team_init->Lat_asmb, team_init->Lon_asmb, team_init->Alt_asmb, team_init->psiInit_rad_asmb, team_init->Lat_dism, team_init->Lon_dism, team_init->Alt_dism, team_init->psiInit_rad_dism, team_init->formationTypeNo, team_init->formation_param1, team_init->formation_param2, team_init->formation_param3, team_init->formation_param4, team_init->formation_param5);
}

/**
 * @brief Encode a team_init struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param team_init C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_team_init_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_team_init_t* team_init)
{
	return mavlink_msg_team_init_pack_chan(system_id, component_id, chan, msg, team_init->Lat_asmb, team_init->Lon_asmb, team_init->Alt_asmb, team_init->psiInit_rad_asmb, team_init->Lat_dism, team_init->Lon_dism, team_init->Alt_dism, team_init->psiInit_rad_dism, team_init->formationTypeNo, team_init->formation_param1, team_init->formation_param2, team_init->formation_param3, team_init->formation_param4, team_init->formation_param5);
}

/**
 * @brief Send a team_init message
 * @param chan MAVLink channel to send the message
 *
 * @param Lat_asmb Marshalling point Latitude
 * @param Lon_asmb Marshalling point Longitude
 * @param Alt_asmb Marshalling point Altitude
 * @param psiInit_rad_asmb Team Yaw
 * @param Lat_dism Break up point Latitude
 * @param Lon_dism Break up point Longitude
 * @param Alt_dism Break up point Altitude
 * @param psiInit_rad_dism Team Yaw
 * @param formationTypeNo Team serial number
 * @param formation_param1 empty
 * @param formation_param2 empty
 * @param formation_param3 empty
 * @param formation_param4 empty
 * @param formation_param5 empty
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_team_init_send(mavlink_channel_t chan, int32_t Lat_asmb, int32_t Lon_asmb, int16_t Alt_asmb, uint16_t psiInit_rad_asmb, int32_t Lat_dism, int32_t Lon_dism, int16_t Alt_dism, uint16_t psiInit_rad_dism, uint8_t formationTypeNo, int16_t formation_param1, int16_t formation_param2, int16_t formation_param3, int16_t formation_param4, int16_t formation_param5)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TEAM_INIT_LEN];
	_mav_put_int32_t(buf, 0, Lat_asmb);
	_mav_put_int32_t(buf, 4, Lon_asmb);
	_mav_put_int32_t(buf, 8, Lat_dism);
	_mav_put_int32_t(buf, 12, Lon_dism);
	_mav_put_int16_t(buf, 16, Alt_asmb);
	_mav_put_uint16_t(buf, 18, psiInit_rad_asmb);
	_mav_put_int16_t(buf, 20, Alt_dism);
	_mav_put_uint16_t(buf, 22, psiInit_rad_dism);
	_mav_put_int16_t(buf, 24, formation_param1);
	_mav_put_int16_t(buf, 26, formation_param2);
	_mav_put_int16_t(buf, 28, formation_param3);
	_mav_put_int16_t(buf, 30, formation_param4);
	_mav_put_int16_t(buf, 32, formation_param5);
	_mav_put_uint8_t(buf, 34, formationTypeNo);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEAM_INIT, buf, MAVLINK_MSG_ID_TEAM_INIT_MIN_LEN, MAVLINK_MSG_ID_TEAM_INIT_LEN, MAVLINK_MSG_ID_TEAM_INIT_CRC);
#else
	mavlink_team_init_t packet;
	packet.Lat_asmb = Lat_asmb;
	packet.Lon_asmb = Lon_asmb;
	packet.Lat_dism = Lat_dism;
	packet.Lon_dism = Lon_dism;
	packet.Alt_asmb = Alt_asmb;
	packet.psiInit_rad_asmb = psiInit_rad_asmb;
	packet.Alt_dism = Alt_dism;
	packet.psiInit_rad_dism = psiInit_rad_dism;
	packet.formation_param1 = formation_param1;
	packet.formation_param2 = formation_param2;
	packet.formation_param3 = formation_param3;
	packet.formation_param4 = formation_param4;
	packet.formation_param5 = formation_param5;
	packet.formationTypeNo = formationTypeNo;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEAM_INIT, (const char *)&packet, MAVLINK_MSG_ID_TEAM_INIT_MIN_LEN, MAVLINK_MSG_ID_TEAM_INIT_LEN, MAVLINK_MSG_ID_TEAM_INIT_CRC);
#endif
}

/**
 * @brief Send a team_init message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_team_init_send_struct(mavlink_channel_t chan, const mavlink_team_init_t* team_init)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_team_init_send(chan, team_init->Lat_asmb, team_init->Lon_asmb, team_init->Alt_asmb, team_init->psiInit_rad_asmb, team_init->Lat_dism, team_init->Lon_dism, team_init->Alt_dism, team_init->psiInit_rad_dism, team_init->formationTypeNo, team_init->formation_param1, team_init->formation_param2, team_init->formation_param3, team_init->formation_param4, team_init->formation_param5);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEAM_INIT, (const char *)team_init, MAVLINK_MSG_ID_TEAM_INIT_MIN_LEN, MAVLINK_MSG_ID_TEAM_INIT_LEN, MAVLINK_MSG_ID_TEAM_INIT_CRC);
#endif
}

#if MAVLINK_MSG_ID_TEAM_INIT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_team_init_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int32_t Lat_asmb, int32_t Lon_asmb, int16_t Alt_asmb, uint16_t psiInit_rad_asmb, int32_t Lat_dism, int32_t Lon_dism, int16_t Alt_dism, uint16_t psiInit_rad_dism, uint8_t formationTypeNo, int16_t formation_param1, int16_t formation_param2, int16_t formation_param3, int16_t formation_param4, int16_t formation_param5)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_int32_t(buf, 0, Lat_asmb);
	_mav_put_int32_t(buf, 4, Lon_asmb);
	_mav_put_int32_t(buf, 8, Lat_dism);
	_mav_put_int32_t(buf, 12, Lon_dism);
	_mav_put_int16_t(buf, 16, Alt_asmb);
	_mav_put_uint16_t(buf, 18, psiInit_rad_asmb);
	_mav_put_int16_t(buf, 20, Alt_dism);
	_mav_put_uint16_t(buf, 22, psiInit_rad_dism);
	_mav_put_int16_t(buf, 24, formation_param1);
	_mav_put_int16_t(buf, 26, formation_param2);
	_mav_put_int16_t(buf, 28, formation_param3);
	_mav_put_int16_t(buf, 30, formation_param4);
	_mav_put_int16_t(buf, 32, formation_param5);
	_mav_put_uint8_t(buf, 34, formationTypeNo);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEAM_INIT, buf, MAVLINK_MSG_ID_TEAM_INIT_MIN_LEN, MAVLINK_MSG_ID_TEAM_INIT_LEN, MAVLINK_MSG_ID_TEAM_INIT_CRC);
#else
	mavlink_team_init_t *packet = (mavlink_team_init_t *)msgbuf;
	packet->Lat_asmb = Lat_asmb;
	packet->Lon_asmb = Lon_asmb;
	packet->Lat_dism = Lat_dism;
	packet->Lon_dism = Lon_dism;
	packet->Alt_asmb = Alt_asmb;
	packet->psiInit_rad_asmb = psiInit_rad_asmb;
	packet->Alt_dism = Alt_dism;
	packet->psiInit_rad_dism = psiInit_rad_dism;
	packet->formation_param1 = formation_param1;
	packet->formation_param2 = formation_param2;
	packet->formation_param3 = formation_param3;
	packet->formation_param4 = formation_param4;
	packet->formation_param5 = formation_param5;
	packet->formationTypeNo = formationTypeNo;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEAM_INIT, (const char *)packet, MAVLINK_MSG_ID_TEAM_INIT_MIN_LEN, MAVLINK_MSG_ID_TEAM_INIT_LEN, MAVLINK_MSG_ID_TEAM_INIT_CRC);
#endif
}
#endif

#endif

// MESSAGE TEAM_INIT UNPACKING


/**
 * @brief Get field Lat_asmb from team_init message
 *
 * @return Marshalling point Latitude
 */
static inline int32_t mavlink_msg_team_init_get_Lat_asmb(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field Lon_asmb from team_init message
 *
 * @return Marshalling point Longitude
 */
static inline int32_t mavlink_msg_team_init_get_Lon_asmb(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field Alt_asmb from team_init message
 *
 * @return Marshalling point Altitude
 */
static inline int16_t mavlink_msg_team_init_get_Alt_asmb(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  16);
}

/**
 * @brief Get field psiInit_rad_asmb from team_init message
 *
 * @return Team Yaw
 */
static inline uint16_t mavlink_msg_team_init_get_psiInit_rad_asmb(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  18);
}

/**
 * @brief Get field Lat_dism from team_init message
 *
 * @return Break up point Latitude
 */
static inline int32_t mavlink_msg_team_init_get_Lat_dism(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field Lon_dism from team_init message
 *
 * @return Break up point Longitude
 */
static inline int32_t mavlink_msg_team_init_get_Lon_dism(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field Alt_dism from team_init message
 *
 * @return Break up point Altitude
 */
static inline int16_t mavlink_msg_team_init_get_Alt_dism(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  20);
}

/**
 * @brief Get field psiInit_rad_dism from team_init message
 *
 * @return Team Yaw
 */
static inline uint16_t mavlink_msg_team_init_get_psiInit_rad_dism(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  22);
}

/**
 * @brief Get field formationTypeNo from team_init message
 *
 * @return Team serial number
 */
static inline uint8_t mavlink_msg_team_init_get_formationTypeNo(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  34);
}

/**
 * @brief Get field formation_param1 from team_init message
 *
 * @return empty
 */
static inline int16_t mavlink_msg_team_init_get_formation_param1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  24);
}

/**
 * @brief Get field formation_param2 from team_init message
 *
 * @return empty
 */
static inline int16_t mavlink_msg_team_init_get_formation_param2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  26);
}

/**
 * @brief Get field formation_param3 from team_init message
 *
 * @return empty
 */
static inline int16_t mavlink_msg_team_init_get_formation_param3(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  28);
}

/**
 * @brief Get field formation_param4 from team_init message
 *
 * @return empty
 */
static inline int16_t mavlink_msg_team_init_get_formation_param4(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  30);
}

/**
 * @brief Get field formation_param5 from team_init message
 *
 * @return empty
 */
static inline int16_t mavlink_msg_team_init_get_formation_param5(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  32);
}

/**
 * @brief Decode a team_init message into a struct
 *
 * @param msg The message to decode
 * @param team_init C-struct to decode the message contents into
 */
static inline void mavlink_msg_team_init_decode(const mavlink_message_t* msg, mavlink_team_init_t* team_init)
{
#if MAVLINK_NEED_BYTE_SWAP
	team_init->Lat_asmb = mavlink_msg_team_init_get_Lat_asmb(msg);
	team_init->Lon_asmb = mavlink_msg_team_init_get_Lon_asmb(msg);
	team_init->Lat_dism = mavlink_msg_team_init_get_Lat_dism(msg);
	team_init->Lon_dism = mavlink_msg_team_init_get_Lon_dism(msg);
	team_init->Alt_asmb = mavlink_msg_team_init_get_Alt_asmb(msg);
	team_init->psiInit_rad_asmb = mavlink_msg_team_init_get_psiInit_rad_asmb(msg);
	team_init->Alt_dism = mavlink_msg_team_init_get_Alt_dism(msg);
	team_init->psiInit_rad_dism = mavlink_msg_team_init_get_psiInit_rad_dism(msg);
	team_init->formation_param1 = mavlink_msg_team_init_get_formation_param1(msg);
	team_init->formation_param2 = mavlink_msg_team_init_get_formation_param2(msg);
	team_init->formation_param3 = mavlink_msg_team_init_get_formation_param3(msg);
	team_init->formation_param4 = mavlink_msg_team_init_get_formation_param4(msg);
	team_init->formation_param5 = mavlink_msg_team_init_get_formation_param5(msg);
	team_init->formationTypeNo = mavlink_msg_team_init_get_formationTypeNo(msg);
#else
	memcpy(team_init, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_TEAM_INIT_LEN);
#endif
}
