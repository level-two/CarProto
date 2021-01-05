/*
 * steer.c
 *
 * Created: 20.05.2020 6:27:27
 *  Author: Yauheni
 */

#include <stdlib.h>
#include "reference/reference.h"
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

    SteerStatePtr state = (SteerStatePtr) alloc(sizeof(struct SteerState));
    if (state == NULL) return NULL;
    autorelease(state);

    state->stepper = stepperSetup(portReg, ddrReg, dirPin, stepPin, sleepPin);
    state->leftStopper = buttonSetup(portReg, pinReg, letfStopperPin);
    state->rightStopper = buttonSetup(portReg, pinReg, rightStopperPin);

    retain(state->stepper);
    retain(state->leftStopper);
    retain(state->rightStopper);

    if (state->stepper == NULL || state->leftStopper == NULL || state->rightStopper == NULL) {
        steerReleaseResources(state);
        return NULL;
    }

    steerTransitionToInitial(state);

    return state;
}

void steerReleaseResources(SteerStatePtr state) {
    if (state == NULL) return;
    stepperReleaseResources(state->stepper);
    buttonReleaseResources(state->leftStopper);
    buttonReleaseResources(state->rightStopper);
    release(state->stepper);
    release(state->leftStopper);
    release(state->rightStopper);
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
