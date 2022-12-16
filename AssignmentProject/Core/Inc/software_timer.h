/*
 * software_timer.h
 *
 *  Created on: Dec 8, 2022
 *      Author: duyvt
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "global.h"

extern int timer1_flag; //for blinking led
extern int timer2_flag; //for state_1
extern int timer3_flag; //for state_2
extern int timer4_flag; //for pedes_light
extern int timer5_flag; //for turnoff_pedes_light
extern int timer6_flag;

void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);
void setTimer4(int duration);
void setTimer5(int duration);
void setTimer6(int duration);

int get_timer2_counter();

void timerInit();

void timerRun();
#endif /* INC_SOFTWARE_TIMER_H_ */
