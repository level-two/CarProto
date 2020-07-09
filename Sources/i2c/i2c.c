/*
 * i2c.c
 *
 * Created: 29.05.2020 6:52:12
 *  Author: Yauheni
 */

#include <stdlib.h>
#include "i2c.h"
#include "driver/driver.h"
#include "states/state.h"
#include "states/initial.h"

#if !defined(F_CPU)
    #error "Please define F_CPU"
#endif

static I2CStatePtr i2cState;

static void acknowledge(bool);

void i2cConfigure(I2CMode mode) {
    i2cState = (I2CStatePtr) malloc(sizeof(struct I2CState));
    i2cTransitionToInitial(i2cState);

    i2cDriverSetAcknowledgeCallback(acknowledge);

    switch (mode) {
    case i2cNormalMode:
        i2cDriverConfigure(I2C_NORMAL_MODE(F_CPU));
        break;
    case i2cFastMode:
        i2cDriverConfigure(I2C_FAST_MODE(F_CPU));
        break;
    }
}

void i2cTransaction(
    uint8_t addr,
    uint8_t command,
    uint8_t bytesCount,
    uint8_t *buffer,
    bool write,
    I2COperationCompletion completion)
{
    i2cState->addTransaction(i2cState, addr, command, bytesCount, buffer, write, completion);
}

void acknowledge(bool ack) {
    i2cState->acknowledge(i2cState, ack);
}