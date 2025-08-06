//#include <crc32.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>

#include "mavlink_rtk.h"
#include "mavlink_main.h"

bool rtk_send_flag;
static gps_inject_data_s g_rtcm_inject_data = {0};/*chj:用了全局变量，记住可不能让飞控接收多个地面站传来的差分信号啊，不然就乱了*/


MavlinkRTK::MavlinkRTK(Mavlink* mavlink)
:MavlinkStream(mavlink),
_rtcm_topic(nullptr)
{
	
}


MavlinkRTK::~MavlinkRTK()
{

}

const char*
MavlinkRTK::get_name(void) const
{
	return "MAVLINK_RTK";
}
uint8_t
MavlinkRTK::get_id(void)
{
	return 0;
}

unsigned
MavlinkRTK::get_size(void)
{
	return 0;
}

void 
MavlinkRTK::send(const hrt_abstime t) 
{

}


MavlinkStream*
MavlinkRTK::new_instance(Mavlink *mavlink)
{
	return new MavlinkRTK(mavlink);
}
void
MavlinkRTK::handle_message(const mavlink_message_t *msg)
{
	switch (msg->msgid) 
    {
    	case MAVLINK_MSG_ID_GPS_INJECT_DATA: 
        {
			mavlink_gps_inject_data_t _mavlink_gps_inject_data;
			memcpy(&_mavlink_gps_inject_data, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_GPS_INJECT_DATA_LEN);
			#if 0
			warnx("GOT A Mavlink RTK MESSAGE");
			//warnx("length=%d",_mavlink_gps_inject_data.len);
			#endif

			/*一个文件描述符只能在一个任务中使用，所以uart的描述符只能在gps驱动中使用，所以用orb将修正电文传给gps驱动*/
			memcpy(&g_rtcm_inject_data.data,_mavlink_gps_inject_data.data,_mavlink_gps_inject_data.len);
			g_rtcm_inject_data.len = _mavlink_gps_inject_data.len;
			g_rtcm_inject_data.heart_beat++;
			g_rtcm_inject_data.timestamp = hrt_absolute_time();

			if(_rtcm_topic != nullptr)
			{
				orb_publish(ORB_ID(gps_inject_data), _rtcm_topic, &g_rtcm_inject_data);
			}
			else
			{
				_rtcm_topic = orb_advertise(ORB_ID(gps_inject_data), &g_rtcm_inject_data);
			}
		}
		break;
	}
}
