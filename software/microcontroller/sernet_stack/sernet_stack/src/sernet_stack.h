#pragma once
/*
* sernet_parser.h
*
* Created: 3/3/2016 1:11:41 PM
*  Author: Nate

This file contains the header code for the Serial Network (SerNet) Stack

The SerNet stack is meant to be implemented as a layer 2 network protocol over
a simple serial connection such as uart or spi.  This module is meant to be implemented
with interrupt routines connected to the rxDequeue and txEnqueue functions.  This
is so that the peripheral can interrupt when receiving data and add it to the rx queue
or interrupt when the data has been sent and check the tx queue to see if there is more data
to send.  This is implemented with a somewhat object oriented approach as the Serial Network
Stack itself is encapsulated within a strucutre that contains the memory, data queue structures,
etc.  Thus a device could have multiple Serial Network Stacks active at once if there were multiple
serial connections that needed this protocol.

*/

#include <stdint.h>

#include "sernet_packet.h"

//this is the size in packets not in bytes.
#define SERNET_QUEUE_SIZE_PACKETS			1//32
#define SERNET_QUEUE_SIZE_BYTES             (SERNET_QUEUE_SIZE_PACKETS * MAX_SERNET_PACKET_SIZE)

#define SERNET_SUCCESS						0x00	//this means the operation was a success
#define SERNET_ERROR_NULL					0x01	//this means a NULL was passed in as an argument and the function did not perform any action
#define SERNET_ERROR_QUEUE_EMPTY			0x02	//this means there was no data in the queue when a dequeue was performed
#define SERNET_ERROR_QUEUE_FULL				0x03	//this means the queue does not have enough free space to enqueue the requested packet
#define SERNET_ERROR_QUEUE_PARTIAL			0x04	//this means that part of a packet is in the queue, but not all so the read failed as we don't want a partial packet


struct SerNetStack
{
	//rx queue variables
	uint8_t rxQueue[(SERNET_QUEUE_SIZE_PACKETS * MAX_SERNET_PACKET_SIZE)];
	uint8_t* rxQueueHead;
	uint8_t* rxQueueTail;
	uint8_t* rxQueueEnd;
	uint16_t rxQueueSize;

	//tx queue variables
	uint8_t txQueue[(SERNET_QUEUE_SIZE_PACKETS * MAX_SERNET_PACKET_SIZE)];
	uint8_t* txQueueHead;
	uint8_t* txQueueTail;
	uint8_t* txQueueEnd;
	uint16_t txQueueSize;
};

void initSerNetStack(struct SerNetStack* serNetStack);

static void incQueuePointer(uint8_t** firstAddress, uint8_t** lastAddress, uint8_t** currentAddress);

uint8_t serNetTxEnqueue(struct SerNetStack* serNetStack, struct SerNetPacket* packet);
uint8_t serNetTxDequeue(struct SerNetStack* serNetStack, uint8_t* data);

uint8_t serNetRxEnqueue(struct SerNetStack* serNetStack, uint8_t* data);
uint8_t serNetRxDequeue(struct SerNetStack* serNetStack, struct SerNetPacket* packet);
