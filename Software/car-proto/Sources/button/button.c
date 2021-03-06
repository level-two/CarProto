/*
 * button.c
 *
 * Created: 20.05.2020 5:51:55
 *  Author: Yauheni
 */

#include <stdlib.h>
#include "reference/reference.h"
#include "button.h"
#include "common/bitManipulations.h"

ButtonPtr buttonSetup(volatile uint8_t* portReg, volatile uint8_t* pinReg, uint8_t buttonPin) {
    ButtonPtr button = (ButtonPtr) alloc(sizeof(Button));
    if (button == NULL) return NULL;
    autorelease(button);

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

void buttonReleaseResources(ButtonPtr button) {
    if (button == NULL) return;
    clearBit(button->portReg, button->buttonPin);
}