/*
 * driver.h
 *
 * Created: 08.05.2020 0:09:30
 *  Author: Yauheni
 */

#ifndef DRIVER_H_
#define DRIVER_H_

#include <stdbool.h>

void driverLayerSetup();
void driverLayerSetStep(bool);
void driverLayerSetDir(bool);
void driverLayerSetSleep(bool);
bool driverLayerLeftStopperStatus();
bool driverLayerRightStopperStatus();

#endif /* DRIVER_H_ */