/*
 * idleState.c
 *
 * Created: 13.05.2020 11:02:02
 *  Author: Yauheni
 */

#include <stdbool.h>
#include "idleState.h"
#include "disabledState.h"
#include "stepState.h"

static void step(StepperStatePtr, bool);
static void enable(StepperStatePtr, bool);

void transitionToIdle(StepperStatePtr state) {
    defaultImplementation(state);

    state->step = step;
    state->enable = enable;
    state->isIdle = true;
}

static void step(StepperStatePtr state, bool dir) {
    transitionToStep(state, dir);
}

static void enable(StepperStatePtr state, bool isEnabled) {
    if (isEnabled) { return; }
    transitionToDisabled(state);
}