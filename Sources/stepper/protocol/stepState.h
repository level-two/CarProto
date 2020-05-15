/*
 * stepState.h
 *
 * Created: 13.05.2020 12:08:22
 *  Author: Yauheni
 */

#ifndef STEPSTATE_H_
#define STEPSTATE_H_

#include "state.h"

void transitionToStep(StatePtr state, StepDir dir);

#endif /* STEPSTATE_H_ */