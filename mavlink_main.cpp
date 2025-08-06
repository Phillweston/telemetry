#include <vxWorks.h>
#include <stdio.h>
#include <string.h>
#include <iosLib.h>
#include <logLib.h>
#include <sioLib.h>
#include <sysLib.h>
#include <stdlib.h>
#include <timerLib.h>
#include <kernelLib.h>
#include <math.h>
#include <subsys/timer/vxbTimerLib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <assert.h>
#include <ioLib.h>
#include <pipeDrv.h>
#include <usrFsLib.h>
#include <time.h>
#include <math.h> 
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "hrt/hrt.h"
#include "uthash/utlist.h"
#include "perf_counter.h"
#include "geo/geo.h"
#include "../dataman/dataman.h"
#include "mathlib/mathlib.h"
#include "mavlink/mavlink_log.h"
#include "mavlink_bridge_header.h"
#include "mavlink_main.h"
#include "mavlink_messages.h"
#include "mavlink_receiver.h"
#include "mavlink_rate_limiter.h"
#include "uORB.h"
#include "task_priority.h"

#ifndef MAVLINK_CRC_EXTRA
#error MAVLINK_CRC_EXTRA has to be defined on PX4 systems
#endif

#define MAVLINK_MAIN_ERR(s, ...)		{printf(s, ## __VA_ARGS__);}
#define MAVLINK_MAIN_WARN(s, ...)		{printf(s, ## __VA_ARGS__);}
#define MAVLINK_MAIN_DEBUG(s, ...)		{printf(s, ## __VA_ARGS__);}

/* oddly, ERROR is not defined for c++ */
#ifdef ERROR
#undef ERROR
#endif
static const int ERROR = -1;

#define DEFAULT_DEVICE_NAME			"/tyCo/0"	
#define MAX_DATA_RATE				1000000	///< max data rate in bytes/s
#define MAIN_LOOP_DELAY 			10000	///< 100 Hz @ 1000 bytes/s data rate
#define FLOW_CONTROL_DISABLE_THRESHOLD		40	///< picked so that some messages still would fit it.

#define mav_floatThreshold  1e-3

//#define MAVLINK_UDP

static Mavlink *_mavlink_instances = nullptr;

/* TODO: if this is a class member it crashes */
//static struct file_operations fops;

static const uint8_t mavlink_message_lengths[256] = MAVLINK_MESSAGE_LENGTHS;
static const uint8_t mavlink_message_crcs[256] = MAVLINK_MESSAGE_CRCS;


static uint32_t temp_bound = 57600;


//extern struct log_MAV_s	userSdLog_mav;


mavlink_system_t mavlink_system = {
	100,
	50
}; // System ID, 1-255, Component/Subsystem ID, 1-255

/*
 * Internal function to give access to the channel status for each channel
 */
mavlink_status_t m_mavlink_status[MAVLINK_COMM_NUM_BUFFERS];
mavlink_status_t *mavlink_get_channel_status(uint8_t channel)
{
	
	return &m_mavlink_status[channel];
}

/*
 * Internal function to give access to the channel buffer for each channel
 */
mavlink_message_t m_mavlink_buffer[MAVLINK_COMM_NUM_BUFFERS];
mavlink_message_t *mavlink_get_channel_buffer(uint8_t channel)
{
	
	return &m_mavlink_buffer[channel];
}


/**
 * mavlink app start / stop handling function
 *
 * @ingroup apps
 */

//extern mavlink_system_t mavlink_system;

static void usage(void);

bool Mavlink::_boot_complete = false;

Mavlink::Mavlink():
	_device_name( (char*)DEFAULT_DEVICE_NAME),
	_device_name_bak( (char*)DEFAULT_DEVICE_NAME),
	_task_should_exit(false),
	_last_msg_seq(0xffff),
	next(nullptr),
	_instance_id(0),
	_task_running(false),
	_hil_enabled(false),
	_generate_rc(false),
	_is_dmu_uart(true), //设置使用内置电台or指定串口标志
	_wait_to_transmit(false),
	_received_messages(false),
	_main_loop_delay(1000),
	_subscriptions(nullptr),
	_streams(nullptr),
	_mission_manager(nullptr),
	_parameters_manager(nullptr),
	_mavlink_rtk(nullptr),
	_mode(MAVLINK_MODE_NORMAL),
	_channel(MAVLINK_COMM_0),
	_radio_id(0),
	_logbuffer {},
	_total_counter(0),
	_receive_thread {},
	_verbose(false),
	_forwarding_on(false),
	_passing_on(false),
	_ftp_on(false),
	_uart_fd(-1),
	_uart_fd_backup(-1),
	_baudrate(57600),
	_socket(-1),
	udp_port(7000),
	_datarate(1000),
	_datarate_events(500),
	_rate_mult(1.0f),
	_last_hw_rate_timestamp(0),
	_mavlink_param_queue_index(0),
	mavlink_link_termination_allowed(false),
	_subscribe_to_stream(nullptr),
	_subscribe_to_stream_rate(0.0f),
	_flow_control_enabled(true),
	_last_write_success_time(0),
	_last_write_try_time(0),
	_bytes_tx(0),
	_bytes_txerr(0),
	_bytes_rx(0),
	_msgs_rx(0),
	_msgs_rxCrcFail(0),
	_rec_msgs_rx(0),
	_rec_msgs_rxCrcFail(0),
	_lost_msgs_rx(0),
	_rec_lost_msgs_rx(0),
	_bytes_timestamp(0),
	_msgs_timestamp(0),
	_rate_tx(0.0f),
	_rate_txerr(0.0f),
	_rate_rx(0.0f),
	_rate_rx_lost_msgs(0.0f),
	_rate_rx_msgs(0.0f),
	_rstatus {},
	_message_buffer {},
	_message_buffer_mutex {},
	_send_mutex {},
	_param_initialized(false),
	_param_system_id(0),
	_param_component_id(0),
	_param_radio_id(0),
	_param_system_type(MAV_TYPE_FIXED_WING),
	_param_vehicle_type(0),
	_param_soft_mult_rate(0),
	_param_teleRateMulti(0),
	_param_teleMinimum(0),
	_soft_mult_rate(1.0f),
	_teleRateMulti(1.0f),	
	_teleMinimum(0),
	_system_type(0),
	_handle_link_0_ip_3(0),
	_handle_link_0_ip_4(0),
	_link_0_ip_3(0),
	_link_0_ip_4(0)
{

	_instance_id = Mavlink::instance_count();

	/* set channel according to instance id */
	switch (_instance_id) {
	case 0:
		_channel = MAVLINK_COMM_0;
		break;

	case 1:
		_channel = MAVLINK_COMM_1;
		break;

	case 2:
		_channel = MAVLINK_COMM_2;
		break;

	case 3:
		_channel = MAVLINK_COMM_3;
		break;

	case 4:
		_channel = MAVLINK_COMM_4;
		break;

	case 5:
		_channel = MAVLINK_COMM_5;
		break;

	case 6:
		_channel = MAVLINK_COMM_6;
		break;

	default:
		MAVLINK_MAIN_ERR("[MAVLINK] instance ID[%d] is out of range\n", _channel);
		break;
	}

	_rstatus.type = TELEMETRY_STATUS_RADIO_TYPE_GENERIC;

	_handle_link_0_ip_3 = param_find("LINK_0_IP_3");
	_handle_link_0_ip_4 = param_find("LINK_0_IP_4");
	param_get(_handle_link_0_ip_3, &_link_0_ip_3);
	param_get(_handle_link_0_ip_4, &_link_0_ip_4);
}

Mavlink::~Mavlink()
{
	if (_task_running) {
		/* task wakes up every 10ms or so at the longest */
		_task_should_exit = true;

		/* wait for a second for the task to quit at our request */
		unsigned i = 0;

		do {
			/* wait 20ms */
			taskDelay(20);

			/* if we have given up, kill it */
			if (++i > 50) {
				//TODO store main task handle in Mavlink instance to allow killing task
				//task_delete(_mavlink_task);
				break;
			}
		} while (_task_running);
	}

	if (_mavlink_instances) {
		LL_DELETE(_mavlink_instances, this);
	}
}

void
Mavlink::count_txerr()
{
	//sperf_count(_txerr_perf);
}

void
Mavlink::set_mode(enum MAVLINK_MODE mode)
{
	_mode = mode;
}

int
Mavlink::instance_count()
{
	unsigned inst_index = 0;
	Mavlink *inst;

	LL_FOREACH(::_mavlink_instances, inst) {
		inst_index++;
	}

	return inst_index;
}

Mavlink *
Mavlink::get_instance(unsigned instance)
{
	Mavlink *inst;
	unsigned inst_index = 0;
	LL_FOREACH(::_mavlink_instances, inst) {
		if (instance == inst_index) {
			return inst;
		}

		inst_index++;
	}

	return nullptr;
}

Mavlink *
Mavlink::get_instance_for_device(const char *device_name)
{
	Mavlink *inst;

	LL_FOREACH(::_mavlink_instances, inst) {
		if (strcmp(inst->_device_name, device_name) == 0) {
			return inst;
		}
	}

	return nullptr;
}

int
Mavlink::destroy_all_instances()
{
	/* start deleting from the end */
	Mavlink *inst_to_del = nullptr;
	Mavlink *next_inst = ::_mavlink_instances;

	unsigned iterations = 0;

	MAVLINK_MAIN_WARN("[MAVLINK] waiting for instances to stop\n");

	while (next_inst != nullptr) {
		inst_to_del = next_inst;
		next_inst = inst_to_del->next;

		/* set flag to stop thread and wait for all threads to finish */
		inst_to_del->_task_should_exit = true;

		while (inst_to_del->_task_running) {
			printf_vx(".");
			fflush((FILE *)stdout);
			taskDelay(10);
			iterations++;

			if (iterations > 1000) {
				MAVLINK_MAIN_WARN("[MAVLINK] ERROR: Couldn't stop all mavlink instances\n");
				return ERROR;
			}
		}
	}

	MAVLINK_MAIN_WARN("[MAVLINK] all instances stopped\n");
	return OK;
}

int
Mavlink::get_status_all_instances()
{
	Mavlink *inst = ::_mavlink_instances;

	unsigned iterations = 0;

	while (inst != nullptr) {

		MAVLINK_MAIN_WARN("[MAVLINK] instance #%u:\n", iterations);
		inst->display_status();

		/* move on */
		inst = inst->next;
		iterations++;
	}

	/* return an error if there are no instances */
	return (iterations == 0);
}

bool
Mavlink::instance_exists(const char *device_name, Mavlink *self)
{
	Mavlink *inst = ::_mavlink_instances;

	while (inst != nullptr) {

		/* don't compare with itself */
		if (inst != self && !strcmp(device_name, inst->_device_name)) {
			return true;
		}

		inst = inst->next;
	}

	return false;
}

void
Mavlink::forward_message(const mavlink_message_t *msg, Mavlink *self)
{
	Mavlink *inst;
	LL_FOREACH(_mavlink_instances, inst) {
		if (inst != self) {

			/* if not in normal mode, we are an onboard link
			 * onboard links should only pass on messages from the same system ID */
			if (!(self->_mode != MAVLINK_MODE_NORMAL && msg->sysid != mavlink_system.sysid)) {
				inst->pass_message(msg);
			}
		}
	}
}

int
Mavlink::get_uart_fd(unsigned index)
{
	Mavlink *inst = get_instance(index);

	if (inst) {
		return inst->get_uart_fd();
	}

	return -1;
}

int
Mavlink::get_uart_fd()
{
	return _uart_fd;
}

int Mavlink::get_uart_fd_back()
{
	return _uart_fd_backup;
}


int
Mavlink::get_udp_socket()
{
	return _socket;
}

int
Mavlink::get_instance_id()
{
	return _instance_id;
}

mavlink_channel_t
Mavlink::get_channel()
{
	return _channel;
}

/****************************************************************************
 * MAVLink text message logger
 ****************************************************************************/

int
Mavlink::mavlink_dev_ioctl(int cmd, unsigned long arg)
{
	switch (cmd) {
	case (int)MAVLINK_IOC_SEND_TEXT_INFO:
	case (int)MAVLINK_IOC_SEND_TEXT_CRITICAL:
	case (int)MAVLINK_IOC_SEND_TEXT_EMERGENCY: {

			const char *txt = (const char *)arg;
			struct mavlink_logmessage msg;
			strncpy(msg.text, txt, sizeof(msg.text));

			switch (cmd) {
			case MAVLINK_IOC_SEND_TEXT_INFO:
				msg.severity = MAV_SEVERITY_INFO;
				break;

			case MAVLINK_IOC_SEND_TEXT_CRITICAL:
				msg.severity = MAV_SEVERITY_CRITICAL;
				break;

			case MAVLINK_IOC_SEND_TEXT_EMERGENCY:
				msg.severity = MAV_SEVERITY_EMERGENCY;
				break;

			default:
				msg.severity = MAV_SEVERITY_INFO;
				break;
			}

			Mavlink *inst;
			LL_FOREACH(_mavlink_instances, inst) {
				if (!inst->_task_should_exit) {
					mavlink_logbuffer_write(&inst->_logbuffer, &msg);
					inst->_total_counter++;
				}
			}

			return OK;
		}

	default:
		return ENOTTY;
	}
}

void Mavlink::mavlink_update_system(void)
{
	if (!_param_initialized) {
	    _param_system_id = param_find("MAV_SYS_ID");
	    _param_component_id = param_find("MAV_COMP_ID");
	    _param_radio_id = param_find("MAV_RADIO_ID");
	    _param_system_type = param_find("MAV_TYPE");
	    _param_vehicle_type = param_find("SYS_VEHICLE_TYPE");

	    //_param_soft_mult_rate = param_find("MAV_SoftMultRate");
	    _param_teleRateMulti = param_find("MAV_TeleRateMul");
	}

	/* update system and component id */
	int32_t system_id;
	param_get(_param_system_id, &system_id);

	int32_t component_id;
	param_get(_param_component_id, &component_id);

	param_get(_param_radio_id, &_radio_id);
	
	//param_get(_param_soft_mult_rate, &_soft_mult_rate);
	param_get(_param_teleRateMulti,&_teleRateMulti);

	/* only allow system ID and component ID updates
	 * after reboot - not during operation */
	if (!_param_initialized) {
		if (system_id > 0 && system_id < 255) {
			mavlink_system.sysid = system_id;
		}

		if (component_id > 0 && component_id < 255) {
			mavlink_system.compid = component_id;
		}

		_param_initialized = true;
	}

	/* MAVLINK_MAIN_WARN users that they need to reboot to take this
	 * into effect
	 */
	if (system_id != mavlink_system.sysid) {
		send_statustext_critical("Save params and reboot to change SYSID");
	}

	if (component_id != mavlink_system.compid) {
		send_statustext_critical("Save params and reboot to change COMPID");
	}

	int32_t vehicle_type;
	param_get(_param_vehicle_type, &vehicle_type);
	_system_type =  vehicle_type;
}

int Mavlink::get_system_id()
{
	return mavlink_system.sysid;
}

int Mavlink::get_component_id()
{
	return mavlink_system.compid;
}

int Mavlink::mavlink_open_udp(uint16_t udp_port)
{
    Udp_Init();    //在非WIN32下，这个函数为空函数
    _socket = CreateNoBlockAndBindUDP(udp_port); //UINT16 port
    return _socket;
}

int	Mavlink::set_rs422(const char *uart_name)
{
	int32_t rs422_en;
	uint8_t rs422_mask[6];
	uint8_t rs422_index = 0;
	uint8_t uart_name_len = strlen(uart_name);
	uint8_t rs422_one = 0;
	uint8_t uart_index = uart_name[uart_name_len -1] - '0';
	param_t param_serial_rs422_en = param_find("SERIAL_RS422_EN");
	
	param_get(param_serial_rs422_en, &rs422_en);
	while (rs422_en > 0) {
		rs422_mask[rs422_index++] = rs422_en % 10;
		rs422_en /= 10;
		if (rs422_mask[rs422_index - 1] == uart_index)
		{
			rs422_one = 1;
			warn_vx("rs422 6 is rs422: %d", rs422_one);
		}
		warn_vx("rs422:%d", rs422_mask[rs422_index - 1]);
	}
	return rs422_one;

}

int Mavlink::mavlink_open_uart(int baud, const char *uart_name, bool *is_dmu, int serial_conf)
{
	/* open uart */
	_uart_fd = open(uart_name, O_RDWR, 0644);

	if (_uart_fd < 0) {
		printf_vx("mavlink open %s fail..\n", uart_name);
		return _uart_fd;
	}
	
	//param2:1->set serial mode 2->get serial mode
	/* 
	 * param3 configurable type as follows :
	 * -RS232 on digit 0
	 * -RS422 on digit 1
	 * -RS485 on digit 2 or others
	 */
	ioctl(_uart_fd, 1, set_rs422(uart_name)); 
	
	/* setting serial port's baud-rate.*/
	ioctl(_uart_fd, SIO_BAUD_SET, baud);
	
	/* setting serial port's hardware information, stop-bit, parity bit, etc.*/
	uint32_t optval = 0 | /* parity bit:0->N 1->E 2->O */
			  0 | /* stop bit:0 1*/
			 (CLOCAL | CREAD | CS8); /* the data size by default 8 */
	ioctl(_uart_fd, SIO_HW_OPTS_SET, optval);
	
	return _uart_fd;
}
 
/**************************************************************************************************
* mavlink_open_uart_back()
* 
* 
* description:
* history:
*  
*/
int Mavlink::mavlink_open_uart_back(int baud, const char *uart_name, bool *is_dmu, int serial_conf)
{
	int uart_fd_temp=-1;
	
	/* open uart */
	uart_fd_temp = open(uart_name, O_RDWR, 0644);

	if (uart_fd_temp < 0) {
		printf_vx("mavlink open %s fail..\n", uart_name);
		return uart_fd_temp;
	}
	
	//param2:1->set serial mode 2->get serial mode
	/* 
	 * param3 configurable type as follows :
	 * -RS232 on digit 0
	 * -RS422 on digit 1
	 * -RS485 on digit 2 or others
	 */
	ioctl(uart_fd_temp, 1, set_rs422(uart_name)); 
	
	/* setting serial port's baud-rate.*/
	ioctl(uart_fd_temp, SIO_BAUD_SET, baud);
	
	/* setting serial port's hardware information, stop-bit, parity bit, etc.*/
	uint32_t optval = 0 | /* parity bit:0->N 1->E 2->O */
			  1 | /* stop bit:0 1*/
			 (CLOCAL | CREAD | CS8); /* the data size by default 8 */
	ioctl(uart_fd_temp, SIO_HW_OPTS_SET, optval);
	
	return uart_fd_temp;
}
 

int
Mavlink::set_hil_enabled(bool hil_enabled)
{
	int ret = OK;

	/* enable HIL */
	if (hil_enabled && !_hil_enabled) {
		_hil_enabled = true;
		configure_stream("HIL_CONTROLS", 200.0f);
	}

	/* disable HIL */
	if (!hil_enabled && _hil_enabled) {
		_hil_enabled = false;
		configure_stream("HIL_CONTROLS", 0.0f);

	} else {
		ret = ERROR;
	}

	return ret;
}


void
Mavlink::send_message(const uint8_t msgid, const void *msg, uint8_t component_ID)
{
	/* If the wait until transmit flag is on, only transmit after we've received messages.
	   Otherwise, transmit all the time. */
	if (!should_transmit()) {
		return;
	}

	pthread_mutex_lock(&_send_mutex);

	//unsigned buf_free = get_free_tx_buf();

	uint8_t payload_len = mavlink_message_lengths[msgid];
	unsigned packet_len = payload_len + MAVLINK_NUM_NON_PAYLOAD_BYTES;

	_last_write_try_time = hrt_absolute_time();

	/* check if there is space in the buffer, let it overflow else
	if (buf_free < packet_len) {
		// no enough space in buffer to send 
		count_txerr();
		count_txerrbytes(packet_len);
		pthread_mutex_unlock(&_send_mutex);
		return;
	}*/

	uint8_t buf[MAVLINK_MAX_PACKET_LEN];

	/* header */
	buf[0] = MAVLINK_STX; //mavlink V1.0 FE开头 | V2.0 FD开头
	buf[1] = payload_len;
	/* use mavlink's internal counter for the TX seq */
	buf[2] = mavlink_get_channel_status(_channel)->current_tx_seq++;
	buf[3] = mavlink_system.sysid;
	buf[4] = (component_ID == 0) ? mavlink_system.compid : component_ID;
	buf[5] = msgid;

	/* payload */
	memcpy(&buf[MAVLINK_NUM_HEADER_BYTES], msg, payload_len);

	/* checksum */
	uint16_t checksum;
	crc_init(&checksum);
	crc_accumulate_buffer(&checksum, (const char *) &buf[1], MAVLINK_CORE_HEADER_LEN + payload_len);
	crc_accumulate(mavlink_message_crcs[msgid], &checksum);

	buf[MAVLINK_NUM_HEADER_BYTES + payload_len] = (uint8_t)(checksum & 0xFF);
	buf[MAVLINK_NUM_HEADER_BYTES + payload_len + 1] = (uint8_t)(checksum >> 8);

	/* send message to UART */
#ifndef MAVLINK_UDP
	ssize_t ret = write(_uart_fd, (char*)buf, packet_len);

#ifdef MAVLINK_USE_BACKUP_DEVICE
	write(_uart_fd_backup, (char*)buf, packet_len);
#endif

#else
	ssize_t ret = UdpSendData(_socket, (PCTSTR)_tar_ip_str, 8000, (char *)buf, packet_len);;
#endif

	if (ret != (int) packet_len) {
		count_txerr();
		count_txerrbytes(packet_len);
		count_txerrMsgs();

	} else {
		_last_write_success_time = _last_write_try_time;
		count_txbytes(packet_len);
		count_txMsgs();
	}

	pthread_mutex_unlock(&_send_mutex);
}

void
Mavlink::resend_message(mavlink_message_t *msg)
{
	/* If the wait until transmit flag is on, only transmit after we've received messages.
	   Otherwise, transmit all the time. */
	if (!should_transmit()) {
		return;
	}

	pthread_mutex_lock(&_send_mutex);

	//unsigned buf_free = get_free_tx_buf();

	_last_write_try_time = hrt_absolute_time();

	unsigned packet_len = msg->len + MAVLINK_NUM_NON_PAYLOAD_BYTES;

	/* check if there is space in the buffer, let it overflow else 
	if (buf_free < packet_len) {
		// no enough space in buffer to send 
		count_txerr();
		count_txerrbytes(packet_len);
		pthread_mutex_unlock(&_send_mutex);
		return;
	}*/

	uint8_t buf[MAVLINK_MAX_PACKET_LEN];

	/* header and payload */
	memcpy(&buf[0], &msg->magic, MAVLINK_NUM_HEADER_BYTES + msg->len);

	/* checksum */
	buf[MAVLINK_NUM_HEADER_BYTES + msg->len] = (uint8_t)(msg->checksum & 0xFF);
	buf[MAVLINK_NUM_HEADER_BYTES + msg->len + 1] = (uint8_t)(msg->checksum >> 8);

	/* send message to UART */
	ssize_t ret = write(_uart_fd, (char*)buf, packet_len);

	if (ret != (int) packet_len) {
		count_txerr();
		count_txerrbytes(packet_len);
		count_txerrMsgs();

	} else {
		_last_write_success_time = _last_write_try_time;
		count_txbytes(packet_len);
		count_txMsgs();
	}

	pthread_mutex_unlock(&_send_mutex);
}

void
Mavlink::handle_message(const mavlink_message_t *msg)
{
	/* handle packet with mission manager */
	_mission_manager->handle_message(msg);

	/* handle packet with parameter component */
	_parameters_manager->handle_message(msg);/*参数列表*/

	/* handle packet with rtk component */
	_mavlink_rtk->handle_message(msg);

	if (get_forwarding_on()) {
		/* forward any messages to other mavlink instances */
		Mavlink::forward_message(msg, this);
	}
}

void
Mavlink::send_statustext_info(const char *string)
{
	send_statustext(MAV_SEVERITY_INFO, string);
}

void
Mavlink::send_statustext_critical(const char *string)
{
	send_statustext(MAV_SEVERITY_CRITICAL, string);
}

void
Mavlink::send_statustext_emergency(const char *string)
{
	send_statustext(MAV_SEVERITY_EMERGENCY, string);
}

void
Mavlink::send_statustext(unsigned char severity, const char *string)
{
	struct mavlink_logmessage logmsg;
	strncpy(logmsg.text, string, sizeof(logmsg.text));
	logmsg.severity = severity;

	mavlink_logbuffer_write(&_logbuffer, &logmsg);
}

#define UNIQUE_ID    	0x1FFF7A10  //STM DocID018909 Rev 8 Sect 39.1 (Unique device ID Register)
#define getreg32(a)          (*(volatile uint32_t *)(a))
/** Copy the 96bit MCU Unique ID into the provided pointer */
void mcu_unique_id(uint32_t *uid_96_bit)
{
	uid_96_bit[0] = getreg32(UNIQUE_ID);
	uid_96_bit[1] = getreg32(UNIQUE_ID+4);
	uid_96_bit[2] = getreg32(UNIQUE_ID+8);
}

MavlinkOrbSubscription *Mavlink::add_orb_subscription(const orb_id_t topic, int instance)
{
	/* check if already subscribed to this topic */
	MavlinkOrbSubscription *sub;

	LL_FOREACH(_subscriptions, sub) {
		if (sub->get_topic() == topic && sub->get_instance() == instance) {
			/* already subscribed */
			return sub;
		}
	}

	/* add new subscription */
	MavlinkOrbSubscription *sub_new = new MavlinkOrbSubscription(topic, instance);

	LL_APPEND(_subscriptions, sub_new);

	return sub_new;
}

unsigned int
Mavlink::interval_from_rate(float rate)
{
   return (rate > 0.0f) ? (1000000.0f / rate) : 0;
}

int
Mavlink::configure_stream(const char *stream_name, const float rate)
{
	/* calculate interval in us, 0 means disabled stream */
	unsigned int interval = interval_from_rate(rate);

	/* search if stream exists */
	MavlinkStream *stream;
	LL_FOREACH(_streams, stream) {
		if (strcmp(stream_name, stream->get_name()) == 0) {
			if (interval > 0) {
				/* set new interval */
				stream->set_interval(interval);

			} else {
				/* delete stream */
				LL_DELETE(_streams, stream);
				delete stream;
			}

			return OK;
		}
	}

	if (interval == 0) {
		/* stream was not active and is requested to be disabled, do nothing */
		return OK;
	}

	/* search for stream with specified name in supported streams list */
	for (unsigned int i = 0; streams_list[i] != nullptr; i++) {

		if (strcmp(stream_name, streams_list[i]->get_name()) == 0) {
			/* create new instance */
			stream = streams_list[i]->new_instance(this);
			stream->set_interval(interval);
			LL_APPEND(_streams, stream);

			return OK;
		}
	}

	/* if we reach here, the stream list does not contain the stream */
	warn_vx("stream %s not found", stream_name);

	return ERROR;
}

void
Mavlink::adjust_stream_rates(const float multiplier)
{
	/* do not allow to push us to zero */
	if (multiplier < 0.0005f) {
		return;
	}

	/* search if stream exists */
	MavlinkStream *stream;
	LL_FOREACH(_streams, stream) {
		/* set new interval */
		unsigned interval = stream->get_interval();
		interval /= multiplier;

		/* allow max ~2000 Hz */
		if (interval < 1600) {
//			interval = 500;
		}

		/* set new interval */
		stream->set_interval(interval * multiplier); //设置为原始速率，没看懂？？？
	}
}

int
Mavlink::message_buffer_init(int size)
{

	_message_buffer.size = size;
	_message_buffer.write_ptr = 0;
	_message_buffer.read_ptr = 0;
	// _message_buffer.data = (char *)malloc(_message_buffer.size);
	char data_array[_message_buffer.size]; // 声明固定长度数组  
	_message_buffer.data = data_array;     // 指针指向数组首地址  


	int ret;

	if (_message_buffer.data == 0) {
		ret = ERROR;
		_message_buffer.size = 0;

	} else {
		ret = OK;
	}

	return ret;
}

void
Mavlink::message_buffer_destroy()
{
	_message_buffer.size = 0;
	_message_buffer.write_ptr = 0;
	_message_buffer.read_ptr = 0;
	// free(_message_buffer.data);
}

int
Mavlink::message_buffer_count()
{
	int n = _message_buffer.write_ptr - _message_buffer.read_ptr;

	if (n < 0) {
		n += _message_buffer.size;
	}

	return n;
}

int
Mavlink::message_buffer_is_empty()
{
	return _message_buffer.read_ptr == _message_buffer.write_ptr;
}


bool
Mavlink::message_buffer_write(const void *ptr, int size)
{
	// bytes available to write
	int available = _message_buffer.read_ptr - _message_buffer.write_ptr - 1;

	if (available < 0) {
		available += _message_buffer.size;
	}

	if (size > available) {
		// buffer overflow
		return false;
	}

	char *c = (char *) ptr;
	int n = _message_buffer.size - _message_buffer.write_ptr;	// bytes to end of the buffer

	if (n < size) {
		// message goes over end of the buffer
		memcpy(&(_message_buffer.data[_message_buffer.write_ptr]), c, n);
		_message_buffer.write_ptr = 0;

	} else {
		n = 0;
	}

	// now: n = bytes already written
	int p = size - n;	// number of bytes to write
	memcpy(&(_message_buffer.data[_message_buffer.write_ptr]), &(c[n]), p);
	_message_buffer.write_ptr = (_message_buffer.write_ptr + p) % _message_buffer.size;
	return true;
}

int
Mavlink::message_buffer_get_ptr(void **ptr, bool *is_part)
{
	// bytes available to read
	int available = _message_buffer.write_ptr - _message_buffer.read_ptr;

	if (available == 0) {
		return 0;	// buffer is empty
	}

	int n = 0;

	if (available > 0) {
		// read pointer is before write pointer, all available bytes can be read
		n = available;
		*is_part = false;

	} else {
		// read pointer is after write pointer, read bytes from read_ptr to end of the buffer
		n = _message_buffer.size - _message_buffer.read_ptr;
		*is_part = _message_buffer.write_ptr > 0;
	}

	*ptr = &(_message_buffer.data[_message_buffer.read_ptr]);
	return n;
}

void
Mavlink::message_buffer_mark_read(int n)
{
	_message_buffer.read_ptr = (_message_buffer.read_ptr + n) % _message_buffer.size;
}

void
Mavlink::pass_message(const mavlink_message_t *msg)
{
	if (_passing_on) {
		/* size is 8 bytes plus variable payload */
		int size = MAVLINK_NUM_NON_PAYLOAD_BYTES + msg->len;
		pthread_mutex_lock(&_message_buffer_mutex);
		message_buffer_write(msg, size);
		pthread_mutex_unlock(&_message_buffer_mutex);
	}
}

float
Mavlink::get_rate_mult()
{
	return _rate_mult;
}

void
Mavlink::update_rate_mult()
{
	float const_rate = 0.0f;
	float rate = 0.0f;

	/* scale down rates if their theoretical bandwidth is exceeding the link bandwidth */
	MavlinkStream *stream;
	LL_FOREACH(_streams, stream) {
		if (stream->const_rate()) {
			const_rate += stream->get_size() * 1000000.0f / stream->get_interval();

		} else {
			rate += stream->get_size() * 1000000.0f / stream->get_interval();
		}
	}

	/* don't scale up rates, only scale down if needed */
	float bandwidth_mult = math::min(1.0f, ((float)_datarate - const_rate) / rate);

	/* check if we have radio feedback */
	struct telemetry_status_s &tstatus = get_rx_status();

	bool radio_critical = false;
	bool radio_found = false;

	/* 2nd pass: Now check hardware limits */
	if (tstatus.type == TELEMETRY_STATUS_RADIO_TYPE_3DR_RADIO) {

		radio_found = true;

		if (tstatus.txbuf < RADIO_BUFFER_LOW_PERCENTAGE) {
			radio_critical = true;
		}
	}

	float hardware_mult = _rate_mult;

	/* scale down if we have a TX err rate suggesting link congestion */
	if (_rate_txerr > 0.0f && !radio_critical) {
		hardware_mult = (_rate_tx) / (_rate_tx + _rate_txerr);
	} else if (radio_found && tstatus.timestamp != _last_hw_rate_timestamp) {

		if (tstatus.txbuf < RADIO_BUFFER_CRITICAL_LOW_PERCENTAGE) {
			/* this indicates link congestion, reduce rate by 20% */
			hardware_mult *= 0.80f;
		} else if (tstatus.txbuf < RADIO_BUFFER_LOW_PERCENTAGE) {
			/* this indicates link congestion, reduce rate by 2.5% */
			hardware_mult *= 0.975f;
		} else if (tstatus.txbuf > RADIO_BUFFER_HALF_PERCENTAGE) {
			/* this indicates spare bandwidth, increase by 2.5% */
			hardware_mult *= 1.025f;
			/* limit to a max multiplier of 1 */
			hardware_mult = math::min(1.0f, hardware_mult);
		}
	} else {
		/* no limitation, set hardware to 1 */
		hardware_mult = 1.0f;
	}

	_last_hw_rate_timestamp = tstatus.timestamp;

	//printf_vx("bandwidth_mult = %.3f, hardware_mult = %.3f\n", bandwidth_mult, hardware_mult); //bandwidth_mult = 0.561
	/* pick the minimum from bandwidth mult and hardware mult as limit */
	_rate_mult = math::min(bandwidth_mult, hardware_mult);

	/* ensure the rate multiplier never drops below 5% so that something is always sent */
	_rate_mult = math::max(0.05f, _rate_mult);
}



/**************************************************************************************************
* device_init_backup()
* 
* 
* description:
* history:
*  
*/
int Mavlink::device_init_back(int uart_port)
{
	sprintf(_device_name_bak, "/tyCo/%d",uart_port);
}

/**************************************************************************************************
* task_main()
* 
* 
* description:
* history:
*  
*/

int
Mavlink::task_main(_Vx_usr_arg_t arg2, _Vx_usr_arg_t arg3, _Vx_usr_arg_t arg4, _Vx_usr_arg_t arg5, _Vx_usr_arg_t arg6)
{

	int ch;
	_baudrate = 115200;//115200->57600
	_datarate = 0;
	_mode = MAVLINK_MODE_NORMAL;
	udp_port = 7000;
	/* don't exit from getopt loop to leave getopt global variables in consistent state,
	 * set error flag instead */
	bool err_flag = false;
	
	int mkdir_ret = mkdir("/mmc0:2/msgs");

	if((mkdir_ret != OK) && (errno != EEXIST)) {
	    warn_vx("failed creating new dir: /mmc0:2/msgs");		
	    return -1;
	}

	if (0 != arg2)
	{
		_baudrate = arg2;

		if (_baudrate < 9600 || _baudrate > 921600*3) {
		    warn_vx("invalid baud rate '%s'", optarg);
			err_flag = true;
		}
	}

	if (0 != arg3)
	{
		_datarate = arg3;

		if (_datarate < 10 || _datarate > MAX_DATA_RATE) {
		    warn_vx("invalid data rate '%s'", optarg);
			err_flag = true;
		}
	}

	if (0 != arg4)
	{
		sprintf(_device_name, "/tyCo/%d",arg4);
		_is_dmu_uart = false;
	}
	
	if (0 != arg5)
	{
			if (1 == arg5) {
				_mode = MAVLINK_MODE_CUSTOM;
			} else if (2 == arg5) {
				// left in here for compatibility
				_mode = MAVLINK_MODE_ONBOARD; //camera
			} else if (3 == arg5) {
				_mode = MAVLINK_MODE_ONBOARD;
			} else if (4 == arg5) {
				_mode = MAVLINK_MODE_OSD;
			} else if (5 == arg5) {
				_mode = MAVLINK_MODE_CONFIG;
			}
	}

	if (0 != arg6)
	{
		if (arg6|1)
			_forwarding_on = true;

		if (arg6|2)
			_passing_on = true;

		if (arg6|4)
			_verbose = true;

		if (arg6|16)
			_wait_to_transmit = true;

		if (arg6|32)
			_ftp_on = true;
	}

    //_baudrate = temp_bound;//FOR NSH USE
	//printf_vx("arg2 = %d, arg3 = %d, arg4 = %d, arg5 = %d, arg6 = %d\n", arg2,  arg3, arg4, arg5, arg6);
	
	if (_datarate == 0) {
		/* convert bits to bytes and use 1/2 of bandwidth by default */
		_datarate = _baudrate / 20;
	}

	if (_datarate > MAX_DATA_RATE) {
		_datarate = MAX_DATA_RATE;
	}

	if (Mavlink::instance_exists(_device_name, this)) {
	    warn_vx("%s already running", _device_name);
		return ERROR;
	}


	/* flush stdout in case MAVLink is about to take it over */
	fflush((FILE *)stdout);

	/* default values for arguments */
#ifndef USE_MAVLINK_UDP
	warn_vx("[mavlink_main]mode: %u, data rate: %d B/s on %s @ %ldbaudrate..", _mode, _datarate, _device_name, _baudrate);
	_uart_fd = mavlink_open_uart(_baudrate, _device_name, &_is_dmu_uart, arg4);
	if (_uart_fd < 0) 
	{
	    warn_vx("could not open %s", _device_name);
		return ERROR;
	}
	else
	{
	    //printf_vx("ssssssss %d sssssssss", _uart_fd);
	}

#ifdef USE_MAVLINK_BACKUP_DEVICE
	device_init_back(TELE_UART_PORT_BAK);

	_uart_fd_backup = mavlink_open_uart_back(_baudrate_backup, _device_name_bak, &_is_dmu_uart,arg4);
	
	if (_uart_fd_backup < 0) 
	{
	    warn_vx("could not open %s", _device_name_bak);
		return ERROR;
	}
	else
	{
	    //printf_vx("ssssssss %d sssssssss", _uart_fd_backup);
	}
#endif


#else
	(void)sprintf(_tar_ip_str, "192.168.%d.%d", _link_0_ip_3, _link_0_ip_4);
	warn_vx("mavlink ip:%s", _tar_ip_str);
	_socket = mavlink_open_udp(udp_port);
#endif

	/* initialize send mutex */
	pthread_mutex_init(&_send_mutex, NULL);

	/* initialize mavlink text message buffering */
	mavlink_logbuffer_init(&_logbuffer, 20);

	/* if we are passing on mavlink messages, we need to prepare a buffer for this instance */
	if (_passing_on || _ftp_on) {
		/* initialize message buffer if multiplexing is on or its needed for FTP.
		 * make space for two messages plus off-by-one space as we use the empty element
		 * marker ring buffer approach.
		 */
		if (OK != message_buffer_init(2 * sizeof(mavlink_message_t) + 1)) {
		    warn_vx("msg buf:message_buffer_init fail..");
		}

		/* initialize message buffer mutex */
		pthread_mutex_init(&_message_buffer_mutex, NULL);
	}

	/* Initialize system properties */
	mavlink_update_system();

	/* 接收mavlink消息的任务 */
	_receive_thread = MavlinkReceiver::receive_start(this);
	
	MavlinkOrbSubscription *param_sub = add_orb_subscription(ORB_ID(parameter_update));
	uint64_t param_time = 0;

	/* add default streams depending on mode */
#if 0
	/* HEARTBEAT is constant rate stream, rate never adjusted */
	configure_stream("HEARTBEAT", 1.0f);

	/* STATUSTEXT stream is like normal stream but gets messages from logbuffer instead of uORB */
	configure_stream("STATUSTEXT", 20.0f);

	/* COMMAND_LONG stream: use high rate to avoid commands skipping */
 	configure_stream("COMMAND_LONG", 100.0f);
#endif
	/* PARAM_VALUE stream */
	_parameters_manager = (MavlinkParametersManager *) MavlinkParametersManager::new_instance(this);
	_parameters_manager->set_interval(interval_from_rate(50.0f));
	LL_APPEND(_streams, _parameters_manager);

	/* MISSION_STREAM stream, actually sends all MISSION_XXX messages at some rate depending on
	 * remote requests rate. Rate specified here controls how much bandwidth we will reserve for
	 * mission messages. */
	_mission_manager = (MavlinkMissionManager *) MavlinkMissionManager::new_instance(this);
	_mission_manager->set_interval(interval_from_rate(10.0f));
	//_mission_manager->set_verbose(_verbose );
	_mission_manager->set_verbose(true);
	LL_APPEND(_streams, _mission_manager);
	
	// Send RTK Mavlink message
	_mavlink_rtk = (MavlinkRTK *) MavlinkRTK::new_instance(this);
	_mavlink_rtk->set_interval(interval_from_rate(80.0f));
	LL_APPEND(_streams, _mavlink_rtk);
	
	switch (_mode) {
	case MAVLINK_MODE_NORMAL:	
		configure_stream("SYS_STATUS", 1.0f*_teleRateMulti);
		configure_stream("TELE_DATA", 1.0f*_teleRateMulti);
		break;

	default:
		break;
	}
	
	/* set main loop delay depending on data rate to minimize CPU overhead */
	_main_loop_delay = (MAIN_LOOP_DELAY) / _datarate;

	/* now the instance is fully initialized and we can bump the instance count */
	LL_APPEND(_mavlink_instances, this);
	
	/*整体的提高或降低 mavlink message 发送频率*/ /*在任务主循环前，暂时不考虑动态变动*/
	if(fabs(_soft_mult_rate - 1.0f) >  mav_floatThreshold)
	{
	    adjust_stream_rates(_soft_mult_rate);
	}	
	
	uint8_t buf[100];
	while (!_task_should_exit) {
		/* main loop */
		taskDelay(_main_loop_delay); //3ms
		
		hrt_abstime t = hrt_absolute_time();
		
		if (param_sub->update(&param_time, nullptr)) 
		{
		    //parameters updated 
		    mavlink_update_system();
		}
		
		//update_rate_mult(); //??? not use
		
		//int nread = read(_uart_fd, (char*)buf, sizeof(buf));
		//write(_uart_fd, (char*)buf, nread);
		
		
#if 1
		/* update streams 关键功能：遍历所有的mavlink流信息，进行数据发送*/
		MavlinkStream *stream;
		LL_FOREACH(_streams, stream) {
			stream->update(t);
		}
#endif	
		/* pass messages from other UARTs or FTP worker */
		if (_passing_on || _ftp_on) 
		{
			bool is_part;
			uint8_t *read_ptr;
			uint8_t *write_ptr;

			pthread_mutex_lock(&_message_buffer_mutex);
			int available = message_buffer_get_ptr((void **)&read_ptr, &is_part);
			pthread_mutex_unlock(&_message_buffer_mutex);

			if (available > 0) {
				// Reconstruct message from buffer

				mavlink_message_t msg;
				write_ptr = (uint8_t *)&msg;

				// Pull a single message from the buffer
				size_t read_count = available;

				if (read_count > sizeof(mavlink_message_t)) {
					read_count = sizeof(mavlink_message_t);
				}

				memcpy(write_ptr, read_ptr, read_count);

				// We hold the mutex until after we complete the second part of the buffer. If we don't
				// we may end up breaking the empty slot overflow detection semantics when we mark the
				// possibly partial read below.
				pthread_mutex_lock(&_message_buffer_mutex);

				message_buffer_mark_read(read_count);

				/* write second part of buffer if there is some */
				if (is_part && read_count < sizeof(mavlink_message_t)) {
					write_ptr += read_count;
					available = message_buffer_get_ptr((void **)&read_ptr, &is_part);
					read_count = sizeof(mavlink_message_t) - read_count;
					memcpy(write_ptr, read_ptr, read_count);
					message_buffer_mark_read(available);
				}

				pthread_mutex_unlock(&_message_buffer_mutex);

				resend_message(&msg);
			}
		}
		/* update TX/RX rates every 1s*/
		if (t > _bytes_timestamp + 1000000) {
			if (_bytes_timestamp != 0) {
				float dt = (t - _bytes_timestamp) / 1000.0f;
				_rate_tx = _bytes_tx / dt;
				_rate_txerr = _bytes_txerr / dt;
				_rate_rx = _bytes_rx / dt;
				_bytes_tx = 0;
				_bytes_txerr = 0;
				_bytes_rx = 0;
			}

			_bytes_timestamp = t;
		}

		/* update rxtx msgs rates every 10s*/
		if (t > _msgs_timestamp + 10000000) 
		{

			float dt = ((float)(t - _msgs_timestamp))/1000000.0f;
			if (_msgs_timestamp != 0) 
			{
				uint32_t totalMsgCnt = _msgs_rx + _lost_msgs_rx;

				_rec_msgs_rx = _msgs_rx;
				_rec_msgs_rxCrcFail = _msgs_rxCrcFail;
				_rec_lost_msgs_rx = _lost_msgs_rx;
				if(totalMsgCnt > 0)
				{
					_rate_rx_lost_msgs = ((float)_lost_msgs_rx)/((float)totalMsgCnt);
				}
				_rate_rx_msgs = _msgs_rx / dt;

				_msgs_rx = 0;
				_lost_msgs_rx = 0;
				_msgs_rxCrcFail = 0;
				
				_rate_tx_msgs = _msgs_tx / dt;
				_rate_tx_err_msgs = ((float)_msgs_txerr)/((float)_rate_tx_msgs + _msgs_txerr);
				_msgs_tx = 0;
				_msgs_txerr = 0;
				
			}
			_msgs_timestamp = t;
		}

		/* confirm task running only once fully initialized */
		_task_running = true;
	}

	delete _subscribe_to_stream;
	_subscribe_to_stream = nullptr;

	/* delete streams */
	MavlinkStream *stream_to_del = nullptr;
	MavlinkStream *stream_next = _streams;

	while (stream_next != nullptr) {
		stream_to_del = stream_next;
		stream_next = stream_to_del->next;
		delete stream_to_del;
	}

	_streams = nullptr;

	/* delete subscriptions */
	MavlinkOrbSubscription *sub_to_del = nullptr;
	MavlinkOrbSubscription *sub_next = _subscriptions;

	while (sub_next != nullptr) {
		sub_to_del = sub_next;
		sub_next = sub_to_del->next;
		delete sub_to_del;
	}

	_subscriptions = nullptr;

	/* wait for threads to complete */
	pthread_join(_receive_thread, NULL);

	/* close UART */
	close(_uart_fd);

	if (_passing_on || _ftp_on) {
		message_buffer_destroy();
		pthread_mutex_destroy(&_message_buffer_mutex);
	}
	
	/* destroy log buffer */
	mavlink_logbuffer_destroy(&_logbuffer);

	warn_vx("exiting");
	_task_running = false;

	return OK;
	
}

int Mavlink::start_helper(_Vx_usr_arg_t arg2, _Vx_usr_arg_t arg3, _Vx_usr_arg_t arg4, _Vx_usr_arg_t arg5, _Vx_usr_arg_t arg6)
{
	/* create the instance in task context */
	Mavlink *instance = new Mavlink();

	int res;

	if (!instance) {

		/* out of memory */
		res = -ENOMEM;
		warn_vx("OUT OF MEM");

	} else {
		/* this will actually only return once MAVLink exits */
		res = instance->task_main(arg2, arg3, arg4, arg5, arg6);

		/* delete instance on main thread end */
		delete instance;
	}

	return res;
}

int
Mavlink::start(_Vx_usr_arg_t arg2, _Vx_usr_arg_t arg3, _Vx_usr_arg_t arg4, _Vx_usr_arg_t arg5, _Vx_usr_arg_t arg6)
{
	// Wait for the instance count to go up one
	// before returning to the shell
	int ic = Mavlink::instance_count();

	if (ic == MAVLINK_COMM_NUM_BUFFERS) {
		MAVLINK_MAIN_WARN("Maximum MAVLink instance count of %d reached.", (int)MAVLINK_COMM_NUM_BUFFERS);
		return 1;
	}

	// Instantiate thread
	char buf[24];
	sprintf(buf, "mavlink_%d", ic);

	// This is where the control flow splits
	// between the starting task and the spawned
	// task - start_helper() only returns
	// when the started task exits.
	//3400->6400

	TASK_ID task_mavlink_helper;
	if ((task_mavlink_helper = taskSpawn( (char*)buf,TASK_PRIO_MAVLINK_MAIN,VX_FP_TASK,20480,(FUNCPTR)&Mavlink::start_helper,arg2, arg3, arg4, arg5, arg6,0,0,0,0,0)) == ERROR)
	{
		logMsg("taskSpawn mavlink failed.\n",0,0,0,0,0,0);
	}
	
	// Ensure that this shell command
	// does not return before the instance
	// is fully initialized. As this is also
	// the only path to create a new instance,
	// this is effectively a lock on concurrent
	// instance starting. XXX do a real lock.

	// Sleep 1000 us between each attempt
	const unsigned sleeptime = 1000;

	// Wait 200 ms max for the startup.
	const unsigned limit = 100 * 1000 / sleeptime;

	unsigned count = 0;

	while (ic == Mavlink::instance_count() && count < limit) {
		taskDelay(sleeptime /1000 ) ;
		count++;
	}

	return OK;
}

void
Mavlink::display_status()
{

	if (_rstatus.heartbeat_time > 0) {
		debug_vx("\tGCS heartbeat:\t%llu us ago", hrt_elapsed_time(&_rstatus.heartbeat_time));
	}

	debug_vx("\tmavlink chan: #%u count = %u", _channel,Mavlink::instance_count());
    
	if (_rstatus.timestamp > 0) {

	    debug_vx("\ttype:\t\t");

		switch (_rstatus.type) {
		case TELEMETRY_STATUS_RADIO_TYPE_3DR_RADIO:
		  debug_vx("3DR RADIO");
			break;

		default:
		  debug_vx("UNKNOWN RADIO");
			break;
		}

		debug_vx("\trssi:\t\t%d", _rstatus.rssi);
		debug_vx("\tremote rssi:\t%u", _rstatus.remote_rssi);
		debug_vx("\ttxbuf:\t\t%u", _rstatus.txbuf);
		debug_vx("\tnoise:\t\t%d", _rstatus.noise);
		debug_vx("\tremote noise:\t%u", _rstatus.remote_noise);
		debug_vx("\trx errors:\t%u", _rstatus.rxerrors);
		debug_vx("\tfixed:\t\t%u", _rstatus.fixed);

	} else {
	    debug_vx("\tno telem status.");
	}

	debug_vx("\t------------rates-----------");
	debug_vx("\ttx: %.3f kB/s", (double)_rate_tx);
	debug_vx("\ttxerr: %.3f kB/s", (double)_rate_txerr);
	debug_vx("\trx: %.3f kB/s", (double)_rate_rx);
	debug_vx("\trate mult: %.3f", (double)_rate_mult);
#if 1
	debug_vx("\t_msgs_tx:%d\t_msgs_txerr:%d",_msgs_tx,_msgs_txerr);
	debug_vx("\t_rate_tx_msgs: %8.4f/s", (double)_rate_tx_msgs);
	debug_vx("\t_rate_tx_err_msgs: %8.4f%%", (double)(_rate_tx_err_msgs*100.0f));
#endif	
	debug_vx("\tlost_msg_cnt:%d\trxCrcFail_cnt:%d\trecv_msg_cnt:%d",_rec_lost_msgs_rx,_rec_msgs_rxCrcFail,_rec_msgs_rx);
	debug_vx("\trate recvMsg: %8.4f/s", (double)_rate_rx_msgs);
	debug_vx("\trate lostMsg: %8.4f%%", (double)(_rate_rx_lost_msgs*100.0f));
	
}


static void usage()
{
	MAVLINK_MAIN_WARN("usage: mavlink {start|stop-all|stream} [-d device] [-b baudrate]\n\t[-r rate][-m mode] [-s stream] [-f] [-p] [-v] [-w] [-x]");
}

int mavlink_main(_Vx_usr_arg_t arg1, _Vx_usr_arg_t arg2, _Vx_usr_arg_t arg3, _Vx_usr_arg_t arg4, _Vx_usr_arg_t arg5, _Vx_usr_arg_t arg6)
{
    if (0 == arg1)
    {
	    return Mavlink::start(arg2, arg3, arg4, arg5, arg6);
    } 
    else if (1 == arg1) 
    {
	    MAVLINK_MAIN_WARN("[mavlink] stop is deprecated, use stop-all instead");
	    usage();
	    exit(1);
    } 
    else if (2 == arg1) 
    {
	    return Mavlink::destroy_all_instances();

    } 
    else if (3 == arg1) 
    {
	    return Mavlink::get_status_all_instances();

    } 
    else if (4 == arg1) 
    {
	    //return Mavlink::stream_command(arg2, arg3, arg4, arg5, arg6);

    } 
    else if (5 == arg1) 
    {
	    Mavlink::set_boot_complete();
	    return 0;
    }
    else if (6 == arg1) 
    {
        temp_bound = 9600;
	    return 0;
    }
    else if (7 == arg1) 
    {
        temp_bound = 19200;
	    return 0;
    }
    else if (8 == arg1) 
    {
        temp_bound = 38400;
	    return 0;
    }
     else if (9 == arg1) 
    {
        temp_bound = 57600;
	    return 0;
    }
    else if (10 == arg1) 
    {
        temp_bound = 921600;
	    return 0;
    }
    else if (11 == arg1) 
    {
        temp_bound = 1843200;
	    return 0;
    }
    else if (12 == arg1) 
    {
        temp_bound = 2764800;
	    return 0;
    }	
    else {
	    usage();
	    exit(1);
    }

    return 0;
}

