/*
* sernet_parser.c
*
* Created: 3/3/2016 1:11:52 PM
*  Author: Nate
*/

#include "sernet_stack.h"

//init the serial network stack.  Set address as well.
void initSerNetStack(struct SerNetStack* serNetStack)
{
	//init the rx
	serNetStack->rxQueueHead = &serNetStack->rxQueue[0];
	serNetStack->rxQueueTail = &serNetStack->rxQueue[0];
	serNetStack->rxQueueEnd = &serNetStack->rxQueue[SERNET_QUEUE_SIZE_BYTES - 1];
	serNetStack->rxQueueSize = 0;

	//now init tx
	serNetStack->txQueueHead = &serNetStack->txQueue[0];
	serNetStack->txQueueTail = &serNetStack->txQueue[0];
	serNetStack->txQueueEnd = &serNetStack->txQueue[SERNET_QUEUE_SIZE_BYTES - 1];
	serNetStack->txQueueSize = 0;
}

static void incQueuePointer(uint8_t** firstAddress, uint8_t** lastAddress, uint8_t** currentAddress)
{
	if (*currentAddress == *lastAddress)
	{
		*currentAddress = *firstAddress;
	}
	else
	{
		(*currentAddress)++;
	}
}

//enqueue an entire tx packet
//this is meant to be called by the user when
//they need to transmit a packet.
uint8_t serNetTxEnqueue(struct SerNetStack* serNetStack, struct SerNetPacket* packet)
{
	if (packet == NULL || serNetStack == NULL)
	{
		return SERNET_ERROR_NULL;  //null packet error
	}

	uint8_t payloadLength = GET_SERNET_PAYLOAD_LENGTH(packet->lenCheckByte);

	//check to make sure the tx queue has room to hold this packet
	if (serNetStack->txQueueSize > (SERNET_QUEUE_SIZE_BYTES - (SERNET_HEADER_SIZE + payloadLength)))
	{
		return SERNET_ERROR_QUEUE_FULL;  //no room in queue for this packet, return error
	}

	uint8_t* temp = serNetStack->txQueue;
	uint8_t** txQueue = &temp;
	uint8_t** txQueueEnd = &serNetStack->txQueueEnd;
	uint8_t** txQueueTail = &serNetStack->txQueueTail;

	//enqueue the bytes of the packet
	**txQueueTail = packet->toAddress;
	incQueuePointer(txQueue, txQueueEnd, txQueueTail);
	**txQueueTail = packet->fromAddress;
	incQueuePointer(txQueue, txQueueEnd, txQueueTail);
	**txQueueTail = packet->lenCheckByte;
	incQueuePointer(txQueue, txQueueEnd, txQueueTail);
	for (int i = 0; i < payloadLength; i++)
	{
		**txQueueTail = packet->payload[i];
		incQueuePointer(txQueue, txQueueEnd, txQueueTail);
	}

	serNetStack->txQueueSize += (SERNET_HEADER_SIZE + payloadLength);

	return SERNET_SUCCESS;
}

//dequeue a tx byte from the tx data pool
//this is for the transmitter module that is sending
//a single byte at a time.
uint8_t serNetTxDequeue(struct SerNetStack* serNetStack, uint8_t* data)
{
	if (data == NULL || serNetStack == NULL)
	{
		return SERNET_ERROR_NULL;  // error handle passed in was null
	}

	if (serNetStack->txQueueSize == 0)
	{
		return SERNET_ERROR_QUEUE_EMPTY;  //error nothing to dequeue
	}

	*data = *(serNetStack->txQueueHead);
	uint8_t* temp = serNetStack->txQueue;
	uint8_t** txQueue = &temp;
	incQueuePointer(txQueue, &serNetStack->txQueueEnd, &serNetStack->txQueueHead);
	serNetStack->txQueueSize--;
	return SERNET_SUCCESS;
}

//enqueue a rx byte from the receiver
//this is for the receiver module that is receiving
//a single byte at a time.
uint8_t serNetRxEnqueue(struct SerNetStack* serNetStack, uint8_t* data)
{
	if (data == NULL || serNetStack == NULL)
	{
		return SERNET_ERROR_NULL; //data handle was null
	}

	if (serNetStack->rxQueueSize == SERNET_QUEUE_SIZE_BYTES)
	{
		return SERNET_ERROR_QUEUE_FULL; //error, no room to enqueue the packet
	}

	*(serNetStack->rxQueueTail) = *data;
	uint8_t* temp = serNetStack->rxQueue;
	uint8_t** rxQueue = &temp;
	incQueuePointer(rxQueue, &serNetStack->rxQueueEnd, &serNetStack->rxQueueTail);
	serNetStack->rxQueueSize++;
	return SERNET_SUCCESS;
}

//dequeue an entire rx packet.  This is meant to be called by
//the user when they desire to get an entire packet out of the rx
//queue
uint8_t serNetRxDequeue(struct SerNetStack* serNetStack, struct SerNetPacket* packet)
{
	if (packet == NULL || serNetStack == NULL)
	{
		return SERNET_ERROR_NULL; //error the packet handle passed in is null
	}

	uint8_t payloadLength = 0;
	uint8_t** rxQueueHead = &serNetStack->rxQueueHead;

	if (serNetStack->rxQueueSize < SERNET_HEADER_SIZE)
	{
		if (serNetStack->rxQueueSize == 0)
		{
			return SERNET_ERROR_QUEUE_EMPTY;
		}
		else
		{
			return SERNET_ERROR_QUEUE_PARTIAL; //error, there is no data to dequeue
		}
	}
	else
	{
		if ((*rxQueueHead) - serNetStack->rxQueueEnd > SERNET_HEADER_SIZE)
		{
			uint8_t* ptr = serNetStack->rxQueue + SERNET_HEADER_SIZE - (serNetStack->rxQueueEnd - (*rxQueueHead));
			payloadLength = GET_SERNET_PAYLOAD_LENGTH(*ptr);
		}
		else
		{
			payloadLength = GET_SERNET_PAYLOAD_LENGTH(*((*rxQueueHead) + SERNET_HEADER_SIZE - 1));
		}
		//payloadLength = GET_SERNET_PAYLOAD_LENGTH(*(rxQueueTail + SERNET_HEADER_SIZE));// *(rxQueueTail + SERNET_HEADER_SIZE) >> 6;
		if (serNetStack->rxQueueSize < SERNET_HEADER_SIZE + payloadLength)
		{
			return SERNET_ERROR_QUEUE_PARTIAL;  //error, there is part of a packet in the queue, but not all the payload is here yet
		}
	}

	uint8_t* temp = serNetStack->rxQueue;
	uint8_t** rxQueue = &temp;
	//uint8_t** rxQueueHead = &serNetStack->rxQueueHead;
	uint8_t** rxQueueEnd = &serNetStack->rxQueueEnd;

	packet->toAddress = **rxQueueHead;
	incQueuePointer(rxQueue, rxQueueEnd, rxQueueHead);
	packet->fromAddress = **rxQueueHead;
	incQueuePointer(rxQueue, rxQueueEnd, rxQueueHead);
	packet->lenCheckByte = **rxQueueHead;
	incQueuePointer(rxQueue, rxQueueEnd, rxQueueHead);
	for (int i = 0; i < payloadLength; i++)
	{
		packet->payload[i] = **rxQueueHead;
		incQueuePointer(rxQueue, rxQueueEnd, rxQueueHead);
	}

	serNetStack->rxQueueSize -= (SERNET_HEADER_SIZE + payloadLength);

	return SERNET_SUCCESS; //successfully dequeued packet
}

