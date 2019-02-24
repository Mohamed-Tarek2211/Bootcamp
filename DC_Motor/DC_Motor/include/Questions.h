#ifndef QUESTIONS_H_
#define QUESTIONS_H_

#include "types.h"
#include "bitwise_operation.h"
#include "DIO.h"
#include "board_peripherals.h"
#include "LCD.h"

void BTN_init(void);
void GenerateQuestion(void);
void WelcomeMessage(void);
void LED_Correct_Celebration(void);
void End_Questions(void);
uint8 Again(void);

#define PRESSED 1
#define NOTPRESSED 0

#define ROW1 1
#define ROW2 2

#define COL0 0
#define COL1 1
#define COL2 2
#define COL3 3
#define COL4 4


#define CORRECT 1
#define WRONG 0

#define NO 0
#define YES 1

#define ASCII_OF_ZERO  48
#define NUM_OF_QUES 5

#define TWENTY_MS 20
#define FOUR_SECONDS 4000
#define TWO_SECONDS 2000
#define HALF_SECOND 1000

#define SAD_EMOJI 0
#define HAPPY_EMOJI 1
#define LEFT_HEART 2
#define RIGHT_HEART 3
 
#endif /* QUESTIONS_H_ */