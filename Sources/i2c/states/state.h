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

typedef struct I2CState* I2CStatePtr;

typedef void (*I2CAcknowledgeEvent)(I2CStatePtr, bool);
typedef void (*I2CTransactionEvent)(I2CStatePtr, I2CTransactionParams);

struct I2CTransactionState {
    uint8_t bytesTransferred;
};

struct I2CState {
    I2CAcknowledgeEvent acknowledge;
    I2CTransactionEvent newTransaction;

    struct I2CTransactionParams transactionParams;
    struct I2CTransactionState transactionState;
};

void i2cDefaultStateImplementation(I2CStatePtr state);

#endif /* I2C_STATE_H_ */