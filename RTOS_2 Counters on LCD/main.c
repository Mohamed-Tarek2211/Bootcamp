#include "tasks.h"


int main()
{
                    /*  Clock Initialization  */
    SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);

                    /*  Task Creation Section  */
	xTaskCreate(InitTask, "Initialization task", 200, NULL , 6 , NULL);
	xTaskCreate(LED1Task, "Red led task", 50 , NULL , 2 , NULL);
	xTaskCreate(BTN1Task,"Button_1 Task", 100 , NULL , 3 , NULL);
	xTaskCreate(BTN2Task,"Button_2 Task", 100 , NULL , 3 , NULL);

	                /*  Scheduler Start  */
	vTaskStartScheduler();

}
