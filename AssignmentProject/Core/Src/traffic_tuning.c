/*
 * traffic_tuning.c
 *
 *  Created on: Dec 9, 2022
 *      Author: duyvt
 */

#include "traffic_tuning.h"

void fsm_tuning_run(){
	switch(state_1){
	case TUN_GREEN:
		if (timer2_flag ==1){
			HAL_GPIO_TogglePin(GPIOA, TRAFFIC1_0_Pin);
			setTimer2(250);
		}

		if(isButton1Pressed()){
			state_1 = AUTO_RED;
			setTimer2(redTime*1000);
		}

		if (isButton2Pressed()){
			state_1 =TUN_AMBER;
			HAL_GPIO_WritePin(GPIOA, TRAFFIC1_0_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, TRAFFIC1_1_Pin, 1);
			setTimer2(250);
		}

		if (isButton3Pressed()){
			if (greenTime <99) greenTime++;
			else greenTime =1;
		}
		break;
	case TUN_AMBER:
		if (timer2_flag ==1){
			HAL_GPIO_TogglePin(GPIOA, TRAFFIC1_0_Pin);
			HAL_GPIO_TogglePin(GPIOB, TRAFFIC1_1_Pin);
			setTimer2(250);
		}

		if(isButton1Pressed()){
			state_1 = AUTO_RED;
			setTimer2(redTime*1000);
		}

		if (isButton2Pressed()){
			state_1 =TUN_RED;
			HAL_GPIO_WritePin(GPIOA, TRAFFIC1_0_Pin, 0);
			setTimer2(250);
		}

		if (isButton3Pressed()){
			if (amberTime <99) amberTime++;
			else amberTime =1;
		}
		break;
	case TUN_RED:
		if (timer2_flag ==1){
			HAL_GPIO_TogglePin(GPIOB, TRAFFIC1_1_Pin);
			setTimer2(250);
		}

		if(isButton1Pressed()){
			state_1 = AUTO_RED;
			setTimer2(redTime*1000);
		}

		if (isButton2Pressed()){
			state_1 =TUN_GREEN;
			HAL_GPIO_WritePin(GPIOB, TRAFFIC1_1_Pin, 0);
			setTimer2(250);
		}

		if (isButton3Pressed()){
			if (redTime <99) redTime++;
			else redTime =1;
		}
		break;
	default:
		break;
	}



	switch(state_2){
	case TUN_GREEN:
		if (timer3_flag ==1){
			HAL_GPIO_TogglePin(GPIOB, TRAFFIC2_0_Pin);
			setTimer3(250);
		}

		if(isButton1Pressed()){
			state_2 = AUTO_GREEN;
			setTimer3(greenTime*1000);
		}

		if (isButton2Pressed()){
			state_2 =TUN_AMBER;
			HAL_GPIO_WritePin(GPIOB, TRAFFIC2_0_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, TRAFFIC2_1_Pin, 1);
			setTimer3(250);
		}
		break;
	case TUN_AMBER:
		if (timer3_flag ==1){
			HAL_GPIO_TogglePin(GPIOB, TRAFFIC2_0_Pin);
			HAL_GPIO_TogglePin(GPIOB, TRAFFIC2_1_Pin);
			setTimer3(250);
		}

		if(isButton1Pressed()){
			state_2 = AUTO_GREEN;
			setTimer3(greenTime*1000);
		}

		if (isButton2Pressed()){
			state_2 =TUN_RED;
			HAL_GPIO_WritePin(GPIOB, TRAFFIC2_0_Pin, 0);
			setTimer3(250);
		}
		break;
	case TUN_RED:
		if (timer3_flag ==1){
			HAL_GPIO_TogglePin(GPIOB, TRAFFIC2_1_Pin);
			setTimer3(250);
		}

		if(isButton1Pressed()){
			state_2 = AUTO_GREEN;
			setTimer3(greenTime*1000);
		}

		if (isButton2Pressed()){
			state_2 =TUN_GREEN;
			HAL_GPIO_WritePin(GPIOB, TRAFFIC2_1_Pin, 0);
			setTimer3(250);
		}
		break;
	default:
		break;
	}
}
