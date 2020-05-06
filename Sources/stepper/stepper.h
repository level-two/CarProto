/*
 * stepper.h
 *
 * Created: 05.05.2020 17:40:07
 *  Author: Yauheni
 */

#include <stdbool.h>
#include <avr/io.h>

#ifndef STEPPER_H_
#define STEPPER_H_

enum StepperCommandProcessingResult {
	commandAccepted,
	alreadyHaveCommand,
	notInitialized,
};

enum StepperDir {
	cw,
	ccw
};

enum StepperState {
	notsetupd,
	idle,
	turning
};

void stepperInit();
StepperCommandProcessingResult stepperPark();
StepperCommandProcessingResult stepperTurn(int steps, StepperDir dir);
StepperCommandProcessingResult stepperSetMaxTurns()



somewhere should be update() - by timer or external (like top loop)

// layer 4 (logic)
void calibrate()
void steer(to dir) // left, right, forward
void enable(on/off) // should terminate any activity
State state() // idle, in progress and so on


// layer 3 (functional)
void setup()
void calibrate() // non blocking
void park(left/right/middle) // assert(minStep != maxStep)
Pos currentPos() // parked left/right/middle
void enable(on/off) // should terminate any activity
Statte state() // idle, calibrating, parking


// layer 2 (protocol impl) - signal timings etc
void setup()
void step(left/right) // error on operation requests collision
void sleep(on/off)
void getStopperState(left/right)
void terminateOperation()
void state() // idle, in progress and so on


// layer 1 (hardware)
void setupHardware()
void setStep(bool)
void setDir(bool)
bool leftStopperState()
bool rightStopperState()
void startTimer(nanosec)
bool timerFired()
void setSleep(bool) // puts all hardware in sleep - driver and timer
void stopTimer()

// internal
void setupTimer()


// Layer 0 (Wiring)
void setupPorts()

void setStepperDir(bool)
void setStepperStep(bool)
void setStepperSleep(bool)
bool getStepperLeftStopper()
bool getStepperRightStopper()

#endif /* STEPPER_H_ */