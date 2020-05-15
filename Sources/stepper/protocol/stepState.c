/*
 * stepState.c
 *
 * Created: 13.05.2020 12:08:39
 *  Author: Yauheni
 */

#include <util/delay.h>
#include "stepState.h"
#include "idleState.h"
#include "stepper/driver.h"

#define STEP_DURATION_US 1000

static void update(StatePtr, uint16_t);

void transitionToStep(StatePtr state, StepDir dir) {
    defaultImplementation(state);
    state->update = update;

    driverLayerSetDir(dir == left ? false : true);
    _delay_us(1);
    driverLayerSetStep(true);
    _delay_us(1);
    driverLayerSetStep(false);

    state->duration = STEP_DURATION_US;
}

static void update(StatePtr state, uint16_t dt) {
    if (state->duration > dt) {
        state->duration -= dt;
    } else {
        transitionToIdle(state);
    }
}
