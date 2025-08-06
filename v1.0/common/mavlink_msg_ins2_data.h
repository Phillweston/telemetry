// MESSAGE INS2_DATA PACKING

#define MAVLINK_MSG_ID_INS2_DATA 185

typedef struct __mavlink_ins2_data_t {
 int32_t lon; /*< Unit:掳 Resolution:180/(2^31-1)*/
 int32_t lat; /*< Unit:掳 Resolution:90/(2^31-1)*/
 int16_t roll; /*< Unit:掳 Resolution:180/(2^15-1)*/
 int16_t pitch; /*< Unit:掳 Resolution:180/(2^15-1)*/
 uint16_t yaw; /*< Unit:掳 Resolution:360/(2^16-1)*/
 int16_t roll_speed; /*< Unit:掳/s Resolution:300/(2^15-1)*/
 int16_t pitch_speed; /*< Unit:掳/s Resolution:300/(2^15-1)*/
 int16_t yaw_speed; /*< Unit:掳/s Resolution:300/(2^15-1)*/
 int16_t acc_lon; /*< Unit:m/s2 Resolution:400/(2^15-1)*/
 int16_t acc_lat; /*< Unit:m/s2 Resolution:400/(2^15-1)*/
 int16_t acc_alt; /*< Unit:m/s2 Resolution:400/(2^15-1)*/
 uint16_t alt; /*< Unit:m Resolution:y=(x+500)/10*/
 int16_t velocity_n; /*< Unit:m/s Resolution:1000/(2^15-1)*/
 int16_t velocity_e; /*< Unit:m/s Resolution:1000/(2^15-1)*/
 int16_t velocity_u; /*< Unit:m/s Resolution:1000/(2^15-1)*/
 uint16_t gs_2d; /*< Unit:m/s Resolution:1000/(2^16-1)*/
 uint16_t gs_3d; /*< Unit:m/s Resolution:1000/(2^16-1)*/
 int16_t fix_position_x; /*< Resolution:0.1*/
 int16_t fix_position_y; /*< Resolution:0.1*/
 int16_t fix_position_z; /*< Resolution:0.1*/
 uint8_t mode_estimator; /*< Resolution:1*/
 uint8_t mode_fix; /*< Resolution:1锛�0锛欼nvalid锛�1锛欸yro锛�2: AHRS锛�3:NAV_Vel锛�4:NAV_Pos锛�*/
 uint8_t satellites; /*< Resolution:1*/
} mavlink_ins2_data_t;

#define MAVLINK_MSG_ID_INS2_DATA_LEN 47
#define MAVLINK_MSG_ID_INS2_DATA_MIN_LEN 47
#define MAVLINK_MSG_ID_185_LEN 47
#define MAVLINK_MSG_ID_185_MIN_LEN 47

#define MAVLINK_MSG_ID_INS2_DATA_CRC 220
#define MAVLINK_MSG_ID_185_CRC 220



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_INS2_DATA { \
	185, \
	"INS2_DATA", \
	23, \
	{  { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_ins2_data_t, lon) }, \
         { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_ins2_data_t, lat) }, \
         { "roll", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_ins2_data_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_ins2_data_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_ins2_data_t, yaw) }, \
         { "roll_speed", NULL, MAVLINK_TYPE_INT16_T, 0, 14, offsetof(mavlink_ins2_data_t, roll_speed) }, \
         { "pitch_speed", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_ins2_data_t, pitch_speed) }, \
         { "yaw_speed", NULL, MAVLINK_TYPE_INT16_T, 0, 18, offsetof(mavlink_ins2_data_t, yaw_speed) }, \
         { "acc_lon", NULL, MAVLINK_TYPE_INT16_T, 0, 20, offsetof(mavlink_ins2_data_t, acc_lon) }, \
         { "acc_lat", NULL, MAVLINK_TYPE_INT16_T, 0, 22, offsetof(mavlink_ins2_data_t, acc_lat) }, \
         { "acc_alt", NULL, MAVLINK_TYPE_INT16_T, 0, 24, offsetof(mavlink_ins2_data_t, acc_alt) }, \
         { "alt", NULL, MAVLINK_TYPE_UINT16_T, 0, 26, offsetof(mavlink_ins2_data_t, alt) }, \
         { "velocity_n", NULL, MAVLINK_TYPE_INT16_T, 0, 28, offsetof(mavlink_ins2_data_t, velocity_n) }, \
         { "velocity_e", NULL, MAVLINK_TYPE_INT16_T, 0, 30, offsetof(mavlink_ins2_data_t, velocity_e) }, \
         { "velocity_u", NULL, MAVLINK_TYPE_INT16_T, 0, 32, offsetof(mavlink_ins2_data_t, velocity_u) }, \
         { "gs_2d", NULL, MAVLINK_TYPE_UINT16_T, 0, 34, offsetof(mavlink_ins2_data_t, gs_2d) }, \
         { "gs_3d", NULL, MAVLINK_TYPE_UINT16_T, 0, 36, offsetof(mavlink_ins2_data_t, gs_3d) }, \
         { "fix_position_x", NULL, MAVLINK_TYPE_INT16_T, 0, 38, offsetof(mavlink_ins2_data_t, fix_position_x) }, \
         { "fix_position_y", NULL, MAVLINK_TYPE_INT16_T, 0, 40, offsetof(mavlink_ins2_data_t, fix_position_y) }, \
         { "fix_position_z", NULL, MAVLINK_TYPE_INT16_T, 0, 42, offsetof(mavlink_ins2_data_t, fix_position_z) }, \
         { "mode_estimator", NULL, MAVLINK_TYPE_UINT8_T, 0, 44, offsetof(mavlink_ins2_data_t, mode_estimator) }, \
         { "mode_fix", NULL, MAVLINK_TYPE_UINT8_T, 0, 45, offsetof(mavlink_ins2_data_t, mode_fix) }, \
         { "satellites", NULL, MAVLINK_TYPE_UINT8_T, 0, 46, offsetof(mavlink_ins2_data_t, satellites) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_INS2_DATA { \
	"INS2_DATA", \
	23, \
	{  { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_ins2_data_t, lon) }, \
         { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_ins2_data_t, lat) }, \
         { "roll", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_ins2_data_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_ins2_data_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_ins2_data_t, yaw) }, \
         { "roll_speed", NULL, MAVLINK_TYPE_INT16_T, 0, 14, offsetof(mavlink_ins2_data_t, roll_speed) }, \
         { "pitch_speed", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_ins2_data_t, pitch_speed) }, \
         { "yaw_speed", NULL, MAVLINK_TYPE_INT16_T, 0, 18, offsetof(mavlink_ins2_data_t, yaw_speed) }, \
         { "acc_lon", NULL, MAVLINK_TYPE_INT16_T, 0, 20, offsetof(mavlink_ins2_data_t, acc_lon) }, \
         { "acc_lat", NULL, MAVLINK_TYPE_INT16_T, 0, 22, offsetof(mavlink_ins2_data_t, acc_lat) }, \
         { "acc_alt", NULL, MAVLINK_TYPE_INT16_T, 0, 24, offsetof(mavlink_ins2_data_t, acc_alt) }, \
         { "alt", NULL, MAVLINK_TYPE_UINT16_T, 0, 26, offsetof(mavlink_ins2_data_t, alt) }, \
         { "velocity_n", NULL, MAVLINK_TYPE_INT16_T, 0, 28, offsetof(mavlink_ins2_data_t, velocity_n) }, \
         { "velocity_e", NULL, MAVLINK_TYPE_INT16_T, 0, 30, offsetof(mavlink_ins2_data_t, velocity_e) }, \
         { "velocity_u", NULL, MAVLINK_TYPE_INT16_T, 0, 32, offsetof(mavlink_ins2_data_t, velocity_u) }, \
         { "gs_2d", NULL, MAVLINK_TYPE_UINT16_T, 0, 34, offsetof(mavlink_ins2_data_t, gs_2d) }, \
         { "gs_3d", NULL, MAVLINK_TYPE_UINT16_T, 0, 36, offsetof(mavlink_ins2_data_t, gs_3d) }, \
         { "fix_position_x", NULL, MAVLINK_TYPE_INT16_T, 0, 38, offsetof(mavlink_ins2_data_t, fix_position_x) }, \
         { "fix_position_y", NULL, MAVLINK_TYPE_INT16_T, 0, 40, offsetof(mavlink_ins2_data_t, fix_position_y) }, \
         { "fix_position_z", NULL, MAVLINK_TYPE_INT16_T, 0, 42, offsetof(mavlink_ins2_data_t, fix_position_z) }, \
         { "mode_estimator", NULL, MAVLINK_TYPE_UINT8_T, 0, 44, offsetof(mavlink_ins2_data_t, mode_estimator) }, \
         { "mode_fix", NULL, MAVLINK_TYPE_UINT8_T, 0, 45, offsetof(mavlink_ins2_data_t, mode_fix) }, \
         { "satellites", NULL, MAVLINK_TYPE_UINT8_T, 0, 46, offsetof(mavlink_ins2_data_t, satellites) }, \
         } \
}
#endif

/**
 * @brief Pack a ins2_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param roll Unit:掳 Resolution:180/(2^15-1)
 * @param pitch Unit:掳 Resolution:180/(2^15-1)
 * @param yaw Unit:掳 Resolution:360/(2^16-1)
 * @param roll_speed Unit:掳/s Resolution:300/(2^15-1)
 * @param pitch_speed Unit:掳/s Resolution:300/(2^15-1)
 * @param yaw_speed Unit:掳/s Resolution:300/(2^15-1)
 * @param acc_lon Unit:m/s2 Resolution:400/(2^15-1)
 * @param acc_lat Unit:m/s2 Resolution:400/(2^15-1)
 * @param acc_alt Unit:m/s2 Resolution:400/(2^15-1)
 * @param lon Unit:掳 Resolution:180/(2^31-1)
 * @param lat Unit:掳 Resolution:90/(2^31-1)
 * @param alt Unit:m Resolution:y=(x+500)/10
 * @param velocity_n Unit:m/s Resolution:1000/(2^15-1)
 * @param velocity_e Unit:m/s Resolution:1000/(2^15-1)
 * @param velocity_u Unit:m/s Resolution:1000/(2^15-1)
 * @param gs_2d Unit:m/s Resolution:1000/(2^16-1)
 * @param gs_3d Unit:m/s Resolution:1000/(2^16-1)
 * @param mode_estimator Resolution:1
 * @param mode_fix Resolution:1锛�0锛欼nvalid锛�1锛欸yro锛�2: AHRS锛�3:NAV_Vel锛�4:NAV_Pos锛�
 * @param satellites Resolution:1
 * @param fix_position_x Resolution:0.1
 * @param fix_position_y Resolution:0.1
 * @param fix_position_z Resolution:0.1
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ins2_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       int16_t roll, int16_t pitch, uint16_t yaw, int16_t roll_speed, int16_t pitch_speed, int16_t yaw_speed, int16_t acc_lon, int16_t acc_lat, int16_t acc_alt, int32_t lon, int32_t lat, uint16_t alt, int16_t velocity_n, int16_t velocity_e, int16_t velocity_u, uint16_t gs_2d, uint16_t gs_3d, uint8_t mode_estimator, uint8_t mode_fix, uint8_t satellites, int16_t fix_position_x, int16_t fix_position_y, int16_t fix_position_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_INS2_DATA_LEN];
	_mav_put_int32_t(buf, 0, lon);
	_mav_put_int32_t(buf, 4, lat);
	_mav_put_int16_t(buf, 8, roll);
	_mav_put_int16_t(buf, 10, pitch);
	_mav_put_uint16_t(buf, 12, yaw);
	_mav_put_int16_t(buf, 14, roll_speed);
	_mav_put_int16_t(buf, 16, pitch_speed);
	_mav_put_int16_t(buf, 18, yaw_speed);
	_mav_put_int16_t(buf, 20, acc_lon);
	_mav_put_int16_t(buf, 22, acc_lat);
	_mav_put_int16_t(buf, 24, acc_alt);
	_mav_put_uint16_t(buf, 26, alt);
	_mav_put_int16_t(buf, 28, velocity_n);
	_mav_put_int16_t(buf, 30, velocity_e);
	_mav_put_int16_t(buf, 32, velocity_u);
	_mav_put_uint16_t(buf, 34, gs_2d);
	_mav_put_uint16_t(buf, 36, gs_3d);
	_mav_put_int16_t(buf, 38, fix_position_x);
	_mav_put_int16_t(buf, 40, fix_position_y);
	_mav_put_int16_t(buf, 42, fix_position_z);
	_mav_put_uint8_t(buf, 44, mode_estimator);
	_mav_put_uint8_t(buf, 45, mode_fix);
	_mav_put_uint8_t(buf, 46, satellites);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_INS2_DATA_LEN);
#else
	mavlink_ins2_data_t packet;
	packet.lon = lon;
	packet.lat = lat;
	packet.roll = roll;
	packet.pitch = pitch;
	packet.yaw = yaw;
	packet.roll_speed = roll_speed;
	packet.pitch_speed = pitch_speed;
	packet.yaw_speed = yaw_speed;
	packet.acc_lon = acc_lon;
	packet.acc_lat = acc_lat;
	packet.acc_alt = acc_alt;
	packet.alt = alt;
	packet.velocity_n = velocity_n;
	packet.velocity_e = velocity_e;
	packet.velocity_u = velocity_u;
	packet.gs_2d = gs_2d;
	packet.gs_3d = gs_3d;
	packet.fix_position_x = fix_position_x;
	packet.fix_position_y = fix_position_y;
	packet.fix_position_z = fix_position_z;
	packet.mode_estimator = mode_estimator;
	packet.mode_fix = mode_fix;
	packet.satellites = satellites;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_INS2_DATA_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_INS2_DATA;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_INS2_DATA_LEN, MAVLINK_MSG_ID_INS2_DATA_CRC);
}

/**
 * @brief Pack a ins2_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param roll Unit:掳 Resolution:180/(2^15-1)
 * @param pitch Unit:掳 Resolution:180/(2^15-1)
 * @param yaw Unit:掳 Resolution:360/(2^16-1)
 * @param roll_speed Unit:掳/s Resolution:300/(2^15-1)
 * @param pitch_speed Unit:掳/s Resolution:300/(2^15-1)
 * @param yaw_speed Unit:掳/s Resolution:300/(2^15-1)
 * @param acc_lon Unit:m/s2 Resolution:400/(2^15-1)
 * @param acc_lat Unit:m/s2 Resolution:400/(2^15-1)
 * @param acc_alt Unit:m/s2 Resolution:400/(2^15-1)
 * @param lon Unit:掳 Resolution:180/(2^31-1)
 * @param lat Unit:掳 Resolution:90/(2^31-1)
 * @param alt Unit:m Resolution:y=(x+500)/10
 * @param velocity_n Unit:m/s Resolution:1000/(2^15-1)
 * @param velocity_e Unit:m/s Resolution:1000/(2^15-1)
 * @param velocity_u Unit:m/s Resolution:1000/(2^15-1)
 * @param gs_2d Unit:m/s Resolution:1000/(2^16-1)
 * @param gs_3d Unit:m/s Resolution:1000/(2^16-1)
 * @param mode_estimator Resolution:1
 * @param mode_fix Resolution:1锛�0锛欼nvalid锛�1锛欸yro锛�2: AHRS锛�3:NAV_Vel锛�4:NAV_Pos锛�
 * @param satellites Resolution:1
 * @param fix_position_x Resolution:0.1
 * @param fix_position_y Resolution:0.1
 * @param fix_position_z Resolution:0.1
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ins2_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           int16_t roll,int16_t pitch,uint16_t yaw,int16_t roll_speed,int16_t pitch_speed,int16_t yaw_speed,int16_t acc_lon,int16_t acc_lat,int16_t acc_alt,int32_t lon,int32_t lat,uint16_t alt,int16_t velocity_n,int16_t velocity_e,int16_t velocity_u,uint16_t gs_2d,uint16_t gs_3d,uint8_t mode_estimator,uint8_t mode_fix,uint8_t satellites,int16_t fix_position_x,int16_t fix_position_y,int16_t fix_position_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_INS2_DATA_LEN];
	_mav_put_int32_t(buf, 0, lon);
	_mav_put_int32_t(buf, 4, lat);
	_mav_put_int16_t(buf, 8, roll);
	_mav_put_int16_t(buf, 10, pitch);
	_mav_put_uint16_t(buf, 12, yaw);
	_mav_put_int16_t(buf, 14, roll_speed);
	_mav_put_int16_t(buf, 16, pitch_speed);
	_mav_put_int16_t(buf, 18, yaw_speed);
	_mav_put_int16_t(buf, 20, acc_lon);
	_mav_put_int16_t(buf, 22, acc_lat);
	_mav_put_int16_t(buf, 24, acc_alt);
	_mav_put_uint16_t(buf, 26, alt);
	_mav_put_int16_t(buf, 28, velocity_n);
	_mav_put_int16_t(buf, 30, velocity_e);
	_mav_put_int16_t(buf, 32, velocity_u);
	_mav_put_uint16_t(buf, 34, gs_2d);
	_mav_put_uint16_t(buf, 36, gs_3d);
	_mav_put_int16_t(buf, 38, fix_position_x);
	_mav_put_int16_t(buf, 40, fix_position_y);
	_mav_put_int16_t(buf, 42, fix_position_z);
	_mav_put_uint8_t(buf, 44, mode_estimator);
	_mav_put_uint8_t(buf, 45, mode_fix);
	_mav_put_uint8_t(buf, 46, satellites);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_INS2_DATA_LEN);
#else
	mavlink_ins2_data_t packet;
	packet.lon = lon;
	packet.lat = lat;
	packet.roll = roll;
	packet.pitch = pitch;
	packet.yaw = yaw;
	packet.roll_speed = roll_speed;
	packet.pitch_speed = pitch_speed;
	packet.yaw_speed = yaw_speed;
	packet.acc_lon = acc_lon;
	packet.acc_lat = acc_lat;
	packet.acc_alt = acc_alt;
	packet.alt = alt;
	packet.velocity_n = velocity_n;
	packet.velocity_e = velocity_e;
	packet.velocity_u = velocity_u;
	packet.gs_2d = gs_2d;
	packet.gs_3d = gs_3d;
	packet.fix_position_x = fix_position_x;
	packet.fix_position_y = fix_position_y;
	packet.fix_position_z = fix_position_z;
	packet.mode_estimator = mode_estimator;
	packet.mode_fix = mode_fix;
	packet.satellites = satellites;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_INS2_DATA_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_INS2_DATA;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_INS2_DATA_LEN, MAVLINK_MSG_ID_INS2_DATA_CRC);
}

/**
 * @brief Encode a ins2_data struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param ins2_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ins2_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_ins2_data_t* ins2_data)
{
	return mavlink_msg_ins2_data_pack(system_id, component_id, msg, ins2_data->roll, ins2_data->pitch, ins2_data->yaw, ins2_data->roll_speed, ins2_data->pitch_speed, ins2_data->yaw_speed, ins2_data->acc_lon, ins2_data->acc_lat, ins2_data->acc_alt, ins2_data->lon, ins2_data->lat, ins2_data->alt, ins2_data->velocity_n, ins2_data->velocity_e, ins2_data->velocity_u, ins2_data->gs_2d, ins2_data->gs_3d, ins2_data->mode_estimator, ins2_data->mode_fix, ins2_data->satellites, ins2_data->fix_position_x, ins2_data->fix_position_y, ins2_data->fix_position_z);
}

/**
 * @brief Encode a ins2_data struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ins2_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ins2_data_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_ins2_data_t* ins2_data)
{
	return mavlink_msg_ins2_data_pack_chan(system_id, component_id, chan, msg, ins2_data->roll, ins2_data->pitch, ins2_data->yaw, ins2_data->roll_speed, ins2_data->pitch_speed, ins2_data->yaw_speed, ins2_data->acc_lon, ins2_data->acc_lat, ins2_data->acc_alt, ins2_data->lon, ins2_data->lat, ins2_data->alt, ins2_data->velocity_n, ins2_data->velocity_e, ins2_data->velocity_u, ins2_data->gs_2d, ins2_data->gs_3d, ins2_data->mode_estimator, ins2_data->mode_fix, ins2_data->satellites, ins2_data->fix_position_x, ins2_data->fix_position_y, ins2_data->fix_position_z);
}

/**
 * @brief Send a ins2_data message
 * @param chan MAVLink channel to send the message
 *
 * @param roll Unit:掳 Resolution:180/(2^15-1)
 * @param pitch Unit:掳 Resolution:180/(2^15-1)
 * @param yaw Unit:掳 Resolution:360/(2^16-1)
 * @param roll_speed Unit:掳/s Resolution:300/(2^15-1)
 * @param pitch_speed Unit:掳/s Resolution:300/(2^15-1)
 * @param yaw_speed Unit:掳/s Resolution:300/(2^15-1)
 * @param acc_lon Unit:m/s2 Resolution:400/(2^15-1)
 * @param acc_lat Unit:m/s2 Resolution:400/(2^15-1)
 * @param acc_alt Unit:m/s2 Resolution:400/(2^15-1)
 * @param lon Unit:掳 Resolution:180/(2^31-1)
 * @param lat Unit:掳 Resolution:90/(2^31-1)
 * @param alt Unit:m Resolution:y=(x+500)/10
 * @param velocity_n Unit:m/s Resolution:1000/(2^15-1)
 * @param velocity_e Unit:m/s Resolution:1000/(2^15-1)
 * @param velocity_u Unit:m/s Resolution:1000/(2^15-1)
 * @param gs_2d Unit:m/s Resolution:1000/(2^16-1)
 * @param gs_3d Unit:m/s Resolution:1000/(2^16-1)
 * @param mode_estimator Resolution:1
 * @param mode_fix Resolution:1锛�0锛欼nvalid锛�1锛欸yro锛�2: AHRS锛�3:NAV_Vel锛�4:NAV_Pos锛�
 * @param satellites Resolution:1
 * @param fix_position_x Resolution:0.1
 * @param fix_position_y Resolution:0.1
 * @param fix_position_z Resolution:0.1
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_ins2_data_send(mavlink_channel_t chan, int16_t roll, int16_t pitch, uint16_t yaw, int16_t roll_speed, int16_t pitch_speed, int16_t yaw_speed, int16_t acc_lon, int16_t acc_lat, int16_t acc_alt, int32_t lon, int32_t lat, uint16_t alt, int16_t velocity_n, int16_t velocity_e, int16_t velocity_u, uint16_t gs_2d, uint16_t gs_3d, uint8_t mode_estimator, uint8_t mode_fix, uint8_t satellites, int16_t fix_position_x, int16_t fix_position_y, int16_t fix_position_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_INS2_DATA_LEN];
	_mav_put_int32_t(buf, 0, lon);
	_mav_put_int32_t(buf, 4, lat);
	_mav_put_int16_t(buf, 8, roll);
	_mav_put_int16_t(buf, 10, pitch);
	_mav_put_uint16_t(buf, 12, yaw);
	_mav_put_int16_t(buf, 14, roll_speed);
	_mav_put_int16_t(buf, 16, pitch_speed);
	_mav_put_int16_t(buf, 18, yaw_speed);
	_mav_put_int16_t(buf, 20, acc_lon);
	_mav_put_int16_t(buf, 22, acc_lat);
	_mav_put_int16_t(buf, 24, acc_alt);
	_mav_put_uint16_t(buf, 26, alt);
	_mav_put_int16_t(buf, 28, velocity_n);
	_mav_put_int16_t(buf, 30, velocity_e);
	_mav_put_int16_t(buf, 32, velocity_u);
	_mav_put_uint16_t(buf, 34, gs_2d);
	_mav_put_uint16_t(buf, 36, gs_3d);
	_mav_put_int16_t(buf, 38, fix_position_x);
	_mav_put_int16_t(buf, 40, fix_position_y);
	_mav_put_int16_t(buf, 42, fix_position_z);
	_mav_put_uint8_t(buf, 44, mode_estimator);
	_mav_put_uint8_t(buf, 45, mode_fix);
	_mav_put_uint8_t(buf, 46, satellites);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_INS2_DATA, buf, MAVLINK_MSG_ID_INS2_DATA_MIN_LEN, MAVLINK_MSG_ID_INS2_DATA_LEN, MAVLINK_MSG_ID_INS2_DATA_CRC);
#else
	mavlink_ins2_data_t packet;
	packet.lon = lon;
	packet.lat = lat;
	packet.roll = roll;
	packet.pitch = pitch;
	packet.yaw = yaw;
	packet.roll_speed = roll_speed;
	packet.pitch_speed = pitch_speed;
	packet.yaw_speed = yaw_speed;
	packet.acc_lon = acc_lon;
	packet.acc_lat = acc_lat;
	packet.acc_alt = acc_alt;
	packet.alt = alt;
	packet.velocity_n = velocity_n;
	packet.velocity_e = velocity_e;
	packet.velocity_u = velocity_u;
	packet.gs_2d = gs_2d;
	packet.gs_3d = gs_3d;
	packet.fix_position_x = fix_position_x;
	packet.fix_position_y = fix_position_y;
	packet.fix_position_z = fix_position_z;
	packet.mode_estimator = mode_estimator;
	packet.mode_fix = mode_fix;
	packet.satellites = satellites;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_INS2_DATA, (const char *)&packet, MAVLINK_MSG_ID_INS2_DATA_MIN_LEN, MAVLINK_MSG_ID_INS2_DATA_LEN, MAVLINK_MSG_ID_INS2_DATA_CRC);
#endif
}

/**
 * @brief Send a ins2_data message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_ins2_data_send_struct(mavlink_channel_t chan, const mavlink_ins2_data_t* ins2_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_ins2_data_send(chan, ins2_data->roll, ins2_data->pitch, ins2_data->yaw, ins2_data->roll_speed, ins2_data->pitch_speed, ins2_data->yaw_speed, ins2_data->acc_lon, ins2_data->acc_lat, ins2_data->acc_alt, ins2_data->lon, ins2_data->lat, ins2_data->alt, ins2_data->velocity_n, ins2_data->velocity_e, ins2_data->velocity_u, ins2_data->gs_2d, ins2_data->gs_3d, ins2_data->mode_estimator, ins2_data->mode_fix, ins2_data->satellites, ins2_data->fix_position_x, ins2_data->fix_position_y, ins2_data->fix_position_z);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_INS2_DATA, (const char *)ins2_data, MAVLINK_MSG_ID_INS2_DATA_MIN_LEN, MAVLINK_MSG_ID_INS2_DATA_LEN, MAVLINK_MSG_ID_INS2_DATA_CRC);
#endif
}

#if MAVLINK_MSG_ID_INS2_DATA_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_ins2_data_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int16_t roll, int16_t pitch, uint16_t yaw, int16_t roll_speed, int16_t pitch_speed, int16_t yaw_speed, int16_t acc_lon, int16_t acc_lat, int16_t acc_alt, int32_t lon, int32_t lat, uint16_t alt, int16_t velocity_n, int16_t velocity_e, int16_t velocity_u, uint16_t gs_2d, uint16_t gs_3d, uint8_t mode_estimator, uint8_t mode_fix, uint8_t satellites, int16_t fix_position_x, int16_t fix_position_y, int16_t fix_position_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_int32_t(buf, 0, lon);
	_mav_put_int32_t(buf, 4, lat);
	_mav_put_int16_t(buf, 8, roll);
	_mav_put_int16_t(buf, 10, pitch);
	_mav_put_uint16_t(buf, 12, yaw);
	_mav_put_int16_t(buf, 14, roll_speed);
	_mav_put_int16_t(buf, 16, pitch_speed);
	_mav_put_int16_t(buf, 18, yaw_speed);
	_mav_put_int16_t(buf, 20, acc_lon);
	_mav_put_int16_t(buf, 22, acc_lat);
	_mav_put_int16_t(buf, 24, acc_alt);
	_mav_put_uint16_t(buf, 26, alt);
	_mav_put_int16_t(buf, 28, velocity_n);
	_mav_put_int16_t(buf, 30, velocity_e);
	_mav_put_int16_t(buf, 32, velocity_u);
	_mav_put_uint16_t(buf, 34, gs_2d);
	_mav_put_uint16_t(buf, 36, gs_3d);
	_mav_put_int16_t(buf, 38, fix_position_x);
	_mav_put_int16_t(buf, 40, fix_position_y);
	_mav_put_int16_t(buf, 42, fix_position_z);
	_mav_put_uint8_t(buf, 44, mode_estimator);
	_mav_put_uint8_t(buf, 45, mode_fix);
	_mav_put_uint8_t(buf, 46, satellites);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_INS2_DATA, buf, MAVLINK_MSG_ID_INS2_DATA_MIN_LEN, MAVLINK_MSG_ID_INS2_DATA_LEN, MAVLINK_MSG_ID_INS2_DATA_CRC);
#else
	mavlink_ins2_data_t *packet = (mavlink_ins2_data_t *)msgbuf;
	packet->lon = lon;
	packet->lat = lat;
	packet->roll = roll;
	packet->pitch = pitch;
	packet->yaw = yaw;
	packet->roll_speed = roll_speed;
	packet->pitch_speed = pitch_speed;
	packet->yaw_speed = yaw_speed;
	packet->acc_lon = acc_lon;
	packet->acc_lat = acc_lat;
	packet->acc_alt = acc_alt;
	packet->alt = alt;
	packet->velocity_n = velocity_n;
	packet->velocity_e = velocity_e;
	packet->velocity_u = velocity_u;
	packet->gs_2d = gs_2d;
	packet->gs_3d = gs_3d;
	packet->fix_position_x = fix_position_x;
	packet->fix_position_y = fix_position_y;
	packet->fix_position_z = fix_position_z;
	packet->mode_estimator = mode_estimator;
	packet->mode_fix = mode_fix;
	packet->satellites = satellites;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_INS2_DATA, (const char *)packet, MAVLINK_MSG_ID_INS2_DATA_MIN_LEN, MAVLINK_MSG_ID_INS2_DATA_LEN, MAVLINK_MSG_ID_INS2_DATA_CRC);
#endif
}
#endif

#endif

// MESSAGE INS2_DATA UNPACKING


/**
 * @brief Get field roll from ins2_data message
 *
 * @return Unit:掳 Resolution:180/(2^15-1)
 */
static inline int16_t mavlink_msg_ins2_data_get_roll(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  8);
}

/**
 * @brief Get field pitch from ins2_data message
 *
 * @return Unit:掳 Resolution:180/(2^15-1)
 */
static inline int16_t mavlink_msg_ins2_data_get_pitch(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  10);
}

/**
 * @brief Get field yaw from ins2_data message
 *
 * @return Unit:掳 Resolution:360/(2^16-1)
 */
static inline uint16_t mavlink_msg_ins2_data_get_yaw(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  12);
}

/**
 * @brief Get field roll_speed from ins2_data message
 *
 * @return Unit:掳/s Resolution:300/(2^15-1)
 */
static inline int16_t mavlink_msg_ins2_data_get_roll_speed(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  14);
}

/**
 * @brief Get field pitch_speed from ins2_data message
 *
 * @return Unit:掳/s Resolution:300/(2^15-1)
 */
static inline int16_t mavlink_msg_ins2_data_get_pitch_speed(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  16);
}

/**
 * @brief Get field yaw_speed from ins2_data message
 *
 * @return Unit:掳/s Resolution:300/(2^15-1)
 */
static inline int16_t mavlink_msg_ins2_data_get_yaw_speed(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  18);
}

/**
 * @brief Get field acc_lon from ins2_data message
 *
 * @return Unit:m/s2 Resolution:400/(2^15-1)
 */
static inline int16_t mavlink_msg_ins2_data_get_acc_lon(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  20);
}

/**
 * @brief Get field acc_lat from ins2_data message
 *
 * @return Unit:m/s2 Resolution:400/(2^15-1)
 */
static inline int16_t mavlink_msg_ins2_data_get_acc_lat(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  22);
}

/**
 * @brief Get field acc_alt from ins2_data message
 *
 * @return Unit:m/s2 Resolution:400/(2^15-1)
 */
static inline int16_t mavlink_msg_ins2_data_get_acc_alt(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  24);
}

/**
 * @brief Get field lon from ins2_data message
 *
 * @return Unit:掳 Resolution:180/(2^31-1)
 */
static inline int32_t mavlink_msg_ins2_data_get_lon(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field lat from ins2_data message
 *
 * @return Unit:掳 Resolution:90/(2^31-1)
 */
static inline int32_t mavlink_msg_ins2_data_get_lat(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field alt from ins2_data message
 *
 * @return Unit:m Resolution:y=(x+500)/10
 */
static inline uint16_t mavlink_msg_ins2_data_get_alt(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  26);
}

/**
 * @brief Get field velocity_n from ins2_data message
 *
 * @return Unit:m/s Resolution:1000/(2^15-1)
 */
static inline int16_t mavlink_msg_ins2_data_get_velocity_n(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  28);
}

/**
 * @brief Get field velocity_e from ins2_data message
 *
 * @return Unit:m/s Resolution:1000/(2^15-1)
 */
static inline int16_t mavlink_msg_ins2_data_get_velocity_e(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  30);
}

/**
 * @brief Get field velocity_u from ins2_data message
 *
 * @return Unit:m/s Resolution:1000/(2^15-1)
 */
static inline int16_t mavlink_msg_ins2_data_get_velocity_u(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  32);
}

/**
 * @brief Get field gs_2d from ins2_data message
 *
 * @return Unit:m/s Resolution:1000/(2^16-1)
 */
static inline uint16_t mavlink_msg_ins2_data_get_gs_2d(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  34);
}

/**
 * @brief Get field gs_3d from ins2_data message
 *
 * @return Unit:m/s Resolution:1000/(2^16-1)
 */
static inline uint16_t mavlink_msg_ins2_data_get_gs_3d(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  36);
}

/**
 * @brief Get field mode_estimator from ins2_data message
 *
 * @return Resolution:1
 */
static inline uint8_t mavlink_msg_ins2_data_get_mode_estimator(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  44);
}

/**
 * @brief Get field mode_fix from ins2_data message
 *
 * @return Resolution:1锛�0锛欼nvalid锛�1锛欸yro锛�2: AHRS锛�3:NAV_Vel锛�4:NAV_Pos锛�
 */
static inline uint8_t mavlink_msg_ins2_data_get_mode_fix(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  45);
}

/**
 * @brief Get field satellites from ins2_data message
 *
 * @return Resolution:1
 */
static inline uint8_t mavlink_msg_ins2_data_get_satellites(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  46);
}

/**
 * @brief Get field fix_position_x from ins2_data message
 *
 * @return Resolution:0.1
 */
static inline int16_t mavlink_msg_ins2_data_get_fix_position_x(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  38);
}

/**
 * @brief Get field fix_position_y from ins2_data message
 *
 * @return Resolution:0.1
 */
static inline int16_t mavlink_msg_ins2_data_get_fix_position_y(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  40);
}

/**
 * @brief Get field fix_position_z from ins2_data message
 *
 * @return Resolution:0.1
 */
static inline int16_t mavlink_msg_ins2_data_get_fix_position_z(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  42);
}

/**
 * @brief Decode a ins2_data message into a struct
 *
 * @param msg The message to decode
 * @param ins2_data C-struct to decode the message contents into
 */
static inline void mavlink_msg_ins2_data_decode(const mavlink_message_t* msg, mavlink_ins2_data_t* ins2_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	ins2_data->lon = mavlink_msg_ins2_data_get_lon(msg);
	ins2_data->lat = mavlink_msg_ins2_data_get_lat(msg);
	ins2_data->roll = mavlink_msg_ins2_data_get_roll(msg);
	ins2_data->pitch = mavlink_msg_ins2_data_get_pitch(msg);
	ins2_data->yaw = mavlink_msg_ins2_data_get_yaw(msg);
	ins2_data->roll_speed = mavlink_msg_ins2_data_get_roll_speed(msg);
	ins2_data->pitch_speed = mavlink_msg_ins2_data_get_pitch_speed(msg);
	ins2_data->yaw_speed = mavlink_msg_ins2_data_get_yaw_speed(msg);
	ins2_data->acc_lon = mavlink_msg_ins2_data_get_acc_lon(msg);
	ins2_data->acc_lat = mavlink_msg_ins2_data_get_acc_lat(msg);
	ins2_data->acc_alt = mavlink_msg_ins2_data_get_acc_alt(msg);
	ins2_data->alt = mavlink_msg_ins2_data_get_alt(msg);
	ins2_data->velocity_n = mavlink_msg_ins2_data_get_velocity_n(msg);
	ins2_data->velocity_e = mavlink_msg_ins2_data_get_velocity_e(msg);
	ins2_data->velocity_u = mavlink_msg_ins2_data_get_velocity_u(msg);
	ins2_data->gs_2d = mavlink_msg_ins2_data_get_gs_2d(msg);
	ins2_data->gs_3d = mavlink_msg_ins2_data_get_gs_3d(msg);
	ins2_data->fix_position_x = mavlink_msg_ins2_data_get_fix_position_x(msg);
	ins2_data->fix_position_y = mavlink_msg_ins2_data_get_fix_position_y(msg);
	ins2_data->fix_position_z = mavlink_msg_ins2_data_get_fix_position_z(msg);
	ins2_data->mode_estimator = mavlink_msg_ins2_data_get_mode_estimator(msg);
	ins2_data->mode_fix = mavlink_msg_ins2_data_get_mode_fix(msg);
	ins2_data->satellites = mavlink_msg_ins2_data_get_satellites(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_INS2_DATA_LEN? msg->len : MAVLINK_MSG_ID_INS2_DATA_LEN;
        memset(ins2_data, 0, MAVLINK_MSG_ID_INS2_DATA_LEN);
	memcpy(ins2_data, _MAV_PAYLOAD(msg), len);
#endif
}
