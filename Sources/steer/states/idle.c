/*
 * idle.c
 *
 * Created: 21.05.2020 12:00:13
 *  Author: Yauheni
 */

#include "idle.h"

static void setPosition(SteerStatePtr, SteerPosition);

void steerTransitionToIdle(SteerStatePtr state) {
    defaultSteerStateImplementation(state);
    state->setPosition = setPosition;
    state->isIdle = true;
}

static void setPosition(SteerStatePtr state, SteerPosition position) {
    steerTransitionToSetPosition(state, position);
}