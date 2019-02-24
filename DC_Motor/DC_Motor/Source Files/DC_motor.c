#include "../include/DCmotor.h "
#include "util/delay.h"



void DC_Motor_Init(uint8 MotorEnablePin,uint8 MotorDirPinA,uint8 MotorDirPinB)
{
	DIO_SetPinDirection(MotorEnablePin,OUTPUT);
	DIO_SetPinDirection(MotorDirPinA,OUTPUT);
	DIO_SetPinDirection(MotorDirPinB,OUTPUT);
	
}

void DC_MotorMove(uint8 MotorEnablePin,uint8 DIR_A,uint8 DIR_B, uint8 Dir)
{
	switch (Dir)
	{
		case FORWARD:
			if (DIO_ReadPin(DIR_A) == LOW && DIO_ReadPin(DIR_B) == HIGH )
			{
				DIO_WritePin(DIR_B,LOW);
				_delay_ms(100);
			}
		DIO_WritePin(DIR_A,HIGH);
		DIO_WritePin(DIR_B,LOW);
	//	DIO_WritePin(MotorEnablePin,HIGH);
		break;
		case BACKWARD:
			if (DIO_ReadPin(DIR_B) == LOW && DIO_ReadPin(DIR_A) == HIGH )
			{
				DIO_WritePin(DIR_A,LOW);
				_delay_ms(100);
			}
		DIO_WritePin(DIR_B,HIGH);
		DIO_WritePin(DIR_A,LOW);
	//	DIO_WritePin(MotorEnablePin,HIGH);
		break;
		case STOP:	
		DIO_WritePin(MotorEnablePin,LOW);
		break;
	} 
	
}
