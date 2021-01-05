/*
 * stepper.h
 *
 * Created: 05.05.2020 17:40:07
 *  Author: Yauheni
 */

#ifndef STEPPER_H_
#define STEPPER_H_

#include <stdbool.h>
#include <inttypes.h>
#include "states/state.h"

typedef enum { stepCW, stepCCW } StepperRotationDir;

StepperStatePtr stepperSetup(
    volatile uint8_t* portReg,
    volatile uint8_t* ddrReg,
    uint8_t dirPin,
    uint8_t stepPin,
    uint8_t sleepPin);
void stepperReleaseResources(StepperStatePtr);
void stepperUpdate(StepperStatePtr, uint16_t);
void stepperStep(StepperStatePtr, StepperRotationDir);
void stepperEnable(StepperStatePtr, bool);
bool stepperIsBusy(StepperStatePtr);

#endif /* STEPPER_H_ */