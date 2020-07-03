/*
 * stop.c
 *
 * Created: 29.05.2020 6:54:22
 *  Author: Yauheni
 */

#include "stop.h"
#include "i2c/driver/driver.h"
#include "idle.h"

static void acknowledge(I2CStatePtr, bool);

void i2cTransitionToStop(I2CStatePtr state) {
    i2cDefaultStateImplementation(state);
    state->acknowledge = acknowledge;

}

static void acknowledge(I2CStatePtr state, bool isSuccess) {
    i2cTransitionToIdle(state);
}


