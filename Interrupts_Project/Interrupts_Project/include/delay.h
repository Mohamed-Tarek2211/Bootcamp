#ifndef DELAY_H
#define DELAY_H

#include "types.h"

uint16 volatile Ticks = 0;
volatile enum STATE{READY, STEADY, GO};

#endif