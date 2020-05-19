/*
 * disabledState.c
 *
 * Created: 13.05.2020 12:57:16
 *  Author: Yauheni
 */

#include "disabledState.h"
#include "stepper/driver.h"
#include "enablingState.h"

static void enable(ProtocolLayerStatePtr, bool);

void transitionToDisabled(ProtocolLayerStatePtr state) {
    defaultImplementation(state);
    state->enable = enable;

    driverLayerSetSleep(state->config, true);
}

static void enable(ProtocolLayerStatePtr state, bool isEnabled) {
    if (!isEnabled) { return; }
    transitionToEnabling(state);
}