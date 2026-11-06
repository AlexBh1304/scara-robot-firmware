#define USING_STM32F411
#include "tim.h"

void TimInit(Timer_Config* pTimConfig, TIM_t* TIMx)
{
    //1
    TIMx->ARR = pTimConfig->ARR;
    TIMx->PSC =  pTimConfig->PSC;
    //TIMx->MODE = pTimConfig->MODE;
    TIMx->CCR1 = pTimConfig->CCR1;
    //CCMRx allows you to configure the output of the selected channel
    //CCRx sets the value
}
/*
void TimEnable(TIM_t* TIMx)
{
    //2
}
void TimDisable(TIM_t* TIMx)
{
    //3

}
void TimSetFrecuency(uint32_t UpdateFrecuency, TIM_t* TIMx)
{

}
uint8_t TimFlagStatus(TIM_t* TIMx, uint8_t FlagMask)
{


    return 0;
}

void TimClearFlag(TIM_t* TIMx, uint8_t FlagMask)
{

}

void TimInterruptEnable(TIM_t* TIMx, uint8_t InterruptName)
{

}
*/
