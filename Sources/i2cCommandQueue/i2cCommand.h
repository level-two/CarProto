/*
 * i2cCommand.h
 *
 * Created: 29.05.2020 12:58:30
 *  Author: Yauheni
 */

#ifndef I2C_COMMAND_H_
#define I2C_COMMAND_H_

#include <inttypes.h>
#include <stdbool.h>

typedef struct I2CCommand* I2CCommandPtr;

typedef enum {
    i2cWriteCommandType,
    i2cWriteReadCommandType
} I2CCommandType;

struct I2CCommand {
    I2CCommandType commandType;
    uint8_t addr;
    uint8_t *wrData;
    uint8_t wrLen;
    uint8_t *rdData;
    uint8_t rdLen;

    bool isCompleted;
    bool isError;

    I2CCommandPtr nextCommand;
};

#endif /* I2C_COMMAND_H_ */