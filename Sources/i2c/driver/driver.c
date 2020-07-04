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
    StatusStart = 0x08,
    StatusRepeatedStart = 0x10,

    StatusWriteAddrAck = 0x18,
    StatusWriteAddrNack = 0x20,
    StatusWriteDataAck = 0x28,
    StatusWriteDataNack = 0x30,

    StatusArbLost = 0x38,

    StatusReadAddrAck = 0x40,
    StatusReadAddrNack = 0x48,
    StatusReadDataAck = 0x50,
    StatusReadDataNack = 0x58,
} OperationStatus;


static I2CDriverAcknowledgeCallback acknowledgeCallback = NULL;
static OperationStatus expectedStatus;
static uint8_t currentStatus();


ISR(TWI_vect) {
    if (acknowledgeCallback != NULL) {
        bool isSuccess = (currentStatus() == expectedStatus);
        acknowledgeCallback(isSuccess);
    }
}


void i2cDriverConfigure(uint8_t bitRateDivisionFactor) {
    TWBR = bitRateDivisionFactor;
    TWSR &= ~( (1 << TWPS1) | (1 << TWPS0));
}

void i2cDriverSetAcknowledgeCallback(I2CDriverAcknowledgeCallback callback) {
    acknowledgeCallback = callback;
}

void i2cDriverSendStart() {
    expectedStatus = StatusStart;
    TWCR = (1 << TWIE) | (1 << TWINT) | (1 << TWEN) | (1 << TWSTA);
}

void i2cDriverSendRepeatedStart() {
    expectedStatus = StatusRepeatedStart;
    TWCR = (1 << TWIE) | (1 << TWINT) | (1 << TWEN) | (1 << TWSTA);
}

void i2cDriverSendStop() {
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
}

void i2cDriverSendAddrForWrite(uint8_t addr) {
    expectedStatus = StatusWriteAddrAck;
    TWDR = addr << 1 | (1 << 0);
    TWCR = (1 << TWIE) | (1 << TWINT) | (1 << TWEN);
}

void i2cDriverSendAddrForRead(uint8_t addr) {
    expectedStatus = StatusReadAddrAck;
    TWDR = addr << 1;
    TWCR = (1 << TWIE) | (1 << TWINT) | (1 << TWEN);
}

void i2cDriverSendData(uint8_t data) {
    expectedStatus = StatusWriteDataAck;
    TWDR = data;
    TWCR = (1 << TWIE) | (1 << TWINT) | (1 << TWEN);
}

uint8_t i2cDriverGetReceivedData() {
    return TWDR;
}

void i2cDriverSendReadDataAck() {
    expectedStatus = StatusReadDataAck;
    TWCR = (1 << TWIE) | (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
}

void i2cDriverSendReadDataNack() {
    expectedStatus = StatusReadDataNack;
    TWCR = (1 << TWIE) | (1 << TWINT) | (1 << TWEN);
}

static uint8_t currentStatus() {
    return (TWSR & 0xF8);
}
