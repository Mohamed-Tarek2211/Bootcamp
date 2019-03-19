#include "tasks.h"
#include "LCD.h"
uint8_t x;
uint16_t LED2Periodicity = 500;
uint16_t LED1Periodicity = 1000;
uint8_t Suspending_flag = 1;
uint16_t BTN_Counter;
uint8_t  Word1[]={"7ob 3omry"};
uint8_t  Word2[]={"naseeto w fatny"};
uint8_t  Word3[]={"3esht m3 wa7da"};
uint8_t  Word4[]={"tmawetni"};
uint8_t  Word5[]={"elfanan 7mo bika "};
TaskHandle_t LED1TaskHandle,LED2TaskHandle;

uint8_t *ptr_Words[5] = {Word1,Word2,Word3,Word4,Word5};

void
LED1Task(void *LED1Periodicity)
{
    uint16_t *Task1_PeriodinMS;
    TickType_t TicksToDelay,LastWakeTime;
    Task1_PeriodinMS = (TickType_t*)LED1Periodicity;

    while(1)
    {
        TicksToDelay = pdMS_TO_TICKS(*Task1_PeriodinMS);
        LastWakeTime = xTaskGetTickCount();

        GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1,GPIO_PIN_1);

        vTaskDelayUntil(&LastWakeTime,TicksToDelay);

        GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1,LOW);

        vTaskDelayUntil(&LastWakeTime,TicksToDelay);
    }
}

void
LED2Task(void *LED2Periodicity)
{
    uint16_t *Task2_PeriodinMS;
    TickType_t TicksToDelayForLED2,LastWakeTimeLED2;

    Task2_PeriodinMS = (TickType_t*)LED2Periodicity;


    while(1){
        TicksToDelayForLED2 = pdMS_TO_TICKS(*Task2_PeriodinMS);
        LastWakeTimeLED2 = xTaskGetTickCount();

        GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2,GPIO_PIN_2);

        vTaskDelayUntil(&LastWakeTimeLED2,TicksToDelayForLED2);

        GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2,LOW);

        vTaskDelayUntil(&LastWakeTimeLED2,TicksToDelayForLED2);
    }
}

void
InitTask(void *pvParameters)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA));

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOC));

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF));

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOD));

    HWREG(GPIO_PORTF_BASE+GPIO_O_LOCK) = GPIO_LOCK_KEY;
    HWREG(GPIO_PORTF_BASE+GPIO_O_CR) |= 0x01;

    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_4 | GPIO_PIN_0);
    GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_4 , GPIO_STRENGTH_2MA , GPIO_PIN_TYPE_STD_WPU);
    GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, GPIO_PIN_3);
    GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE,GPIO_PIN_2 |GPIO_PIN_3|GPIO_PIN_4);
    GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE,GPIO_PIN_4 |GPIO_PIN_5|GPIO_PIN_6 | GPIO_PIN_7);

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

    vTaskSuspend(NULL);
}

void
BTNTask(void *pvParameters)
{
    TickType_t TicksToDelayBTN,LastWakeTimeBTN;
    TicksToDelayBTN = pdMS_TO_TICKS(10);
    LastWakeTimeBTN = xTaskGetTickCount();

    while(1)
    {
        x = GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4);

        if( LOW == GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4) )
        {
            BTN_Counter++;
        }
        vTaskDelay(pdMS_TO_TICKS(TEN_MS));
        if( BTN_Counter > 0 && BTN_Counter <= 5 && ( LOW != GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4) ) )
        {
            BTN_Counter = 0;
        }
        if( BTN_Counter > VALUEFORDEBOUNCING && ( LOW != GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4) ) )
        {
               if(BTN_Counter < 500)
                   {
                       if(Suspending_flag == 1)
                           {
                           LED2Periodicity += 100;
                           LED1Periodicity += 100;
                           Suspending_flag = 0;
                           }
                   }
               if(BTN_Counter >= 5)
                 {
                       Suspending_flag ^= 1;
                   if (Suspending_flag == 0)
                   {
                      vTaskSuspend(LED1TaskHandle);
                      vTaskSuspend(LED2TaskHandle);
                      BTN_Counter = 0;
                   }
                   else if(Suspending_flag == 1)
                   {
                       vTaskResume(LED1TaskHandle);
                       vTaskResume(LED2TaskHandle);
                       BTN_Counter = 0;
                   }
                 }
        }
        vTaskDelayUntil(&LastWakeTimeBTN,TicksToDelayBTN);
    }
}

void
LCDTask(void *pvParameters)
{
    TickType_t TicksToDelayLCD,LastWakeTimeLCD;
    TicksToDelayLCD = pdMS_TO_TICKS(ONESECOND);
    LastWakeTimeLCD = xTaskGetTickCount();
    uint8_t static counter = 0;
    while(1)
    {
        LCD_clear();
        vTaskDelay( pdMS_TO_TICKS(5) );
        LCD_displayString(ptr_Words[counter]);
        counter++;
        if(counter == 5)
            counter = 0;

        vTaskDelayUntil(&LastWakeTimeLCD,TicksToDelayLCD);
    }
}
void BuzzerTask(void *pvParameters) {

        TickType_t TicksToDelayBUZZER,LastWakeTimeBUZZER;
        TicksToDelayBUZZER = pdMS_TO_TICKS(10);
        LastWakeTimeBUZZER = xTaskGetTickCount();
        while(1)
        {
            GPIOPinWrite(GPIO_PORTD_BASE,GPIO_PIN_3,GPIO_PIN_3);

            vTaskDelayUntil(&LastWakeTimeBUZZER,TicksToDelayBUZZER);

            GPIOPinWrite(GPIO_PORTD_BASE,GPIO_PIN_3,0);

            vTaskDelayUntil(&LastWakeTimeBUZZER,TicksToDelayBUZZER);
        }
}
