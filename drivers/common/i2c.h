#ifndef I2C_H
#define I2C_H

#include <stdint.h>

#ifdef USING_STM32F411
#include "stm32f411.h"

typedef struct
{
    uint32_t ClockSpeed; 

}I2C_Config_t;



#endif /*USING_STM32F411*/


#endif /*I2C_H*/
