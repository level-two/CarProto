/*
 * i2c.c
 *
 * Created: 29.05.2020 6:52:12
 *  Author: Yauheni
 */

#include <stdlib.h>
#include "i2c.h"
#include "common/queue.h"
#include "reference/reference.h"
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
    retain(transactionQueue);

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

void i2cDisable() {
    while (queueIsEmpty(transactionQueue) == false);
    release(transactionQueue);
    i2cDriverDisable();
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
    I2CTransactionPtr transaction = (I2CTransactionPtr) alloc(sizeof(struct I2CTransaction));
    autorelease(transaction);
    transaction->addr = addr;
    transaction->subaddr = subaddr;
    transaction->write = false;
    transaction->data = (uint8_t *) alloc(bytesCount * sizeof(uint8_t));
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
    I2CTransactionPtr transaction = (I2CTransactionPtr) alloc(sizeof(struct I2CTransaction));
    autorelease(transaction);
    transaction->addr = addr;
    transaction->subaddr = subaddr;
    transaction->write = true;
    transaction->data = (uint8_t *) alloc(sizeof(uint8_t));
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
    I2CTransactionPtr transaction = (I2CTransactionPtr) alloc(sizeof(struct I2CTransaction));
    autorelease(transaction);
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
    autorelease(transaction->data);

    I2COperationCompletion completion = transaction->completion;

    if (completion == NULL) {
        // do nothing
    } else if (isSuccess == false || transaction->write) {
        completion(isSuccess, NULL, 0);
    } else {
        completion(isSuccess, transaction->data, transaction->dataLen);
    }

    tryStrartNextTransaction();
}

static void tryStrartNextTransaction() {
    if (i2cSequenceInProgress() || queueIsEmpty(transactionQueue)) { return; }
    I2CTransactionPtr transaction = queueHead(transactionQueue);
    i2cSequenceStratTransaction(transaction);
}