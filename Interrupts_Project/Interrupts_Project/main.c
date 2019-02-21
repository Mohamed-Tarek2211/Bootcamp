/*
 * Interrupts_Project.c
 *
 * Created: 2/20/2019 6:36:49 PM
 * Author : AVE-LAP-052
 */ 

#include "include/board_peripherals.h"
#include "include/DIO.h"
#include "include/timers.h"
#include "include/types.h"
#include <avr/interrupt.h>

  
int main(void)
{
	timer_init();
	DIO_SetPinDirection(LED1,OUTPUT);
	DIO_SetPinDirection(LED2,OUTPUT);	
	DIO_SetPinDirection(LED3,OUTPUT);	
	DIO_SetPinDirection(BTN1,INPUT);
	CurrentState = INITIAL_STATE;
	
	Set_Bit(GICR,INT2);
	Set_Bit(MCUCSR,ISC2);
	while(1){
		
	if (Ticks >= NUM_OF_OVERFLOWS)
	{
		Ticks = INITIAL_STATE;
		CurrentState++;	
	}
	if (CurrentState > MAX_NUM_OF_STATES)
	{
		CurrentState = INITIAL_STATE;
	}
	else if (CurrentState < INITIAL_STATE)
	{
		CurrentState = MAX_NUM_OF_STATES;
	}

switch (CurrentState)
{
case READY :   /*READY*/
	DIO_WritePin(LED1,HIGH);
	DIO_WritePin(LED2,LOW);
	DIO_WritePin(LED3,LOW);
	break;
case STOP :	/*STOP*/
	DIO_WritePin(LED1,LOW);
	DIO_WritePin(LED2,HIGH);
	DIO_WritePin(LED3,LOW);	
	break;
case GO :	/*GO*/
	DIO_WritePin(LED1,LOW);
	DIO_WritePin(LED2,LOW);
	DIO_WritePin(LED3,HIGH);
	break;
}
}
}
