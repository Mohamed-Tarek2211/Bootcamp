#include "../include/DIO.h"


/*********************************************************************************
 *
 * Function: DIO_WritePin
 *
 * @param:
 *		input : PinNum, The number of the pin to write a value on
 *		input : PinValue, The value to be written on the pin
 * @return: void
 *
 * Description: function to set or clear a predefined pin
 *
 *
 ********************************************************************************/
void DIO_WritePin(uint8 PinNum,uint8 PinValue){
	if(PinValue == LOW)
	{
		if (PinNum <= SEVEN_AS_PORT1_MAX)
		{
			Clear_Bit(PortA,PinNum);		
		}
		else if ((PinNum > SEVEN_AS_PORT1_MAX) && (PinNum <= FIFTEEN_AS_PORT2_MAX) )
		{
			Clear_Bit(PortB,(PinNum-PORT1_MAX));
		}
		else if ((PinNum > FIFTEEN_AS_PORT2_MAX) && (PinNum <= TWENTY_THREE_AS_PORT3_MAX) ){
				Clear_Bit(PortC,(PinNum-PORT2_MAX));
		}
		else if ((PinNum > TWENTY_THREE_AS_PORT3_MAX) && (PinNum <= THIRTY_ONE_AS_PORT3_MAX) ){
			Clear_Bit(PortD,(PinNum-PORT3_MAX));
		}
	}
	else if (PinValue == HIGH){
		if (PinNum <= SEVEN_AS_PORT1_MAX)
		{
			Set_Bit(PortA,PinNum);
		}
		else if ((PinNum > SEVEN_AS_PORT1_MAX) && (PinNum <= FIFTEEN_AS_PORT2_MAX) )
		{
			Set_Bit(PortB,(PinNum-PORT1_MAX));
		}
		else if ((PinNum > FIFTEEN_AS_PORT2_MAX) && (PinNum <= TWENTY_THREE_AS_PORT3_MAX) ){
			Set_Bit(PortC,(PinNum-PORT2_MAX));
		}
		else if ((PinNum > TWENTY_THREE_AS_PORT3_MAX) && (PinNum <= THIRTY_ONE_AS_PORT3_MAX) ){
			Set_Bit(PortD,(PinNum-PORT3_MAX));
		}
	}
}

/*********************************************************************************
 *
 * Function: DIO_ReadPin
 *
 * @param:
 *		input : PinNum, The number of the pin to write a value on
 * 
 * @return:The value of the determined pin as either a logic 0 or a logic 1 
 *
 * Description: function to return the logic state of a predefined pin
 *
 *
 ********************************************************************************/
uint8 DIO_ReadPin(uint8 PinNum){
	
		if (PinNum <= SEVEN_AS_PORT1_MAX)
		{
		return (Get_Bit(PINA,PinNum)) >>PinNum;		
		}
		else if ((PinNum > SEVEN_AS_PORT1_MAX) && (PinNum <= FIFTEEN_AS_PORT2_MAX) )
		{
		return (Get_Bit(PINB,(PinNum-PORT1_MAX))) >>(PinNum-PORT1_MAX);
		}
		else if ((PinNum > FIFTEEN_AS_PORT2_MAX) && (PinNum <= TWENTY_THREE_AS_PORT3_MAX) ){
		return (Get_Bit(PINC,(PinNum-PORT2_MAX))) >> (PinNum-PORT2_MAX);
		}
		
		else if ((PinNum > TWENTY_THREE_AS_PORT3_MAX) && (PinNum <= THIRTY_ONE_AS_PORT3_MAX) ){
		return (Get_Bit(PIND,(PinNum-PORT3_MAX))) >> (PinNum-PORT3_MAX);
		}
	}
	

/*********************************************************************************
 *
 * Function: DIO_SetPinDirection
 *
 * @param:
 *		input : PinNum, The number of the pin to write a value on
 *		input : PinDirection, The direction of the selected pin either INPUT or OUTPUT 
 *
 * @return: void
 *
 * Description: function to determine the direction predefined pin as either INPUT or OUTPUT
 *
 *
 ********************************************************************************/
void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection){

if(PinDirection == INPUT)
{
	if (PinNum <= SEVEN_AS_PORT1_MAX)
	{
		Clear_Bit(DDRA,PinNum);
	}
	else if ((PinNum > SEVEN_AS_PORT1_MAX) && (PinNum <= FIFTEEN_AS_PORT2_MAX) )
	{
		Clear_Bit(DDRB,(PinNum-PORT1_MAX));
	}
	else if ((PinNum > FIFTEEN_AS_PORT2_MAX) && (PinNum <= TWENTY_THREE_AS_PORT3_MAX) ){
		Clear_Bit(DDRC,(PinNum-PORT2_MAX));
	}
	else if ((PinNum > TWENTY_THREE_AS_PORT3_MAX) && (PinNum <= THIRTY_ONE_AS_PORT3_MAX) ){
		Clear_Bit(DDRD,(PinNum-24));
	}
}
else if (PinDirection == OUTPUT){
	if (PinNum <= SEVEN_AS_PORT1_MAX)
	{
		Set_Bit(DDRA,PinNum);
	}
	else if ((PinNum > SEVEN_AS_PORT1_MAX) && (PinNum <= FIFTEEN_AS_PORT2_MAX) )
	{
		Set_Bit(DDRB,(PinNum-PORT1_MAX));
	}
	else if ((PinNum > FIFTEEN_AS_PORT2_MAX) && (PinNum <= TWENTY_THREE_AS_PORT3_MAX) ){
		Set_Bit(DDRC,(PinNum-PORT2_MAX));
	}
	else if ((PinNum > TWENTY_THREE_AS_PORT3_MAX) && (PinNum <= THIRTY_ONE_AS_PORT3_MAX) ){
		Set_Bit(DDRD,(PinNum-PORT3_MAX));
	}
}
}