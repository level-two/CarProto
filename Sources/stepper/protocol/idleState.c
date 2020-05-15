/*
 * idleState.c
 *
 * Created: 13.05.2020 11:02:02
 *  Author: Yauheni
 */

#include "idleState.h"
#include "disabledState.h"
#include "stepState.h"

static void step(StatePtr, StepDir);
static void enable(StatePtr, bool);

void transitionToIdle(StatePtr state) {
    defaultImplementation(state);

    state->step = step;
    state->enable = enable;
    state->isIdle = true;
}

static void step(StatePtr state, StepDir dir) {
    transitionToStep(state, dir);
}

static void enable(StatePtr state, bool isEnabled) {
    if (isEnabled) { return; }
    transitionToDisabled(state);
}