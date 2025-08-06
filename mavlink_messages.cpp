#include <stdio.h>
#include <math.h>
#include "mathlib/mathlib.h"
#include "../commander/custom_mode.h"
#include "geo/geo.h"
#include "uORB.h"
#include "topics/sensor_combined.h"
#include "topics/vehicle_gps_position.h"
#include "topics/vehicle_local_position.h"
#include "topics/home_position.h"
#include "topics/vehicle_status.h"
#include "topics/vehicle_command.h"
#include "topics/vehicle_local_position_setpoint.h"
#include "topics/vehicle_vicon_position.h"
#include "topics/vehicle_attitude_setpoint.h"
#include "topics/vehicle_rates_setpoint.h"
#include "topics/position_setpoint_triplet.h"
#include "topics/optical_flow.h"
#include "topics/actuator_outputs.h"
#include "topics/actuator_controls.h"
#include "topics/actuator_controls_0.h"
#include "topics/actuator_controls_1.h"
#include "topics/actuator_controls_2.h"
#include "topics/actuator_armed.h"
#include "topics/manual_control_setpoint.h"
#include "topics/telemetry_status.h"
#include "topics/debug_key_value.h"
#include "topics/airspeed_inside.h"
#include "topics/battery_status.h"
#include "topics/navigation_capabilities.h"
#include "topics/formation_fly_synch_out.h"
#include "topics/formation_fly_leaderStatus_in.h"
#include "topics/formation_fly_leaderStatus_out.h"
#include "topics/formation_fly_tele.h"
#include "topics/servo2gcs.h"
#include "topics/range_finder.h"
#include "topics/input_rc.h"
#include "topics/output_pwm.h"
#include "topics/vehicle_global_position.h"
#include "topics/vehicle_attitude.h"
#include "topics/vehicle_sensor_manage.h"
#include "topics/attitude_estimate.h"
#include "topics/sensor_extIns.h"
#include "topics/control_law_output.h"
#include "topics/control_law_output_mc.h"
#include "topics/ecu_data.h"
#include "topics/cpuload.h"
#include "topics/vehicle_sensor_manage.h"
#include "topics/control_law_theta.h"
#include "topics/control_law_phi.h"
#include "visibility.h"
#include "mavlink/mavlink_log.h"
#include "mavlink_messages.h"
#include "mavlink_main.h"

extern double SCALE32_formula(int x);
extern float SCALE16_formula(int x);
extern float SCALE16U_formula(int x);

static uint16_t cm_uint16_from_m_float(float m);
static void get_mavlink_mode_state(struct vehicle_status_s *status,
	                        struct position_setpoint_triplet_s *pos_sp_triplet,
	                        struct vehicle_attitude_setpoint_s *att_sp,
			                uint8_t *mavlink_state, 
			                uint8_t *mavlink_base_mode, 
			                uint32_t *mavlink_custom_mode);

uint16_t
cm_uint16_from_m_float(float m)
{
	if (m < 0.0f) {
		return 0;

	} else if (m > 655.35f) {
		return 65535;
	}

	return (uint16_t)(m * 100.0f);
}

void get_mavlink_mode_state(struct vehicle_status_s *status,
	                        struct position_setpoint_triplet_s *pos_sp_triplet,
	                        struct vehicle_attitude_setpoint_s *att_sp,
			                uint8_t *mavlink_state, 
			                uint8_t *mavlink_base_mode, 
			                uint32_t *mavlink_custom_mode)
{
	*mavlink_state = 0;
	*mavlink_base_mode = 0;
	*mavlink_custom_mode = 0;
    #if 0    
	/* HIL */
	if (status->hil_state == vehicle_status_s::HIL_STATE_ON) {
		*mavlink_base_mode |= MAV_MODE_FLAG_HIL_ENABLED;
	}

	/* arming state */
	if (status->arming_state == vehicle_status_s::ARMING_STATE_RUN
	    || status->arming_state == vehicle_status_s::ARMING_STATE_ARMED_ERROR) {
		*mavlink_base_mode |= MAV_MODE_FLAG_SAFETY_ARMED;
	}
    #endif
	/* main state */
    /*begin add state by caojiangzhi 2016.5.11 */
    if (status->test_state > 0l)
    {
        *mavlink_base_mode |= MAV_MODE_FLAG_TEST_ENABLED;
    }
    else  /*end add state by caojiangzhi 2016.5.11 */
    	*mavlink_base_mode |= MAV_MODE_FLAG_CUSTOM_MODE_ENABLED;

	union custom_mode custom_mode;
	custom_mode.data = 0;

	switch (status->nav_state) {

	   case vehicle_status_s::NAVIGATION_STATE_MANUAL:
		//	*mavlink_base_mode |= MAV_MODE_FLAG_MANUAL_INPUT_ENABLED
		//	                      | (status->is_rotary_wing ? MAV_MODE_FLAG_STABILIZE_ENABLED : 0);
			custom_mode.main_mode = CUSTOM_MAIN_MODE_MANUAL;		
    		custom_mode.sub_mode = 0;
			break;
            
       case vehicle_status_s::NAVIGATION_STATE_AUTO_MISSION:
		//	*mavlink_base_mode |= MAV_MODE_FLAG_AUTO_ENABLED
		//	                      | MAV_MODE_FLAG_STABILIZE_ENABLED
		//			      | MAV_MODE_FLAG_GUIDED_ENABLED;
			custom_mode.main_mode = CUSTOM_MAIN_MODE_AUTO;
			custom_mode.sub_mode = 0;
   			break;

	  case vehicle_status_s::NAVIGATION_STATE_AUTO_TAKEOFF:
	  	    custom_mode.main_mode = CUSTOM_MAIN_MODE_TAKEOFF;
			custom_mode.sub_mode  = 0;			
   			break;
      case vehicle_status_s::NAVIGATION_STATE_AUTO_LAND:      
            custom_mode.main_mode = CUSTOM_MAIN_MODE_LAND;
      		custom_mode.sub_mode  = 0;			
  			break;
      case vehicle_status_s::NAVIGATION_STATE_AUTO_CONTROL: 
      	  	custom_mode.main_mode = CUSTOM_MAIN_MODE_CONTROL;
      		custom_mode.sub_mode  = status->sub_nav_state;		
   			break;
      case vehicle_status_s::NAVIGATION_STATE_AUTO_LOITER: 	
      		custom_mode.main_mode = CUSTOM_MAIN_MODE_AUTO_LOITER;
      		custom_mode.sub_mode  = 0;			
      		break;
      case vehicle_status_s::NAVIGATION_STATE_AUTO_RETURN_HOME: 	
      		custom_mode.main_mode = CUSTOM_MAIN_MODE_RETURN;
      		custom_mode.sub_mode  = 0;			
       		break;
      case vehicle_status_s::NAVIGATION_STATE_AUTO_POINT_FLY: 
      		custom_mode.main_mode = CUSTOM_MAIN_MODE_POINT;
      		custom_mode.sub_mode  = 0;			
   			break;
      case vehicle_status_s::NAVIGATION_STATE_AUTO_GROUND_READY: 
      		custom_mode.main_mode = CUSTOM_MAIN_MODE_GROUND_READY;
      		custom_mode.sub_mode  = 0;			
   			break;	
      case vehicle_status_s::NAVIGATION_STATE_AUTO_TAKEOFF_STOP: 
      		custom_mode.main_mode = CUSTOM_MAIN_MODE_TAKEOFF_STOP;
      		custom_mode.sub_mode  = 0;			
   			break;
	 case vehicle_status_s::NAVIGATION_STATE_STAB: 
	 case vehicle_status_s::NAVIGATION_STATE_POSITION: 
      		custom_mode.main_mode = CUSTOM_MAIN_MODE_STAB;
      		custom_mode.sub_mode  = 0;			
   			break;
      case vehicle_status_s::NAVIGATION_STATE_AUTO_PRECLAND: 
      		custom_mode.main_mode = CUSTOM_MAIN_MODE_PRECLAND;
      		custom_mode.sub_mode  = 0;			
   			break;
      default:
            custom_mode.main_mode = CUSTOM_MAIN_MODE_UNKNOW;
      		custom_mode.sub_mode  = 0;
      		/* this is an unused case, ignore */
      		break;
      
	}
    /*begin add state by caojiangzhi 2016.5.11 */
    custom_mode.reserved = status->main_state;
    custom_mode.reserved = (custom_mode.reserved << 8) | status->nav_state;
     /*end add state by caojiangzhi 2016.5.11 */
     
	*mavlink_custom_mode = custom_mode.data;
	*mavlink_state = att_sp->bismcctl;
 #if 0
	/* set system state */
	if (status->arming_state == vehicle_status_s::ARMING_STATE_INIT
	    || status->arming_state == vehicle_status_s::ARMING_STATE_IN_AIR_RESTORE
	    || status->arming_state == vehicle_status_s::ARMING_STATE_STANDBY_ERROR) {	// TODO review
		*mavlink_state = MAV_STATE_UNINIT;

	} else if (status->arming_state == vehicle_status_s::ARMING_STATE_RUN) {
		*mavlink_state = MAV_STATE_ACTIVE;

	} else if (status->arming_state == vehicle_status_s::ARMING_STATE_ARMED_ERROR) {
		*mavlink_state = MAV_STATE_CRITICAL;

	} else if (status->arming_state == vehicle_status_s::ARMING_STATE_STANDBY) {
		*mavlink_state = MAV_STATE_STANDBY;

	} else if (status->arming_state == vehicle_status_s::ARMING_STATE_REBOOT) {
		*mavlink_state = MAV_STATE_POWEROFF;

	} else {
		*mavlink_state = MAV_STATE_CRITICAL;
	}
    #endif
}



class MavlinkStreamTeleData : public MavlinkStream
{
public:
	const char *get_name() const
	{
		return MavlinkStreamTeleData::get_name_static();
	}

	static const char *get_name_static()
	{
		return "TELE_DATA";
	}

	uint8_t get_id()
	{
		return MAVLINK_MSG_ID_TELE_DATA;// 156
	}

	static MavlinkStream *new_instance(Mavlink *mavlink)
	{
		return new MavlinkStreamTeleData(mavlink);
	}

	unsigned get_size()
	{
		return MAVLINK_MSG_ID_TELE_DATA_LEN + MAVLINK_NUM_HEADER_BYTES + MAVLINK_NUM_CHECKSUM_BYTES;//fix 256 bytes
	}

private:
	MavlinkOrbSubscription *_vehicle_status_sub;
	uint64_t _vehicle_status_time;

	MavlinkOrbSubscription *_att_sub;
	uint64_t _att_time;

	MavlinkOrbSubscription *_pos_sub;
	uint64_t _pos_time;

	MavlinkOrbSubscription *_gps_sub;
	uint64_t _gps_time;

	MavlinkOrbSubscription *_airspeed_sub;
	uint64_t _airspeed_time;

	MavlinkOrbSubscription *_armed_sub;
	uint64_t _armed_time;

	MavlinkOrbSubscription *_sensor_sub;
	uint64_t _sensor_time;

	MavlinkOrbSubscription *_extIns_sub;
	uint64_t _extIns_time;
	
	MavlinkOrbSubscription *_battery_sta_sub;
	uint64_t _battery_sta_time;

	MavlinkOrbSubscription *_pos_sp_triplet_sub;
	uint64_t _pos_sp_triplet_time;

	MavlinkOrbSubscription *_att_sp_sub;
	uint64_t _att_sp_time;

	MavlinkOrbSubscription *_cmd_sub;
	uint64_t _cmd_time;

	MavlinkOrbSubscription *_ctl_out_sub;
	uint64_t _ctl_out_time;
	
	MavlinkOrbSubscription *_ctl_out_mc_sub;
	uint64_t _ctl_out_mc_time;

	//MavlinkOrbSubscription *_act_fb_sub;
	//uint64_t _act_fb_time;

	MavlinkOrbSubscription *_act_out_sub;
	uint64_t _act_out_time;

	MavlinkOrbSubscription *_home_sub;
	uint64_t _home_time;

	MavlinkOrbSubscription *_sensor_man_sub;
	uint64_t _sensor_man_time;

	MavlinkOrbSubscription *_att_estimate_sub;
	uint64_t _att_estimate_time;
	
	MavlinkOrbSubscription *_cpuload_sub;
	uint64_t _cpuload_time;
	
	MavlinkOrbSubscription *_controlLawPhi_sub;
	uint64_t _controlLawPhi_time;
	
	MavlinkOrbSubscription *_controlLawTheta_sub;
	uint64_t _controlLawTheta_time;

	/* do not allow top copying this class */
	MavlinkStreamTeleData(MavlinkStreamTeleData &);
	MavlinkStreamTeleData& operator = (const MavlinkStreamTeleData &);

	struct vehicle_status_s status;
	struct vehicle_attitude_s att;
	struct vehicle_global_position_s pos;
	struct vehicle_gps_position_s gps;
	struct airspeed_inside_s airspeed;
	struct actuator_armed_s armed;
	struct sensor_combined_s sensor_combined;
	struct position_setpoint_triplet_s pos_sp_triplet;
	struct vehicle_attitude_setpoint_s att_sp;
	struct vehicle_command_s cmd;
	struct actuator_outputs_s act_out;
	struct home_position_s home_pos;
	struct mavlink_logmessage logmsg;
	struct sensor_extIns_s extIns;
	struct battery_status_s battery_sta;
	struct control_law_output_s law_output;
	struct control_law_output_mc_s law_output_mc;
//	struct actuator_feedback_s act_fb;
	struct vehicle_sensor_manage_s sensor_man;
	struct attitude_estimate_s att_estimate;
	struct cpuload_s cpuload;
	struct control_law_theta_s controllaw_theta;
	struct control_law_phi_s controllaw_phi;

protected:
	explicit MavlinkStreamTeleData(Mavlink *mavlink) : MavlinkStream(mavlink),
    	_vehicle_status_sub(),
		_vehicle_status_time(0),
		_att_sub(),
		_att_time(0),
		_pos_sub(),
		_pos_time(0),
		_gps_sub(),
		_gps_time(0),
		_airspeed_sub(),
		_airspeed_time(0),
		_armed_sub(),
		_armed_time(0),
		_sensor_sub(),
		_sensor_time(0),
		_pos_sp_triplet_sub(),
		_pos_sp_triplet_time(0),
		_att_sp_sub(),
		_att_sp_time(0),
		_cmd_sub(),
		_cmd_time(0),
		_act_out_sub(),
		_act_out_time(0),
		_home_sub(),
		_home_time(0),
		_extIns_sub(),
		_extIns_time(0),
		_battery_sta_sub(),
		_battery_sta_time(0),		
		_ctl_out_sub(),
		_ctl_out_time(0),
		_ctl_out_mc_sub(),
		_ctl_out_mc_time(0),		
//		_act_fb_sub(),
//		_act_fb_time(0),
		_sensor_man_sub(),
		_sensor_man_time(0),
		_att_estimate_sub(),
		_att_estimate_time(0),
		_cpuload_sub(),
		_cpuload_time(0),
		_controlLawPhi_sub(),
		_controlLawPhi_time(0),
		_controlLawTheta_sub(),
		_controlLawTheta_time(0),
		status(),
		att(),
		pos(),
		gps(),
		airspeed(),
		armed(),
		sensor_combined(),
		pos_sp_triplet(),
		att_sp(),
		cmd(),
		act_out(),
		home_pos(),
		logmsg(),
		extIns(),
		battery_sta(),
		law_output(),
		law_output_mc(),
//		act_fb(),
		sensor_man(),
		att_estimate(),
		cpuload(),
		controllaw_theta(),
		controllaw_phi()
	{
	}
	
	void subscription()
	{
		static bool subscription = false;
		if(subscription == true)
		{
			return;
		}
		_vehicle_status_sub = _mavlink->add_orb_subscription(ORB_ID(vehicle_status));
		_att_sub = _mavlink->add_orb_subscription(ORB_ID(vehicle_attitude));
		_pos_sub = _mavlink->add_orb_subscription(ORB_ID(vehicle_global_position));	
		_gps_sub = _mavlink->add_orb_subscription(ORB_ID(vehicle_gps_position));
		_airspeed_sub = _mavlink->add_orb_subscription(ORB_ID(airspeed_inside));
		_armed_sub = _mavlink->add_orb_subscription(ORB_ID(actuator_armed));
		_sensor_sub = _mavlink->add_orb_subscription(ORB_ID(sensor_combined));
		_pos_sp_triplet_sub = _mavlink->add_orb_subscription(ORB_ID(position_setpoint_triplet));
		_att_sp_sub = _mavlink->add_orb_subscription(ORB_ID(vehicle_attitude_setpoint));
		_cmd_sub = _mavlink->add_orb_subscription(ORB_ID(vehicle_command));
		_act_out_sub = _mavlink->add_orb_subscription(ORB_ID(actuator_outputs));
		_home_sub = _mavlink->add_orb_subscription(ORB_ID(home_position));
		_extIns_sub = _mavlink->add_orb_subscription(ORB_ID(sensor_extIns));
		_battery_sta_sub = _mavlink->add_orb_subscription(ORB_ID(battery_status));
		_ctl_out_sub = _mavlink->add_orb_subscription(ORB_ID(control_law_output));
		_ctl_out_mc_sub = _mavlink->add_orb_subscription(ORB_ID(control_law_output_mc));
		//_act_fb_sub = _mavlink->add_orb_subscription(ORB_ID(actuator_feedback));
		_sensor_man_sub = _mavlink->add_orb_subscription(ORB_ID(vehicle_sensor_manage));
		_att_estimate_sub = _mavlink->add_orb_subscription(ORB_ID(attitude_estimate));
		_cpuload_sub = _mavlink->add_orb_subscription(ORB_ID(cpuload));
		_controlLawPhi_sub = _mavlink->add_orb_subscription(ORB_ID(control_law_phi));
		_controlLawTheta_sub = _mavlink->add_orb_subscription(ORB_ID(control_law_theta));
		subscription = true;
	}
	
	void send(const hrt_abstime t)
	{ 
		subscription();
		
		bool updated = false;
		updated |= _vehicle_status_sub->update(&_vehicle_status_time,&status);
		updated |= _att_sub->update(&_att_time,&att);
		updated |= _pos_sub->update(&_pos_time,&pos);		
		updated |= _gps_sub->update(&_gps_time,&gps);
		updated |= _airspeed_sub->update(&_airspeed_time,&airspeed);
		updated |= _sensor_sub->update(&_sensor_time,&sensor_combined);
		updated |= _att_sp_sub->update(&_att_sp_time,&att_sp);
		updated |= _act_out_sub->update(&_act_out_time,&act_out);
		updated |= _home_sub->update(&_home_time,&home_pos);
		updated |= _ctl_out_sub->update(&_ctl_out_time,&law_output);
		updated |= _ctl_out_mc_sub->update(&_ctl_out_mc_time,&law_output_mc);	
		updated |= !mavlink_logbuffer_is_empty(_mavlink->get_logbuffer());


		/*这些orb消息未使用*/
		updated |= _armed_sub->update(&_armed_time,&armed);
		updated |= _cmd_sub->update(&_cmd_time,&cmd);
		updated |= _pos_sp_triplet_sub->update(&_pos_sp_triplet_time,&pos_sp_triplet);
		updated |= _sensor_man_sub->update(&_sensor_man_time,&sensor_man);	
		updated |= _extIns_sub->update(&_extIns_time,&extIns);
		updated |= _battery_sta_sub->update(&_battery_sta_time,&battery_sta);		
//		updated |= _act_fb_sub->update(&_act_fb_time,&act_fb);
		updated |= _att_estimate_sub->update(&_att_estimate_time,&att_estimate);
		updated |= _cpuload_sub->update(&_cpuload_time,&cpuload);
		updated |= _controlLawPhi_sub->update(&_controlLawPhi_time,&controllaw_phi);
		updated |= _controlLawTheta_sub->update(&_controlLawTheta_time,&controllaw_theta);

	
	#if 0
		if(updated)
		{
			static int cnt = 0;
			cnt++;
			if(cnt%100 == 0)
			{
				/*
				printf_vx("vehicle_id = %d\t",status.vehicle_id);
				printf_vx("flight_time = %d\t",status.flight_time);
				printf_vx("armed = %d\t",status.arming_state);
				printf_vx("flight_mode = %d\n",status.nav_state);
				*/
				printf_vx("MAVLINK:vx-vy[%.1f|%.1f]\n",att_sp.vx_cmd_var,att_sp.vy_cmd_var);
				
			}
		}
	#endif
		

		
		if(updated)
		{
			mavlink_tele_data_t msg;

			/*system status*/
			memset(&msg, 0, sizeof(msg));
			
			time_t current_time = time(NULL); 
			struct tm *local_time = localtime(&current_time);

			/* 系统状态 */
			msg.vehicle_id = status.vehicle_id;
			msg.flight_time_sec = status.flight_time;
			msg.endurance_time_min = status.endurance_time_min;
			msg.endurance_distance_km = status.endurance_distance_km;
			msg.distance2Home = status.distance2Home_m;
			msg.year = local_time->tm_year + 1900 -2020; //TODO:start 2020 
			// msg.month = local_time->tm_mon + 1;
			// msg.day = local_time->tm_mday;
			// msg.hour = local_time->tm_hour;
			// msg.min = local_time->tm_min;
			// msg.sec = local_time->tm_sec;

			msg.year = status.year; //TODO:start 2020 
			msg.month = status.mon;
			msg.day = status.day;
			msg.hour = status.hour;
			msg.min = status.min;
			msg.sec = status.sec;

			msg.armed = status.arming_state;//TODO
			msg.flight_mode = status.nav_state;
			msg.flight_state = status.vehicle_wing_state;

			/* 姿态数据 */
			msg.pitch =  (att.pitch*M_RAD_TO_DEG_F*32767/90);
			msg.roll =  (att.roll*M_RAD_TO_DEG_F*32767/180);
			msg.yaw =  (_wrap_2pi(att.yaw)*M_RAD_TO_DEG_F*65535/360);

			/* gnss */
			msg.satelliteUse = gps.satellites_used;
			msg.fix_mode = gps.fix_type;

			/*global position*/
			msg.psiV =  (pos.yaw*M_RAD_TO_DEG_F*32767/180);
			msg.lon =  (pos.lon*(double)((pow(2,31)-1.0f)/180.0f));
			msg.lat =  (pos.lat*(double)((pow(2,31)-1.0f)/90.0f));
			msg.alt =  ((pos.alt+500.0f)*65535/10500);
			msg.alt_relative =  ((pos.alt-home_pos.alt+500.0f)*65535/10500);
			msg.Vg =  (sqrt(pos.vel_n*pos.vel_n + pos.vel_e*pos.vel_e)*10.0f);
			msg.hdot =  (pos.vel_d * -10.0f);
			msg.Vi =  (airspeed.indicated_airspeed_m_s*10.0f);
			msg.Vx =  (pos.Vx*10.0f);
			msg.Vy =  (pos.Vy*10.0f);

			/* 期望姿态       *********  待飞距、侧偏距、高度差*/
			msg.cmd_alt = ((att_sp.altitude+500)*65535/10500);
			msg.cmd_Vi = (att_sp.Vi*10.0f);
			if(vehicle_status_s::VEHICLE_WING_STATE_FW == status.vehicle_wing_state)
			{
				msg.cmd_theta =(controllaw_theta.theta_cmd_phi*32767/90);
				msg.cmd_phi = (controllaw_phi.phi_cmd*32767/180);
			}
			else
			{
				msg.cmd_theta =(att_sp.pitch_body*M_RAD_TO_DEG_F*32767/90);
				msg.cmd_phi = (att_sp.roll_body*M_RAD_TO_DEG_F*32767/180);
			}

			msg.cmd_psi = (_wrap_2pi(att_sp.yaw_body)*M_RAD_TO_DEG_F*65535/360);
			msg.cmd_hdot = (att_sp.ve_z*10.0f*-1.0f);	//ve_z下为正,转为上为正发送至GCS
			msg.cmd_Vx = (att_sp.vx_cmd_var*10.0f);
			msg.cmd_Vy = (att_sp.vy_cmd_var*10.0f);
			msg.airlineTrack_dL = att_sp.lineTrack_dL;
			msg.airlineTrack_dY = att_sp.lineTrack_dY;
			msg.airlineTrack_dH = (pos.alt - att_sp.altitude);

			/* home点坐标 */
			msg.homePos_lat = (home_pos.lat*(double)((pow(2,31)-1.0f)/90.0f));
			msg.homePos_lon = (home_pos.lon*(double)((pow(2,31)-1.0f)/180.0f));
			msg.homePos_alt = ((home_pos.alt+500.0f)*65535.0f/10500.0f);

			/* internal sensor */
			msg.intSensor_fixStatus = gps.fix_type;
			msg.intSensor_starUse = gps.satellites_used;
			msg.intSensor_Eph =  (gps.eph*10.0f);
			msg.intSensor_Epv =  (gps.epv*10.0f);
			msg.intSensor_lon_gps =  (gps.lon/1e7*(double)((pow(2,31)-1)/180));
			msg.intSensor_lat_gps =  (gps.lat/1e7*(double)((pow(2,31)-1)/90));
			msg.intSensor_alt_gps =  ((gps.alt/1000+500.0f)*65535/10500);
			msg.intSensor_Vg_2D =  (sqrt(gps.vel_n_m_s*gps.vel_n_m_s+gps.vel_e_m_s*gps.vel_e_m_s)*10.0f);
			msg.intSensor_roll =  (att_estimate.roll*M_RAD_TO_DEG_F*32767/180);
			msg.intSensor_pitch =  (att_estimate.pitch*M_RAD_TO_DEG_F*32767/90);
			msg.intSensor_yaw =  (_wrap_2pi(att_estimate.yaw)*M_RAD_TO_DEG_F*65535/360);
			msg.intSensor_rollRate =  (att_estimate.rollspeed*M_RAD_TO_DEG_F*10.0f);
			msg.intSensor_pitchRate =  (att_estimate.pitchspeed*M_RAD_TO_DEG_F*10.0f);
			msg.intSensor_yawRate =  (att_estimate.yawspeed*M_RAD_TO_DEG_F*10.0f);
			msg.intSensor_Vi = (airspeed.indicated_airspeed_m_s*10.0f);
			/*baro alt*/
			msg.intSensor_alt_baro =  (((uint16_t)(sensor_combined.baro_alt_meter+500))*65535/10500);
			
			msg.posSrc = sensor_man.srcInuse_pos;
			msg.altSrc = sensor_man.srcInuse_height;
			msg.airSpdSrc = sensor_man.srcInuse_airSpd;
			msg.grdSpdSrc = sensor_man.srcInuse_grdSpd;
			msg.attSrc = sensor_man.srcInuse_att;
			msg.yawSrc = sensor_man.srcInuse_heading; //sensor_man.srcInuse_heading; //TODO:java地面站显示有问题，可能是协议未适配，暂时这样处理
			
			/*control law output*/
			msg.lawOuput_ele = (law_output.fw_law_ele_deg*10.0f);
			msg.lawOuput_ail = (law_output.fw_law_ail_deg*10.0f);
			msg.lawOuput_rud = (law_output.fw_law_rud_deg*10.0f);
			msg.lawOuput_thr = (law_output.fw_law_thr_deg*100.0f);	
			
			/*control law output mc*/
			msg.lawOuput_F_thrust = (law_output_mc.F_thrust*100.0f);
			msg.lawOuput_M_Roll = (law_output_mc.M_Roll*100.0f);
			msg.lawOuput_M_Pitch = (law_output_mc.M_Pitch*100.0f);
			msg.lawOuput_M_Yaw = (law_output_mc.M_Yaw*100.0f);	
			
	//		printf_vx("ele = %d	ail = %d	rud = %d	thr = %d\n",msg.lawOuput_ele,msg.lawOuput_ail,msg.lawOuput_rud,msg.lawOuput_thr);	
			//msg.link_quality = 0;//TODO
			//msg.err_rate = 0;//TODO

			/* SCNS_W27 */
			//msg.SCNS_fault_flag = extIns.SCNS_fault_mark;
			msg.SCNS_fix_status = extIns.gps_status;
			msg.SCNS_mode = extIns.nav_status;
			msg.SCNS_PDOP = extIns.rawGps_starUsed*10;
			msg.SCNS_velocity_N = extIns.velocity_N*10.0f;
			msg.SCNS_velocity_E = extIns.velocity_E*10.0f;
			msg.SCNS_velocity_U = extIns.velocity_D*-10.0f;
			msg.SCNS_picth = extIns.pitch*M_RAD_TO_DEG_F*32767/90;
			msg.SCNS_roll = extIns.roll*M_RAD_TO_DEG_F*32767/180;
			msg.SCNS_yaw = _wrap_2pi(extIns.yaw)*M_RAD_TO_DEG_F*65535/360;
			msg.SCNS_rollRate = extIns.rollSpeed*M_RAD_TO_DEG_F*10.0f;
			msg.SCNS_pitchRate = extIns.pitchSpeed*M_RAD_TO_DEG_F*10.0f;
			msg.SCNS_yawRate = extIns.yawSpeed*M_RAD_TO_DEG_F*10.0f;
			msg.SCNS_xAcc = extIns.xAcc*10.0f;//extIns.xAcc*10.0f;
			msg.SCNS_yAcc = extIns.yAcc*10.0f;//extIns.yAcc*10.0f;
			msg.SCNS_zAcc = extIns.zAcc*10.0f;//extIns.zAcc*10.0f;
			msg.SCNS_lon = (double)extIns.longitude/1e7*(double)((pow(2,31)-1.0f)/180.0f);
			msg.SCNS_lat = (double)extIns.latitude/1e7*(double)((pow(2,31)-1.0f)/90.0f);
			msg.SCNS_alt =  (extIns.altitude+500.0f)*65535/10500;
			msg.SCNS_Vg_2D = sqrt(extIns.velocity_N*extIns.velocity_N+extIns.velocity_E*extIns.velocity_E)*10.0f;

			/* Voltage  */
			msg.voltage_power = battery_sta.power_voltage_filtered_v*10.0f;//104.0f*10.f;
			msg.voltage_equip = battery_sta.voltage_filtered_v*255.0f/30.0f;//24.0f*255.0f/30.0f;
			msg.voltage_actuator = battery_sta.actuator_voltage_filtered_v*255.0f/30.0f;//12.0f*255.0f/30.0f;
			msg.voltage_tether = 99*255.0f/30.0f;//12.0f*255.0f/30.0f;
			msg.current_tether = 99*255.0f/30.0f;//12.0f*255.0f/30.0f;
			msg.power_alarm = status.power_alarm;
			
			msg.cpuload_0 = cpuload.load_0;
			msg.cpuload_1 = cpuload.load_1;
		#if 0
			/* pwm/rotary/angle  feedback */
			msg.actFb_1 = pulse_input.input1;
			msg.actFb_2 = pulse_input.input2;
			msg.actFb_3 = pulse_input.input3;
			msg.actFb_4 = pulse_input.input4;
			msg.actFb_5 = pulse_input.input5;
			msg.actFb_6 = pulse_input.input6;
			msg.actFb_7 = pulse_input.input7;
			msg.actFb_8 = pulse_input.input8;
			msg.actFb_9 = pulse_input.input9;
			msg.actFb_10 = pulse_input.input10;
			msg.actFb_11 = pulse_input.input11;
			msg.actFb_12 = pulse_input.input12;
			msg.actFb_13 = pulse_input.input13;
			msg.actFb_14 = pulse_input.input14;
			msg.actFb_15 = pulse_input.input15;
			msg.actFb_16 = pulse_input.input16;
			msg.motor_alarm = 0xFF;
		#else
			/* pwm  output */
			msg.actFb_1 = act_out.output[0];
			msg.actFb_2 = act_out.output[1];
			msg.actFb_3 = act_out.output[2];
			msg.actFb_4 = act_out.output[3];
			msg.actFb_5 = act_out.output[4];
			msg.actFb_6 = act_out.output[5];
			msg.actFb_7 = act_out.output[6];
			msg.actFb_8 = act_out.output[7];
			msg.actFb_9 = act_out.output[8];
			msg.actFb_10 = act_out.output[9];
			msg.actFb_11 = act_out.output[10];
			msg.actFb_12 = act_out.output[11];
			msg.actFb_13 = act_out.output[12];
			msg.actFb_14 = act_out.output[13];
			msg.actFb_15 = act_out.output[14];
			msg.actFb_16 = act_out.output[15];
			msg.motor_alarm = 0;
		#endif



			/* status text */
			if(!mavlink_logbuffer_is_empty(_mavlink->get_logbuffer()))
			{
				mavlink_logbuffer_read(_mavlink->get_logbuffer(),&logmsg);
			}
			
			//msg.severity = logmsg.severity;
			strncpy(msg.text,logmsg.text,sizeof(msg.text));

			_mavlink->send_message(MAVLINK_MSG_ID_TELE_DATA,&msg);
			
		}
	}
};

class MavlinkStreamSysStatus : public MavlinkStream
{
public:
	const char *get_name() const
	{
		return MavlinkStreamSysStatus::get_name_static();
	}

	static const char *get_name_static()
	{
		return "SYS_STATUS";
	}

	uint8_t get_id()
	{
		return MAVLINK_MSG_ID_SYS_STATUS;
	}

	static MavlinkStream *new_instance(Mavlink *mavlink)
	{
		return new MavlinkStreamSysStatus(mavlink);
	}

	unsigned get_size()
	{
		return MAVLINK_MSG_ID_SYS_STATUS_LEN + MAVLINK_NUM_HEADER_BYTES + MAVLINK_NUM_CHECKSUM_BYTES;//fix 256 bytes
	}

private:
	MavlinkOrbSubscription *_ecu_data_sub;
	MavlinkOrbSubscription *_act_out_sub;
	MavlinkOrbSubscription *_v_sensor_manage_sub;
	uint64_t _ecu_data_time;
	uint64_t _act_data_time;
	uint64_t _v_sensor_manage_time;

	/* do not allow top copying this class */
	MavlinkStreamSysStatus(MavlinkStreamSysStatus &);
	MavlinkStreamSysStatus& operator = (const MavlinkStreamSysStatus &);

	struct ecu_data_s ecu_data;
	struct actuator_outputs_s act_output;
	struct vehicle_sensor_manage_s v_sensor_manage;
	// 位操作函数
	void byte_bit_operations(uint8_t &byte, int bit_position, bool set_bit) {
		if (bit_position < 0 || bit_position >= 8) {
			warn_vx("Invalid bit position!");
			return;
		}

		if (set_bit) {
			// 设置位
			byte |= (1 << bit_position);
		} else {
			// 清除位
			byte &= ~(1 << bit_position);
		}
	}

protected:
	explicit MavlinkStreamSysStatus(Mavlink *mavlink) : MavlinkStream(mavlink),
    	_ecu_data_sub(),
		_act_out_sub(),
		_ecu_data_time(0),
		ecu_data(),
		_v_sensor_manage_time(0)
	{
	}
	
	void subscription()
	{
		static bool subscription = false;
		if(subscription == true)
		{
			return;
		}
		_ecu_data_sub = _mavlink->add_orb_subscription(ORB_ID(ecu_data));
		_act_out_sub = _mavlink->add_orb_subscription(ORB_ID(actuator_outputs));
		_v_sensor_manage_sub = _mavlink->add_orb_subscription(ORB_ID(vehicle_sensor_manage));
		subscription = true;
	}

	void send(const hrt_abstime t)
	{ 
		bool updated = false;
		bool ins_valid = false;
		bool ecu_valid = false;
		bool rc_valid = false;
		bool gps_valid = false;
		bool fc_voltage_valid = false;
		bool power_voltage_valid = false;
		bool airspeed_valid = false;

		bool ins_i_att = false;
		bool ins_i_yaw = false;
		bool ins_i_vel = false;
		bool ins_i_pos = false;

		bool ins_x_att = false;
		bool ins_x_yaw = false;
		bool ins_x_vel = false;
		bool ins_x_pos = false;
		
		subscription();
		
		updated |= _ecu_data_sub->update(&_ecu_data_time,&ecu_data);
		updated |= _act_out_sub->update(&_act_data_time,&act_output);
		updated |= _v_sensor_manage_sub->update(&_v_sensor_manage_time,&v_sensor_manage);

		if(updated)
		{
			mavlink_sys_status_t msg;
			memset(&msg, 0, sizeof(msg));
			ins_i_att = (bool)v_sensor_manage.sensorValid_interINS_ATT;
			ins_x_att = (bool)v_sensor_manage.sensorValid_extINS_ATT;
			ins_i_vel = (bool)v_sensor_manage.sensorValid_interGNSS;
			ins_x_vel = (bool)v_sensor_manage.sensorValid_extGNSS;
			ins_i_pos = (bool)v_sensor_manage.sensorValid_interGNSS;
			ins_x_pos = (bool)v_sensor_manage.sensorValid_extGNSS;
			ecu_valid = (bool)v_sensor_manage.sensorValid_ecu;
			airspeed_valid = (bool)v_sensor_manage.sensorValid_interBaro_Vi;
			ins_valid = (bool)v_sensor_manage.sensorValid_extINS_NAV;
			
			fc_voltage_valid = (bool)v_sensor_manage.sensorValid_bat; 
			power_voltage_valid = (bool)v_sensor_manage.sensorValid_power_bat;
			rc_valid = (bool)v_sensor_manage.sensorValid_rc;

			/* ecu状态 */
			msg.oil_consume_current = ecu_data.oil_consume_current*(double)((pow(2,16)-1.0f)/120000.0f);	
			msg.engine_speed = ecu_data.engine_speed;
			msg.cylinder_temp1 = ecu_data.cylinder_temp1;
			msg.cylinder_temp2 = ecu_data.cylinder_temp2;
			msg.cylinder_temp3 = ecu_data.cylinder_temp3;
			msg.cylinder_temp4 = ecu_data.cylinder_temp4;
			msg.exhaust_temp1 = ecu_data.exhaust_temp1;
			msg.exhaust_temp2 = ecu_data.exhaust_temp2;
			msg.exhaust_temp3 = ecu_data.exhaust_temp3;
			msg.exhaust_temp4 = ecu_data.exhaust_temp4;
			msg.intake_temp = ecu_data.intake_temp;
			msg.thrAngle_offset = ecu_data.thrAngle_offset*(double)((pow(2,7)-1.0f)/60.0f);
			msg.engine_status = ecu_data.engine_status;
			msg.oil_consumption_rate = ecu_data.oil_consumption_rate*10.0f;
			msg.oil_lowPress_sp = ecu_data.oil_lowPress_sp*(double)((pow(2,8)-1.0f)/400.0f);
			msg.oil_lowPress = ecu_data.oil_lowPress*(double)((pow(2,8)-1.0f)/400.0f);
			msg.oil_railPress_sp = ecu_data.oil_railPress_sp;
			msg.oil_railPress = ecu_data.oil_railPress;
			msg.thrAngle = ecu_data.thrAngle*(double)((pow(2,8)-1.0f)/120.0f);
			msg.voltage_sys = ecu_data.voltage_sys*(double)((pow(2,8)-1.0f)/25.0f);
			msg.fault_status1 = ecu_data.fault_status1;
			msg.fault_status2 = ecu_data.fault_status2;
			msg.fault_status3 = ecu_data.fault_status3;
			msg.fault_status4 = ecu_data.fault_status4;
			msg.fault_status5 = ecu_data.fault_status5;
			msg.fault_status6 = ecu_data.fault_status6;
			msg.fault_status7 = ecu_data.fault_status7;
			msg.fault_status8 = ecu_data.fault_status8;

			byte_bit_operations(msg.health_dev, 0, act_output.motor_kill);
			byte_bit_operations(msg.health_dev, 1, ins_valid);
			byte_bit_operations(msg.health_dev, 2, ecu_valid);
			byte_bit_operations(msg.health_dev, 3, rc_valid);
			byte_bit_operations(msg.health_dev, 4, gps_valid);
			byte_bit_operations(msg.health_dev, 5, fc_voltage_valid);
			byte_bit_operations(msg.health_dev, 6, power_voltage_valid);
			byte_bit_operations(msg.health_dev, 7, airspeed_valid);

			byte_bit_operations(msg.health_ins, 0, ins_i_att);
			byte_bit_operations(msg.health_ins, 1, ins_i_yaw);
			byte_bit_operations(msg.health_ins, 2, ins_i_vel);
			byte_bit_operations(msg.health_ins, 3, ins_i_pos);
			byte_bit_operations(msg.health_ins, 4, ins_x_att);
			byte_bit_operations(msg.health_ins, 5, ins_x_yaw);
			byte_bit_operations(msg.health_ins, 6, ins_x_vel);
			byte_bit_operations(msg.health_ins, 7, ins_x_pos);
			
			_mavlink->send_message(MAVLINK_MSG_ID_SYS_STATUS,&msg);
		}
	}
};

const StreamListItem *streams_list[] = {
	new StreamListItem(&MavlinkStreamSysStatus::new_instance,&MavlinkStreamSysStatus::get_name_static),
	new StreamListItem(&MavlinkStreamTeleData::new_instance,&MavlinkStreamTeleData::get_name_static),
	nullptr
};
