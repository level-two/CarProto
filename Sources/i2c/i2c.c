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

void i2cWrite(uint8_t addr, uint8_t *data, uint8_t len, I2COperationCompletion completion) {
    //I2CHandlerPtr handler = (I2CCommandPtr) malloc(sizeof(struct I2CHandler));
    //handler->state = (I2CStatePtr) malloc(sizeof(struct I2CState));
    //return handler;
    //state->
}

void i2cWriteRead(uint8_t addr, uint8_t *wrData, uint8_t wrLen, uint8_t *rdData, uint8_t rdLen, I2COperationCompletion completion) {
    //I2CHandlerPtr handler = (I2CHandlerPtr) malloc(sizeof(struct I2CHandler));
    //handler->state = (I2CStatePtr) malloc(sizeof(struct I2CState));
    //return handler;
}
