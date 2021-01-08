/*
 * magnetometer.h
 *
 * Created: 14.07.2020 17:15:07
 *  Author: Yauheni
 */

#ifndef MAGNETOMETER_H_
#define MAGNETOMETER_H_

#include <inttypes.h>

typedef struct {
    int16_t x;
    int16_t y;
    int16_t z;
} MagnetometerData;

typedef void (*MagnetometerDataCallback)(MagnetometerData);

void magnetometerConfigure();
void magnetometerRequestData();
void magnetometerOnDataReceived(MagnetometerDataCallback);

#endif /* MAGNETOMETER_H_ */