#ifndef ATMEGA_32A_H
#define ATMEGA_32A_H

#include "types.h"

/********************************************/
/***************GPIO REGISTERS***************/ 
/********************************************/

#define PortA (*(volatile uint8*)(0x3B))
#define PortB (*(volatile uint8*)(0x38))
#define PortC (*(volatile uint8*)(0x35))
#define PortD (*(volatile uint8*)(0x32))

#define DDRA  (*(volatile uint8*)(0x3A))
#define DDRB  (*(volatile uint8*)(0x37))
#define DDRC  (*(volatile uint8*)(0x34))
#define DDRD  (*(volatile uint8*)(0x31))
	 
#define PINA  (*(volatile uint8*)(0x39))
#define PINB  (*(volatile uint8*)(0x36))
#define PINC  (*(volatile uint8*)(0x33))
#define PIND  (*(volatile uint8*)(0x30))


/********************************************/
/**************TIMER 0 REGISTERS*************/
/********************************************/


#define TCCR0	(*(volatile uint8*)(0x53))
#define TCNT0	(*(volatile uint8*)(0x52))
#define OCR0	(*(volatile uint8*)(0x5C))
#define TIMSK	(*(volatile uint8*)(0x59))
#define TIFR	(*(volatile uint8*)(0x58))
#define TWCR	(*(volatile uint8*)(0x56))




#endif
