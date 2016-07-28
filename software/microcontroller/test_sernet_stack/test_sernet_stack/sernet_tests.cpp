
#include "sernet_tests.h"


bool testInitialization()
{
	SerNetStack stack;
	initSerNetStack(&stack);

	//check sizes are init correctly
	ASSERT(stack.rxQueueSize == 0);
	ASSERT(stack.txQueueSize == 0);

	//check that head and tail inits are correct
	ASSERT(stack.rxQueue == stack.rxQueueHead);
	ASSERT(stack.rxQueueHead == stack.rxQueueTail);

	ASSERT(stack.txQueue == stack.txQueueHead);
	ASSERT(stack.txQueueHead == stack.txQueueTail);

	//check that the arrays under the queues are sized correctly
	ASSERT(stack.rxQueueEnd - stack.rxQueueHead == (SERNET_QUEUE_SIZE_BYTES - 1));
	ASSERT(stack.txQueueEnd - stack.txQueueHead == (SERNET_QUEUE_SIZE_BYTES - 1));

	//check that the ends are in the right spot.  Above test pretty much already covers this, but just to be sure...
	ASSERT(stack.rxQueueEnd == &stack.rxQueue[SERNET_QUEUE_SIZE_BYTES - 1])

	return true;
}

bool testEmptyDequeueTx()
{
	SerNetStack stack;
	initSerNetStack(&stack);
	uint8_t testData;
	uint8_t status = serNetTxDequeue(&stack, &testData);
	ASSERT(status == SERNET_ERROR_QUEUE_EMPTY);

	return true;
}

bool testEmptyDequeueRx()
{
	SerNetStack stack;
	initSerNetStack(&stack);
	SerNetPacket packet;
	uint8_t status = serNetRxDequeue(&stack, &packet);
	ASSERT(status == SERNET_ERROR_QUEUE_EMPTY);
	return true;
}

bool testSingleEnqueueDequeueTx()
{
	SerNetStack stack;
	initSerNetStack(&stack);

	//setup a test packet
	uint8_t testData[7] = { 0x01, 0x02, 0x00, 0x03, 0x04, 0x05, 0x06 };
	SerNetPacket testPacket;
	testPacket.toAddress = testData[0];
	testPacket.fromAddress = testData[1];
	testPacket.lenCheckByte = testData[2];
	testPacket.payload[0] = testData[3];

	//enqueue the test packet
	uint8_t res = serNetTxEnqueue(&stack, &testPacket);
	ASSERT(res == SERNET_SUCCESS);

	//check the enqueued state
	ASSERT(stack.txQueueSize == 4);
	ASSERT(stack.rxQueueSize == 0);
	ASSERT(stack.txQueue == stack.txQueueHead);
	ASSERT(stack.txQueueTail - stack.txQueueHead == 4);

	uint8_t dequeueData = 0xff;

	//check the dequeued data
	res = serNetTxDequeue(&stack, &dequeueData);
	ASSERT(res == SERNET_SUCCESS && dequeueData == testData[0]);
	res = serNetTxDequeue(&stack, &dequeueData);
	ASSERT(res == SERNET_SUCCESS && dequeueData == testData[1]);
	res = serNetTxDequeue(&stack, &dequeueData);
	ASSERT(res == SERNET_SUCCESS && dequeueData == testData[2]);
	res = serNetTxDequeue(&stack, &dequeueData);
	ASSERT(res == SERNET_SUCCESS && dequeueData == testData[3]);

	//check the dequeued state
	ASSERT(stack.txQueueSize == 0);
	ASSERT(stack.rxQueueSize == 0);
	ASSERT(stack.txQueueHead == stack.txQueueTail);
	ASSERT(stack.txQueueEnd - stack.txQueue == (SERNET_QUEUE_SIZE_BYTES - 1));

	return true;
}

bool testSingleEnqueueDequeueRx()
{
	SerNetStack stack;
	initSerNetStack(&stack);

	//setup a test packet
	uint8_t testData[7] = { 0x01, 0x02, 0x00, 0x03, 0x04, 0x05, 0x06 };
	SerNetPacket testPacket;

	//check deqeueu of empty queue
	uint8_t result = serNetRxDequeue(&stack, &testPacket);
	ASSERT(result == SERNET_ERROR_QUEUE_EMPTY);

	//test enqueue the bytes on the rx side
	serNetRxEnqueue(&stack, &testData[0]);
	ASSERT(stack.rxQueueSize == 1);
	ASSERT(stack.txQueueSize == 0);
	ASSERT(stack.rxQueueTail - stack.rxQueueHead == stack.rxQueueSize);
	ASSERT(stack.rxQueueEnd - stack.rxQueue == (SERNET_QUEUE_SIZE_BYTES - 1));
	result = serNetRxDequeue(&stack, &testPacket);
	ASSERT(result == SERNET_ERROR_QUEUE_PARTIAL);

	serNetRxEnqueue(&stack, &testData[1]);
	ASSERT(stack.rxQueueSize == 2);
	ASSERT(stack.txQueueSize == 0);
	ASSERT(stack.rxQueueTail - stack.rxQueueHead == stack.rxQueueSize);
	ASSERT(stack.rxQueueEnd - stack.rxQueue == (SERNET_QUEUE_SIZE_BYTES - 1));
	result = serNetRxDequeue(&stack, &testPacket);
	ASSERT(result == SERNET_ERROR_QUEUE_PARTIAL);

	serNetRxEnqueue(&stack, &testData[2]);
	ASSERT(stack.rxQueueSize == 3);
	ASSERT(stack.txQueueSize == 0);
	ASSERT(stack.rxQueueTail - stack.rxQueueHead == stack.rxQueueSize);
	ASSERT(stack.rxQueueEnd - stack.rxQueue == (SERNET_QUEUE_SIZE_BYTES - 1));
	result = serNetRxDequeue(&stack, &testPacket);
	ASSERT(result == SERNET_ERROR_QUEUE_PARTIAL);

	serNetRxEnqueue(&stack, &testData[3]);
	ASSERT(stack.rxQueueSize == 4);
	ASSERT(stack.txQueueSize == 0);
	ASSERT(stack.rxQueueTail - stack.rxQueueHead == stack.rxQueueSize);
	ASSERT(stack.rxQueueEnd - stack.rxQueue == (SERNET_QUEUE_SIZE_BYTES - 1));

	//dequeue the packet
	result = serNetRxDequeue(&stack, &testPacket);
	ASSERT(result == SERNET_SUCCESS);

	ASSERT(testPacket.toAddress == testData[0]);
	ASSERT(testPacket.fromAddress == testData[1]);
	ASSERT(testPacket.lenCheckByte == testData[2]);
	ASSERT(testPacket.payload[0] == testData[3]);

	ASSERT(stack.rxQueueSize == 0);
	ASSERT(stack.txQueueSize == 0);
	ASSERT(stack.rxQueueHead == stack.rxQueueTail);
	ASSERT(stack.rxQueueEnd - stack.rxQueue == (SERNET_QUEUE_SIZE_BYTES - 1));

	return true;
}

bool testNullEnqueueRx()
{
	SerNetStack stack;
	initSerNetStack(&stack);
	uint8_t status = serNetRxEnqueue(&stack, NULL);
	ASSERT(status == SERNET_ERROR_NULL);
	status = serNetRxEnqueue(NULL, &status);
	ASSERT(status == SERNET_ERROR_NULL);
	return true;
}

bool testNullEnqueueTx()
{
	SerNetStack stack;
	initSerNetStack(&stack);
	uint8_t status = serNetTxEnqueue(&stack, NULL);
	ASSERT(status == SERNET_ERROR_NULL);
	SerNetPacket packet;
	status = serNetTxEnqueue(NULL, &packet);
	ASSERT(status == SERNET_ERROR_NULL);

	return true;
}

bool testNullDequeueRx()
{
	SerNetStack stack;
	initSerNetStack(&stack);
	uint8_t status = serNetRxDequeue(&stack, NULL);
	ASSERT(status == SERNET_ERROR_NULL);
	SerNetPacket packet;
	status = serNetRxDequeue(NULL, &packet);
	ASSERT(status == SERNET_ERROR_NULL);
	return true;
}

bool testNullDequeueTx()
{
	SerNetStack stack;
	initSerNetStack(&stack);
	uint8_t status = serNetTxDequeue(&stack, NULL);
	ASSERT(status == SERNET_ERROR_NULL);
	status = serNetTxDequeue(NULL, &status);
	ASSERT(status == SERNET_ERROR_NULL);

	return true;
}

bool testMaxPacketSizeEnqueueRx()
{
	SerNetStack stack;
	initSerNetStack(&stack);
	
	uint8_t testData[MAX_SERNET_PACKET_SIZE];
	for (int i = 0; i < MAX_SERNET_PACKET_SIZE; i++)
	{
		if (i == 2)
		{
			testData[i] = SET_SERNET_LEN_CHECK_BYTE(MAX_SERNET_PAYLOAD_SIZE, 0);
		}
		else
		{
			testData[i] = i;
		}
		uint8_t status = serNetRxEnqueue(&stack, &testData[i]);
		ASSERT(status == SERNET_SUCCESS);
		SerNetPacket packet;
		status = serNetRxDequeue(&stack, &packet);
		if (i == MAX_SERNET_PACKET_SIZE - 1)
		{
			ASSERT(status == SERNET_SUCCESS);
			ASSERT(packet.toAddress == testData[0]);
			ASSERT(packet.fromAddress == testData[1]);
			ASSERT(packet.lenCheckByte == testData[2]);
			for (int i = 0; i < MAX_SERNET_PAYLOAD_SIZE; i++)
			{
				ASSERT(testData[i + SERNET_HEADER_SIZE] == packet.payload[i]);
			}

			ASSERT(stack.rxQueueSize == 0);
			ASSERT(stack.txQueueSize == 0);
		}
		else
		{
			ASSERT(status == SERNET_ERROR_QUEUE_PARTIAL);
		}
	}
	return true;
}

bool testMaxPacketSizeEnqueueTx()
{
	SerNetStack stack;
	initSerNetStack(&stack);

	SerNetPacket packet;
	packet.toAddress = 0x01;
	packet.fromAddress = 0x02;
	packet.lenCheckByte = SET_SERNET_LEN_CHECK_BYTE(MAX_SERNET_PAYLOAD_SIZE, 0);
	for (int i = 0; i < MAX_SERNET_PAYLOAD_SIZE; i++)
	{
		packet.payload[i] = i;
	}
	
	uint8_t status = serNetTxEnqueue(&stack, &packet);
	ASSERT(status == SERNET_SUCCESS);

	uint8_t data = 0;
	status = serNetTxDequeue(&stack, &data);
	ASSERT(status == SERNET_SUCCESS);
	ASSERT(data == 0x01);
	
	status = serNetTxDequeue(&stack, &data);
	ASSERT(status == SERNET_SUCCESS);
	ASSERT(data == 0x02);

	status = serNetTxDequeue(&stack, &data);
	ASSERT(status == SERNET_SUCCESS);
	ASSERT(data == SET_SERNET_LEN_CHECK_BYTE(MAX_SERNET_PAYLOAD_SIZE, 0));
	ASSERT(GET_SERNET_PAYLOAD_LENGTH(data) == MAX_SERNET_PAYLOAD_SIZE);

	for (int i = 0; i < MAX_SERNET_PAYLOAD_SIZE; i++)
	{
		status = serNetTxDequeue(&stack, &data);
		ASSERT(status == SERNET_SUCCESS);
		ASSERT(data == packet.payload[i]);
	}

	status = serNetTxDequeue(&stack, &data);
	ASSERT(status == SERNET_ERROR_QUEUE_EMPTY);


	return true;
}