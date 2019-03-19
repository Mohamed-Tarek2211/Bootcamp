#include "tasks.h"
#include "LCD.h"



/* Variable that takes the value of the event flag in LED1Task */
uint8_t ButtonPressedFlag = 0;

/* Mutex between BTN1Task & BTN2Task to allow only 1 to write on the event flag */
SemaphoreHandle_t LCD_MUTEXFlag;

/* The event flag */
EventGroupHandle_t xEventGroupBTNFlags;

/* The Queue */
QueueHandle_t LCDMessagesQueue;

uint8_t xBTN1_msg;
uint8_t xBTN2_msg;
/*********************************************************************************
 *
 * Function: LED1Task
 *
 * @param: void
 * @return: void
 *
 * Description: task that gets data from the event flag and turn the corresponding
 *          LED on and type the corresponding data on the LCD
 *
 ********************************************************************************/
void LED1Task(void *pvParameters)
{

    TickType_t TicksToDelay,LastWakeTime;
    TicksToDelay = pdMS_TO_TICKS(HUNDRED_MS);
    LastWakeTime = xTaskGetTickCount();
    static uint8_t ValueFromQueue,counter2 = '0',counter1 = '0';

    while(1)
    {
        if(pdPASS == xQueueReceive( LCDMessagesQueue, &ValueFromQueue, 10 )  )
        {
        /* Nothing was received from the queue – even after blocking to wait
        for data to arrive. */
        if( ValueFromQueue == COUNTER1INCREMENT )
        {
            ValueFromQueue = 0;
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1,GPIO_PIN_1);
           // vTaskDelay( pdMS_TO_TICKS(5) );
            LCD_gotoRowColumn(1,0);
            counter1++;
            LCD_displayChar(counter1);
        }
        else if( ValueFromQueue == COUNTER2INCREMENT )
        {
            ValueFromQueue = 0;
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2,GPIO_PIN_2);
            //vTaskDelay( pdMS_TO_TICKS(5) );
            LCD_gotoRowColumn(2,0);
            counter2++;
            LCD_displayChar(counter2);

        }
        else
        {
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1,LOW);
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2,LOW);
           // LCD_clear();
        }
        vTaskDelayUntil(&LastWakeTime,TicksToDelay);
    }
    }
}

/*********************************************************************************
 *
 * Function: InitTask
 *
 * @param: void
 * @return: void
 *
 * Description: function to initialize all the hardware
 *
 ********************************************************************************/
void
InitTask(void *pvParameters)
{
    /*  Create the Event Group  */
    xEventGroupBTNFlags = xEventGroupCreate();
    /*  Create the Mutex Flag  */
    LCD_MUTEXFlag = xSemaphoreCreateMutex();
    /*  Create the Queue  */
    LCDMessagesQueue = xQueueCreate( TWOITEMS , sizeof(uint8_t) );

    /* Peripherals Initialization  */
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA));

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOC));

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF));

    /* Unlock the PORTF Pins for activating the push buttons  */
    HWREG(GPIO_PORTF_BASE+GPIO_O_LOCK) = GPIO_LOCK_KEY;
    HWREG(GPIO_PORTF_BASE+GPIO_O_CR) |= 0x01;

    /* Pins Configurations  */
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_4 | GPIO_PIN_0);
    GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_4 | GPIO_PIN_0  , GPIO_STRENGTH_2MA |GPIO_STRENGTH_2MA , GPIO_PIN_TYPE_STD_WPU | GPIO_PIN_TYPE_STD_WPU);
    GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE,GPIO_PIN_2 |GPIO_PIN_3|GPIO_PIN_4);
    GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE,GPIO_PIN_4 |GPIO_PIN_5|GPIO_PIN_6 | GPIO_PIN_7);

    /* LCD Initialization  */
    LCD_sendCommand(CMD_LCD4BIT33);
    vTaskDelay(FOUR_MS);
    LCD_sendCommand(CMD_LCD4BIT32);
    vTaskDelay(FOUR_MS);
    LCD_sendCommand(CMD_LCD_2_LINES_5X7);
    vTaskDelay(FOUR_MS);
    LCD_sendCommand(CMD_CURSOR_ON);
    vTaskDelay(FOUR_MS);
    LCD_sendCommand(CMD_RESET);
    vTaskDelay(FOUR_MS);
    LCD_sendCommand(CMD_SHIFT_DISPLAY_LEFT);
    vTaskDelay(FOUR_MS);
    LCD_sendCommand(0x80);

    /* Suspend the Init task  */
    vTaskSuspend(NULL);
}
/*********************************************************************************
 *
 * Function: BTN1Task
 *
 * @param: void
 * @return: void
 *
 * Description: task that sets a bit in the event flag after a button is pressed
 *
 ********************************************************************************/
void
BTN1Task(void *pvParameters)
{
    TickType_t TicksToDelayBTN,LastWakeTimeBTN;
    TicksToDelayBTN = pdMS_TO_TICKS(100);
    LastWakeTimeBTN = xTaskGetTickCount();
    xBTN1_msg = COUNTER1INCREMENT;
    static uint8_t BTN1PRESSED = LOW;

    while(1)
    {
        if ( LOW == GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4) && BTN1PRESSED == LOW)
        {
            BTN1PRESSED = HIGH;
            // xEventGroupSetBits(xEventGroupBTNFlags , BIT_0);
            xQueueSend( LCDMessagesQueue, &xBTN1_msg , 10 );
            //xQueueOverwrite( LCDMessagesQueue, &xBTN1_msg );
        }
        else
        {
            BTN1PRESSED = LOW;
        }

        vTaskDelayUntil(&LastWakeTimeBTN,TicksToDelayBTN);
    }
}
/*********************************************************************************
 *
 * Function: BTN2Task
 *
 * @param: void
 * @return: void
 *
 * Description: task that sets a bit in the event flag after a button is pressed
 *
 ********************************************************************************/
void
BTN2Task(void *pvParameters)
{
    TickType_t TicksToDelayBTN,LastWakeTimeBTN;
    TicksToDelayBTN = pdMS_TO_TICKS(100);
    LastWakeTimeBTN = xTaskGetTickCount();
    xBTN2_msg = COUNTER2INCREMENT;
    static uint8_t BTN2PRESSED = LOW;

    while(1)
    {

        if ( LOW == GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_0) && BTN2PRESSED == LOW)
        {
            BTN2PRESSED = HIGH;
            //   xEventGroupSetBits(xEventGroupBTNFlags , BIT_1);
            xQueueSend( LCDMessagesQueue, &xBTN2_msg , 10 );
            // xQueueOverwrite( LCDMessagesQueue, &xBTN2_msg );
        }
        else
            BTN2PRESSED = LOW;


        vTaskDelayUntil(&LastWakeTimeBTN,TicksToDelayBTN);
    }
}
