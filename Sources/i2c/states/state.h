/*
 * state.h
 *
 * Created: 29.05.2020 7:14:33
 *  Author: Yauheni
 */

#ifndef I2C_STATE_H_
#define I2C_STATE_H_

#include <inttypes.h>
#include <stdbool.h>
#include "transactionParams.h"
#include "queue.h"

typedef struct I2CState* I2CStatePtr;

typedef void (*I2CAcknowledgeEvent)(I2CStatePtr, bool);
typedef void (*I2CTransactionEvent)(I2CStatePtr, uint8_t, uint8_t, uint8_t, uint8_t*, bool, I2CTransactionCompletion);

struct I2CTransactionState {
    uint8_t bytesTransferred;
};

struct I2CState {
    I2CAcknowledgeEvent acknowledge;
    I2CTransactionEvent addTransaction;

    I2CTransactionParamsPtr transactionParams;
    struct I2CTransactionState transactionState;

    QueuePtr transactionQueue;
};

void i2cDefaultStateImplementation(I2CStatePtr state);

#endif /* I2C_STATE_H_ */