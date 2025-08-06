/**
 * @file mavlink_log.h
 * MAVLink text logging.
 *
 * @author Lorenz Meier <lorenz@px4.io>
 */

#ifndef MAVLINK_LOG
#define MAVLINK_LOG

/*
 * IOCTL interface for sending log messages.
 */
#include <sys/ioctl.h>
#include <time.h>
#include "hrt/hrt.h"
/**
 * The mavlink log device node; must be opened before messages
 * can be logged.
 */
#define MAVLINK_LOG_DEVICE	"/mavlink"
/**
 * The maximum string length supported.
 */
#define MAVLINK_LOG_MAXLEN			50

#define IOC(type,nr)   ((type)|(nr))

#define MAVLINK_IOC_SEND_TEXT_INFO		IOC(0x1100, 1)
#define MAVLINK_IOC_SEND_TEXT_CRITICAL		IOC(0x1100, 2)
#define MAVLINK_IOC_SEND_TEXT_EMERGENCY		IOC(0x1100, 3)

#ifdef __cplusplus
extern "C" {
#endif
void mavlink_vasprintf(int severity, const char *fmt, ...);
#ifdef __cplusplus
}
#endif

/*
 * The va_args implementation here is not beautiful, but obviously we run into the same issues
 * the GCC devs saw, and are using their solution:
 *
 * http://gcc.gnu.org/onlinedocs/cpp/Variadic-Macros.html
 */

/**
 * Send a mavlink emergency message.
 *
 * @param _fd		A file descriptor returned from open(MAVLINK_LOG_DEVICE, 0);
 * @param _text		The text to log;
 */
#define mavlink_log_emergency(_text, ...)		mavlink_vasprintf(MAVLINK_IOC_SEND_TEXT_EMERGENCY, _text, ##__VA_ARGS__);

/**
 * Send a mavlink critical message.
 *
 * @param _fd		A file descriptor returned from open(MAVLINK_LOG_DEVICE, 0);
 * @param _text		The text to log;
 */
#define mavlink_log_critical(_text, ...)		mavlink_vasprintf(MAVLINK_IOC_SEND_TEXT_CRITICAL, _text, ##__VA_ARGS__);

/**
 * Send a mavlink info message.
 *
 * @param _fd		A file descriptor returned from open(MAVLINK_LOG_DEVICE, 0);
 * @param _text		The text to log;
 */
#define mavlink_log_info(_text, ...)		mavlink_vasprintf(MAVLINK_IOC_SEND_TEXT_INFO, _text, ##__VA_ARGS__);

/**
 * Send a mavlink emergency message and print to console.
 *
 * @param _fd		A file descriptor returned from open(MAVLINK_LOG_DEVICE, 0);
 * @param _text		The text to log;
 */
#define mavlink_and_console_log_emergency(_text, ...)		mavlink_vasprintf(MAVLINK_IOC_SEND_TEXT_EMERGENCY, _text, ##__VA_ARGS__); \
									fprintf(stderr, "telem> "); \
									fprintf(stderr, _text, ##__VA_ARGS__); \
									fprintf(stderr, "\n");

/**
 * Send a mavlink critical message and print to console.
 *
 * @param _fd		A file descriptor returned from open(MAVLINK_LOG_DEVICE, 0);
 * @param _text		The text to log;
 */
#define mavlink_and_console_log_critical(_text, ...)		mavlink_vasprintf(MAVLINK_IOC_SEND_TEXT_CRITICAL, _text, ##__VA_ARGS__); \
									fprintf(stderr, "telem> "); \
									fprintf(stderr, _text, ##__VA_ARGS__); \
									fprintf(stderr, "\n");

/**
 * Send a mavlink emergency message and print to console.
 *
 * @param _fd		A file descriptor returned from open(MAVLINK_LOG_DEVICE, 0);
 * @param _text		The text to log;
 */
#define mavlink_and_console_log_info(_text, ...)			mavlink_vasprintf(MAVLINK_IOC_SEND_TEXT_INFO, _text, ##__VA_ARGS__); \
									fprintf(stderr, "telem> "); \
									fprintf(stderr, _text, ##__VA_ARGS__); \
									fprintf(stderr, "\n");

struct mavlink_logmessage {
	char text[MAVLINK_LOG_MAXLEN + 1];
	unsigned char severity;
};

struct mavlink_logbuffer {
	unsigned int start;
	unsigned int size;
	int count;
	struct mavlink_logmessage *elems;
};


void mavlink_logbuffer_init(struct mavlink_logbuffer *lb, int size);

void mavlink_logbuffer_destroy(struct mavlink_logbuffer *lb);

int mavlink_logbuffer_is_full(struct mavlink_logbuffer *lb);

int mavlink_logbuffer_is_empty(struct mavlink_logbuffer *lb);

void mavlink_logbuffer_write(struct mavlink_logbuffer *lb, const struct mavlink_logmessage *elem);

int mavlink_logbuffer_read(struct mavlink_logbuffer *lb, struct mavlink_logmessage *elem);

void mavlink_logbuffer_vasprintf(struct mavlink_logbuffer *lb, int severity, const char *fmt, ...);

struct log_time
{   
   struct tm tim;
   hrt_abstime last_hrt;
   time_t last_t;
   uint8_t usedflag;
}; 

extern struct log_time  rec_tm; 

struct log_time * log_time_flash(struct log_time * logtm);

#endif

