/*
 * driver.h
 *
 * Created: 29.05.2020 12:05:55
 *  Author: Yauheni
 */


#ifndef I2C_DRIVER_H_
#define I2C_DRIVER_H_

#include <avr/io.h>

typedef enum {
    i2cDriverStatusStart = 0x08,
    i2cDriverStatusRepeatedStart = 0x10,

    i2cDriverStatusWriteAddrAck = 0x18,
    i2cDriverStatusWriteAddrNack = 0x20,
    i2cDriverStatusWriteDataAck = 0x28,
    i2cDriverStatusWriteDataNack = 0x30,

    i2cDriverStatusArbLost = 0x38,

    i2cDriverStatusReadAddrAck = 0x40,
    i2cDriverStatusReadAddrNack = 0x48,
    i2cDriverStatusReadDataAck = 0x50,
    i2cDriverStatusReadDataNack = 0x58,
} I2CDriverOperationStatus;

typedef void (*I2CDriverAcknowledgeCallback)(bool);

void i2cDriverSetAcknowledgeCallback(I2CDriverAcknowledgeCallback);


#endif /* I2C_DRIVER_H_ */