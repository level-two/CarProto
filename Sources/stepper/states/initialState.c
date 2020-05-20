/*
 * initialState.c
 *
 * Created: 13.05.2020 10:55:31
 *  Author: Yauheni
 */

#include "initialState.h"
#include "idleState.h"

void transitionToInitial(StepperStatePtr state, StepperConfigPtr config) {
    defaultImplementation(state);
    state->config = config;
    stepperDriverSetup(state->config);
    transitionToIdle(state);
}
