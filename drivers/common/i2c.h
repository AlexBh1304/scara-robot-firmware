#ifndef I2C_H
#define I2C_H

#include <stdint.h>

#ifdef USING_STM32F411
#include "stm32f411.h"

typedef struct
{
    uint32_t ClockSpeed; 

}I2C_Config_t;

void GenerateStartCondition(I2C_t I2C);
void MasterSendAddress(I2C_t I2C, uint8_t deviceAddress);




#endif /*USING_STM32F411*/


#endif /*I2C_H*/
