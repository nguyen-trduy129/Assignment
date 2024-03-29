/*
 * fsm_mode.c
 *
 *  Created on: Dec 16, 2022
 *      Author: duyvt
 */


#include "fsm_mode.h"

void modeRun(){
	switch(mode){
	case INIT_MODE:
		mode = MODE_1;
		break;
	case MODE_1:
		if (isButton1Pressed()){
			mode = MODE_2;
		}
		break;
	case MODE_2:
		if (isButton1Pressed()){
			mode = MODE_3;
		}

		if (isButton2Pressed()){
			switch(state_1){
			case MAN_RED:
				state_1= MAN_GREEN;
				setTimer2(WAITING_TIME);
				break;
			case MAN_GREEN:
				state_1= MAN_AMBER;
				setTimer2(WAITING_TIME);
				break;
			case MAN_AMBER:
				state_1= MAN_RED;
				setTimer2(WAITING_TIME);
				break;
			default:
				break;
			}

			switch(state_2){
			case MAN_RED:
				state_2= MAN_GREEN;
				setTimer3(WAITING_TIME);
				break;
			case MAN_GREEN:
				state_2= MAN_AMBER;
				setTimer3(WAITING_TIME);
				break;
			case MAN_AMBER:
				state_2= MAN_RED;
				setTimer3(WAITING_TIME);
				break;
			default:
				break;
			}
		}

		if (isButton3Pressed()){
			switch(state_1){
			case MAN_RED:
				state_1=MAN_AMBER;
				setTimer2(WAITING_TIME);
				break;
			case MAN_GREEN:
				state_1=MAN_RED;
				setTimer2(WAITING_TIME);
				break;
			case MAN_AMBER:
				state_1=MAN_GREEN;
				setTimer2(WAITING_TIME);
				break;
			default:
				break;
			}

			switch(state_2){
			case MAN_RED:
				state_2=MAN_AMBER;
				setTimer3(WAITING_TIME);
				break;
			case MAN_GREEN:
				state_2=MAN_RED;
				setTimer3(WAITING_TIME);
				break;
			case MAN_AMBER:
				state_2=MAN_GREEN;
				setTimer3(WAITING_TIME);
				break;
			default:
				break;
			}
		}
		break;
	case MODE_3:
		if (isButton1Pressed()){
			mode = MODE_1;
		}

		if (isButton2Pressed()){
			switch(state_1){
			case TUN_RED:
				state_1 =TUN_GREEN;
				HAL_GPIO_WritePin(GPIOA, TRAFFIC1_1_Pin, 0);
				setTimer2(250);
				break;
			case TUN_GREEN:
				state_1 =TUN_AMBER;
				HAL_GPIO_WritePin(GPIOA, TRAFFIC1_1_Pin, 1);
				HAL_GPIO_WritePin(GPIOB, TRAFFIC1_0_Pin, 1);
				setTimer2(250);
				break;
			case TUN_AMBER:
				state_1 =TUN_RED;
				HAL_GPIO_WritePin(GPIOB, TRAFFIC1_0_Pin, 0);
				setTimer2(250);
				break;
			default:
				break;
			}

			switch(state_2){
			case TUN_RED:
				state_2 =TUN_GREEN;
				HAL_GPIO_WritePin(GPIOB, TRAFFIC2_1_Pin, 0);
				setTimer3(250);
				break;
			case TUN_GREEN:
				state_2 =TUN_AMBER;
				HAL_GPIO_WritePin(GPIOB, TRAFFIC2_1_Pin, 1);
				HAL_GPIO_WritePin(GPIOB, TRAFFIC2_0_Pin, 1);
				setTimer3(250);
				break;
			case TUN_AMBER:
				state_2 =TUN_RED;
				HAL_GPIO_WritePin(GPIOB, TRAFFIC2_0_Pin, 0);
				setTimer3(250);
				break;
			default:
				break;
			}
		}

		if (isButton3Pressed()){
			switch (state_1){
			case TUN_GREEN:
				if (greenTime <99) greenTime++;
				else greenTime =1;
				break;
			case TUN_AMBER:
				if (amberTime <99) amberTime++;
				else amberTime =1;
				break;
			case TUN_RED:
				if (redTime <99) redTime++;
				else redTime =1;
				break;
			default:
				break;
			}
		}
	}
}
