/**
 *
 * @brief Timer generating a pwm at 3200hz, enable and disable
 *
 */

#include "stm32f411.h"
void TIMER_INIT2();
void TIMER_INIT3();
void TIMER_INIT4();
void TIMER_INIT5();

#define MAX_STEPS   3200
//this is not the max frecuency, if you want to get a higher frecuency, lower this number, if you want a lower one do otherwise
#define MAX_FRECUENCY   350

int main()
{

    //Change clock to hse 25mhz
    RCC->CR |= (1 << 16);
    while(!(RCC->CR &(1 << 17)));
    RCC->CFGR |= (0b01);
    TIMER_INIT2();
    TIMER_INIT4();
    TIMER_INIT5();
    TIMER_INIT3();
    
    while(!(TIM5->SR & (0b1)))
    {
        
        if((TIM5->CNT >= 0) && (TIM5->CNT <= 400))
        {
            TIM3->PSC = MAX_FRECUENCY * 8;
        }
        else if ((TIM5->CNT >= 401) && (TIM5->CNT <= 800))
        {
            TIM3->PSC = MAX_FRECUENCY * 4;
        }
        else if ((TIM5->CNT >= 801) && (TIM5->CNT <= 1200))
        {
            TIM3->PSC = MAX_FRECUENCY * 2;
        }
        else if ((TIM5->CNT >= 1201) && (TIM5->CNT <= 2000))
        {
            TIM3->PSC = MAX_FRECUENCY;
        }
        else if ((TIM5->CNT >= 2001) && (TIM5->CNT <= 2400))
        {
            TIM3->PSC = MAX_FRECUENCY * 2;
        }
        else if ((TIM5->CNT >= 2401) && (TIM5->CNT <= 2800))
        {
            TIM3->PSC = MAX_FRECUENCY * 4;
        }
        else if ((TIM5->CNT >= 2801) && (TIM5->CNT <= 3200))
        {
            TIM3->PSC = MAX_FRECUENCY * 8;
        }

    }
        
    TIM3->CR1 &= ~(0b1);
    

    while(1);
    return 0;
}
void TIMER_INIT3()
{

    TIMxClockControl(TIM3, ENABLE);

    GPIOx_Config_t timerPin;   
    timerPin.Pin = GPIO_PIN6;
	timerPin.Mode = ALTERNATE_FUNCTION_MODE;
	timerPin.OutputSpeed = HIGH_OUTPUT_SPEED;
    timerPin.AFOutputType = 0;
    timerPin.AFNumber = AF02;
    

    //GPIOxClockControl(GPIOA, ENABLE);
    Gpio_Init(&timerPin, GPIOA);

    //PSC = 32khz
    TIM3->PSC = 780;

    //ARR = PWM frecuency = 3.2khz
    TIM3->ARR = 9;
    
    //CCR1 = Duty Cycle = 50%
    TIM3->CCR1 = 5;

    //CCMR1 -> OCxM = PWM1 mode
    TIM3->CCMR1 |= (0b110 << 4);

    //CCMR1 ->OC1PE = preload enable
    TIM3->CCMR1 |= (0b1 << 3);

    //ARPE CR1 Auto reload preload enable
    TIM3->CR1 |= (0b1 << 7);

    //EGR UG bit Update generation
    TIM3->EGR |= (0b1);

    //Activate the output CC1E
    TIM3->CCER |= (0b1);

    //Master mode?
    TIM3->CR2 |= (0b010 << 4);
    
    //Activate counter
    TIM3->CR1 |= (0b1);

    //Deactivate counter

}
void TIMER_INIT2()
{

    TIMxClockControl(TIM2, ENABLE);

    GPIOx_Config_t timerPin;   
    timerPin.Pin = GPIO_PIN0;
	timerPin.Mode = ALTERNATE_FUNCTION_MODE;
	timerPin.OutputSpeed = HIGH_OUTPUT_SPEED;
    timerPin.AFOutputType = 0;
    timerPin.AFNumber = AF01;
    

    //GPIOxClockControl(GPIOA, ENABLE);
    Gpio_Init(&timerPin, GPIOA);

    //PSC = 32khz
    TIM2->PSC = 0;

    //ARR = PWM frecuency = 3.2khz
    TIM2->ARR = 3;
    
    //CCR1 = Duty Cycle = 50%
    TIM2->CCR1 = 2;

    //CCMR1 -> OCxM = PWM1 mode
    TIM2->CCMR1 |= (0b110 << 4);

    //CCMR1 ->OC1PE = preload enable
    TIM2->CCMR1 |= (0b1 << 3);

    //ARPE CR1 Auto reload preload enable
    TIM2->CR1 |= (0b1 << 7);

    //Select clock source 
    TIM2->SMCR |= ((0b010 << 4) | (0b111));

    //EGR UG bit Update generation
    TIM2->EGR |= (0b1);

    //Activate the output CC1E
    TIM2->CCER |= (0b1);
    


    //Activate counter
    TIM2->CR1 |= (0b1);

    //Deactivate counter
}

void TIMER_INIT4()
{

    TIMxClockControl(TIM4, ENABLE);

    GPIOx_Config_t timerPin;   
    timerPin.Pin = GPIO_PIN9;
	timerPin.Mode = ALTERNATE_FUNCTION_MODE;
	timerPin.OutputSpeed = HIGH_OUTPUT_SPEED;
    timerPin.AFOutputType = 0;
    timerPin.AFNumber = AF02;
    

    //GPIOxClockControl(GPIOA, ENABLE);
    Gpio_Init(&timerPin, GPIOB);

    //PSC = 32khz
    TIM4->PSC = 0;

    //ARR = PWM frecuency = 3.2khz
    TIM4->ARR = 7;
    
    //CCR1 = Duty Cycle = 50%
    TIM4->CCR4 = 4;

    //CCMR1 -> OCxM = PWM1 mode
    TIM4->CCMR2 |= (0b110 << 12);

    //CCMR1 ->OC1PE = preload enable
    TIM4->CCMR2 |= (0b1 << 11);

    //ARPE CR1 Auto reload preload enable
    TIM4->CR1 |= (0b1 << 7);

    //Select clock source 
    TIM4->SMCR |= ((0b010 << 4) | (0b111));

    //EGR UG bit Update generation
    TIM4->EGR |= (0b1);

    //Activate the output CC1E
    TIM4->CCER |= (0b1 << 12);
    
    //Activate counter
    TIM4->CR1 |= (0b1);

    //Deactivate counter
}
void TIMER_INIT5()
{

    TIMxClockControl(TIM5, ENABLE);

    GPIOx_Config_t timerPin;   
    timerPin.Pin = GPIO_PIN1;
	timerPin.Mode = ALTERNATE_FUNCTION_MODE;
	timerPin.OutputSpeed = HIGH_OUTPUT_SPEED;
    timerPin.AFOutputType = 0;
    timerPin.AFNumber = AF02;
    

    //GPIOxClockControl(GPIOA, ENABLE);
    Gpio_Init(&timerPin, GPIOA);

    //PSC = 32khz
    TIM5->PSC = 0;

    //ARR = PWM frecuency = 3.2khz
    TIM5->ARR = 3200 - 1;
    
    //CCR1 = Duty Cycle = 50%
    TIM5->CCR2 = 1600;

    //CCMR1 -> OCxM = PWM1 mode
    TIM5->CCMR1 |= (0b110 << 12);

    //CCMR1 ->OC1PE = preload enable
    TIM5->CCMR1 |= (0b1 << 11);

    //ARPE CR1 Auto reload preload enable
    TIM5->CR1 |= (0b1 << 7);

    //Select clock source 
    TIM5->SMCR |= ((0b001 << 4) | (0b111));

    //EGR UG bit Update generation
    TIM5->EGR |= (0b1);

    //Activate the output CC1E
    TIM5->CCER |= (0b1 << 4);
    
    //UPDATE FLAG REMOVE
    TIM5->SR &= ~(0b1);
    //Activate counter
    TIM5->CR1 |= (0b1);


    //Deactivate counter
}


