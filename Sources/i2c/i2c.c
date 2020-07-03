/*
 * i2c.c
 *
 * Created: 29.05.2020 6:52:12
 *  Author: Yauheni
 */

#include <stdlib.h>
#include "i2c.h"
#include "states/state.h"

//static I2CStatePtr i2cState;

void i2cTransaction(uint8_t addr, uint8_t command, uint8_t bytesCount, uint8_t *bufferPtr, bool isWrite, I2COperationCompletion completion) {
    //I2CHandlerPtr handler = (I2CHandlerPtr) malloc(sizeof(struct I2CHandler));
    //handler->state = (I2CStatePtr) malloc(sizeof(struct I2CState));
    //return handler;
}

