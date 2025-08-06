/**
 * @file mavlink_orb_subscription.h
 * uORB subscription definition.
 *
 * @author Anton Babushkin <anton.babushkin@me.com>
 */

#ifndef MAVLINK_ORB_SUBSCRIPTION_H_
#define MAVLINK_ORB_SUBSCRIPTION_H_

#include "uthash/utlist.h"
#include "hrt/hrt.h"


class MavlinkOrbSubscription
{
public:
	MavlinkOrbSubscription *next;	///< pointer to next subscription in list

	MavlinkOrbSubscription(const orb_id_t topic, int instance);
	~MavlinkOrbSubscription();

	/**
	 * Check if subscription updated and get data.
	 *
	 * @return true only if topic was updated and data copied to buffer successfully.
	 * If topic was not updated since last check it will return false but still copy the data.
	 * If no data available data buffer will be filled with zeroes.
	 */
	bool update(uint64_t *time, void* data);

	/**
	 * Copy topic data to given buffer.
	 *
	 * @return true only if topic data copied successfully.
	 */
	bool update(void* data);

	/**
	 * Check if the topic has been published.
	 *
	 * This call will return true if the topic was ever published.
	 * @return true if the topic has been published at least once.
	 */
	bool is_published();
	orb_id_t get_topic() const;
	int get_instance() const;

private:
	const orb_id_t _topic;		///< topic metadata
	const int _instance;		///< get topic instance
	int _fd;			///< subscription handle
	bool _published;		///< topic was ever published

	/* do not allow copying this class */
	MavlinkOrbSubscription(const MavlinkOrbSubscription&);
	MavlinkOrbSubscription operator=(const MavlinkOrbSubscription&);
};


#endif /* MAVLINK_ORB_SUBSCRIPTION_H_ */
