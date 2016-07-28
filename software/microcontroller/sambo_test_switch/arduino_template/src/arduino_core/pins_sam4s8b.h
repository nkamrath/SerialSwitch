/*
 * pins_sam4s8b.h
 *
 * Created: 3/15/2016 12:50:45 PM
 *  Author: Nate
 */ 


#ifndef PINS_SAM4S8B_H_
#define PINS_SAM4S8B_H_

#include <asf.h>
//#include "arduino_core/Arduino.h"

#define PIOA_FIRST_PIN			0
#define PIOA_NUM_PINS			10
#define PIOB_FIRST_PIN			(PIOA_FIRST_PIN + PIOA_NUM_PINS)
#define PIOB_NUM_PINS			10

/*
//Analog to Digital Converter Pins
#define ADC0					PA17
#define ADC1					PA18
#define ADC2					PA19
#define ADC3					PA20
#define ADC4					PB0
#define ADC5					PB1
#define ADC6					PB2
#define ADC7					PB3
#define ADC8					PA21
#define ADC9					PA22

//these only available on packages with more pinsd
#define ADC10					PC13
#define ADC11					PC15
#define ADC12					PC12
#define ADC13					PC29
#define ADC14					PC30 

//Digital to Analog pins
#define DAC0					PB13
#define DAC1					PB14

#define NUMBER_PINS				3
//Digital I/O Pins
#define DIGITAL_IO_1			PA17
#define DIGITAL_IO_2			PA18
#define DIGITAL_IO_3			PA19

//abstraction layer for generic "pins"
#define PIN1					DIGITAL_IO_1
#define PIN2					DIGITAL_IO_2
#define PIN3					DIGITAL_IO_3
*/

/*
mapping of pins that maps the integer number (1, 2...etc) that arduino uses
to the PIOX_PXX that atmel uses internally.  Index of the pins array
is the arduino number, data at that index is the index of the pin
according to internal atmel definitions
*/ 
#define NUMBER_PINS	12
const uint8_t PINS[NUMBER_PINS] = {PIO_PA0_IDX, PIO_PA1_IDX, PIO_PA2_IDX, 
								   PIO_PA3_IDX, PIO_PA4_IDX, PIO_PA5_IDX,
								   PIO_PA6_IDX, PIO_PA7_IDX, PIO_PA8_IDX,
								   PIO_PA9_IDX, PIO_PA10_IDX, PIO_PA11_IDX, };


#ifdef __cplusplus
extern "C" {
#endif

void pinMode(uint8_t pin, uint8_t mode);

void digitalWrite(uint8_t pin, uint8_t state);

#ifdef __cplusplus
}
#endif

#endif /* PINS_SAM4S8B_H_ */