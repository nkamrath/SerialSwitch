/**
 * \file
 *
 * \brief User board initialization template
 *
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#include <asf.h>
#include <board.h>
#include <conf_board.h>

#include "arduino_core/internal_timer.h"

void board_init(void)
{
	/* This function is meant to contain board-specific initialization code
	 * for, e.g., the I/O pins. The initialization can rely on application-
	 * specific board configuration, found in conf_board.h.
	 */
	WDT->WDT_MR = WDT_MR_WDDIS;  //disable watchdog timer
	
	//init and start up the adc
	sysclk_enable_peripheral_clock(ID_ADC);
	adc_init(ADC, sysclk_get_main_hz(), sysclk_get_main_hz() / 4, 512);
	adc_configure_timing(ADC, 0, ADC_SETTLING_TIME_3, 1);
	adc_set_resolution(ADC, ADC_MR_LOWRES_BITS_12);
	adc_enable_channel(ADC, ADC_CHANNEL_3);
	adc_start(ADC);

	//configure timer counter to create milliseconds counter for Arduino
	//delay/millis functions
	internal_timer_configure(1000);
}
