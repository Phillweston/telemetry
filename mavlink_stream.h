/**
 * @file mavlink_stream.h
 * Mavlink messages stream definition.
 *
 * @author Anton Babushkin <anton.babushkin@me.com>
 */

#ifndef MAVLINK_STREAM_H_
#define MAVLINK_STREAM_H_

#include "hrt/hrt.h"

class Mavlink;
class MavlinkStream;

class MavlinkStream
{

public:
	MavlinkStream *next;

	MavlinkStream(Mavlink *mavlink);
	virtual ~MavlinkStream();

	/**
	 * Get the interval
	 *
	 * @param interval the inveral in microseconds (us) between messages
	 */
	void set_interval(const unsigned int interval);

	/**
	 * Get the interval
	 *
	 * @return the inveral in microseconds (ms) between messages
	 */
	unsigned get_interval() { return _interval; }

	/**
	 * @return 0 if updated / sent, -1 if unchanged
	 */
	int update(const hrt_abstime t);
	virtual const char *get_name() const = 0;
	virtual uint8_t get_id() = 0;

	/**
	 * @return true if steam rate shouldn't be adjusted
	 */
	virtual bool const_rate() { return true; }

	/**
	 * Get maximal total messages size on update
	 */
	virtual unsigned get_size() = 0;

protected:
	Mavlink     *_mavlink;
	unsigned int _interval;

	virtual void send(const hrt_abstime t) = 0;

private:
	hrt_abstime _last_sent;

	/* do not allow top copying this class */
	MavlinkStream(const MavlinkStream &);
	MavlinkStream &operator=(const MavlinkStream &);
};


#endif /* MAVLINK_STREAM_H_ */
