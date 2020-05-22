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

    SteerStatePtr state = (SteerStatePtr) malloc(sizeof(struct SteerState));
    if (state == NULL) return NULL;

    state->stepper = stepperSetup(portReg, ddrReg, dirPin, stepPin, sleepPin);
    state->leftStopper = buttonSetup(portReg, pinReg, letfStopperPin);
    state->rightStopper = buttonSetup(portReg, pinReg, rightStopperPin);

    if (state->stepper == NULL || state->leftStopper == NULL || state->rightStopper == NULL) {
        steerRelease(state);
        return NULL;
    }

    steerTransitionToInitial(state);

    return state;
}

void steerRelease(SteerStatePtr state) {
    if (state == NULL) return;
    stepperRelease(state->stepper);
    buttonRelease(state->leftStopper);
    buttonRelease(state->rightStopper);
    free(state);
}

void steerUpdate(SteerStatePtr state, uint16_t dt) {
    state->update(state, dt);
}

void steerSetPosition(SteerStatePtr state, SteerPosition position) {
    state->setPosition(state, position);
}

bool steerIsBusy(SteerStatePtr state) {
    return !state->isIdle;
}

SteerPosition steerCurrentPosition(SteerStatePtr state) {
    if (state->currentPosition == 0) {
        return steerPositionLeft;
    }

    if (state->currentPosition == state->totalSteps) {
        return steerPositionRight;
    }

    return steerPositionMiddle;
}
