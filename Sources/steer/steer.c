/*
 * steer.c
 *
 * Created: 20.05.2020 6:27:27
 *  Author: Yauheni
 */

#include <stdlib.h>
#include "steer.h"
#include "stepper/stepper.h"
#include "button/button.h"
#include "states/initial.h"

SteerStatePtr steerSetup(
    volatile uint8_t* portReg,
    volatile uint8_t* ddrReg,
    volatile uint8_t* pinReg,
    uint8_t dirPin,
    uint8_t stepPin,
    uint8_t sleepPin,
    uint8_t letfStopperPin,
    uint8_t rightStopperPin) {

    StepperStatePtr stepper = stepperSetup(portReg, ddrReg, dirPin, stepPin, sleepPin);
    if (stepper == NULL) {
        return NULL;
    }

    ButtonPtr leftStopper = buttonSetup(portReg, pinReg, letfStopperPin);
    if (leftStopper == NULL) {
        stepperRelease(stepper);
        return NULL;
    }

    ButtonPtr rightStopper = buttonSetup(portReg, pinReg, rightStopperPin);
    if (rightStopper == NULL) {
        stepperRelease(stepper);
        buttonRelease(leftStopper);
        return NULL;
    }

    SteerStatePtr steer = (SteerStatePtr) malloc(sizeof(struct SteerState));
    if (steer == NULL) {
        stepperRelease(stepper);
        buttonRelease(leftStopper);
        buttonRelease(rightStopper);
        return NULL;
    }

    steer->stepper = stepper;
    steer->leftStopper = leftStopper;
    steer->rightStopper = rightStopper;

    steerTransitionToInitial(steer);

    return steer;
}

//
//void stepperEnable(StepperHandlerPtr stepperHandler, bool isEnabled) {
    //stepperEnable(stepperHandler->stepperState, isEnabled);
//}
//
//void stepperCalibrate(StepperHandlerPtr stepperHandler) {
//
//}
//
//void stepperPark(StepperHandlerPtr stepperHandler, StepperParkPosition position)
//{
    //// assert(minStep != maxStep)
//}
//
//StepperState stepperState(StepperHandlerPtr stepperHandler) {
    //return stepperStateDisabled;
//}
//
//StepperParkPosition stepperCurrentPosition(StepperHandlerPtr stepperHandler) {
    //return stepperParkedMiddle;
//}
