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

typedef struct I2CState* I2CStatePtr;
typedef void (*I2CAcknowledgeEvent)(I2CStatePtr, bool);
typedef void (*I2CWriteEvent)(I2CStatePtr, uint8_t, uint8_t*, uint8_t);
typedef void (*I2CReadEvent)(I2CStatePtr, uint8_t, uint8_t*, uint8_t, uint8_t*, uint8_t);

struct I2CState {
    I2CAcknowledgeEvent acknowledge;
    I2CWriteEvent write;
    I2CReadEvent read;

    // parameters
    uint8_t addr;
    uint8_t *wrData;
    uint8_t wrLen;

    bool isRead;
    uint8_t *rdData;
    uint8_t rdLen;

    // state
    uint8_t bytesCount;
};

void i2cDefaultStateImplementation(I2CStatePtr state);

#endif /* I2C_STATE_H_ */