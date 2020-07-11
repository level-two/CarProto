/*
 * gyroscope.c
 *
 * Created: 10.07.2020 15:05:24
 *  Author: Yauheni
 */

#include "gyroscope.h"
#include "i2c/i2c.h"

#define GYRO_ADDR 0x68
#define GYRO_WHO_REG 0x0F
#define GYRO_CTRL1_REG 0x20
#define GYRO_CTRL2_REG 0x21

void gyroscopeConfigure() {
    //i2cTransaction(GYRO_ADDR, GYRO_CTRL1_REG, 1, bufferwr, true, readCompleted);
}

//void gyroscopeGetData(GyroscopeDataCallback) {
//
//}