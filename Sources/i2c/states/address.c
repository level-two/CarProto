/*
 * address.c
 *
 * Created: 29.05.2020 17:04:08
 *  Author: Yauheni
 */

#include "address.h"
#include "driver/driver.h"
#include "writeData.h"

static void acknowledge(I2CStatePtr, bool);

void i2cTransitionToAddress(I2CStatePtr state) {
    i2cDefaultStateImplementation(state);
    state->acknowledge = acknowledge;



}

static void acknowledge(I2CStatePtr state, bool isSuccess) {
    if (isSuccess) {
        i2cTransitionToWriteData(state);
    } else {
        i2cTransitionToError(state);
    }
}
