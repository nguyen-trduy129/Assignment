/*
 * global.c
 *
 *  Created on: Dec 8, 2022
 *      Author: duyvt
 */


#include "global.h"

int state_1 = 0;
int state_2 = 0;
int mode = 0;
int redTime = 5;
int amberTime = 2;
int greenTime = 3;

void ledBlink(){
	if (timer1_flag ==1){
		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
		setTimer1(250);
	}
}
