/*
 * accelerometer.h
 *
 * Created: 14.07.2020 16:18:32
 *  Author: Yauheni
 */


#ifndef ACCELEROMETER_H_
#define ACCELEROMETER_H_

#include <inttypes.h>

typedef struct {
    int16_t x;
    int16_t y;
    int16_t z;
} AccelerometerData;

typedef void (*AccelerometerDataCallback)(AccelerometerData);

void accelerometerConfigure();
void accelerometerRequestData();
void accelerometerOnDataReceived(AccelerometerDataCallback);



#endif /* ACCELEROMETER_H_ */