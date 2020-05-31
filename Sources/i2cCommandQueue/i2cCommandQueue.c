/*
 * i2cCommandQueue.c
 *
 * Created: 29.05.2020 14:05:05
 *  Author: Yauheni
 */

#include <stdlib.h>
#include "i2cCommandQueue.h"
#include "i2c/i2c.h"

static I2CCommandPtr currentCommand = NULL;

static I2CCommandPtr i2cQueueMakeCommand();
static I2CCommandPtr i2cQueueCurrentCommand();
static void i2cQueuePushBack(I2CCommandPtr);
static void i2cQueuePopFront();
static void i2cQueueExecute(I2CCommandPtr command);
static void i2cQueueCommandCompletion(bool isSuccess);

I2CCommandPtr i2cQueueWriteCommand(uint8_t addr, uint8_t *data, uint8_t len) {
    I2CCommandPtr command = i2cQueueMakeCommand();
    if (command == NULL) { return NULL; }

    command->commandType = i2cWriteCommandType;
    command->addr= addr;
    command->wrData = data;
    command->wrLen = len;
    i2cQueuePushBack(command);

    return command;
}

I2CCommandPtr i2cQueueWriteReadCommand(uint8_t addr, uint8_t *wrData, uint8_t wrLen, uint8_t *rdData, uint8_t rdLen) {
    I2CCommandPtr command = i2cQueueMakeCommand();
    if (command == NULL) { return NULL; }

    command->commandType = i2cWriteReadCommandType;
    command->addr = addr;
    command->wrData = wrData;
    command->wrLen = wrLen;
    command->rdData = rdData;
    command->rdLen = rdLen;
    i2cQueuePushBack(command);

    return command;
}

bool i2cQueueIsCompleted(I2CCommandPtr command) {
    return command->isCompleted;
}

bool i2cQueueIsError(I2CCommandPtr command) {
    return command->isError;
}

void i2cQueueRelease(I2CCommandPtr command) {
    free(command);
}


static I2CCommandPtr i2cQueueMakeCommand() {
    return (I2CCommandPtr) calloc(1, sizeof(struct I2CCommand));
}


static I2CCommandPtr i2cQueueCurrentCommand() {
    return currentCommand;
}

static void i2cQueuePushBack(I2CCommandPtr command) {
    if (currentCommand == NULL) {
        currentCommand = command;
        i2cQueueExecute(command);
    } else {
        I2CCommandPtr cmd;
        for (cmd = currentCommand; cmd->nextCommand != NULL; cmd = cmd->nextCommand);
        cmd->nextCommand = command;
    }
}

static void i2cQueuePopFront() {
    currentCommand = currentCommand->nextCommand;
}


static void i2cQueueExecute(I2CCommandPtr command) {
    if (command == NULL) { return; }

    switch (command->commandType) {
    case i2cWriteCommandType:
        i2cWrite(
            command->addr,
            command->wrData,
            command->wrLen,
            i2cQueueCommandCompletion);
        break;
    case i2cWriteReadCommandType:
        i2cWriteRead(
            command->addr,
            command->wrData,
            command->wrLen,
            command->rdData,
            command->rdLen,
            i2cQueueCommandCompletion);
        break;
    }
}

static void i2cQueueCommandCompletion(bool isSuccess) {
    I2CCommandPtr command = i2cQueueCurrentCommand();
    command->isCompleted = true;
    command->isError = !isSuccess;

    i2cQueuePopFront();
    I2CCommandPtr nextCommand = i2cQueueCurrentCommand();
    i2cQueueExecute(nextCommand);
}