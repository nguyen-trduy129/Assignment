/*
 * button.c
 *
 *  Created on: Dec 8, 2022
 *      Author: duyvt
 */

#include "button.h"

int button1_flag = 0;
int button2_flag =0;
int button3_flag =0;
int buttonPedes_flag =0;

int KeyReg0[4] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg1[4] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg2[4] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};

int KeyReg3[4] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};

int timeForKeyPressed[4] = {300/TICK, 300/TICK, 300/TICK, 300/TICK};

int isButton1Pressed(){
	if (button1_flag ==1){
		button1_flag =0;
		return 1;
	}
	return 0;
}

int isButton2Pressed(){
	if (button2_flag ==1){
		button2_flag =0;
		return 1;
	}
	return 0;
}

int isButton3Pressed(){
	if (button3_flag ==1){
		button3_flag =0;
		return 1;
	}
	return 0;
}

int isButtonPedesPressed(){
	if (buttonPedes_flag ==1){
		buttonPedes_flag =0;
		return 1;
	}
	return 0;
}

void doProcess(int i){
	switch (i){
	case 0:
		button1_flag =1;
		break;
	case 1:
		button2_flag =1;
		break;
	case 2:
		button3_flag =1;
		break;
	case 3:
		buttonPedes_flag =1;
		break;
	default:
		break;
	}
}


int readPin(int i){
	switch(i){
	case 0:
		return HAL_GPIO_ReadPin(GPIOA, BUTTON1_Pin);
		break;
	case 1:
		return HAL_GPIO_ReadPin(GPIOA, BUTTON2_Pin);
		break;
	case 2:
		return HAL_GPIO_ReadPin(GPIOB, BUTTON3_Pin);
		break;
	case 3:
		return HAL_GPIO_ReadPin(GPIOA, BUTTON_PEDES_Pin);
		break;
	default:
		return GPIO_PIN_RESET;
		break;
	}
}


void getKeyInput(){
	for (int i =0; i<4; i++){
		KeyReg0[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg2[i];
		KeyReg2[i] = readPin(i);

		if (KeyReg0[i] == KeyReg1[i] && KeyReg1[i] == KeyReg2[i]){
			if (KeyReg2[i] != KeyReg3[i]){
				KeyReg3[i] = KeyReg2[i];
				if (KeyReg2[i] == PRESSED_STATE){
					timeForKeyPressed[i] = 300/TICK;
					doProcess(i);
				}
			}else {
				timeForKeyPressed[i]--;
				if (timeForKeyPressed[i] ==0){
					KeyReg3[i] =NORMAL_STATE;
					timeForKeyPressed[i] = 300/TICK;
				}
			}
		}
	}
}
