// MESSAGE TEAM_SYNC PACKING

#define MAVLINK_MSG_ID_TEAM_SYNC 184

typedef struct __mavlink_team_sync_t {
 uint8_t phyId_src; /*< Team ID*/
 uint8_t phyId_dest; /*< Team ID*/
 uint8_t posId; /*< Marshalling point Latitude*/
 uint8_t formation_state; /*< Marshalling point Longitude*/
 uint8_t isLeaderOnline; /*< leader online flag*/
}mavlink_team_sync_t;

#define MAVLINK_MSG_ID_TEAM_SYNC_LEN 5
#define MAVLINK_MSG_ID_TEAM_SYNC_MIN_LEN 5
#define MAVLINK_MSG_ID_184_LEN 5
#define MAVLINK_MSG_ID_184_MIN_LEN 5

#define MAVLINK_MSG_ID_TEAM_SYNC_CRC 245
#define MAVLINK_MSG_ID_184_CRC 245



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TEAM_SYNC { \
	184, \
	"TEAM_SYNC", \
	5, \
	{  { "phyId_src", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_team_sync_t, phyId_src) }, \
         { "phyId_dest", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_team_sync_t, phyId_dest) }, \
         { "posId", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_team_sync_t, posId) }, \
         { "formation_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_team_sync_t, formation_state) }, \
         { "isLeaderOnline", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_team_sync_t, isLeaderOnline) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TEAM_SYNC { \
	"TEAM_SYNC", \
	5, \
	{  { "phyId_src", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_team_sync_t, phyId_src) }, \
         { "phyId_dest", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_team_sync_t, phyId_dest) }, \
         { "posId", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_team_sync_t, posId) }, \
         { "formation_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_team_sync_t, formation_state) }, \
         { "isLeaderOnline", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_team_sync_t, isLeaderOnline) }, \
         } \
}
#endif

/**
 * @brief Pack a team_sync message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param phyId_src Team ID
 * @param phyId_dest Team ID
 * @param posId Marshalling point Latitude
 * @param formation_state Marshalling point Longitude
 * @param isLeaderOnline leader online flag
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_team_sync_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t phyId_src, uint8_t phyId_dest, uint8_t posId, uint8_t formation_state, uint8_t isLeaderOnline)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TEAM_SYNC_LEN];
	_mav_put_uint8_t(buf, 0, phyId_src);
	_mav_put_uint8_t(buf, 1, phyId_dest);
	_mav_put_uint8_t(buf, 2, posId);
	_mav_put_uint8_t(buf, 3, formation_state);
	_mav_put_uint8_t(buf, 4, isLeaderOnline);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TEAM_SYNC_LEN);
#else
	mavlink_team_sync_t packet;
	packet.phyId_src = phyId_src;
	packet.phyId_dest = phyId_dest;
	packet.posId = posId;
	packet.formation_state = formation_state;
	packet.isLeaderOnline = isLeaderOnline;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TEAM_SYNC_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TEAM_SYNC;
#if MAVLINK_CRC_EXTRA
			return mavlink_finalize_message(msg, system_id, component_id,  MAVLINK_MSG_ID_TEAM_SYNC_LEN, MAVLINK_MSG_ID_TEAM_SYNC_CRC);
#else
			return mavlink_finalize_message(msg, system_id, component_id,  MAVLINK_MSG_ID_TEAM_SYNC_LEN);
#endif

}

/**
 * @brief Pack a team_sync message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param phyId_src Team ID
 * @param phyId_dest Team ID
 * @param posId Marshalling point Latitude
 * @param formation_state Marshalling point Longitude
 * @param isLeaderOnline leader online flag
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_team_sync_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t phyId_src,uint8_t phyId_dest,uint8_t posId,uint8_t formation_state,uint8_t isLeaderOnline)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TEAM_SYNC_LEN];
	_mav_put_uint8_t(buf, 0, phyId_src);
	_mav_put_uint8_t(buf, 1, phyId_dest);
	_mav_put_uint8_t(buf, 2, posId);
	_mav_put_uint8_t(buf, 3, formation_state);
	_mav_put_uint8_t(buf, 4, isLeaderOnline);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TEAM_SYNC_LEN);
#else
	mavlink_team_sync_t packet;
	packet.phyId_src = phyId_src;
	packet.phyId_dest = phyId_dest;
	packet.posId = posId;
	packet.formation_state = formation_state;
	packet.isLeaderOnline = isLeaderOnline;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TEAM_SYNC_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TEAM_SYNC;
#if MAVLINK_CRC_EXTRA
	return mavlink_finalize_message_chan(msg, system_id, component_id, chan,  MAVLINK_MSG_ID_TEAM_SYNC_LEN, MAVLINK_MSG_ID_TEAM_SYNC_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan,  MAVLINK_MSG_ID_TEAM_SYNC_LEN);
#endif

}

/**
 * @brief Encode a team_sync struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param team_sync C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_team_sync_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_team_sync_t* team_sync)
{
	return mavlink_msg_team_sync_pack(system_id, component_id, msg, team_sync->phyId_src, team_sync->phyId_dest, team_sync->posId, team_sync->formation_state, team_sync->isLeaderOnline);
}

/**
 * @brief Encode a team_sync struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param team_sync C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_team_sync_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_team_sync_t* team_sync)
{
	return mavlink_msg_team_sync_pack_chan(system_id, component_id, chan, msg, team_sync->phyId_src, team_sync->phyId_dest, team_sync->posId, team_sync->formation_state, team_sync->isLeaderOnline);
}

/**
 * @brief Send a team_sync message
 * @param chan MAVLink channel to send the message
 *
 * @param phyId_src Team ID
 * @param phyId_dest Team ID
 * @param posId Marshalling point Latitude
 * @param formation_state Marshalling point Longitude
 * @param isLeaderOnline leader online flag
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_team_sync_send(mavlink_channel_t chan, uint8_t phyId_src, uint8_t phyId_dest, uint8_t posId, uint8_t formation_state, uint8_t isLeaderOnline)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TEAM_SYNC_LEN];
	_mav_put_uint8_t(buf, 0, phyId_src);
	_mav_put_uint8_t(buf, 1, phyId_dest);
	_mav_put_uint8_t(buf, 2, posId);
	_mav_put_uint8_t(buf, 3, formation_state);
	_mav_put_uint8_t(buf, 4, isLeaderOnline);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEAM_SYNC, buf, MAVLINK_MSG_ID_TEAM_SYNC_MIN_LEN, MAVLINK_MSG_ID_TEAM_SYNC_LEN, MAVLINK_MSG_ID_TEAM_SYNC_CRC);
#else
	mavlink_team_sync_t packet;
	packet.phyId_src = phyId_src;
	packet.phyId_dest = phyId_dest;
	packet.posId = posId;
	packet.formation_state = formation_state;
	packet.isLeaderOnline = isLeaderOnline;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEAM_SYNC, (const char *)&packet, MAVLINK_MSG_ID_TEAM_SYNC_MIN_LEN, MAVLINK_MSG_ID_TEAM_SYNC_LEN, MAVLINK_MSG_ID_TEAM_SYNC_CRC);
#endif
}

/**
 * @brief Send a team_sync message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_team_sync_send_struct(mavlink_channel_t chan, const mavlink_team_sync_t* team_sync)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_team_sync_send(chan, team_sync->phyId_src, team_sync->phyId_dest, team_sync->posId, team_sync->formation_state, team_sync->isLeaderOnline);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEAM_SYNC, (const char *)team_sync, MAVLINK_MSG_ID_TEAM_SYNC_MIN_LEN, MAVLINK_MSG_ID_TEAM_SYNC_LEN, MAVLINK_MSG_ID_TEAM_SYNC_CRC);
#endif
}

#if MAVLINK_MSG_ID_TEAM_SYNC_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_team_sync_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t phyId_src, uint8_t phyId_dest, uint8_t posId, uint8_t formation_state, uint8_t isLeaderOnline)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint8_t(buf, 0, phyId_src);
	_mav_put_uint8_t(buf, 1, phyId_dest);
	_mav_put_uint8_t(buf, 2, posId);
	_mav_put_uint8_t(buf, 3, formation_state);
	_mav_put_uint8_t(buf, 4, isLeaderOnline);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEAM_SYNC, buf, MAVLINK_MSG_ID_TEAM_SYNC_MIN_LEN, MAVLINK_MSG_ID_TEAM_SYNC_LEN, MAVLINK_MSG_ID_TEAM_SYNC_CRC);
#else
	mavlink_team_sync_t *packet = (mavlink_team_sync_t *)msgbuf;
	packet->phyId_src = phyId_src;
	packet->phyId_dest = phyId_dest;
	packet->posId = posId;
	packet->formation_state = formation_state;
	packet->isLeaderOnline = isLeaderOnline;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEAM_SYNC, (const char *)packet, MAVLINK_MSG_ID_TEAM_SYNC_MIN_LEN, MAVLINK_MSG_ID_TEAM_SYNC_LEN, MAVLINK_MSG_ID_TEAM_SYNC_CRC);
#endif
}
#endif

#endif

// MESSAGE TEAM_SYNC UNPACKING


/**
 * @brief Get field phyId_src from team_sync message
 *
 * @return Team ID
 */
static inline uint8_t mavlink_msg_team_sync_get_phyId_src(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field phyId_dest from team_sync message
 *
 * @return Team ID
 */
static inline uint8_t mavlink_msg_team_sync_get_phyId_dest(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field posId from team_sync message
 *
 * @return Marshalling point Latitude
 */
static inline uint8_t mavlink_msg_team_sync_get_posId(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field formation_state from team_sync message
 *
 * @return Marshalling point Longitude
 */
static inline uint8_t mavlink_msg_team_sync_get_formation_state(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field isLeaderOnline from team_sync message
 *
 * @return leader online flag
 */
static inline uint8_t mavlink_msg_team_sync_get_isLeaderOnline(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Decode a team_sync message into a struct
 *
 * @param msg The message to decode
 * @param team_sync C-struct to decode the message contents into
 */
static inline void mavlink_msg_team_sync_decode(const mavlink_message_t* msg, mavlink_team_sync_t* team_sync)
{
#if MAVLINK_NEED_BYTE_SWAP
	team_sync->phyId_src = mavlink_msg_team_sync_get_phyId_src(msg);
	team_sync->phyId_dest = mavlink_msg_team_sync_get_phyId_dest(msg);
	team_sync->posId = mavlink_msg_team_sync_get_posId(msg);
	team_sync->formation_state = mavlink_msg_team_sync_get_formation_state(msg);
	team_sync->isLeaderOnline = mavlink_msg_team_sync_get_isLeaderOnline(msg);
#else
	memcpy(team_sync, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_TEAM_SYNC_LEN);
#endif
}
