/*
 * command.c
 *
 * Created: 29.05.2020 7:12:56
 *  Author: Yauheni
 */

#include <stdlib.h>
#include "command.h"
#include "i2c/driver/driver.h"
#include "writeData.h"
#include "repeatedStart.h"
#include "completion.h"

static void acknowledge(I2CStatePtr, bool);

void i2cTransitionToCommand(I2CStatePtr state) {
    i2cDefaultStateImplementation(state);
    state->acknowledge = acknowledge;

    uint8_t command = state->transactionParams->command;
    i2cDriverSendData(command);
}

static void acknowledge(I2CStatePtr state, bool isSuccess) {
    if (!isSuccess) {
        i2cTransitionToCompletion(state, false);
    } else if (state->transactionParams->write) {
        i2cTransitionToWriteData(state);
    } else {
        i2cTransitionToRepeatedStart(state);
    }
}
