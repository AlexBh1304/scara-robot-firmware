#define USING_STM32F411

#include "gpio.h"
#include "rcc.h"

void Gpio_Init(GPIOx_Config_t* pGpioConfig, GPIO_t* pGPIO)
{
    //Enable Peripheral Clock
    GPIOxClockControl(pGPIO, ENABLE);

    //Configure port mode register
    pGPIO->MODER &= ~(0b11<<((pGpioConfig->Pin * 2)));
    pGPIO->MODER |= (((pGpioConfig->Mode) & 0b11)<<((pGpioConfig->Pin * 2)));

    if(pGpioConfig->Mode & 0b1000)
    {
        //Output type
        pGPIO->OTYPER &= ~(1 << pGpioConfig->Pin);           
        pGPIO->OTYPER |= ((((pGpioConfig->Mode) & 0b100) >> 2) << pGpioConfig->Pin);           
        
        //Output speed
        pGPIO->OSPEEDR &= ~(0b11 << (pGpioConfig->Pin * 2));           
        pGPIO->OSPEEDR |= ((pGpioConfig->OutputSpeed) << (pGpioConfig->Pin * 2));           
    }
    
    if(pGpioConfig->Mode & ALTERNATE_FUNCTION_MODE)
    {
        //Output type
        //pGpioConfig->AFOutputType = 1;
        pGPIO->OTYPER &= ~((0b1) << (pGpioConfig->Pin));
        pGPIO->OTYPER |= ((pGpioConfig->AFOutputType) << (pGpioConfig->Pin));

        if(pGpioConfig->Pin <= GPIO_PIN7)
        {
            //Low Register
            pGPIO->AFRL &= ~((0b1111) << (pGpioConfig->Pin * 4));
            pGPIO->AFRL |= ((pGpioConfig->AFNumber) << (pGpioConfig->Pin * 4));
        }
        else if(pGpioConfig->Pin >= GPIO_PIN8)
        {
            //High Register
            pGPIO->AFRH &= ~((0b1111) << (((pGpioConfig->Pin) % 8) * 4));
            pGPIO->AFRH |= ((pGpioConfig->AFNumber) << (((pGpioConfig->Pin) % 8) * 4));
        }
    }

    //Pull control
    pGPIO->PUPDR &= ~(0b11 << (pGpioConfig->Pin *2));
    pGPIO->PUPDR |= (pGpioConfig->PullOption << (pGpioConfig->Pin *2));
    
}

void Gpio_Pin_Set(GPIO_t* pGPIO, uint8_t PinNumber)
{
    pGPIO->BSRR = (1 << PinNumber);
}

void Gpio_Pin_Reset(GPIO_t* pGPIO, uint8_t PinNumber)
{
    pGPIO->BSRR = (1 << (PinNumber + 16));
}

void Gpio_Pin_Toggle(GPIO_t* pGPIO, uint8_t PinNumber)
{
    if((pGPIO->ODR) & (1 << PinNumber))
    {
        pGPIO->BSRR = (1 << (PinNumber + 16));
    }

    else
    {
        pGPIO->BSRR = (1 << PinNumber);
    }
}
