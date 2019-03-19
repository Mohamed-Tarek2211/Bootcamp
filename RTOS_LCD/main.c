#include "tasks.h"


int main()
{

    SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);

	xTaskCreate(InitTask, "Initialization task", 300, NULL , 5 , NULL);
	xTaskCreate(LED1Task, "Red led task", 50 , (void*)&LED1Periodicity , 3 , &LED1TaskHandle);
	xTaskCreate(LED2Task, "BLUE led task", 50 , (void*)&LED2Periodicity , 3 , &LED2TaskHandle);
	xTaskCreate(BuzzerTask,"LED Blink", 50 , NULL , 4 , NULL);
	xTaskCreate(LCDTask,"LCD Blink", 50 , NULL , 1 , NULL);
	xTaskCreate(BTNTask,"Button Task", 200 , NULL , 4 , NULL);

	   vTaskStartScheduler();

}
