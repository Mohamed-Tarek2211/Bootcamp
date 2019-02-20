 
#include "../include/timers.h"

void timer_init()
{
	/* CTC Mode */
	Set_Bit(TCCR0,PIN3);
	Clear_Bit(TCCR0,PIN6);
	
	
	/* Clear TCNT0 & OCR0 */
	TCNT0 = INITIALIZE_TO_ZERO ;
	OCR0 = START_COUNT_FROM_250 ;
	
	/* 64 Prescaler */
	Set_Bit(TCCR0,PIN0);
	Set_Bit(TCCR0,PIN1);
	Clear_Bit(TCCR0,PIN2);
}

void timer_delay(uint32 n)
{
	
	/* Reset Over Flow flag*/
	Set_Bit(TIFR,PIN0);
	/* Reset Timer count */
	TCNT0 = INITIALIZE_TO_ZERO;
	
	/* Each OF = 1ms */
	for(n ; n>0 ; n--)
	{
		while(!(TIFR & (PIN1<<1) ));
		TIFR |= (PIN1<<1);
	}
	
}