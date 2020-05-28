/*
 * state.c
 *
 * Created: 13.05.2020 10:54:39
 *  Author: Yauheni
 */

#include "state.h"
#include "release.h"
#include "common/unused.h"

static void defaultUpdate(StepperStatePtr, uint16_t);
static void defaultStep(StepperStatePtr, bool);
static void defaultEnable(StepperStatePtr, bool);

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

static void defaultUpdate(StepperStatePtr state, uint16_t dt) {
    UNUSED(state);
    UNUSED(dt);
}

static void defaultStep(StepperStatePtr state, bool dir) {
    UNUSED(state);
    UNUSED(dir);
}

static void defaultEnable(StepperStatePtr state, bool isEnabled) {
    UNUSED(state);
    UNUSED(isEnabled);
}
