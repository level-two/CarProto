/*
 * i2c.h
 *
 * Created: 29.05.2020 6:52:04
 *  Author: Yauheni
 */

#ifndef I2C_H_
#define I2C_H_

#include <inttypes.h>
#include <stdbool.h>


I2CCommandPtr i2cWrite(uint8_t addr, uint8_t *data, uint8_t len);
I2CCommandPtr i2cWriteRead(
    uint8_t addr,
    uint8_t *wrData, uint8_t wrLen,
    uint8_t *rdData, uint8_t rdLen);

void i2cComplete(I2CCommandPtr);

#endif /* I2C_H_ */