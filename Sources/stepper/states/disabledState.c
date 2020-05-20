/*
 * disabledState.c
 *
 * Created: 13.05.2020 12:57:16
 *  Author: Yauheni
 */

#include <stdbool.h>
#include "disabledState.h"
#include "../driver/driver.h"
#include "enablingState.h"

static void enable(StepperStatePtr, bool);

void transitionToDisabled(StepperStatePtr state) {
    defaultImplementation(state);
    state->enable = enable;

    stepperDriverSetSleep(state->config, true);
}

static void enable(StepperStatePtr state, bool isEnabled) {
    if (!isEnabled) { return; }
    transitionToEnabling(state);
}