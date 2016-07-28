/**
 * \file PinIO.cpp
 *
 * \brief PinIO library for digital and analog I/O on the pin level.
 * facilitates basic pin read/write functionality.
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

#include "PinIO.h"
#include "pins_sam4s8b.h"
#include "Arduino.h"


void get_pio_index(uint8_t pin_number, Pio* pio, uint8_t* pin_index)
{
	if(pin_number < PIO_PB0_IDX)
	{
		pio = PIOA;
	}
	else
	{
		pio = PIOB;
	}

	//getting the pin index within this PIO Controller requires the modulus
	//32 because there are 32 bits in each PIO
	*pin_index = (PINS[pin_number] % 32);
}

Pio* get_pio(uint8_t pin)
{
	if(pin < PIO_PB0_IDX)
	{
		return PIOA;
	}
	else
	{
		return PIOB;
	}		
}

uint8_t get_pin_index(uint8_t pin)
{
	return (PINS[pin] % 32);
}

void pinMode(uint8_t pin, uint8_t mode)
{
	uint8_t internal_pin_index = 0;
	Pio* pio_ptr = get_pio(pin);
	internal_pin_index = get_pin_index(pin);
	
	if(mode == INPUT)
	{
		pio_set_input(pio_ptr, (1<<internal_pin_index), PIO_DEFAULT);
	}
	else if(mode == OUTPUT)
	{
		pio_set_output(pio_ptr, (1<<internal_pin_index), LOW, DISABLE, ENABLE);
	}
}

int digitalRead(uint8_t pin)
{
	//make sure the pin is in range of I/O
	if(pin >= NUMBER_PINS)
	{
		return NOT_A_PIN;
	}
	
	return LOW;
}

void digitalWrite(uint8_t pin, uint8_t state)
{
	uint8_t internal_pin_index = 0;
	Pio* pio_ptr = get_pio(pin);
	internal_pin_index = get_pin_index(pin);
	
	if(state == HIGH)
	{
		pio_set(pio_ptr, (1<<internal_pin_index));
	}
	else
	{
		pio_clear(pio_ptr, (1<<internal_pin_index));
	}
}


int analogRead(uint8_t pin)
{
	//set this pin to connect to adc.  ADC is periph b for all adc pins
	pio_configure(PIOA, PIO_PERIPH_B, PINS[pin], PIO_DEFAULT);
	adc_enable_interrupt(ADC, ADC_IER_DRDY);
	adc_configure_trigger(ADC, ADC_TRIG_SW, 0);
	
	adc_start(ADC);
	//wait for the conversion to finish
	while((adc_get_status(ADC) & ADC_ISR_DRDY) == 0); 
	
	adc_disable_interrupt(ADC, ADC_IDR_DRDY);
	int result = adc_get_latest_value(ADC);
	return result;
}
