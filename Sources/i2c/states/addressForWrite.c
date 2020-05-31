/*
 * addressForWrite.c
 *
 * Created: 29.05.2020 17:04:08
 *  Author: Yauheni
 */

#include "addressForWrite.h"
#include "i2c/driver/driver.h"
#include "writeData.h"
#include "completion.h"

static void acknowledge(I2CStatePtr, bool);

void i2cTransitionToAddressForWrite(I2CStatePtr state) {
    i2cDefaultStateImplementation(state);
    state->acknowledge = acknowledge;

}

static void acknowledge(I2CStatePtr state, bool isSuccess) {
    if (isSuccess) {
        i2cTransitionToWriteData(state);
    } else {
        i2cTransitionToCompletion(state, false);
    }
}
