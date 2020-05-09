/*
 * driver.h
 *
 * Created: 08.05.2020 0:09:30
 *  Author: Yauheni
 */

#ifndef DRIVER_H_
#define DRIVER_H_

#include <stdbool.h>

// layer 1 (Driver)
void setupHardware()
void setStep(bool)
void setDir(bool)
void setSleep(bool) // puts all hardware in sleep - driver and timer
bool leftStopperState()
bool rightStopperState()

// probably, this should be system
void call(func, after ms)
void setupTimer()
void startTimer(nanosec)
bool timerFired()
void stopTimer()



#endif /* DRIVER_H_ */