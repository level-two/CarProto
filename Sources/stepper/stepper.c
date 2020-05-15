/*
 * stepper.c
 *
 * Created: 08.05.2020 0:58:50
 *  Author: Yauheni
 */

#include "stepper.h"
#include "wiring.h" // FIXME

void stepperSetup() {
   // setupPorts();
}

void stepperEnable(bool en) {
    // should terminate any activity
}

void stepperCalibrate() {

}

void stepperPark(StepperParkPosition position)
{
    // assert(minStep != maxStep)
}

StepperState stepperState() {
    return disabled;
}

StepperParkPosition stepperCurrentPosition() {
    return middle;
}