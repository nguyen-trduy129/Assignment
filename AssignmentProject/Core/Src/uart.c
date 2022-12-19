/*
 * uart.c
 *
 *  Created on: Dec 16, 2022
 *      Author: duyvt
 */

#include "uart.h"

UART_HandleTypeDef huart2;
char str1[10];

void uartRun(){
//	switch(state_1){
//	case TUN_RED:
//		HAL_UART_Transmit (&huart2, (void*)str1, sprintf (str1 , "!7SEG:%d#", redTime), 500);
//		break;
//	case TUN_GREEN:
//		HAL_UART_Transmit (&huart2, (void*)str3, sprintf (str3 , "!7SEG:%d#", greenTime), 500);
//		break;
//	case TUN_AMBER:
//		HAL_UART_Transmit (&huart2, (void*)str2, sprintf (str2 , "!7SEG:%d#", amberTime), 500);
//		break;
//	default:
//		break;
//	}

	if (mode == MODE_1){
		if (timer8_flag ==1){
			HAL_UART_Transmit (&huart2, (void*)str1, sprintf (str1 , "!7SEG:%d#", (get_timer2_counter()/1000)), 500);
			setTimer8(500);
		}
	}

	if (mode == MODE_3){
		switch(state_1){
		case TUN_RED:
			if (timer8_flag ==1){
				HAL_UART_Transmit (&huart2, (void*)str1, sprintf (str1 , "!7SEG:%d#", redTime), 500);
				setTimer8(500);
			}
			break;
		case TUN_GREEN:
			if (timer8_flag ==1){
				HAL_UART_Transmit (&huart2, (void*)str1, sprintf (str1 , "!7SEG:%d#", greenTime), 500);
				setTimer8(500);
			}
			break;
		case TUN_AMBER:
			if (timer8_flag ==1){
				HAL_UART_Transmit (&huart2, (void*)str1, sprintf (str1 , "!7SEG:%d#", amberTime), 500);
				setTimer8(500);
			}
			break;
		default:
			break;
		}
	}
}
