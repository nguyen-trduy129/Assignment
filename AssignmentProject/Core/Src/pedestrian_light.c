/*
 * pedestrian_light.c
 *
 *  Created on: Dec 8, 2022
 *      Author: duyvt
 */

#include "pedestrian_light.h"

int pedes_state = PEDES_INIT;
int pedes_flag =0;

void pedes_light_fsm(){
	switch(pedes_state){
	case PEDES_INIT:
		pedes_state = PEDES_OFF;

		break;
	case PEDES_OFF:
		HAL_GPIO_WritePin(PLED_GREEN_GPIO_Port, PLED_GREEN_Pin, 0);
		HAL_GPIO_WritePin(PLED_RED_GPIO_Port, PLED_RED_Pin, 0);
		buzzer_flag = BUZZER_OFF;

		if (isButtonPedesPressed()){
			if (state_1 == AUTO_RED){
				setTimer4(get_timer2_counter());
				pedes_state = PEDES_GREEN;
			}else if (state_1 == AUTO_GREEN){
				setTimer4(get_timer2_counter() + amberTime*1000);
				pedes_state = PEDES_RED;
			}else if (state_1 == AUTO_AMBER){
				setTimer4(get_timer2_counter());
				pedes_state = PEDES_RED;
			}

			setTimer5((redTime + amberTime + greenTime) *2000);
		}
		break;
	case PEDES_GREEN:
		HAL_GPIO_WritePin(PLED_GREEN_GPIO_Port, PLED_GREEN_Pin, 1);
		HAL_GPIO_WritePin(PLED_RED_GPIO_Port, PLED_RED_Pin, 0);
		buzzer_flag = BUZZER_ON;

		if (timer4_flag ==1){
			pedes_state = PEDES_RED;
			setTimer4((greenTime +amberTime) *1000);
		}
		if (timer5_flag ==1){
			pedes_state = PEDES_OFF;
		}

		if (mode != MODE_1){
			pedes_state = PEDES_OFF;
		}
		break;
	case PEDES_RED:
		HAL_GPIO_WritePin(PLED_GREEN_GPIO_Port, PLED_GREEN_Pin, 0);
		HAL_GPIO_WritePin(PLED_RED_GPIO_Port, PLED_RED_Pin, 1);
		buzzer_flag = BUZZER_OFF;

		if (timer4_flag ==1){
			pedes_state = PEDES_GREEN;
			setTimer4(redTime *1000);
		}
		if (timer5_flag ==1){
			pedes_state = PEDES_OFF;
		}

		if (mode != MODE_1){
			pedes_state = PEDES_OFF;
		}
		break;
	default:
		break;
	}
}
