/*
 * protocol.c
 *
 * Created: 09.05.2020 15:15:27
 *  Author: Yauheni
 */

#include <stdlib.h>
#include "protocol.h"
#include "protocolStates/protocolLayerState.h"
#include "driver.h"
#include "protocolStates/initialState.h"

ProtocolLayerStatePtr protocolLayerSetup(StepperConfigPtr config) {
    ProtocolLayerStatePtr state = (ProtocolLayerStatePtr) malloc(sizeof(struct ProtocolLayerState));
    if (state == NULL) { return NULL; }

    transitionToInitial(state, config);

    return state;
}

void protocolLayerUpdate(ProtocolLayerStatePtr state, uint16_t dt) {
    state->update(state, dt);
}

void protocolLayerStep(ProtocolLayerStatePtr state, StepDir dir) {
    state->step(state, dir);
}

void protocolLayerEnable(ProtocolLayerStatePtr state, bool isEnabled) {
    state->enable(state, isEnabled);
}

ProtocolLayerStatus protocolLayerStatus(ProtocolLayerStatePtr state) {
    if (!state->isIdle) {
        return protocolStatusBusy;
    } else if (driverLayerLeftStopperStatus(state->config)) {
        return protocolStatusIdleLeft;
    } else if (driverLayerRightStopperStatus(state->config)) {
        return protocolStatusIdleLeft;
    } else {
        return protocolStatusIdle;
    }
}
