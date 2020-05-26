/*
 * setPosition.c
 *
 * Created: 22.05.2020 16:30:19
 *  Author: Yauheni
 */

#include <stdbool.h>
#include "setPosition.h"
#include "idle.h"
#include "stepper/stepper.h"

#define MOVE_LEFT_STEP_DIR stepCW
#define MOVE_RIGHT_STEP_DIR stepCCW

static void update(SteerStatePtr, uint16_t);

void steerTransitionToSetPosition(SteerStatePtr state, SteerPosition position) {
    defaultSteerStateImplementation(state);
    state->update = update;

    state->destPosition =
        (position == steerPositionLeft) ? 0 :
        (position == steerPositionRight) ? state->totalSteps :
        (state->totalSteps >> 1);

    stepperEnable(state->stepper, true);
}

static void update(SteerStatePtr state, uint16_t dt) {
    stepperUpdate(state->stepper, dt);

    if (stepperIsBusy(state->stepper)) { return; }

    if (state->currentPosition > state->destPosition) {
        state->currentPosition--;
        stepperStep(state->stepper, MOVE_LEFT_STEP_DIR);
    } else if (state->currentPosition < state->destPosition) {
        state->currentPosition++;
        stepperStep(state->stepper, MOVE_RIGHT_STEP_DIR);
    } else {
       steerTransitionToIdle(state);
    }
}