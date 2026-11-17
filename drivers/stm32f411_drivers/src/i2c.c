#define USING_STM32F411
#include "i2c.h"

void GenerateStartCondition(I2C_t* I2Cx)
{
    //Generate Start condition
    I2Cx->CR1 |= (1 << I2Cx_CR1_START);
    //Wait until the StartBit flag is set
    while(!(I2Cx->SR1 & SR1_SB_FLAGMASK));
}

void MasterSendAddress(I2C_t* I2Cx, uint8_t deviceAddress, uint8_t Mode)//Where mode is write or read
{
    //Clear StartBit Flag
    uint16_t temp;
    temp = I2Cx->SR1;
    //Write Address in the data Register
    I2Cx->DR = ((deviceAddress << 1) | (Mode));
    //Wait until the ADDR flag is set (Address has been sent and Acknowledged)
    while(!(I2Cx->SR1 & SR1_ADDR_FLAGMASK));
}

void MasterSendData(I2C_t* I2Cx, uint8_t data)
{
    //Clear ADDR flag
    uint16_t temp;
    temp = I2Cx->SR1;
    temp = I2Cx->SR2;
    //Write Data to Data register
    I2Cx->DR = data;
}

void GenerateStopCondition(I2C_t* I2Cx)
{
    I2Cx->CR1 |= (1 << I2Cx_CR1_STOP);
}


void MasterReadData(I2C_t* I2Cx, uint8_t* data, uint8_t amount)
{
    if(amount == 1)
    {
        //Clear ADDR flag
        uint16_t temp;
        temp = I2Cx->SR1;
        temp = I2Cx->SR2;
        while(!(I2Cx->SR1 & SR1_RXNE_FLAGMASK));
        *data = I2Cx->DR;
    }
    if(amount == 2)
    {
        //Set ACK low 
        I2Cx->CR1 &= ~(1 << I2Cx_CR1_ACK);
        //Set POS high
        I2Cx->CR1 |= (1 << I2Cx_CR1_POS);
        //Clear ADDR flag
        uint16_t temp;
        temp = I2Cx->SR1;
        temp = I2Cx->SR2;
        //Wait until BTF = 1
        while(!(I2Cx->SR1 & SR1_BTF_FLAGMASK));
        //Set STOP high
        I2Cx->CR1 |= (1 << I2Cx_CR1_STOP);
        //ReadData one and data two

        *data = I2Cx->DR;
        data++;
        *data = I2Cx->DR;
    }
}
