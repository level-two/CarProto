/*
 * i2cHandler.h
 *
 * Created: 29.05.2020 12:58:30
 *  Author: Yauheni
 */

#ifndef I2C_HANDLER_H_
#define I2C_HANDLER_H_

#include <inttypes.h>

typedef struct I2CCommand* I2CCommandPtr;

struct I2CCommand {
    uint8_t addr;
    uint8_t *wrData;
    uint8_t *rdData;
    uint8_t wrLen;
    uint8_t rdLen;

    //uint8_t id;
    //I2CCommand *nextCommand;
};

I2CCommand i2cCommandMake();
void i2cCommandRelease(I2CCommand*);

#endif /* I2C_HANDLER_H_ */