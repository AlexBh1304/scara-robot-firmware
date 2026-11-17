#include "stm32f411.h"

void I2C1_Init();
void AS5600_GetRawAngle(uint16_t* angle);
int main()
{
    //change clock to hse   
    RCC->CR |= (1 << 16);
    while(!(RCC->CR &(1 << 17)));
    RCC->CFGR |= (0b01);

    I2C1_Init();
    uint16_t Angle;
    AS5600_GetRawAngle(&Angle);
    while(1);
    return 0;
}

void AS5600_GetRawAngle(uint16_t* angle)
{
    uint8_t deviceAddress = 0x36;
    uint8_t WriteData = 0x0C;
    uint8_t RxData[2];
    GenerateStartCondition(I2C1);
    MasterSendAddress(I2C1, deviceAddress, I2C_MASTER_WRITE);
    MasterSendData(I2C1, WriteData);
    GenerateStartCondition(I2C1);
    MasterSendAddress(I2C1, deviceAddress, I2C_MASTER_READ);
    MasterReadData(I2C1, RxData, 2);
    *angle = ((RxData[0] << 8) | (RxData[1]));
}
void I2C1_Init()
{
    //SCL Alternate function AF04 con port B pin 6
    GPIOx_Config_t scl_pin = {0};  
    scl_pin.Pin = GPIO_PIN6;
    scl_pin.Mode = ALTERNATE_FUNCTION_MODE;
    scl_pin.OutputSpeed = HIGH_OUTPUT_SPEED;
    //scl_pin.PullOption = PULLUP;
    scl_pin.AFOutputType = OUTPUT_OPEN_DRAIN;
    scl_pin.AFNumber = AF04;
    Gpio_Init(&scl_pin,GPIOB);
    //SDA Alternate function AF04 con port B pin 7
    GPIOx_Config_t sda_pin = {0};  
    sda_pin.Pin = GPIO_PIN7;
    sda_pin.Mode = ALTERNATE_FUNCTION_MODE;
    sda_pin.OutputSpeed = HIGH_OUTPUT_SPEED;
    //sda_pin.PullOption = PULLUP;
    sda_pin.AFOutputType = OUTPUT_OPEN_DRAIN;
    sda_pin.AFNumber = AF04;
    Gpio_Init(&sda_pin,GPIOB);


    RCC->APB1ENR |= (1 << 21);

    // Program the peripheral input clock in I2C_CR2 Register in order to generate correct timings
    I2C1->CR2 |= (0b11001); //25MHz from HSE

    I2C1->CCR |= (0b11111010); //250d to set 100khz frecuency clock for standard mode
    
    // Configure the rise time register
    I2C1->TRISE |= (0b11010); //1000ns / 40ns = 25 + 1 = 26

    // Program the I2C_CR1 register to enable the peripheral
    I2C1->CR1 |= (0b1);
}
