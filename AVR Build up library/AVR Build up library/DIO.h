#ifndef DIO_H
#define DIO_H

#include "ATMEGA32A.h"
#include "types.h"
#include "bitwise_operation.h"

#define OUTPUT 1
#define INPUT 0

#define HIGH 1
#define LOW 0
 
void DIO_WritePin(uint8 PinNum,uint8 PinValue);
uint8 DIO_ReadPin(uint8 PinNum);
void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection);


#endif