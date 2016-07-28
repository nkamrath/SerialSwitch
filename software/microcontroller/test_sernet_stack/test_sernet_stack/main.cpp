//main file for sernet stack tests

#include <iostream>

#include "sernet_packet.h"
#include "sernet_stack.h"

#include "sernet_tests.h"

using namespace std;

bool runTest(bool(*testFunction)(), const char* testName, int* passed, int* failed)
{
	cout << "[RUN]\t" << testName << endl;
	bool result = testFunction();
	if (result)
	{
		cout << "[PASS]" << endl;
		(*passed)++;
	}
	else
	{
		cout << "[FAIL]" << endl;
		(*failed)++;
	}
	return result;
}

int main()
{
	cout << "Serial Network Stack Test Suite" << endl;

	int passed = 0;
	int failed = 0;

	
	runTest(testInitialization, "Test SerNetStack Initialization", &passed, &failed);
	runTest(testEmptyDequeueTx, "Test Empty Dequeue TX", &passed, &failed);
	runTest(testEmptyDequeueRx, "Test Empty Dequeue RX", &passed, &failed);
	runTest(testSingleEnqueueDequeueTx, "Test Single Enqueue/Dequeue TX", &passed, &failed);
	runTest(testSingleEnqueueDequeueRx, "Test Single Enqueue/Dequeue RX", &passed, &failed);
	runTest(testNullEnqueueRx, "Test Null Enqueue RX", &passed, &failed);
	runTest(testNullEnqueueTx, "Test Null Enqueue TX", &passed, &failed);
	runTest(testNullDequeueRx, "Test Null Dequeue RX", &passed, &failed);
	runTest(testNullDequeueTx, "Test Null Dequeue TX", &passed, &failed);
	runTest(testMaxPacketSizeEnqueueRx, "Test Max Packet Size Enqueue RX", &passed, &failed);
	runTest(testMaxPacketSizeEnqueueTx, "Test Max Packet Size Enqueue TX", &passed, &failed);

	cout << "--------------------------------------------------------" << endl;
	cout << "Test Results: " << endl;
	cout << "Tests Ran:\t\t" << (passed + failed) << endl;
	cout << "Tests Passed:\t\t" << passed << endl;
	cout << "Tests Failed: \t\t" << failed << endl;
	cout << "--------------------------------------------------------" << endl;

	//wait for input before exiting
	char waitKey;
	cin >> waitKey;
}