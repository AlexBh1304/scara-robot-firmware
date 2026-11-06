/**
 * @brief Header file for timer basic peripherals
 */

#ifndef TIM_H
#define TIM_H

#ifdef USING_STM32F411
#include "stm32f411.h"

#endif  /*USING_STM32F411*/

#ifdef USING_STM32F103

#include "stm32f1xx.h"

#define TIM_SR_FLAG_UI	 0x01U
#define TIM_SR_FLAG_CC1F 0x02U
#define TIM_DIER_UI_IR		0
#define TIM_DIER_CC1IE_IR 	1

#endif  /*USING_STM32F103*/



typedef struct{
	uint16_t ARR;
	uint16_t PSC;
	uint16_t MODE;
	uint16_t CCR1;
}Timer_Config;

void TimInit(Timer_Config* pTimConfig, TIM_t* TIMx);
void TimEnable(TIM_t* TIMx);
void TimDisable(TIM_t* TIMx);
void TimSetFrecuency(uint32_t UpdateFrecuency, TIM_t* TIMx);
uint8_t TimFlagStatus(TIM_t* TIMx, uint8_t FlagMask);


void TimClearFlag(TIM_t* TIMx, uint8_t FlagMask);
void TimInterruptEnable(TIM_t* TIMx, uint8_t InterruptName);


#endif /*TIM_H*/

