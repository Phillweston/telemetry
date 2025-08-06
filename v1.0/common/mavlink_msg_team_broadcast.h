// MESSAGE TEAM_BROADCAST PACKING

#define MAVLINK_MSG_ID_TEAM_BROADCAST 183


typedef struct __mavlink_team_broadcast_t {
 int32_t Lat; /*< Marshalling point Latitude*/
 int32_t Lon; /*< Marshalling point Longitude*/
 int16_t Alt; /*< Marshalling point Altitude*/
 int16_t Hdot; /*< Hdot*/
 uint16_t Vground; /*< Vground*/
 uint16_t Vias; /*< Vias*/
 int16_t PsiCmd_rad; /*< PsiCmd_rad*/
 int16_t Psiv_rad; /*< Psiv_rad*/
 int16_t PhiCmd_rad; /*< PhiCmd_rad*/
 int16_t HCmd; /*< HCmd*/
 uint8_t destFollowPhyId; /*< Team ID*/
 uint8_t formationStateCmd; /*< Team ID*/
 uint8_t curAirlineNo; /*< airlineID*/
 uint8_t curWpNo; /*< airpointID*/
} mavlink_team_broadcast_t;

#define MAVLINK_MSG_ID_TEAM_BROADCAST_LEN 28
#define MAVLINK_MSG_ID_TEAM_BROADCAST_MIN_LEN 28
#define MAVLINK_MSG_ID_183_LEN 28
#define MAVLINK_MSG_ID_183_MIN_LEN 28

#define MAVLINK_MSG_ID_TEAM_BROADCAST_CRC 129
#define MAVLINK_MSG_ID_183_CRC 129



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TEAM_BROADCAST { \
	183, \
	"TEAM_BROADCAST", \
	14, \
	{  { "Lat", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_team_broadcast_t, Lat) }, \
         { "Lon", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_team_broadcast_t, Lon) }, \
         { "Alt", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_team_broadcast_t, Alt) }, \
         { "Hdot", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_team_broadcast_t, Hdot) }, \
         { "Vground", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_team_broadcast_t, Vground) }, \
         { "Vias", NULL, MAVLINK_TYPE_UINT16_T, 0, 14, offsetof(mavlink_team_broadcast_t, Vias) }, \
         { "PsiCmd_rad", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_team_broadcast_t, PsiCmd_rad) }, \
         { "Psiv_rad", NULL, MAVLINK_TYPE_INT16_T, 0, 18, offsetof(mavlink_team_broadcast_t, Psiv_rad) }, \
         { "PhiCmd_rad", NULL, MAVLINK_TYPE_INT16_T, 0, 20, offsetof(mavlink_team_broadcast_t, PhiCmd_rad) }, \
         { "HCmd", NULL, MAVLINK_TYPE_INT16_T, 0, 22, offsetof(mavlink_team_broadcast_t, HCmd) }, \
         { "destFollowPhyId", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_team_broadcast_t, destFollowPhyId) }, \
         { "formationStateCmd", NULL, MAVLINK_TYPE_UINT8_T, 0, 25, offsetof(mavlink_team_broadcast_t, formationStateCmd) }, \
         { "curAirlineNo", NULL, MAVLINK_TYPE_UINT8_T, 0, 26, offsetof(mavlink_team_broadcast_t, curAirlineNo) }, \
         { "curWpNo", NULL, MAVLINK_TYPE_UINT8_T, 0, 27, offsetof(mavlink_team_broadcast_t, curWpNo) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TEAM_BROADCAST { \
	"TEAM_BROADCAST", \
	14, \
	{  { "Lat", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_team_broadcast_t, Lat) }, \
         { "Lon", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_team_broadcast_t, Lon) }, \
         { "Alt", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_team_broadcast_t, Alt) }, \
         { "Hdot", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_team_broadcast_t, Hdot) }, \
         { "Vground", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_team_broadcast_t, Vground) }, \
         { "Vias", NULL, MAVLINK_TYPE_UINT16_T, 0, 14, offsetof(mavlink_team_broadcast_t, Vias) }, \
         { "PsiCmd_rad", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_team_broadcast_t, PsiCmd_rad) }, \
         { "Psiv_rad", NULL, MAVLINK_TYPE_INT16_T, 0, 18, offsetof(mavlink_team_broadcast_t, Psiv_rad) }, \
         { "PhiCmd_rad", NULL, MAVLINK_TYPE_INT16_T, 0, 20, offsetof(mavlink_team_broadcast_t, PhiCmd_rad) }, \
         { "HCmd", NULL, MAVLINK_TYPE_INT16_T, 0, 22, offsetof(mavlink_team_broadcast_t, HCmd) }, \
         { "destFollowPhyId", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_team_broadcast_t, destFollowPhyId) }, \
         { "formationStateCmd", NULL, MAVLINK_TYPE_UINT8_T, 0, 25, offsetof(mavlink_team_broadcast_t, formationStateCmd) }, \
         { "curAirlineNo", NULL, MAVLINK_TYPE_UINT8_T, 0, 26, offsetof(mavlink_team_broadcast_t, curAirlineNo) }, \
         { "curWpNo", NULL, MAVLINK_TYPE_UINT8_T, 0, 27, offsetof(mavlink_team_broadcast_t, curWpNo) }, \
         } \
}
#endif

/**
 * @brief Pack a team_broadcast message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param destFollowPhyId Team ID
 * @param formationStateCmd Team ID
 * @param Lat Marshalling point Latitude
 * @param Lon Marshalling point Longitude
 * @param Alt Marshalling point Altitude
 * @param Hdot Hdot
 * @param Vground Vground
 * @param Vias Vias
 * @param PsiCmd_rad PsiCmd_rad
 * @param Psiv_rad Psiv_rad
 * @param PhiCmd_rad PhiCmd_rad
 * @param HCmd HCmd
 * @param curAirlineNo airlineID
 * @param curWpNo airpointID
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_team_broadcast_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t destFollowPhyId, uint8_t formationStateCmd, int32_t Lat, int32_t Lon, int16_t Alt, int16_t Hdot, uint16_t Vground, uint16_t Vias, int16_t PsiCmd_rad, int16_t Psiv_rad, int16_t PhiCmd_rad, int16_t HCmd, uint8_t curAirlineNo, uint8_t curWpNo)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TEAM_BROADCAST_LEN];
	_mav_put_int32_t(buf, 0, Lat);
	_mav_put_int32_t(buf, 4, Lon);
	_mav_put_int16_t(buf, 8, Alt);
	_mav_put_int16_t(buf, 10, Hdot);
	_mav_put_uint16_t(buf, 12, Vground);
	_mav_put_uint16_t(buf, 14, Vias);
	_mav_put_int16_t(buf, 16, PsiCmd_rad);
	_mav_put_int16_t(buf, 18, Psiv_rad);
	_mav_put_int16_t(buf, 20, PhiCmd_rad);
	_mav_put_int16_t(buf, 22, HCmd);
	_mav_put_uint8_t(buf, 24, destFollowPhyId);
	_mav_put_uint8_t(buf, 25, formationStateCmd);
	_mav_put_uint8_t(buf, 26, curAirlineNo);
	_mav_put_uint8_t(buf, 27, curWpNo);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TEAM_BROADCAST_LEN);
#else
	mavlink_team_broadcast_t packet;
	packet.Lat = Lat;
	packet.Lon = Lon;
	packet.Alt = Alt;
	packet.Hdot = Hdot;
	packet.Vground = Vground;
	packet.Vias = Vias;
	packet.PsiCmd_rad = PsiCmd_rad;
	packet.Psiv_rad = Psiv_rad;
	packet.PhiCmd_rad = PhiCmd_rad;
	packet.HCmd = HCmd;
	packet.destFollowPhyId = destFollowPhyId;
	packet.formationStateCmd = formationStateCmd;
	packet.curAirlineNo = curAirlineNo;
	packet.curWpNo = curWpNo;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TEAM_BROADCAST_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TEAM_BROADCAST;
#if MAVLINK_CRC_EXTRA
	return mavlink_finalize_message(msg, system_id, component_id,  MAVLINK_MSG_ID_TEAM_BROADCAST_LEN, MAVLINK_MSG_ID_TEAM_BROADCAST_CRC);
#else
	return mavlink_finalize_message(msg, system_id, component_id,  MAVLINK_MSG_ID_TEAM_BROADCAST_LEN);
#endif

}

/**
 * @brief Pack a team_broadcast message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param destFollowPhyId Team ID
 * @param formationStateCmd Team ID
 * @param Lat Marshalling point Latitude
 * @param Lon Marshalling point Longitude
 * @param Alt Marshalling point Altitude
 * @param Hdot Hdot
 * @param Vground Vground
 * @param Vias Vias
 * @param PsiCmd_rad PsiCmd_rad
 * @param Psiv_rad Psiv_rad
 * @param PhiCmd_rad PhiCmd_rad
 * @param HCmd HCmd
 * @param curAirlineNo airlineID
 * @param curWpNo airpointID
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_team_broadcast_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t destFollowPhyId,uint8_t formationStateCmd,int32_t Lat,int32_t Lon,int16_t Alt,int16_t Hdot,uint16_t Vground,uint16_t Vias,int16_t PsiCmd_rad,int16_t Psiv_rad,int16_t PhiCmd_rad,int16_t HCmd,uint8_t curAirlineNo,uint8_t curWpNo)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TEAM_BROADCAST_LEN];
	_mav_put_int32_t(buf, 0, Lat);
	_mav_put_int32_t(buf, 4, Lon);
	_mav_put_int16_t(buf, 8, Alt);
	_mav_put_int16_t(buf, 10, Hdot);
	_mav_put_uint16_t(buf, 12, Vground);
	_mav_put_uint16_t(buf, 14, Vias);
	_mav_put_int16_t(buf, 16, PsiCmd_rad);
	_mav_put_int16_t(buf, 18, Psiv_rad);
	_mav_put_int16_t(buf, 20, PhiCmd_rad);
	_mav_put_int16_t(buf, 22, HCmd);
	_mav_put_uint8_t(buf, 24, destFollowPhyId);
	_mav_put_uint8_t(buf, 25, formationStateCmd);
	_mav_put_uint8_t(buf, 26, curAirlineNo);
	_mav_put_uint8_t(buf, 27, curWpNo);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TEAM_BROADCAST_LEN);
#else
	mavlink_team_broadcast_t packet;
	packet.Lat = Lat;
	packet.Lon = Lon;
	packet.Alt = Alt;
	packet.Hdot = Hdot;
	packet.Vground = Vground;
	packet.Vias = Vias;
	packet.PsiCmd_rad = PsiCmd_rad;
	packet.Psiv_rad = Psiv_rad;
	packet.PhiCmd_rad = PhiCmd_rad;
	packet.HCmd = HCmd;
	packet.destFollowPhyId = destFollowPhyId;
	packet.formationStateCmd = formationStateCmd;
	packet.curAirlineNo = curAirlineNo;
	packet.curWpNo = curWpNo;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TEAM_BROADCAST_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TEAM_BROADCAST;
#if MAVLINK_CRC_EXTRA
	return mavlink_finalize_message_chan(msg, system_id, component_id, chan,  MAVLINK_MSG_ID_TEAM_BROADCAST_LEN, MAVLINK_MSG_ID_TEAM_BROADCAST_CRC);
#else
	return mavlink_finalize_message_chan(msg, system_id, component_id, chan,  MAVLINK_MSG_ID_TEAM_BROADCAST_LEN);
#endif

}

/**
 * @brief Encode a team_broadcast struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param team_broadcast C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_team_broadcast_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_team_broadcast_t* team_broadcast)
{
	return mavlink_msg_team_broadcast_pack(system_id, component_id, msg, team_broadcast->destFollowPhyId, team_broadcast->formationStateCmd, team_broadcast->Lat, team_broadcast->Lon, team_broadcast->Alt, team_broadcast->Hdot, team_broadcast->Vground, team_broadcast->Vias, team_broadcast->PsiCmd_rad, team_broadcast->Psiv_rad, team_broadcast->PhiCmd_rad, team_broadcast->HCmd, team_broadcast->curAirlineNo, team_broadcast->curWpNo);
}

/**
 * @brief Encode a team_broadcast struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param team_broadcast C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_team_broadcast_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_team_broadcast_t* team_broadcast)
{
	return mavlink_msg_team_broadcast_pack_chan(system_id, component_id, chan, msg, team_broadcast->destFollowPhyId, team_broadcast->formationStateCmd, team_broadcast->Lat, team_broadcast->Lon, team_broadcast->Alt, team_broadcast->Hdot, team_broadcast->Vground, team_broadcast->Vias, team_broadcast->PsiCmd_rad, team_broadcast->Psiv_rad, team_broadcast->PhiCmd_rad, team_broadcast->HCmd, team_broadcast->curAirlineNo, team_broadcast->curWpNo);
}

/**
 * @brief Send a team_broadcast message
 * @param chan MAVLink channel to send the message
 *
 * @param destFollowPhyId Team ID
 * @param formationStateCmd Team ID
 * @param Lat Marshalling point Latitude
 * @param Lon Marshalling point Longitude
 * @param Alt Marshalling point Altitude
 * @param Hdot Hdot
 * @param Vground Vground
 * @param Vias Vias
 * @param PsiCmd_rad PsiCmd_rad
 * @param Psiv_rad Psiv_rad
 * @param PhiCmd_rad PhiCmd_rad
 * @param HCmd HCmd
 * @param curAirlineNo airlineID
 * @param curWpNo airpointID
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_team_broadcast_send(mavlink_channel_t chan, uint8_t destFollowPhyId, uint8_t formationStateCmd, int32_t Lat, int32_t Lon, int16_t Alt, int16_t Hdot, uint16_t Vground, uint16_t Vias, int16_t PsiCmd_rad, int16_t Psiv_rad, int16_t PhiCmd_rad, int16_t HCmd, uint8_t curAirlineNo, uint8_t curWpNo)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TEAM_BROADCAST_LEN];
	_mav_put_int32_t(buf, 0, Lat);
	_mav_put_int32_t(buf, 4, Lon);
	_mav_put_int16_t(buf, 8, Alt);
	_mav_put_int16_t(buf, 10, Hdot);
	_mav_put_uint16_t(buf, 12, Vground);
	_mav_put_uint16_t(buf, 14, Vias);
	_mav_put_int16_t(buf, 16, PsiCmd_rad);
	_mav_put_int16_t(buf, 18, Psiv_rad);
	_mav_put_int16_t(buf, 20, PhiCmd_rad);
	_mav_put_int16_t(buf, 22, HCmd);
	_mav_put_uint8_t(buf, 24, destFollowPhyId);
	_mav_put_uint8_t(buf, 25, formationStateCmd);
	_mav_put_uint8_t(buf, 26, curAirlineNo);
	_mav_put_uint8_t(buf, 27, curWpNo);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEAM_BROADCAST, buf, MAVLINK_MSG_ID_TEAM_BROADCAST_MIN_LEN, MAVLINK_MSG_ID_TEAM_BROADCAST_LEN, MAVLINK_MSG_ID_TEAM_BROADCAST_CRC);
#else
	mavlink_team_broadcast_t packet;
	packet.Lat = Lat;
	packet.Lon = Lon;
	packet.Alt = Alt;
	packet.Hdot = Hdot;
	packet.Vground = Vground;
	packet.Vias = Vias;
	packet.PsiCmd_rad = PsiCmd_rad;
	packet.Psiv_rad = Psiv_rad;
	packet.PhiCmd_rad = PhiCmd_rad;
	packet.HCmd = HCmd;
	packet.destFollowPhyId = destFollowPhyId;
	packet.formationStateCmd = formationStateCmd;
	packet.curAirlineNo = curAirlineNo;
	packet.curWpNo = curWpNo;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEAM_BROADCAST, (const char *)&packet, MAVLINK_MSG_ID_TEAM_BROADCAST_MIN_LEN, MAVLINK_MSG_ID_TEAM_BROADCAST_LEN, MAVLINK_MSG_ID_TEAM_BROADCAST_CRC);
#endif
}

/**
 * @brief Send a team_broadcast message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_team_broadcast_send_struct(mavlink_channel_t chan, const mavlink_team_broadcast_t* team_broadcast)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_team_broadcast_send(chan, team_broadcast->destFollowPhyId, team_broadcast->formationStateCmd, team_broadcast->Lat, team_broadcast->Lon, team_broadcast->Alt, team_broadcast->Hdot, team_broadcast->Vground, team_broadcast->Vias, team_broadcast->PsiCmd_rad, team_broadcast->Psiv_rad, team_broadcast->PhiCmd_rad, team_broadcast->HCmd, team_broadcast->curAirlineNo, team_broadcast->curWpNo);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEAM_BROADCAST, (const char *)team_broadcast, MAVLINK_MSG_ID_TEAM_BROADCAST_MIN_LEN, MAVLINK_MSG_ID_TEAM_BROADCAST_LEN, MAVLINK_MSG_ID_TEAM_BROADCAST_CRC);
#endif
}

#if MAVLINK_MSG_ID_TEAM_BROADCAST_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_team_broadcast_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t destFollowPhyId, uint8_t formationStateCmd, int32_t Lat, int32_t Lon, int16_t Alt, int16_t Hdot, uint16_t Vground, uint16_t Vias, int16_t PsiCmd_rad, int16_t Psiv_rad, int16_t PhiCmd_rad, int16_t HCmd, uint8_t curAirlineNo, uint8_t curWpNo)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_int32_t(buf, 0, Lat);
	_mav_put_int32_t(buf, 4, Lon);
	_mav_put_int16_t(buf, 8, Alt);
	_mav_put_int16_t(buf, 10, Hdot);
	_mav_put_uint16_t(buf, 12, Vground);
	_mav_put_uint16_t(buf, 14, Vias);
	_mav_put_int16_t(buf, 16, PsiCmd_rad);
	_mav_put_int16_t(buf, 18, Psiv_rad);
	_mav_put_int16_t(buf, 20, PhiCmd_rad);
	_mav_put_int16_t(buf, 22, HCmd);
	_mav_put_uint8_t(buf, 24, destFollowPhyId);
	_mav_put_uint8_t(buf, 25, formationStateCmd);
	_mav_put_uint8_t(buf, 26, curAirlineNo);
	_mav_put_uint8_t(buf, 27, curWpNo);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEAM_BROADCAST, buf, MAVLINK_MSG_ID_TEAM_BROADCAST_MIN_LEN, MAVLINK_MSG_ID_TEAM_BROADCAST_LEN, MAVLINK_MSG_ID_TEAM_BROADCAST_CRC);
#else
	mavlink_team_broadcast_t *packet = (mavlink_team_broadcast_t *)msgbuf;
	packet->Lat = Lat;
	packet->Lon = Lon;
	packet->Alt = Alt;
	packet->Hdot = Hdot;
	packet->Vground = Vground;
	packet->Vias = Vias;
	packet->PsiCmd_rad = PsiCmd_rad;
	packet->Psiv_rad = Psiv_rad;
	packet->PhiCmd_rad = PhiCmd_rad;
	packet->HCmd = HCmd;
	packet->destFollowPhyId = destFollowPhyId;
	packet->formationStateCmd = formationStateCmd;
	packet->curAirlineNo = curAirlineNo;
	packet->curWpNo = curWpNo;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEAM_BROADCAST, (const char *)packet, MAVLINK_MSG_ID_TEAM_BROADCAST_MIN_LEN, MAVLINK_MSG_ID_TEAM_BROADCAST_LEN, MAVLINK_MSG_ID_TEAM_BROADCAST_CRC);
#endif
}
#endif

#endif

// MESSAGE TEAM_BROADCAST UNPACKING


/**
 * @brief Get field destFollowPhyId from team_broadcast message
 *
 * @return Team ID
 */
static inline uint8_t mavlink_msg_team_broadcast_get_destFollowPhyId(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  24);
}

/**
 * @brief Get field formationStateCmd from team_broadcast message
 *
 * @return Team ID
 */
static inline uint8_t mavlink_msg_team_broadcast_get_formationStateCmd(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  25);
}

/**
 * @brief Get field Lat from team_broadcast message
 *
 * @return Marshalling point Latitude
 */
static inline int32_t mavlink_msg_team_broadcast_get_Lat(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field Lon from team_broadcast message
 *
 * @return Marshalling point Longitude
 */
static inline int32_t mavlink_msg_team_broadcast_get_Lon(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field Alt from team_broadcast message
 *
 * @return Marshalling point Altitude
 */
static inline int16_t mavlink_msg_team_broadcast_get_Alt(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  8);
}

/**
 * @brief Get field Hdot from team_broadcast message
 *
 * @return Hdot
 */
static inline int16_t mavlink_msg_team_broadcast_get_Hdot(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  10);
}

/**
 * @brief Get field Vground from team_broadcast message
 *
 * @return Vground
 */
static inline uint16_t mavlink_msg_team_broadcast_get_Vground(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  12);
}

/**
 * @brief Get field Vias from team_broadcast message
 *
 * @return Vias
 */
static inline uint16_t mavlink_msg_team_broadcast_get_Vias(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  14);
}

/**
 * @brief Get field PsiCmd_rad from team_broadcast message
 *
 * @return PsiCmd_rad
 */
static inline int16_t mavlink_msg_team_broadcast_get_PsiCmd_rad(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  16);
}

/**
 * @brief Get field Psiv_rad from team_broadcast message
 *
 * @return Psiv_rad
 */
static inline int16_t mavlink_msg_team_broadcast_get_Psiv_rad(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  18);
}

/**
 * @brief Get field PhiCmd_rad from team_broadcast message
 *
 * @return PhiCmd_rad
 */
static inline int16_t mavlink_msg_team_broadcast_get_PhiCmd_rad(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  20);
}

/**
 * @brief Get field HCmd from team_broadcast message
 *
 * @return HCmd
 */
static inline int16_t mavlink_msg_team_broadcast_get_HCmd(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  22);
}

/**
 * @brief Get field curAirlineNo from team_broadcast message
 *
 * @return airlineID
 */
static inline uint8_t mavlink_msg_team_broadcast_get_curAirlineNo(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  26);
}

/**
 * @brief Get field curWpNo from team_broadcast message
 *
 * @return airpointID
 */
static inline uint8_t mavlink_msg_team_broadcast_get_curWpNo(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  27);
}

/**
 * @brief Decode a team_broadcast message into a struct
 *
 * @param msg The message to decode
 * @param team_broadcast C-struct to decode the message contents into
 */
static inline void mavlink_msg_team_broadcast_decode(const mavlink_message_t* msg, mavlink_team_broadcast_t* team_broadcast)
{
#if MAVLINK_NEED_BYTE_SWAP
	team_broadcast->Lat = mavlink_msg_team_broadcast_get_Lat(msg);
	team_broadcast->Lon = mavlink_msg_team_broadcast_get_Lon(msg);
	team_broadcast->Alt = mavlink_msg_team_broadcast_get_Alt(msg);
	team_broadcast->Hdot = mavlink_msg_team_broadcast_get_Hdot(msg);
	team_broadcast->Vground = mavlink_msg_team_broadcast_get_Vground(msg);
	team_broadcast->Vias = mavlink_msg_team_broadcast_get_Vias(msg);
	team_broadcast->PsiCmd_rad = mavlink_msg_team_broadcast_get_PsiCmd_rad(msg);
	team_broadcast->Psiv_rad = mavlink_msg_team_broadcast_get_Psiv_rad(msg);
	team_broadcast->PhiCmd_rad = mavlink_msg_team_broadcast_get_PhiCmd_rad(msg);
	team_broadcast->HCmd = mavlink_msg_team_broadcast_get_HCmd(msg);
	team_broadcast->destFollowPhyId = mavlink_msg_team_broadcast_get_destFollowPhyId(msg);
	team_broadcast->formationStateCmd = mavlink_msg_team_broadcast_get_formationStateCmd(msg);
	team_broadcast->curAirlineNo = mavlink_msg_team_broadcast_get_curAirlineNo(msg);
	team_broadcast->curWpNo = mavlink_msg_team_broadcast_get_curWpNo(msg);
#else
	memcpy(team_broadcast, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_TEAM_BROADCAST_LEN);
#endif
}
