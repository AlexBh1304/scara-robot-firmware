#include "stm32f411.h"


int main()
{
    
    //uint8_t SlaveAddress;
    uint32_t temp;
    uint8_t data;
    //Change clock to hse
    RCC->CR |= (1 << 16);
    while(!(RCC->CR &(1 << 17)));
    RCC->CFGR |= (0b01);

    //SCL
    GPIOx_Config_t gpioconfigscl;
    GPIOxClockControl(GPIOB, ENABLE);
    GPIOB->AFRL |= (0b0100 << 24);
    gpioconfigscl.Pin = GPIO_PIN6;
    gpioconfigscl.Mode = ALTERNATE_FUNCTION_MODE;             
    gpioconfigscl.OutputSpeed = HIGH_OUTPUT_SPEED;                   
    Gpio_Init(&gpioconfigscl,GPIOB);


    //SDA
    GPIOx_Config_t sda;
    GPIOB->AFRL |= (0b0100 << 28);
    sda.Pin = GPIO_PIN7;
    sda.Mode = ALTERNATE_FUNCTION_MODE;             
    sda.OutputSpeed = HIGH_OUTPUT_SPEED;                   

    GPIOB->ODR |= (0b11 << 6);
    GPIOB->OTYPER |= (0b11 << 6);
    GPIOB->PUPDR |= (0b0101 << 12);

    Gpio_Init(&sda,GPIOB);
        

    RCC->APB1ENR |= (1 << 21);

    // Program the peripheral input clock in I2C_CR2 Register in order to generate correct timings
    I2C1->CR2 |= (0b11001); //25MHz from HSE

    // Configure the clock control registers
    //I2C1->CCR |= (0b1 << 15); //Standard mode is selected by reset

    I2C1->CCR |= (0b11111010); //250d to set 100khz frecuency clock for standard mode
    
    // Configure the rise time register
    I2C1->TRISE |= (0b11010); //1000ns / 40ns = 25 + 1 = 26
    
    //Ack enable


    //Own address?
    //I2C1->OAR1 |= (0b100000010110111);
    // Program the I2C_CR1 register to enable the peripheral
    I2C1->CR1 |= (0b1);

    // Set the START bit in the I2C_CR1 register to generate a Start condition
    I2C1->CR1 |= (0b1 << 8);

    while(!(I2C1->SR1 & 0b1));

    temp = I2C1->SR1;

    I2C1->DR = 0b01101100;
    //I2C1->DR = 0b01010001;
    
    //Stop genLration
    //I2C1->CR1 |= (0b1 << 9);
    
    while(!(I2C1->SR1 & 0b10));

    temp = I2C1->SR1;
    temp = I2C1->SR2;
    
    I2C1->DR = 0x0B;

    //Start condition
    I2C1->CR1 |= (0b1 << 8);
    
    //Wait for sb flag
    while(!(I2C1->SR1 & 0b1));
    
    //Ev5
    temp = I2C1->SR1;

    I2C1->DR = 0b01101101;

    //Wait for EV6 to start
    while(!(I2C1->SR1 & 0b10));

 
/* ---------Ev6 ----------------*/
    
    //Nack 
    I2C1->CR1 &= ~(0b1 << 10);


    temp = I2C1->SR1;
    temp = I2C1->SR2;

/* ---------Ev6 ----------------*/

    //Stop
    I2C1->CR1 |= (0b1 << 9);

/* ---------Ev7 ----------------*/

    while(!(I2C1->SR1 & 0b1000000));
    data = I2C1->DR;

/* ---------Ev7 ----------------*/

    while(1);

    return 0;
}



