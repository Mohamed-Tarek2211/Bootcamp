
 #include "../include/timers.h"
 #include <avr/interrupt.h>
 
 uint16 volatile Ticks = 0;
 
 /*********************************************************************************
 *
 * Function: timer_init
 *
 * @param: void
 *		
 * @return: void
 *
 * Description: function initialize the timer using the interrupt
 *
 *
 ********************************************************************************/
void timer_init()
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
	//Set_Bit(TCCR0,PIN2);
	
	Set_Bit(TIMSK,PIN1);
	sei();
}

/*********************************************************************************
 *
 * Function: timer_delay
 *
 * @param:
 *		input : n, the number of milliseconds to delay ( halts the processor )
 * @return: void
 *
 * Description: function to create a delay
 *
 *
 ********************************************************************************/
void timer_delay(uint32 n)
{
	/* Reset Over Flow flag*/
	Set_Bit(TIFR,BIT1);
	/* Reset Timer count */
	TCNT0 = INITIALIZE_TO_ZERO;
	
	/* Each OF = 1ms */
	for(n ; n>0 ; n--)
	{
		while((TIFR & (PIN1<<ONE) == 0 ));
		TCCR0 = INITIALIZE_TO_ZERO;
		TIFR |= (PIN1<<1);

		Set_Bit(TCCR0,PIN0);
		Set_Bit(TCCR0,PIN1);
		Set_Bit(TCCR0,PIN2);	
	}
	
}

/*********************************************************************************
 *
 * Function: ISR_TIMER0_COMP_vect
 *
 * Description: The ISR of Timer0 interrupt
 *
 *
 ********************************************************************************/
ISR(TIMER0_COMP_vect)
{
Ticks++;
}

/*********************************************************************************
 *
 * Function: ISR_INT2_vect
 *
 * Description: The ISR of External INT2 interrupt
 *
 *
 ********************************************************************************/
ISR(INT2_vect){
	CurrentState = STOP;
	while (DIO_ReadPin(BTN1))
	{
		DIO_WritePin(LED1,LOW);
		DIO_WritePin(LED2,HIGH);
		DIO_WritePin(LED3,LOW);
	}
}