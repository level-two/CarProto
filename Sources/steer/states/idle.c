/*
 * idle.c
 *
 * Created: 21.05.2020 12:00:13
 *  Author: Yauheni
 */

#include <stdbool.h>
#include "idle.h"
#include "setPosition.h"
#include "stepper/stepper.h"

static void setPosition(SteerStatePtr, SteerPosition);

void steerTransitionToIdle(SteerStatePtr state) {
    defaultSteerStateImplementation(state);
    state->setPosition = setPosition;
    state->isIdle = true;

    stepperEnable(state->stepper, false);
}

static void setPosition(SteerStatePtr state, SteerPosition position) {
    steerTransitionToSetPosition(state, position);
}