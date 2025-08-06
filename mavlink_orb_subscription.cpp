/**
 * @file mavlink_orb_subscription.cpp
 * uORB subscription implementation.
 *
 * @author Anton Babushkin <anton.babushkin@me.com>
 * @author Lorenz Meier <lorenz@px4.io>
 */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "uORB.h"
#include <stdio.h>
#include "mavlink_orb_subscription.h"

MavlinkOrbSubscription::MavlinkOrbSubscription(const orb_id_t topic, int instance) :
	next(nullptr),
	_topic(topic),
	_instance(instance),
	_fd(orb_subscribe(_topic)),
	_published(false)
{
}

MavlinkOrbSubscription::~MavlinkOrbSubscription()
{
	//close(_fd);
}

orb_id_t
MavlinkOrbSubscription::get_topic() const
{
	return _topic;
}

int
MavlinkOrbSubscription::get_instance() const
{
	return _instance;
}

bool
MavlinkOrbSubscription::update(uint64_t *time, void* data)
{
	// TODO this is NOT atomic operation, we can get data newer than time
	// if topic was published between orb_stat and orb_copy calls.

	uint64_t time_topic;
	if (orb_stat(_fd, &time_topic)) {
		/* error getting last topic publication time */
		time_topic = 0;
	}
	
	bool updated = 0;
	orb_check(_fd, &updated);

	if (updated)
	{
		if (orb_copy(_topic, _fd, data)) {
			/* error copying topic data */
			memset(data, 0, _topic->o_size);
			return false;
	
		} else {
			/* data copied successfully */
			_published = true;
			if (time_topic != *time) {
				*time = time_topic;
				return true;
	
			} else {
				return false;
			}
		}
	}else{
		return false;
	}
}

bool
MavlinkOrbSubscription::update(void* data)
{
	return !orb_copy(_topic, _fd, data);
}

bool
MavlinkOrbSubscription::is_published()
{
	if (_published) {
		return true;
	}

	bool updated;
	orb_check(_fd, &updated);

	if (updated) {
		_published = true;
	}

	return _published;
}
