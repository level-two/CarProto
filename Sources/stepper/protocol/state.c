/*
 * state.c
 *
 * Created: 13.05.2020 10:54:39
 *  Author: Yauheni
 */

#include "state.h"

static void defaultUpdate(StatePtr state, uint16_t dt) { }
static void defaultStep(StatePtr state, StepDir dir) { }
static void defaultEnable(StatePtr state, bool isEnabled) { }

void defaultImplementation(StatePtr state) {
    state->update = defaultUpdate;
    state->step = defaultStep;
    state->enable = defaultEnable;
    state->isIdle = false;
    state->duration = 0;
}