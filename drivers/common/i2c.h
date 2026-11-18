#ifndef I2C_H
#define I2C_H

#include <stdint.h>

#ifdef USING_STM32F411
#include "stm32f411.h"

typedef struct
{
    uint8_t SCL_AFNumber;
    uint8_t SCL_PinNumber;
    GPIO_t* SCL_PinPort;
    uint8_t SDA_AFNumber;
    uint8_t SDA_PinNumber;
    GPIO_t* SDA_PinPort;
    uint8_t PullUp;
    uint8_t I2C_Mode;
}I2C_Config_t;

void I2Cx_Init(I2C_t* I2Cx, I2C_Config_t* I2C_Config);
void GenerateStartCondition(I2C_t* I2Cx);
void GenerateStopCondition(I2C_t* I2Cx);
void MasterSendAddress(I2C_t* I2Cx, uint8_t deviceAddress, uint8_t Mode); //Where mode is write or read
void MasterSendData(I2C_t* I2Cx, uint8_t data); 
void MasterReadData(I2C_t* I2Cx, uint8_t* data, uint8_t amount); 


#define I2C_MASTER_WRITE ((uint8_t)0)
#define I2C_MASTER_READ ((uint8_t)1)

/* I2C modes options*/
#define I2C_STANDARD_MODE ((uint8_t)0)
#define I2C_FAST_MODE ((uint8_t)1)

#endif /*USING_STM32F411*/


#endif /*I2C_H*/
