#include "stm32f411.h"
#include "as5600.h"

void I2C1_Init();
int main()
{
    //change clock to hse   
    RCC->CR |= (1 << 16);
    while(!(RCC->CR &(1 << 17)));
    RCC->CFGR |= (0b01);

    I2C_Config_t I2C_Config = {0};
    
    I2C_Config.SCL_AFNumber = AF04;
    I2C_Config.SCL_PinNumber = GPIO_PIN6;
    I2C_Config.SCL_PinPort = GPIOB;
    I2C_Config.SDA_AFNumber = AF04;
    I2C_Config.SDA_PinNumber = GPIO_PIN7;
    I2C_Config.SDA_PinPort = GPIOB;
    I2C_Config.PullUp = DISABLE;
    I2C_Config.I2C_Mode = I2C_STANDARD_MODE;
    
    I2Cx_Init(I2C1, &I2C_Config);

    I2C_Config_t I2C_Config2 = {0};
    I2C_Config2.SCL_AFNumber = AF04;
    I2C_Config2.SCL_PinNumber = GPIO_PIN10;
    I2C_Config2.SCL_PinPort = GPIOB;
    I2C_Config2.SDA_AFNumber = AF09;
    I2C_Config2.SDA_PinNumber = GPIO_PIN3;
    I2C_Config2.SDA_PinPort = GPIOB;
    I2C_Config2.PullUp = DISABLE;
    I2C_Config2.I2C_Mode = I2C_STANDARD_MODE;

    I2Cx_Init(I2C2, &I2C_Config2);
    

    uint16_t Angle1;
    uint16_t Angle2;
    AS5600_GetRawAngle(I2C1, &Angle1);
    AS5600_GetRawAngle(I2C2, &Angle2);
    while(1);
    return 0;
}
