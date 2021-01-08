/*
 * disabledState.c
 *
 * Created: 13.05.2020 12:57:16
 *  Author: Yauheni
 */

#include <stdbool.h>
#include "disabled.h"
#include "../driver/driver.h"
#include "enabling.h"

static void enable(StepperStatePtr, bool);

void stepperTransitionToDisabled(StepperStatePtr state) {
    defaultStepperStateImplementation(state);
    state->enable = enable;

    stepperDriverSetSleep(state->config, true);
}

static void enable(StepperStatePtr state, bool isEnabled) {
    if (!isEnabled) { return; }
    stepperTransitionToEnabling(state);
}