/*
 * timer0.h
 *
 * Created: 09.05.2020 16:23:14
 *  Author: Yauheni
 */

#ifndef TIMER0_H_
#define TIMER0_H_

#include <inttypes.h>

void timer0Start();
void timer0Stop();
void timer0Reset();
uint16_t timer0Microseconds();

#endif /* TIMER_H_ */