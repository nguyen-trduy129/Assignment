/*
 * buzzer.c
 *
 *  Created on: Dec 8, 2022
 *      Author: duyvt
 */


#include "buzzer.h"

TIM_HandleTypeDef htim3;

void buzzerRun(int value){
	__HAL_TIM_SetCompare (&htim3,TIM_CHANNEL_1,value);
	setTimer6(10+value*10);
}
