/*
 * buzzer.c
 *
 *  Created on: Dec 8, 2022
 *      Author: duyvt
 */


#include "buzzer.h"

TIM_HandleTypeDef htim3;

int buzzer_flag =0;

void buzzerRun(){
	switch (buzzer_flag){
	case BUZZER_OFF:
		__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_1, 0);
		setTimer6(10);
		setTimer7(50);
		break;
	case BUZZER_ON:

		if (timer6_flag == 1){
			__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_1, (100 /(get_timer4_counter()/1000 +1)));
			setTimer6(250);
		}

		if (timer7_flag ==1){
			__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_1, 0);
			setTimer7(250);
		}
		break;
	default:
		break;
	}
}
