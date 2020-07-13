/*
 * i2c.c
 *
 * Created: 29.05.2020 6:52:12
 *  Author: Yauheni
 */

#include <stdlib.h>
#include "i2c.h"
#include "common/queue.h"
#include "driver/driver.h"
#include "sequence/sequence.h"
#include "sequence/transaction.h"

#if !defined(F_CPU)
    #error "Please define F_CPU"
#endif

static QueuePtr transactionQueue;
static void transactionCompleted(bool);
static void tryStrartNextTransaction();

void i2cConfigure(I2CMode mode) {
    transactionQueue = queueMake();

    i2cSequenceSetup();
    i2cSequenceSetCompletion(transactionCompleted);

    switch (mode) {
    case i2cNormalMode:
        i2cDriverConfigure(I2C_NORMAL_MODE(F_CPU));
        break;
    case i2cFastMode:
        i2cDriverConfigure(I2C_FAST_MODE(F_CPU));
        break;
    }
}

void i2cReadByte(
    uint8_t addr,
    uint8_t subaddr,
    I2COperationCompletion completion)
{
    i2cRead(addr, subaddr, 1, completion);
}

void i2cRead(
    uint8_t addr,
    uint8_t subaddr,
    uint8_t bytesCount,
    I2COperationCompletion completion)
{
    I2CTransactionPtr transaction = (I2CTransactionPtr) malloc(sizeof(struct I2CTransaction));
    transaction->addr = addr;
    transaction->subaddr = subaddr;
    transaction->write = false;
    transaction->data = (uint8_t *) malloc(bytesCount * sizeof(uint8_t));
    transaction->dataLen = bytesCount;
    transaction->completion = completion;
    queuePushBack(transactionQueue, transaction);
    tryStrartNextTransaction();
}

void i2cWriteByte(
    uint8_t addr,
    uint8_t subaddr,
    uint8_t byte,
    I2COperationCompletion completion)
{
    I2CTransactionPtr transaction = (I2CTransactionPtr) malloc(sizeof(struct I2CTransaction));
    transaction->addr = addr;
    transaction->subaddr = subaddr;
    transaction->write = true;
    transaction->data = (uint8_t *) malloc(sizeof(uint8_t));
    transaction->data[0] = byte;
    transaction->dataLen = 1;
    transaction->completion = completion;
    queuePushBack(transactionQueue, transaction);
    tryStrartNextTransaction();
}

void i2cWrite(
    uint8_t addr,
    uint8_t subaddr,
    uint8_t *data,
    uint8_t bytesCount,
    I2COperationCompletion completion)
{
    I2CTransactionPtr transaction = (I2CTransactionPtr) malloc(sizeof(struct I2CTransaction));
    transaction->addr = addr;
    transaction->subaddr = subaddr;
    transaction->write = true;
    transaction->data = data;
    transaction->dataLen = bytesCount;
    transaction->completion = completion;
    queuePushBack(transactionQueue, transaction);
    tryStrartNextTransaction();
}

static void transactionCompleted(bool isSuccess) {
    I2CTransactionPtr transaction = queuePopFront(transactionQueue);

    I2COperationCompletion completion = transaction->completion;

    if (isSuccess == false || completion == NULL || transaction->write) {
        free(transaction->data);
        transaction->data = NULL;
        transaction->dataLen = 0;
    }

    if (completion != NULL) {
        completion(isSuccess, transaction->data, transaction->dataLen);
    }

    free(transaction);

    tryStrartNextTransaction();
}

static void tryStrartNextTransaction() {
    if (i2cSequenceInProgress() || queueIsEmpty(transactionQueue)) { return; }
    I2CTransactionPtr transaction = queueHead(transactionQueue);
    i2cSequenceStratTransaction(transaction);
}