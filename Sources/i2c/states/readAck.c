/*
 * readAck.c
 *
 * Created: 04.07.2020 18:17:11
 *  Author: Yauheni
 */

#include "readAck.h"
#include "i2c/driver/driver.h"
#include "readData.h"
#include "completion.h"

static void acknowledge(I2CStatePtr, bool);

void i2cTransitionToReadAck(I2CStatePtr state) {
    i2cDefaultStateImplementation(state);
    state->acknowledge = acknowledge;
    i2cDriverSendReadDataAck();
}

static void acknowledge(I2CStatePtr state, bool isSuccess) {
    if (isSuccess) {
        i2cTransitionToReadData(state);
    } else {
        i2cTransitionToCompletion(state, false);
    }
}
