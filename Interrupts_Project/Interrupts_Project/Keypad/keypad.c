/*
 * keypad.c
 *
 * Created: 2/18/2019 2:55:05 PM
 *  Author: AVE-LAP-052
 */ 
#include "../include/keypad.h"
#include "../include/types.h"
#include "../include/board_peripherals.h"
#include "../include/ATMEGA32A.h"


/*********************************************************************************
 *
 * Function: keypad_init
 *
 * @param: void 
 * @return: void
 *
 * Description: function to initialize the keypad pins and enable all the pull up resistors
 *
 *
 ********************************************************************************/
void keypad_init(){
	
		DIO_SetPinDirection(KEYPAD_C1,OUTPUT);
		DIO_SetPinDirection(KEYPAD_C2,OUTPUT);
		DIO_SetPinDirection(KEYPAD_C3,OUTPUT);
		DIO_WritePin(KEYPAD_C1,HIGH);
		DIO_WritePin(KEYPAD_C2,HIGH);
		DIO_WritePin(KEYPAD_C3,HIGH);

		DIO_SetPinDirection(KEYPAD_R1,INPUT);
		DIO_SetPinDirection(KEYPAD_R2,INPUT);
		DIO_SetPinDirection(KEYPAD_R3,INPUT);	
		DIO_WritePin(KEYPAD_R3,HIGH);
		DIO_WritePin(KEYPAD_R2,HIGH);
		DIO_WritePin(KEYPAD_R1,HIGH);
}


/*********************************************************************************
 *
 * Function: Get_Pressed_Key
 *
 * @param: void 
 * @return: 
 *		RES, the number pressed on by the keypad
 *
 * Description: function to show return the pressed key on a keypad
 *
 *
 ********************************************************************************/
uint8 Get_Pressed_Key(void){
uint8 RES;

	for(uint8 i = 0 ; i <KEYPAD_COL ; i++){
		keypad_init();
		DIO_WritePin(i+KEYPAD_C1,LOW);
			for (uint8 j = 0; j< KEYPAD_ROWS;j++)
			{
				if(!DIO_ReadPin(j+KEYPAD_R1)){
					 RES = ((j*KEYPAD_COL)+i+1);
					return RES;
				}	
			}
	}
return 0;

}