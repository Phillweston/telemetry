/**
 * @file mavlink_parameters.h
 * Mavlink parameters manager definition.
 *
 * @author Anton Babushkin <anton.babushkin@me.com>
 * @author Lorenz Meier <lorenz@px4.io>
 */

#pragma once

#include "parameters/param.h"

#include "mavlink_bridge_header.h"
#include "mavlink_stream.h"
#include "uORB.h"

class MavlinkParametersManager : public MavlinkStream
{
public:
	const char *get_name() const
	{
		return MavlinkParametersManager::get_name_static();
	}

	static const char *get_name_static()
	{
		return "PARAM_VALUE";
	}

	uint8_t get_id()
	{
		return MAVLINK_MSG_ID_PARAM_VALUE;
	}

	static MavlinkStream *new_instance(Mavlink *mavlink)
	{
		return new MavlinkParametersManager(mavlink);
	}

	unsigned get_size();

	void handle_message(const mavlink_message_t *msg);

	/**
	 * Send one parameter identified by index.
	 *
	 * @param index		The index of the parameter to send.
	 * @return		zero on success, nonzero else.
	 */
	void		start_send_one(int index);


	/**
	 * Send one parameter identified by name.
	 *
	 * @param name		The index of the parameter to send.
	 * @return		zero on success, nonzero else.
	 */
	int			start_send_for_name(const char *name);

	/**
	 * Start sending the parameter queue.
	 *
	 * This function will not directly send parameters, but instead
	 * activate the sending of one parameter on each call of
	 * mavlink_pm_queued_send().
	 * @see 		mavlink_pm_queued_send()
	 */
	void		start_send_all();

private:
	int		_send_all_index;

	/* do not allow top copying this class */
	MavlinkParametersManager(MavlinkParametersManager &);
	MavlinkParametersManager& operator = (const MavlinkParametersManager &);

protected:
	explicit MavlinkParametersManager(Mavlink *mavlink);

	void send(const hrt_abstime t);

	int send_param(param_t param);

	orb_advert_t _rc_param_map_pub;
};
