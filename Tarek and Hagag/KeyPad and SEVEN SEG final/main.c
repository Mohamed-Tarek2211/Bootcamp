#include "include/types.h"
#include "include/bitwise_operation.h"
#include "util/delay.h"
#include "include/DIO.h"
#include "include/board_peripherals.h"
#include "include/timers.h"
#include "include/7SEG.h"
#include "include/keypad.h"
#include "include/LCD.h"
#include "include/Questions.h"

# define F_CPU 16000000UL


int main(void)
{
	
	LCD_init();
	BTN_init();
	LCD_AllowSpecialCharacters();
	
	while(1){
		
		WelcomeMessage();
		GenerateQuestion();
		
		uint8 i = Again();
		
		if(i==0)
		break;
	}
	LCD_clear();
	LCD_gotoRowColumn(1,2);
	LCD_displayString("Thank You");
	DIO_WritePin(LCD_EN,LOW);
}
