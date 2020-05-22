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
    if (button == NULL) return NULL;

    button->portReg = portReg;
    button->pinReg = pinReg;
    button->buttonPin = buttonPin;

    // Set pullup
    setBit(button->portReg, button->buttonPin);
    return button;
}

bool buttonIsPressed(ButtonPtr button) {
    bool pinState = readBit(button->pinReg, button->buttonPin);
    return !pinState; // Pin pulled low when button is pressed
}

void buttonRelease(ButtonPtr button) {
    if (button == NULL) return;
    clearBit(button->portReg, button->buttonPin);
    free(button);
}