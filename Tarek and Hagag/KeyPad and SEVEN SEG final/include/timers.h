#ifndef TIMER_H_
#define TIMER_H_

#include "ATMEGA32A.h"
#include "DIO.h"

void timer_init();

void timer_delay(uint32 n);

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define START_COUNT_FROM_250 250
#define INITIALIZE_TO_ZERO 0x00

#endif /* TIMER_H_ */