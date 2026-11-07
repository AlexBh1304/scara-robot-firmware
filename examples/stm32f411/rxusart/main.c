#include "stm32f411.h"
#define ANGLE   1024
#define TOLERANCE   5

void USART_INIT();

int main()
{
    USART_INIT();
    uint8_t data;
    uint8_t rxdata;
    uint8_t data1;
    uint16_t raw_angle;
    uint16_t lower;
    uint16_t higher;
    uint32_t temp;
    //change clock to hse   
    RCC->CR |= (1 << 16);
    while(!(RCC->CR &(1 << 17)));
    RCC->CFGR |= (0b01);

    
    rxdata = 0xFF;

    while(1)
    {
        UsartRxByte(&rxdata, USART1);   
        UsartSendByte(&rxdata, USART1);   
        for(volatile uint32_t i=0; i<500000; i++);
    }


    while(1);
    return 0;
}

void USART_INIT()
{
    USART_Config usartconfig;

    USARTxClockControl(USART1, ENABLE);
    GPIOxClockControl(GPIOA, ENABLE);

    GPIOx_Config_t txconfig;
    txconfig.AFNumber = AF07;
    txconfig.Pin = GPIO_PIN9;
    txconfig.Mode = ALTERNATE_FUNCTION_MODE;             

    Gpio_Init(&txconfig,GPIOA);

    GPIOx_Config_t rxconfig;
    rxconfig.AFNumber = AF07;
    rxconfig.Pin = GPIO_PIN10;
    rxconfig.Mode = ALTERNATE_FUNCTION_MODE;             
 
    Gpio_Init(&rxconfig,GPIOA);


    USARTInit(USART1, &usartconfig);
}


//void USART_INIT()
//{
//    USART_Config usartconfig;
//    RCC->APB2ENR |= (1 << 4);
//    USART_t* pPointer = USART1;
//    GPIOx_Config_t gpioconfig;
//    GPIOxClockControl(GPIOA, ENABLE);
//    GPIOA->AFRH |= (0b111 << 4);
//    gpioconfig.Pin = GPIO_PIN9;
//    gpioconfig.Mode = ALTERNATE_FUNCTION_MODE;             
//    Gpio_Init(&gpioconfig,GPIOA);
//    USARTInit(USART1, &usartconfig);
//}

