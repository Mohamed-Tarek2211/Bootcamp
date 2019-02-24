#ifndef TIMER_H_
#define TIMER_H_

#include "ATMEGA32A.h"
#include "DIO.h"

void timer0_init();

void timer0_delay(uint32 n);

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define BIT0 0
#define BIT1 1
#define BIT2 2
#define BIT3 3
#define BIT4 4
#define BIT5 5
#define BIT6 6
#define BIT7 7

#define START_COUNT_FROM_250 250
#define START_COUNT_FROM_124 124
#define INITIALIZE_TO_ZERO 0x00

#define NUM_OF_OVERFLOWS 1000

#endif /* TIMER_H_ */