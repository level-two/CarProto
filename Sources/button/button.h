/*
 * button.h
 *
 * Created: 20.05.2020 5:51:40
 *  Author: Yauheni
 */


#ifndef BUTTON_H_
#define BUTTON_H_

#include <inttypes.h>
#include <stdbool.h>

typedef struct {
    volatile uint8_t* portReg;
    volatile uint8_t* pinReg;
    uint8_t buttonPin;
} Button;

typedef Button* ButtonPtr;

ButtonPtr buttonSetup(volatile uint8_t* portReg, volatile uint8_t* pinReg, uint8_t buttonPin);
bool buttonIsPressed(ButtonPtr);
void buttonRelease(ButtonPtr);

#endif /* BUTTON_H_ */