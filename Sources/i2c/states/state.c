/*
 * state.c
 *
 * Created: 29.05.2020 7:14:25
 *  Author: Yauheni
 */

#include "state.h"
#include "common/unused.h"

static void defaultI2CInterrupt(I2CStatePtr);

void defaultI2CStateImplementation(I2CStatePtr state) {
    state->i2cInterrupt = defaultI2CInterrupt;
}

static void defaultI2CInterrupt(I2CStatePtr state) {
    UNUSED(state);
}