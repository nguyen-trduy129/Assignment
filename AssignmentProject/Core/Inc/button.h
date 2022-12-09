/*
 * button.h
 *
 *  Created on: Dec 8, 2022
 *      Author: duyvt
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "global.h"

#define NORMAL_STATE	GPIO_PIN_SET
#define PRESSED_STATE	GPIO_PIN_RESET

int isButton1Pressed();
int isButton2Pressed();
int isButton3Pressed();
int isButtonPedesPressed();

void getKeyInput();

#endif /* INC_BUTTON_H_ */
