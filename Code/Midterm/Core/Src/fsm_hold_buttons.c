/*
 * fsm_hold_buttons.c
 *
 *  Created on: Nov 5, 2022
 *      Author: ADMIN
 */
#include "fsm_hold_buttons.h"
#include "button.h"

void fsm_hold_buttons_run (){
	switch(status){
	case RESET:
		//TO DO
		display7SEG(0);
		if(isButtonINCholding() == 1){
			counter = 1;
			display7SEG(3);
			status = HOLD_INC;
		}
		if(isButtonDECholding() == 1){
			counter = 9;
			display7SEG(counter);
			status = HOLD_DEC;
		}
		if(isButtonRESETpressed() == 1){
			counter = 0;
			display7SEG(counter);
			status = RESET;
		}
		if(isButtonINCpressed() == 1){
			counter = 1;
			display7SEG(counter);
			status = INC;
		}
		if (isButtonDECpressed() == 1){
			counter = 9;
			display7SEG(counter);
			status = DEC;
		}

		break;
	case INC:
		//TO DO
		if(isButtonINCholding() == 1){
			counter++;
			if(counter == 10) counter = 0;
			display7SEG(9);
			status = HOLD_INC;
		}
		if(isButtonDECholding() == 1){
			counter--;
			display7SEG(counter);
			status = HOLD_DEC;
		}
		if(isButtonRESETpressed() == 1){
			counter = 0;
			display7SEG(counter);
			status = RESET;
		}
		if(isButtonINCpressed() == 1){
			counter++;
			if(counter == 10) counter = 0;
			display7SEG(counter);
			status = INC;
		}
		if (isButtonDECpressed() == 1){
			counter--;
			display7SEG(counter);
			status = DEC;
		}
		break;
	case HOLD_INC:
		//TO DO
		if(isButtonINCholding() == 1){
			counter++;
			if(counter == 10) counter = 0;
			display7SEG(6);
			status = HOLD_INC;
		}
		if(isButtonDECholding() == 1){
			counter--;
			display7SEG(counter);
			status = HOLD_DEC;
		}
		if(isButtonRESETpressed() == 1){
			counter = 0;
			display7SEG(counter);
			status = RESET;
		}
		if(isButtonINCpressed() == 1){
			counter++;
			if(counter == 10) counter = 0;
			display7SEG(counter);
			status = INC;
		}
		if (isButtonDECpressed() == 1){
			counter--;
			display7SEG(counter);
			status = DEC;
		}
		break;
	case DEC:
		//TO DO
		if(isButtonRESETpressed() == 1){
			counter = 0;
			display7SEG(counter);
			status = RESET;
		}
		if(isButtonINCpressed() == 1){
			counter++;
			display7SEG(counter);
			status = INC;
		}
		if (isButtonDECpressed() == 1){
			counter--;
			if(counter == -1) counter = 9;
			display7SEG(counter);
			status = DEC;
		}
		if(isButtonINCholding() == 1){
			counter++;
			display7SEG(counter);
			status = HOLD_INC;
		}
		if(isButtonDECholding() == 1){
			counter--;
			if(counter == -1) counter = 9;
			display7SEG(counter);
			status = DEC;
		}
		break;
	case HOLD_DEC:
		//TO DO
		if(isButtonRESETpressed() == 1){
			counter = 0;
			display7SEG(counter);
			status = RESET;
		}
		if(isButtonINCpressed() == 1){
			counter++;
			display7SEG(counter);
			status = INC;
		}
		if (isButtonDECpressed() == 1){
			counter--;
			if(counter == -1) counter = 9;
			display7SEG(counter);
			status = DEC;
		}
		if(isButtonINCholding() == 1){
			counter++;
			display7SEG(counter);
			status = HOLD_INC;
		}
		if(isButtonDECholding() == 1){
			counter--;
			if(counter == -1) counter = 9;
			display7SEG(counter);
			status = DEC;
		}
		break;
	default:
		//NOTHING
		break;
	}
}
