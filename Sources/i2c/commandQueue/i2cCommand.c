/*
 * i2cCommand.c
 *
 * Created: 29.05.2020 12:59:08
 *  Author: Yauheni
 */

#include "i2cCommand.h"
#include <stdlib.h>

I2CCommand* i2cCommandMake() {
    static uint8_t id = 0;

    I2CCommand* command = (I2CCommand*) calloc(1, sizeof(struct I2CCommand));
    if (command == NULL) { return NULL; }

    command->id = id;
    id += 1;

    return command;
}

void i2cCommandRelease(I2CCommand* command) {
    free(command);
}