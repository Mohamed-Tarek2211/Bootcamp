//#include <avr/io.h>
#include "types.h"
#include "bitwise_operation.h"
#include "util/delay.h"
#include "DIO.h"
#include "board_peripherals.h"
#include "timers.h"

#define FCPU 16000000
#define GO 0
#define STOP 1
#define READY 2
/*
struct State {
	uint8 GO;
	uint8 STOP;
	uint8 READY;
	}State;
*/
uint8 state;
int main(void)
{
	state = GO;
	DIO_SetPinDirection(LED3,OUTPUT);
	DIO_SetPinDirection(LED2,OUTPUT);
	DIO_SetPinDirection(LED1,OUTPUT);
	DIO_SetPinDirection(BTN1,INPUT);
timer_init();
		DIO_WritePin(LED1,HIGH);
		timer_delay(1000);
		DIO_WritePin(LED1,LOW);
		timer_delay(1000);
		
		
	 	(*(volatile uint8*)(0x53)) = 0x0B;
		(*(volatile uint8*)(0x52)) = 0x00;
		(*(volatile uint8*)(0x5C)) = 250;
		
		

	while(1){
			
			switch (state)
			{	
			case GO:
			DIO_WritePin(LED1,HIGH);
			timer_delay(500);
			state = STOP;
			DIO_WritePin(LED1,LOW);
			if (BTN1 == HIGH)
			{	
				state = STOP;
			}
			break;
			
			case STOP:
			DIO_WritePin(LED2,HIGH);
			while(BTN1 == HIGH);
			timer_delay(500);
			state = READY;
			DIO_WritePin(LED2,LOW);			
			if (BTN1 == HIGH)
			{
				state = STOP;
			}
			break;
			
			case READY:
			DIO_WritePin(LED3,HIGH);
			timer_delay(500);
			state = GO;
			DIO_WritePin(LED3,LOW);
			if (BTN1 == HIGH)
			{
				state = STOP;
			}
			break;
			}
		
		}

}

