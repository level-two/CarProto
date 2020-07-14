/*
 * accelerometer.c
 *
 * Created: 14.07.2020 16:18:42
 *  Author: Yauheni
 */

#include <stdlib.h>
#include <stdbool.h>
#include "i2c/i2c.h"
#include "common/unused.h"
#include "accelerometer.h"
#include "lis331dlh.h"

static void onData(bool, uint8_t*, uint8_t);

static AccelerometerDataCallback onDataReceived;

void accelerometerConfigure() {
    i2cWriteByte(ADDRESS, CTRL1_REG, (1 << PM) | (7 << ZYXEN), NULL);
    i2cWriteByte(ADDRESS, CTRL4_REG, (1 << BDU), NULL);
}

void accelerometerOnDataReceived(AccelerometerDataCallback callback) {
    onDataReceived = callback;
}

void accelerometerRequestData() {
    i2cRead(ADDRESS, DATA_OUT_BASE_REG, 6, onData);
}

static void onData(bool isSuccess, uint8_t* data, uint8_t len) {
    UNUSED(len);
    if (!isSuccess) { return; }

    AccelerometerData accData;
    accData.x = ((int16_t)data[1] << 8) | (int16_t)data[0];
    accData.y = ((int16_t)data[3] << 8) | (int16_t)data[2];
    accData.z = ((int16_t)data[5] << 8) | (int16_t)data[4];

    onDataReceived(accData);
    free(data);

}
