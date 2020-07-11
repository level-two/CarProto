/*
 * driver.c
 *
 * Created: 29.05.2020 12:06:05
 *  Author: Yauheni
 */

#include <stdbool.h>
#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "driver.h"
#include "common/bitManipulations.h"

typedef enum {
    statusStart = 0x08,
    statusRepeatedStart = 0x10,

    statusWriteAddrAck = 0x18,
    statusWriteAddrNack = 0x20,
    statusWriteDataAck = 0x28,
    statusWriteDataNack = 0x30,

    statusArbLost = 0x38,

    statusReadAddrAck = 0x40,
    statusReadAddrNack = 0x48,
    statusReadDataAck = 0x50,
    statusReadDataNack = 0x58
} OperationStatus;


static I2CDriverOperationCompleted completionCallback = NULL;

static OperationStatus expectedStatus;
static uint8_t currentStatus();


ISR(TWI_vect) {
    if (completionCallback == NULL) { return; }
    bool isSuccess = (currentStatus() == expectedStatus);
    completionCallback(isSuccess);
}


void i2cDriverConfigure(uint8_t bitRateDivisionFactor) {
    TWBR = bitRateDivisionFactor;
    TWSR &= ~( (1 << TWPS1) | (1 << TWPS0));
}

void i2cDriverOnOperationCompleted(I2CDriverOperationCompleted completion) {
    completionCallback = completion;
}

void i2cDriverSendStart() {
    expectedStatus = statusStart;
    TWCR = (1 << TWIE) | (1 << TWINT) | (1 << TWEN) | (1 << TWSTA);
}

void i2cDriverSendRepeatedStart() {
    expectedStatus = statusRepeatedStart;
    TWCR = (1 << TWIE) | (1 << TWINT) | (1 << TWEN) | (1 << TWSTA);
}

void i2cDriverSendStop() {
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
}

void i2cDriverSendAddrForWrite(uint8_t addr) {
    expectedStatus = statusWriteAddrAck;
    TWDR = (addr << 1);
    TWCR = (1 << TWIE) | (1 << TWINT) | (1 << TWEN);
}

void i2cDriverSendAddrForRead(uint8_t addr) {
    expectedStatus = statusReadAddrAck;
    TWDR = (addr << 1) | 0x01;
    TWCR = (1 << TWIE) | (1 << TWINT) | (1 << TWEN);
}

void i2cDriverSendData(uint8_t data) {
    expectedStatus = statusWriteDataAck;
    TWDR = data;
    TWCR = (1 << TWIE) | (1 << TWINT) | (1 << TWEN);
}

void i2cDriverReadData(bool isLast) {
    if (isLast) {
        expectedStatus = statusReadDataNack;
        TWCR =(1 << TWIE) | (1 << TWINT) | (1 << TWEN);
    } else {
        expectedStatus = statusReadDataAck;
        TWCR = (1 << TWIE) | (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
    }
}

uint8_t i2cDriverGetReceivedData() {
    return TWDR;
}

static uint8_t currentStatus() {
    return (TWSR & 0xF8);
}
