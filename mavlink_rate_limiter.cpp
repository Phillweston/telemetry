/**
 * @file mavlink_rate_limiter.cpp
 * Message rate limiter implementation.
 *
 * @author Anton Babushkin <anton.babushkin@me.com>
 */

#include "mavlink_rate_limiter.h"

MavlinkRateLimiter::MavlinkRateLimiter() : _last_sent(0), _interval(1000000)
{
}

MavlinkRateLimiter::MavlinkRateLimiter(unsigned int interval) : _last_sent(0), _interval(interval)
{
}

MavlinkRateLimiter::~MavlinkRateLimiter()
{
}

void
MavlinkRateLimiter::set_interval(unsigned int interval)
{
	_interval = interval;
}

bool
MavlinkRateLimiter::check(hrt_abstime t)
{
	uint64_t dt = t - _last_sent;

	if (dt > 0 && dt >= _interval) {
		_last_sent = t;
		return true;
	}

	return false;
}
