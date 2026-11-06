/**
 *
 * @brief Timer generating a pwm at 3200hz, enable and disable
 *
 */


#include "stm32f411.h"


int main()
{
    //Change clock to hse 25mhz
    RCC->CR |= (1 << 16);
    while(!(RCC->CR &(1 << 17)));
    RCC->CFGR |= (0b01);

    TIMxClockControl(TIM3, ENABLE);

    GPIOx_Config_t timerPin;   
    timerPin.Pin = GPIO_PIN6;
	timerPin.Mode = ALTERNATE_FUNCTION_MODE;
	timerPin.OutputSpeed = HIGH_OUTPUT_SPEED;
    timerPin.AFOutputType = 1;
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
    
    //Activate counter
    TIM3->CR1 |= (0b1);

    //Deactivate counter
    //TIM3->CR1 &= ~(0b1);

    while(1);
    return 0;
}
