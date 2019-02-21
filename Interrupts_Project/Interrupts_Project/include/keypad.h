/*
 * keypad.h
 *
 * Created: 2/18/2019 2:54:46 PM
 *  Author: AVE-LAP-052
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "board_peripherals.h"
#include "DIO.h"
#include "ATMEGA32A.h"


#define KEYPAD_PORT PortC

void keypad_init(void);
uint8 Get_Pressed_Key(void);	


#endif /* KEYPAD_H_ */