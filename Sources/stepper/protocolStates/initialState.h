/*
 * initialState.h
 *
 * Created: 13.05.2020 10:55:15
 *  Author: Yauheni
 */

#ifndef INITIALSTATE_H_
#define INITIALSTATE_H_

#include "protocolLayerState.h"
#include "stepper/stepperConfig.h"

void transitionToInitial(ProtocolLayerStatePtr, StepperConfigPtr);

#endif /* INITIALSTATE_H_ */