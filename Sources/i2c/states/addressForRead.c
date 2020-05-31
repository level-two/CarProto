/*
 * addressForRead.c
 *
 * Created: 30.05.2020 7:00:03
 *  Author: Yauheni
 */

#include "addressForRead.h"
#include "i2c/driver/driver.h"
#include "readData.h"
#include "completion.h"

static void acknowledge(I2CStatePtr, bool);

void i2cTransitionToAddressForRead(I2CStatePtr state) {
    i2cDefaultStateImplementation(state);
    state->acknowledge = acknowledge;

}

static void acknowledge(I2CStatePtr state, bool isSuccess) {
    if (isSuccess) {
        i2cTransitionToReadData(state);
    } else {
        i2cTransitionToCompletion(state, false);
    }
}
