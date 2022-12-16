/*
 * traffic_automatic.c
 *
 *  Created on: Dec 8, 2022
 *      Author: duyvt
 */

#include "traffic_automatic.h"

void fsm_automatic_run(){
	switch(state_1){
	case INIT:
		state_1 = AUTO_RED;
		setTimer2(redTime*1000);
		break;
	case AUTO_RED:
		HAL_GPIO_WritePin(GPIOA,TRAFFIC1_1_Pin , 1);
		HAL_GPIO_WritePin(GPIOB,TRAFFIC1_0_Pin , 0);

		if(timer2_flag ==1){
			state_1 = AUTO_GREEN;
			setTimer2(greenTime*1000);
		}

		if (isButton1Pressed()){
			state_1 = MAN_RED;
			setTimer2(WAITING_TIME);
		}

		break;
	case AUTO_GREEN:
		HAL_GPIO_WritePin(GPIOA,TRAFFIC1_1_Pin , 0);
		HAL_GPIO_WritePin(GPIOB,TRAFFIC1_0_Pin , 1);

		if(timer2_flag ==1){
			state_1 = AUTO_AMBER;
			setTimer2(amberTime*1000);
		}

		if (isButton1Pressed()){
			state_1 = MAN_RED;
			setTimer2(WAITING_TIME);
		}

		break;
	case AUTO_AMBER:
		HAL_GPIO_WritePin(GPIOA,TRAFFIC1_1_Pin , 1);
		HAL_GPIO_WritePin(GPIOB,TRAFFIC1_0_Pin , 1);

		if(timer2_flag ==1){
			state_1 = AUTO_RED;
			setTimer2(redTime*1000);
		}

		if (isButton1Pressed()){
			state_1 = MAN_RED;
			setTimer2(WAITING_TIME);
		}

		break;
	default:
		break;
	}

	switch(state_2){
		case INIT:
			state_2 = AUTO_GREEN;
			setTimer3(greenTime*1000);
			break;
		case AUTO_GREEN:
			HAL_GPIO_WritePin(GPIOB,TRAFFIC2_1_Pin , 0);
			HAL_GPIO_WritePin(GPIOB,TRAFFIC2_0_Pin , 1);


			if(timer3_flag ==1){
				state_2 = AUTO_AMBER;
				setTimer3(amberTime*1000);
			}

			break;
		case AUTO_AMBER:
			HAL_GPIO_WritePin(GPIOB,TRAFFIC2_0_Pin , 1);
			HAL_GPIO_WritePin(GPIOB,TRAFFIC2_1_Pin , 1);
			if(timer3_flag ==1){
				state_2 = AUTO_RED;
				setTimer3(redTime*1000);
			}

			if (isButton1Pressed()){
				state_2 = MAN_GREEN;
				setTimer3(WAITING_TIME);
			}
			break;
		case AUTO_RED:
			HAL_GPIO_WritePin(GPIOB,TRAFFIC2_1_Pin , 1);
			HAL_GPIO_WritePin(GPIOB,TRAFFIC2_0_Pin , 0);

			if(timer3_flag ==1){
				state_2 = AUTO_GREEN;
				setTimer3(greenTime*1000);
			}

			if (isButton1Pressed()){
				state_2 = MAN_GREEN;
				setTimer3(WAITING_TIME);
			}
			break;
		default:
			break;
		}
}
