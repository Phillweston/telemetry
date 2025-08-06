/**
 * @file mavlink_bridge_header
 * MAVLink bridge header for UART access.
 *
 * @author Lorenz Meier <lm@inf.ethz.ch>
 */

/* MAVLink adapter header */
#ifndef MAVLINK_BRIDGE_HEADER_H
#define MAVLINK_BRIDGE_HEADER_H


/*
 * We are NOT using convenience functions,
 * but instead send messages with a custom function.
 * So we do NOT do this:
 * #define MAVLINK_USE_CONVENIENCE_FUNCTIONS
 */

/* use efficient approach, see mavlink_helpers.h */
#define MAVLINK_SEND_UART_BYTES mavlink_send_uart_bytes

#define MAVLINK_GET_CHANNEL_BUFFER mavlink_get_channel_buffer
#define MAVLINK_GET_CHANNEL_STATUS mavlink_get_channel_status

#include "v1.0/mavlink_types.h"
#include <unistd.h>


/* Struct that stores the communication settings of this system.
   you can also define / alter these settings elsewhere, as long
   as they're included BEFORE mavlink.h.
   So you can set the

   mavlink_system.sysid = 100; // System ID, 1-255
   mavlink_system.compid = 50; // Component/Subsystem ID, 1-255

   Lines also in your main.c, e.g. by reading these parameter from EEPROM.
 */
extern mavlink_system_t mavlink_system;

/**
 * @brief Send multiple chars (uint8_t) over a comm channel
 *
 * @param chan MAVLink channel to use, usually MAVLINK_COMM_0 = UART0
 * @param ch Character to send
 */
void mavlink_send_uart_bytes(mavlink_channel_t chan, const uint8_t *ch, int length);

extern mavlink_status_t *mavlink_get_channel_status(uint8_t chan);
extern mavlink_message_t *mavlink_get_channel_buffer(uint8_t chan);

#include "v1.0/common/mavlink.h"


#endif /* MAVLINK_BRIDGE_HEADER_H */
