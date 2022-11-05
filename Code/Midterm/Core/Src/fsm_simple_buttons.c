/*
 * fsm_automatic.c
 *
 *  Created on: Nov 5, 2022
 *      Author: ADMIN
 */
#include <fsm_simple_buttons.h>

void fsm_automatic_run(){
	switch(status){
	case	INIT:
		//TO DO
		setTimer1(5000);
		break;
	case	AUTO_RED:
		//TODO
		if(timer1_flag == 1){
			status = AUTO_GREEN;
			setTimer1(3000);
		}
		if(isButton1Pressed()==1){
			status = MAN_RED;
			setTimer1(1000);
		}
		break;
	case	AUTO_GREEN:
		//TODO
		if(timer1_flag == 1){
			status = AUTO_YELLOW;
			setTimer1(2000);
		}
		break;
	case	AUTO_YELLOW:
		//TODO
		if(timer1_flag == 1){
			status = AUTO_RED;
			setTimer1(5000);
		}
		break;
	default:
		break;
	}
}
