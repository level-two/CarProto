/*
 * wiring.c
 *
 * Created: 08.05.2020 1:22:52
 *  Author: Yauheni
 */

#include <avr/io.h>
#include "wiring.h"
#include "common/bitManipulations.h"

void setupPorts() {
    setBits(&DDRA, bitVector3(DDA2, DDA1, DDA0));

    // inputs with pullups
    clearBits(&DDRA, bitVector2(DDA4, DDA3));
    setBits(&PORTA, bitVector2(PORTA4, PORTA3));
}

void setStepperDir(bool val) {
    writeBit(&PORTA, PORTA0, val);
}

void setStepperStep(bool val) {
    writeBit(&PORTA, PORTA1, val);
}

void setStepperSleep(bool val) {
    writeBit(&PORTA, PORTA2, val);
}

bool getStepperLeftStopper() {
    return readBit(&PINA, PINA4);
}

bool getStepperRightStopper() {
    return readBit(&PINA, PINA3);
}
