#include "DIO.h"

void DIO_WritePin(uint8 PinNum,uint8 PinValue){
	if(PinValue == 0)
	{
		if (PinNum <= 7)
		{
			Clear_Bit(PortA,PinNum);		
		}
		else if ((PinNum > 7) && (PinNum <= 15) )
		{
			Clear_Bit(PortB,(PinNum-8));
		}
		else if ((PinNum > 15) && (PinNum <= 23) ){
				Clear_Bit(PortC,PinNum-16);
		}
		else if ((PinNum > 23) && (PinNum <= 31) ){
			Clear_Bit(PortD,PinNum-24);
		}
	}
	else if (PinValue == 1){
		if (PinNum <= 7)
		{
			Set_Bit(PortA,PinNum);
		}
		else if ((PinNum > 7) && (PinNum <= 15) )
		{
			Set_Bit(PortB,(PinNum-8));
		}
		else if ((PinNum > 15) && (PinNum <= 23) ){
			Set_Bit(PortC,(PinNum-16));
		}
		else if ((PinNum > 23) && (PinNum <= 31) ){
			Set_Bit(PortD,(PinNum-24));
		}
	}
}
uint8 DIO_ReadPin(uint8 PinNum){
	
		if (PinNum <= 7)
		{
		return (Get_Bit(PINA,PinNum)) >>PinNum;		
		}
		else if ((PinNum > 7) && (PinNum <= 15) )
		{
		return (Get_Bit(PINB,(PinNum-8))) >>(PinNum-8);
		}
		else if ((PinNum > 15) && (PinNum <= 23) ){
		return (Get_Bit(PINC,PinNum-16)) >> (PinNum-16);
		}
		
		else if ((PinNum > 23) && (PinNum <= 31) ){
		return (Get_Bit(PIND,PinNum-24)) >> (PinNum-24);
		}
	}
	

void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection){

if(PinDirection == 0)
{
	if (PinNum <= 7)
	{
		Clear_Bit(DDRA,PinNum);
	}
	else if ((PinNum > 7) && (PinNum <= 15) )
	{
		Clear_Bit(DDRB,(PinNum-8));
	}
	else if ((PinNum > 15) && (PinNum <= 23) ){
		Clear_Bit(DDRC,PinNum-16);
	}
	else if ((PinNum > 23) && (PinNum <= 31) ){
		Clear_Bit(DDRD,PinNum-24);
	}
}
else if (PinDirection == 1){
	if (PinNum <= 7)
	{
		Set_Bit(DDRA,PinNum);
	}
	else if ((PinNum > 7) && (PinNum <= 15) )
	{
		Set_Bit(DDRB,(PinNum-8));
	}
	else if ((PinNum > 15) && (PinNum <= 23) ){
		Set_Bit(DDRC,(PinNum-16));
	}
	else if ((PinNum > 23) && (PinNum <= 31) ){
		Set_Bit(DDRD,(PinNum-24));
	}
}
}