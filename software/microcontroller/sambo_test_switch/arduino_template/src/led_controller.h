/*
 * led_controller.h
 *
 * Created: 3/22/2016 9:36:34 AM
 *  Author: Nate
 */ 


#ifndef LED_CONTROLLER_H_
#define LED_CONTROLLER_H_

#define NUM_LEDS			4

//define in Arduino pin number style the led control pins.
const uint8_t LED_PINS[NUM_LEDS] = {0, 1, 2, 3};

#ifdef __cplusplus
extern "C" {
#endif

void led_controller_init(void);

void toggle_led(uint8_t led_number);


#ifdef __cplusplus
}
#endif


#endif /* LED_CONTROLLER_H_ */