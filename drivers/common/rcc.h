/**
 * @brief Functions to enable peripheral clocks
 */

#ifndef RCC_H
#define RCC_H

#include <stdint.h>


#ifdef USING_STM32F411

#ifndef STM32F411_H 
#include "stm32f411.h"
#include "tim.h"
#include "gpio.h"
#endif /*STM32F411_H */

#endif /*USING_STM32F411*/

#ifdef USING_STM32F1XX

#ifndef STM32F1XX_H
#include "stm32f1xx.h"
#include "gpio.h"
#include "tim.h"
#endif /*STM32F1XX_H*/

#endif /*USING_STM32F1XX*/

typedef struct  
{
    uint8_t TargetClockSource;
    //Pll multiplier?
}ClockConfig_t;


void GPIOxClockControl(GPIO_t* pGPIO, uint8_t Action);
void TIMxClockControl(TIM_t* pTIM, uint8_t Action);
void I2CxClockControl(I2C_t* pI2C, uint8_t Action);
void USARTxClockControl(USART_t* pUSART, uint8_t Action);
//void ADCxClockControl(ADC_t* pADC, uint8_t Action);
void ChangeClockSource(ClockConfig_t* clockconfig);

// TargetClockSource options
#define HSI 0
#define HSE 1
#define PLL_HSE 2
#define PLL_HSI 3

#endif /*RCC_H*/
