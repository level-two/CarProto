/*
 * state.h
 *
 * Created: 29.05.2020 7:14:33
 *  Author: Yauheni
 */

#ifndef I2C_STATE_H_
#define I2C_STATE_H_

typedef struct I2CState* I2CStatePtr;
typedef void (*I2CInterruptEvent)(I2CStatePtr);

struct I2CState {
    I2CInterruptEvent i2cInterrupt;
};

void defaultI2CStateImplementation(I2CStatePtr state);

#endif /* I2C_STATE_H_ */