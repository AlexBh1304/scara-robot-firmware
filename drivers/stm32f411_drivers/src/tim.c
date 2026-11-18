#define USING_STM32F411
#include "tim.h"

void TimInit(TIM_t* TIMx, Timer_Config* pTimConfig)
{

    TIMxClockControl(TIMx, ENABLE);

    if(pTimConfig->TimerOutput == ENABLE)
    {
        GPIOx_Config_t timerPin;   
        timerPin.Pin = pTimConfig->OutputPinNumber;
        timerPin.Mode = ALTERNATE_FUNCTION_MODE;
        timerPin.OutputSpeed = HIGH_OUTPUT_SPEED;
        timerPin.AFOutputType = 0;
        timerPin.AFNumber = pTimConfig->AFNumber;
        Gpio_Init(&timerPin, pTimConfig->OutputPinPort);
    }
        
    if(pTimConfig->TimerMode == PWM)
    {
        //PSC = Preescaler from Peripheralclock
        TIMx->PSC = pTimConfig->PSC;
        //ARR = PWM frecuency 
        TIMx->ARR = pTimConfig->ARR;
        //ARPE CR1 Auto reload preload enable
        TIMx->CR1 |= (0b1 << 7);
        //EGR UG bit Update generation
        TIMx->EGR |= (0b1);


        switch(pTimConfig->TimerxChannelx)
        {
            case TimerxChannel1:
                //CCRx = Duty Cycle *
                TIMx->CCR1 = pTimConfig->CCRx; 
                //CCMRx -> OCxM = PWM1 mode *
                TIMx->CCMR1 |= (0b110 << 4); 
                //CCMRx ->OC1PE = preload enable *
                TIMx->CCMR1 |= (0b1 << 3); 
                //Activate the output CC1E *
                TIMx->CCER |= (0b1);
                break;
            case TimerxChannel2:
                break;
            case TimerxChannel3:
                break;
            case TimerxChannel4:
                break;
        }
    }
}
void TIMxEnableCounter(TIM_t* TIMx)
{
    TIMx->CR1 |= (0b1);
}

void TIMxDisableCounter(TIM_t* TIMx)
{
    TIMx->CR1 &= ~(0b1);
}

void TIMxSetARR(TIM_t* TIMx, uint32_t ARR)
{
    TIMx->ARR = ARR;
}

void TIMxSetPSC(TIM_t* TIMx, uint32_t PSC)
{
    TIMx->PSC = PSC;
}
/*



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
