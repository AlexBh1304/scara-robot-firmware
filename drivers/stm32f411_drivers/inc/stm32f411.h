#ifndef STM32F411_H
#define STM32F411_H
#define USING_STM32F411

#define ENABLE  1
#define DISABLE  0

#include <stdint.h>


typedef struct
{
    uint32_t MODER;
    uint32_t OTYPER;
    uint32_t OSPEEDR;
    uint32_t PUPDR;
    uint32_t IDR;
    uint32_t ODR;
    uint32_t BSRR;
    uint32_t LCKR;
    uint32_t AFRL;
    uint32_t AFRH;
}GPIO_t;

#define GPIOA_BASE_ADDRESS 0x40020000
#define GPIOB_BASE_ADDRESS 0x40020400
#define GPIOC_BASE_ADDRESS 0x40020800
#define GPIOD_BASE_ADDRESS 0x40020C00

#define GPIOA ((GPIO_t*)GPIOA_BASE_ADDRESS)
#define GPIOB ((GPIO_t*)GPIOB_BASE_ADDRESS)
#define GPIOC ((GPIO_t*)GPIOC_BASE_ADDRESS)
#define GPIOD ((GPIO_t*)GPIOD_BASE_ADDRESS)


typedef struct
{
    uint32_t CR;
    uint32_t PLLCFGR;
    uint32_t CFGR;
    uint32_t CIR;
    uint32_t AHB1RSTR;
    uint32_t AHB2RSTR;
    uint32_t Reserved1;
    uint32_t Reserved2;
    uint32_t APB1RSTR;
    uint32_t APB2RSTR;
    uint32_t Reserved3;
    uint32_t Reserved4;
    uint32_t AHB1ENR;
    uint32_t AHB2ENR;
    uint32_t Reserved5;
    uint32_t Reserved6;
    uint32_t APB1ENR;
    uint32_t APB2ENR;
    uint32_t Reserved7;
    uint32_t Reserved8;
    uint32_t AHB1LPENR;
    uint32_t AHB2LPENR;
    uint32_t Reserved9;
    uint32_t Reserved10;
    uint32_t APB1LPENR;
    uint32_t APB2LPENR;
    uint32_t Reserved11;
    uint32_t Reserved12;
    uint32_t BDCR;
    uint32_t CSR;
    uint32_t Reserved13;
    uint32_t Reserved14;
    uint32_t SSCGR;
    uint32_t PLLI2SCFGR;
    uint32_t Reserved15;
    uint32_t DCKCFGR;

}RCC_t;


#define RCC_BASE_ADDRESS    (0x40023800)
#define RCC     ((RCC_t*)RCC_BASE_ADDRESS)

typedef struct
{
    uint32_t SR;
    uint32_t DR;
    uint32_t BRR;
    uint32_t CR1;
    uint32_t CR2;
    uint32_t CR3;
    uint32_t GTPR;
}USART_t;

#define USART1_BASE_ADDRESS (0x40011000)
#define USART2_BASE_ADDRESS (0x40004400)
#define USART6_BASE_ADDRESS (0x40011400)

#define USART1  ((USART_t*)USART1_BASE_ADDRESS)
#define USART2  ((USART_t*)USART2_BASE_ADDRESS)
#define USART6  ((USART_t*)USART6_BASE_ADDRESS)

typedef struct
{
    uint32_t CR1;
    uint32_t CR2;
    uint32_t OAR1;
    uint32_t OAR2;
    uint32_t DR;
    uint32_t SR1;
    uint32_t SR2;
    uint32_t CCR;
    uint32_t TRISE;
    uint32_t FLTR;
}I2C_t;

#define I2C1_BASE_ADDRESS (0x40005400)
#define I2C2_BASE_ADDRESS (0x40005800)
#define I2C3_BASE_ADDRESS (0x40005C00)

#define I2C1  ((I2C_t*)I2C1_BASE_ADDRESS)
#define I2C2  ((I2C_t*)I2C2_BASE_ADDRESS)
#define I2C3  ((I2C_t*)I2C3_BASE_ADDRESS)

typedef struct 
{
    uint32_t    CR1;
    uint32_t    CR2;
    uint32_t    SMCR;
    uint32_t    DIER;
    uint32_t    SR;
    uint32_t    EGR;
    uint32_t    CCMR1;
    uint32_t    CCMR2;
    uint32_t    CCER;
    uint32_t    CNT;
    uint32_t    PSC;
    uint32_t    ARR;
    uint32_t    RESERVED0;
    uint32_t    CCR1;
    uint32_t    CCR2;
    uint32_t    CCR3;
    uint32_t    CCR4;
    uint32_t    RESERVED1;
    uint32_t    DCR;
    uint32_t    DMAR;
    uint32_t    TIM2_OR;
}TIM_t;

#define TIM2_BASE_ADDRESS   (0x40000000)
#define TIM3_BASE_ADDRESS   (0x40000400)
#define TIM4_BASE_ADDRESS   (0x40000800)
#define TIM5_BASE_ADDRESS   (0x40000C00)

#define TIM2    ((TIM_t*)TIM2_BASE_ADDRESS)
#define TIM3    ((TIM_t*)TIM3_BASE_ADDRESS)
#define TIM4    ((TIM_t*)TIM4_BASE_ADDRESS)
#define TIM5    ((TIM_t*)TIM5_BASE_ADDRESS)


#include "gpio.h"
#include "rcc.h"
#include "usart.h"
#include "tim.h"
//#include "i2c.h"


#endif

