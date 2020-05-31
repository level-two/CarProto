/*
 * i2cCommandQueue.h
 *
 * Created: 29.05.2020 14:04:53
 *  Author: Yauheni
 */


#ifndef I2CCOMMANDQUEUE_H_
#define I2CCOMMANDQUEUE_H_

#include <inttypes.h>
#include <stdbool.h>
#include "i2cCommand.h"

I2CCommandPtr i2cQueueWriteCommand(uint8_t addr, uint8_t *data, uint8_t len);
I2CCommandPtr i2cQueueWriteReadCommand(uint8_t addr, uint8_t *wrData, uint8_t wrLen, uint8_t *rdData, uint8_t rdLen);
bool i2cQueueIsCompleted(I2CCommandPtr);
bool i2cQueueIsError(I2CCommandPtr);
void i2cQueueRelease(I2CCommandPtr);

#endif /* I2CCOMMANDQUEUE_H_ */