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

bool steerSetup(
    volatile uint8_t* portReg,
    volatile uint8_t* ddrReg,
    volatile uint8_t* pinReg,
    uint8_t dirPin,
    uint8_t stepPin,
    uint8_t sleepPin,
    uint8_t letfStopperPin,
    uint8_t rightStopperPin) {

    // TODO: Create steer state

    StepperStatePtr stepper = stepperSetup(
        DRIVER_PORT_REG,
        DRIVER_DDR_REG,
        DRIVER_DIR_PIN,
        DRIVER_STEP_PIN,
        DRIVER_SLEEP_PIN);
    if (stepper == NULL) { return false; }

    ButtonPtr leftStopper = buttonSetup(STOPPER_PORT_REG, STOPPER_PIN_REG, STOPPER_LEFT_PIN);
    if (leftStopper == NULL) {
        stepperRelease(stepper);
        return false;
    }

    ButtonPtr rightStopper = buttonSetup(STOPPER_PORT_REG, STOPPER_PIN_REG, STOPPER_RIGHT_PIN);
    if (rightStopper == NULL) {
        stepperRelease(stepper);
        buttonRelease(leftStopper);
        return false;
    }

    // TODO

    return true;
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
