/*
 * start.c
 *
 * Created: 29.05.2020 6:54:15
 *  Author: Yauheni
 */

#include "start.h"
#include "i2c/driver/driver.h"
#include "address.h"
#include "completion.h"

static void acknowledge(I2CStatePtr, bool);

void i2cTransitionToStart(I2CStatePtr state) {
    i2cDefaultStateImplementation(state);
    state->acknowledge = acknowledge;
    i2cDriverSendStart();
}

static void acknowledge(I2CStatePtr state, bool isSuccess) {
    if (isSuccess) {
        i2cTransitionToAddress(state);
    } else {
        i2cTransitionToCompletion(state, false);
    }
}


