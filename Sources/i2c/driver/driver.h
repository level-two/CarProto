/*
 * driver.h
 *
 * Created: 29.05.2020 12:05:55
 *  Author: Yauheni
 */


#ifndef I2C_DRIVER_H_
#define I2C_DRIVER_H_

#include <avr/io.h>
#include <stdbool.h>

typedef void (*I2CDriverOperationCompleted)(bool);

#define I2C_NORMAL_MODE(xtalCpu) ((xtalCpu / 100000UL - 16UL)/2UL)
#define I2C_FAST_MODE(xtalCpu) ((xtalCpu / 400000UL - 16UL)/2UL)

void i2cDriverConfigure(uint8_t bitRateDivisionFactor);
void i2cDriverOnOperationCompleted(I2CDriverOperationCompleted completion);

void i2cDriverSendStart();
void i2cDriverSendRepeatedStart();
void i2cDriverSendStop();
void i2cDriverSendAddrForWrite(uint8_t addr);
void i2cDriverSendAddrForRead(uint8_t addr);
void i2cDriverSendData(uint8_t data);
void i2cDriverReadData(bool isLast);
uint8_t i2cDriverGetReceivedData();

#endif /* I2C_DRIVER_H_ */