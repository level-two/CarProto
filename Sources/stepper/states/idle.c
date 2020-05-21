/*
 * idleState.c
 *
 * Created: 13.05.2020 11:02:02
 *  Author: Yauheni
 */

#include <stdbool.h>
#include "idle.h"
#include "disabled.h"
#include "step.h"

static void step(StepperStatePtr, bool);
static void enable(StepperStatePtr, bool);

void stepperTransitionToIdle(StepperStatePtr state) {
    defaultStepperStateImplementation(state);

    state->step = step;
    state->enable = enable;
    state->isIdle = true;
}

static void step(StepperStatePtr state, bool dir) {
    stepperTransitionToStep(state, dir);
}

static void enable(StepperStatePtr state, bool isEnabled) {
    if (isEnabled) { return; }
    stepperTransitionToDisabled(state);
}