/*
 * led.c
 *
 *  Created on: Nov 6, 2022
 *      Author: ADMIN
 */

#include "led.h"

void led_blinky(){
	switch(ledstate){
	case 0:
		//TO DO
		setTimer3(1000);
		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
		ledstate = 1;
		break;
	case 1:
		//TO DO
		if(timer3_flag == 1){
			setTimer3(1000);
			ledstate = 0;
		}

		break;
	default:
		//TO DO

		break;
	}
}
