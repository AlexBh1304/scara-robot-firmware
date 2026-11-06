#include "stm32f411.h"
#include <stdint.h>

int main()
{


    //Change clock to hse
    RCC->CR |= (1 << 16);
    while(!(RCC->CR &(1 << 17)));
    RCC->CFGR |= (0b01);
    
    
    USART_Config usartconfig;
    
    char byte[]= "HOLA\n";

    uint8_t* pBytepointer = byte;
    RCC->APB2ENR |= (1 << 4);
    

    USART_t* pPointer = USART1;
    GPIOx_Config_t gpioconfig;
    GPIOxClockControl(GPIOA, ENABLE);
    GPIOA->AFRH |= (0b111 << 4);

    gpioconfig.Pin = GPIO_PIN9;
    gpioconfig.Mode = ALTERNATE_FUNCTION_MODE;             
    Gpio_Init(&gpioconfig,GPIOA);

    USARTInit(USART1, &usartconfig);
    
    UsartSendByte(pBytepointer, USART1);   
    pBytepointer++;
    UsartSendByte(pBytepointer, USART1);   
    pBytepointer++;
    UsartSendByte(pBytepointer, USART1);   
    pBytepointer++;
    UsartSendByte(pBytepointer, USART1);   
    pBytepointer++;
    UsartSendByte(pBytepointer, USART1);   
    pBytepointer = (uint8_t*)byte;
    
    while(1);


    return 0;
}
