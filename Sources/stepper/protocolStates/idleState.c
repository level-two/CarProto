/*
 * idleState.c
 *
 * Created: 13.05.2020 11:02:02
 *  Author: Yauheni
 */

#include "idleState.h"
#include "disabledState.h"
#include "stepState.h"

static void step(ProtocolLayerStatePtr, StepDir);
static void enable(ProtocolLayerStatePtr, bool);

void transitionToIdle(ProtocolLayerStatePtr state) {
    defaultImplementation(state);

    state->step = step;
    state->enable = enable;
    state->isIdle = true;
}

static void step(ProtocolLayerStatePtr state, StepDir dir) {
    transitionToStep(state, dir);
}

static void enable(ProtocolLayerStatePtr state, bool isEnabled) {
    if (isEnabled) { return; }
    transitionToDisabled(state);
}