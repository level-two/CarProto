/*
 * gyroscope.h
 *
 * Created: 10.07.2020 15:05:11
 *  Author: Yauheni
 */

#ifndef GYROSCOPE_H_
#define GYROSCOPE_H_

#include <inttypes.h>

typedef void (*GyroscopeDataCallback)(uint8_t*, uint8_t);

void gyroscopeConfigure();
//void gyroscopeGetData(GyroscopeDataCallback);

#endif /* GYROSCOPE_H_ */