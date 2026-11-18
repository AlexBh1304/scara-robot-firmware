#define USING_STM32F411
#include "i2c.h"
#include "gpio.h"

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

void I2Cx_Init(I2C_t* I2Cx, I2C_Config_t* I2C_Config)
{
    //SCL Alternate function AF04 con port B pin 6
    GPIOx_Config_t scl_pin_config = {0};  
    GPIOx_Config_t sda_pin_config = {0};  
    if(I2C_Config->PullUp)
    {
        scl_pin_config.PullOption = PULLUP;
        sda_pin_config.PullOption = PULLUP;
    }
    scl_pin_config.Pin = I2C_Config->SCL_PinNumber;
    scl_pin_config.Mode = ALTERNATE_FUNCTION_MODE;
    scl_pin_config.OutputSpeed = HIGH_OUTPUT_SPEED;
    scl_pin_config.AFOutputType = OUTPUT_OPEN_DRAIN;
    scl_pin_config.AFNumber = I2C_Config->SCL_AFNumber;
    Gpio_Init(&scl_pin_config,I2C_Config->SCL_PinPort);
    //SDA Configuration 
    sda_pin_config.Pin = I2C_Config->SDA_PinNumber;
    sda_pin_config.Mode = ALTERNATE_FUNCTION_MODE;
    sda_pin_config.OutputSpeed = HIGH_OUTPUT_SPEED;
    sda_pin_config.AFOutputType = OUTPUT_OPEN_DRAIN;
    sda_pin_config.AFNumber = I2C_Config->SDA_AFNumber;
    Gpio_Init(&sda_pin_config,I2C_Config->SDA_PinPort);
    //Enable I2Cx peripheral clock
    I2CxClockControl(I2Cx, ENABLE);
    //Configure i2c mode
    if(I2C_Config->I2C_Mode == I2C_STANDARD_MODE)
    {
        // To Do, Alex.: Create a function that gets the frecuency of the peripheral clock in rcc driver
        // Program the peripheral input clock in I2C_CR2 Register in order to generate correct timings
        I2Cx->CR2 |= (0b11001); //25MHz from HSE
        //250d to set 100khz frecuency clock for standard mode
        I2Cx->CCR |= (0b11111010); 
        // Configure the rise time register
        I2Cx->TRISE |= (0b11010); //1000ns / 40ns = 25 + 1 = 26
        // Program the I2C_CR1 register to enable the peripheral
        I2Cx->CR1 |= (0b1);
    }
}
