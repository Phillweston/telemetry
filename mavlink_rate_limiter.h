/**
 * @file mavlink_rate_limiter.h
 * Message rate limiter definition.
 *
 * @author Anton Babushkin <anton.babushkin@me.com>
 */

#ifndef MAVLINK_RATE_LIMITER_H_
#define MAVLINK_RATE_LIMITER_H_

#include "hrt/hrt.h"


class MavlinkRateLimiter
{
private:
	hrt_abstime _last_sent;
	hrt_abstime _interval;

public:
	MavlinkRateLimiter();
	MavlinkRateLimiter(unsigned int interval);
	~MavlinkRateLimiter();
	void set_interval(unsigned int interval);
	bool check(hrt_abstime t);
};


#endif /* MAVLINK_RATE_LIMITER_H_ */
