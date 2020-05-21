/*
 * state.c
 *
 * Created: 13.05.2020 10:54:39
 *  Author: Yauheni
 */

#include "state.h"
#include "release.h"

static void defaultUpdate(StepperStatePtr state, uint16_t dt) { }
static void defaultStep(StepperStatePtr state, bool dir) { }
static void defaultEnable(StepperStatePtr state, bool isEnabled) { }

static void defaultRelease(StepperStatePtr state) {
    stepperTransitionToRelease(state);
}

void defaultStepperStateImplementation(StepperStatePtr state) {
    state->update = defaultUpdate;
    state->step = defaultStep;
    state->enable = defaultEnable;
    state->release = defaultRelease;

    state->isIdle = false;
    state->duration = 0;
}