#include <stdint.h>

//We must save this variable at adress 0, as this will be the value to load into the stack pointer register

uint32_t endofram __attribute__ ((section (".vector_table"))) = 0x20020000;
uint32_t main();

void Default_Handler(void)
{
    while(1);
}

void Reset_Handler(void)
{
    //Copy global, static, and initilized variables to ram
    
    //Set to cero the bss section on ram
    
    //Call main

    main();
}
void (*const pReset_Handler) = Reset_Handler; 

void __attribute__((weak)) NMI_Handler(void)
{
    Default_Handler();
}
void (*const pNMI_Handler) = NMI_Handler;

void __attribute__((weak)) MemManage_Handler(void)
{
    Default_Handler();
}

void (*const pMemManage_Handler) = MemManage_Handler;

void __attribute__((weak)) BusFault_Handler(void)
{
    Default_Handler();
}
void (*const pBusFault_Handler) = BusFault_Handler;

void  __attribute__((weak))UsageFault_Handler (void)
{
    Default_Handler();
}
void (*const pUsageFault_Handler) = UsageFault_Handler; 

void __attribute__((weak)) SVCall_Handler(void)
{
    Default_Handler();
}
void (*const pSVCall_Handler) = SVCall_Handler; 

void __attribute__((weak)) Debug_Monitor_Handler(void)
{
    Default_Handler();
}
void (*const pDebug_Monitor_Handler) = Debug_Monitor_Handler; 

void __attribute__((weak)) PendSV_Handler(void)
{
    Default_Handler();
}

void (*const pPendSV_Handler) = PendSV_Handler; 

void __attribute__((weak)) Systick_Handler(void)
{
    Default_Handler();
}
void (*const pSystick_Handler)= Systick_Handler; 

void __attribute__((weak)) WWDG_IRQHandler(void)
{
    Default_Handler();
}
void (*const pWWDG_IRQHandler) = WWDG_IRQHandler; 

void __attribute__((weak))EXTI16_IRQHandler(void)
{
    Default_Handler();
}
void (*const pEXTI16_IRQHandler) = EXTI16_IRQHandler; 

void __attribute__((weak))EXTI21_IRQHandler(void)
{
    Default_Handler();
}
void (*const pEXTI21_IRQHandler) = EXTI21_IRQHandler; 

void __attribute__((weak))EXTI22_IRQHandler(void)
{
    Default_Handler();
}
void (*const pEXTI22_IRQHandler) = EXTI22_IRQHandler; 

void __attribute__((weak))FLASH_IRQHandler(void)
{
    Default_Handler();
}
void (*const pFLASH_IRQHandler) = FLASH_IRQHandler; 

void __attribute__((weak))RCC_IRQHandler(void)
{
    Default_Handler();
}
void (*const pRCC_IRQHandler) = RCC_IRQHandler; 

void __attribute__((weak))EXTI0_IRQHandler(void)
{
    Default_Handler();
}
void (*const pEXTI0_IRQHandler) = EXTI0_IRQHandler; 

void __attribute__((weak))EXTI1_IRQHandler(void)
{
    Default_Handler();
}
void (*const pEXTI1_IRQHandler) = EXTI1_IRQHandler; 

void __attribute__((weak))EXTI2_IRQHandler(void)
{
    Default_Handler();
}

void (*const pEXTI2_IRQHandler) = EXTI2_IRQHandler; 

void __attribute__((weak))EXTI3_IRQHandler(void)
{
    Default_Handler();
}
void (*const pEXTI3_IRQHandler) = EXTI3_IRQHandler; 

void __attribute__((weak))EXTI4_IRQHandler(void)
{
    Default_Handler();
}
void (*const pEXTI4_IRQHandler) = EXTI4_IRQHandler; 

void __attribute__((weak))DMA1_Stream0_IRQHandler(void)
{
    Default_Handler();
}
void (*const pDMA1_Stream0_IRQHandler) = DMA1_Stream0_IRQHandler; 

void __attribute__((weak))DMA1_Stream1_IRQHandler(void)
{
    Default_Handler();
}
void (*const pDMA1_Stream1_IRQHandler) = DMA1_Stream1_IRQHandler; 

void __attribute__((weak))DMA1_Stream2_IRQHandler(void)
{
    Default_Handler();
}
void (*const pDMA1_Stream2_IRQHandler) = DMA1_Stream2_IRQHandler; 

void __attribute__((weak))DMA1_Stream3_IRQHandler(void)
{
    Default_Handler();
}
void (*const pDMA1_Stream3_IRQHandler) = DMA1_Stream3_IRQHandler; 

void __attribute__((weak))DMA1_Stream4_IRQHandler(void)
{
    Default_Handler();
}
void (*const pDMA1_Stream4_IRQHandler) = DMA1_Stream4_IRQHandler; 

void __attribute__((weak))DMA1_Stream5_IRQHandler(void)
{
    Default_Handler();
}
void (*const pDMA1_Stream5_IRQHandler) = DMA1_Stream5_IRQHandler; 

void __attribute__((weak))DMA1_Stream6_IRQHandler(void)
{
    Default_Handler();
}
void (*const pDMA1_Stream6_IRQHandler) = DMA1_Stream6_IRQHandler; 

void __attribute__((weak))ADC_IRQHandler(void)
{
    Default_Handler();
}
void (*const pADC_IRQHandler) = ADC_IRQHandler; 

void __attribute__((weak))EXTI9_5_IRQHandler(void)
{
    Default_Handler();
}
void (*const pEXTI9_5_IRQHandler) = EXTI9_5_IRQHandler; 

void __attribute__((weak))TIM1_BRK_TIM9_IRQHandler(void)
{
    Default_Handler();
}
void (*const pTIM1_BRK_TIM9_IRQHandler) = TIM1_BRK_TIM9_IRQHandler ; 

void __attribute__((weak))TIM1_UP_TIM10_IRQHandler(void)
{
    Default_Handler();
}
void (*const pTIM1_UP_TIM10_IRQHandler) = TIM1_UP_TIM10_IRQHandler; 

void __attribute__((weak))TIM1_TRG_COM_TIM11_IRQHandler(void)
{
    Default_Handler();
}
void (*const pTIM1_TRG_COM_TIM11_IRQHandler) = TIM1_TRG_COM_TIM11_IRQHandler; 

void __attribute__((weak))TIM1_CC_IRQHandler(void)
{
    Default_Handler();
}
void (*const pTIM1_CC_IRQHandler) = TIM1_CC_IRQHandler; 

void __attribute__((weak))TIM2_IRQHandler(void)
{
    Default_Handler();
}
void (*const pTIM2_IRQHandler) = TIM2_IRQHandler; 

void __attribute__((weak))TIM3_IRQHandler(void)
{
    Default_Handler();
}
void (*const pTIM3_IRQHandler) = TIM3_IRQHandler; 

void __attribute__((weak))TIM4_IRQHandler(void)
{
    Default_Handler();
}
void (*const pTIM4_IRQHandler) = TIM4_IRQHandler; 

void __attribute__((weak))I2C1_EV_IRQHandler(void)
{
    Default_Handler();
}
void (*const pI2C1_EV_IRQHandler) = I2C1_EV_IRQHandler; 

void __attribute__((weak))I2C1_ER_IRQHandler(void)
{
    Default_Handler();
}
void (*const pI2C1_ER_IRQHandler) = I2C1_ER_IRQHandler; 

void __attribute__((weak))I2C2_EV_IRQHandler(void)
{
    Default_Handler();
}
void (*const pI2C2_EV_IRQHandler) = I2C2_EV_IRQHandler; 

void __attribute__((weak))I2C2_ER_IRQHandler(void)
{
    Default_Handler();
}
void (*const pI2C2_ER_IRQHandler) = I2C2_ER_IRQHandler; 

void __attribute__((weak))SPI1_IRQHandler(void)
{
    Default_Handler();
}
void (*const pSPI1_IRQHandler) = SPI1_IRQHandler; 

void __attribute__((weak))SPI2_IRQHandler(void)
{
    Default_Handler();
}
void (*const pSPI2_IRQHandler) = SPI2_IRQHandler; 

void __attribute__((weak))USART1_IRQHandler(void)
{
    Default_Handler();
}
void (*const pUSART1_IRQHandler) = USART1_IRQHandler; 

void __attribute__((weak))USART2_IRQHandler(void)
{
    Default_Handler();
}
void (*const pUSART2_IRQHandler) = USART2_IRQHandler; 

void __attribute__((weak))EXTI15_10_IRQHandler(void)
{
    Default_Handler();
}
void (*const pEXTI15_10_IRQHandler) = EXTI15_10_IRQHandler; 

void __attribute__((weak))EXTI17_IRQHandler(void)
{
    Default_Handler();
}
void (*const pEXTI17_IRQHandler) = EXTI17_IRQHandler; 

void __attribute__((weak))EXTI18_IRQHandler(void)
{
    Default_Handler();
}
void (*const pEXTI18_IRQHandler) = EXTI18_IRQHandler; 

void __attribute__((weak))DMA1_Stream7_IRQHandler(void)
{
    Default_Handler();
}
void (*const pDMA1_Stream7_IRQHandler) = DMA1_Stream7_IRQHandler; 

void __attribute__((weak))SDIO_IRQHandler(void)
{
    Default_Handler();
}
void (*const pSDIO_IRQHandler) = SDIO_IRQHandler; 

void __attribute__((weak))TIM5_IRQHandler(void)
{
    Default_Handler();
}
void (*const pTIM5_IRQHandler) = TIM5_IRQHandler; 

void __attribute__((weak))SPI3_IRQHandler(void)
{
    Default_Handler();
}
void (*const pSPI3_IRQHandler) = SPI3_IRQHandler; 

void __attribute__((weak))DMA2_Stream0_IRQHandler(void)
{
    Default_Handler();
}
void (*const pDMA2_Stream0_IRQHandler) = DMA2_Stream0_IRQHandler; 

void __attribute__((weak))DMA2_Stream1_IRQHandler(void)
{
    Default_Handler();
}
void (*const pDMA2_Stream1_IRQHandler) = DMA2_Stream1_IRQHandler; 

void __attribute__((weak))DMA2_Stream2_IRQHandler(void)
{
    Default_Handler();
}
void (*const pDMA2_Stream2_IRQHandler) = DMA2_Stream2_IRQHandler; 

void __attribute__((weak))DMA2_Stream3_IRQHandler(void)
{
    Default_Handler();
}
void (*const pDMA2_Stream3_IRQHandler) = DMA2_Stream3_IRQHandler; 

void __attribute__((weak))DMA2_Stream4_IRQHandler(void)
{
    Default_Handler();
}
void (*const pDMA2_Stream4_IRQHandler) = DMA2_Stream4_IRQHandler; 

void __attribute__((weak))OTG_FS_IRQHandler(void)
{
    Default_Handler();
}
void (*const pOTG_FS_IRQHandler) = OTG_FS_IRQHandler; 

void __attribute__((weak))DMA2_Stream5_IRQHandler(void)
{
    Default_Handler();
}
void (*const pDMA2_Stream5_IRQHandler) = DMA2_Stream5_IRQHandler; 

void __attribute__((weak))DMA2_Stream6_IRQHandler(void)
{
    Default_Handler();
}
void (*const pDMA2_Stream6_IRQHandler) = DMA2_Stream6_IRQHandler; 

void __attribute__((weak))DMA2_Stream7_IRQHandler(void)
{
    Default_Handler();
}
void (*const pDMA2_Stream7_IRQHandler) = DMA2_Stream7_IRQHandler; 

void __attribute__((weak))USART6_IRQHandler(void)
{
    Default_Handler();
}
void (*const pUSART6_IRQHandler) = USART6_IRQHandler; 

void __attribute__((weak))I2C3_EV_IRQHandler(void)
{
    Default_Handler();
}
void (*const pI2C3_EV_IRQHandler) = I2C3_EV_IRQHandler; 

void __attribute__((weak))I2C3_ER_IRQHandler(void)
{
    Default_Handler();
}
void (*const pI2C3_ER_IRQHandler) = I2C3_ER_IRQHandler; 

void __attribute__((weak))FPU_IRQHandler(void)
{
    Default_Handler();
}
void (*const pFPU_IRQHandler) = FPU_IRQHandler; 

void __attribute__((weak))SPI4_IRQHandler(void)
{
    Default_Handler();
}
void (*const pSPI4_IRQHandler) = SPI4_IRQHandler; 

void __attribute__((weak))SPI5_IRQHandler(void)
{
    Default_Handler();
}
void (*const pSPI5_IRQHandler) = SPI5_IRQHandler; 


const void* __attribute__((section(".vector_table")))VectorTable[71] = 
{
    pReset_Handler,
    pNMI_Handler,
    pMemManage_Handler,
    pBusFault_Handler,
    pUsageFault_Handler,
    (void*)0,
    (void*)0,
    (void*)0,
    (void*)0,
    pSVCall_Handler,
    pDebug_Monitor_Handler,
    (void*)0,
    pPendSV_Handler,
    pSystick_Handler,
    pWWDG_IRQHandler,
    pEXTI16_IRQHandler,
    pEXTI21_IRQHandler,
    pEXTI22_IRQHandler,
    pFLASH_IRQHandler,
    pRCC_IRQHandler,
    pEXTI0_IRQHandler,
    pEXTI1_IRQHandler,
    pEXTI2_IRQHandler,
    pEXTI3_IRQHandler,
    pEXTI4_IRQHandler,
    pDMA1_Stream0_IRQHandler,
    pDMA1_Stream1_IRQHandler,
    pDMA1_Stream2_IRQHandler,
    pDMA1_Stream3_IRQHandler, 
    pDMA1_Stream4_IRQHandler, 
    pDMA1_Stream5_IRQHandler, 
    pDMA1_Stream6_IRQHandler, 
    pADC_IRQHandler, 
    pEXTI9_5_IRQHandler, 
    pTIM1_BRK_TIM9_IRQHandler, 
    pTIM1_UP_TIM10_IRQHandler,
    pTIM1_TRG_COM_TIM11_IRQHandler,
    pTIM1_CC_IRQHandler,
    pTIM2_IRQHandler,
    pTIM3_IRQHandler,
    pTIM4_IRQHandler,
    pI2C1_EV_IRQHandler,
    pI2C1_ER_IRQHandler,
    pI2C2_EV_IRQHandler,
    pI2C2_ER_IRQHandler,
    pSPI1_IRQHandler,
    pSPI2_IRQHandler,
    pUSART1_IRQHandler,
    pUSART2_IRQHandler,
    pEXTI15_10_IRQHandler,
    pEXTI17_IRQHandler,
    pEXTI18_IRQHandler,
    pDMA1_Stream7_IRQHandler,
    pSDIO_IRQHandler,
    pTIM5_IRQHandler,
    pSPI3_IRQHandler,  
    pDMA2_Stream0_IRQHandler,
    pDMA2_Stream1_IRQHandler,
    pDMA2_Stream2_IRQHandler,
    pDMA2_Stream3_IRQHandler,
    pDMA2_Stream4_IRQHandler,
    pOTG_FS_IRQHandler,
    pDMA2_Stream5_IRQHandler,
    pDMA2_Stream6_IRQHandler,
    pDMA2_Stream7_IRQHandler,
    pUSART6_IRQHandler,
    pI2C3_EV_IRQHandler,
    pI2C3_ER_IRQHandler,
    pFPU_IRQHandler,
    pSPI4_IRQHandler,
    pSPI5_IRQHandler
};
