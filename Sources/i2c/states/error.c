/*
 * error.c
 *
 * Created: 29.05.2020 6:55:24
 *  Author: Yauheni
 */

#include "error.h"
#include "idle.h"

void i2cTransitionToError(I2CStatePtr state) {
    i2cDefaultStateImplementation(state);

    // call callback

    i2cTransitionToIdle(state);
}