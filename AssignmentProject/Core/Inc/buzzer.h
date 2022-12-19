/*
 * buzzef.h
 *
 *  Created on: Dec 8, 2022
 *      Author: duyvt
 */

#ifndef INC_BUZZER_H_
#define INC_BUZZER_H_

#include "global.h"

#define BUZZER_OFF		0
#define	BUZZER_ON		1

extern TIM_HandleTypeDef htim3;
extern int buzzer_flag;

void buzzerRun();

#endif /* INC_BUZZER_H_ */
