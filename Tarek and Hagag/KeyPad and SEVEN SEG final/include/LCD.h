#ifndef LCD_H_
#define LCD_H_

#include "LCD_cfg.h"
#include "DIO.h"
#include "util/delay.h"
#include "types.h"


void LCD_init(void);
void LCD_sendCommand(uint8 cmd);
void LCD_displayChar(uint8 c);
void LCD_displayString(uint8* kalam);
void LCD_displayStringRowColumn(uint8 ROW, uint8 COL, uint8* kalam);
void LCD_clear();
void LCD_gotoRowColumn(uint8 ROW,uint8 COL);
void LCD_AllowSpecialCharacters(void);

#define BYTE 8
#define BYTE_minus1 7
#define BIT0 0
#define BIT1 1
#define BIT2 2
#define BIT3 3
#define BIT4 4
#define BIT5 5
#define BIT6 6
#define BIT7 7


#define NUMBER4_ToShiftToUpperBits 4


#endif /* LCD_H_ */