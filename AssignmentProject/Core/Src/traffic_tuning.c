/*
 * traffic_tuning.c
 *
 *  Created on: Dec 9, 2022
 *      Author: duyvt
 */

#include "traffic_tuning.h"

void fsm_tuning_run1(){
	switch(state_1){
	case TUN_GREEN:
		if (timer2_flag ==1){
			HAL_GPIO_TogglePin(GPIOB, TRAFFIC1_0_Pin);
			setTimer2(250);
		}

		if(mode == MODE_1){
			state_1 = AUTO_RED;
			setTimer2(redTime*1000);
		}

		break;
	case TUN_AMBER:
		if (timer2_flag ==1){
			HAL_GPIO_TogglePin(GPIOA, TRAFFIC1_1_Pin);
			HAL_GPIO_TogglePin(GPIOB, TRAFFIC1_0_Pin);
			setTimer2(250);
		}

		if(mode == MODE_1){
			state_1 = AUTO_RED;
			setTimer2(redTime*1000);
		}

		break;
	case TUN_RED:
		if (timer2_flag ==1){
			HAL_GPIO_TogglePin(GPIOA, TRAFFIC1_1_Pin);
			setTimer2(250);
		}

		if(mode == MODE_1){
			state_1 = AUTO_RED;
			setTimer2(redTime*1000);
		}

		break;
	default:
		break;
	}
}

void fsm_tuning_run2(){
	switch(state_2){
	case TUN_GREEN:
		if (timer3_flag ==1){
			HAL_GPIO_TogglePin(GPIOB, TRAFFIC2_0_Pin);
			setTimer3(250);
		}

		if(mode == MODE_1){
			state_2 = AUTO_GREEN;
			setTimer3(greenTime*1000);
		}

		break;
	case TUN_AMBER:
		if (timer3_flag ==1){
			HAL_GPIO_TogglePin(GPIOB, TRAFFIC2_1_Pin);
			HAL_GPIO_TogglePin(GPIOB, TRAFFIC2_0_Pin);
			setTimer3(250);
		}

		if(mode == MODE_1){
			state_2 = AUTO_GREEN;
			setTimer3(greenTime*1000);
		}

		break;
	case TUN_RED:
		if (timer3_flag ==1){
			HAL_GPIO_TogglePin(GPIOB, TRAFFIC2_1_Pin);
			setTimer3(250);
		}

		if(mode == MODE_1){
			state_2 = AUTO_GREEN;
			setTimer3(greenTime*1000);
		}

		break;
	default:
		break;
	}
}
