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

		if (isButtonPedesPressed()){
			if (state_1 == AUTO_RED){
				setTimer4(get_timer2_counter());
				pedes_state = PEDES_GREEN;
			}else if (state_1 == AUTO_GREEN){
				setTimer4(get_timer2_counter() + amberTime);
				pedes_state = PEDES_RED;
			}else{
				setTimer4(get_timer2_counter());
				pedes_state = PEDES_RED;
			}

			setTimer5(redTime + amberTime + greenTime);
		}
		break;
	case PEDES_GREEN:
		HAL_GPIO_WritePin(PLED_GREEN_GPIO_Port, PLED_GREEN_Pin, 1);
		HAL_GPIO_WritePin(PLED_RED_GPIO_Port, PLED_RED_Pin, 0);

		if (timer4_flag ==1){
			pedes_state = PEDES_RED;
			setTimer4(redTime);
		}
		if (timer5_flag ==1){
			pedes_state = PEDES_OFF;
		}
		break;
	case PEDES_RED:
		HAL_GPIO_WritePin(PLED_GREEN_GPIO_Port, PLED_GREEN_Pin, 0);
		HAL_GPIO_WritePin(PLED_RED_GPIO_Port, PLED_RED_Pin, 1);

		if (timer4_flag ==1){
			pedes_state = PEDES_OFF;
			setTimer4(greenTime +amberTime);
		}
		if (timer5_flag ==1){
			pedes_state = PEDES_OFF;
		}
		break;
	default:
		break;
	}
}
