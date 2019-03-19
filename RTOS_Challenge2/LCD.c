#include "LCD.h"
#include "FreeRTOS.h"
#include "task.h"

#if 0
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
	/*
	DIO_SetPinDirection(LCD_RS,OUTPUT);
	DIO_SetPinDirection(LCD_RW,OUTPUT);
	DIO_SetPinDirection(LCD_EN,OUTPUT);	
	DIO_SetPinDirection(LCD_D4,OUTPUT);
	DIO_SetPinDirection(LCD_D5,OUTPUT);
	DIO_SetPinDirection(LCD_D6,OUTPUT);
	DIO_SetPinDirection(LCD_D7,OUTPUT);
*/
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA));
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOC));

    GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE,GPIO_PIN_2 |GPIO_PIN_3|GPIO_PIN_4);
    GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE,GPIO_PIN_4 |GPIO_PIN_5|GPIO_PIN_6 | GPIO_PIN_7);



LCD_sendCommand(CMD_LCD4BIT33);
vTaskDelay(2);
//SysCtlDelay(2*16000);
LCD_sendCommand(CMD_LCD4BIT32);
vTaskDelay(2);
LCD_sendCommand(CMD_LCD_2_LINES_5X7);
vTaskDelay(2);
LCD_sendCommand(CMD_CURSOR_ON);
vTaskDelay(2);
LCD_sendCommand(CMD_RESET);
vTaskDelay(2);
LCD_sendCommand(CMD_SHIFT_DISPLAY_LEFT);
vTaskDelay(2);
LCD_sendCommand(0x80);
}

#endif
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
void LCD_sendCommand(uint8_t cmd){

/*    Write The MOST significant bits of the command in the 4 bits of the LCD	*/


GPIOPinWrite(GPIO_PORTC_BASE,LCD_D4, (Get_Bit(cmd,BIT4) ));

GPIOPinWrite(GPIO_PORTC_BASE,LCD_D5, (Get_Bit(cmd,BIT5) ));

GPIOPinWrite(GPIO_PORTC_BASE,LCD_D6, (Get_Bit(cmd,BIT6) ));

GPIOPinWrite(GPIO_PORTC_BASE,LCD_D7, (Get_Bit(cmd,BIT7) ));


GPIOPinWrite(GPIO_PORTA_BASE , LCD_RS | LCD_RW | LCD_EN , LOW | LOW | LCD_EN);
vTaskDelay(TWO_MS);
GPIOPinWrite(GPIO_PORTA_BASE , LCD_EN , LOW);
vTaskDelay(TWO_MS);

/*    Write The LEAST significant bits of the command in the 4 bits of the LCD	*/

GPIOPinWrite(GPIO_PORTC_BASE,LCD_D4, (Get_Bit(cmd,BIT0) << SHIFT_UPPER_BITS ));

GPIOPinWrite(GPIO_PORTC_BASE,LCD_D5, (Get_Bit(cmd,BIT1)  << SHIFT_UPPER_BITS ));

GPIOPinWrite(GPIO_PORTC_BASE,LCD_D6, (Get_Bit(cmd,BIT2)  << SHIFT_UPPER_BITS ));

GPIOPinWrite(GPIO_PORTC_BASE,LCD_D7, (Get_Bit(cmd,BIT3)  << SHIFT_UPPER_BITS ));

GPIOPinWrite(GPIO_PORTA_BASE,LCD_EN ,LCD_EN);
vTaskDelay(5); /*WAS 5 */
GPIOPinWrite(GPIO_PORTA_BASE,LCD_EN ,LOW);
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
void LCD_displayChar(uint8_t c){
	
/*    Write The MOST significant bits of the command in the 4 bits of the LCD	*/

    //DIO_WritePin(LCD_D4,(Get_Bit(cmd,BIT4) >> BIT4));
    GPIOPinWrite(GPIO_PORTC_BASE,LCD_D4, (Get_Bit(c,BIT4)));
    //DIO_WritePin(LCD_D5,(Get_Bit(cmd,BIT5) >> BIT5));
    GPIOPinWrite(GPIO_PORTC_BASE,LCD_D5, (Get_Bit(c,BIT5)));
    //DIO_WritePin(LCD_D6,(Get_Bit(cmd,BIT6) >> BIT6));
    GPIOPinWrite(GPIO_PORTC_BASE,LCD_D6, (Get_Bit(c,BIT6)));
    //DIO_WritePin(LCD_D7,(Get_Bit(cmd,BIT7) >> BIT7));
    GPIOPinWrite(GPIO_PORTC_BASE,LCD_D7, (Get_Bit(c,BIT7)));

    GPIOPinWrite(GPIO_PORTA_BASE,LCD_RS | LCD_RW |LCD_EN ,LCD_RS| LOW | LCD_EN);
//DIO_WritePin(LCD_RS,HIGH);
//DIO_WritePin(LCD_RW,LOW);
//DIO_WritePin(LCD_EN,HIGH);
    vTaskDelay(TWO_MS);
    GPIOPinWrite(GPIO_PORTA_BASE,LCD_EN ,LOW);
//DIO_WritePin(LCD_EN,LOW);
    vTaskDelay(TWO_MS);

/*    Write The LEAST significant bits of the command in the 4 bits of the LCD	*/

GPIOPinWrite(GPIO_PORTC_BASE,LCD_D4, (Get_Bit(c,BIT0) << SHIFT_UPPER_BITS ));
//DIO_WritePin(LCD_D5,(Get_Bit(cmd,BIT5) >> BIT5));
GPIOPinWrite(GPIO_PORTC_BASE,LCD_D5, (Get_Bit(c,BIT1)  << SHIFT_UPPER_BITS ));
//DIO_WritePin(LCD_D6,(Get_Bit(cmd,BIT6) >> BIT6));
GPIOPinWrite(GPIO_PORTC_BASE,LCD_D6, (Get_Bit(c,BIT2)  << SHIFT_UPPER_BITS ));
//DIO_WritePin(LCD_D7,(Get_Bit(cmd,BIT7) >> BIT7));
GPIOPinWrite(GPIO_PORTC_BASE,LCD_D7, (Get_Bit(c,BIT3)  << SHIFT_UPPER_BITS ));



GPIOPinWrite(GPIO_PORTA_BASE,LCD_RS | LCD_RW |LCD_EN ,LCD_RS | LOW | LCD_EN);
vTaskDelay(TWO_MS);
    GPIOPinWrite(GPIO_PORTA_BASE,LCD_EN ,LOW);
}	

void LCD_clear(){
    LCD_sendCommand(CMD_RESET);
}

void LCD_displayString(uint8_t* kalam)
{
    while(*kalam != (NULL_CHARACTER))
    {
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
void LCD_gotoRowColumn(uint8_t ROW, uint8_t COL){
    uint8_t i;
    if(ROW == FIRST_ROW)
    {
        LCD_sendCommand(CMD_CURSOR_TO_LINE1);
        for ( i = LOW; i<COL;i++)
        {
            LCD_sendCommand(CMD_SHIFT_CURSOR_RIGHT);
        }
    }
    if(ROW == SECOND_ROW){
        LCD_sendCommand(CMD_CURSOR_TO_LINE2);
        for (i = LOW; i<COL;i++)
        {
        LCD_sendCommand(CMD_SHIFT_CURSOR_RIGHT);
        }
    }

}





