/**
 * \file interrupts.cpp
 *
 * \brief Hardware Interrupt Service Routines source.
 *
 * Copyright (c) 2016 Nate Kamrath. All rights reserved.
 *
 * \sambo_license_start
 *
 * \page "SAMBO License"
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL AUTHORS BE LIABLE 
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \sambo_license_stop
 *
 */

#ifdef __cplusplus
//extern "C" {
//#endif

#include <asf.h>
//#include "HardwareSerialUart.h"

extern HardwareSerialUsart Serial1;
extern HardwareSerialUsart Serial2;

extern HardwareSerialUart Serial3;
extern HardwareSerialUart Serial4;

void UART0_Handler()
{
	uint32_t uart_status = uart_get_status(UART0);
	if(uart_status & UART_SR_RXRDY)
	{
		//uint8_t data;
		//uart_read(UART0, &data);
		Serial3.rx_ready_callback();
	}
	
	if(uart_status & UART_SR_TXEMPTY)
	{
		Serial3.tx_empty_callback();
	}
}

void UART1_Handler()
{
	uint32_t uart_status = uart_get_status(UART0);
	if(uart_status & UART_SR_RXRDY)
	{
		//uint8_t data;
		//uart_read(UART0, &data);
		Serial4.rx_ready_callback();
	}
	
	if(uart_status & UART_SR_TXEMPTY)
	{
		Serial4.tx_empty_callback();
	}
}

void USART0_Handler()
{
	uint32_t usart_status = usart_get_status(USART0);
	if(usart_status & US_CSR_RXRDY)
	{
		Serial1.rx_ready_callback();
	}
	
	if(usart_status & US_CSR_TXRDY)
	{
		Serial1.tx_empty_callback();
	}
}

void USART1_Handler()
{
	uint32_t usart_status = usart_get_status(USART1);
	if(usart_status & US_CSR_RXRDY)
	{
		Serial2.rx_ready_callback();
	}
	
	if(usart_status & US_CSR_TXRDY)
	{
		Serial2.tx_empty_callback();
	}
}

//#ifdef __cplusplus
//}
#endif