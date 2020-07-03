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

static I2CDriverAcknowledgeCallback acknnowledgeCallback = NULL;

ISR(TWI_vect) {
    acknnowledgeCallback();
}

void i2cDriverSetAcknowledgeCallback(I2CDriverAcknowledgeCallback callback) {
    acknnowledgeCallback = callback;
}

bool i2cDriverIsStatusEqual(I2CDriverOperationStatus status) {
    return (TWSR & 0xF8) == status;
}
