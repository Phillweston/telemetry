/**
 * @file mavlink_messages.h
 * MAVLink 1.0 message formatters definition.
 *
 * @author Anton Babushkin <anton.babushkin@me.com>
 */

#ifndef MAVLINK_MESSAGES_H_
#define MAVLINK_MESSAGES_H_

#include "mavlink_stream.h"

class StreamListItem {

public:
	MavlinkStream* (*new_instance)(Mavlink *mavlink);
	const char* (*get_name)();

	StreamListItem(MavlinkStream* (*inst)(Mavlink *mavlink), const char* (*name)()) :
		new_instance(inst),
		get_name(name) {};

	~StreamListItem() {};
};

extern const StreamListItem *streams_list[];

#endif /* MAVLINK_MESSAGES_H_ */
