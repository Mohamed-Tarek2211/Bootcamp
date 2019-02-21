#ifndef SEVENSEG_H_
#define SEVENSEG_H_

#include "ATMEGA32A.h"
#include "DIO.h"
#include "7SEG_cfg.h"
#include "util/delay.h"


void BCDSevegments_enable(uint8 Seven_Seg_No);
void BCDSevegments_disable(uint8 Seven_Seg_No);
void BCDSevegments_displayNo(uint8 No);
void BCDSevegments_init(void);

#define DECIMAL_BASE 10
#define DECIMAL_BASEX10 100
#define DECIMAL_BASEX100 1000

#define DELAY_MS_40 40

#endif /* 7SEG_H_ */