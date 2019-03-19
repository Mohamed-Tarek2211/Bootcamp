#ifndef TASKS_H_
#define TASKS_H_

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "FreeRTOSConfig.h"

#define HIGH 1
#define LOW 0
#define TWO_MS 2
#define FIVEHUNDRED_MS 500
#define ONESECOND 1000
#define FIFTY_MS 50
#define TEN_MS 10

#define VALUEFORDEBOUNCING 5

extern uint16_t LED2Periodicity;
extern uint16_t LED1Periodicity;
extern TaskHandle_t LED1TaskHandle,LED2TaskHandle;


void
InitTask(void *pvParameters);

void
LED1Task(void *LED1Periodicity);

void
LED2Task(void *LED2Periodicity);

void
LED3Task(void *pvParameters);

void
LCDTask(void *pvParameters);

void
BuzzerTask(void *pvParameters);

void
BTNTask(void *pvParameters);

#endif /* TASKS_H_ */
