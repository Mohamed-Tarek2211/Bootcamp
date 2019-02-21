#include"../include/LCD.h"

/*********************************************************************************
 *
 * Function: LCD_init
 *
 * @param: void
 * @return: void
 *
 * Description: function to initialize the pins of the LCD as output and gives the LCD
 * its initial commands
 *
 ********************************************************************************/
void LCD_init(){
	
	DIO_SetPinDirection(LCD_RS,OUTPUT);
	DIO_SetPinDirection(LCD_RW,OUTPUT);
	DIO_SetPinDirection(LCD_EN,OUTPUT);	
	DIO_SetPinDirection(LCD_D4,OUTPUT);
	DIO_SetPinDirection(LCD_D5,OUTPUT);
	DIO_SetPinDirection(LCD_D6,OUTPUT);
	DIO_SetPinDirection(LCD_D7,OUTPUT);


LCD_sendCommand(CMD_LCD4BIT33);
_delay_ms(TWO_MS);
LCD_sendCommand(CMD_LCD4BIT32);
_delay_ms(TWO_MS);
LCD_sendCommand(CMD_LCD_2_LINES_5X7);
_delay_ms(TWO_MS);
LCD_sendCommand(CMD_CURSOR_ON);
_delay_ms(TWO_MS);
LCD_sendCommand(CMD_RESET);
_delay_ms(TWO_MS);
LCD_sendCommand(CMD_SHIFT_DISPLAY_LEFT);
}

/*********************************************************************************
 *
 * Function: LCD_sendCommand
 *
 * @param: 
		input : cmd , the command given to the LCD 
 * @return: void
 *
 * Description: function to send commands to the LCD
 *
 *
 ********************************************************************************/
void LCD_sendCommand(uint8 cmd){

/*    Write The MOST significant bits of the command in the 4 bits of the LCD	*/
DIO_WritePin(LCD_D4,(Get_Bit(cmd,BIT4) >> BIT4));    
DIO_WritePin(LCD_D5,(Get_Bit(cmd,BIT5) >> BIT5));
DIO_WritePin(LCD_D6,(Get_Bit(cmd,BIT6) >> BIT6));
DIO_WritePin(LCD_D7,(Get_Bit(cmd,BIT7) >> BIT7));

DIO_WritePin(LCD_RS,LOW);
DIO_WritePin(LCD_RW,LOW);
DIO_WritePin(LCD_EN,HIGH);
_delay_ms(TWO_MS);
DIO_WritePin(LCD_EN,LOW);
_delay_ms(TWO_MS);

/*    Write The LEAST significant bits of the command in the 4 bits of the LCD	*/
DIO_WritePin(LCD_D4,(Get_Bit(cmd,BIT0) >> BIT0));
DIO_WritePin(LCD_D5,(Get_Bit(cmd,BIT1) >> BIT1));
DIO_WritePin(LCD_D6,(Get_Bit(cmd,BIT2) >> BIT2));
DIO_WritePin(LCD_D7,(Get_Bit(cmd,BIT3) >> BIT3));


DIO_WritePin(LCD_EN,HIGH);	
_delay_ms(TWO_MS);
DIO_WritePin(LCD_EN,LOW);
}


/*********************************************************************************
 *
 * Function: LCD_displayChar
 *
 * @param: 
		input : c , the character given to the LCD 
 * @return: void
 *
 * Description: function to print a character on the LCD
 *
 *
 ********************************************************************************/
void LCD_displayChar(uint8 c){
	
/*    Write The MOST significant bits of the command in the 4 bits of the LCD	*/

DIO_WritePin(LCD_D4,(Get_Bit(c,BIT4) >> BIT4));
DIO_WritePin(LCD_D5,(Get_Bit(c,BIT5) >> BIT5));
DIO_WritePin(LCD_D6,(Get_Bit(c,BIT6) >> BIT6));
DIO_WritePin(LCD_D7,(Get_Bit(c,BIT7) >> BIT7));

DIO_WritePin(LCD_RS,HIGH);
DIO_WritePin(LCD_RW,LOW);
DIO_WritePin(LCD_EN,HIGH);
_delay_ms(TWO_MS);
DIO_WritePin(LCD_EN,LOW);
_delay_ms(TWO_MS);

/*    Write The LEAST significant bits of the command in the 4 bits of the LCD	*/

DIO_WritePin(LCD_D4,(Get_Bit(c,BIT0) >> BIT0));
DIO_WritePin(LCD_D5,(Get_Bit(c,BIT1) >> BIT1));
DIO_WritePin(LCD_D6,(Get_Bit(c,BIT2) >> BIT2));
DIO_WritePin(LCD_D7,(Get_Bit(c,BIT3) >> BIT3));


DIO_WritePin(LCD_EN,HIGH);
_delay_ms(TWO_MS);
DIO_WritePin(LCD_EN,LOW);	
}	

/*********************************************************************************
 *
 * Function: LCD_displayString
 *
 * @param: 
		input : *kalam , the string to be printed on the LCD 
 * @return: void
 *
 * Description: function to write a string on the LCD
 *
 *
 ********************************************************************************/
void LCD_displayString(uint8* kalam){
while(*kalam != (NULL_CHARACTER)){
LCD_displayChar(*kalam);
*kalam++;
}
}

/*********************************************************************************
 *
 * Function: LCD_gotoRowColumn
 *
 * @param: 
		input : ROW , the row needed to start typing on
		input : COL , the column needed to start typing on 
 * @return: void
 *
 * Description: function to go to a certain cell in the LCD by addressing it through rows and columns
 *
 *
 ********************************************************************************/
void LCD_gotoRowColumn(uint8 ROW, uint8 COL){
	
	if(ROW == FIRST_ROW)
	{
		LCD_sendCommand(CMD_CURSOR_TO_LINE1);
		for (uint8 i = 0; i<COL;i++)
		{
			LCD_sendCommand(CMD_SHIFT_CURSOR_RIGHT);
		}
	}
	if(ROW == SECOND_ROW){
		LCD_sendCommand(CMD_CURSOR_TO_LINE2);
		for (uint8 i = 0; i<COL;i++)
		{
		LCD_sendCommand(CMD_SHIFT_CURSOR_RIGHT);
		}
	}	
	
}


/*********************************************************************************
 *
 * Function: LCD_displayStringRowColumn
 *
 * @param: 
		input : ROW , the row needed to start typing on
		input : COL , the column needed to start typing on
		input : *kalam , string to be written starting from the given cell through row and column 
 * @return: void
 *
 * Description: function to go to a certain cell in the LCD by addressing it through rows and columns and print a string starting
 *	from that cell
 *
 ********************************************************************************/
void LCD_displayStringRowColumn(uint8 ROW, uint8 COL, uint8* kalam){
	
	LCD_gotoRowColumn(ROW,COL);
	while(*kalam != (NULL_CHARACTER)){
		LCD_displayChar(*kalam);
		*kalam++;
	}
}


/*********************************************************************************
 *
 * Function: LCD_clear
 *
 * @param: void 
		
 * @return: void
 *
 * Description: function to clear the lcd display
 *
 ********************************************************************************/
void LCD_clear(){
	LCD_sendCommand(CMD_RESET);
	_delay_ms(TWO_MS);
}

/*********************************************************************************
 *
 * Function: LCD_AllowSpecialCharacters
 *
 * @param: void
 * @return: void
 *
 * Description: function that writes special characters to to LCD CGRAM
 *
 ********************************************************************************/
void LCD_AllowSpecialCharacters(){
	
	uint8 SadEmoji[8] = {0, 0, 27, 0, 0, 31, 17, 17};
	uint8 HappyEmoji[8]={0, 0, 27, 0, 0, 17, 31, 0};
	uint8 Left_Heart[8]={0, 6, 15, 31, 30, 28, 24, 16};
	uint8 Right_Heart[8]={0, 12, 30, 31, 15, 7, 3, 1};
	
	LCD_sendCommand(CMD_FIRST_ALLOWED_ADDRESS_IN_CGRAM);
	
	for(uint8 i=0 ; i<BYTE_minus1 ;i++)
	{
	LCD_displayChar(SadEmoji[i]);
	}
	
	for(uint8 i=0 ; i<BYTE_minus1 ;i++)
	{
	LCD_displayChar(HappyEmoji[i]);
	}

	for(uint8 i=0 ; i<BYTE_minus1 ;i++)
	{
		LCD_displayChar(Left_Heart[i]);
	}
	for(uint8 i=0 ; i<BYTE_minus1 ;i++)
	{
		LCD_displayChar(Right_Heart[i]);
	}
	LCD_sendCommand(CMD_END_ALLOWED_ADDRESS_IN_CGRAM);
}