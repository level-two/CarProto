/*
 * state.c
 *
 * Created: 13.05.2020 10:54:39
 *  Author: Yauheni
 */

#include "protocolLayerState.h"

static void defaultUpdate(ProtocolLayerStatePtr state, uint16_t dt) { }
static void defaultStep(ProtocolLayerStatePtr state, StepDir dir) { }
static void defaultEnable(ProtocolLayerStatePtr state, bool isEnabled) { }

void defaultImplementation(ProtocolLayerStatePtr state) {
    state->update = defaultUpdate;
    state->step = defaultStep;
    state->enable = defaultEnable;
    state->isIdle = false;
    state->duration = 0;
}