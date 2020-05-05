/*
 * stepper.h
 *
 * Created: 05.05.2020 17:40:07
 *  Author: Yauheni
 */ 


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
	notConfigured,
	idle,
	turning
};

void stepperInit();
StepperCommandProcessingResult stepperPark();
StepperCommandProcessingResult stepperTurn(int steps, StepperDir dir);
StepperCommandProcessingResult stepperSetMaxTurns()



#endif /* STEPPER_H_ */