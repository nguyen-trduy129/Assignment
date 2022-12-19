/*
 * traffic_manual.c
 *
 *  Created on: Dec 8, 2022
 *      Author: duyvt
 */


#include "traffic_manual.h"

void fsm_manual_run1(){
	switch (state_1){
	case MAN_RED:
		HAL_GPIO_WritePin(GPIOA,TRAFFIC1_1_Pin , 1);
		HAL_GPIO_WritePin(GPIOB,TRAFFIC1_0_Pin , 0);

		if (mode == MODE_3){
			state_1= TUN_GREEN;
			HAL_GPIO_WritePin(GPIOA, TRAFFIC1_1_Pin, 0);
			uartRun();
			setTimer2(250);
		}

		if (timer2_flag ==1){
			mode = MODE_1;
			state_1=AUTO_RED;
			setTimer2(redTime*1000);
		}
		break;
	case MAN_GREEN:
		HAL_GPIO_WritePin(GPIOA,TRAFFIC1_1_Pin , 0);
		HAL_GPIO_WritePin(GPIOB,TRAFFIC1_0_Pin , 1);

		if (mode == MODE_3){
			state_1= TUN_GREEN;
			HAL_GPIO_WritePin(GPIOA, TRAFFIC1_1_Pin, 0);
			uartRun();
			setTimer2(250);
		}

		if (timer2_flag ==1){
			mode = MODE_1;
			state_1=AUTO_RED;
			setTimer2(redTime*1000);
		}
		break;
	case MAN_AMBER:
		HAL_GPIO_WritePin(GPIOA,TRAFFIC1_1_Pin , 1);
		HAL_GPIO_WritePin(GPIOB,TRAFFIC1_0_Pin , 1);

		if (mode == MODE_3){
			state_1= TUN_GREEN;
			HAL_GPIO_WritePin(GPIOA, TRAFFIC1_1_Pin, 0);
			uartRun();
			setTimer2(250);
		}

		if (timer2_flag ==1){
			mode = MODE_1;
			state_1=AUTO_RED;
			setTimer2(redTime*1000);
		}
		break;
	default:
		break;
	}
}

void fsm_manual_run2(){
	switch (state_2){
	case MAN_GREEN:
		HAL_GPIO_WritePin(GPIOB,TRAFFIC2_1_Pin , 0);
		HAL_GPIO_WritePin(GPIOB,TRAFFIC2_0_Pin , 1);

		if (mode == MODE_3){
			state_2= TUN_GREEN;
			HAL_GPIO_WritePin(GPIOB, TRAFFIC2_1_Pin, 0);
			setTimer3(250);
		}

		if (timer3_flag ==1){
			mode = MODE_1;
			state_2=AUTO_GREEN;
			setTimer3(greenTime*1000);
		}
		break;
	case MAN_AMBER:
		HAL_GPIO_WritePin(GPIOB,TRAFFIC2_0_Pin , 1);
		HAL_GPIO_WritePin(GPIOB,TRAFFIC2_1_Pin , 1);

		if (mode == MODE_3){
			state_2= TUN_GREEN;
			HAL_GPIO_WritePin(GPIOB, TRAFFIC2_1_Pin, 0);
			setTimer3(250);
		}

		if (timer3_flag ==1){
			mode = MODE_1;
			state_2=AUTO_GREEN;
			setTimer3(greenTime*1000);
		}
		break;
	case MAN_RED:
		HAL_GPIO_WritePin(GPIOB,TRAFFIC2_1_Pin , 1);
		HAL_GPIO_WritePin(GPIOB,TRAFFIC2_0_Pin , 0);

		if (mode == MODE_3){
			state_2= TUN_GREEN;
			HAL_GPIO_WritePin(GPIOB, TRAFFIC2_1_Pin, 0);
			setTimer3(250);
		}

		if (timer3_flag ==1){
			mode = MODE_1;
			state_2=AUTO_GREEN;
			setTimer3(greenTime*1000);
		}
		break;
	default:
		break;
	}
}
