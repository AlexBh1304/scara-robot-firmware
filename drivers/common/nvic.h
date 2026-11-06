#ifndef NVIC_H
#define NVIC_H

#include "stm32f1xx.h"

void EnableIRQ(uint8_t irqnumber);

#define TIM1_UP_IRQ	25
#define TIM1_CC_IRQ	27




#endif
