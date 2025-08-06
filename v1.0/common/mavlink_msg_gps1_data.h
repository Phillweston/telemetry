// MESSAGE GPS1_DATA PACKING

#define MAVLINK_MSG_ID_GPS1_DATA 186

MAVPACKED(
typedef struct __mavlink_gps1_data_t {
 int32_t lon; /*< Unit:掳 Resolution:180/(2^31-1)*/
 int32_t lat; /*< Unit:掳 Resolution:90/(2^31-1)*/
 uint16_t alt; /*< Unit:m Resolution:y=(x+500)/10*/
 int16_t velocity_n; /*< Unit:m/s Resolution:1000/(2^15-1)*/
 int16_t velocity_e; /*< Unit:m/s Resolution:1000/(2^15-1)*/
 int16_t velocity_u; /*< Unit:m/s Resolution:1000/(2^15-1)*/
 uint16_t gs_2d; /*< Unit:m/s Resolution:1000/(2^16-1)*/
 int16_t eph; /*< Resolution:0.1*/
 int16_t epv; /*< Resolution:0.1*/
 uint16_t yaw; /*< Unit:掳 Resolution:360/(2^16-1)*/
 uint8_t mode_fix; /*< Resolution:1锛�*/
 uint8_t satellites; /*< Resolution:1*/
}) mavlink_gps1_data_t;

#define MAVLINK_MSG_ID_GPS1_DATA_LEN 26
#define MAVLINK_MSG_ID_GPS1_DATA_MIN_LEN 26
#define MAVLINK_MSG_ID_186_LEN 26
#define MAVLINK_MSG_ID_186_MIN_LEN 26

#define MAVLINK_MSG_ID_GPS1_DATA_CRC 235
#define MAVLINK_MSG_ID_186_CRC 235



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_GPS1_DATA { \
	186, \
	"GPS1_DATA", \
	12, \
	{  { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_gps1_data_t, lon) }, \
         { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_gps1_data_t, lat) }, \
         { "alt", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_gps1_data_t, alt) }, \
         { "velocity_n", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_gps1_data_t, velocity_n) }, \
         { "velocity_e", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_gps1_data_t, velocity_e) }, \
         { "velocity_u", NULL, MAVLINK_TYPE_INT16_T, 0, 14, offsetof(mavlink_gps1_data_t, velocity_u) }, \
         { "gs_2d", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_gps1_data_t, gs_2d) }, \
         { "eph", NULL, MAVLINK_TYPE_INT16_T, 0, 18, offsetof(mavlink_gps1_data_t, eph) }, \
         { "epv", NULL, MAVLINK_TYPE_INT16_T, 0, 20, offsetof(mavlink_gps1_data_t, epv) }, \
         { "yaw", NULL, MAVLINK_TYPE_UINT16_T, 0, 22, offsetof(mavlink_gps1_data_t, yaw) }, \
         { "mode_fix", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_gps1_data_t, mode_fix) }, \
         { "satellites", NULL, MAVLINK_TYPE_UINT8_T, 0, 25, offsetof(mavlink_gps1_data_t, satellites) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_GPS1_DATA { \
	"GPS1_DATA", \
	12, \
	{  { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_gps1_data_t, lon) }, \
         { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_gps1_data_t, lat) }, \
         { "alt", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_gps1_data_t, alt) }, \
         { "velocity_n", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_gps1_data_t, velocity_n) }, \
         { "velocity_e", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_gps1_data_t, velocity_e) }, \
         { "velocity_u", NULL, MAVLINK_TYPE_INT16_T, 0, 14, offsetof(mavlink_gps1_data_t, velocity_u) }, \
         { "gs_2d", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_gps1_data_t, gs_2d) }, \
         { "eph", NULL, MAVLINK_TYPE_INT16_T, 0, 18, offsetof(mavlink_gps1_data_t, eph) }, \
         { "epv", NULL, MAVLINK_TYPE_INT16_T, 0, 20, offsetof(mavlink_gps1_data_t, epv) }, \
         { "yaw", NULL, MAVLINK_TYPE_UINT16_T, 0, 22, offsetof(mavlink_gps1_data_t, yaw) }, \
         { "mode_fix", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_gps1_data_t, mode_fix) }, \
         { "satellites", NULL, MAVLINK_TYPE_UINT8_T, 0, 25, offsetof(mavlink_gps1_data_t, satellites) }, \
         } \
}
#endif

/**
 * @brief Pack a gps1_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param lon Unit:掳 Resolution:180/(2^31-1)
 * @param lat Unit:掳 Resolution:90/(2^31-1)
 * @param alt Unit:m Resolution:y=(x+500)/10
 * @param velocity_n Unit:m/s Resolution:1000/(2^15-1)
 * @param velocity_e Unit:m/s Resolution:1000/(2^15-1)
 * @param velocity_u Unit:m/s Resolution:1000/(2^15-1)
 * @param gs_2d Unit:m/s Resolution:1000/(2^16-1)
 * @param mode_fix Resolution:1锛�
 * @param satellites Resolution:1
 * @param eph Resolution:0.1
 * @param epv Resolution:0.1
 * @param yaw Unit:掳 Resolution:360/(2^16-1)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gps1_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       int32_t lon, int32_t lat, uint16_t alt, int16_t velocity_n, int16_t velocity_e, int16_t velocity_u, uint16_t gs_2d, uint8_t mode_fix, uint8_t satellites, int16_t eph, int16_t epv, uint16_t yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_GPS1_DATA_LEN];
	_mav_put_int32_t(buf, 0, lon);
	_mav_put_int32_t(buf, 4, lat);
	_mav_put_uint16_t(buf, 8, alt);
	_mav_put_int16_t(buf, 10, velocity_n);
	_mav_put_int16_t(buf, 12, velocity_e);
	_mav_put_int16_t(buf, 14, velocity_u);
	_mav_put_uint16_t(buf, 16, gs_2d);
	_mav_put_int16_t(buf, 18, eph);
	_mav_put_int16_t(buf, 20, epv);
	_mav_put_uint16_t(buf, 22, yaw);
	_mav_put_uint8_t(buf, 24, mode_fix);
	_mav_put_uint8_t(buf, 25, satellites);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GPS1_DATA_LEN);
#else
	mavlink_gps1_data_t packet;
	packet.lon = lon;
	packet.lat = lat;
	packet.alt = alt;
	packet.velocity_n = velocity_n;
	packet.velocity_e = velocity_e;
	packet.velocity_u = velocity_u;
	packet.gs_2d = gs_2d;
	packet.eph = eph;
	packet.epv = epv;
	packet.yaw = yaw;
	packet.mode_fix = mode_fix;
	packet.satellites = satellites;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GPS1_DATA_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_GPS1_DATA;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_GPS1_DATA_LEN, MAVLINK_MSG_ID_GPS1_DATA_CRC);
}

/**
 * @brief Pack a gps1_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param lon Unit:掳 Resolution:180/(2^31-1)
 * @param lat Unit:掳 Resolution:90/(2^31-1)
 * @param alt Unit:m Resolution:y=(x+500)/10
 * @param velocity_n Unit:m/s Resolution:1000/(2^15-1)
 * @param velocity_e Unit:m/s Resolution:1000/(2^15-1)
 * @param velocity_u Unit:m/s Resolution:1000/(2^15-1)
 * @param gs_2d Unit:m/s Resolution:1000/(2^16-1)
 * @param mode_fix Resolution:1锛�
 * @param satellites Resolution:1
 * @param eph Resolution:0.1
 * @param epv Resolution:0.1
 * @param yaw Unit:掳 Resolution:360/(2^16-1)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gps1_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           int32_t lon,int32_t lat,uint16_t alt,int16_t velocity_n,int16_t velocity_e,int16_t velocity_u,uint16_t gs_2d,uint8_t mode_fix,uint8_t satellites,int16_t eph,int16_t epv,uint16_t yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_GPS1_DATA_LEN];
	_mav_put_int32_t(buf, 0, lon);
	_mav_put_int32_t(buf, 4, lat);
	_mav_put_uint16_t(buf, 8, alt);
	_mav_put_int16_t(buf, 10, velocity_n);
	_mav_put_int16_t(buf, 12, velocity_e);
	_mav_put_int16_t(buf, 14, velocity_u);
	_mav_put_uint16_t(buf, 16, gs_2d);
	_mav_put_int16_t(buf, 18, eph);
	_mav_put_int16_t(buf, 20, epv);
	_mav_put_uint16_t(buf, 22, yaw);
	_mav_put_uint8_t(buf, 24, mode_fix);
	_mav_put_uint8_t(buf, 25, satellites);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GPS1_DATA_LEN);
#else
	mavlink_gps1_data_t packet;
	packet.lon = lon;
	packet.lat = lat;
	packet.alt = alt;
	packet.velocity_n = velocity_n;
	packet.velocity_e = velocity_e;
	packet.velocity_u = velocity_u;
	packet.gs_2d = gs_2d;
	packet.eph = eph;
	packet.epv = epv;
	packet.yaw = yaw;
	packet.mode_fix = mode_fix;
	packet.satellites = satellites;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GPS1_DATA_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_GPS1_DATA;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_GPS1_DATA_LEN, MAVLINK_MSG_ID_GPS1_DATA_CRC);
}

/**
 * @brief Encode a gps1_data struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param gps1_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gps1_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_gps1_data_t* gps1_data)
{
	return mavlink_msg_gps1_data_pack(system_id, component_id, msg, gps1_data->lon, gps1_data->lat, gps1_data->alt, gps1_data->velocity_n, gps1_data->velocity_e, gps1_data->velocity_u, gps1_data->gs_2d, gps1_data->mode_fix, gps1_data->satellites, gps1_data->eph, gps1_data->epv, gps1_data->yaw);
}

/**
 * @brief Encode a gps1_data struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param gps1_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gps1_data_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_gps1_data_t* gps1_data)
{
	return mavlink_msg_gps1_data_pack_chan(system_id, component_id, chan, msg, gps1_data->lon, gps1_data->lat, gps1_data->alt, gps1_data->velocity_n, gps1_data->velocity_e, gps1_data->velocity_u, gps1_data->gs_2d, gps1_data->mode_fix, gps1_data->satellites, gps1_data->eph, gps1_data->epv, gps1_data->yaw);
}

/**
 * @brief Send a gps1_data message
 * @param chan MAVLink channel to send the message
 *
 * @param lon Unit:掳 Resolution:180/(2^31-1)
 * @param lat Unit:掳 Resolution:90/(2^31-1)
 * @param alt Unit:m Resolution:y=(x+500)/10
 * @param velocity_n Unit:m/s Resolution:1000/(2^15-1)
 * @param velocity_e Unit:m/s Resolution:1000/(2^15-1)
 * @param velocity_u Unit:m/s Resolution:1000/(2^15-1)
 * @param gs_2d Unit:m/s Resolution:1000/(2^16-1)
 * @param mode_fix Resolution:1锛�
 * @param satellites Resolution:1
 * @param eph Resolution:0.1
 * @param epv Resolution:0.1
 * @param yaw Unit:掳 Resolution:360/(2^16-1)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_gps1_data_send(mavlink_channel_t chan, int32_t lon, int32_t lat, uint16_t alt, int16_t velocity_n, int16_t velocity_e, int16_t velocity_u, uint16_t gs_2d, uint8_t mode_fix, uint8_t satellites, int16_t eph, int16_t epv, uint16_t yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_GPS1_DATA_LEN];
	_mav_put_int32_t(buf, 0, lon);
	_mav_put_int32_t(buf, 4, lat);
	_mav_put_uint16_t(buf, 8, alt);
	_mav_put_int16_t(buf, 10, velocity_n);
	_mav_put_int16_t(buf, 12, velocity_e);
	_mav_put_int16_t(buf, 14, velocity_u);
	_mav_put_uint16_t(buf, 16, gs_2d);
	_mav_put_int16_t(buf, 18, eph);
	_mav_put_int16_t(buf, 20, epv);
	_mav_put_uint16_t(buf, 22, yaw);
	_mav_put_uint8_t(buf, 24, mode_fix);
	_mav_put_uint8_t(buf, 25, satellites);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS1_DATA, buf, MAVLINK_MSG_ID_GPS1_DATA_MIN_LEN, MAVLINK_MSG_ID_GPS1_DATA_LEN, MAVLINK_MSG_ID_GPS1_DATA_CRC);
#else
	mavlink_gps1_data_t packet;
	packet.lon = lon;
	packet.lat = lat;
	packet.alt = alt;
	packet.velocity_n = velocity_n;
	packet.velocity_e = velocity_e;
	packet.velocity_u = velocity_u;
	packet.gs_2d = gs_2d;
	packet.eph = eph;
	packet.epv = epv;
	packet.yaw = yaw;
	packet.mode_fix = mode_fix;
	packet.satellites = satellites;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS1_DATA, (const char *)&packet, MAVLINK_MSG_ID_GPS1_DATA_MIN_LEN, MAVLINK_MSG_ID_GPS1_DATA_LEN, MAVLINK_MSG_ID_GPS1_DATA_CRC);
#endif
}

/**
 * @brief Send a gps1_data message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_gps1_data_send_struct(mavlink_channel_t chan, const mavlink_gps1_data_t* gps1_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_gps1_data_send(chan, gps1_data->lon, gps1_data->lat, gps1_data->alt, gps1_data->velocity_n, gps1_data->velocity_e, gps1_data->velocity_u, gps1_data->gs_2d, gps1_data->mode_fix, gps1_data->satellites, gps1_data->eph, gps1_data->epv, gps1_data->yaw);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS1_DATA, (const char *)gps1_data, MAVLINK_MSG_ID_GPS1_DATA_MIN_LEN, MAVLINK_MSG_ID_GPS1_DATA_LEN, MAVLINK_MSG_ID_GPS1_DATA_CRC);
#endif
}

#if MAVLINK_MSG_ID_GPS1_DATA_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_gps1_data_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int32_t lon, int32_t lat, uint16_t alt, int16_t velocity_n, int16_t velocity_e, int16_t velocity_u, uint16_t gs_2d, uint8_t mode_fix, uint8_t satellites, int16_t eph, int16_t epv, uint16_t yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_int32_t(buf, 0, lon);
	_mav_put_int32_t(buf, 4, lat);
	_mav_put_uint16_t(buf, 8, alt);
	_mav_put_int16_t(buf, 10, velocity_n);
	_mav_put_int16_t(buf, 12, velocity_e);
	_mav_put_int16_t(buf, 14, velocity_u);
	_mav_put_uint16_t(buf, 16, gs_2d);
	_mav_put_int16_t(buf, 18, eph);
	_mav_put_int16_t(buf, 20, epv);
	_mav_put_uint16_t(buf, 22, yaw);
	_mav_put_uint8_t(buf, 24, mode_fix);
	_mav_put_uint8_t(buf, 25, satellites);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS1_DATA, buf, MAVLINK_MSG_ID_GPS1_DATA_MIN_LEN, MAVLINK_MSG_ID_GPS1_DATA_LEN, MAVLINK_MSG_ID_GPS1_DATA_CRC);
#else
	mavlink_gps1_data_t *packet = (mavlink_gps1_data_t *)msgbuf;
	packet->lon = lon;
	packet->lat = lat;
	packet->alt = alt;
	packet->velocity_n = velocity_n;
	packet->velocity_e = velocity_e;
	packet->velocity_u = velocity_u;
	packet->gs_2d = gs_2d;
	packet->eph = eph;
	packet->epv = epv;
	packet->yaw = yaw;
	packet->mode_fix = mode_fix;
	packet->satellites = satellites;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS1_DATA, (const char *)packet, MAVLINK_MSG_ID_GPS1_DATA_MIN_LEN, MAVLINK_MSG_ID_GPS1_DATA_LEN, MAVLINK_MSG_ID_GPS1_DATA_CRC);
#endif
}
#endif

#endif

// MESSAGE GPS1_DATA UNPACKING


/**
 * @brief Get field lon from gps1_data message
 *
 * @return Unit:掳 Resolution:180/(2^31-1)
 */
static inline int32_t mavlink_msg_gps1_data_get_lon(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field lat from gps1_data message
 *
 * @return Unit:掳 Resolution:90/(2^31-1)
 */
static inline int32_t mavlink_msg_gps1_data_get_lat(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field alt from gps1_data message
 *
 * @return Unit:m Resolution:y=(x+500)/10
 */
static inline uint16_t mavlink_msg_gps1_data_get_alt(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  8);
}

/**
 * @brief Get field velocity_n from gps1_data message
 *
 * @return Unit:m/s Resolution:1000/(2^15-1)
 */
static inline int16_t mavlink_msg_gps1_data_get_velocity_n(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  10);
}

/**
 * @brief Get field velocity_e from gps1_data message
 *
 * @return Unit:m/s Resolution:1000/(2^15-1)
 */
static inline int16_t mavlink_msg_gps1_data_get_velocity_e(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  12);
}

/**
 * @brief Get field velocity_u from gps1_data message
 *
 * @return Unit:m/s Resolution:1000/(2^15-1)
 */
static inline int16_t mavlink_msg_gps1_data_get_velocity_u(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  14);
}

/**
 * @brief Get field gs_2d from gps1_data message
 *
 * @return Unit:m/s Resolution:1000/(2^16-1)
 */
static inline uint16_t mavlink_msg_gps1_data_get_gs_2d(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  16);
}

/**
 * @brief Get field mode_fix from gps1_data message
 *
 * @return Resolution:1锛�
 */
static inline uint8_t mavlink_msg_gps1_data_get_mode_fix(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  24);
}

/**
 * @brief Get field satellites from gps1_data message
 *
 * @return Resolution:1
 */
static inline uint8_t mavlink_msg_gps1_data_get_satellites(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  25);
}

/**
 * @brief Get field eph from gps1_data message
 *
 * @return Resolution:0.1
 */
static inline int16_t mavlink_msg_gps1_data_get_eph(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  18);
}

/**
 * @brief Get field epv from gps1_data message
 *
 * @return Resolution:0.1
 */
static inline int16_t mavlink_msg_gps1_data_get_epv(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  20);
}

/**
 * @brief Get field yaw from gps1_data message
 *
 * @return Unit:掳 Resolution:360/(2^16-1)
 */
static inline uint16_t mavlink_msg_gps1_data_get_yaw(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  22);
}

/**
 * @brief Decode a gps1_data message into a struct
 *
 * @param msg The message to decode
 * @param gps1_data C-struct to decode the message contents into
 */
static inline void mavlink_msg_gps1_data_decode(const mavlink_message_t* msg, mavlink_gps1_data_t* gps1_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	gps1_data->lon = mavlink_msg_gps1_data_get_lon(msg);
	gps1_data->lat = mavlink_msg_gps1_data_get_lat(msg);
	gps1_data->alt = mavlink_msg_gps1_data_get_alt(msg);
	gps1_data->velocity_n = mavlink_msg_gps1_data_get_velocity_n(msg);
	gps1_data->velocity_e = mavlink_msg_gps1_data_get_velocity_e(msg);
	gps1_data->velocity_u = mavlink_msg_gps1_data_get_velocity_u(msg);
	gps1_data->gs_2d = mavlink_msg_gps1_data_get_gs_2d(msg);
	gps1_data->eph = mavlink_msg_gps1_data_get_eph(msg);
	gps1_data->epv = mavlink_msg_gps1_data_get_epv(msg);
	gps1_data->yaw = mavlink_msg_gps1_data_get_yaw(msg);
	gps1_data->mode_fix = mavlink_msg_gps1_data_get_mode_fix(msg);
	gps1_data->satellites = mavlink_msg_gps1_data_get_satellites(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_GPS1_DATA_LEN? msg->len : MAVLINK_MSG_ID_GPS1_DATA_LEN;
        memset(gps1_data, 0, MAVLINK_MSG_ID_GPS1_DATA_LEN);
	memcpy(gps1_data, _MAV_PAYLOAD(msg), len);
#endif
}
