#include "../include/Questions.h"
#include "util/delay.h"


uint8  Answer[]={"B0:Yes B1:No"};

uint8  Question1[]={"0! = 0"};
uint8  Question2[]={"KHONT SA7BAK ?"};
uint8  Question3[]={"Om el Donia ? "};
uint8  Question4[]={"SunnyN17 1600CC?"};
uint8  Question5[]={"19277 MAJESTY? "};


uint8 *ptr_Questions[5] = {Question1,Question2,Question3,Question4,Question5};
uint8 Model_Answer[]= { NO, YES, YES, NO, NO};

void WelcomeMessage(void){

LCD_clear();
	
	LCD_displayStringRowColumn(ROW1,COL4,"WELCOME !");
DIO_SetPinDirection(BUZZER_PIN,OUTPUT);
DIO_SetPinDirection(LED0,OUTPUT);
DIO_SetPinDirection(LED1,OUTPUT);
DIO_SetPinDirection(LED2,OUTPUT);
DIO_SetPinDirection(LED3,OUTPUT);	

DIO_WritePin(LED0,HIGH);
_delay_ms(HALF_SECOND);
DIO_WritePin(LED0,LOW);
DIO_WritePin(BUZZER_PIN,HIGH);
_delay_ms(HALF_SECOND);
DIO_WritePin(BUZZER_PIN,LOW);
_delay_ms(HALF_SECOND);

DIO_WritePin(LED1,HIGH);
_delay_ms(HALF_SECOND);
DIO_WritePin(LED1,LOW);
DIO_WritePin(BUZZER_PIN,HIGH);
_delay_ms(HALF_SECOND);
DIO_WritePin(BUZZER_PIN,LOW);

DIO_WritePin(LED2,HIGH);
_delay_ms(HALF_SECOND);
DIO_WritePin(LED2,LOW);
DIO_WritePin(BUZZER_PIN,HIGH);
_delay_ms(HALF_SECOND);
DIO_WritePin(BUZZER_PIN,LOW);

DIO_WritePin(LED3,HIGH);
_delay_ms(HALF_SECOND);
DIO_WritePin(LED3,LOW);
DIO_WritePin(BUZZER_PIN,HIGH);
_delay_ms(HALF_SECOND);
DIO_WritePin(BUZZER_PIN,LOW);


LCD_clear();
}

/*********************************************************************************
 *
 * Function: BCD_init
 *
 * @param: void
 * @return: void
 *
 * Description: function to initialize the push buttons 0 and 1
 *
 ********************************************************************************/	
void BTN_init(void){
	
	DIO_SetPinDirection(BTN1,INPUT);
	DIO_SetPinDirection(BTN0,INPUT);
	
}

/*********************************************************************************
 *
 * Function: LCD_init
 *
 * @param: void
 * @return: void
 *
 * Description: function that Interfaces directly with the user by asking questions,
 *			taking answers, and judging them  
 *
 ********************************************************************************/
void GenerateQuestion(void){
	uint8 score= ASCII_OF_ZERO;
	uint8 ans[NUM_OF_QUES];
	uint8 i;
	

for(i=0;i<NUM_OF_QUES;i++)
	{
	LCD_clear();	
		_delay_ms(TWENTY_MS);
	LCD_displayStringRowColumn(ROW1,COL0,ptr_Questions[i]);
		_delay_ms(TWENTY_MS);
	LCD_displayStringRowColumn(ROW2,COL0,&Answer);
	_delay_ms(TWENTY_MS);

while(DIO_ReadPin(BTN0) == LOW && DIO_ReadPin(BTN1) == LOW);

if (DIO_ReadPin(BTN0) == PRESSED){
	ans[i] = YES;
}

else { ans[i] = NO; }

if (ans[i] == Model_Answer[i])
{
		score++;
		LCD_clear();
			_delay_ms(TWENTY_MS);
		LCD_displayStringRowColumn(ROW1,COL0,"Correct Answer ");
		LCD_displayChar(HAPPY_EMOJI);
		LED_Correct_Celebration();
			_delay_ms(FOUR_SECONDS);
}
	else { 
		LCD_clear();
			_delay_ms(TWENTY_MS);
		DIO_WritePin(BUZZER_PIN,HIGH);
		_delay_ms(TWO_SECONDS);
		DIO_WritePin(BUZZER_PIN,LOW);
		LCD_displayStringRowColumn(ROW1,COL0,"Wrong Answer ");
		LCD_displayChar(SAD_EMOJI);
			_delay_ms(FOUR_SECONDS);
		
		}
	
	}

	LCD_clear();
	_delay_ms(TWENTY_MS);
	LCD_displayStringRowColumn(ROW1,COL0,"Your Score is ");
	_delay_ms(TWENTY_MS);
	LCD_gotoRowColumn(ROW2,COL0);
	_delay_ms(TWENTY_MS);
	LCD_displayChar(score);
	_delay_ms(FOUR_SECONDS);
	End_Questions();
	
}


/*********************************************************************************
 *
 * Function: LED_Correct_Celebration
 *
 * @param: void
 * @return: void
 *
 * Description: function that excutes a set of commands after a correct answer   
 *
 ********************************************************************************/
void LED_Correct_Celebration(){

	DIO_WritePin(LED0,HIGH);
	_delay_ms(HALF_SECOND);
	DIO_WritePin(LED0,LOW);
	
	DIO_WritePin(LED1,HIGH);
	_delay_ms(HALF_SECOND);
	DIO_WritePin(LED1,LOW);
	
	DIO_WritePin(LED2,HIGH);
	_delay_ms(HALF_SECOND);
	DIO_WritePin(LED2,LOW);
	
	DIO_WritePin(LED3,HIGH);
	_delay_ms(HALF_SECOND);
	DIO_WritePin(LED3,LOW);	

	DIO_WritePin(LED3,HIGH);
	_delay_ms(HALF_SECOND);
	DIO_WritePin(LED3,LOW);		

	DIO_WritePin(LED2,HIGH);
	_delay_ms(HALF_SECOND);
	DIO_WritePin(LED2,LOW);

	DIO_WritePin(LED1,HIGH);
	_delay_ms(HALF_SECOND);
	DIO_WritePin(LED1,LOW);
	
	DIO_WritePin(LED0,HIGH);
	_delay_ms(HALF_SECOND);
	DIO_WritePin(LED0,LOW);
}

/*********************************************************************************
 *
 * Function: END_Question
 *
 * @param: void
 * @return: void
 *
 * Description: function that ends the Questions and do some commands   
 *
 ********************************************************************************/
void End_Questions(void){
		

		LCD_gotoRowColumn(ROW2,COL4);
		LCD_displayString("THANK YOU ");
		LCD_displayChar(RIGHT_HEART);
		LCD_displayChar(LEFT_HEART);


	for (uint8 i = 0;i<2;i++){
		
	DIO_WritePin(LED0,HIGH);
	DIO_WritePin(LED1,HIGH);
	DIO_WritePin(LED2,HIGH);
	DIO_WritePin(LED3,HIGH);
	DIO_WritePin(BUZZER_PIN,HIGH);
	_delay_ms(HALF_SECOND);
	
	DIO_WritePin(LED0,LOW);
	DIO_WritePin(LED1,LOW);
	DIO_WritePin(LED2,LOW);
	DIO_WritePin(LED3,LOW);
	DIO_WritePin(BUZZER_PIN,LOW);
	_delay_ms(HALF_SECOND);
	
	}
}

/*********************************************************************************
 *
 * Function: Again
 *
 * @param: void
 * @return: YES, if the YES button is pressed
 *			 NO, if the NO button is pressed
 *
 * Description: function that executes a set of commands after a correct answer   
 *
 ********************************************************************************/
uint8 Again(void){
	
	LCD_clear();
	LCD_gotoRowColumn(ROW1,COL1);
	LCD_displayString("Play Again ?");
	LCD_displayStringRowColumn(ROW2,COL1,"B0:Yes B1:No");
	
	while(DIO_ReadPin(BTN0) == LOW && DIO_ReadPin(BTN1) == LOW);
	if (DIO_ReadPin(BTN0)==HIGH)
	{
		return YES;
	}
	else return NO;
}