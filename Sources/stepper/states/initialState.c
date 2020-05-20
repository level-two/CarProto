/*
 * initialState.c
 *
 * Created: 13.05.2020 10:55:31
 *  Author: Yauheni
 */

#include "initialState.h"
#include "idleState.h"
#include "../driver/driver.h"

void transitionToInitial(StepperStatePtr state) {
    defaultImplementation(state);
    stepperDriverSetup(state->config);
    transitionToIdle(state);
}
