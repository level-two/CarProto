/*
 * address.c
 *
 * Created: 30.05.2020 7:00:03
 *  Author: Yauheni
 */

#include "address.h"
#include "i2c/driver/driver.h"
#include "command.h"

static void acknowledge(I2CStatePtr, bool);

void i2cTransitionToAddress(I2CStatePtr state) {
    i2cDefaultStateImplementation(state);
    state->acknowledge = acknowledge;
}

static void acknowledge(I2CStatePtr state, bool isSuccess) {
    if (isSuccess) {
        i2cTransitionToCommand(state);
    } else {
        i2cTransitionToCompletion(state, false);
    }
}
