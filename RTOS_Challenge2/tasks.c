#include "tasks.h"
#include "LCD.h"



/* Variable that takes the value of the event flag in LED1Task */
uint8_t ButtonPressedFlag = 0;

/* Mutex between BTN1Task & BTN2Task to allow only 1 to write on the event flag */
SemaphoreHandle_t LCD_MUTEXFlag;

/* The event flag */
EventGroupHandle_t xEventGroupBTNFlags;
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

    while(1)
    {
        ButtonPressedFlag = xEventGroupWaitBits(
        xEventGroupBTNFlags, /* The event group being tested. */
        BIT_1 | BIT_0, /* The bits within the event group to wait for. */
        pdTRUE, /* BIT_0 and BIT_4 should be cleared before returning. */
        pdFALSE, /* Don't wait for both bits, either bit will do. */
        10 );/* Wait a maximum of 10ms for either bit to be set. */
        if( (ButtonPressedFlag & BIT_0 ) != LOW  )
        {
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1,GPIO_PIN_1);
            vTaskDelay( pdMS_TO_TICKS(5) );
            LCD_gotoRowColumn(1,0);
            LCD_displayString("BUTTON 1 PRESSED!");
        }
        else if( (ButtonPressedFlag & BIT_1 ) != LOW )
        {
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2,GPIO_PIN_2);
            vTaskDelay( pdMS_TO_TICKS(5) );
            LCD_gotoRowColumn(1,0);
            LCD_displayString("BUTTON 2 PRESSED!");
        }
        else
        {
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1,LOW);
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2,LOW);
            LCD_clear();
        }
        vTaskDelayUntil(&LastWakeTime,TicksToDelay);
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

    /* Peripherals Initialization  */
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA));

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOC));

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF));

    /* Unlock the PORTF Pins for activationg the push buttons  */
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
    vTaskDelay(4);
    LCD_sendCommand(CMD_LCD4BIT32);
    vTaskDelay(4);
    LCD_sendCommand(CMD_LCD_2_LINES_5X7);
    vTaskDelay(4);
    LCD_sendCommand(CMD_CURSOR_ON);
    vTaskDelay(4);
    LCD_sendCommand(CMD_RESET);
    vTaskDelay(4);
    LCD_sendCommand(CMD_SHIFT_DISPLAY_LEFT);
    vTaskDelay(4);
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
    TicksToDelayBTN = pdMS_TO_TICKS(10);
    LastWakeTimeBTN = xTaskGetTickCount();

    while(1)
    {
        if ( LOW == GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4))
        {
           //ButtonPressedFlag = HIGH;
            if( xSemaphoreTake( LCD_MUTEXFlag, 10 ) == pdTRUE)
            {
                xEventGroupSetBits(xEventGroupBTNFlags , BIT_0);
            }

        }
        else
        {
            xSemaphoreGive( LCD_MUTEXFlag );
            //ButtonPressedFlag = LOW;
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
    TicksToDelayBTN = pdMS_TO_TICKS(10);
    LastWakeTimeBTN = xTaskGetTickCount();

    while(1)
    {
        if ( LOW == GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_0))
        {
         //  ButtonPressedFlag = HIGH;
            if( xSemaphoreTake( LCD_MUTEXFlag, 10 ) == pdTRUE)
            {
            xEventGroupSetBits(xEventGroupBTNFlags , BIT_1);
            }
        }
        else
        {
            xSemaphoreGive( LCD_MUTEXFlag );
            //ButtonPressedFlag = LOW;
        }

        vTaskDelayUntil(&LastWakeTimeBTN,TicksToDelayBTN);
    }
}
