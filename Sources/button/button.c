/*
 * button.c
 *
 * Created: 20.05.2020 5:51:55
 *  Author: Yauheni
 */

#include <stdlib.h>
#include "button.h"
#include "common/bitManipulations.h"

ButtonPtr buttonSetup(volatile uint8_t* portReg, volatile uint8_t* pinReg, uint8_t buttonPin) {
    ButtonPtr button = (ButtonPtr) malloc(sizeof(Button));
    if (button == NULL) { return NULL; }

    button->portReg = portReg;
    button->pinReg = pinReg;
    button->buttonPin = buttonPin;

    // Set pullup
    setBit(button->portReg, button->buttonPin);
    return button;
}

bool buttonStatus(ButtonPtr button) {
    return readBit(button->pinReg, button->buttonPin);
}

void buttonRelease(ButtonPtr button) {
    clearBit(button->portReg, button->buttonPin);
    free(button);
}