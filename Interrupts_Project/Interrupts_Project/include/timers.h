#ifndef TIMER_H_
#define TIMER_H_

#include "board_peripherals.h"
#include "ATMEGA32A.h"
#include "DIO.h"
#include "types.h"

  enum STATE CurrentState;
  uint8 StopFlag;


uint16 extern volatile Ticks;


extern volatile enum STATE{READY, STOP, GO};
 
void timer_init();

void timer_delay(uint32 n);

#define ONE 1

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

#define INITIAL_STATE 0
#define MAX_NUM_OF_STATES 2
#endif /* TIMER_H_ */