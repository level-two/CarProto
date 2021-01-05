/*
 * enablingState.c
 *
 * Created: 13.05.2020 13:20:17
 *  Author: Yauheni
 */

#include <stdbool.h>
#include <inttypes.h>
#include "enabling.h"
#include "../driver/driver.h"
#include "idle.h"

// In ticks - 1ms
#define WAKEUP_DURATION_US 1000

static void update(StepperStatePtr, uint16_t);

void stepperTransitionToEnabling(StepperStatePtr state) {
    defaultStepperStateImplementation(state);
    state->update = update;

    stepperDriverSetSleep(state->config, false);
    state->duration = WAKEUP_DURATION_US;
}

static void update(StepperStatePtr state, uint16_t dt) {
    if (state->duration > dt) {
        state->duration -= dt;
    } else {
        stepperTransitionToIdle(state);
    }
}
