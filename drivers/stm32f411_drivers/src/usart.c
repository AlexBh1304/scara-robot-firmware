#define USING_STM32F411
#include "usart.h"

void USARTInit(USART_t* pUSART, USART_Config* pConfig)
{
    //Baud rate
    //pUSART->BRR = 0b0000011010000010;
    pUSART->BRR = 0b0000101000101100;
    pUSART->CR1 |= (1 << 13);
    pUSART->CR1 |= (1 << 3);
}
void UsartSendByte(uint8_t* byte,USART_t* pUSART)
{
    while(!(pUSART->SR & (1<<7)));
    pUSART->DR = *byte;

}
void UsartRxByte(uint8_t* byte,USART_t* pUSART)
{

}
uint8_t UsartFlagStatus(uint8_t usartflag,USART_t* pUSART)
{
    return 0;
}


