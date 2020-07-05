/*
 * timer0.c
 *
 * Created: 09.05.2020 16:23:58
 *  Author: Yauheni
 */

#include <avr/io.h>
#include "common/bitManipulations.h"
#include "timer0.h"

#if !defined(F_CPU)
    #error "Please define F_CPU"
#endif

#define PRESCALER_DIV 64
#define USEC_PER_TICK (1000000UL * PRESCALER_DIV / F_CPU)

void timer0Start() {
    // Set prescaler to 64
    TCCR0B |= _BV(CS01) | _BV(CS00);
    timer0Reset();
}

void timer0Stop() {
    TCCR0B &= ~( _BV(CS02) | _BV(CS01) | _BV(CS00));
}

void timer0Reset() {
    TCNT0 = 0;
}

uint16_t timer0Microseconds() {
    uint16_t currentTick = (uint16_t)TCNT0;
    return currentTick * USEC_PER_TICK;
}
