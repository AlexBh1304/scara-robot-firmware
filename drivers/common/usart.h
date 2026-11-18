#ifndef USART_H
#define USART_H
#include <stdint.h>

#ifdef USING_STM32F411

#include "stm32f411.h"

typedef struct
{
    uint8_t DataSize;
    uint8_t Parity;
    uint8_t NoStopBits;
    uint16_t Baudrate;

}USART_Config;


#endif /*USING_STM32F411*/


void USARTInit(USART_t* pUSART, USART_Config* pConfig);

void UsartSendByte(USART_t* pUSART, uint8_t* byte, uint8_t amount);
//void UsartSendByte(uint8_t* byte,USART_t* pUSART );
void UsartRxByte(USART_t* pUSART, uint8_t* byte, uint8_t amount);
//void UsartRxByte(USART_t* pUSART, uint8_t* byte);
uint8_t UsartFlagStatus(uint8_t usartflag,USART_t* pUSART);

//Options for Data Size 
#define DATA_BITS_8     0
#define DATA_BITS_9     1

//Options for Parity
#define EVEN_PARITY     0
#define ODD_PARITY      1
#define NO_PARITY       2

//Options for StopBits
#define STOP_BITS_1     0
#define STOP_BITS_0_5   1
#define STOP_BITS_2     2
#define STOP_BITS_1_5   3

//Options for BaudRate
#define BD9600          0b1101000001

////Flag masks
//
//#define USART_TXE_FLAG  (1 << 7)
//#define USART_RXNE_FLAG  (1 << 5)

#endif /*USART_H*/
