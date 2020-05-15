/*
 * protocol.c
 *
 * Created: 09.05.2020 15:15:27
 *  Author: Yauheni
 */

#include "protocol.h"
#include "state.h"
#include "stepper/driver.h"
#include "initialState.h"

void protocolLayerSetup(StatePtr state) {
    transitionToInitial(state);
}

void protocolLayerUpdate(StatePtr state, uint16_t dt) {
    state->update(state, dt);
}

void protocolLayerStep(StatePtr state, StepDir dir) {
    state->step(state, dir);
}

void protocolLayerEnable(StatePtr state, bool isEnabled) {
    state->enable(state, isEnabled);
}

ProtocolLayerStatus protocolLayerStatus(StatePtr state) {
    if (!state->isIdle) {
        return busy;
    } else if (driverLayerLeftStopperStatus()) {
        return idleLeft;
    } else if (driverLayerRightStopperStatus()) {
        return idleLeft;
    } else {
        return idle;
    }
}
