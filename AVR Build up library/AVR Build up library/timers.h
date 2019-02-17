#ifndef TIMER_H_
#define TIMER_H_
#define F_CPU 16000000UL

#include "ATMEGA32A.h"
#include "DIO.h"

void timer_init();

void timer_delay(uint32 n);


#endif /* TIMER_H_ */