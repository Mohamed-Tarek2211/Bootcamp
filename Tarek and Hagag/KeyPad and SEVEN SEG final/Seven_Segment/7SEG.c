
#include "../include/7SEG.h"
#include "../include/types.h"
#include "../include/DIO.h"
#include "../include/ATMEGA32A.h"

/*********************************************************************************
 *
 * Function: BCDSevegments_init
 *
 * @param: void
 * @return: void
 *
 * Description: function to go to initialize the pins of the seven segment display as output
 *
 *
 ********************************************************************************/
void BCDSevegments_init(void){
	
	DIO_SetPinDirection(SEG1_EN,OUTPUT);
	DIO_SetPinDirection(SEG2_EN,OUTPUT);
	DIO_SetPinDirection(SEG3_EN,OUTPUT);
	DIO_SetPinDirection(SEG4_EN,OUTPUT);

	DIO_SetPinDirection(SEVSEG_BCD_A,OUTPUT);
	DIO_SetPinDirection(SEVSEG_BCD_B,OUTPUT);
	DIO_SetPinDirection(SEVSEG_BCD_C,OUTPUT);
	DIO_SetPinDirection(SEVSEG_BCD_D,OUTPUT);

}


/*********************************************************************************
 *
 * Function: BCDSevegments_enable
 *
 * @param:
 *		input : Seven_Seg_No, The enable pin of the seven segment to be enabled
 * @return: void
 *
 * Description: function to go to enable a seven segment display
 *
 *
 ********************************************************************************/
void BCDSevegments_enable(uint8 Seven_Seg_No){
	
	DIO_WritePin(Seven_Seg_No,HIGH);
}


/*********************************************************************************
 *
 * Function: BCDSevegments_disable
 *
 * @param:
 *		input : Seven_Seg_No, The enable pin of the seven segment to be disabled
 * @return: void
 *
 * Description: function to go to disable a seven segment display
 *
 *
 ********************************************************************************/
void BCDSevegments_disable(uint8 Seven_Seg_No){
	
	DIO_WritePin(Seven_Seg_No,LOW);
	
}


/*********************************************************************************
 *
 * Function: BCDSevegments_displayNo
 *
 * @param:
 *		input : No, A digit to be printed on one seven segment display
 * @return: void
 *
 * Description: function to show a digit on a seven segment display
 *
 *
 ********************************************************************************/
void BCDSevegments_displayNo(uint8 No){
	
	DIO_WritePin(SEVSEG_BCD_A,(Get_Bit(No,BIT0) >> BIT0));
	DIO_WritePin(SEVSEG_BCD_B,(Get_Bit(No,BIT1) >> BIT1));
	DIO_WritePin(SEVSEG_BCD_C,(Get_Bit(No,BIT2) >> BIT2));
	DIO_WritePin(SEVSEG_BCD_D,(Get_Bit(No,BIT3) >> BIT3));	
}


/*********************************************************************************
 *
 * Function: BCDSevegments_displayNumbers
 *
 * @param:
 *		input : No, A 4 digit number to be printed on one seven segment display
 * @return: void
 *
 * Description: function to show a 4 digits number on a seven segment display
 *
 *
 ********************************************************************************/
void BCDSevegments_displayNumbers(uint8 No){

/*	
	uint8 n1,n2,n3,n4;
	n4 = No%10;
	n3 = (No/10)%10;
	n2 = (No/100)%10;
	n1 = (No/1000)%10;
*/
	BCDSevegments_enable(SEG4_EN);
	BCDSevegments_disable(SEG2_EN);
	BCDSevegments_disable(SEG3_EN);
	BCDSevegments_disable(SEG1_EN);
	
	BCDSevegments_displayNo((No/DECIMAL_BASEX100)%DECIMAL_BASE);
	_delay_ms(DELAY_MS_40);
	
	BCDSevegments_enable(SEG3_EN);
	BCDSevegments_disable(SEG1_EN);
	BCDSevegments_disable(SEG2_EN);
	BCDSevegments_disable(SEG4_EN);
		
	BCDSevegments_displayNo((No/DECIMAL_BASEX10)%DECIMAL_BASE);
	_delay_ms(DELAY_MS_40);

	BCDSevegments_enable(SEG2_EN);
	BCDSevegments_disable(SEG3_EN);
	BCDSevegments_disable(SEG1_EN);
	BCDSevegments_disable(SEG4_EN);
	
	BCDSevegments_displayNo((No/DECIMAL_BASE)%DECIMAL_BASE);
	_delay_ms(DELAY_MS_40);

	BCDSevegments_enable(SEG1_EN);
	BCDSevegments_disable(SEG2_EN);
	BCDSevegments_disable(SEG3_EN);
	BCDSevegments_disable(SEG4_EN);
	
	BCDSevegments_displayNo(No%DECIMAL_BASE);
	_delay_ms(DELAY_MS_40);


}



