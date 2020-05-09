/*
 * wiring.h
 *
 * Created: 08.05.2020 0:10:19
 *  Author: Yauheni
 */

#ifndef WIRING_H_
#define WIRING_H_

#include <stdbool.h>

void setupPorts();

void setStepperDir(bool);
void setStepperStep(bool);
void setStepperSleep(bool);
bool getStepperLeftStopper();
bool getStepperRightStopper();


#endif /* WIRING_H_ */