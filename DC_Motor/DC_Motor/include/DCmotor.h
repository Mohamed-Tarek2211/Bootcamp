#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#include "DIO.h"
#include "board_peripherals.h"

#define FORWARD 1
#define BACKWARD 2
#define STOP 0

void DC_MotorInit(uint8 MotorEnablePin,uint8 MotorDirPinA,uint8 MotorDirPinB);
void DC_MotorMove(uint8 MotorEnablePin,uint8 DIR_A,uint8 DIR_B, uint8 Dir);
void DC_SetMotorDirection(uint8 Dir, uint8 DIR_A,uint8 DIR_B);


#endif /* DCMOTOR_H_ */