/*
 * stepper.h
 *
 * Created: 05.05.2020 17:40:07
 *  Author: Yauheni
 */

#ifndef STEPPER_H_
#define STEPPER_H_

#include <stdbool.h>

typedef enum {
    left,
    right,
    middle
} StepperParkPosition;

typedef enum {
    idle,
    calibrating,
    parking,
    disabled
} StepperState;

void stepperSetup();
void stepperEnable(bool en); // should terminate any activity
void stepperCalibrate();
void stepperPark(StepperParkPosition position); // assert(minStep != maxStep)
StepperState stepperState();
StepperParkPosition stepperCurrentPosition();

#endif /* STEPPER_H_ */