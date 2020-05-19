/*
 * enablingState.c
 *
 * Created: 13.05.2020 13:20:17
 *  Author: Yauheni
 */

#include "enablingState.h"
#include "stepper/driver.h"
#include "idleState.h"

// In ticks - 1ms
#define WAKEUP_DURATION_US 1000

static void update(ProtocolLayerStatePtr, uint16_t);

void transitionToEnabling(ProtocolLayerStatePtr state) {
    defaultImplementation(state);
    state->update = update;

    driverLayerSetSleep(state->config, false);
    state->duration = WAKEUP_DURATION_US;
}

static void update(ProtocolLayerStatePtr state, uint16_t dt) {
    if (state->duration > dt) {
        state->duration -= dt;
    } else {
        transitionToIdle(state);
    }
}
