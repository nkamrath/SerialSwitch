#pragma once

#include "sernet_packet.h"
#include "sernet_stack.h"

#define ASSERT(x)			if (x == false) return false;

bool testInitialization();
bool testEmptyDequeueTx();
bool testEmptyDequeueRx();
bool testSingleEnqueueDequeueTx();
bool testSingleEnqueueDequeueRx();

bool testNullEnqueueRx();
bool testNullEnqueueTx();
bool testNullDequeueRx();
bool testNullDequeueTx();

bool testMaxPacketSizeEnqueueRx();
bool testMaxPacketSizeEnqueueTx();

