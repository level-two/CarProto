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

typedef void (*I2COperationCompletion)(bool, uint8_t*, uint8_t);

typedef enum {
    i2cNormalMode,
    i2cFastMode
} I2CMode;

void i2cConfigure(I2CMode mode);

void i2cRead(
    uint8_t addr,
    uint8_t subaddr,
    uint8_t bytesCount,
    I2COperationCompletion completion);

void i2cWriteByte(
    uint8_t addr,
    uint8_t subaddr,
    uint8_t byte,
    I2COperationCompletion completion);

void i2cWriteData(
    uint8_t addr,
    uint8_t subaddr,
    uint8_t *data,
    uint8_t bytesCount,
    I2COperationCompletion completion);

#endif /* I2C_H_ */