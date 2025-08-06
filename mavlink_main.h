#pragma once

#include <stdbool.h>
#include "parameters/param.h"
#include "perf_counter.h"
#include "print/print.h"
#include <pthread.h>
#include "mavlink/mavlink_log.h"
#include "uORB.h"
#include "topics/mission.h"
#include "topics/mission_result.h"
#include "topics/telemetry_status.h"
#include "mavlink_bridge_header.h"
#include "mavlink_orb_subscription.h"
#include "mavlink_stream.h"
#include "mavlink_messages.h"
#include "mavlink_mission.h"
#include "mavlink_parameters.h"
#include "mavlink_rtk.h"
#include "mavlink/mavlink_log.h"
#include "udp/udp.h"
#include "../../drivers/drv_device.h"
#include "main.h"


class Mavlink
{

public:
	/**
	 * Constructor
	 */
	Mavlink();

	/**
	 * Destructor, also kills the mavlinks task.
	 */
	~Mavlink();

	/**
	* Start the mavlink task.
	 *
	 * @return		OK on success.
	 */
	static int		start(_Vx_usr_arg_t arg2, _Vx_usr_arg_t arg3, _Vx_usr_arg_t arg4, _Vx_usr_arg_t arg5, _Vx_usr_arg_t arg6);

	/**
	 * Display the mavlink status.
	 */
	void			display_status();

	static int		stream_command(_Vx_usr_arg_t arg2, _Vx_usr_arg_t arg3, _Vx_usr_arg_t arg4, _Vx_usr_arg_t arg5, _Vx_usr_arg_t arg6);

	static int		instance_count();

	static Mavlink		*new_instance();

	static Mavlink		*get_instance(unsigned instance);

	static Mavlink		*get_instance_for_device(const char *device_name);

	static int		destroy_all_instances();

	static int		get_status_all_instances();

	static bool		instance_exists(const char *device_name, Mavlink *self);

	static void		forward_message(const mavlink_message_t *msg, Mavlink *self);

	static int		get_uart_fd(unsigned index);

	int			get_uart_fd();
	int			get_uart_fd_back();
	int			get_udp_socket();

	/**
	 * Get the MAVLink system id.
	 *
	 * @return		The system ID of this vehicle
	 */
	int			get_system_id();

	/**
	 * Get the MAVLink component id.
	 *
	 * @return		The component ID of this vehicle
	 */
	int			get_component_id();

	char *_device_name;			//主链路设备
	char *_device_name_bak;		//备链路设备

	enum MAVLINK_MODE {
		MAVLINK_MODE_NORMAL = 0,
		MAVLINK_MODE_CUSTOM,
		MAVLINK_MODE_ONBOARD,
		MAVLINK_MODE_OSD,
		MAVLINK_MODE_CONFIG
	};

	void			set_mode(enum MAVLINK_MODE);
	enum MAVLINK_MODE	get_mode() { return _mode; }

	bool			get_hil_enabled() { return _hil_enabled; }

	bool			get_flow_control_enabled() { return _flow_control_enabled; }

	bool			get_forwarding_on() { return _forwarding_on; }

	/**
	 * Set the boot complete flag on all instances
	 *
	 * Setting the flag unblocks parameter transmissions, which are gated
	 * beforehand to ensure that the system is fully initialized.
	 */
	static void		set_boot_complete() { _boot_complete = true; }

	static int		start_helper(_Vx_usr_arg_t arg2, _Vx_usr_arg_t arg3, _Vx_usr_arg_t arg4, _Vx_usr_arg_t arg5, _Vx_usr_arg_t arg6);

	/**
	 * Handle parameter related messages.
	 */
	void			mavlink_pm_message_handler(const mavlink_channel_t chan, const mavlink_message_t *msg);

	void			get_mavlink_mode_and_state(struct vehicle_status_s *status, struct position_setpoint_triplet_s *pos_sp_triplet, uint8_t *mavlink_state, uint8_t *mavlink_base_mode, uint32_t *mavlink_custom_mode);

	/**
	 * Enable / disable Hardware in the Loop simulation mode.
	 *
	 * @param hil_enabled	The new HIL enable/disable state.
	 * @return		OK if the HIL state changed, ERROR if the
	 *			requested change could not be made or was
	 *			redundant.
	 */
	int			set_hil_enabled(bool hil_enabled);

	/**
	 * Get the manual input generation mode
	 *
	 * @return true if manual inputs should generate RC data
	 */
	bool			get_manual_input_mode_generation() { return _generate_rc; }

	void			send_message(const uint8_t msgid, const void *msg, uint8_t component_ID = 0);

	/**
	 * Resend message as is, don't change sequence number and CRC.
	 */
	void			resend_message(mavlink_message_t *msg);

	void			handle_message(const mavlink_message_t *msg);

	MavlinkOrbSubscription *add_orb_subscription(const orb_id_t topic, int instance=0);

	int			get_instance_id();

	mavlink_channel_t	get_channel();

	bool			_task_should_exit;	/**< if true, mavlink task should exit */

	/**
	 * Send a status text with loglevel INFO
	 *
	 * @param string the message to send (will be capped by mavlink max string length)
	 */
	void			send_statustext_info(const char *string);

	/**
	 * Send a status text with loglevel CRITICAL
	 *
	 * @param string the message to send (will be capped by mavlink max string length)
	 */
	void			send_statustext_critical(const char *string);

	/**
	 * Send a status text with loglevel EMERGENCY
	 *
	 * @param string the message to send (will be capped by mavlink max string length)
	 */
	void			send_statustext_emergency(const char *string);

	/**
	 * Send a status text with loglevel, the difference from mavlink_log_xxx() is that message sent
	 * only on this mavlink connection. Useful for reporting communication specific, not system-wide info
	 * only to client interested in it. Message will be not sent immediately but queued in buffer as
	 * for mavlink_log_xxx().
	 *
	 * @param string the message to send (will be capped by mavlink max string length)
	 * @param severity the log level
	 */
	void			send_statustext(unsigned char severity, const char *string);

	MavlinkStream *		get_streams() const { return _streams; }

	float			get_rate_mult();

	/* Functions for waiting to start transmission until message received. */
	void			set_has_received_messages(bool received_messages) { _received_messages = received_messages; }
	bool			get_has_received_messages() { return _received_messages; }
	void			set_wait_to_transmit(bool wait) { _wait_to_transmit = wait; }
	bool			get_wait_to_transmit() { return _wait_to_transmit; }
	bool			should_transmit() { return (!_wait_to_transmit || (_wait_to_transmit && _received_messages)); }

	bool			message_buffer_write(const void *ptr, int size);

	void			lockMessageBufferMutex(void) { pthread_mutex_lock(&_message_buffer_mutex); }
	void			unlockMessageBufferMutex(void) { pthread_mutex_unlock(&_message_buffer_mutex); }

	/**
	 * Count a transmision error
	 * 
	 */
	void			count_txerr();
	
	void			count_txerrMsgs() { _msgs_txerr += 1; };
	
	void			count_txMsgs() { _msgs_tx += 1; };

	/**
	 * Count transmitted bytes
	 */
	void			count_txbytes(unsigned n) { _bytes_tx += n; };

	/**
	 * Count bytes not transmitted because of errors
	 */
	void			count_txerrbytes(unsigned n) { _bytes_txerr += n; };

	/**
	 * Count received bytes
	 */
	void			count_rxbytes(unsigned n) { _bytes_rx += n; };

	/**
	 * Count received msg
	 */
	void			count_rxMsgs(unsigned n) { _msgs_rx += n; };

	/**
	 * Count received crc fail
	 */
	void			count_rxCrcFail(unsigned n) { _msgs_rxCrcFail += n; };

	/**
	 * Count lost msg
	 */
	void			count_rxLostMsgs(unsigned n) { _lost_msgs_rx += n; };

	/**
	 * Get the receive status of this MAVLink link
	 */
	struct telemetry_status_s&	get_rx_status() { return _rstatus; }

	struct mavlink_logbuffer	*get_logbuffer() { return &_logbuffer; }

	unsigned		get_system_type() { return _system_type; }

	static bool		boot_complete() { return _boot_complete; }

	uint32_t _last_msg_seq;
	
	static int	mavlink_dev_ioctl(int cmd, unsigned long arg);

protected:
	Mavlink			*next;

private:
	int			_instance_id;

	bool			_task_running;
	static bool		_boot_complete;

	/* states */
	bool			_hil_enabled;		/**< Hardware In the Loop mode */
	bool			_generate_rc;		/**< Generate RC messages from manual input MAVLink messages */
	bool			_is_dmu_uart;		/**< Port is dmu 默认内置电台串口 */
	bool        		_wait_to_transmit;  	/**< Wait to transmit until received messages. */
	bool        		_received_messages;	/**< Whether we've received valid mavlink messages. */

	unsigned		_main_loop_delay;	/**< mainloop delay, depends on data rate */

	MavlinkOrbSubscription	*_subscriptions;
	MavlinkStream		*_streams;

	MavlinkMissionManager		*_mission_manager;
	MavlinkParametersManager	*_parameters_manager;	
	MavlinkRTK          *_mavlink_rtk;
	MAVLINK_MODE 		_mode;

	mavlink_channel_t	_channel;
	int32_t			_radio_id;

	struct mavlink_logbuffer _logbuffer;
	unsigned int		_total_counter;

	pthread_t		_receive_thread;

	bool			_verbose;
	bool			_forwarding_on;
	bool			_passing_on;
	bool			_ftp_on;
	int			    _uart_fd;
	int				_uart_fd_backup;
	long			_baudrate=57600;
	long			_baudrate_backup=115200;
	int			    _datarate;		///< data rate for normal streams (attitude, position, etc.)
	int			    _datarate_events;	///< data rate for params, waypoints, text messages
	float			_rate_mult;
	hrt_abstime		_last_hw_rate_timestamp;
	uint16_t 		udp_port;
	int				_socket;


	/**
	 * If the queue index is not at 0, the queue sending
	 * logic will send parameters from the current index
	 * to len - 1, the end of the param list.
	 */
	unsigned int		_mavlink_param_queue_index;

	bool			mavlink_link_termination_allowed;

	char 			*_subscribe_to_stream;
	float			_subscribe_to_stream_rate;

	bool			_flow_control_enabled;
	uint64_t		_last_write_success_time;
	uint64_t		_last_write_try_time;

	unsigned		_bytes_tx;
	unsigned		_bytes_txerr;
	unsigned		_msgs_tx = 0;
	unsigned		_msgs_txerr = 0;
	
	unsigned		_bytes_rx;
	unsigned		_msgs_rx;
	unsigned		_msgs_rxCrcFail;	
	unsigned		_rec_msgs_rx;
	unsigned		_rec_msgs_rxCrcFail;
	unsigned		_lost_msgs_rx;
	unsigned		_rec_lost_msgs_rx;
	uint64_t		_bytes_timestamp;
	uint64_t		_msgs_timestamp;
	float			_rate_tx;
	float			_rate_txerr;
	float			_rate_rx;
	
	float			_rate_tx_err_msgs = 0;
	float			_rate_tx_msgs = 0;
	float			_rate_rx_lost_msgs;
	float			_rate_rx_msgs;

	struct telemetry_status_s	_rstatus;			///< receive status

	struct mavlink_message_buffer {
		int write_ptr;
		int read_ptr;
		int size;
		char *data;
	};

	mavlink_message_buffer	_message_buffer;

	pthread_mutex_t		_message_buffer_mutex;
	pthread_mutex_t		_send_mutex;

	bool			_param_initialized;
	param_t			_param_system_id;
	param_t			_param_component_id;
	param_t			_param_radio_id;
	param_t			_param_system_type;
	param_t			_param_vehicle_type;
	param_t         _param_soft_mult_rate;

	param_t			_param_teleRateMulti;
	param_t			_param_teleMinimum;
	
	float           _soft_mult_rate;

	float 			_teleRateMulti;
	uint32_t		_teleMinimum;
	
	unsigned		_system_type;

	perf_counter_t		_loop_perf;			/*< loop performance counter */
	perf_counter_t		_txerr_perf;			/*< TX error counter */


	param_t			_handle_link_0_ip_3;
	param_t 		_handle_link_0_ip_4;
	uint32_t 		_link_0_ip_3 = 3;
	uint32_t 		_link_0_ip_4 = 100;

	char _tar_ip_str[16];


	void			mavlink_update_system();

	int mavlink_open_uart(int baudrate, const char *uart_name, bool *is_dmu, int serial_conf);
	int mavlink_open_uart_back(int baud, const char *uart_name, bool *is_dmu, int serial_conf);
	int			mavlink_open_udp(uint16_t udp_port);
	
	static unsigned int	interval_from_rate(float rate);
	int device_init_back(int uart_port);

	static constexpr unsigned RADIO_BUFFER_CRITICAL_LOW_PERCENTAGE = 25;
	static constexpr unsigned RADIO_BUFFER_LOW_PERCENTAGE = 35;
	static constexpr unsigned RADIO_BUFFER_HALF_PERCENTAGE = 50;

	int configure_stream(const char *stream_name, const float rate);

	/**
	 * Adjust the stream rates based on the current rate
	 *
	 * @param multiplier if greater than 1, the transmission rate will increase, if smaller than one decrease
	 */
	void adjust_stream_rates(const float multiplier);

	int message_buffer_init(int size);

	void message_buffer_destroy();

	int message_buffer_count();

	int message_buffer_is_empty();

	int message_buffer_get_ptr(void **ptr, bool *is_part);

	void message_buffer_mark_read(int n);

	void pass_message(const mavlink_message_t *msg);

	/**
	 * Update rate mult so total bitrate will be equal to _datarate.
	 */
	void update_rate_mult();

	/**
	 * Main mavlink task.
	 */
	int		task_main(_Vx_usr_arg_t arg2, _Vx_usr_arg_t arg3, _Vx_usr_arg_t arg4, _Vx_usr_arg_t arg5, _Vx_usr_arg_t arg6);


	int	set_rs422(const char *uart_name);

	/* do not allow copying this class */
	Mavlink(const Mavlink&);
	Mavlink operator=(const Mavlink&);
};

int mavlink_main(_Vx_usr_arg_t arg1, _Vx_usr_arg_t arg2, _Vx_usr_arg_t arg3, _Vx_usr_arg_t arg4, _Vx_usr_arg_t arg5, _Vx_usr_arg_t arg6);
