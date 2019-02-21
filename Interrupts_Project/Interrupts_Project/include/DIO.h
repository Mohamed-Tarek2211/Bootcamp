#ifndef DIO_H
#define DIO_H

#include "ATMEGA32A.h"
#include "types.h"
#include "bitwise_operation.h"

#define OUTPUT 1
#define INPUT 0

#define HIGH 1
#define LOW 0

#define SEVEN_AS_PORT1_MAX 7
#define FIFTEEN_AS_PORT2_MAX 15
#define TWENTY_THREE_AS_PORT3_MAX 23
#define THIRTY_ONE_AS_PORT3_MAX 31

#define PORT1_MAX 8
#define PORT2_MAX 16
#define PORT3_MAX 24


#define ZERO 0
 
void DIO_WritePin(uint8 PinNum,uint8 PinValue);
uint8 DIO_ReadPin(uint8 PinNum);
void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection);


#endif