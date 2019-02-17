#ifndef BITWISE_OPERATIONS_H
#define BITWISE_OPERATIONS_H

#include "types.h"

/*********************************************/
/*********BITWISE MACROS FOR DIO *************/ 
/*********************************************/

#define Set_Bit(Register,Bit)	(Register |= (1<<(uint8)Bit)) 
#define Clear_Bit(Register,Bit)	(Register &= ~(1<<(uint8)Bit))
#define Get_Bit(Register,Bit)	((Register) & (1<<(uint8)Bit))
#define Toggle_Bit(Register,Bit) (Register ^= (1<<(uint8)Bit))

#endif