/*
 * led_controller.cpp
 *
 * Created: 3/22/2016 9:36:48 AM
 *  Author: Nate
 */ 

#include "led_controller.h"

uint8_t led_states[NUM_LEDS];

void led_controller_init(void)
{
	for(int i = 0; i < NUM_LEDS; i++)
	{
		led_states[i] = 0;
		digitalWrite(LED_PINS[i], LOW);
	}
}

void toggle_led(uint8_t led_number)
{
	led_states[led_number] = !led_states[led_number];
	digitalWrite(LED_PINS[led_number], led_states[led_number]);
}