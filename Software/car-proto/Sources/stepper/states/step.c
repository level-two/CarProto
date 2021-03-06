/*
 * stepState.c
 *
 * Created: 13.05.2020 12:08:39
 *  Author: Yauheni
 */

#include <stdbool.h>
#include <inttypes.h>
#include <util/delay.h>
#include "step.h"
#include "idle.h"
#include "../driver/driver.h"

#define STEP_DURATION_US 10000

static void update(StepperStatePtr, uint16_t);

void stepperTransitionToStep(StepperStatePtr state, bool dir) {
    defaultStepperStateImplementation(state);
    state->update = update;

    stepperDriverSetDir(state->config, dir);
    _delay_us(1);
    stepperDriverSetStep(state->config, true);
    _delay_us(1);
    stepperDriverSetStep(state->config, false);

    state->duration = STEP_DURATION_US;
}

static void update(StepperStatePtr state, uint16_t dt) {
    if (state->duration > dt) {
        state->duration -= dt;
    } else {
        stepperTransitionToIdle(state);
    }
}
