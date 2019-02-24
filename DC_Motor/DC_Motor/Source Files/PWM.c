#include "../include/PWM.h"


void PWM_init(float DutyCycle)
{
	 uint16 Comp_Val;
	
	
	/* Turn off the Timer */
	//TCCR1A  = INITIALIZE_TO_ZERO; 
	
	/*	Set the starting value to zero	*/
	TCNT1H = INITIALIZE_TO_ZERO;
	TCNT1L = INITIALIZE_TO_ZERO;

	
	
	/*	Set the TOP value 	*/
	ICR1H = (TOP_VALUE>>ONEBYTE);		
	ICR1L = TOP_VALUE;
	
	/*OCR1BH = (COMPARE_VALUE>>ONEBYTE);
	OCR1BL = COMPARE_VALUE;

*/	
	// Set on match, clear on TOP
	TCCR1A  |= (HIGH << COM1A1) | (HIGH << COM1A0);
	TCCR1A  |= ((HIGH << COM1B0)  | (HIGH << COM1B1));
	TCCR1A  &= ~((HIGH << FOC1A)  | (HIGH << FOC1B));
	TCCR1A  |= (HIGH << WGM11);
	TCCR1A  &= ~(HIGH << WGM10);
	
	TCCR1B  &= ~(HIGH << WGM12);
	TCCR1B  |= ((HIGH << CS10) | (HIGH << WGM13));
	
	Comp_Val = TOP_VALUE - (uint16)( (DutyCycle/100)*TOP_VALUE );
	
	/*	Set the compare value 	*/
	OCR1AH = (Comp_Val>>ONEBYTE);
	OCR1AL = Comp_Val;
}