/*
 * fsm_manual.c
 *
 *  Created on: Nov 5, 2022
 *      Author: ADMIN
 */

#include "fsm_manual.h"

void fsm_manual_run(){
	switch(status){
	case	MAN_RED:
		set_red();
		if(timer1_flag == 1){
			status = AUTO_RED;
			setTimer1(5000);
		}
		if(isButton1Pressed()==1){
			status = MAN_GREEN;
			setTimer1(10000);
		}
		break;
	case	MAN_GREEN:
		set_green();
		if(timer1_flag == 1){
			status = AUTO_GREEN;
			setTimer1(5000);
		}
		if(isButton1Pressed()==1){
			status = MAN_YELLOW;
			setTimer1(10000);
		}
		break;
	case	MAN_YELLOW:
		set_yellow();
		if(timer1_flag == 1){
			status = AUTO_YELLOW;
			setTimer1(5000);
		}
		if(isButton1Pressed()==1){
			status = MAN_RED;
			setTimer1(10000);
		}
		break;
	default:
		break;
	}
}
