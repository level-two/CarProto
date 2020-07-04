/*
 * readNack.c
 *
 * Created: 04.07.2020 18:17:11
 *  Author: Yauheni
 */

#include "readNack.h"
#include "i2c/driver/driver.h"
#include "readData.h"
#include "completion.h"

static void acknowledge(I2CStatePtr, bool);

void i2cTransitionToReadNack(I2CStatePtr state) {
    i2cDefaultStateImplementation(state);
    state->acknowledge = acknowledge;
    i2cDriverSendReadDataNack();
}

static void acknowledge(I2CStatePtr state, bool isSuccess) {
    i2cTransitionToCompletion(state, isSuccess);
}
