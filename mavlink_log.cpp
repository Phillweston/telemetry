/**
 * @file mavlink_log.c
 * MAVLink text logging.
 *
 * @author Lorenz Meier <lm@inf.ethz.ch>
 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "mavlink_main.h"
#include "mavlink/mavlink_log.h"

 void mavlink_logbuffer_init(struct mavlink_logbuffer *lb, int size)
{
	lb->size  = size;
	lb->start = 0;
	lb->count = 0;
	lb->elems =  (struct mavlink_logmessage *)calloc(lb->size, sizeof(struct mavlink_logmessage));
}

 void mavlink_logbuffer_destroy(struct mavlink_logbuffer *lb)
{
	lb->size  = 0;
	lb->start = 0;
	lb->count = 0;
	free(lb->elems);
}

 int mavlink_logbuffer_is_full(struct mavlink_logbuffer *lb)
{
	return lb->count == (int)lb->size;
}

 int mavlink_logbuffer_is_empty(struct mavlink_logbuffer *lb)
{
	return lb->count == 0;
}

 void mavlink_logbuffer_write(struct mavlink_logbuffer *lb, const struct mavlink_logmessage *elem)
{
	int end = (lb->start + lb->count) % lb->size;
	memcpy(&(lb->elems[end]), elem, sizeof(struct mavlink_logmessage));

	if (mavlink_logbuffer_is_full(lb)) {
		lb->start = (lb->start + 1) % lb->size; /* full, overwrite */

	} else {
		++lb->count;
	}
}

 int mavlink_logbuffer_read(struct mavlink_logbuffer *lb, struct mavlink_logmessage *elem)
{
	if (!mavlink_logbuffer_is_empty(lb)) {
		memcpy(elem, &(lb->elems[lb->start]), sizeof(struct mavlink_logmessage));
		lb->start = (lb->start + 1) % lb->size;
		--lb->count;

		return 0;

	} else {
		return 1;
	}
}

 void mavlink_logbuffer_vasprintf(struct mavlink_logbuffer *lb, int severity, const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	int end = (lb->start + lb->count) % lb->size;
	lb->elems[end].severity = severity;
	vsnprintf(lb->elems[end].text, sizeof(lb->elems[0].text), fmt, ap);
	va_end(ap);

	/* increase count */
	if (mavlink_logbuffer_is_full(lb)) {
		lb->start = (lb->start + 1) % lb->size; /* full, overwrite */

	} else {
		++lb->count;
	}
}

 void mavlink_vasprintf(int severity, const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	char text[MAVLINK_LOG_MAXLEN + 1];
	vsnprintf(text, sizeof(text), fmt, ap);
	va_end(ap);
	
	Mavlink::mavlink_dev_ioctl(severity, (unsigned long)&text[0]);
	
}

struct log_time  rec_tm; 
 
 struct log_time * log_time_flash(struct log_time * logtm)
 {
    hrt_abstime ha_time =  hrt_absolute_time();
    hrt_abstime dif_time = ha_time - logtm->last_hrt;
    logtm->last_hrt = ha_time;
    logtm->last_t  += dif_time / 1e6;

    gmtime_r(&logtm->last_t, &rec_tm.tim);
    
    return logtm;
 }
 
