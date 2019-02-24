 #include "../include/timers.h"
 #include <avr/interrupt.h>
 
uint16 volatile Ticks = 0;

void timer0_init()
{
	/* CTC Mode */
	Set_Bit(TCCR0,PIN3);
	Clear_Bit(TCCR0,PIN6);
	
	/* Clear TCNT0 & OCR0 */
	TCNT0 = INITIALIZE_TO_ZERO ;
	OCR0 = START_COUNT_FROM_124 ;
	
	/* 64 Prescaler */
	Set_Bit(TCCR0,PIN0);
	Set_Bit(TCCR0,PIN1);
	Set_Bit(TCCR0,PIN2);
}

void timer0_delay(uint32 n)
{
	/* Reset Over Flow flag*/
	Set_Bit(TIFR,BIT1);
	/* Reset Timer count */
	TCNT0 = INITIALIZE_TO_ZERO;
	
	/* Each OF = 1ms */
	for(n ; n>0 ; n--)
	{
		while((TIFR & (PIN1<<1) == 0 ));
		TCCR0 = INITIALIZE_TO_ZERO;
		TIFR |= (PIN1<<1);

		Set_Bit(TCCR0,PIN0);
		Set_Bit(TCCR0,PIN1);
		Set_Bit(TCCR0,PIN2);	
	}
	
}

ISR(TIMER0_COMP_vect)
{
Ticks++;

if (Ticks == NUM_OF_OVERFLOWS)
{
	Ticks = 0;	
}

}