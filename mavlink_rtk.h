#pragma once

#include <dirent.h>
#include "queue/queue.h"
#include "mavlink_stream.h"
#include "mavlink_bridge_header.h"
#include "topics/gps_inject_data.h"

class MavlinkRTK: public MavlinkStream
{
public:
	// @brief Contructor is only public so unit test code can new objects.
	MavlinkRTK(Mavlink *mavlink);
	~MavlinkRTK();
	
	virtual const char* get_name(void) const;
	virtual uint8_t get_id(void);
	virtual unsigned get_size(void);
	virtual void send(const hrt_abstime t) ;
	static MavlinkStream *new_instance(Mavlink *mavlink);
	
	// Handle possible RTK message
	void handle_message(const mavlink_message_t *msg);

	orb_advert_t		_rtcm_topic;
	
private:
	/* do not allow copying this class */
	MavlinkRTK(const MavlinkRTK&);
	MavlinkRTK& operator=(const MavlinkRTK&);
};

