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

typedef void (*I2COperationCompletion)(bool);

void i2cTransaction(
    uint8_t addr,
    uint8_t command,
    uint8_t bytesCount,
    uint8_t *bufferPtr,
    bool write,
    I2COperationCompletion completion);

#endif /* I2C_H_ */