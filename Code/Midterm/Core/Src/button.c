/*
 * button.c
 *
 *  Created on: Nov 4, 2022
 *      Author: ADMIN
 */
#include "button.h"
//RESET
int TimerForKeyRESETPress = 200;
int button1_flag = 0;
int KeyRegRESET0 = NORMAL_STATE;
int KeyRegRESET1 = NORMAL_STATE;
int KeyRegRESET2 = NORMAL_STATE;
int KeyRegRESET3 = NORMAL_STATE;
//INC
int TimerForKeyINCPress = 200;
int button2_flag = 0;
int KeyRegINC0 = NORMAL_STATE;
int KeyRegINC1 = NORMAL_STATE;
int KeyRegINC2 = NORMAL_STATE;
int KeyRegINC3 = NORMAL_STATE;
//DEC
int TimerForKeyDECPress = 200;
int button3_flag = 0;
int KeyRegDEC0 = NORMAL_STATE;
int KeyRegDEC1 = NORMAL_STATE;
int KeyRegDEC2 = NORMAL_STATE;
int KeyRegDEC3 = NORMAL_STATE;

//Button is press?
int isButtonRESETpressed(){
	if(button1_flag == 1){
		button1_flag = 0;
		return 1;
	}
	return 0;
}
int isButtonINCpressed(){
	if(button2_flag == 1){
		button2_flag = 0;
		return 1;
	}
	return 0;
}
int isButtonDECpressed(){
	if(button3_flag == 1){
		button3_flag = 0;
		return 1;
	}
	return 0;
}


//sub key
void subKeyRESETProcess(){
	//TODO
	button1_flag = 1;
}
void subKeyINCProcess(){
	//TODO
	button2_flag = 1;
}
void subKeyDECProcess(){
	//TODO
	button3_flag = 1;
}


//Get key
void getKeyRESETinput(){
	KeyRegRESET0 = KeyRegRESET1;
	KeyRegRESET1 = KeyRegRESET2;
	KeyRegRESET2 = HAL_GPIO_ReadPin(RESET_GPIO_Port, RESET_Pin);
	if((KeyRegRESET0 == KeyRegRESET1) && (KeyRegRESET1 == KeyRegRESET2)){
		if(KeyRegRESET3 != KeyRegRESET2){
			KeyRegRESET3 = KeyRegRESET2;
			if(KeyRegRESET2 == PRESSED_STATE){
				//TODO
				subKeyRESETProcess();
				TimerForKeyRESETPress = 200;
			}
		} else {
			TimerForKeyRESETPress--;
			if(TimerForKeyRESETPress == 0){
				//TODO
				if(KeyRegRESET2 == PRESSED_STATE){
					subKeyRESETProcess();
				}
				TimerForKeyRESETPress = 200;
			}
		}
	}
}

void getKeyINCinput(){
	KeyRegINC0 = KeyRegINC1;
	KeyRegINC1 = KeyRegINC2;
	KeyRegINC2 = HAL_GPIO_ReadPin(INC_GPIO_Port, INC_Pin);
	if((KeyRegINC0 == KeyRegINC1) && (KeyRegINC1 == KeyRegINC2)){
		if(KeyRegINC3 != KeyRegINC2){
			KeyRegINC3 = KeyRegINC2;
			if(KeyRegINC2 == PRESSED_STATE){
				//TODO
				subKeyINCProcess();
				TimerForKeyINCPress = 200;
			}
		} else {
			TimerForKeyINCPress--;
			if(TimerForKeyINCPress == 0){
				//TODO
				if(KeyRegINC2 == PRESSED_STATE){
					subKeyINCProcess();
				}
				TimerForKeyINCPress = 200;
			}
		}
	}
}
void getKeyDECinput(){
	KeyRegDEC0 = KeyRegDEC1;
	KeyRegDEC1 = KeyRegDEC2;
	KeyRegDEC2 = HAL_GPIO_ReadPin(DEC_GPIO_Port, DEC_Pin);
	if((KeyRegDEC0 == KeyRegDEC1) && (KeyRegDEC1 == KeyRegDEC2)){
		if(KeyRegDEC3 != KeyRegDEC2){
			KeyRegDEC3 = KeyRegDEC2;
			if(KeyRegDEC2 == PRESSED_STATE){
				//TODO
				subKeyDECProcess();
				TimerForKeyDECPress = 200;
			}
		} else {
			TimerForKeyDECPress--;
			if(TimerForKeyDECPress == 0){
				//TODO
				if(KeyRegDEC2 == PRESSED_STATE){
					subKeyDECProcess();
				}
				TimerForKeyDECPress = 200;
			}
		}
	}
}
