// MESSAGE TEAM_STATUS PACKING

#define MAVLINK_MSG_ID_TEAM_STATUS 181

typedef struct __mavlink_team_status_t {
 float dL2Leader; /*< Relative landscape location to leader */
 float dY2Leader; /*< Relative lateral location to leader */
 float dH2Leader; /*< Relative altitude location to leader*/
 float Psiv; /*< Track angle*/
 float FormationInitOk; /*< Formation Init Ok*/
 uint8_t Formation_PosID; /*< Team ID*/
 uint8_t Formation_mode; /*< Team Mode*/
} mavlink_team_status_t;

#define MAVLINK_MSG_ID_TEAM_STATUS_LEN 22
#define MAVLINK_MSG_ID_TEAM_STATUS_MIN_LEN 22
#define MAVLINK_MSG_ID_181_LEN 22
#define MAVLINK_MSG_ID_181_MIN_LEN 22

#define MAVLINK_MSG_ID_TEAM_STATUS_CRC 58
#define MAVLINK_MSG_ID_181_CRC 58



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TEAM_STATUS { \
	181, \
	"TEAM_STATUS", \
	7, \
	{  { "dL2Leader", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_team_status_t, dL2Leader) }, \
         { "dY2Leader", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_team_status_t, dY2Leader) }, \
         { "dH2Leader", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_team_status_t, dH2Leader) }, \
         { "Psiv", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_team_status_t, Psiv) }, \
         { "FormationInitOk", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_team_status_t, FormationInitOk) }, \
         { "Formation_PosID", NULL, MAVLINK_TYPE_UINT8_T, 0, 20, offsetof(mavlink_team_status_t, Formation_PosID) }, \
         { "Formation_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 21, offsetof(mavlink_team_status_t, Formation_mode) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TEAM_STATUS { \
	"TEAM_STATUS", \
	7, \
	{  { "dL2Leader", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_team_status_t, dL2Leader) }, \
         { "dY2Leader", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_team_status_t, dY2Leader) }, \
         { "dH2Leader", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_team_status_t, dH2Leader) }, \
         { "Psiv", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_team_status_t, Psiv) }, \
         { "FormationInitOk", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_team_status_t, FormationInitOk) }, \
         { "Formation_PosID", NULL, MAVLINK_TYPE_UINT8_T, 0, 20, offsetof(mavlink_team_status_t, Formation_PosID) }, \
         { "Formation_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 21, offsetof(mavlink_team_status_t, Formation_mode) }, \
         } \
}
#endif

/**
 * @brief Pack a team_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param Formation_PosID Team ID
 * @param Formation_mode Team Mode
 * @param dL2Leader Relative landscape location to leader 
 * @param dY2Leader Relative lateral location to leader 
 * @param dH2Leader Relative altitude location to leader
 * @param Psiv Track angle
 * @param FormationInitOk Formation Init Ok
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_team_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t Formation_PosID, uint8_t Formation_mode, float dL2Leader, float dY2Leader, float dH2Leader, float Psiv, float FormationInitOk)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TEAM_STATUS_LEN];
	_mav_put_float(buf, 0, dL2Leader);
	_mav_put_float(buf, 4, dY2Leader);
	_mav_put_float(buf, 8, dH2Leader);
	_mav_put_float(buf, 12, Psiv);
	_mav_put_float(buf, 16, FormationInitOk);
	_mav_put_uint8_t(buf, 20, Formation_PosID);
	_mav_put_uint8_t(buf, 21, Formation_mode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TEAM_STATUS_LEN);
#else
	mavlink_team_status_t packet;
	packet.dL2Leader = dL2Leader;
	packet.dY2Leader = dY2Leader;
	packet.dH2Leader = dH2Leader;
	packet.Psiv = Psiv;
	packet.FormationInitOk = FormationInitOk;
	packet.Formation_PosID = Formation_PosID;
	packet.Formation_mode = Formation_mode;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TEAM_STATUS_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TEAM_STATUS;
#if MAVLINK_CRC_EXTRA
		return mavlink_finalize_message(msg, system_id, component_id,  MAVLINK_MSG_ID_TEAM_STATUS_LEN, MAVLINK_MSG_ID_TEAM_STATUS_CRC);
#else
		return mavlink_finalize_message(msg, system_id, component_id,  MAVLINK_MSG_ID_TEAM_STATUS_LEN);
#endif
}

/**
 * @brief Pack a team_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param Formation_PosID Team ID
 * @param Formation_mode Team Mode
 * @param dL2Leader Relative landscape location to leader 
 * @param dY2Leader Relative lateral location to leader 
 * @param dH2Leader Relative altitude location to leader
 * @param Psiv Track angle
 * @param FormationInitOk Formation Init Ok
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_team_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t Formation_PosID,uint8_t Formation_mode,float dL2Leader,float dY2Leader,float dH2Leader,float Psiv,float FormationInitOk)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TEAM_STATUS_LEN];
	_mav_put_float(buf, 0, dL2Leader);
	_mav_put_float(buf, 4, dY2Leader);
	_mav_put_float(buf, 8, dH2Leader);
	_mav_put_float(buf, 12, Psiv);
	_mav_put_float(buf, 16, FormationInitOk);
	_mav_put_uint8_t(buf, 20, Formation_PosID);
	_mav_put_uint8_t(buf, 21, Formation_mode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TEAM_STATUS_LEN);
#else
	mavlink_team_status_t packet;
	packet.dL2Leader = dL2Leader;
	packet.dY2Leader = dY2Leader;
	packet.dH2Leader = dH2Leader;
	packet.Psiv = Psiv;
	packet.FormationInitOk = FormationInitOk;
	packet.Formation_PosID = Formation_PosID;
	packet.Formation_mode = Formation_mode;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TEAM_STATUS_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TEAM_STATUS;

#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan,  MAVLINK_MSG_ID_TEAM_STATUS_LEN, MAVLINK_MSG_ID_TEAM_STATUS_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan,  MAVLINK_MSG_ID_TEAM_STATUS_LEN);
#endif
}

/**
 * @brief Encode a team_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param team_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_team_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_team_status_t* team_status)
{
	return mavlink_msg_team_status_pack(system_id, component_id, msg, team_status->Formation_PosID, team_status->Formation_mode, team_status->dL2Leader, team_status->dY2Leader, team_status->dH2Leader, team_status->Psiv, team_status->FormationInitOk);
}

/**
 * @brief Encode a team_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param team_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_team_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_team_status_t* team_status)
{
	return mavlink_msg_team_status_pack_chan(system_id, component_id, chan, msg, team_status->Formation_PosID, team_status->Formation_mode, team_status->dL2Leader, team_status->dY2Leader, team_status->dH2Leader, team_status->Psiv, team_status->FormationInitOk);
}

/**
 * @brief Send a team_status message
 * @param chan MAVLink channel to send the message
 *
 * @param Formation_PosID Team ID
 * @param Formation_mode Team Mode
 * @param dL2Leader Relative landscape location to leader 
 * @param dY2Leader Relative lateral location to leader 
 * @param dH2Leader Relative altitude location to leader
 * @param Psiv Track angle
 * @param FormationInitOk Formation Init Ok
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_team_status_send(mavlink_channel_t chan, uint8_t Formation_PosID, uint8_t Formation_mode, float dL2Leader, float dY2Leader, float dH2Leader, float Psiv, float FormationInitOk)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TEAM_STATUS_LEN];
	_mav_put_float(buf, 0, dL2Leader);
	_mav_put_float(buf, 4, dY2Leader);
	_mav_put_float(buf, 8, dH2Leader);
	_mav_put_float(buf, 12, Psiv);
	_mav_put_float(buf, 16, FormationInitOk);
	_mav_put_uint8_t(buf, 20, Formation_PosID);
	_mav_put_uint8_t(buf, 21, Formation_mode);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEAM_STATUS, buf, MAVLINK_MSG_ID_TEAM_STATUS_MIN_LEN, MAVLINK_MSG_ID_TEAM_STATUS_LEN, MAVLINK_MSG_ID_TEAM_STATUS_CRC);
#else
	mavlink_team_status_t packet;
	packet.dL2Leader = dL2Leader;
	packet.dY2Leader = dY2Leader;
	packet.dH2Leader = dH2Leader;
	packet.Psiv = Psiv;
	packet.FormationInitOk = FormationInitOk;
	packet.Formation_PosID = Formation_PosID;
	packet.Formation_mode = Formation_mode;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEAM_STATUS, (const char *)&packet, MAVLINK_MSG_ID_TEAM_STATUS_MIN_LEN, MAVLINK_MSG_ID_TEAM_STATUS_LEN, MAVLINK_MSG_ID_TEAM_STATUS_CRC);
#endif
}

/**
 * @brief Send a team_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_team_status_send_struct(mavlink_channel_t chan, const mavlink_team_status_t* team_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_team_status_send(chan, team_status->Formation_PosID, team_status->Formation_mode, team_status->dL2Leader, team_status->dY2Leader, team_status->dH2Leader, team_status->Psiv, team_status->FormationInitOk);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEAM_STATUS, (const char *)team_status, MAVLINK_MSG_ID_TEAM_STATUS_MIN_LEN, MAVLINK_MSG_ID_TEAM_STATUS_LEN, MAVLINK_MSG_ID_TEAM_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_TEAM_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_team_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t Formation_PosID, uint8_t Formation_mode, float dL2Leader, float dY2Leader, float dH2Leader, float Psiv, float FormationInitOk)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, dL2Leader);
	_mav_put_float(buf, 4, dY2Leader);
	_mav_put_float(buf, 8, dH2Leader);
	_mav_put_float(buf, 12, Psiv);
	_mav_put_float(buf, 16, FormationInitOk);
	_mav_put_uint8_t(buf, 20, Formation_PosID);
	_mav_put_uint8_t(buf, 21, Formation_mode);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEAM_STATUS, buf, MAVLINK_MSG_ID_TEAM_STATUS_MIN_LEN, MAVLINK_MSG_ID_TEAM_STATUS_LEN, MAVLINK_MSG_ID_TEAM_STATUS_CRC);
#else
	mavlink_team_status_t *packet = (mavlink_team_status_t *)msgbuf;
	packet->dL2Leader = dL2Leader;
	packet->dY2Leader = dY2Leader;
	packet->dH2Leader = dH2Leader;
	packet->Psiv = Psiv;
	packet->FormationInitOk = FormationInitOk;
	packet->Formation_PosID = Formation_PosID;
	packet->Formation_mode = Formation_mode;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEAM_STATUS, (const char *)packet, MAVLINK_MSG_ID_TEAM_STATUS_MIN_LEN, MAVLINK_MSG_ID_TEAM_STATUS_LEN, MAVLINK_MSG_ID_TEAM_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE TEAM_STATUS UNPACKING


/**
 * @brief Get field Formation_PosID from team_status message
 *
 * @return Team ID
 */
static inline uint8_t mavlink_msg_team_status_get_Formation_PosID(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  20);
}

/**
 * @brief Get field Formation_mode from team_status message
 *
 * @return Team Mode
 */
static inline uint8_t mavlink_msg_team_status_get_Formation_mode(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  21);
}

/**
 * @brief Get field dL2Leader from team_status message
 *
 * @return Relative landscape location to leader 
 */
static inline float mavlink_msg_team_status_get_dL2Leader(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field dY2Leader from team_status message
 *
 * @return Relative lateral location to leader 
 */
static inline float mavlink_msg_team_status_get_dY2Leader(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field dH2Leader from team_status message
 *
 * @return Relative altitude location to leader
 */
static inline float mavlink_msg_team_status_get_dH2Leader(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field Psiv from team_status message
 *
 * @return Track angle
 */
static inline float mavlink_msg_team_status_get_Psiv(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field FormationInitOk from team_status message
 *
 * @return Formation Init Ok
 */
static inline float mavlink_msg_team_status_get_FormationInitOk(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Decode a team_status message into a struct
 *
 * @param msg The message to decode
 * @param team_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_team_status_decode(const mavlink_message_t* msg, mavlink_team_status_t* team_status)
{
#if MAVLINK_NEED_BYTE_SWAP 
	team_status->dL2Leader = mavlink_msg_team_status_get_dL2Leader(msg);
	team_status->dY2Leader = mavlink_msg_team_status_get_dY2Leader(msg);
	team_status->dH2Leader = mavlink_msg_team_status_get_dH2Leader(msg);
	team_status->Psiv = mavlink_msg_team_status_get_Psiv(msg);
	team_status->FormationInitOk = mavlink_msg_team_status_get_FormationInitOk(msg);
	team_status->Formation_PosID = mavlink_msg_team_status_get_Formation_PosID(msg);
	team_status->Formation_mode = mavlink_msg_team_status_get_Formation_mode(msg);
#else
    memcpy(team_status, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_TEAM_STATUS_LEN);
#endif
}
