/*
 * magnetometer.c
 *
 * Created: 14.07.2020 17:15:16
 *  Author: Yauheni
 */

#include <stdlib.h>
#include <stdbool.h>
#include "i2c/i2c.h"
#include "common/unused.h"
#include "magnetometer.h"
#include "lis3mdl.h"

static void onData(bool, uint8_t*, uint8_t);

static MagnetometerDataCallback onDataReceived;

void magnetometerConfigure() {
    i2cWriteByte(ADDRESS, CTRL2_REG, 0, NULL);
    i2cWriteByte(ADDRESS, CTRL1_REG, (3 << OM) | (4 << DO), NULL);
    i2cWriteByte(ADDRESS, CTRL4_REG, (3 << OMZ), NULL);
    i2cWriteByte(ADDRESS, CTRL3_REG, 0, NULL);
    i2cWriteByte(ADDRESS, CTRL5_REG, (1 << BDU), NULL);
}

void magnetometerOnDataReceived(MagnetometerDataCallback callback) {
    onDataReceived = callback;
}

void magnetometerRequestData() {
    i2cRead(ADDRESS, DATA_OUT_BASE_REG, 6, onData);
}

static void onData(bool isSuccess, uint8_t* data, uint8_t len) {
    UNUSED(len);
    if (!isSuccess) { return; }

    MagnetometerData magData;
    magData.x = ((int16_t)data[1] << 8) | (int16_t)data[0];
    magData.y = ((int16_t)data[3] << 8) | (int16_t)data[2];
    magData.z = ((int16_t)data[5] << 8) | (int16_t)data[4];

    onDataReceived(magData);
}
