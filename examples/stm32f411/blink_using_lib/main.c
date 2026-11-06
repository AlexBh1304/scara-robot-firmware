#include "stm32f411.h"
#include <stdint.h>

int main()
{
    
    GPIO_t* pointerlol = GPIOC;
    GPIOx_Config_t LedConfig;
    LedConfig.Pin = GPIO_PIN13;
    LedConfig.Mode = GENERAL_PURPOSE_OUTPUT_PP_MODE;      
    LedConfig.OutputSpeed = HIGH_OUTPUT_SPEED;                   
    LedConfig.PullOption = NO_PU_PD;                            
    
    GPIOxClockControl(GPIOC,ENABLE);

    Gpio_Init(&LedConfig, pointerlol);

    while(1)
    {
        for(volatile uint32_t i = 0; i < 500000; i++);
        Gpio_Pin_Toggle(GPIOC, GPIO_PIN13);
    }

    return 0;
}
