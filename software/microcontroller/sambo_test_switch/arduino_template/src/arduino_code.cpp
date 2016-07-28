/*
 * arduino_code.cpp
 *
 * Created: 3/11/2016 9:30:57 AM
 *  Author: Nate
 */ 

#include <stdint.h>

/** \brief Size of the SerNet stack internal queues in packets **/
#define MAX_SERNET_PAYLOAD_SIZE							4
#define SERNET_HEADER_SIZE								3
#define MAX_SERNET_PACKET_SIZE							(SERNET_HEADER_SIZE + MAX_SERNET_PAYLOAD_SIZE)

#define GET_SERNET_PAYLOAD_LENGTH(lenCheckByte)			((lenCheckByte>>6) + 1)
#define SET_SERNET_LEN_CHECK_BYTE(length, checksum)		((((length - 1) & 0x03) << 6) | (checksum & 0x3f))

int byteCounter = 0;
int myAddress = 0;
int bufferIndex = 0;
char buffer[128];

void setup(void)
{
	Serial.begin(115200);
	Serial1.begin(115200);
	
	pmc_enable_periph_clk(ID_PIOA);
	
	
	delay(2000);
	//Get my address
	Serial.println("Enter this unit's address");
	while(Serial.available() == 0);  //wait for byte
	myAddress = Serial.read() - 48;
	Serial.print("Requesting Address from switch: ");
	Serial.println(myAddress);
	
	//request address from the server
	Serial1.write(0x00);
	Serial1.write(myAddress);
	Serial1.write(SET_SERNET_LEN_CHECK_BYTE(2, 0x00));
	Serial1.write(0x01);
	Serial1.write(myAddress);
}

void loop(void)
{
	if(Serial.available() > 0)
	{
		//write to sernet packet and send
		char c = Serial.read();
		if((c == '\r' || c == '\n') && bufferIndex > 0)
		{
			//send the buffer
			int readIndex = 0;
			int toAddress = buffer[0] - 48;
			readIndex ++;
			while(readIndex < bufferIndex)
			{
				//first byte is to address
				Serial1.write(toAddress);
				Serial1.write(myAddress);
				Serial1.write(SET_SERNET_LEN_CHECK_BYTE(0x01, 0x00));
				Serial1.write(buffer[readIndex]);
				readIndex++;
			}
			bufferIndex = 0;
			Serial.println("Sent Packet");
		}
		else if(c == '\r' || c == '\n')
		{
			bufferIndex = 0;
			Serial1.flush();
			Serial.println("Flushed");
		}
		else
		{
			buffer[bufferIndex] = c;
			bufferIndex++;
		}
	}
	
	if(Serial1.available() > 3)
	{
		int toAddress = Serial1.read();
		int fromAddress = Serial1.read();
		int lenCheck = Serial1.read();
		int data = Serial1.read();
		Serial.print("Got Data: ");
		Serial.print(fromAddress);
		Serial.print(" ");
		Serial.println((char)data);
	}
	
}