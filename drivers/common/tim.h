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
	uint16_t TimerMode;
	uint16_t CCRx;
    uint8_t TimerxChannelx;
    uint8_t TimerOutput;
    uint16_t OutputPinNumber;
    uint16_t AFNumber;
    GPIO_t* OutputPinPort;
}Timer_Config;

void TimInit(TIM_t* TIMx, Timer_Config* pTimConfig);
void TIMxEnableCounter(TIM_t* TIMx);
void TIMxDisableCounter(TIM_t* TIMx);
void TIMxSetPSC(TIM_t* TIMx, uint32_t PSC);
void TIMxSetARR(TIM_t* TIMx, uint32_t ARR);
uint8_t TimFlagStatus(TIM_t* TIMx, uint8_t FlagMask);
void TimClearFlag(TIM_t* TIMx, uint8_t FlagMask);
void TimInterruptEnable(TIM_t* TIMx, uint8_t InterruptName);

#define PWM 0

#define TimerxChannel1 1
#define TimerxChannel2 2
#define TimerxChannel3 3
#define TimerxChannel4 4

#endif /*TIM_H*/

