/*
 * initialState.c
 *
 * Created: 13.05.2020 10:55:31
 *  Author: Yauheni
 */

#include "initialState.h"
#include "idleState.h"
#include "stepper/driver.h"

void transitionToInitial(ProtocolLayerStatePtr state, StepperConfigPtr config) {
    defaultImplementation(state);
    state->config = config;
    driverLayerSetup(state->config);
    transitionToIdle(state);
}
