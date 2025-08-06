#pragma once
// MESSAGE TELE_DATA PACKING

#define MAVLINK_MSG_ID_TELE_DATA 156


typedef struct __mavlink_tele_data_t {
 int32_t homePos_lat; /*<  home position,lat*/
 int32_t homePos_lon; /*<  home position,lon*/
 int32_t lon; /*<  fly status: lon*/
 int32_t lat; /*<  fly status: lat*/
 int32_t SCNS_lon; /*<  sbg: gps position lon*/
 int32_t SCNS_lat; /*<  sbg: gps position lat*/
 int32_t intSensor_lon_gps; /*<  inter sensor: gps position lon*/
 int32_t intSensor_lat_gps; /*<  inter sensor: gps position lat*/
 uint16_t flight_time_sec; /*<  flight time,unit sec*/
 uint16_t distance2Home; /*<  distance to home position,unit m*/
 uint16_t homePos_alt; /*<  home position,alt*/
 int16_t pitch; /*<  fly status: pitch*/
 int16_t roll; /*<  fly status: roll*/
 uint16_t Vi; /*<  fly status: Vi*/
 uint16_t Vg; /*<  fly status: Vg*/
 int16_t Vx; /*<  fly status: Vx*/
 int16_t Vy; /*<  fly status: Vy*/
 int16_t hdot; /*<  fly status: hdot*/
 uint16_t yaw; /*<  fly status: yaw*/
 int16_t psiV; /*<  fly status: psiV*/
 uint16_t alt; /*<  fly status: alt*/
 uint16_t alt_relative; /*<  fly status: alt_relative*/
 uint16_t cmd_alt; /*<  fly command: alt*/
 uint16_t cmd_Vi; /*<  fly command: Vi*/
 int16_t cmd_Vx; /*<  fly command: Vx*/
 int16_t cmd_Vy; /*<  fly command: Vy*/
 int16_t cmd_theta; /*<  fly command: tehta*/
 int16_t cmd_phi; /*<  fly command: phi*/
 int16_t cmd_psi; /*<  fly command: psi*/
 int16_t cmd_hdot; /*<  fly command: hdot*/
 int16_t lawOuput_ele; /*<  law output: ele*/
 int16_t lawOuput_ail; /*<  law output: ail*/
 int16_t lawOuput_rud; /*<  law output: rud*/
 int16_t SCNS_velocity_N; /*<  sbg: position accurancy of lat*/
 int16_t SCNS_velocity_E; /*<  sbg: position accurancy of lon*/
 int16_t SCNS_velocity_U; /*<  sbg: position accurancy of alt*/
 int16_t SCNS_picth; /*<  sbg: pitch*/
 int16_t SCNS_roll; /*<  sbg: roll*/
 uint16_t SCNS_yaw; /*<  sbg: yaw*/
 int16_t SCNS_rollRate; /*<  sbg: roll rate*/
 int16_t SCNS_pitchRate; /*<  sbg: pitch rate*/
 int16_t SCNS_yawRate; /*<  sbg: yaw rate*/
 int16_t SCNS_xAcc; /*<  sbg: X acc*/
 int16_t SCNS_yAcc; /*<  sbg: Y acc*/
 int16_t SCNS_zAcc; /*<  sbg: Z acc*/
 uint16_t SCNS_alt; /*<  sbg: gps position alt*/
 int16_t SCNS_Vg_2D; /*<  sbg: Vg 2D*/
 uint16_t intSensor_Eph; /*<  inter sensor: eph*/
 uint16_t intSensor_Epv; /*<  inter sensor: epv*/
 uint16_t intSensor_alt_gps; /*<  inter sensor: gps position alt*/
 uint16_t intSensor_Vg_2D; /*<  inter sensor: Vg 2D*/
 int16_t intSensor_roll; /*<  inter sensor: roll*/
 int16_t intSensor_pitch; /*<  inter sensor: pitch*/
 uint16_t intSensor_yaw; /*<  inter sensor: yaw*/
 int16_t intSensor_psiV; /*<  inter sensor: psiV*/
 int16_t intSensor_rollRate; /*<  inter sensor: roll rate*/
 int16_t intSensor_pitchRate; /*<  inter sensor: pitch rate*/
 int16_t intSensor_yawRate; /*<  inter sensor: yaw rate*/
 uint16_t intSensor_alt_baro; /*<  inter sensor: barometer alt*/
 int16_t intSensor_Vi; /*<  inter sensor: airspeed*/
 uint16_t actFb_1; /*<  pwm/rotary/angle feedback: 1*/
 uint16_t actFb_2; /*<  pwm/rotary/angle feedback: 2*/
 uint16_t actFb_3; /*<  pwm/rotary/angle feedback: 3*/
 uint16_t actFb_4; /*<  pwm/rotary/angle feedback: 4*/
 uint16_t actFb_5; /*<  pwm/rotary/angle feedback: 5*/
 uint16_t actFb_6; /*<  pwm/rotary/angle feedback: 6*/
 uint16_t actFb_7; /*<  pwm/rotary/angle feedback: 7*/
 uint16_t actFb_8; /*<  pwm/rotary/angle feedback: 8*/
 uint16_t actFb_9; /*<  pwm/rotary/angle feedback: 9*/
 uint16_t actFb_10; /*<  pwm/rotary/angle feedback: 10*/
 uint16_t actFb_11; /*<  pwm/rotary/angle feedback: 11*/
 uint16_t actFb_12; /*<  pwm/rotary/angle feedback: 12*/
 uint16_t actFb_13; /*<  pwm/rotary/angle feedback: 13*/
 uint16_t actFb_14; /*<  pwm/rotary/angle feedback: 14*/
 uint16_t actFb_15; /*<  pwm/rotary/angle feedback: 15*/
 uint16_t actFb_16; /*<  pwm/rotary/angle feedback: 16*/
 uint16_t voltage_tether; /*<  voltage of tether power*/
 uint16_t current_tether; /*<  current of tether power*/
 uint16_t motor_alarm; /*<  alarm of motor stops running, bit0-15,0-normal,1-stop*/
 uint16_t voltage_power; /*<  voltage of power*/ 
 int16_t airlineTrack_dL; /*<  airlineTrack: dL*/
 int16_t airlineTrack_dY; /*<  airlineTrack: dY*/
 int16_t airlineTrack_dH; /*<  airlineTrack: dH*/
 uint8_t vehicle_id; /*<  vehicle id*/
 uint8_t link_quality; /*<  communication quality*/
 uint8_t err_rate; /*<  bit err rate*/
 uint8_t endurance_time_min; /*<  endurance time,unit min*/
 uint8_t endurance_distance_km; /*<  endurance distance,unit km*/
 uint8_t year; /*<  GPS time,year-2020*/
 uint8_t month; /*<  GPS time,month*/
 uint8_t day; /*<  GPS time,day*/
 uint8_t hour; /*<  GPS time,hour*/
 uint8_t min; /*<  GPS time,min*/
 uint8_t sec; /*<  GPS time,sec*/
 uint8_t armed; /*<  arm status*/
 uint8_t flight_mode; /*<  flight mode*/
 uint8_t fix_mode; /*<  GPS fix mode*/
 uint8_t satelliteUse; /*<  satellite use number*/
 uint8_t posSrc; /*<  position sensor source*/
 uint8_t altSrc; /*<  altitude sensor source*/
 uint8_t airSpdSrc; /*<  airSpeed sensor source*/
 uint8_t grdSpdSrc; /*<  ground speed sensor source*/
 uint8_t attSrc; /*<  attitude sensor source*/
 uint8_t yawSrc; /*<  yaw sensor source*/
 uint8_t lawOuput_thr; /*<  law output: thr*/
 uint8_t lawOuput_F_thrust; /*<  law output: thrust of mc*/
 uint8_t lawOuput_M_Roll; /*<  law output: roll moment of mc*/
 uint8_t lawOuput_M_Pitch; /*<  law output: pitch moment of mc*/
 uint8_t lawOuput_M_Yaw; /*<  law output: yaw moment of mc*/
 uint8_t flight_state; /*<  1-fw, 2-transition ,3-mc*/
 uint8_t power_alarm;/*<  bit0:vol of fmu,bit1:vol of motor,bit2:vol of actuator,bit3:vol of tether,0-normal,1-low*/ 
 uint8_t SCNS_fault_flag; /*<  extIns: star use*/
 uint8_t SCNS_mode; /*<  extIns: navigation status*/
 uint8_t SCNS_fix_status; /*<  extIns: gps fix status*/
 uint8_t SCNS_PDOP; /*<  extIns: PDOP status*/
 uint8_t intSensor_fixStatus; /*<  internal sensor: fix status*/
 uint8_t intSensor_starUse; /*<  internal sensor: star use*/
 uint8_t voltage_equip; /*<  voltage of equipment*/
 uint8_t voltage_actuator; /*<  voltage of actuator*/
 uint8_t cpuload_0; /*<  voltage of actuator*/
 uint8_t cpuload_1; /*<  voltage of actuator*/
 char text[30]; /*<  Status text message, without null termination character*/
} mavlink_tele_data_t;

#define MAVLINK_MSG_ID_TELE_DATA_LEN 248
#define MAVLINK_MSG_ID_TELE_DATA_MIN_LEN 248
#define MAVLINK_MSG_ID_156_LEN 248
#define MAVLINK_MSG_ID_156_MIN_LEN 248

#define MAVLINK_MSG_ID_TELE_DATA_CRC 255
#define MAVLINK_MSG_ID_156_CRC 255

#define MAVLINK_MSG_TELE_DATA_FIELD_TEXT_LEN 30
#if 0
#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TELE_DATA { \
    156, \
    "TELE_DATA", \
    106, \
    {  { "vehicle_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 162, offsetof(mavlink_tele_data_t, vehicle_id) }, \
         { "link_quality", NULL, MAVLINK_TYPE_UINT8_T, 0, 163, offsetof(mavlink_tele_data_t, link_quality) }, \
         { "err_rate", NULL, MAVLINK_TYPE_UINT8_T, 0, 164, offsetof(mavlink_tele_data_t, err_rate) }, \
         { "flight_time_sec", NULL, MAVLINK_TYPE_UINT16_T, 0, 32, offsetof(mavlink_tele_data_t, flight_time_sec) }, \
         { "endurance_time_min", NULL, MAVLINK_TYPE_UINT8_T, 0, 165, offsetof(mavlink_tele_data_t, endurance_time_min) }, \
         { "endurance_distance_km", NULL, MAVLINK_TYPE_UINT8_T, 0, 166, offsetof(mavlink_tele_data_t, endurance_distance_km) }, \
         { "distance2Home", NULL, MAVLINK_TYPE_UINT16_T, 0, 34, offsetof(mavlink_tele_data_t, distance2Home) }, \
         { "year", NULL, MAVLINK_TYPE_UINT8_T, 0, 167, offsetof(mavlink_tele_data_t, year) }, \
         { "month", NULL, MAVLINK_TYPE_UINT8_T, 0, 168, offsetof(mavlink_tele_data_t, month) }, \
         { "day", NULL, MAVLINK_TYPE_UINT8_T, 0, 169, offsetof(mavlink_tele_data_t, day) }, \
         { "hour", NULL, MAVLINK_TYPE_UINT8_T, 0, 170, offsetof(mavlink_tele_data_t, hour) }, \
         { "min", NULL, MAVLINK_TYPE_UINT8_T, 0, 171, offsetof(mavlink_tele_data_t, min) }, \
         { "sec", NULL, MAVLINK_TYPE_UINT8_T, 0, 172, offsetof(mavlink_tele_data_t, sec) }, \
         { "homePos_lat", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_tele_data_t, homePos_lat) }, \
         { "homePos_lon", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_tele_data_t, homePos_lon) }, \
         { "homePos_alt", NULL, MAVLINK_TYPE_UINT16_T, 0, 36, offsetof(mavlink_tele_data_t, homePos_alt) }, \
         { "armed", NULL, MAVLINK_TYPE_UINT8_T, 0, 173, offsetof(mavlink_tele_data_t, armed) }, \
         { "flight_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 174, offsetof(mavlink_tele_data_t, flight_mode) }, \
         { "fix_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 175, offsetof(mavlink_tele_data_t, fix_mode) }, \
         { "satelliteUse", NULL, MAVLINK_TYPE_UINT8_T, 0, 176, offsetof(mavlink_tele_data_t, satelliteUse) }, \
         { "posSrc", NULL, MAVLINK_TYPE_UINT8_T, 0, 177, offsetof(mavlink_tele_data_t, posSrc) }, \
         { "altSrc", NULL, MAVLINK_TYPE_UINT8_T, 0, 178, offsetof(mavlink_tele_data_t, altSrc) }, \
         { "airSpdSrc", NULL, MAVLINK_TYPE_UINT8_T, 0, 179, offsetof(mavlink_tele_data_t, airSpdSrc) }, \
         { "grdSpdSrc", NULL, MAVLINK_TYPE_UINT8_T, 0, 180, offsetof(mavlink_tele_data_t, grdSpdSrc) }, \
         { "attSrc", NULL, MAVLINK_TYPE_UINT8_T, 0, 181, offsetof(mavlink_tele_data_t, attSrc) }, \
         { "yawSrc", NULL, MAVLINK_TYPE_UINT8_T, 0, 182, offsetof(mavlink_tele_data_t, yawSrc) }, \
         { "pitch", NULL, MAVLINK_TYPE_INT16_T, 0, 38, offsetof(mavlink_tele_data_t, pitch) }, \
         { "roll", NULL, MAVLINK_TYPE_INT16_T, 0, 40, offsetof(mavlink_tele_data_t, roll) }, \
         { "Vi", NULL, MAVLINK_TYPE_UINT16_T, 0, 42, offsetof(mavlink_tele_data_t, Vi) }, \
         { "Vg", NULL, MAVLINK_TYPE_UINT16_T, 0, 44, offsetof(mavlink_tele_data_t, Vg) }, \
         { "hdot", NULL, MAVLINK_TYPE_INT16_T, 0, 46, offsetof(mavlink_tele_data_t, hdot) }, \
         { "yaw", NULL, MAVLINK_TYPE_UINT16_T, 0, 48, offsetof(mavlink_tele_data_t, yaw) }, \
         { "psiV", NULL, MAVLINK_TYPE_INT16_T, 0, 50, offsetof(mavlink_tele_data_t, psiV) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_tele_data_t, lon) }, \
         { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_tele_data_t, lat) }, \
         { "alt", NULL, MAVLINK_TYPE_UINT16_T, 0, 52, offsetof(mavlink_tele_data_t, alt) }, \
         { "alt_relative", NULL, MAVLINK_TYPE_UINT16_T, 0, 54, offsetof(mavlink_tele_data_t, alt_relative) }, \
         { "cmd_alt", NULL, MAVLINK_TYPE_UINT16_T, 0, 56, offsetof(mavlink_tele_data_t, cmd_alt) }, \
         { "cmd_Vi", NULL, MAVLINK_TYPE_UINT16_T, 0, 58, offsetof(mavlink_tele_data_t, cmd_Vi) }, \
         { "cmd_theta", NULL, MAVLINK_TYPE_INT16_T, 0, 60, offsetof(mavlink_tele_data_t, cmd_theta) }, \
         { "cmd_phi", NULL, MAVLINK_TYPE_INT16_T, 0, 62, offsetof(mavlink_tele_data_t, cmd_phi) }, \
         { "cmd_psi", NULL, MAVLINK_TYPE_INT16_T, 0, 64, offsetof(mavlink_tele_data_t, cmd_psi) }, \
         { "cmd_hdot", NULL, MAVLINK_TYPE_INT16_T, 0, 66, offsetof(mavlink_tele_data_t, cmd_hdot) }, \
         { "lawOuput_ele", NULL, MAVLINK_TYPE_INT16_T, 0, 68, offsetof(mavlink_tele_data_t, lawOuput_ele) }, \
         { "lawOuput_ail", NULL, MAVLINK_TYPE_INT16_T, 0, 70, offsetof(mavlink_tele_data_t, lawOuput_ail) }, \
         { "lawOuput_rud", NULL, MAVLINK_TYPE_INT16_T, 0, 72, offsetof(mavlink_tele_data_t, lawOuput_rud) }, \
         { "lawOuput_thr", NULL, MAVLINK_TYPE_UINT8_T, 0, 183, offsetof(mavlink_tele_data_t, lawOuput_thr) }, \
         { "SCNS_fault_flag", NULL, MAVLINK_TYPE_UINT8_T, 0, 184, offsetof(mavlink_tele_data_t, SCNS_fault_flag) }, \
         { "SCNS_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 185, offsetof(mavlink_tele_data_t, SCNS_mode) }, \
         { "SCNS_fix_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 186, offsetof(mavlink_tele_data_t, SCNS_fix_status) }, \
         { "SCNS_PDOP", NULL, MAVLINK_TYPE_UINT8_T, 0, 187, offsetof(mavlink_tele_data_t, SCNS_PDOP) }, \
         { "SCNS_velocity_N", NULL, MAVLINK_TYPE_INT16_T, 0, 74, offsetof(mavlink_tele_data_t, SCNS_velocity_N) }, \
         { "SCNS_velocity_E", NULL, MAVLINK_TYPE_INT16_T, 0, 76, offsetof(mavlink_tele_data_t, SCNS_velocity_E) }, \
         { "SCNS_velocity_U", NULL, MAVLINK_TYPE_INT16_T, 0, 78, offsetof(mavlink_tele_data_t, SCNS_velocity_U) }, \
         { "SCNS_picth", NULL, MAVLINK_TYPE_INT16_T, 0, 80, offsetof(mavlink_tele_data_t, SCNS_picth) }, \
         { "SCNS_roll", NULL, MAVLINK_TYPE_INT16_T, 0, 82, offsetof(mavlink_tele_data_t, SCNS_roll) }, \
         { "SCNS_yaw", NULL, MAVLINK_TYPE_UINT16_T, 0, 84, offsetof(mavlink_tele_data_t, SCNS_yaw) }, \
         { "SCNS_rollRate", NULL, MAVLINK_TYPE_INT16_T, 0, 86, offsetof(mavlink_tele_data_t, SCNS_rollRate) }, \
         { "SCNS_pitchRate", NULL, MAVLINK_TYPE_INT16_T, 0, 88, offsetof(mavlink_tele_data_t, SCNS_pitchRate) }, \
         { "SCNS_yawRate", NULL, MAVLINK_TYPE_INT16_T, 0, 90, offsetof(mavlink_tele_data_t, SCNS_yawRate) }, \
         { "SCNS_xAcc", NULL, MAVLINK_TYPE_INT16_T, 0, 92, offsetof(mavlink_tele_data_t, SCNS_xAcc) }, \
         { "SCNS_lon", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_tele_data_t, SCNS_lon) }, \
         { "SCNS_lat", NULL, MAVLINK_TYPE_INT32_T, 0, 20, offsetof(mavlink_tele_data_t, SCNS_lat) }, \
         { "SCNS_alt", NULL, MAVLINK_TYPE_UINT16_T, 0, 94, offsetof(mavlink_tele_data_t, SCNS_alt) }, \
         { "SCNS_Vg_2D", NULL, MAVLINK_TYPE_INT16_T, 0, 96, offsetof(mavlink_tele_data_t, SCNS_Vg_2D) }, \
         { "intSensor_fixStatus", NULL, MAVLINK_TYPE_UINT8_T, 0, 188, offsetof(mavlink_tele_data_t, intSensor_fixStatus) }, \
         { "intSensor_starUse", NULL, MAVLINK_TYPE_UINT8_T, 0, 189, offsetof(mavlink_tele_data_t, intSensor_starUse) }, \
         { "intSensor_Eph", NULL, MAVLINK_TYPE_UINT16_T, 0, 98, offsetof(mavlink_tele_data_t, intSensor_Eph) }, \
         { "intSensor_Epv", NULL, MAVLINK_TYPE_UINT16_T, 0, 100, offsetof(mavlink_tele_data_t, intSensor_Epv) }, \
         { "intSensor_lon_gps", NULL, MAVLINK_TYPE_INT32_T, 0, 24, offsetof(mavlink_tele_data_t, intSensor_lon_gps) }, \
         { "intSensor_lat_gps", NULL, MAVLINK_TYPE_INT32_T, 0, 28, offsetof(mavlink_tele_data_t, intSensor_lat_gps) }, \
         { "intSensor_alt_gps", NULL, MAVLINK_TYPE_UINT16_T, 0, 102, offsetof(mavlink_tele_data_t, intSensor_alt_gps) }, \
         { "intSensor_Vg_2D", NULL, MAVLINK_TYPE_UINT16_T, 0, 104, offsetof(mavlink_tele_data_t, intSensor_Vg_2D) }, \
         { "intSensor_roll", NULL, MAVLINK_TYPE_INT16_T, 0, 106, offsetof(mavlink_tele_data_t, intSensor_roll) }, \
         { "intSensor_pitch", NULL, MAVLINK_TYPE_INT16_T, 0, 108, offsetof(mavlink_tele_data_t, intSensor_pitch) }, \
         { "intSensor_yaw", NULL, MAVLINK_TYPE_UINT16_T, 0, 110, offsetof(mavlink_tele_data_t, intSensor_yaw) }, \
         { "intSensor_psiV", NULL, MAVLINK_TYPE_INT16_T, 0, 112, offsetof(mavlink_tele_data_t, intSensor_psiV) }, \
         { "intSensor_rollRate", NULL, MAVLINK_TYPE_INT16_T, 0, 114, offsetof(mavlink_tele_data_t, intSensor_rollRate) }, \
         { "intSensor_pitchRate", NULL, MAVLINK_TYPE_INT16_T, 0, 116, offsetof(mavlink_tele_data_t, intSensor_pitchRate) }, \
         { "intSensor_yawRate", NULL, MAVLINK_TYPE_INT16_T, 0, 118, offsetof(mavlink_tele_data_t, intSensor_yawRate) }, \
         { "intSensor_alt_baro", NULL, MAVLINK_TYPE_UINT16_T, 0, 120, offsetof(mavlink_tele_data_t, intSensor_alt_baro) }, \
         { "intSensor_Vi", NULL, MAVLINK_TYPE_INT16_T, 0, 122, offsetof(mavlink_tele_data_t, intSensor_Vi) }, \
         { "pwmOut_ail_L", NULL, MAVLINK_TYPE_UINT16_T, 0, 124, offsetof(mavlink_tele_data_t, pwmOut_ail_L) }, \
         { "pwmOut_ail_R", NULL, MAVLINK_TYPE_UINT16_T, 0, 126, offsetof(mavlink_tele_data_t, pwmOut_ail_R) }, \
         { "pwmOut_ele_L", NULL, MAVLINK_TYPE_UINT16_T, 0, 128, offsetof(mavlink_tele_data_t, pwmOut_ele_L) }, \
         { "pwmOut_ele_R", NULL, MAVLINK_TYPE_UINT16_T, 0, 130, offsetof(mavlink_tele_data_t, pwmOut_ele_R) }, \
         { "pwmOut_rud_L", NULL, MAVLINK_TYPE_UINT16_T, 0, 132, offsetof(mavlink_tele_data_t, pwmOut_rud_L) }, \
         { "pwmOut_rud_R", NULL, MAVLINK_TYPE_UINT16_T, 0, 134, offsetof(mavlink_tele_data_t, pwmOut_rud_R) }, \
         { "pwmOut_thr", NULL, MAVLINK_TYPE_UINT16_T, 0, 136, offsetof(mavlink_tele_data_t, pwmOut_thr) }, \
         { "pwmFb_ail_L", NULL, MAVLINK_TYPE_UINT16_T, 0, 138, offsetof(mavlink_tele_data_t, pwmFb_ail_L) }, \
         { "pwmFb_ail_R", NULL, MAVLINK_TYPE_UINT16_T, 0, 140, offsetof(mavlink_tele_data_t, pwmFb_ail_R) }, \
         { "pwmFb_ele_L", NULL, MAVLINK_TYPE_UINT16_T, 0, 142, offsetof(mavlink_tele_data_t, pwmFb_ele_L) }, \
         { "pwmFb_ele_R", NULL, MAVLINK_TYPE_UINT16_T, 0, 144, offsetof(mavlink_tele_data_t, pwmFb_ele_R) }, \
         { "pwmFb_rud_L", NULL, MAVLINK_TYPE_UINT16_T, 0, 146, offsetof(mavlink_tele_data_t, pwmFb_rud_L) }, \
         { "pwmFb_rud_R", NULL, MAVLINK_TYPE_UINT16_T, 0, 148, offsetof(mavlink_tele_data_t, pwmFb_rud_R) }, \
         { "pwmFb_thr", NULL, MAVLINK_TYPE_UINT16_T, 0, 150, offsetof(mavlink_tele_data_t, pwmFb_thr) }, \
         { "voltage_power", NULL, MAVLINK_TYPE_UINT16_T, 0, 152, offsetof(mavlink_tele_data_t, voltage_power) }, \
         { "voltage_equip", NULL, MAVLINK_TYPE_UINT8_T, 0, 190, offsetof(mavlink_tele_data_t, voltage_equip) }, \
         { "voltage_actuator", NULL, MAVLINK_TYPE_UINT8_T, 0, 191, offsetof(mavlink_tele_data_t, voltage_actuator) }, \
         { "DI_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 192, offsetof(mavlink_tele_data_t, DI_status) }, \
         { "DO_status", NULL, MAVLINK_TYPE_UINT16_T, 0, 154, offsetof(mavlink_tele_data_t, DO_status) }, \
         { "airlineTrack_dL", NULL, MAVLINK_TYPE_INT16_T, 0, 156, offsetof(mavlink_tele_data_t, airlineTrack_dL) }, \
         { "airlineTrack_dY", NULL, MAVLINK_TYPE_INT16_T, 0, 158, offsetof(mavlink_tele_data_t, airlineTrack_dY) }, \
         { "airlineTrack_dH", NULL, MAVLINK_TYPE_INT16_T, 0, 160, offsetof(mavlink_tele_data_t, airlineTrack_dH) }, \
         { "severity", NULL, MAVLINK_TYPE_UINT8_T, 0, 193, offsetof(mavlink_tele_data_t, severity) }, \
         { "text", NULL, MAVLINK_TYPE_CHAR, 30, 194, offsetof(mavlink_tele_data_t, text) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TELE_DATA { \
    "TELE_DATA", \
    106, \
    {  { "vehicle_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 162, offsetof(mavlink_tele_data_t, vehicle_id) }, \
         { "link_quality", NULL, MAVLINK_TYPE_UINT8_T, 0, 163, offsetof(mavlink_tele_data_t, link_quality) }, \
         { "err_rate", NULL, MAVLINK_TYPE_UINT8_T, 0, 164, offsetof(mavlink_tele_data_t, err_rate) }, \
         { "flight_time_sec", NULL, MAVLINK_TYPE_UINT16_T, 0, 32, offsetof(mavlink_tele_data_t, flight_time_sec) }, \
         { "endurance_time_min", NULL, MAVLINK_TYPE_UINT8_T, 0, 165, offsetof(mavlink_tele_data_t, endurance_time_min) }, \
         { "endurance_distance_km", NULL, MAVLINK_TYPE_UINT8_T, 0, 166, offsetof(mavlink_tele_data_t, endurance_distance_km) }, \
         { "distance2Home", NULL, MAVLINK_TYPE_UINT16_T, 0, 34, offsetof(mavlink_tele_data_t, distance2Home) }, \
         { "year", NULL, MAVLINK_TYPE_UINT8_T, 0, 167, offsetof(mavlink_tele_data_t, year) }, \
         { "month", NULL, MAVLINK_TYPE_UINT8_T, 0, 168, offsetof(mavlink_tele_data_t, month) }, \
         { "day", NULL, MAVLINK_TYPE_UINT8_T, 0, 169, offsetof(mavlink_tele_data_t, day) }, \
         { "hour", NULL, MAVLINK_TYPE_UINT8_T, 0, 170, offsetof(mavlink_tele_data_t, hour) }, \
         { "min", NULL, MAVLINK_TYPE_UINT8_T, 0, 171, offsetof(mavlink_tele_data_t, min) }, \
         { "sec", NULL, MAVLINK_TYPE_UINT8_T, 0, 172, offsetof(mavlink_tele_data_t, sec) }, \
         { "homePos_lat", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_tele_data_t, homePos_lat) }, \
         { "homePos_lon", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_tele_data_t, homePos_lon) }, \
         { "homePos_alt", NULL, MAVLINK_TYPE_UINT16_T, 0, 36, offsetof(mavlink_tele_data_t, homePos_alt) }, \
         { "armed", NULL, MAVLINK_TYPE_UINT8_T, 0, 173, offsetof(mavlink_tele_data_t, armed) }, \
         { "flight_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 174, offsetof(mavlink_tele_data_t, flight_mode) }, \
         { "fix_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 175, offsetof(mavlink_tele_data_t, fix_mode) }, \
         { "satelliteUse", NULL, MAVLINK_TYPE_UINT8_T, 0, 176, offsetof(mavlink_tele_data_t, satelliteUse) }, \
         { "posSrc", NULL, MAVLINK_TYPE_UINT8_T, 0, 177, offsetof(mavlink_tele_data_t, posSrc) }, \
         { "altSrc", NULL, MAVLINK_TYPE_UINT8_T, 0, 178, offsetof(mavlink_tele_data_t, altSrc) }, \
         { "airSpdSrc", NULL, MAVLINK_TYPE_UINT8_T, 0, 179, offsetof(mavlink_tele_data_t, airSpdSrc) }, \
         { "grdSpdSrc", NULL, MAVLINK_TYPE_UINT8_T, 0, 180, offsetof(mavlink_tele_data_t, grdSpdSrc) }, \
         { "attSrc", NULL, MAVLINK_TYPE_UINT8_T, 0, 181, offsetof(mavlink_tele_data_t, attSrc) }, \
         { "yawSrc", NULL, MAVLINK_TYPE_UINT8_T, 0, 182, offsetof(mavlink_tele_data_t, yawSrc) }, \
         { "pitch", NULL, MAVLINK_TYPE_INT16_T, 0, 38, offsetof(mavlink_tele_data_t, pitch) }, \
         { "roll", NULL, MAVLINK_TYPE_INT16_T, 0, 40, offsetof(mavlink_tele_data_t, roll) }, \
         { "Vi", NULL, MAVLINK_TYPE_UINT16_T, 0, 42, offsetof(mavlink_tele_data_t, Vi) }, \
         { "Vg", NULL, MAVLINK_TYPE_UINT16_T, 0, 44, offsetof(mavlink_tele_data_t, Vg) }, \
         { "hdot", NULL, MAVLINK_TYPE_INT16_T, 0, 46, offsetof(mavlink_tele_data_t, hdot) }, \
         { "yaw", NULL, MAVLINK_TYPE_UINT16_T, 0, 48, offsetof(mavlink_tele_data_t, yaw) }, \
         { "psiV", NULL, MAVLINK_TYPE_INT16_T, 0, 50, offsetof(mavlink_tele_data_t, psiV) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_tele_data_t, lon) }, \
         { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_tele_data_t, lat) }, \
         { "alt", NULL, MAVLINK_TYPE_UINT16_T, 0, 52, offsetof(mavlink_tele_data_t, alt) }, \
         { "alt_relative", NULL, MAVLINK_TYPE_UINT16_T, 0, 54, offsetof(mavlink_tele_data_t, alt_relative) }, \
         { "cmd_alt", NULL, MAVLINK_TYPE_UINT16_T, 0, 56, offsetof(mavlink_tele_data_t, cmd_alt) }, \
         { "cmd_Vi", NULL, MAVLINK_TYPE_UINT16_T, 0, 58, offsetof(mavlink_tele_data_t, cmd_Vi) }, \
         { "cmd_theta", NULL, MAVLINK_TYPE_INT16_T, 0, 60, offsetof(mavlink_tele_data_t, cmd_theta) }, \
         { "cmd_phi", NULL, MAVLINK_TYPE_INT16_T, 0, 62, offsetof(mavlink_tele_data_t, cmd_phi) }, \
         { "cmd_psi", NULL, MAVLINK_TYPE_INT16_T, 0, 64, offsetof(mavlink_tele_data_t, cmd_psi) }, \
         { "cmd_hdot", NULL, MAVLINK_TYPE_INT16_T, 0, 66, offsetof(mavlink_tele_data_t, cmd_hdot) }, \
         { "lawOuput_ele", NULL, MAVLINK_TYPE_INT16_T, 0, 68, offsetof(mavlink_tele_data_t, lawOuput_ele) }, \
         { "lawOuput_ail", NULL, MAVLINK_TYPE_INT16_T, 0, 70, offsetof(mavlink_tele_data_t, lawOuput_ail) }, \
         { "lawOuput_rud", NULL, MAVLINK_TYPE_INT16_T, 0, 72, offsetof(mavlink_tele_data_t, lawOuput_rud) }, \
         { "lawOuput_thr", NULL, MAVLINK_TYPE_UINT8_T, 0, 183, offsetof(mavlink_tele_data_t, lawOuput_thr) }, \
         { "SCNS_fault_flag", NULL, MAVLINK_TYPE_UINT8_T, 0, 184, offsetof(mavlink_tele_data_t, SCNS_fault_flag) }, \
         { "SCNS_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 185, offsetof(mavlink_tele_data_t, SCNS_mode) }, \
         { "SCNS_fix_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 186, offsetof(mavlink_tele_data_t, SCNS_fix_status) }, \
         { "SCNS_PDOP", NULL, MAVLINK_TYPE_UINT8_T, 0, 187, offsetof(mavlink_tele_data_t, SCNS_PDOP) }, \
         { "SCNS_velocity_N", NULL, MAVLINK_TYPE_INT16_T, 0, 74, offsetof(mavlink_tele_data_t, SCNS_velocity_N) }, \
         { "SCNS_velocity_E", NULL, MAVLINK_TYPE_INT16_T, 0, 76, offsetof(mavlink_tele_data_t, SCNS_velocity_E) }, \
         { "SCNS_velocity_U", NULL, MAVLINK_TYPE_INT16_T, 0, 78, offsetof(mavlink_tele_data_t, SCNS_velocity_U) }, \
         { "SCNS_picth", NULL, MAVLINK_TYPE_INT16_T, 0, 80, offsetof(mavlink_tele_data_t, SCNS_picth) }, \
         { "SCNS_roll", NULL, MAVLINK_TYPE_INT16_T, 0, 82, offsetof(mavlink_tele_data_t, SCNS_roll) }, \
         { "SCNS_yaw", NULL, MAVLINK_TYPE_UINT16_T, 0, 84, offsetof(mavlink_tele_data_t, SCNS_yaw) }, \
         { "SCNS_rollRate", NULL, MAVLINK_TYPE_INT16_T, 0, 86, offsetof(mavlink_tele_data_t, SCNS_rollRate) }, \
         { "SCNS_pitchRate", NULL, MAVLINK_TYPE_INT16_T, 0, 88, offsetof(mavlink_tele_data_t, SCNS_pitchRate) }, \
         { "SCNS_yawRate", NULL, MAVLINK_TYPE_INT16_T, 0, 90, offsetof(mavlink_tele_data_t, SCNS_yawRate) }, \
         { "SCNS_xAcc", NULL, MAVLINK_TYPE_INT16_T, 0, 92, offsetof(mavlink_tele_data_t, SCNS_xAcc) }, \
         { "SCNS_lon", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_tele_data_t, SCNS_lon) }, \
         { "SCNS_lat", NULL, MAVLINK_TYPE_INT32_T, 0, 20, offsetof(mavlink_tele_data_t, SCNS_lat) }, \
         { "SCNS_alt", NULL, MAVLINK_TYPE_UINT16_T, 0, 94, offsetof(mavlink_tele_data_t, SCNS_alt) }, \
         { "SCNS_Vg_2D", NULL, MAVLINK_TYPE_INT16_T, 0, 96, offsetof(mavlink_tele_data_t, SCNS_Vg_2D) }, \
         { "intSensor_fixStatus", NULL, MAVLINK_TYPE_UINT8_T, 0, 188, offsetof(mavlink_tele_data_t, intSensor_fixStatus) }, \
         { "intSensor_starUse", NULL, MAVLINK_TYPE_UINT8_T, 0, 189, offsetof(mavlink_tele_data_t, intSensor_starUse) }, \
         { "intSensor_Eph", NULL, MAVLINK_TYPE_UINT16_T, 0, 98, offsetof(mavlink_tele_data_t, intSensor_Eph) }, \
         { "intSensor_Epv", NULL, MAVLINK_TYPE_UINT16_T, 0, 100, offsetof(mavlink_tele_data_t, intSensor_Epv) }, \
         { "intSensor_lon_gps", NULL, MAVLINK_TYPE_INT32_T, 0, 24, offsetof(mavlink_tele_data_t, intSensor_lon_gps) }, \
         { "intSensor_lat_gps", NULL, MAVLINK_TYPE_INT32_T, 0, 28, offsetof(mavlink_tele_data_t, intSensor_lat_gps) }, \
         { "intSensor_alt_gps", NULL, MAVLINK_TYPE_UINT16_T, 0, 102, offsetof(mavlink_tele_data_t, intSensor_alt_gps) }, \
         { "intSensor_Vg_2D", NULL, MAVLINK_TYPE_UINT16_T, 0, 104, offsetof(mavlink_tele_data_t, intSensor_Vg_2D) }, \
         { "intSensor_roll", NULL, MAVLINK_TYPE_INT16_T, 0, 106, offsetof(mavlink_tele_data_t, intSensor_roll) }, \
         { "intSensor_pitch", NULL, MAVLINK_TYPE_INT16_T, 0, 108, offsetof(mavlink_tele_data_t, intSensor_pitch) }, \
         { "intSensor_yaw", NULL, MAVLINK_TYPE_UINT16_T, 0, 110, offsetof(mavlink_tele_data_t, intSensor_yaw) }, \
         { "intSensor_psiV", NULL, MAVLINK_TYPE_INT16_T, 0, 112, offsetof(mavlink_tele_data_t, intSensor_psiV) }, \
         { "intSensor_rollRate", NULL, MAVLINK_TYPE_INT16_T, 0, 114, offsetof(mavlink_tele_data_t, intSensor_rollRate) }, \
         { "intSensor_pitchRate", NULL, MAVLINK_TYPE_INT16_T, 0, 116, offsetof(mavlink_tele_data_t, intSensor_pitchRate) }, \
         { "intSensor_yawRate", NULL, MAVLINK_TYPE_INT16_T, 0, 118, offsetof(mavlink_tele_data_t, intSensor_yawRate) }, \
         { "intSensor_alt_baro", NULL, MAVLINK_TYPE_UINT16_T, 0, 120, offsetof(mavlink_tele_data_t, intSensor_alt_baro) }, \
         { "intSensor_Vi", NULL, MAVLINK_TYPE_INT16_T, 0, 122, offsetof(mavlink_tele_data_t, intSensor_Vi) }, \
         { "pwmOut_ail_L", NULL, MAVLINK_TYPE_UINT16_T, 0, 124, offsetof(mavlink_tele_data_t, pwmOut_ail_L) }, \
         { "pwmOut_ail_R", NULL, MAVLINK_TYPE_UINT16_T, 0, 126, offsetof(mavlink_tele_data_t, pwmOut_ail_R) }, \
         { "pwmOut_ele_L", NULL, MAVLINK_TYPE_UINT16_T, 0, 128, offsetof(mavlink_tele_data_t, pwmOut_ele_L) }, \
         { "pwmOut_ele_R", NULL, MAVLINK_TYPE_UINT16_T, 0, 130, offsetof(mavlink_tele_data_t, pwmOut_ele_R) }, \
         { "pwmOut_rud_L", NULL, MAVLINK_TYPE_UINT16_T, 0, 132, offsetof(mavlink_tele_data_t, pwmOut_rud_L) }, \
         { "pwmOut_rud_R", NULL, MAVLINK_TYPE_UINT16_T, 0, 134, offsetof(mavlink_tele_data_t, pwmOut_rud_R) }, \
         { "pwmOut_thr", NULL, MAVLINK_TYPE_UINT16_T, 0, 136, offsetof(mavlink_tele_data_t, pwmOut_thr) }, \
         { "pwmFb_ail_L", NULL, MAVLINK_TYPE_UINT16_T, 0, 138, offsetof(mavlink_tele_data_t, pwmFb_ail_L) }, \
         { "pwmFb_ail_R", NULL, MAVLINK_TYPE_UINT16_T, 0, 140, offsetof(mavlink_tele_data_t, pwmFb_ail_R) }, \
         { "pwmFb_ele_L", NULL, MAVLINK_TYPE_UINT16_T, 0, 142, offsetof(mavlink_tele_data_t, pwmFb_ele_L) }, \
         { "pwmFb_ele_R", NULL, MAVLINK_TYPE_UINT16_T, 0, 144, offsetof(mavlink_tele_data_t, pwmFb_ele_R) }, \
         { "pwmFb_rud_L", NULL, MAVLINK_TYPE_UINT16_T, 0, 146, offsetof(mavlink_tele_data_t, pwmFb_rud_L) }, \
         { "pwmFb_rud_R", NULL, MAVLINK_TYPE_UINT16_T, 0, 148, offsetof(mavlink_tele_data_t, pwmFb_rud_R) }, \
         { "pwmFb_thr", NULL, MAVLINK_TYPE_UINT16_T, 0, 150, offsetof(mavlink_tele_data_t, pwmFb_thr) }, \
         { "voltage_power", NULL, MAVLINK_TYPE_UINT16_T, 0, 152, offsetof(mavlink_tele_data_t, voltage_power) }, \
         { "voltage_equip", NULL, MAVLINK_TYPE_UINT8_T, 0, 190, offsetof(mavlink_tele_data_t, voltage_equip) }, \
         { "voltage_actuator", NULL, MAVLINK_TYPE_UINT8_T, 0, 191, offsetof(mavlink_tele_data_t, voltage_actuator) }, \
         { "DI_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 192, offsetof(mavlink_tele_data_t, DI_status) }, \
         { "DO_status", NULL, MAVLINK_TYPE_UINT16_T, 0, 154, offsetof(mavlink_tele_data_t, DO_status) }, \
         { "airlineTrack_dL", NULL, MAVLINK_TYPE_INT16_T, 0, 156, offsetof(mavlink_tele_data_t, airlineTrack_dL) }, \
         { "airlineTrack_dY", NULL, MAVLINK_TYPE_INT16_T, 0, 158, offsetof(mavlink_tele_data_t, airlineTrack_dY) }, \
         { "airlineTrack_dH", NULL, MAVLINK_TYPE_INT16_T, 0, 160, offsetof(mavlink_tele_data_t, airlineTrack_dH) }, \
         { "severity", NULL, MAVLINK_TYPE_UINT8_T, 0, 193, offsetof(mavlink_tele_data_t, severity) }, \
         { "text", NULL, MAVLINK_TYPE_CHAR, 30, 194, offsetof(mavlink_tele_data_t, text) }, \
         } \
}
#endif

/**
 * @brief Pack a tele_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param vehicle_id  vehicle id
 * @param link_quality  communication quality
 * @param err_rate  bit err rate
 * @param flight_time_sec  flight time,unit sec
 * @param endurance_time_min  endurance time,unit min
 * @param endurance_distance_km  endurance distance,unit km
 * @param distance2Home  distance to home position,unit m
 * @param year  GPS time,year-2020
 * @param month  GPS time,month
 * @param day  GPS time,day
 * @param hour  GPS time,hour
 * @param min  GPS time,min
 * @param sec  GPS time,sec
 * @param homePos_lat  home position,lat
 * @param homePos_lon  home position,lon
 * @param homePos_alt  home position,alt
 * @param armed  arm status
 * @param flight_mode  flight mode
 * @param fix_mode  GPS fix mode
 * @param satelliteUse  satellite use number
 * @param posSrc  position sensor source
 * @param altSrc  altitude sensor source
 * @param airSpdSrc  airSpeed sensor source
 * @param grdSpdSrc  ground speed sensor source
 * @param attSrc  attitude sensor source
 * @param yawSrc  yaw sensor source
 * @param pitch  fly status: pitch
 * @param roll  fly status: roll
 * @param Vi  fly status: Vi
 * @param Vg  fly status: Vg
 * @param hdot  fly status: hdot
 * @param yaw  fly status: yaw
 * @param psiV  fly status: psiV
 * @param lon  fly status: lon
 * @param lat  fly status: lat
 * @param alt  fly status: alt
 * @param alt_relative  fly status: alt_relative
 * @param cmd_alt  fly command: alt
 * @param cmd_Vi  fly command: Vi
 * @param cmd_theta  fly command: tehta
 * @param cmd_phi  fly command: phi
 * @param cmd_psi  fly command: psi
 * @param cmd_hdot  fly command: hdot
 * @param lawOuput_ele  law output: ele
 * @param lawOuput_ail  law output: ail
 * @param lawOuput_rud  law output: rud
 * @param lawOuput_thr  law output: thr
 * @param SCNS_fault_flag  sbg: star use
 * @param SCNS_mode  sbg: solution status
 * @param SCNS_fix_status  sbg: fix status
 * @param SCNS_PDOP  sbg: solution status
 * @param SCNS_velocity_N  sbg: position accurancy of lat
 * @param SCNS_velocity_E  sbg: position accurancy of lon
 * @param SCNS_velocity_U  sbg: position accurancy of alt
 * @param SCNS_picth  sbg: pitch
 * @param SCNS_roll  sbg: roll
 * @param SCNS_yaw  sbg: yaw
 * @param SCNS_rollRate  sbg: roll rate
 * @param SCNS_pitchRate  sbg: pitch rate
 * @param SCNS_yawRate  sbg: yaw rate
 * @param SCNS_xAcc  sbg: barometer alt
 * @param SCNS_lon  sbg: gps position lon
 * @param SCNS_lat  sbg: gps position lat
 * @param SCNS_alt  sbg: gps position alt
 * @param SCNS_Vg_2D  sbg: Vg 2D
 * @param intSensor_fixStatus  inter sensor: fix status
 * @param intSensor_starUse  inter sensor: star use
 * @param intSensor_Eph  inter sensor: eph
 * @param intSensor_Epv  inter sensor: epv
 * @param intSensor_lon_gps  inter sensor: gps position lon
 * @param intSensor_lat_gps  inter sensor: gps position lat
 * @param intSensor_alt_gps  inter sensor: gps position alt
 * @param intSensor_Vg_2D  inter sensor: Vg 2D
 * @param intSensor_roll  inter sensor: roll
 * @param intSensor_pitch  inter sensor: pitch
 * @param intSensor_yaw  inter sensor: yaw
 * @param intSensor_psiV  inter sensor: psiV
 * @param intSensor_rollRate  inter sensor: roll rate
 * @param intSensor_pitchRate  inter sensor: pitch rate
 * @param intSensor_yawRate  inter sensor: yaw rate
 * @param intSensor_alt_baro  inter sensor: barometer alt
 * @param intSensor_Vi  inter sensor: airspeed
 * @param pwmOut_ail_L  pwm output: ail left
 * @param pwmOut_ail_R  pwm output: ail right
 * @param pwmOut_ele_L  pwm output: ele left
 * @param pwmOut_ele_R  pwm output: ele right
 * @param pwmOut_rud_L  pwm output: rud left
 * @param pwmOut_rud_R  pwm output: rud right
 * @param pwmOut_thr  pwm output:  thr
 * @param pwmFb_ail_L  pwm feedback: ail left
 * @param pwmFb_ail_R  pwm feedback: ail right
 * @param pwmFb_ele_L  pwm feedback: ele left
 * @param pwmFb_ele_R  pwm feedback: ele right
 * @param pwmFb_rud_L  pwm feedback: rud left
 * @param pwmFb_rud_R  pwm feedback: rud right
 * @param pwmFb_thr  pwm feedback: thr
 * @param voltage_power  voltage of power
 * @param voltage_equip  voltage of equipment
 * @param voltage_actuator  voltage of actuator
 * @param DI_status  DI status
 * @param DO_status  DO status
 * @param airlineTrack_dL  airlineTrack: dL
 * @param airlineTrack_dY  airlineTrack: dY
 * @param airlineTrack_dH  airlineTrack: dH
 * @param severity  Severity of status. Relies on the definitions within RFC-5424. See enum MAV_SEVERITY.
 * @param text  Status text message, without null termination character
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tele_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t vehicle_id, uint8_t link_quality, uint8_t err_rate, uint16_t flight_time_sec, uint8_t endurance_time_min, uint8_t endurance_distance_km, uint16_t distance2Home, uint8_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t min, uint8_t sec, int32_t homePos_lat, int32_t homePos_lon, uint16_t homePos_alt, uint8_t armed, uint8_t flight_mode, uint8_t fix_mode, uint8_t satelliteUse, uint8_t posSrc, uint8_t altSrc, uint8_t airSpdSrc, uint8_t grdSpdSrc, uint8_t attSrc, uint8_t yawSrc, int16_t pitch, int16_t roll, uint16_t Vi, uint16_t Vg, int16_t hdot, uint16_t yaw, int16_t psiV, int32_t lon, int32_t lat, uint16_t alt, uint16_t alt_relative, uint16_t cmd_alt, uint16_t cmd_Vi, int16_t cmd_theta, int16_t cmd_phi, int16_t cmd_psi, int16_t cmd_hdot, int16_t lawOuput_ele, int16_t lawOuput_ail, int16_t lawOuput_rud, uint8_t lawOuput_thr, uint8_t SCNS_fault_flag, uint8_t SCNS_mode, uint8_t SCNS_fix_status, uint8_t SCNS_PDOP, int16_t SCNS_velocity_N, int16_t SCNS_velocity_E, int16_t SCNS_velocity_U, int16_t SCNS_picth, int16_t SCNS_roll, uint16_t SCNS_yaw, int16_t SCNS_rollRate, int16_t SCNS_pitchRate, int16_t SCNS_yawRate, int16_t SCNS_xAcc, int32_t SCNS_lon, int32_t SCNS_lat, uint16_t SCNS_alt, int16_t SCNS_Vg_2D, uint8_t intSensor_fixStatus, uint8_t intSensor_starUse, uint16_t intSensor_Eph, uint16_t intSensor_Epv, int32_t intSensor_lon_gps, int32_t intSensor_lat_gps, uint16_t intSensor_alt_gps, uint16_t intSensor_Vg_2D, int16_t intSensor_roll, int16_t intSensor_pitch, uint16_t intSensor_yaw, int16_t intSensor_psiV, int16_t intSensor_rollRate, int16_t intSensor_pitchRate, int16_t intSensor_yawRate, uint16_t intSensor_alt_baro, int16_t intSensor_Vi, uint16_t pwmOut_ail_L, uint16_t pwmOut_ail_R, uint16_t pwmOut_ele_L, uint16_t pwmOut_ele_R, uint16_t pwmOut_rud_L, uint16_t pwmOut_rud_R, uint16_t pwmOut_thr, uint16_t pwmFb_ail_L, uint16_t pwmFb_ail_R, uint16_t pwmFb_ele_L, uint16_t pwmFb_ele_R, uint16_t pwmFb_rud_L, uint16_t pwmFb_rud_R, uint16_t pwmFb_thr, uint16_t voltage_power, uint8_t voltage_equip, uint8_t voltage_actuator, uint8_t DI_status, uint16_t DO_status, int16_t airlineTrack_dL, int16_t airlineTrack_dY, int16_t airlineTrack_dH, uint8_t severity, const char *text)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TELE_DATA_LEN];
    _mav_put_int32_t(buf, 0, homePos_lat);
    _mav_put_int32_t(buf, 4, homePos_lon);
    _mav_put_int32_t(buf, 8, lon);
    _mav_put_int32_t(buf, 12, lat);
    _mav_put_int32_t(buf, 16, SCNS_lon);
    _mav_put_int32_t(buf, 20, SCNS_lat);
    _mav_put_int32_t(buf, 24, intSensor_lon_gps);
    _mav_put_int32_t(buf, 28, intSensor_lat_gps);
    _mav_put_uint16_t(buf, 32, flight_time_sec);
    _mav_put_uint16_t(buf, 34, distance2Home);
    _mav_put_uint16_t(buf, 36, homePos_alt);
    _mav_put_int16_t(buf, 38, pitch);
    _mav_put_int16_t(buf, 40, roll);
    _mav_put_uint16_t(buf, 42, Vi);
    _mav_put_uint16_t(buf, 44, Vg);
    _mav_put_int16_t(buf, 46, hdot);
    _mav_put_uint16_t(buf, 48, yaw);
    _mav_put_int16_t(buf, 50, psiV);
    _mav_put_uint16_t(buf, 52, alt);
    _mav_put_uint16_t(buf, 54, alt_relative);
    _mav_put_uint16_t(buf, 56, cmd_alt);
    _mav_put_uint16_t(buf, 58, cmd_Vi);
    _mav_put_int16_t(buf, 60, cmd_theta);
    _mav_put_int16_t(buf, 62, cmd_phi);
    _mav_put_int16_t(buf, 64, cmd_psi);
    _mav_put_int16_t(buf, 66, cmd_hdot);
    _mav_put_int16_t(buf, 68, lawOuput_ele);
    _mav_put_int16_t(buf, 70, lawOuput_ail);
    _mav_put_int16_t(buf, 72, lawOuput_rud);
    _mav_put_int16_t(buf, 74, SCNS_velocity_N);
    _mav_put_int16_t(buf, 76, SCNS_velocity_E);
    _mav_put_int16_t(buf, 78, SCNS_velocity_U);
    _mav_put_int16_t(buf, 80, SCNS_picth);
    _mav_put_int16_t(buf, 82, SCNS_roll);
    _mav_put_uint16_t(buf, 84, SCNS_yaw);
    _mav_put_int16_t(buf, 86, SCNS_rollRate);
    _mav_put_int16_t(buf, 88, SCNS_pitchRate);
    _mav_put_int16_t(buf, 90, SCNS_yawRate);
    _mav_put_int16_t(buf, 92, SCNS_xAcc);
    _mav_put_uint16_t(buf, 94, SCNS_alt);
    _mav_put_int16_t(buf, 96, SCNS_Vg_2D);
    _mav_put_uint16_t(buf, 98, intSensor_Eph);
    _mav_put_uint16_t(buf, 100, intSensor_Epv);
    _mav_put_uint16_t(buf, 102, intSensor_alt_gps);
    _mav_put_uint16_t(buf, 104, intSensor_Vg_2D);
    _mav_put_int16_t(buf, 106, intSensor_roll);
    _mav_put_int16_t(buf, 108, intSensor_pitch);
    _mav_put_uint16_t(buf, 110, intSensor_yaw);
    _mav_put_int16_t(buf, 112, intSensor_psiV);
    _mav_put_int16_t(buf, 114, intSensor_rollRate);
    _mav_put_int16_t(buf, 116, intSensor_pitchRate);
    _mav_put_int16_t(buf, 118, intSensor_yawRate);
    _mav_put_uint16_t(buf, 120, intSensor_alt_baro);
    _mav_put_int16_t(buf, 122, intSensor_Vi);
    _mav_put_uint16_t(buf, 124, pwmOut_ail_L);
    _mav_put_uint16_t(buf, 126, pwmOut_ail_R);
    _mav_put_uint16_t(buf, 128, pwmOut_ele_L);
    _mav_put_uint16_t(buf, 130, pwmOut_ele_R);
    _mav_put_uint16_t(buf, 132, pwmOut_rud_L);
    _mav_put_uint16_t(buf, 134, pwmOut_rud_R);
    _mav_put_uint16_t(buf, 136, pwmOut_thr);
    _mav_put_uint16_t(buf, 138, pwmFb_ail_L);
    _mav_put_uint16_t(buf, 140, pwmFb_ail_R);
    _mav_put_uint16_t(buf, 142, pwmFb_ele_L);
    _mav_put_uint16_t(buf, 144, pwmFb_ele_R);
    _mav_put_uint16_t(buf, 146, pwmFb_rud_L);
    _mav_put_uint16_t(buf, 148, pwmFb_rud_R);
    _mav_put_uint16_t(buf, 150, pwmFb_thr);
    _mav_put_uint16_t(buf, 152, voltage_power);
    _mav_put_uint16_t(buf, 154, DO_status);
    _mav_put_int16_t(buf, 156, airlineTrack_dL);
    _mav_put_int16_t(buf, 158, airlineTrack_dY);
    _mav_put_int16_t(buf, 160, airlineTrack_dH);
    _mav_put_uint8_t(buf, 162, vehicle_id);
    _mav_put_uint8_t(buf, 163, link_quality);
    _mav_put_uint8_t(buf, 164, err_rate);
    _mav_put_uint8_t(buf, 165, endurance_time_min);
    _mav_put_uint8_t(buf, 166, endurance_distance_km);
    _mav_put_uint8_t(buf, 167, year);
    _mav_put_uint8_t(buf, 168, month);
    _mav_put_uint8_t(buf, 169, day);
    _mav_put_uint8_t(buf, 170, hour);
    _mav_put_uint8_t(buf, 171, min);
    _mav_put_uint8_t(buf, 172, sec);
    _mav_put_uint8_t(buf, 173, armed);
    _mav_put_uint8_t(buf, 174, flight_mode);
    _mav_put_uint8_t(buf, 175, fix_mode);
    _mav_put_uint8_t(buf, 176, satelliteUse);
    _mav_put_uint8_t(buf, 177, posSrc);
    _mav_put_uint8_t(buf, 178, altSrc);
    _mav_put_uint8_t(buf, 179, airSpdSrc);
    _mav_put_uint8_t(buf, 180, grdSpdSrc);
    _mav_put_uint8_t(buf, 181, attSrc);
    _mav_put_uint8_t(buf, 182, yawSrc);
    _mav_put_uint8_t(buf, 183, lawOuput_thr);
    _mav_put_uint8_t(buf, 184, SCNS_fault_flag);
    _mav_put_uint8_t(buf, 185, SCNS_mode);
    _mav_put_uint8_t(buf, 186, SCNS_fix_status);
    _mav_put_uint8_t(buf, 187, SCNS_PDOP);
    _mav_put_uint8_t(buf, 188, intSensor_fixStatus);
    _mav_put_uint8_t(buf, 189, intSensor_starUse);
    _mav_put_uint8_t(buf, 190, voltage_equip);
    _mav_put_uint8_t(buf, 191, voltage_actuator);
    _mav_put_uint8_t(buf, 192, DI_status);
    _mav_put_uint8_t(buf, 193, severity);
    _mav_put_char_array(buf, 194, text, 30);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TELE_DATA_LEN);
#else
    mavlink_tele_data_t packet;
    packet.homePos_lat = homePos_lat;
    packet.homePos_lon = homePos_lon;
    packet.lon = lon;
    packet.lat = lat;
    packet.SCNS_lon = SCNS_lon;
    packet.SCNS_lat = SCNS_lat;
    packet.intSensor_lon_gps = intSensor_lon_gps;
    packet.intSensor_lat_gps = intSensor_lat_gps;
    packet.flight_time_sec = flight_time_sec;
    packet.distance2Home = distance2Home;
    packet.homePos_alt = homePos_alt;
    packet.pitch = pitch;
    packet.roll = roll;
    packet.Vi = Vi;
    packet.Vg = Vg;
    packet.hdot = hdot;
    packet.yaw = yaw;
    packet.psiV = psiV;
    packet.alt = alt;
    packet.alt_relative = alt_relative;
    packet.cmd_alt = cmd_alt;
    packet.cmd_Vi = cmd_Vi;
    packet.cmd_theta = cmd_theta;
    packet.cmd_phi = cmd_phi;
    packet.cmd_psi = cmd_psi;
    packet.cmd_hdot = cmd_hdot;
    packet.lawOuput_ele = lawOuput_ele;
    packet.lawOuput_ail = lawOuput_ail;
    packet.lawOuput_rud = lawOuput_rud;
    packet.SCNS_velocity_N = SCNS_velocity_N;
    packet.SCNS_velocity_E = SCNS_velocity_E;
    packet.SCNS_velocity_U = SCNS_velocity_U;
    packet.SCNS_picth = SCNS_picth;
    packet.SCNS_roll = SCNS_roll;
    packet.SCNS_yaw = SCNS_yaw;
    packet.SCNS_rollRate = SCNS_rollRate;
    packet.SCNS_pitchRate = SCNS_pitchRate;
    packet.SCNS_yawRate = SCNS_yawRate;
    packet.SCNS_xAcc = SCNS_xAcc;
    packet.SCNS_alt = SCNS_alt;
    packet.SCNS_Vg_2D = SCNS_Vg_2D;
    packet.intSensor_Eph = intSensor_Eph;
    packet.intSensor_Epv = intSensor_Epv;
    packet.intSensor_alt_gps = intSensor_alt_gps;
    packet.intSensor_Vg_2D = intSensor_Vg_2D;
    packet.intSensor_roll = intSensor_roll;
    packet.intSensor_pitch = intSensor_pitch;
    packet.intSensor_yaw = intSensor_yaw;
    packet.intSensor_psiV = intSensor_psiV;
    packet.intSensor_rollRate = intSensor_rollRate;
    packet.intSensor_pitchRate = intSensor_pitchRate;
    packet.intSensor_yawRate = intSensor_yawRate;
    packet.intSensor_alt_baro = intSensor_alt_baro;
    packet.intSensor_Vi = intSensor_Vi;
    packet.pwmOut_ail_L = pwmOut_ail_L;
    packet.pwmOut_ail_R = pwmOut_ail_R;
    packet.pwmOut_ele_L = pwmOut_ele_L;
    packet.pwmOut_ele_R = pwmOut_ele_R;
    packet.pwmOut_rud_L = pwmOut_rud_L;
    packet.pwmOut_rud_R = pwmOut_rud_R;
    packet.pwmOut_thr = pwmOut_thr;
    packet.pwmFb_ail_L = pwmFb_ail_L;
    packet.pwmFb_ail_R = pwmFb_ail_R;
    packet.pwmFb_ele_L = pwmFb_ele_L;
    packet.pwmFb_ele_R = pwmFb_ele_R;
    packet.pwmFb_rud_L = pwmFb_rud_L;
    packet.pwmFb_rud_R = pwmFb_rud_R;
    packet.pwmFb_thr = pwmFb_thr;
    packet.voltage_power = voltage_power;
    packet.DO_status = DO_status;
    packet.airlineTrack_dL = airlineTrack_dL;
    packet.airlineTrack_dY = airlineTrack_dY;
    packet.airlineTrack_dH = airlineTrack_dH;
    packet.vehicle_id = vehicle_id;
    packet.link_quality = link_quality;
    packet.err_rate = err_rate;
    packet.endurance_time_min = endurance_time_min;
    packet.endurance_distance_km = endurance_distance_km;
    packet.year = year;
    packet.month = month;
    packet.day = day;
    packet.hour = hour;
    packet.min = min;
    packet.sec = sec;
    packet.armed = armed;
    packet.flight_mode = flight_mode;
    packet.fix_mode = fix_mode;
    packet.satelliteUse = satelliteUse;
    packet.posSrc = posSrc;
    packet.altSrc = altSrc;
    packet.airSpdSrc = airSpdSrc;
    packet.grdSpdSrc = grdSpdSrc;
    packet.attSrc = attSrc;
    packet.yawSrc = yawSrc;
    packet.lawOuput_thr = lawOuput_thr;
    packet.SCNS_fault_flag = SCNS_fault_flag;
    packet.SCNS_mode = SCNS_mode;
    packet.SCNS_fix_status = SCNS_fix_status;
    packet.SCNS_PDOP = SCNS_PDOP;
    packet.intSensor_fixStatus = intSensor_fixStatus;
    packet.intSensor_starUse = intSensor_starUse;
    packet.voltage_equip = voltage_equip;
    packet.voltage_actuator = voltage_actuator;
    packet.DI_status = DI_status;
    packet.severity = severity;
    mav_array_memcpy(packet.text, text, sizeof(char)*30);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TELE_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TELE_DATA;
#if MAVLINK_CRC_EXTRA
		return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TELE_DATA_LEN, MAVLINK_MSG_ID_TELE_DATA_CRC);
#else
		return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TELE_DATA_LEN);
#endif
}

/**
 * @brief Pack a tele_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param vehicle_id  vehicle id
 * @param link_quality  communication quality
 * @param err_rate  bit err rate
 * @param flight_time_sec  flight time,unit sec
 * @param endurance_time_min  endurance time,unit min
 * @param endurance_distance_km  endurance distance,unit km
 * @param distance2Home  distance to home position,unit m
 * @param year  GPS time,year-2020
 * @param month  GPS time,month
 * @param day  GPS time,day
 * @param hour  GPS time,hour
 * @param min  GPS time,min
 * @param sec  GPS time,sec
 * @param homePos_lat  home position,lat
 * @param homePos_lon  home position,lon
 * @param homePos_alt  home position,alt
 * @param armed  arm status
 * @param flight_mode  flight mode
 * @param fix_mode  GPS fix mode
 * @param satelliteUse  satellite use number
 * @param posSrc  position sensor source
 * @param altSrc  altitude sensor source
 * @param airSpdSrc  airSpeed sensor source
 * @param grdSpdSrc  ground speed sensor source
 * @param attSrc  attitude sensor source
 * @param yawSrc  yaw sensor source
 * @param pitch  fly status: pitch
 * @param roll  fly status: roll
 * @param Vi  fly status: Vi
 * @param Vg  fly status: Vg
 * @param hdot  fly status: hdot
 * @param yaw  fly status: yaw
 * @param psiV  fly status: psiV
 * @param lon  fly status: lon
 * @param lat  fly status: lat
 * @param alt  fly status: alt
 * @param alt_relative  fly status: alt_relative
 * @param cmd_alt  fly command: alt
 * @param cmd_Vi  fly command: Vi
 * @param cmd_theta  fly command: tehta
 * @param cmd_phi  fly command: phi
 * @param cmd_psi  fly command: psi
 * @param cmd_hdot  fly command: hdot
 * @param lawOuput_ele  law output: ele
 * @param lawOuput_ail  law output: ail
 * @param lawOuput_rud  law output: rud
 * @param lawOuput_thr  law output: thr
 * @param SCNS_fault_flag  sbg: star use
 * @param SCNS_mode  sbg: solution status
 * @param SCNS_fix_status  sbg: fix status
 * @param SCNS_PDOP  sbg: solution status
 * @param SCNS_velocity_N  sbg: position accurancy of lat
 * @param SCNS_velocity_E  sbg: position accurancy of lon
 * @param SCNS_velocity_U  sbg: position accurancy of alt
 * @param SCNS_picth  sbg: pitch
 * @param SCNS_roll  sbg: roll
 * @param SCNS_yaw  sbg: yaw
 * @param SCNS_rollRate  sbg: roll rate
 * @param SCNS_pitchRate  sbg: pitch rate
 * @param SCNS_yawRate  sbg: yaw rate
 * @param SCNS_xAcc  sbg: barometer alt
 * @param SCNS_lon  sbg: gps position lon
 * @param SCNS_lat  sbg: gps position lat
 * @param SCNS_alt  sbg: gps position alt
 * @param SCNS_Vg_2D  sbg: Vg 2D
 * @param intSensor_fixStatus  inter sensor: fix status
 * @param intSensor_starUse  inter sensor: star use
 * @param intSensor_Eph  inter sensor: eph
 * @param intSensor_Epv  inter sensor: epv
 * @param intSensor_lon_gps  inter sensor: gps position lon
 * @param intSensor_lat_gps  inter sensor: gps position lat
 * @param intSensor_alt_gps  inter sensor: gps position alt
 * @param intSensor_Vg_2D  inter sensor: Vg 2D
 * @param intSensor_roll  inter sensor: roll
 * @param intSensor_pitch  inter sensor: pitch
 * @param intSensor_yaw  inter sensor: yaw
 * @param intSensor_psiV  inter sensor: psiV
 * @param intSensor_rollRate  inter sensor: roll rate
 * @param intSensor_pitchRate  inter sensor: pitch rate
 * @param intSensor_yawRate  inter sensor: yaw rate
 * @param intSensor_alt_baro  inter sensor: barometer alt
 * @param intSensor_Vi  inter sensor: airspeed
 * @param pwmOut_ail_L  pwm output: ail left
 * @param pwmOut_ail_R  pwm output: ail right
 * @param pwmOut_ele_L  pwm output: ele left
 * @param pwmOut_ele_R  pwm output: ele right
 * @param pwmOut_rud_L  pwm output: rud left
 * @param pwmOut_rud_R  pwm output: rud right
 * @param pwmOut_thr  pwm output:  thr
 * @param pwmFb_ail_L  pwm feedback: ail left
 * @param pwmFb_ail_R  pwm feedback: ail right
 * @param pwmFb_ele_L  pwm feedback: ele left
 * @param pwmFb_ele_R  pwm feedback: ele right
 * @param pwmFb_rud_L  pwm feedback: rud left
 * @param pwmFb_rud_R  pwm feedback: rud right
 * @param pwmFb_thr  pwm feedback: thr
 * @param voltage_power  voltage of power
 * @param voltage_equip  voltage of equipment
 * @param voltage_actuator  voltage of actuator
 * @param DI_status  DI status
 * @param DO_status  DO status
 * @param airlineTrack_dL  airlineTrack: dL
 * @param airlineTrack_dY  airlineTrack: dY
 * @param airlineTrack_dH  airlineTrack: dH
 * @param severity  Severity of status. Relies on the definitions within RFC-5424. See enum MAV_SEVERITY.
 * @param text  Status text message, without null termination character
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tele_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t vehicle_id,uint8_t link_quality,uint8_t err_rate,uint16_t flight_time_sec,uint8_t endurance_time_min,uint8_t endurance_distance_km,uint16_t distance2Home,uint8_t year,uint8_t month,uint8_t day,uint8_t hour,uint8_t min,uint8_t sec,int32_t homePos_lat,int32_t homePos_lon,uint16_t homePos_alt,uint8_t armed,uint8_t flight_mode,uint8_t fix_mode,uint8_t satelliteUse,uint8_t posSrc,uint8_t altSrc,uint8_t airSpdSrc,uint8_t grdSpdSrc,uint8_t attSrc,uint8_t yawSrc,int16_t pitch,int16_t roll,uint16_t Vi,uint16_t Vg,int16_t hdot,uint16_t yaw,int16_t psiV,int32_t lon,int32_t lat,uint16_t alt,uint16_t alt_relative,uint16_t cmd_alt,uint16_t cmd_Vi,int16_t cmd_theta,int16_t cmd_phi,int16_t cmd_psi,int16_t cmd_hdot,int16_t lawOuput_ele,int16_t lawOuput_ail,int16_t lawOuput_rud,uint8_t lawOuput_thr,uint8_t SCNS_fault_flag,uint8_t SCNS_mode,uint8_t SCNS_fix_status,uint8_t SCNS_PDOP,int16_t SCNS_velocity_N,int16_t SCNS_velocity_E,int16_t SCNS_velocity_U,int16_t SCNS_picth,int16_t SCNS_roll,uint16_t SCNS_yaw,int16_t SCNS_rollRate,int16_t SCNS_pitchRate,int16_t SCNS_yawRate,int16_t SCNS_xAcc,int32_t SCNS_lon,int32_t SCNS_lat,uint16_t SCNS_alt,int16_t SCNS_Vg_2D,uint8_t intSensor_fixStatus,uint8_t intSensor_starUse,uint16_t intSensor_Eph,uint16_t intSensor_Epv,int32_t intSensor_lon_gps,int32_t intSensor_lat_gps,uint16_t intSensor_alt_gps,uint16_t intSensor_Vg_2D,int16_t intSensor_roll,int16_t intSensor_pitch,uint16_t intSensor_yaw,int16_t intSensor_psiV,int16_t intSensor_rollRate,int16_t intSensor_pitchRate,int16_t intSensor_yawRate,uint16_t intSensor_alt_baro,int16_t intSensor_Vi,uint16_t pwmOut_ail_L,uint16_t pwmOut_ail_R,uint16_t pwmOut_ele_L,uint16_t pwmOut_ele_R,uint16_t pwmOut_rud_L,uint16_t pwmOut_rud_R,uint16_t pwmOut_thr,uint16_t pwmFb_ail_L,uint16_t pwmFb_ail_R,uint16_t pwmFb_ele_L,uint16_t pwmFb_ele_R,uint16_t pwmFb_rud_L,uint16_t pwmFb_rud_R,uint16_t pwmFb_thr,uint16_t voltage_power,uint8_t voltage_equip,uint8_t voltage_actuator,uint8_t DI_status,uint16_t DO_status,int16_t airlineTrack_dL,int16_t airlineTrack_dY,int16_t airlineTrack_dH,uint8_t severity,const char *text)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TELE_DATA_LEN];
    _mav_put_int32_t(buf, 0, homePos_lat);
    _mav_put_int32_t(buf, 4, homePos_lon);
    _mav_put_int32_t(buf, 8, lon);
    _mav_put_int32_t(buf, 12, lat);
    _mav_put_int32_t(buf, 16, SCNS_lon);
    _mav_put_int32_t(buf, 20, SCNS_lat);
    _mav_put_int32_t(buf, 24, intSensor_lon_gps);
    _mav_put_int32_t(buf, 28, intSensor_lat_gps);
    _mav_put_uint16_t(buf, 32, flight_time_sec);
    _mav_put_uint16_t(buf, 34, distance2Home);
    _mav_put_uint16_t(buf, 36, homePos_alt);
    _mav_put_int16_t(buf, 38, pitch);
    _mav_put_int16_t(buf, 40, roll);
    _mav_put_uint16_t(buf, 42, Vi);
    _mav_put_uint16_t(buf, 44, Vg);
    _mav_put_int16_t(buf, 46, hdot);
    _mav_put_uint16_t(buf, 48, yaw);
    _mav_put_int16_t(buf, 50, psiV);
    _mav_put_uint16_t(buf, 52, alt);
    _mav_put_uint16_t(buf, 54, alt_relative);
    _mav_put_uint16_t(buf, 56, cmd_alt);
    _mav_put_uint16_t(buf, 58, cmd_Vi);
    _mav_put_int16_t(buf, 60, cmd_theta);
    _mav_put_int16_t(buf, 62, cmd_phi);
    _mav_put_int16_t(buf, 64, cmd_psi);
    _mav_put_int16_t(buf, 66, cmd_hdot);
    _mav_put_int16_t(buf, 68, lawOuput_ele);
    _mav_put_int16_t(buf, 70, lawOuput_ail);
    _mav_put_int16_t(buf, 72, lawOuput_rud);
    _mav_put_int16_t(buf, 74, SCNS_velocity_N);
    _mav_put_int16_t(buf, 76, SCNS_velocity_E);
    _mav_put_int16_t(buf, 78, SCNS_velocity_U);
    _mav_put_int16_t(buf, 80, SCNS_picth);
    _mav_put_int16_t(buf, 82, SCNS_roll);
    _mav_put_uint16_t(buf, 84, SCNS_yaw);
    _mav_put_int16_t(buf, 86, SCNS_rollRate);
    _mav_put_int16_t(buf, 88, SCNS_pitchRate);
    _mav_put_int16_t(buf, 90, SCNS_yawRate);
    _mav_put_int16_t(buf, 92, SCNS_xAcc);
    _mav_put_uint16_t(buf, 94, SCNS_alt);
    _mav_put_int16_t(buf, 96, SCNS_Vg_2D);
    _mav_put_uint16_t(buf, 98, intSensor_Eph);
    _mav_put_uint16_t(buf, 100, intSensor_Epv);
    _mav_put_uint16_t(buf, 102, intSensor_alt_gps);
    _mav_put_uint16_t(buf, 104, intSensor_Vg_2D);
    _mav_put_int16_t(buf, 106, intSensor_roll);
    _mav_put_int16_t(buf, 108, intSensor_pitch);
    _mav_put_uint16_t(buf, 110, intSensor_yaw);
    _mav_put_int16_t(buf, 112, intSensor_psiV);
    _mav_put_int16_t(buf, 114, intSensor_rollRate);
    _mav_put_int16_t(buf, 116, intSensor_pitchRate);
    _mav_put_int16_t(buf, 118, intSensor_yawRate);
    _mav_put_uint16_t(buf, 120, intSensor_alt_baro);
    _mav_put_int16_t(buf, 122, intSensor_Vi);
    _mav_put_uint16_t(buf, 124, pwmOut_ail_L);
    _mav_put_uint16_t(buf, 126, pwmOut_ail_R);
    _mav_put_uint16_t(buf, 128, pwmOut_ele_L);
    _mav_put_uint16_t(buf, 130, pwmOut_ele_R);
    _mav_put_uint16_t(buf, 132, pwmOut_rud_L);
    _mav_put_uint16_t(buf, 134, pwmOut_rud_R);
    _mav_put_uint16_t(buf, 136, pwmOut_thr);
    _mav_put_uint16_t(buf, 138, pwmFb_ail_L);
    _mav_put_uint16_t(buf, 140, pwmFb_ail_R);
    _mav_put_uint16_t(buf, 142, pwmFb_ele_L);
    _mav_put_uint16_t(buf, 144, pwmFb_ele_R);
    _mav_put_uint16_t(buf, 146, pwmFb_rud_L);
    _mav_put_uint16_t(buf, 148, pwmFb_rud_R);
    _mav_put_uint16_t(buf, 150, pwmFb_thr);
    _mav_put_uint16_t(buf, 152, voltage_power);
    _mav_put_uint16_t(buf, 154, DO_status);
    _mav_put_int16_t(buf, 156, airlineTrack_dL);
    _mav_put_int16_t(buf, 158, airlineTrack_dY);
    _mav_put_int16_t(buf, 160, airlineTrack_dH);
    _mav_put_uint8_t(buf, 162, vehicle_id);
    _mav_put_uint8_t(buf, 163, link_quality);
    _mav_put_uint8_t(buf, 164, err_rate);
    _mav_put_uint8_t(buf, 165, endurance_time_min);
    _mav_put_uint8_t(buf, 166, endurance_distance_km);
    _mav_put_uint8_t(buf, 167, year);
    _mav_put_uint8_t(buf, 168, month);
    _mav_put_uint8_t(buf, 169, day);
    _mav_put_uint8_t(buf, 170, hour);
    _mav_put_uint8_t(buf, 171, min);
    _mav_put_uint8_t(buf, 172, sec);
    _mav_put_uint8_t(buf, 173, armed);
    _mav_put_uint8_t(buf, 174, flight_mode);
    _mav_put_uint8_t(buf, 175, fix_mode);
    _mav_put_uint8_t(buf, 176, satelliteUse);
    _mav_put_uint8_t(buf, 177, posSrc);
    _mav_put_uint8_t(buf, 178, altSrc);
    _mav_put_uint8_t(buf, 179, airSpdSrc);
    _mav_put_uint8_t(buf, 180, grdSpdSrc);
    _mav_put_uint8_t(buf, 181, attSrc);
    _mav_put_uint8_t(buf, 182, yawSrc);
    _mav_put_uint8_t(buf, 183, lawOuput_thr);
    _mav_put_uint8_t(buf, 184, SCNS_fault_flag);
    _mav_put_uint8_t(buf, 185, SCNS_mode);
    _mav_put_uint8_t(buf, 186, SCNS_fix_status);
    _mav_put_uint8_t(buf, 187, SCNS_PDOP);
    _mav_put_uint8_t(buf, 188, intSensor_fixStatus);
    _mav_put_uint8_t(buf, 189, intSensor_starUse);
    _mav_put_uint8_t(buf, 190, voltage_equip);
    _mav_put_uint8_t(buf, 191, voltage_actuator);
    _mav_put_uint8_t(buf, 192, DI_status);
    _mav_put_uint8_t(buf, 193, severity);
    _mav_put_char_array(buf, 194, text, 30);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TELE_DATA_LEN);
#else
    mavlink_tele_data_t packet;
    packet.homePos_lat = homePos_lat;
    packet.homePos_lon = homePos_lon;
    packet.lon = lon;
    packet.lat = lat;
    packet.SCNS_lon = SCNS_lon;
    packet.SCNS_lat = SCNS_lat;
    packet.intSensor_lon_gps = intSensor_lon_gps;
    packet.intSensor_lat_gps = intSensor_lat_gps;
    packet.flight_time_sec = flight_time_sec;
    packet.distance2Home = distance2Home;
    packet.homePos_alt = homePos_alt;
    packet.pitch = pitch;
    packet.roll = roll;
    packet.Vi = Vi;
    packet.Vg = Vg;
    packet.hdot = hdot;
    packet.yaw = yaw;
    packet.psiV = psiV;
    packet.alt = alt;
    packet.alt_relative = alt_relative;
    packet.cmd_alt = cmd_alt;
    packet.cmd_Vi = cmd_Vi;
    packet.cmd_theta = cmd_theta;
    packet.cmd_phi = cmd_phi;
    packet.cmd_psi = cmd_psi;
    packet.cmd_hdot = cmd_hdot;
    packet.lawOuput_ele = lawOuput_ele;
    packet.lawOuput_ail = lawOuput_ail;
    packet.lawOuput_rud = lawOuput_rud;
    packet.SCNS_velocity_N = SCNS_velocity_N;
    packet.SCNS_velocity_E = SCNS_velocity_E;
    packet.SCNS_velocity_U = SCNS_velocity_U;
    packet.SCNS_picth = SCNS_picth;
    packet.SCNS_roll = SCNS_roll;
    packet.SCNS_yaw = SCNS_yaw;
    packet.SCNS_rollRate = SCNS_rollRate;
    packet.SCNS_pitchRate = SCNS_pitchRate;
    packet.SCNS_yawRate = SCNS_yawRate;
    packet.SCNS_xAcc = SCNS_xAcc;
    packet.SCNS_alt = SCNS_alt;
    packet.SCNS_Vg_2D = SCNS_Vg_2D;
    packet.intSensor_Eph = intSensor_Eph;
    packet.intSensor_Epv = intSensor_Epv;
    packet.intSensor_alt_gps = intSensor_alt_gps;
    packet.intSensor_Vg_2D = intSensor_Vg_2D;
    packet.intSensor_roll = intSensor_roll;
    packet.intSensor_pitch = intSensor_pitch;
    packet.intSensor_yaw = intSensor_yaw;
    packet.intSensor_psiV = intSensor_psiV;
    packet.intSensor_rollRate = intSensor_rollRate;
    packet.intSensor_pitchRate = intSensor_pitchRate;
    packet.intSensor_yawRate = intSensor_yawRate;
    packet.intSensor_alt_baro = intSensor_alt_baro;
    packet.intSensor_Vi = intSensor_Vi;
    packet.pwmOut_ail_L = pwmOut_ail_L;
    packet.pwmOut_ail_R = pwmOut_ail_R;
    packet.pwmOut_ele_L = pwmOut_ele_L;
    packet.pwmOut_ele_R = pwmOut_ele_R;
    packet.pwmOut_rud_L = pwmOut_rud_L;
    packet.pwmOut_rud_R = pwmOut_rud_R;
    packet.pwmOut_thr = pwmOut_thr;
    packet.pwmFb_ail_L = pwmFb_ail_L;
    packet.pwmFb_ail_R = pwmFb_ail_R;
    packet.pwmFb_ele_L = pwmFb_ele_L;
    packet.pwmFb_ele_R = pwmFb_ele_R;
    packet.pwmFb_rud_L = pwmFb_rud_L;
    packet.pwmFb_rud_R = pwmFb_rud_R;
    packet.pwmFb_thr = pwmFb_thr;
    packet.voltage_power = voltage_power;
    packet.DO_status = DO_status;
    packet.airlineTrack_dL = airlineTrack_dL;
    packet.airlineTrack_dY = airlineTrack_dY;
    packet.airlineTrack_dH = airlineTrack_dH;
    packet.vehicle_id = vehicle_id;
    packet.link_quality = link_quality;
    packet.err_rate = err_rate;
    packet.endurance_time_min = endurance_time_min;
    packet.endurance_distance_km = endurance_distance_km;
    packet.year = year;
    packet.month = month;
    packet.day = day;
    packet.hour = hour;
    packet.min = min;
    packet.sec = sec;
    packet.armed = armed;
    packet.flight_mode = flight_mode;
    packet.fix_mode = fix_mode;
    packet.satelliteUse = satelliteUse;
    packet.posSrc = posSrc;
    packet.altSrc = altSrc;
    packet.airSpdSrc = airSpdSrc;
    packet.grdSpdSrc = grdSpdSrc;
    packet.attSrc = attSrc;
    packet.yawSrc = yawSrc;
    packet.lawOuput_thr = lawOuput_thr;
    packet.SCNS_fault_flag = SCNS_fault_flag;
    packet.SCNS_mode = SCNS_mode;
    packet.SCNS_fix_status = SCNS_fix_status;
    packet.SCNS_PDOP = SCNS_PDOP;
    packet.intSensor_fixStatus = intSensor_fixStatus;
    packet.intSensor_starUse = intSensor_starUse;
    packet.voltage_equip = voltage_equip;
    packet.voltage_actuator = voltage_actuator;
    packet.DI_status = DI_status;
    packet.severity = severity;
    mav_array_memcpy(packet.text, text, sizeof(char)*30);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TELE_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TELE_DATA;
#if MAVLINK_CRC_EXTRA
		return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TELE_DATA_LEN, MAVLINK_MSG_ID_TELE_DATA_CRC);
#else
		return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TELE_DATA_LEN);
#endif 
}

/**
 * @brief Encode a tele_data struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param tele_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tele_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_tele_data_t* tele_data)
{
    return mavlink_msg_tele_data_pack(system_id, component_id, msg, tele_data->vehicle_id, tele_data->link_quality, tele_data->err_rate, tele_data->flight_time_sec, tele_data->endurance_time_min, tele_data->endurance_distance_km, tele_data->distance2Home, tele_data->year, tele_data->month, tele_data->day, tele_data->hour, tele_data->min, tele_data->sec, tele_data->homePos_lat, tele_data->homePos_lon, tele_data->homePos_alt, tele_data->armed, tele_data->flight_mode, tele_data->fix_mode, tele_data->satelliteUse, tele_data->posSrc, tele_data->altSrc, tele_data->airSpdSrc, tele_data->grdSpdSrc, tele_data->attSrc, tele_data->yawSrc, tele_data->pitch, tele_data->roll, tele_data->Vi, tele_data->Vg, tele_data->hdot, tele_data->yaw, tele_data->psiV, tele_data->lon, tele_data->lat, tele_data->alt, tele_data->alt_relative, tele_data->cmd_alt, tele_data->cmd_Vi, tele_data->cmd_theta, tele_data->cmd_phi, tele_data->cmd_psi, tele_data->cmd_hdot, tele_data->lawOuput_ele, tele_data->lawOuput_ail, tele_data->lawOuput_rud, tele_data->lawOuput_thr, tele_data->SCNS_fault_flag, tele_data->SCNS_mode, tele_data->SCNS_fix_status, tele_data->SCNS_PDOP, tele_data->SCNS_velocity_N, tele_data->SCNS_velocity_E, tele_data->SCNS_velocity_U, tele_data->SCNS_picth, tele_data->SCNS_roll, tele_data->SCNS_yaw, tele_data->SCNS_rollRate, tele_data->SCNS_pitchRate, tele_data->SCNS_yawRate, tele_data->SCNS_xAcc, tele_data->SCNS_lon, tele_data->SCNS_lat, tele_data->SCNS_alt, tele_data->SCNS_Vg_2D, tele_data->intSensor_fixStatus, tele_data->intSensor_starUse, tele_data->intSensor_Eph, tele_data->intSensor_Epv, tele_data->intSensor_lon_gps, tele_data->intSensor_lat_gps, tele_data->intSensor_alt_gps, tele_data->intSensor_Vg_2D, tele_data->intSensor_roll, tele_data->intSensor_pitch, tele_data->intSensor_yaw, tele_data->intSensor_psiV, tele_data->intSensor_rollRate, tele_data->intSensor_pitchRate, tele_data->intSensor_yawRate, tele_data->intSensor_alt_baro, tele_data->intSensor_Vi, tele_data->pwmOut_ail_L, tele_data->pwmOut_ail_R, tele_data->pwmOut_ele_L, tele_data->pwmOut_ele_R, tele_data->pwmOut_rud_L, tele_data->pwmOut_rud_R, tele_data->pwmOut_thr, tele_data->pwmFb_ail_L, tele_data->pwmFb_ail_R, tele_data->pwmFb_ele_L, tele_data->pwmFb_ele_R, tele_data->pwmFb_rud_L, tele_data->pwmFb_rud_R, tele_data->pwmFb_thr, tele_data->voltage_power, tele_data->voltage_equip, tele_data->voltage_actuator, tele_data->DI_status, tele_data->DO_status, tele_data->airlineTrack_dL, tele_data->airlineTrack_dY, tele_data->airlineTrack_dH, tele_data->severity, tele_data->text);
}

/**
 * @brief Encode a tele_data struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param tele_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tele_data_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_tele_data_t* tele_data)
{
    return mavlink_msg_tele_data_pack_chan(system_id, component_id, chan, msg, tele_data->vehicle_id, tele_data->link_quality, tele_data->err_rate, tele_data->flight_time_sec, tele_data->endurance_time_min, tele_data->endurance_distance_km, tele_data->distance2Home, tele_data->year, tele_data->month, tele_data->day, tele_data->hour, tele_data->min, tele_data->sec, tele_data->homePos_lat, tele_data->homePos_lon, tele_data->homePos_alt, tele_data->armed, tele_data->flight_mode, tele_data->fix_mode, tele_data->satelliteUse, tele_data->posSrc, tele_data->altSrc, tele_data->airSpdSrc, tele_data->grdSpdSrc, tele_data->attSrc, tele_data->yawSrc, tele_data->pitch, tele_data->roll, tele_data->Vi, tele_data->Vg, tele_data->hdot, tele_data->yaw, tele_data->psiV, tele_data->lon, tele_data->lat, tele_data->alt, tele_data->alt_relative, tele_data->cmd_alt, tele_data->cmd_Vi, tele_data->cmd_theta, tele_data->cmd_phi, tele_data->cmd_psi, tele_data->cmd_hdot, tele_data->lawOuput_ele, tele_data->lawOuput_ail, tele_data->lawOuput_rud, tele_data->lawOuput_thr, tele_data->SCNS_fault_flag, tele_data->SCNS_mode, tele_data->SCNS_fix_status, tele_data->SCNS_PDOP, tele_data->SCNS_velocity_N, tele_data->SCNS_velocity_E, tele_data->SCNS_velocity_U, tele_data->SCNS_picth, tele_data->SCNS_roll, tele_data->SCNS_yaw, tele_data->SCNS_rollRate, tele_data->SCNS_pitchRate, tele_data->SCNS_yawRate, tele_data->SCNS_xAcc, tele_data->SCNS_lon, tele_data->SCNS_lat, tele_data->SCNS_alt, tele_data->SCNS_Vg_2D, tele_data->intSensor_fixStatus, tele_data->intSensor_starUse, tele_data->intSensor_Eph, tele_data->intSensor_Epv, tele_data->intSensor_lon_gps, tele_data->intSensor_lat_gps, tele_data->intSensor_alt_gps, tele_data->intSensor_Vg_2D, tele_data->intSensor_roll, tele_data->intSensor_pitch, tele_data->intSensor_yaw, tele_data->intSensor_psiV, tele_data->intSensor_rollRate, tele_data->intSensor_pitchRate, tele_data->intSensor_yawRate, tele_data->intSensor_alt_baro, tele_data->intSensor_Vi, tele_data->pwmOut_ail_L, tele_data->pwmOut_ail_R, tele_data->pwmOut_ele_L, tele_data->pwmOut_ele_R, tele_data->pwmOut_rud_L, tele_data->pwmOut_rud_R, tele_data->pwmOut_thr, tele_data->pwmFb_ail_L, tele_data->pwmFb_ail_R, tele_data->pwmFb_ele_L, tele_data->pwmFb_ele_R, tele_data->pwmFb_rud_L, tele_data->pwmFb_rud_R, tele_data->pwmFb_thr, tele_data->voltage_power, tele_data->voltage_equip, tele_data->voltage_actuator, tele_data->DI_status, tele_data->DO_status, tele_data->airlineTrack_dL, tele_data->airlineTrack_dY, tele_data->airlineTrack_dH, tele_data->severity, tele_data->text);
}

/**
 * @brief Send a tele_data message
 * @param chan MAVLink channel to send the message
 *
 * @param vehicle_id  vehicle id
 * @param link_quality  communication quality
 * @param err_rate  bit err rate
 * @param flight_time_sec  flight time,unit sec
 * @param endurance_time_min  endurance time,unit min
 * @param endurance_distance_km  endurance distance,unit km
 * @param distance2Home  distance to home position,unit m
 * @param year  GPS time,year-2020
 * @param month  GPS time,month
 * @param day  GPS time,day
 * @param hour  GPS time,hour
 * @param min  GPS time,min
 * @param sec  GPS time,sec
 * @param homePos_lat  home position,lat
 * @param homePos_lon  home position,lon
 * @param homePos_alt  home position,alt
 * @param armed  arm status
 * @param flight_mode  flight mode
 * @param fix_mode  GPS fix mode
 * @param satelliteUse  satellite use number
 * @param posSrc  position sensor source
 * @param altSrc  altitude sensor source
 * @param airSpdSrc  airSpeed sensor source
 * @param grdSpdSrc  ground speed sensor source
 * @param attSrc  attitude sensor source
 * @param yawSrc  yaw sensor source
 * @param pitch  fly status: pitch
 * @param roll  fly status: roll
 * @param Vi  fly status: Vi
 * @param Vg  fly status: Vg
 * @param hdot  fly status: hdot
 * @param yaw  fly status: yaw
 * @param psiV  fly status: psiV
 * @param lon  fly status: lon
 * @param lat  fly status: lat
 * @param alt  fly status: alt
 * @param alt_relative  fly status: alt_relative
 * @param cmd_alt  fly command: alt
 * @param cmd_Vi  fly command: Vi
 * @param cmd_theta  fly command: tehta
 * @param cmd_phi  fly command: phi
 * @param cmd_psi  fly command: psi
 * @param cmd_hdot  fly command: hdot
 * @param lawOuput_ele  law output: ele
 * @param lawOuput_ail  law output: ail
 * @param lawOuput_rud  law output: rud
 * @param lawOuput_thr  law output: thr
 * @param SCNS_fault_flag  sbg: star use
 * @param SCNS_mode  sbg: solution status
 * @param SCNS_fix_status  sbg: fix status
 * @param SCNS_PDOP  sbg: solution status
 * @param SCNS_velocity_N  sbg: position accurancy of lat
 * @param SCNS_velocity_E  sbg: position accurancy of lon
 * @param SCNS_velocity_U  sbg: position accurancy of alt
 * @param SCNS_picth  sbg: pitch
 * @param SCNS_roll  sbg: roll
 * @param SCNS_yaw  sbg: yaw
 * @param SCNS_rollRate  sbg: roll rate
 * @param SCNS_pitchRate  sbg: pitch rate
 * @param SCNS_yawRate  sbg: yaw rate
 * @param SCNS_xAcc  sbg: barometer alt
 * @param SCNS_lon  sbg: gps position lon
 * @param SCNS_lat  sbg: gps position lat
 * @param SCNS_alt  sbg: gps position alt
 * @param SCNS_Vg_2D  sbg: Vg 2D
 * @param intSensor_fixStatus  inter sensor: fix status
 * @param intSensor_starUse  inter sensor: star use
 * @param intSensor_Eph  inter sensor: eph
 * @param intSensor_Epv  inter sensor: epv
 * @param intSensor_lon_gps  inter sensor: gps position lon
 * @param intSensor_lat_gps  inter sensor: gps position lat
 * @param intSensor_alt_gps  inter sensor: gps position alt
 * @param intSensor_Vg_2D  inter sensor: Vg 2D
 * @param intSensor_roll  inter sensor: roll
 * @param intSensor_pitch  inter sensor: pitch
 * @param intSensor_yaw  inter sensor: yaw
 * @param intSensor_psiV  inter sensor: psiV
 * @param intSensor_rollRate  inter sensor: roll rate
 * @param intSensor_pitchRate  inter sensor: pitch rate
 * @param intSensor_yawRate  inter sensor: yaw rate
 * @param intSensor_alt_baro  inter sensor: barometer alt
 * @param intSensor_Vi  inter sensor: airspeed
 * @param pwmOut_ail_L  pwm output: ail left
 * @param pwmOut_ail_R  pwm output: ail right
 * @param pwmOut_ele_L  pwm output: ele left
 * @param pwmOut_ele_R  pwm output: ele right
 * @param pwmOut_rud_L  pwm output: rud left
 * @param pwmOut_rud_R  pwm output: rud right
 * @param pwmOut_thr  pwm output:  thr
 * @param pwmFb_ail_L  pwm feedback: ail left
 * @param pwmFb_ail_R  pwm feedback: ail right
 * @param pwmFb_ele_L  pwm feedback: ele left
 * @param pwmFb_ele_R  pwm feedback: ele right
 * @param pwmFb_rud_L  pwm feedback: rud left
 * @param pwmFb_rud_R  pwm feedback: rud right
 * @param pwmFb_thr  pwm feedback: thr
 * @param voltage_power  voltage of power
 * @param voltage_equip  voltage of equipment
 * @param voltage_actuator  voltage of actuator
 * @param DI_status  DI status
 * @param DO_status  DO status
 * @param airlineTrack_dL  airlineTrack: dL
 * @param airlineTrack_dY  airlineTrack: dY
 * @param airlineTrack_dH  airlineTrack: dH
 * @param severity  Severity of status. Relies on the definitions within RFC-5424. See enum MAV_SEVERITY.
 * @param text  Status text message, without null termination character
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_tele_data_send(mavlink_channel_t chan, uint8_t vehicle_id, uint8_t link_quality, uint8_t err_rate, uint16_t flight_time_sec, uint8_t endurance_time_min, uint8_t endurance_distance_km, uint16_t distance2Home, uint8_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t min, uint8_t sec, int32_t homePos_lat, int32_t homePos_lon, uint16_t homePos_alt, uint8_t armed, uint8_t flight_mode, uint8_t fix_mode, uint8_t satelliteUse, uint8_t posSrc, uint8_t altSrc, uint8_t airSpdSrc, uint8_t grdSpdSrc, uint8_t attSrc, uint8_t yawSrc, int16_t pitch, int16_t roll, uint16_t Vi, uint16_t Vg, int16_t hdot, uint16_t yaw, int16_t psiV, int32_t lon, int32_t lat, uint16_t alt, uint16_t alt_relative, uint16_t cmd_alt, uint16_t cmd_Vi, int16_t cmd_theta, int16_t cmd_phi, int16_t cmd_psi, int16_t cmd_hdot, int16_t lawOuput_ele, int16_t lawOuput_ail, int16_t lawOuput_rud, uint8_t lawOuput_thr, uint8_t SCNS_fault_flag, uint8_t SCNS_mode, uint8_t SCNS_fix_status, uint8_t SCNS_PDOP, int16_t SCNS_velocity_N, int16_t SCNS_velocity_E, int16_t SCNS_velocity_U, int16_t SCNS_picth, int16_t SCNS_roll, uint16_t SCNS_yaw, int16_t SCNS_rollRate, int16_t SCNS_pitchRate, int16_t SCNS_yawRate, int16_t SCNS_xAcc, int32_t SCNS_lon, int32_t SCNS_lat, uint16_t SCNS_alt, int16_t SCNS_Vg_2D, uint8_t intSensor_fixStatus, uint8_t intSensor_starUse, uint16_t intSensor_Eph, uint16_t intSensor_Epv, int32_t intSensor_lon_gps, int32_t intSensor_lat_gps, uint16_t intSensor_alt_gps, uint16_t intSensor_Vg_2D, int16_t intSensor_roll, int16_t intSensor_pitch, uint16_t intSensor_yaw, int16_t intSensor_psiV, int16_t intSensor_rollRate, int16_t intSensor_pitchRate, int16_t intSensor_yawRate, uint16_t intSensor_alt_baro, int16_t intSensor_Vi, uint16_t pwmOut_ail_L, uint16_t pwmOut_ail_R, uint16_t pwmOut_ele_L, uint16_t pwmOut_ele_R, uint16_t pwmOut_rud_L, uint16_t pwmOut_rud_R, uint16_t pwmOut_thr, uint16_t pwmFb_ail_L, uint16_t pwmFb_ail_R, uint16_t pwmFb_ele_L, uint16_t pwmFb_ele_R, uint16_t pwmFb_rud_L, uint16_t pwmFb_rud_R, uint16_t pwmFb_thr, uint16_t voltage_power, uint8_t voltage_equip, uint8_t voltage_actuator, uint8_t DI_status, uint16_t DO_status, int16_t airlineTrack_dL, int16_t airlineTrack_dY, int16_t airlineTrack_dH, uint8_t severity, const char *text)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TELE_DATA_LEN];
    _mav_put_int32_t(buf, 0, homePos_lat);
    _mav_put_int32_t(buf, 4, homePos_lon);
    _mav_put_int32_t(buf, 8, lon);
    _mav_put_int32_t(buf, 12, lat);
    _mav_put_int32_t(buf, 16, SCNS_lon);
    _mav_put_int32_t(buf, 20, SCNS_lat);
    _mav_put_int32_t(buf, 24, intSensor_lon_gps);
    _mav_put_int32_t(buf, 28, intSensor_lat_gps);
    _mav_put_uint16_t(buf, 32, flight_time_sec);
    _mav_put_uint16_t(buf, 34, distance2Home);
    _mav_put_uint16_t(buf, 36, homePos_alt);
    _mav_put_int16_t(buf, 38, pitch);
    _mav_put_int16_t(buf, 40, roll);
    _mav_put_uint16_t(buf, 42, Vi);
    _mav_put_uint16_t(buf, 44, Vg);
    _mav_put_int16_t(buf, 46, hdot);
    _mav_put_uint16_t(buf, 48, yaw);
    _mav_put_int16_t(buf, 50, psiV);
    _mav_put_uint16_t(buf, 52, alt);
    _mav_put_uint16_t(buf, 54, alt_relative);
    _mav_put_uint16_t(buf, 56, cmd_alt);
    _mav_put_uint16_t(buf, 58, cmd_Vi);
    _mav_put_int16_t(buf, 60, cmd_theta);
    _mav_put_int16_t(buf, 62, cmd_phi);
    _mav_put_int16_t(buf, 64, cmd_psi);
    _mav_put_int16_t(buf, 66, cmd_hdot);
    _mav_put_int16_t(buf, 68, lawOuput_ele);
    _mav_put_int16_t(buf, 70, lawOuput_ail);
    _mav_put_int16_t(buf, 72, lawOuput_rud);
    _mav_put_int16_t(buf, 74, SCNS_velocity_N);
    _mav_put_int16_t(buf, 76, SCNS_velocity_E);
    _mav_put_int16_t(buf, 78, SCNS_velocity_U);
    _mav_put_int16_t(buf, 80, SCNS_picth);
    _mav_put_int16_t(buf, 82, SCNS_roll);
    _mav_put_uint16_t(buf, 84, SCNS_yaw);
    _mav_put_int16_t(buf, 86, SCNS_rollRate);
    _mav_put_int16_t(buf, 88, SCNS_pitchRate);
    _mav_put_int16_t(buf, 90, SCNS_yawRate);
    _mav_put_int16_t(buf, 92, SCNS_xAcc);
    _mav_put_uint16_t(buf, 94, SCNS_alt);
    _mav_put_int16_t(buf, 96, SCNS_Vg_2D);
    _mav_put_uint16_t(buf, 98, intSensor_Eph);
    _mav_put_uint16_t(buf, 100, intSensor_Epv);
    _mav_put_uint16_t(buf, 102, intSensor_alt_gps);
    _mav_put_uint16_t(buf, 104, intSensor_Vg_2D);
    _mav_put_int16_t(buf, 106, intSensor_roll);
    _mav_put_int16_t(buf, 108, intSensor_pitch);
    _mav_put_uint16_t(buf, 110, intSensor_yaw);
    _mav_put_int16_t(buf, 112, intSensor_psiV);
    _mav_put_int16_t(buf, 114, intSensor_rollRate);
    _mav_put_int16_t(buf, 116, intSensor_pitchRate);
    _mav_put_int16_t(buf, 118, intSensor_yawRate);
    _mav_put_uint16_t(buf, 120, intSensor_alt_baro);
    _mav_put_int16_t(buf, 122, intSensor_Vi);
    _mav_put_uint16_t(buf, 124, pwmOut_ail_L);
    _mav_put_uint16_t(buf, 126, pwmOut_ail_R);
    _mav_put_uint16_t(buf, 128, pwmOut_ele_L);
    _mav_put_uint16_t(buf, 130, pwmOut_ele_R);
    _mav_put_uint16_t(buf, 132, pwmOut_rud_L);
    _mav_put_uint16_t(buf, 134, pwmOut_rud_R);
    _mav_put_uint16_t(buf, 136, pwmOut_thr);
    _mav_put_uint16_t(buf, 138, pwmFb_ail_L);
    _mav_put_uint16_t(buf, 140, pwmFb_ail_R);
    _mav_put_uint16_t(buf, 142, pwmFb_ele_L);
    _mav_put_uint16_t(buf, 144, pwmFb_ele_R);
    _mav_put_uint16_t(buf, 146, pwmFb_rud_L);
    _mav_put_uint16_t(buf, 148, pwmFb_rud_R);
    _mav_put_uint16_t(buf, 150, pwmFb_thr);
    _mav_put_uint16_t(buf, 152, voltage_power);
    _mav_put_uint16_t(buf, 154, DO_status);
    _mav_put_int16_t(buf, 156, airlineTrack_dL);
    _mav_put_int16_t(buf, 158, airlineTrack_dY);
    _mav_put_int16_t(buf, 160, airlineTrack_dH);
    _mav_put_uint8_t(buf, 162, vehicle_id);
    _mav_put_uint8_t(buf, 163, link_quality);
    _mav_put_uint8_t(buf, 164, err_rate);
    _mav_put_uint8_t(buf, 165, endurance_time_min);
    _mav_put_uint8_t(buf, 166, endurance_distance_km);
    _mav_put_uint8_t(buf, 167, year);
    _mav_put_uint8_t(buf, 168, month);
    _mav_put_uint8_t(buf, 169, day);
    _mav_put_uint8_t(buf, 170, hour);
    _mav_put_uint8_t(buf, 171, min);
    _mav_put_uint8_t(buf, 172, sec);
    _mav_put_uint8_t(buf, 173, armed);
    _mav_put_uint8_t(buf, 174, flight_mode);
    _mav_put_uint8_t(buf, 175, fix_mode);
    _mav_put_uint8_t(buf, 176, satelliteUse);
    _mav_put_uint8_t(buf, 177, posSrc);
    _mav_put_uint8_t(buf, 178, altSrc);
    _mav_put_uint8_t(buf, 179, airSpdSrc);
    _mav_put_uint8_t(buf, 180, grdSpdSrc);
    _mav_put_uint8_t(buf, 181, attSrc);
    _mav_put_uint8_t(buf, 182, yawSrc);
    _mav_put_uint8_t(buf, 183, lawOuput_thr);
    _mav_put_uint8_t(buf, 184, SCNS_fault_flag);
    _mav_put_uint8_t(buf, 185, SCNS_mode);
    _mav_put_uint8_t(buf, 186, SCNS_fix_status);
    _mav_put_uint8_t(buf, 187, SCNS_PDOP);
    _mav_put_uint8_t(buf, 188, intSensor_fixStatus);
    _mav_put_uint8_t(buf, 189, intSensor_starUse);
    _mav_put_uint8_t(buf, 190, voltage_equip);
    _mav_put_uint8_t(buf, 191, voltage_actuator);
    _mav_put_uint8_t(buf, 192, DI_status);
    _mav_put_uint8_t(buf, 193, severity);
    _mav_put_char_array(buf, 194, text, 30);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TELE_DATA, buf, MAVLINK_MSG_ID_TELE_DATA_MIN_LEN, MAVLINK_MSG_ID_TELE_DATA_LEN, MAVLINK_MSG_ID_TELE_DATA_CRC);
#else
    mavlink_tele_data_t packet;
    packet.homePos_lat = homePos_lat;
    packet.homePos_lon = homePos_lon;
    packet.lon = lon;
    packet.lat = lat;
    packet.SCNS_lon = SCNS_lon;
    packet.SCNS_lat = SCNS_lat;
    packet.intSensor_lon_gps = intSensor_lon_gps;
    packet.intSensor_lat_gps = intSensor_lat_gps;
    packet.flight_time_sec = flight_time_sec;
    packet.distance2Home = distance2Home;
    packet.homePos_alt = homePos_alt;
    packet.pitch = pitch;
    packet.roll = roll;
    packet.Vi = Vi;
    packet.Vg = Vg;
    packet.hdot = hdot;
    packet.yaw = yaw;
    packet.psiV = psiV;
    packet.alt = alt;
    packet.alt_relative = alt_relative;
    packet.cmd_alt = cmd_alt;
    packet.cmd_Vi = cmd_Vi;
    packet.cmd_theta = cmd_theta;
    packet.cmd_phi = cmd_phi;
    packet.cmd_psi = cmd_psi;
    packet.cmd_hdot = cmd_hdot;
    packet.lawOuput_ele = lawOuput_ele;
    packet.lawOuput_ail = lawOuput_ail;
    packet.lawOuput_rud = lawOuput_rud;
    packet.SCNS_velocity_N = SCNS_velocity_N;
    packet.SCNS_velocity_E = SCNS_velocity_E;
    packet.SCNS_velocity_U = SCNS_velocity_U;
    packet.SCNS_picth = SCNS_picth;
    packet.SCNS_roll = SCNS_roll;
    packet.SCNS_yaw = SCNS_yaw;
    packet.SCNS_rollRate = SCNS_rollRate;
    packet.SCNS_pitchRate = SCNS_pitchRate;
    packet.SCNS_yawRate = SCNS_yawRate;
    packet.SCNS_xAcc = SCNS_xAcc;
    packet.SCNS_alt = SCNS_alt;
    packet.SCNS_Vg_2D = SCNS_Vg_2D;
    packet.intSensor_Eph = intSensor_Eph;
    packet.intSensor_Epv = intSensor_Epv;
    packet.intSensor_alt_gps = intSensor_alt_gps;
    packet.intSensor_Vg_2D = intSensor_Vg_2D;
    packet.intSensor_roll = intSensor_roll;
    packet.intSensor_pitch = intSensor_pitch;
    packet.intSensor_yaw = intSensor_yaw;
    packet.intSensor_psiV = intSensor_psiV;
    packet.intSensor_rollRate = intSensor_rollRate;
    packet.intSensor_pitchRate = intSensor_pitchRate;
    packet.intSensor_yawRate = intSensor_yawRate;
    packet.intSensor_alt_baro = intSensor_alt_baro;
    packet.intSensor_Vi = intSensor_Vi;
    packet.pwmOut_ail_L = pwmOut_ail_L;
    packet.pwmOut_ail_R = pwmOut_ail_R;
    packet.pwmOut_ele_L = pwmOut_ele_L;
    packet.pwmOut_ele_R = pwmOut_ele_R;
    packet.pwmOut_rud_L = pwmOut_rud_L;
    packet.pwmOut_rud_R = pwmOut_rud_R;
    packet.pwmOut_thr = pwmOut_thr;
    packet.pwmFb_ail_L = pwmFb_ail_L;
    packet.pwmFb_ail_R = pwmFb_ail_R;
    packet.pwmFb_ele_L = pwmFb_ele_L;
    packet.pwmFb_ele_R = pwmFb_ele_R;
    packet.pwmFb_rud_L = pwmFb_rud_L;
    packet.pwmFb_rud_R = pwmFb_rud_R;
    packet.pwmFb_thr = pwmFb_thr;
    packet.voltage_power = voltage_power;
    packet.DO_status = DO_status;
    packet.airlineTrack_dL = airlineTrack_dL;
    packet.airlineTrack_dY = airlineTrack_dY;
    packet.airlineTrack_dH = airlineTrack_dH;
    packet.vehicle_id = vehicle_id;
    packet.link_quality = link_quality;
    packet.err_rate = err_rate;
    packet.endurance_time_min = endurance_time_min;
    packet.endurance_distance_km = endurance_distance_km;
    packet.year = year;
    packet.month = month;
    packet.day = day;
    packet.hour = hour;
    packet.min = min;
    packet.sec = sec;
    packet.armed = armed;
    packet.flight_mode = flight_mode;
    packet.fix_mode = fix_mode;
    packet.satelliteUse = satelliteUse;
    packet.posSrc = posSrc;
    packet.altSrc = altSrc;
    packet.airSpdSrc = airSpdSrc;
    packet.grdSpdSrc = grdSpdSrc;
    packet.attSrc = attSrc;
    packet.yawSrc = yawSrc;
    packet.lawOuput_thr = lawOuput_thr;
    packet.SCNS_fault_flag = SCNS_fault_flag;
    packet.SCNS_mode = SCNS_mode;
    packet.SCNS_fix_status = SCNS_fix_status;
    packet.SCNS_PDOP = SCNS_PDOP;
    packet.intSensor_fixStatus = intSensor_fixStatus;
    packet.intSensor_starUse = intSensor_starUse;
    packet.voltage_equip = voltage_equip;
    packet.voltage_actuator = voltage_actuator;
    packet.DI_status = DI_status;
    packet.severity = severity;
    mav_array_memcpy(packet.text, text, sizeof(char)*30);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TELE_DATA, (const char *)&packet, MAVLINK_MSG_ID_TELE_DATA_MIN_LEN, MAVLINK_MSG_ID_TELE_DATA_LEN, MAVLINK_MSG_ID_TELE_DATA_CRC);
#endif
}

/**
 * @brief Send a tele_data message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_tele_data_send_struct(mavlink_channel_t chan, const mavlink_tele_data_t* tele_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_tele_data_send(chan, tele_data->vehicle_id, tele_data->link_quality, tele_data->err_rate, tele_data->flight_time_sec, tele_data->endurance_time_min, tele_data->endurance_distance_km, tele_data->distance2Home, tele_data->year, tele_data->month, tele_data->day, tele_data->hour, tele_data->min, tele_data->sec, tele_data->homePos_lat, tele_data->homePos_lon, tele_data->homePos_alt, tele_data->armed, tele_data->flight_mode, tele_data->fix_mode, tele_data->satelliteUse, tele_data->posSrc, tele_data->altSrc, tele_data->airSpdSrc, tele_data->grdSpdSrc, tele_data->attSrc, tele_data->yawSrc, tele_data->pitch, tele_data->roll, tele_data->Vi, tele_data->Vg, tele_data->hdot, tele_data->yaw, tele_data->psiV, tele_data->lon, tele_data->lat, tele_data->alt, tele_data->alt_relative, tele_data->cmd_alt, tele_data->cmd_Vi, tele_data->cmd_theta, tele_data->cmd_phi, tele_data->cmd_psi, tele_data->cmd_hdot, tele_data->lawOuput_ele, tele_data->lawOuput_ail, tele_data->lawOuput_rud, tele_data->lawOuput_thr, tele_data->SCNS_fault_flag, tele_data->SCNS_mode, tele_data->SCNS_fix_status, tele_data->SCNS_PDOP, tele_data->SCNS_velocity_N, tele_data->SCNS_velocity_E, tele_data->SCNS_velocity_U, tele_data->SCNS_picth, tele_data->SCNS_roll, tele_data->SCNS_yaw, tele_data->SCNS_rollRate, tele_data->SCNS_pitchRate, tele_data->SCNS_yawRate, tele_data->SCNS_xAcc, tele_data->SCNS_lon, tele_data->SCNS_lat, tele_data->SCNS_alt, tele_data->SCNS_Vg_2D, tele_data->intSensor_fixStatus, tele_data->intSensor_starUse, tele_data->intSensor_Eph, tele_data->intSensor_Epv, tele_data->intSensor_lon_gps, tele_data->intSensor_lat_gps, tele_data->intSensor_alt_gps, tele_data->intSensor_Vg_2D, tele_data->intSensor_roll, tele_data->intSensor_pitch, tele_data->intSensor_yaw, tele_data->intSensor_psiV, tele_data->intSensor_rollRate, tele_data->intSensor_pitchRate, tele_data->intSensor_yawRate, tele_data->intSensor_alt_baro, tele_data->intSensor_Vi, tele_data->pwmOut_ail_L, tele_data->pwmOut_ail_R, tele_data->pwmOut_ele_L, tele_data->pwmOut_ele_R, tele_data->pwmOut_rud_L, tele_data->pwmOut_rud_R, tele_data->pwmOut_thr, tele_data->pwmFb_ail_L, tele_data->pwmFb_ail_R, tele_data->pwmFb_ele_L, tele_data->pwmFb_ele_R, tele_data->pwmFb_rud_L, tele_data->pwmFb_rud_R, tele_data->pwmFb_thr, tele_data->voltage_power, tele_data->voltage_equip, tele_data->voltage_actuator, tele_data->DI_status, tele_data->DO_status, tele_data->airlineTrack_dL, tele_data->airlineTrack_dY, tele_data->airlineTrack_dH, tele_data->severity, tele_data->text);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TELE_DATA, (const char *)tele_data, MAVLINK_MSG_ID_TELE_DATA_MIN_LEN, MAVLINK_MSG_ID_TELE_DATA_LEN, MAVLINK_MSG_ID_TELE_DATA_CRC);
#endif
}

#if MAVLINK_MSG_ID_TELE_DATA_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_tele_data_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t vehicle_id, uint8_t link_quality, uint8_t err_rate, uint16_t flight_time_sec, uint8_t endurance_time_min, uint8_t endurance_distance_km, uint16_t distance2Home, uint8_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t min, uint8_t sec, int32_t homePos_lat, int32_t homePos_lon, uint16_t homePos_alt, uint8_t armed, uint8_t flight_mode, uint8_t fix_mode, uint8_t satelliteUse, uint8_t posSrc, uint8_t altSrc, uint8_t airSpdSrc, uint8_t grdSpdSrc, uint8_t attSrc, uint8_t yawSrc, int16_t pitch, int16_t roll, uint16_t Vi, uint16_t Vg, int16_t hdot, uint16_t yaw, int16_t psiV, int32_t lon, int32_t lat, uint16_t alt, uint16_t alt_relative, uint16_t cmd_alt, uint16_t cmd_Vi, int16_t cmd_theta, int16_t cmd_phi, int16_t cmd_psi, int16_t cmd_hdot, int16_t lawOuput_ele, int16_t lawOuput_ail, int16_t lawOuput_rud, uint8_t lawOuput_thr, uint8_t SCNS_fault_flag, uint8_t SCNS_mode, uint8_t SCNS_fix_status, uint8_t SCNS_PDOP, int16_t SCNS_velocity_N, int16_t SCNS_velocity_E, int16_t SCNS_velocity_U, int16_t SCNS_picth, int16_t SCNS_roll, uint16_t SCNS_yaw, int16_t SCNS_rollRate, int16_t SCNS_pitchRate, int16_t SCNS_yawRate, int16_t SCNS_xAcc, int32_t SCNS_lon, int32_t SCNS_lat, uint16_t SCNS_alt, int16_t SCNS_Vg_2D, uint8_t intSensor_fixStatus, uint8_t intSensor_starUse, uint16_t intSensor_Eph, uint16_t intSensor_Epv, int32_t intSensor_lon_gps, int32_t intSensor_lat_gps, uint16_t intSensor_alt_gps, uint16_t intSensor_Vg_2D, int16_t intSensor_roll, int16_t intSensor_pitch, uint16_t intSensor_yaw, int16_t intSensor_psiV, int16_t intSensor_rollRate, int16_t intSensor_pitchRate, int16_t intSensor_yawRate, uint16_t intSensor_alt_baro, int16_t intSensor_Vi, uint16_t pwmOut_ail_L, uint16_t pwmOut_ail_R, uint16_t pwmOut_ele_L, uint16_t pwmOut_ele_R, uint16_t pwmOut_rud_L, uint16_t pwmOut_rud_R, uint16_t pwmOut_thr, uint16_t pwmFb_ail_L, uint16_t pwmFb_ail_R, uint16_t pwmFb_ele_L, uint16_t pwmFb_ele_R, uint16_t pwmFb_rud_L, uint16_t pwmFb_rud_R, uint16_t pwmFb_thr, uint16_t voltage_power, uint8_t voltage_equip, uint8_t voltage_actuator, uint8_t DI_status, uint16_t DO_status, int16_t airlineTrack_dL, int16_t airlineTrack_dY, int16_t airlineTrack_dH, uint8_t severity, const char *text)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int32_t(buf, 0, homePos_lat);
    _mav_put_int32_t(buf, 4, homePos_lon);
    _mav_put_int32_t(buf, 8, lon);
    _mav_put_int32_t(buf, 12, lat);
    _mav_put_int32_t(buf, 16, SCNS_lon);
    _mav_put_int32_t(buf, 20, SCNS_lat);
    _mav_put_int32_t(buf, 24, intSensor_lon_gps);
    _mav_put_int32_t(buf, 28, intSensor_lat_gps);
    _mav_put_uint16_t(buf, 32, flight_time_sec);
    _mav_put_uint16_t(buf, 34, distance2Home);
    _mav_put_uint16_t(buf, 36, homePos_alt);
    _mav_put_int16_t(buf, 38, pitch);
    _mav_put_int16_t(buf, 40, roll);
    _mav_put_uint16_t(buf, 42, Vi);
    _mav_put_uint16_t(buf, 44, Vg);
    _mav_put_int16_t(buf, 46, hdot);
    _mav_put_uint16_t(buf, 48, yaw);
    _mav_put_int16_t(buf, 50, psiV);
    _mav_put_uint16_t(buf, 52, alt);
    _mav_put_uint16_t(buf, 54, alt_relative);
    _mav_put_uint16_t(buf, 56, cmd_alt);
    _mav_put_uint16_t(buf, 58, cmd_Vi);
    _mav_put_int16_t(buf, 60, cmd_theta);
    _mav_put_int16_t(buf, 62, cmd_phi);
    _mav_put_int16_t(buf, 64, cmd_psi);
    _mav_put_int16_t(buf, 66, cmd_hdot);
    _mav_put_int16_t(buf, 68, lawOuput_ele);
    _mav_put_int16_t(buf, 70, lawOuput_ail);
    _mav_put_int16_t(buf, 72, lawOuput_rud);
    _mav_put_int16_t(buf, 74, SCNS_velocity_N);
    _mav_put_int16_t(buf, 76, SCNS_velocity_E);
    _mav_put_int16_t(buf, 78, SCNS_velocity_U);
    _mav_put_int16_t(buf, 80, SCNS_picth);
    _mav_put_int16_t(buf, 82, SCNS_roll);
    _mav_put_uint16_t(buf, 84, SCNS_yaw);
    _mav_put_int16_t(buf, 86, SCNS_rollRate);
    _mav_put_int16_t(buf, 88, SCNS_pitchRate);
    _mav_put_int16_t(buf, 90, SCNS_yawRate);
    _mav_put_int16_t(buf, 92, SCNS_xAcc);
    _mav_put_uint16_t(buf, 94, SCNS_alt);
    _mav_put_int16_t(buf, 96, SCNS_Vg_2D);
    _mav_put_uint16_t(buf, 98, intSensor_Eph);
    _mav_put_uint16_t(buf, 100, intSensor_Epv);
    _mav_put_uint16_t(buf, 102, intSensor_alt_gps);
    _mav_put_uint16_t(buf, 104, intSensor_Vg_2D);
    _mav_put_int16_t(buf, 106, intSensor_roll);
    _mav_put_int16_t(buf, 108, intSensor_pitch);
    _mav_put_uint16_t(buf, 110, intSensor_yaw);
    _mav_put_int16_t(buf, 112, intSensor_psiV);
    _mav_put_int16_t(buf, 114, intSensor_rollRate);
    _mav_put_int16_t(buf, 116, intSensor_pitchRate);
    _mav_put_int16_t(buf, 118, intSensor_yawRate);
    _mav_put_uint16_t(buf, 120, intSensor_alt_baro);
    _mav_put_int16_t(buf, 122, intSensor_Vi);
    _mav_put_uint16_t(buf, 124, pwmOut_ail_L);
    _mav_put_uint16_t(buf, 126, pwmOut_ail_R);
    _mav_put_uint16_t(buf, 128, pwmOut_ele_L);
    _mav_put_uint16_t(buf, 130, pwmOut_ele_R);
    _mav_put_uint16_t(buf, 132, pwmOut_rud_L);
    _mav_put_uint16_t(buf, 134, pwmOut_rud_R);
    _mav_put_uint16_t(buf, 136, pwmOut_thr);
    _mav_put_uint16_t(buf, 138, pwmFb_ail_L);
    _mav_put_uint16_t(buf, 140, pwmFb_ail_R);
    _mav_put_uint16_t(buf, 142, pwmFb_ele_L);
    _mav_put_uint16_t(buf, 144, pwmFb_ele_R);
    _mav_put_uint16_t(buf, 146, pwmFb_rud_L);
    _mav_put_uint16_t(buf, 148, pwmFb_rud_R);
    _mav_put_uint16_t(buf, 150, pwmFb_thr);
    _mav_put_uint16_t(buf, 152, voltage_power);
    _mav_put_uint16_t(buf, 154, DO_status);
    _mav_put_int16_t(buf, 156, airlineTrack_dL);
    _mav_put_int16_t(buf, 158, airlineTrack_dY);
    _mav_put_int16_t(buf, 160, airlineTrack_dH);
    _mav_put_uint8_t(buf, 162, vehicle_id);
    _mav_put_uint8_t(buf, 163, link_quality);
    _mav_put_uint8_t(buf, 164, err_rate);
    _mav_put_uint8_t(buf, 165, endurance_time_min);
    _mav_put_uint8_t(buf, 166, endurance_distance_km);
    _mav_put_uint8_t(buf, 167, year);
    _mav_put_uint8_t(buf, 168, month);
    _mav_put_uint8_t(buf, 169, day);
    _mav_put_uint8_t(buf, 170, hour);
    _mav_put_uint8_t(buf, 171, min);
    _mav_put_uint8_t(buf, 172, sec);
    _mav_put_uint8_t(buf, 173, armed);
    _mav_put_uint8_t(buf, 174, flight_mode);
    _mav_put_uint8_t(buf, 175, fix_mode);
    _mav_put_uint8_t(buf, 176, satelliteUse);
    _mav_put_uint8_t(buf, 177, posSrc);
    _mav_put_uint8_t(buf, 178, altSrc);
    _mav_put_uint8_t(buf, 179, airSpdSrc);
    _mav_put_uint8_t(buf, 180, grdSpdSrc);
    _mav_put_uint8_t(buf, 181, attSrc);
    _mav_put_uint8_t(buf, 182, yawSrc);
    _mav_put_uint8_t(buf, 183, lawOuput_thr);
    _mav_put_uint8_t(buf, 184, SCNS_fault_flag);
    _mav_put_uint8_t(buf, 185, SCNS_mode);
    _mav_put_uint8_t(buf, 186, SCNS_fix_status);
    _mav_put_uint8_t(buf, 187, SCNS_PDOP);
    _mav_put_uint8_t(buf, 188, intSensor_fixStatus);
    _mav_put_uint8_t(buf, 189, intSensor_starUse);
    _mav_put_uint8_t(buf, 190, voltage_equip);
    _mav_put_uint8_t(buf, 191, voltage_actuator);
    _mav_put_uint8_t(buf, 192, DI_status);
    _mav_put_uint8_t(buf, 193, severity);
    _mav_put_char_array(buf, 194, text, 30);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TELE_DATA, buf, MAVLINK_MSG_ID_TELE_DATA_MIN_LEN, MAVLINK_MSG_ID_TELE_DATA_LEN, MAVLINK_MSG_ID_TELE_DATA_CRC);
#else
    mavlink_tele_data_t *packet = (mavlink_tele_data_t *)msgbuf;
    packet->homePos_lat = homePos_lat;
    packet->homePos_lon = homePos_lon;
    packet->lon = lon;
    packet->lat = lat;
    packet->SCNS_lon = SCNS_lon;
    packet->SCNS_lat = SCNS_lat;
    packet->intSensor_lon_gps = intSensor_lon_gps;
    packet->intSensor_lat_gps = intSensor_lat_gps;
    packet->flight_time_sec = flight_time_sec;
    packet->distance2Home = distance2Home;
    packet->homePos_alt = homePos_alt;
    packet->pitch = pitch;
    packet->roll = roll;
    packet->Vi = Vi;
    packet->Vg = Vg;
    packet->hdot = hdot;
    packet->yaw = yaw;
    packet->psiV = psiV;
    packet->alt = alt;
    packet->alt_relative = alt_relative;
    packet->cmd_alt = cmd_alt;
    packet->cmd_Vi = cmd_Vi;
    packet->cmd_theta = cmd_theta;
    packet->cmd_phi = cmd_phi;
    packet->cmd_psi = cmd_psi;
    packet->cmd_hdot = cmd_hdot;
    packet->lawOuput_ele = lawOuput_ele;
    packet->lawOuput_ail = lawOuput_ail;
    packet->lawOuput_rud = lawOuput_rud;
    packet->SCNS_velocity_N = SCNS_velocity_N;
    packet->SCNS_velocity_E = SCNS_velocity_E;
    packet->SCNS_velocity_U = SCNS_velocity_U;
    packet->SCNS_picth = SCNS_picth;
    packet->SCNS_roll = SCNS_roll;
    packet->SCNS_yaw = SCNS_yaw;
    packet->SCNS_rollRate = SCNS_rollRate;
    packet->SCNS_pitchRate = SCNS_pitchRate;
    packet->SCNS_yawRate = SCNS_yawRate;
    packet->SCNS_xAcc = SCNS_xAcc;
    packet->SCNS_alt = SCNS_alt;
    packet->SCNS_Vg_2D = SCNS_Vg_2D;
    packet->intSensor_Eph = intSensor_Eph;
    packet->intSensor_Epv = intSensor_Epv;
    packet->intSensor_alt_gps = intSensor_alt_gps;
    packet->intSensor_Vg_2D = intSensor_Vg_2D;
    packet->intSensor_roll = intSensor_roll;
    packet->intSensor_pitch = intSensor_pitch;
    packet->intSensor_yaw = intSensor_yaw;
    packet->intSensor_psiV = intSensor_psiV;
    packet->intSensor_rollRate = intSensor_rollRate;
    packet->intSensor_pitchRate = intSensor_pitchRate;
    packet->intSensor_yawRate = intSensor_yawRate;
    packet->intSensor_alt_baro = intSensor_alt_baro;
    packet->intSensor_Vi = intSensor_Vi;
    packet->pwmOut_ail_L = pwmOut_ail_L;
    packet->pwmOut_ail_R = pwmOut_ail_R;
    packet->pwmOut_ele_L = pwmOut_ele_L;
    packet->pwmOut_ele_R = pwmOut_ele_R;
    packet->pwmOut_rud_L = pwmOut_rud_L;
    packet->pwmOut_rud_R = pwmOut_rud_R;
    packet->pwmOut_thr = pwmOut_thr;
    packet->pwmFb_ail_L = pwmFb_ail_L;
    packet->pwmFb_ail_R = pwmFb_ail_R;
    packet->pwmFb_ele_L = pwmFb_ele_L;
    packet->pwmFb_ele_R = pwmFb_ele_R;
    packet->pwmFb_rud_L = pwmFb_rud_L;
    packet->pwmFb_rud_R = pwmFb_rud_R;
    packet->pwmFb_thr = pwmFb_thr;
    packet->voltage_power = voltage_power;
    packet->DO_status = DO_status;
    packet->airlineTrack_dL = airlineTrack_dL;
    packet->airlineTrack_dY = airlineTrack_dY;
    packet->airlineTrack_dH = airlineTrack_dH;
    packet->vehicle_id = vehicle_id;
    packet->link_quality = link_quality;
    packet->err_rate = err_rate;
    packet->endurance_time_min = endurance_time_min;
    packet->endurance_distance_km = endurance_distance_km;
    packet->year = year;
    packet->month = month;
    packet->day = day;
    packet->hour = hour;
    packet->min = min;
    packet->sec = sec;
    packet->armed = armed;
    packet->flight_mode = flight_mode;
    packet->fix_mode = fix_mode;
    packet->satelliteUse = satelliteUse;
    packet->posSrc = posSrc;
    packet->altSrc = altSrc;
    packet->airSpdSrc = airSpdSrc;
    packet->grdSpdSrc = grdSpdSrc;
    packet->attSrc = attSrc;
    packet->yawSrc = yawSrc;
    packet->lawOuput_thr = lawOuput_thr;
    packet->SCNS_fault_flag = SCNS_fault_flag;
    packet->SCNS_mode = SCNS_mode;
    packet->SCNS_fix_status = SCNS_fix_status;
    packet->SCNS_PDOP = SCNS_PDOP;
    packet->intSensor_fixStatus = intSensor_fixStatus;
    packet->intSensor_starUse = intSensor_starUse;
    packet->voltage_equip = voltage_equip;
    packet->voltage_actuator = voltage_actuator;
    packet->DI_status = DI_status;
    packet->severity = severity;
    mav_array_memcpy(packet->text, text, sizeof(char)*30);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TELE_DATA, (const char *)packet, MAVLINK_MSG_ID_TELE_DATA_MIN_LEN, MAVLINK_MSG_ID_TELE_DATA_LEN, MAVLINK_MSG_ID_TELE_DATA_CRC);
#endif
}
#endif

#endif

// MESSAGE TELE_DATA UNPACKING


/**
 * @brief Get field vehicle_id from tele_data message
 *
 * @return  vehicle id
 */
static inline uint8_t mavlink_msg_tele_data_get_vehicle_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  162);
}

/**
 * @brief Get field link_quality from tele_data message
 *
 * @return  communication quality
 */
static inline uint8_t mavlink_msg_tele_data_get_link_quality(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  163);
}

/**
 * @brief Get field err_rate from tele_data message
 *
 * @return  bit err rate
 */
static inline uint8_t mavlink_msg_tele_data_get_err_rate(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  164);
}

/**
 * @brief Get field flight_time_sec from tele_data message
 *
 * @return  flight time,unit sec
 */
static inline uint16_t mavlink_msg_tele_data_get_flight_time_sec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  32);
}

/**
 * @brief Get field endurance_time_min from tele_data message
 *
 * @return  endurance time,unit min
 */
static inline uint8_t mavlink_msg_tele_data_get_endurance_time_min(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  165);
}

/**
 * @brief Get field endurance_distance_km from tele_data message
 *
 * @return  endurance distance,unit km
 */
static inline uint8_t mavlink_msg_tele_data_get_endurance_distance_km(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  166);
}

/**
 * @brief Get field distance2Home from tele_data message
 *
 * @return  distance to home position,unit m
 */
static inline uint16_t mavlink_msg_tele_data_get_distance2Home(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  34);
}

/**
 * @brief Get field year from tele_data message
 *
 * @return  GPS time,year-2020
 */
static inline uint8_t mavlink_msg_tele_data_get_year(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  167);
}

/**
 * @brief Get field month from tele_data message
 *
 * @return  GPS time,month
 */
static inline uint8_t mavlink_msg_tele_data_get_month(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  168);
}

/**
 * @brief Get field day from tele_data message
 *
 * @return  GPS time,day
 */
static inline uint8_t mavlink_msg_tele_data_get_day(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  169);
}

/**
 * @brief Get field hour from tele_data message
 *
 * @return  GPS time,hour
 */
static inline uint8_t mavlink_msg_tele_data_get_hour(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  170);
}

/**
 * @brief Get field min from tele_data message
 *
 * @return  GPS time,min
 */
static inline uint8_t mavlink_msg_tele_data_get_min(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  171);
}

/**
 * @brief Get field sec from tele_data message
 *
 * @return  GPS time,sec
 */
static inline uint8_t mavlink_msg_tele_data_get_sec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  172);
}

/**
 * @brief Get field homePos_lat from tele_data message
 *
 * @return  home position,lat
 */
static inline int32_t mavlink_msg_tele_data_get_homePos_lat(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field homePos_lon from tele_data message
 *
 * @return  home position,lon
 */
static inline int32_t mavlink_msg_tele_data_get_homePos_lon(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field homePos_alt from tele_data message
 *
 * @return  home position,alt
 */
static inline uint16_t mavlink_msg_tele_data_get_homePos_alt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  36);
}

/**
 * @brief Get field armed from tele_data message
 *
 * @return  arm status
 */
static inline uint8_t mavlink_msg_tele_data_get_armed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  173);
}

/**
 * @brief Get field flight_mode from tele_data message
 *
 * @return  flight mode
 */
static inline uint8_t mavlink_msg_tele_data_get_flight_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  174);
}

/**
 * @brief Get field fix_mode from tele_data message
 *
 * @return  GPS fix mode
 */
static inline uint8_t mavlink_msg_tele_data_get_fix_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  175);
}

/**
 * @brief Get field satelliteUse from tele_data message
 *
 * @return  satellite use number
 */
static inline uint8_t mavlink_msg_tele_data_get_satelliteUse(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  176);
}

/**
 * @brief Get field posSrc from tele_data message
 *
 * @return  position sensor source
 */
static inline uint8_t mavlink_msg_tele_data_get_posSrc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  177);
}

/**
 * @brief Get field altSrc from tele_data message
 *
 * @return  altitude sensor source
 */
static inline uint8_t mavlink_msg_tele_data_get_altSrc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  178);
}

/**
 * @brief Get field airSpdSrc from tele_data message
 *
 * @return  airSpeed sensor source
 */
static inline uint8_t mavlink_msg_tele_data_get_airSpdSrc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  179);
}

/**
 * @brief Get field grdSpdSrc from tele_data message
 *
 * @return  ground speed sensor source
 */
static inline uint8_t mavlink_msg_tele_data_get_grdSpdSrc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  180);
}

/**
 * @brief Get field attSrc from tele_data message
 *
 * @return  attitude sensor source
 */
static inline uint8_t mavlink_msg_tele_data_get_attSrc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  181);
}

/**
 * @brief Get field yawSrc from tele_data message
 *
 * @return  yaw sensor source
 */
static inline uint8_t mavlink_msg_tele_data_get_yawSrc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  182);
}

/**
 * @brief Get field pitch from tele_data message
 *
 * @return  fly status: pitch
 */
static inline int16_t mavlink_msg_tele_data_get_pitch(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  38);
}

/**
 * @brief Get field roll from tele_data message
 *
 * @return  fly status: roll
 */
static inline int16_t mavlink_msg_tele_data_get_roll(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  40);
}

/**
 * @brief Get field Vi from tele_data message
 *
 * @return  fly status: Vi
 */
static inline uint16_t mavlink_msg_tele_data_get_Vi(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  42);
}

/**
 * @brief Get field Vg from tele_data message
 *
 * @return  fly status: Vg
 */
static inline uint16_t mavlink_msg_tele_data_get_Vg(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  44);
}

/**
 * @brief Get field hdot from tele_data message
 *
 * @return  fly status: hdot
 */
static inline int16_t mavlink_msg_tele_data_get_hdot(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  46);
}

/**
 * @brief Get field yaw from tele_data message
 *
 * @return  fly status: yaw
 */
static inline uint16_t mavlink_msg_tele_data_get_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  48);
}

/**
 * @brief Get field psiV from tele_data message
 *
 * @return  fly status: psiV
 */
static inline int16_t mavlink_msg_tele_data_get_psiV(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  50);
}

/**
 * @brief Get field lon from tele_data message
 *
 * @return  fly status: lon
 */
static inline int32_t mavlink_msg_tele_data_get_lon(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field lat from tele_data message
 *
 * @return  fly status: lat
 */
static inline int32_t mavlink_msg_tele_data_get_lat(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field alt from tele_data message
 *
 * @return  fly status: alt
 */
static inline uint16_t mavlink_msg_tele_data_get_alt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  52);
}

/**
 * @brief Get field alt_relative from tele_data message
 *
 * @return  fly status: alt_relative
 */
static inline uint16_t mavlink_msg_tele_data_get_alt_relative(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  54);
}

/**
 * @brief Get field cmd_alt from tele_data message
 *
 * @return  fly command: alt
 */
static inline uint16_t mavlink_msg_tele_data_get_cmd_alt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  56);
}

/**
 * @brief Get field cmd_Vi from tele_data message
 *
 * @return  fly command: Vi
 */
static inline uint16_t mavlink_msg_tele_data_get_cmd_Vi(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  58);
}

/**
 * @brief Get field cmd_theta from tele_data message
 *
 * @return  fly command: tehta
 */
static inline int16_t mavlink_msg_tele_data_get_cmd_theta(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  60);
}

/**
 * @brief Get field cmd_phi from tele_data message
 *
 * @return  fly command: phi
 */
static inline int16_t mavlink_msg_tele_data_get_cmd_phi(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  62);
}

/**
 * @brief Get field cmd_psi from tele_data message
 *
 * @return  fly command: psi
 */
static inline int16_t mavlink_msg_tele_data_get_cmd_psi(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  64);
}

/**
 * @brief Get field cmd_hdot from tele_data message
 *
 * @return  fly command: hdot
 */
static inline int16_t mavlink_msg_tele_data_get_cmd_hdot(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  66);
}

/**
 * @brief Get field lawOuput_ele from tele_data message
 *
 * @return  law output: ele
 */
static inline int16_t mavlink_msg_tele_data_get_lawOuput_ele(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  68);
}

/**
 * @brief Get field lawOuput_ail from tele_data message
 *
 * @return  law output: ail
 */
static inline int16_t mavlink_msg_tele_data_get_lawOuput_ail(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  70);
}

/**
 * @brief Get field lawOuput_rud from tele_data message
 *
 * @return  law output: rud
 */
static inline int16_t mavlink_msg_tele_data_get_lawOuput_rud(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  72);
}

/**
 * @brief Get field lawOuput_thr from tele_data message
 *
 * @return  law output: thr
 */
static inline uint8_t mavlink_msg_tele_data_get_lawOuput_thr(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  183);
}

/**
 * @brief Get field SCNS_fault_flag from tele_data message
 *
 * @return  sbg: star use
 */
static inline uint8_t mavlink_msg_tele_data_get_SCNS_fault_flag(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  184);
}

/**
 * @brief Get field SCNS_mode from tele_data message
 *
 * @return  sbg: solution status
 */
static inline uint8_t mavlink_msg_tele_data_get_SCNS_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  185);
}

/**
 * @brief Get field SCNS_fix_status from tele_data message
 *
 * @return  sbg: fix status
 */
static inline uint8_t mavlink_msg_tele_data_get_SCNS_fix_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  186);
}

/**
 * @brief Get field SCNS_PDOP from tele_data message
 *
 * @return  sbg: solution status
 */
static inline uint8_t mavlink_msg_tele_data_get_SCNS_PDOP(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  187);
}

/**
 * @brief Get field SCNS_velocity_N from tele_data message
 *
 * @return  sbg: position accurancy of lat
 */
static inline int16_t mavlink_msg_tele_data_get_SCNS_velocity_N(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  74);
}

/**
 * @brief Get field SCNS_velocity_E from tele_data message
 *
 * @return  sbg: position accurancy of lon
 */
static inline int16_t mavlink_msg_tele_data_get_SCNS_velocity_E(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  76);
}

/**
 * @brief Get field SCNS_velocity_U from tele_data message
 *
 * @return  sbg: position accurancy of alt
 */
static inline int16_t mavlink_msg_tele_data_get_SCNS_velocity_U(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  78);
}

/**
 * @brief Get field SCNS_picth from tele_data message
 *
 * @return  sbg: pitch
 */
static inline int16_t mavlink_msg_tele_data_get_SCNS_picth(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  80);
}

/**
 * @brief Get field SCNS_roll from tele_data message
 *
 * @return  sbg: roll
 */
static inline int16_t mavlink_msg_tele_data_get_SCNS_roll(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  82);
}

/**
 * @brief Get field SCNS_yaw from tele_data message
 *
 * @return  sbg: yaw
 */
static inline uint16_t mavlink_msg_tele_data_get_SCNS_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  84);
}

/**
 * @brief Get field SCNS_rollRate from tele_data message
 *
 * @return  sbg: roll rate
 */
static inline int16_t mavlink_msg_tele_data_get_SCNS_rollRate(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  86);
}

/**
 * @brief Get field SCNS_pitchRate from tele_data message
 *
 * @return  sbg: pitch rate
 */
static inline int16_t mavlink_msg_tele_data_get_SCNS_pitchRate(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  88);
}

/**
 * @brief Get field SCNS_yawRate from tele_data message
 *
 * @return  sbg: yaw rate
 */
static inline int16_t mavlink_msg_tele_data_get_SCNS_yawRate(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  90);
}

/**
 * @brief Get field SCNS_xAcc from tele_data message
 *
 * @return  sbg: barometer alt
 */
static inline int16_t mavlink_msg_tele_data_get_SCNS_xAcc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  92);
}

/**
 * @brief Get field SCNS_lon from tele_data message
 *
 * @return  sbg: gps position lon
 */
static inline int32_t mavlink_msg_tele_data_get_SCNS_lon(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  16);
}

/**
 * @brief Get field SCNS_lat from tele_data message
 *
 * @return  sbg: gps position lat
 */
static inline int32_t mavlink_msg_tele_data_get_SCNS_lat(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  20);
}

/**
 * @brief Get field SCNS_alt from tele_data message
 *
 * @return  sbg: gps position alt
 */
static inline uint16_t mavlink_msg_tele_data_get_SCNS_alt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  94);
}

/**
 * @brief Get field SCNS_Vg_2D from tele_data message
 *
 * @return  sbg: Vg 2D
 */
static inline int16_t mavlink_msg_tele_data_get_SCNS_Vg_2D(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  96);
}

/**
 * @brief Get field intSensor_fixStatus from tele_data message
 *
 * @return  inter sensor: fix status
 */
static inline uint8_t mavlink_msg_tele_data_get_intSensor_fixStatus(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  188);
}

/**
 * @brief Get field intSensor_starUse from tele_data message
 *
 * @return  inter sensor: star use
 */
static inline uint8_t mavlink_msg_tele_data_get_intSensor_starUse(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  189);
}

/**
 * @brief Get field intSensor_Eph from tele_data message
 *
 * @return  inter sensor: eph
 */
static inline uint16_t mavlink_msg_tele_data_get_intSensor_Eph(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  98);
}

/**
 * @brief Get field intSensor_Epv from tele_data message
 *
 * @return  inter sensor: epv
 */
static inline uint16_t mavlink_msg_tele_data_get_intSensor_Epv(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  100);
}

/**
 * @brief Get field intSensor_lon_gps from tele_data message
 *
 * @return  inter sensor: gps position lon
 */
static inline int32_t mavlink_msg_tele_data_get_intSensor_lon_gps(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  24);
}

/**
 * @brief Get field intSensor_lat_gps from tele_data message
 *
 * @return  inter sensor: gps position lat
 */
static inline int32_t mavlink_msg_tele_data_get_intSensor_lat_gps(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  28);
}

/**
 * @brief Get field intSensor_alt_gps from tele_data message
 *
 * @return  inter sensor: gps position alt
 */
static inline uint16_t mavlink_msg_tele_data_get_intSensor_alt_gps(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  102);
}

/**
 * @brief Get field intSensor_Vg_2D from tele_data message
 *
 * @return  inter sensor: Vg 2D
 */
static inline uint16_t mavlink_msg_tele_data_get_intSensor_Vg_2D(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  104);
}

/**
 * @brief Get field intSensor_roll from tele_data message
 *
 * @return  inter sensor: roll
 */
static inline int16_t mavlink_msg_tele_data_get_intSensor_roll(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  106);
}

/**
 * @brief Get field intSensor_pitch from tele_data message
 *
 * @return  inter sensor: pitch
 */
static inline int16_t mavlink_msg_tele_data_get_intSensor_pitch(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  108);
}

/**
 * @brief Get field intSensor_yaw from tele_data message
 *
 * @return  inter sensor: yaw
 */
static inline uint16_t mavlink_msg_tele_data_get_intSensor_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  110);
}

/**
 * @brief Get field intSensor_psiV from tele_data message
 *
 * @return  inter sensor: psiV
 */
static inline int16_t mavlink_msg_tele_data_get_intSensor_psiV(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  112);
}

/**
 * @brief Get field intSensor_rollRate from tele_data message
 *
 * @return  inter sensor: roll rate
 */
static inline int16_t mavlink_msg_tele_data_get_intSensor_rollRate(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  114);
}

/**
 * @brief Get field intSensor_pitchRate from tele_data message
 *
 * @return  inter sensor: pitch rate
 */
static inline int16_t mavlink_msg_tele_data_get_intSensor_pitchRate(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  116);
}

/**
 * @brief Get field intSensor_yawRate from tele_data message
 *
 * @return  inter sensor: yaw rate
 */
static inline int16_t mavlink_msg_tele_data_get_intSensor_yawRate(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  118);
}

/**
 * @brief Get field intSensor_alt_baro from tele_data message
 *
 * @return  inter sensor: barometer alt
 */
static inline uint16_t mavlink_msg_tele_data_get_intSensor_alt_baro(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  120);
}

/**
 * @brief Get field intSensor_Vi from tele_data message
 *
 * @return  inter sensor: airspeed
 */
static inline int16_t mavlink_msg_tele_data_get_intSensor_Vi(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  122);
}

/**
 * @brief Get field pwmOut_ail_L from tele_data message
 *
 * @return  pwm output: ail left
 */
static inline uint16_t mavlink_msg_tele_data_get_pwmOut_ail_L(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  124);
}

/**
 * @brief Get field pwmOut_ail_R from tele_data message
 *
 * @return  pwm output: ail right
 */
static inline uint16_t mavlink_msg_tele_data_get_pwmOut_ail_R(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  126);
}

/**
 * @brief Get field pwmOut_ele_L from tele_data message
 *
 * @return  pwm output: ele left
 */
static inline uint16_t mavlink_msg_tele_data_get_pwmOut_ele_L(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  128);
}

/**
 * @brief Get field pwmOut_ele_R from tele_data message
 *
 * @return  pwm output: ele right
 */
static inline uint16_t mavlink_msg_tele_data_get_pwmOut_ele_R(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  130);
}

/**
 * @brief Get field pwmOut_rud_L from tele_data message
 *
 * @return  pwm output: rud left
 */
static inline uint16_t mavlink_msg_tele_data_get_pwmOut_rud_L(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  132);
}

/**
 * @brief Get field pwmOut_rud_R from tele_data message
 *
 * @return  pwm output: rud right
 */
static inline uint16_t mavlink_msg_tele_data_get_pwmOut_rud_R(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  134);
}

/**
 * @brief Get field pwmOut_thr from tele_data message
 *
 * @return  pwm output:  thr
 */
static inline uint16_t mavlink_msg_tele_data_get_pwmOut_thr(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  136);
}

/**
 * @brief Get field pwmFb_ail_L from tele_data message
 *
 * @return  pwm feedback: ail left
 */
static inline uint16_t mavlink_msg_tele_data_get_pwmFb_ail_L(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  138);
}

/**
 * @brief Get field pwmFb_ail_R from tele_data message
 *
 * @return  pwm feedback: ail right
 */
static inline uint16_t mavlink_msg_tele_data_get_pwmFb_ail_R(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  140);
}

/**
 * @brief Get field pwmFb_ele_L from tele_data message
 *
 * @return  pwm feedback: ele left
 */
static inline uint16_t mavlink_msg_tele_data_get_pwmFb_ele_L(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  142);
}

/**
 * @brief Get field pwmFb_ele_R from tele_data message
 *
 * @return  pwm feedback: ele right
 */
static inline uint16_t mavlink_msg_tele_data_get_pwmFb_ele_R(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  144);
}

/**
 * @brief Get field pwmFb_rud_L from tele_data message
 *
 * @return  pwm feedback: rud left
 */
static inline uint16_t mavlink_msg_tele_data_get_pwmFb_rud_L(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  146);
}

/**
 * @brief Get field pwmFb_rud_R from tele_data message
 *
 * @return  pwm feedback: rud right
 */
static inline uint16_t mavlink_msg_tele_data_get_pwmFb_rud_R(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  148);
}

/**
 * @brief Get field pwmFb_thr from tele_data message
 *
 * @return  pwm feedback: thr
 */
static inline uint16_t mavlink_msg_tele_data_get_pwmFb_thr(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  150);
}

/**
 * @brief Get field voltage_power from tele_data message
 *
 * @return  voltage of power
 */
static inline uint16_t mavlink_msg_tele_data_get_voltage_power(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  152);
}

/**
 * @brief Get field voltage_equip from tele_data message
 *
 * @return  voltage of equipment
 */
static inline uint8_t mavlink_msg_tele_data_get_voltage_equip(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  190);
}

/**
 * @brief Get field voltage_actuator from tele_data message
 *
 * @return  voltage of actuator
 */
static inline uint8_t mavlink_msg_tele_data_get_voltage_actuator(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  191);
}

/**
 * @brief Get field DI_status from tele_data message
 *
 * @return  DI status
 */
static inline uint8_t mavlink_msg_tele_data_get_DI_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  192);
}

/**
 * @brief Get field DO_status from tele_data message
 *
 * @return  DO status
 */
static inline uint16_t mavlink_msg_tele_data_get_DO_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  154);
}

/**
 * @brief Get field airlineTrack_dL from tele_data message
 *
 * @return  airlineTrack: dL
 */
static inline int16_t mavlink_msg_tele_data_get_airlineTrack_dL(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  156);
}

/**
 * @brief Get field airlineTrack_dY from tele_data message
 *
 * @return  airlineTrack: dY
 */
static inline int16_t mavlink_msg_tele_data_get_airlineTrack_dY(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  158);
}

/**
 * @brief Get field airlineTrack_dH from tele_data message
 *
 * @return  airlineTrack: dH
 */
static inline int16_t mavlink_msg_tele_data_get_airlineTrack_dH(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  160);
}

/**
 * @brief Get field severity from tele_data message
 *
 * @return  Severity of status. Relies on the definitions within RFC-5424. See enum MAV_SEVERITY.
 */
static inline uint8_t mavlink_msg_tele_data_get_severity(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  193);
}

/**
 * @brief Get field text from tele_data message
 *
 * @return  Status text message, without null termination character
 */
static inline uint16_t mavlink_msg_tele_data_get_text(const mavlink_message_t* msg, char *text)
{
    return _MAV_RETURN_char_array(msg, text, 30,  194);
}

/**
 * @brief Decode a tele_data message into a struct
 *
 * @param msg The message to decode
 * @param tele_data C-struct to decode the message contents into
 */
static inline void mavlink_msg_tele_data_decode(const mavlink_message_t* msg, mavlink_tele_data_t* tele_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    tele_data->homePos_lat = mavlink_msg_tele_data_get_homePos_lat(msg);
    tele_data->homePos_lon = mavlink_msg_tele_data_get_homePos_lon(msg);
    tele_data->lon = mavlink_msg_tele_data_get_lon(msg);
    tele_data->lat = mavlink_msg_tele_data_get_lat(msg);
    tele_data->SCNS_lon = mavlink_msg_tele_data_get_SCNS_lon(msg);
    tele_data->SCNS_lat = mavlink_msg_tele_data_get_SCNS_lat(msg);
    tele_data->intSensor_lon_gps = mavlink_msg_tele_data_get_intSensor_lon_gps(msg);
    tele_data->intSensor_lat_gps = mavlink_msg_tele_data_get_intSensor_lat_gps(msg);
    tele_data->flight_time_sec = mavlink_msg_tele_data_get_flight_time_sec(msg);
    tele_data->distance2Home = mavlink_msg_tele_data_get_distance2Home(msg);
    tele_data->homePos_alt = mavlink_msg_tele_data_get_homePos_alt(msg);
    tele_data->pitch = mavlink_msg_tele_data_get_pitch(msg);
    tele_data->roll = mavlink_msg_tele_data_get_roll(msg);
    tele_data->Vi = mavlink_msg_tele_data_get_Vi(msg);
    tele_data->Vg = mavlink_msg_tele_data_get_Vg(msg);
    tele_data->hdot = mavlink_msg_tele_data_get_hdot(msg);
    tele_data->yaw = mavlink_msg_tele_data_get_yaw(msg);
    tele_data->psiV = mavlink_msg_tele_data_get_psiV(msg);
    tele_data->alt = mavlink_msg_tele_data_get_alt(msg);
    tele_data->alt_relative = mavlink_msg_tele_data_get_alt_relative(msg);
    tele_data->cmd_alt = mavlink_msg_tele_data_get_cmd_alt(msg);
    tele_data->cmd_Vi = mavlink_msg_tele_data_get_cmd_Vi(msg);
    tele_data->cmd_theta = mavlink_msg_tele_data_get_cmd_theta(msg);
    tele_data->cmd_phi = mavlink_msg_tele_data_get_cmd_phi(msg);
    tele_data->cmd_psi = mavlink_msg_tele_data_get_cmd_psi(msg);
    tele_data->cmd_hdot = mavlink_msg_tele_data_get_cmd_hdot(msg);
    tele_data->lawOuput_ele = mavlink_msg_tele_data_get_lawOuput_ele(msg);
    tele_data->lawOuput_ail = mavlink_msg_tele_data_get_lawOuput_ail(msg);
    tele_data->lawOuput_rud = mavlink_msg_tele_data_get_lawOuput_rud(msg);
    tele_data->SCNS_velocity_N = mavlink_msg_tele_data_get_SCNS_velocity_N(msg);
    tele_data->SCNS_velocity_E = mavlink_msg_tele_data_get_SCNS_velocity_E(msg);
    tele_data->SCNS_velocity_U = mavlink_msg_tele_data_get_SCNS_velocity_U(msg);
    tele_data->SCNS_picth = mavlink_msg_tele_data_get_SCNS_picth(msg);
    tele_data->SCNS_roll = mavlink_msg_tele_data_get_SCNS_roll(msg);
    tele_data->SCNS_yaw = mavlink_msg_tele_data_get_SCNS_yaw(msg);
    tele_data->SCNS_rollRate = mavlink_msg_tele_data_get_SCNS_rollRate(msg);
    tele_data->SCNS_pitchRate = mavlink_msg_tele_data_get_SCNS_pitchRate(msg);
    tele_data->SCNS_yawRate = mavlink_msg_tele_data_get_SCNS_yawRate(msg);
    tele_data->SCNS_xAcc = mavlink_msg_tele_data_get_SCNS_xAcc(msg);
    tele_data->SCNS_alt = mavlink_msg_tele_data_get_SCNS_alt(msg);
    tele_data->SCNS_Vg_2D = mavlink_msg_tele_data_get_SCNS_Vg_2D(msg);
    tele_data->intSensor_Eph = mavlink_msg_tele_data_get_intSensor_Eph(msg);
    tele_data->intSensor_Epv = mavlink_msg_tele_data_get_intSensor_Epv(msg);
    tele_data->intSensor_alt_gps = mavlink_msg_tele_data_get_intSensor_alt_gps(msg);
    tele_data->intSensor_Vg_2D = mavlink_msg_tele_data_get_intSensor_Vg_2D(msg);
    tele_data->intSensor_roll = mavlink_msg_tele_data_get_intSensor_roll(msg);
    tele_data->intSensor_pitch = mavlink_msg_tele_data_get_intSensor_pitch(msg);
    tele_data->intSensor_yaw = mavlink_msg_tele_data_get_intSensor_yaw(msg);
    tele_data->intSensor_psiV = mavlink_msg_tele_data_get_intSensor_psiV(msg);
    tele_data->intSensor_rollRate = mavlink_msg_tele_data_get_intSensor_rollRate(msg);
    tele_data->intSensor_pitchRate = mavlink_msg_tele_data_get_intSensor_pitchRate(msg);
    tele_data->intSensor_yawRate = mavlink_msg_tele_data_get_intSensor_yawRate(msg);
    tele_data->intSensor_alt_baro = mavlink_msg_tele_data_get_intSensor_alt_baro(msg);
    tele_data->intSensor_Vi = mavlink_msg_tele_data_get_intSensor_Vi(msg);
    tele_data->pwmOut_ail_L = mavlink_msg_tele_data_get_pwmOut_ail_L(msg);
    tele_data->pwmOut_ail_R = mavlink_msg_tele_data_get_pwmOut_ail_R(msg);
    tele_data->pwmOut_ele_L = mavlink_msg_tele_data_get_pwmOut_ele_L(msg);
    tele_data->pwmOut_ele_R = mavlink_msg_tele_data_get_pwmOut_ele_R(msg);
    tele_data->pwmOut_rud_L = mavlink_msg_tele_data_get_pwmOut_rud_L(msg);
    tele_data->pwmOut_rud_R = mavlink_msg_tele_data_get_pwmOut_rud_R(msg);
    tele_data->pwmOut_thr = mavlink_msg_tele_data_get_pwmOut_thr(msg);
    tele_data->pwmFb_ail_L = mavlink_msg_tele_data_get_pwmFb_ail_L(msg);
    tele_data->pwmFb_ail_R = mavlink_msg_tele_data_get_pwmFb_ail_R(msg);
    tele_data->pwmFb_ele_L = mavlink_msg_tele_data_get_pwmFb_ele_L(msg);
    tele_data->pwmFb_ele_R = mavlink_msg_tele_data_get_pwmFb_ele_R(msg);
    tele_data->pwmFb_rud_L = mavlink_msg_tele_data_get_pwmFb_rud_L(msg);
    tele_data->pwmFb_rud_R = mavlink_msg_tele_data_get_pwmFb_rud_R(msg);
    tele_data->pwmFb_thr = mavlink_msg_tele_data_get_pwmFb_thr(msg);
    tele_data->voltage_power = mavlink_msg_tele_data_get_voltage_power(msg);
    tele_data->DO_status = mavlink_msg_tele_data_get_DO_status(msg);
    tele_data->airlineTrack_dL = mavlink_msg_tele_data_get_airlineTrack_dL(msg);
    tele_data->airlineTrack_dY = mavlink_msg_tele_data_get_airlineTrack_dY(msg);
    tele_data->airlineTrack_dH = mavlink_msg_tele_data_get_airlineTrack_dH(msg);
    tele_data->vehicle_id = mavlink_msg_tele_data_get_vehicle_id(msg);
    tele_data->link_quality = mavlink_msg_tele_data_get_link_quality(msg);
    tele_data->err_rate = mavlink_msg_tele_data_get_err_rate(msg);
    tele_data->endurance_time_min = mavlink_msg_tele_data_get_endurance_time_min(msg);
    tele_data->endurance_distance_km = mavlink_msg_tele_data_get_endurance_distance_km(msg);
    tele_data->year = mavlink_msg_tele_data_get_year(msg);
    tele_data->month = mavlink_msg_tele_data_get_month(msg);
    tele_data->day = mavlink_msg_tele_data_get_day(msg);
    tele_data->hour = mavlink_msg_tele_data_get_hour(msg);
    tele_data->min = mavlink_msg_tele_data_get_min(msg);
    tele_data->sec = mavlink_msg_tele_data_get_sec(msg);
    tele_data->armed = mavlink_msg_tele_data_get_armed(msg);
    tele_data->flight_mode = mavlink_msg_tele_data_get_flight_mode(msg);
    tele_data->fix_mode = mavlink_msg_tele_data_get_fix_mode(msg);
    tele_data->satelliteUse = mavlink_msg_tele_data_get_satelliteUse(msg);
    tele_data->posSrc = mavlink_msg_tele_data_get_posSrc(msg);
    tele_data->altSrc = mavlink_msg_tele_data_get_altSrc(msg);
    tele_data->airSpdSrc = mavlink_msg_tele_data_get_airSpdSrc(msg);
    tele_data->grdSpdSrc = mavlink_msg_tele_data_get_grdSpdSrc(msg);
    tele_data->attSrc = mavlink_msg_tele_data_get_attSrc(msg);
    tele_data->yawSrc = mavlink_msg_tele_data_get_yawSrc(msg);
    tele_data->lawOuput_thr = mavlink_msg_tele_data_get_lawOuput_thr(msg);
    tele_data->SCNS_fault_flag = mavlink_msg_tele_data_get_SCNS_fault_flag(msg);
    tele_data->SCNS_mode = mavlink_msg_tele_data_get_SCNS_mode(msg);
    tele_data->SCNS_fix_status = mavlink_msg_tele_data_get_SCNS_fix_status(msg);
    tele_data->SCNS_PDOP = mavlink_msg_tele_data_get_SCNS_PDOP(msg);
    tele_data->intSensor_fixStatus = mavlink_msg_tele_data_get_intSensor_fixStatus(msg);
    tele_data->intSensor_starUse = mavlink_msg_tele_data_get_intSensor_starUse(msg);
    tele_data->voltage_equip = mavlink_msg_tele_data_get_voltage_equip(msg);
    tele_data->voltage_actuator = mavlink_msg_tele_data_get_voltage_actuator(msg);
    tele_data->DI_status = mavlink_msg_tele_data_get_DI_status(msg);
    tele_data->severity = mavlink_msg_tele_data_get_severity(msg);
    mavlink_msg_tele_data_get_text(msg, tele_data->text);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TELE_DATA_LEN? msg->len : MAVLINK_MSG_ID_TELE_DATA_LEN;
        memset(tele_data, 0, MAVLINK_MSG_ID_TELE_DATA_LEN);
    memcpy(tele_data, _MAV_PAYLOAD(msg), len);
#endif
}
#endif
