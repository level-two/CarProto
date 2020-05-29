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

typedef struct I2CHandler* I2CHandlerPtr;

I2CHandlerPtr i2cWrite(uint8_t addr, uint8_t *data, uint8_t len);
I2CHandlerPtr i2cWriteRead(uint8_t addr, uint8_t *wrData, uint8_t wrLen, uint8_t *rdDataOutputBuf, uint8_t rdLen);

#endif /* I2C_H_ */