/*
 * state.c
 *
 * Created: 29.05.2020 7:14:25
 *  Author: Yauheni
 */

#include <stdlib.h>
#include "state.h"
#include "common/unused.h"

static void defaultAcknowledge(I2CStatePtr, bool);
static void defaultAddTransaction(I2CStatePtr, uint8_t, uint8_t, uint8_t, uint8_t*, bool, I2CTransactionCompletion);

void i2cDefaultStateImplementation(I2CStatePtr state) {
    state->acknowledge = defaultAcknowledge;
    state->addTransaction = defaultAddTransaction;
}

static void defaultAcknowledge(I2CStatePtr state, bool isSuccess) {
    UNUSED(state);
    UNUSED(isSuccess);
}

static void defaultAddTransaction(
    I2CStatePtr state,
    uint8_t addr,
    uint8_t command,
    uint8_t bytesCount,
    uint8_t *buffer,
    bool write,
    I2CTransactionCompletion completion)
{
    I2CTransactionParamsPtr params = (I2CTransactionParamsPtr) malloc(sizeof(struct I2CTransactionParams));
    params->addr = addr;
    params->command = command;
    params->bytesCount = bytesCount;
    params->buffer = buffer;
    params->write = write;
    params->completion = completion;
    queuePushBack(state->transactionQueue, params);
}
