#ifndef PWM_H_
#define PWM_H_

#include "ATMEGA32A.h"
#include "util/delay.h"

void PWM_init(float DutyCycle);

#define COMPARE_VALUE 3000
#define TOP_VALUE 4000

#define INITIALIZE_TO_ZERO 0x00
#define ONEBYTE 8

#define HIGH 1

#endif /* PWM_H_ */