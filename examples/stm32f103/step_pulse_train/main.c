#include "gpio.h"
#include "rcc.h"
#include "tim.h"
#include "nvic.h"

#include "stm32f1xx.h"

#define TOTAL_STEPS 6400

volatile uint32_t counter = 0;

int main(void){

	ChangeSysClockPLL();
	GPIOx_Config_t gpioconfig;

	GPIOxClockControl(GPIOA, ENABLE);

	gpioconfig.Pin = GPIO_PIN8;
	gpioconfig.Mode = ALTERNATE_FUNCTION_OUTPUT_PP;
	gpioconfig.OutputSpeed = OUTPUT_SPEED_50MHZ;

	Gpio_Init(&gpioconfig, GPIOA);
	Gpio_Pin_Reset(GPIOA, GPIO_PIN8);
	
	Timer_Config timconfig;
	timconfig.ARR = 500;
	timconfig.PSC = 4;
	timconfig.CCR1 = 250;

	TIMxClockControl(TIM1, ENABLE);
	TimInit(&timconfig, TIM1);
	
	//PWM mode
	//0b110 << 4 -> CCMR1
	TIM1->CCMR1 |= (0b110 << 4);
	//CCER-> |= (1<< 0);
	TIM1->CCER |= (1<<0);
	//TIM1->CCER |= (1<<1);
	
	TIM1->BDTR |= (1 << 15);
	
	TIM1->EGR = (0b1); //Write only register

    //Clear Flag
    
	TimClearFlag(TIM1, TIM_SR_FLAG_UI);
    
	TIM1->CNT = 0;

	TimInterruptEnable(TIM1, TIM_DIER_UI_IR);
	EnableIRQ(TIM1_UP_IRQ);

	TimEnable(TIM1);

	while(1)
    {
        
	}

	return 0;
}


void TIM1_UP_IRQHandler(void){

	TimClearFlag(TIM1, TIM_SR_FLAG_UI);
	counter++;

	if(counter < 10)
    {
        TIM1->ARR += 50;
        TIM1->CCR1 += 25;
	}
    
    if(counter >= TOTAL_STEPS)
    {
        TimDisable(TIM1);
    }

}
