/*
 * fsm_automatic.c
 *
 *  Created on: Nov 5, 2022
 *      Author: ADMIN
 */
#include "fsm_automatic.h"

void fsm_automatic_run(){
	switch(status){
	case	INIT:
		//TO DO
		set_default();

		status = AUTO_RED;
		setTimer1(5000);
		break;
	case	AUTO_RED:
		//TODO
		set_red();

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
		set_green();

		if(timer1_flag == 1){
			status = AUTO_YELLOW;
			setTimer1(2000);
		}
		break;
	case	AUTO_YELLOW:
		//TODO
		set_yellow();
		if(timer1_flag == 1){
			status = AUTO_RED;
			setTimer1(5000);
		}
		break;
	default:
		break;
	}
}