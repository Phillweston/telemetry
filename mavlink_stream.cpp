/**
 * @file mavlink_stream.cpp
 * Mavlink messages stream implementation.
 *
 * @author Anton Babushkin <anton.babushkin@me.com>
 */

#include <stdlib.h>

#include "mavlink_stream.h"
#include "mavlink_main.h"

MavlinkStream::MavlinkStream(Mavlink *mavlink) :
	next(nullptr),
	_mavlink(mavlink),
	_interval(1000000),
	_last_sent(0)
{
}

MavlinkStream::~MavlinkStream()
{
}

/**
 * Set messages interval in ms
 */
void
MavlinkStream::set_interval(const unsigned int interval)
{
	_interval = interval;
}

/**
 * Update subscriptions and send message if necessary
 */
int
MavlinkStream::update(const hrt_abstime t)
{
	uint64_t dt = t - _last_sent;
	unsigned int interval = _interval;

	if (!const_rate()) {
		interval /= _mavlink->get_rate_mult();
	}

	if (dt > 0 && dt >= interval) {
		/* interval expired, send message */
		send(t);

		if (const_rate()) {
			_last_sent = (t / _interval) * _interval;

		} else {
			_last_sent = t;
		}

		return 0;
	}

	return -1;
}
