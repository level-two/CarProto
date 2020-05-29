/*
 * i2c.c
 *
 * Created: 29.05.2020 6:52:12
 *  Author: Yauheni
 */

#include <stdlib.h>
#include "i2c.h"
#include "states/state.h"
#include "private/i2cCommand.h"

static I2CStatePtr i2cState;
static I2CCommandPtr currentCommand;

I2CCommandPtr i2cWrite(uint8_t addr, uint8_t *data, uint8_t len) {
    I2CHandlerPtr handler = (I2CCommandPtr) malloc(sizeof(struct I2CHandler));
    handler->state = (I2CStatePtr) malloc(sizeof(struct I2CState));
    return handler;
}

I2CCommandPtr i2cWriteRead(uint8_t addr, uint8_t *wrData, uint8_t wrLen, uint8_t *rdData, uint8_t rdLen) {
    //I2CHandlerPtr handler = (I2CHandlerPtr) malloc(sizeof(struct I2CHandler));
    //handler->state = (I2CStatePtr) malloc(sizeof(struct I2CState));
    return handler;
}

void i2cRelease(I2CCommandPtr command) {
    currentCommand = currentCommand->nextCommand;

}
