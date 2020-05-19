/*
 * driver.h
 *
 * Created: 08.05.2020 0:09:30
 *  Author: Yauheni
 */

#ifndef DRIVER_H_
#define DRIVER_H_

#include <stdbool.h>
#include "stepperConfig.h"

void driverLayerSetup(StepperConfigPtr);
void driverLayerSetStep(StepperConfigPtr, bool);
void driverLayerSetDir(StepperConfigPtr, bool);
void driverLayerSetSleep(StepperConfigPtr, bool);
bool driverLayerLeftStopperStatus(StepperConfigPtr);
bool driverLayerRightStopperStatus(StepperConfigPtr);

#endif /* DRIVER_H_ */