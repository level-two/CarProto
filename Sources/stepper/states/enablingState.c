/*
 * enablingState.c
 *
 * Created: 13.05.2020 13:20:17
 *  Author: Yauheni
 */

#include <stdbool.h>
#include <inttypes.h>
#include "enablingState.h"
#include "../driver/driver.h"
#include "idleState.h"

// In ticks - 1ms
#define WAKEUP_DURATION_US 1000

static void update(StepperStatePtr, uint16_t);

void transitionToEnabling(StepperStatePtr state) {
    defaultImplementation(state);
    state->update = update;

    stepperDriverSetSleep(state->config, false);
    state->duration = WAKEUP_DURATION_US;
}

static void update(StepperStatePtr state, uint16_t dt) {
    if (state->duration > dt) {
        state->duration -= dt;
    } else {
        transitionToIdle(state);
    }
}
