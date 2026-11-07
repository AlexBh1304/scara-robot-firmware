#define USING_STM32F411

#include "rcc.h"


void GPIOxClockControl(GPIO_t* pGPIO, uint8_t Action)
{
    if(Action == ENABLE)
    {
        if(pGPIO == GPIOA)
        {
            RCC->AHB1ENR |= (1 << 0);
        }
        else if(pGPIO == GPIOB)
        {
            RCC->AHB1ENR |= (1 << 1);
        }
        else if(pGPIO == GPIOC)
        {
            RCC->AHB1ENR |= (1 << 2);
        }
        else if(pGPIO == GPIOD)
        {
            RCC->AHB1ENR |= (1 << 3);
        }
    }
    
    if(Action == DISABLE)
    {
        if(pGPIO == GPIOA)
        {
            RCC->AHB1ENR &= ~(1 << 0);
        }
        else if(pGPIO == GPIOB)
        {
            RCC->AHB1ENR &= ~(1 << 1);
        }
        else if(pGPIO == GPIOC)
        {
            RCC->AHB1ENR &= ~(1 << 2);
        }
        else if(pGPIO == GPIOD)
        {
            RCC->AHB1ENR &= ~(1 << 3);
        }
    }
    
}

void TIMxClockControl(TIM_t* pTIM, uint8_t Action)
{    
    if(Action == ENABLE)
    {
        if(pTIM == TIM2)
        {
            RCC->APB1ENR |= (1 << 0);
        }
        else if(pTIM == TIM3)
        {
            RCC->APB1ENR |= (1 << 1);
        }
        else if(pTIM == TIM4)
        {
            RCC->APB1ENR |= (1 << 2);
        }
        else if(pTIM == TIM5)
        {
            RCC->APB1ENR |= (1 << 3);
        }
    }
    else if(Action == DISABLE)
    {
        if(pTIM == TIM2)
        {
            RCC->APB1ENR &= ~(1 << 0);
        }
        else if(pTIM == TIM3)
        {
            RCC->APB1ENR &= ~(1 << 1);
        }
        else if(pTIM == TIM4)
        {
            RCC->APB1ENR &= ~(1 << 2);
        }
        else if(pTIM == TIM5)
        {
            RCC->APB1ENR &= ~(1 << 3);
        }
    }
}



//TODO
/*
void I2CxClockControl(I2C_t* pI2C, uint8_t Action)
{
    if(Action == ENABLE)
    {
        if(pTIM == TIM2)
        {
            RCC->APB1ENR |= (1 << 0);
        }
        else if(pTIM == TIM5)
        {
            RCC->APB1ENR |= (1 << 1);
        }
        else if(pTIM == TIM4)
        {
            RCC->APB1ENR |= (1 << 2);
        }
        else if(pTIM == TIM5)
        {
            RCC->APB1ENR |= (1 << 3);
        }
    }
    else if(Action == DISABLE)
    {
        if(pTIM == TIM2)
        {
            RCC->APB1ENR &= ~(1 << 0);
        }
        else if(pTIM == TIM5)
        {
            RCC->APB1ENR &= ~(1 << 1);
        }
        else if(pTIM == TIM4)
        {
            RCC->APB1ENR &= ~(1 << 2);
        }
        else if(pTIM == TIM5)
        {
            RCC->APB1ENR &= ~(1 << 3);
        }
    }
}


*/
void USARTxClockControl(USART_t* pUSART, uint8_t Action)
{
    if(Action == ENABLE)
    {
        if(pUSART == USART1)
        {
            RCC->APB2ENR |= (1 << 4);
        }
        else if(pUSART == USART2)
        {
            RCC->APB1ENR |= (1 << 17);
        }
        else if(pUSART == USART6)
        {
            RCC->APB2ENR |= (1 << 5);
        }
    }
    
    if(Action == DISABLE)
    {
        if(pUSART == USART1)
        {
            RCC->APB2ENR &= ~(1 << 4);
        }
        else if(pUSART == USART2)
        {
            RCC->APB1ENR &= ~(1 << 17);
        }
        else if(pUSART == USART6)
        {
            RCC->APB2ENR &= ~(1 << 5);
        }
    }
    
}


