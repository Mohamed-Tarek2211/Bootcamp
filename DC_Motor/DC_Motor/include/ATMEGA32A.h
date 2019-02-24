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


/************************************************************************/
/* Mapping Timer0 Registers                                             */
/************************************************************************/
#define TCCR0			(*(volatile uint8 *)(0x53))
#define TCNT0			(*(volatile uint8 *)(0x52))
#define OCR0			(*(volatile uint8 *)(0x5C))
#define TIMSK			(*(volatile uint8 *)(0x59))
#define TIFR			(*(volatile uint8 *)(0x58))
#define TWCR			(*(volatile uint8 *)(0x56))

/************************************************************************/
/* TCCR0 Bits                                                           */
/************************************************************************/
#define CS00			0
#define CS01			1
#define CS02			2
#define	WGM01			3
#define COM00			4
#define COM01			5
#define WGM00			6
#define FOC0			7

/************************************************************************/
/* TIMSK Bits                                                           */
/************************************************************************/

#define TOIE0			0
#define	OCIE0			1
#define TOIE1			2
#define OCIE1B			3
#define OCIE1A			4
#define TICIE1			5
#define TOIE2			6
#define OCIE2			7


/************************************************************************/
/* TIFR Bits                                                            */
/************************************************************************/
#define TOV0			0
#define OCF0			1
#define	TOV1			2
#define OCF1B			3
#define OCF1A			4
#define ICF1			5
#define	TOV2			6
#define OCF2			7



/************************************************************************/
/* Mapping Timer1 Registers                                             */
/************************************************************************/
#define TCCR1A			(*(volatile uint8 *)(0x4F))
#define TCCR1B			(*(volatile uint8 *)(0x4E))
#define TCNT1H			(*(volatile uint8 *)(0x4D))
#define TCNT1L			(*(volatile uint8 *)(0x4C))
#define OCR1AH			(*(volatile uint8 *)(0x4B))
#define OCR1AL			(*(volatile uint8 *)(0x4A))
#define OCR1BH			(*(volatile uint8 *)(0x49))
#define OCR1BL			(*(volatile uint8 *)(0x48))

#define ICR1H			(*(volatile uint8 *)(0x47))
#define ICR1L			(*(volatile uint8 *)(0x46))

/************************************************************************/
/* TCCR1A Bits                                                          */
/************************************************************************/
#define WGM10			0
#define WGM11			1
#define FOC1B			2
#define	FOC1A			3
#define COM1B0			4
#define COM1B1			5
#define COM1A0			6
#define COM1A1			7


/************************************************************************/
/* TCCR1B Bits                                                          */
/************************************************************************/
#define CS10			0
#define CS11			1
#define CS12			2
#define	WGM12			3
#define WGM13			4
#define ICES1			6
#define ICNC1			7





#endif
