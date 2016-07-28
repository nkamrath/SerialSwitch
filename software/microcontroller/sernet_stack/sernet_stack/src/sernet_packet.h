#pragma once
/*
* serial_network_packet.h
*
* Created: 3/3/2016 1:09:19 PM
*  Author: Nate
*/

#include <stdint.h>

/** \brief Size of the SerNet stack internal queues in packets **/
#define MAX_SERNET_PAYLOAD_SIZE							4
#define SERNET_HEADER_SIZE								3
#define MAX_SERNET_PACKET_SIZE							(SERNET_HEADER_SIZE + MAX_SERNET_PAYLOAD_SIZE)

#define GET_SERNET_PAYLOAD_LENGTH(lenCheckByte)			((lenCheckByte>>6) + 1)
#define SET_SERNET_LEN_CHECK_BYTE(length, checksum)		((((length - 1) & 0x03) << 6) | (checksum & 0x3f))

struct SerNetPacket
{
	uint8_t toAddress;
	uint8_t fromAddress;
	uint8_t lenCheckByte;
	uint8_t payload[MAX_SERNET_PAYLOAD_SIZE];
};
