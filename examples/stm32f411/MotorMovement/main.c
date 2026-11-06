#include "stm32f411.h"

void USART_INIT();

int main()
{
    USART_INIT();
    //uint8_t SlaveAddress;
    uint32_t temp;
    uint8_t data;
    uint8_t data1;
    uint16_t raw_angle;
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
    
    while(1)
    {
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
    
    I2C1->DR = 0x0C;

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
    
    I2C1->CR1 |= (0b1 << 10);


    temp = I2C1->SR1;
    temp = I2C1->SR2;

/* ---------Ev6 ----------------*/


/* ---------Ev7_1 ----------------*/

    while(!(I2C1->SR1 & 0b1000000));
    data = I2C1->DR;

    I2C1->CR1 &= ~(0b1 << 10);
    //Stop
    I2C1->CR1 |= (0b1 << 9);

/* ---------Ev7_1 ----------------*/

/* ---------Ev7 ----------------*/
    while(!(I2C1->SR1 & 0b1000000));
    data1 = I2C1->DR;

/* ---------Ev7 ----------------*/
    raw_angle = ((data << 8) | (data1));
    raw_angle = ((raw_angle * 360) >> 12);

    UsartSendByte(&data, USART1);   
    UsartSendByte(&data1, USART1);   
    
    //TO DO; CREATE A DELAY FUNCITION USING THE SYSTICK 
    for(volatile uint32_t i = 0; i< 500000; i++);
    }
    while(1);


    return 0;
}

void USART_INIT()
{
    USART_Config usartconfig;
    
    RCC->APB2ENR |= (1 << 4);

    USART_t* pPointer = USART1;
    GPIOx_Config_t gpioconfig;
    GPIOxClockControl(GPIOA, ENABLE);
    GPIOA->AFRH |= (0b111 << 4);

    gpioconfig.Pin = GPIO_PIN9;
    gpioconfig.Mode = ALTERNATE_FUNCTION_MODE;             
    Gpio_Init(&gpioconfig,GPIOA);

    USARTInit(USART1, &usartconfig);
 
}

