/*
 * fsm_automatic.c
 *
 *  Created on: Nov 5, 2022
 *      Author: ADMIN
 */
#include <fsm_simple_buttons.h>
int counter = 0;
void fsm_simple_buttons_run (){

	switch(status){
	case RESET:
		//TO DO
		display7SEG(0);
		if(isButtonRESETpressed() == 1){
			counter = 0;
			display7SEG(counter);
			status = RESET;
		}
		else if(isButtonINCpressed() == 1){
			counter = 1;
			display7SEG(counter);
			status = INC;
		} else
			if (isButtonDECpressed() == 1){
			counter = 0;
			display7SEG(counter);
			status = DEC;
		}
		else {
			//NOTHING
		}
		break;
	case INC:
		//TO DO
		if(isButtonRESETpressed() == 1){
			counter = 0;
			display7SEG(counter);
			status = RESET;
		}
		else if(isButtonINCpressed() == 1){
			counter++;
			if(counter == 10) counter = 0;
			display7SEG(counter);
			status = INC;
		} else
			if (isButtonDECpressed() == 1){
			counter--;
			display7SEG(counter);
			status = DEC;
		}
		else {
			//NOTHING
		}
		break;
	case DEC:
		//TO DO
		if(isButtonRESETpressed() == 1){
			counter = 0;
			display7SEG(counter);
			status = RESET;
		}
		else if(isButtonINCpressed() == 1){
			counter++;
			display7SEG(counter);
			status = INC;
		} else
			if (isButtonDECpressed() == 1){
			counter--;
			if(counter == -1) counter = 9;
			display7SEG(counter);
			status = DEC;
		}
		else {
			//NOTHING
		}
		break;
	default:
		break;
	}
}
