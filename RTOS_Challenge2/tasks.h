#ifndef TASKS_H_
#define TASKS_H_

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "inc/hw_memmap.h"
#include "inc/hw_gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "FreeRTOSConfig.h"
#include "event_groups.h"

#define HIGH 1
#define LOW 0
#define TWO_MS 2
#define FIVEHUNDRED_MS 500
#define ONESECOND 1000
#define HUNDRED_MS 100
#define FIFTY_MS 50
#define TEN_MS 10

#define BIT_0 (1<<0)
#define BIT_1 (1<<1)

#define VALUEFORDEBOUNCING 5

void
InitTask(void *pvParameters);

void
LED1Task(void *pvParameters);

void
BTN1Task(void *pvParameters);

void
BTN2Task(void *pvParameters);

#endif /* TASKS_H_ */
