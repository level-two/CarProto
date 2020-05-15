/*
 * disabledState.c
 *
 * Created: 13.05.2020 12:57:16
 *  Author: Yauheni
 */

#include "disabledState.h"
#include "stepper/driver.h"
#include "enablingState.h"

static void enable(StatePtr, bool);

void transitionToDisabled(StatePtr state) {
    defaultImplementation(state);
    state->enable = enable;

    driverLayerSetSleep(true);
}

static void enable(StatePtr state, bool isEnabled) {
    if (!isEnabled) { return; }
    transitionToEnabling(state);
}