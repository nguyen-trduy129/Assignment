/*
 * global.h
 *
 *  Created on: Dec 8, 2022
 *      Author: duyvt
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "button.h"
#include "scheduler.h"
#include "traffic_automatic.h"
#include "traffic_manual.h"
#include "pedestrian_light.h"
#include "buzzef.h"
#include "software_timer.h"
#include "traffic_tuning.h"


#define TICK 			10
#define WAITING_TIME 	10000

#define INIT			0
#define AUTO_RED		1
#define AUTO_AMBER		2
#define AUTO_GREEN		3

#define MAN_RED			11
#define MAN_AMBER		12
#define MAN_GREEN		13

#define TUN_RED			21
#define TUN_AMBER		22
#define TUN_GREEN		23

#define INIT_MODE		0
#define MODE_1			1
#define MODE_2			2
#define MODE_3			3

extern int redTime;
extern int amberTime;
extern int greenTime;

extern int mode;
extern int state_1;
extern int state_2;

#endif /* INC_GLOBAL_H_ */
