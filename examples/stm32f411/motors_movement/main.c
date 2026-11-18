#include "stm32f411.h"
#include "as5600.h"

#define TOLERANCE   5
#define GPIO_DIR GPIO_PIN2   

void I2C1_Init();
void USART_INIT();
void TIMER_INIT();
void GPIO_INIT();
void Setup();

int main()
{
    Setup();
    typedef union
    {
        uint8_t RxBytes[4];
        uint16_t TargetAngles[2];
    }RxUsart_t;

    RxUsart_t RxUsart;
    
    uint16_t raw_angle_1;
    uint16_t raw_angle_2;
    int32_t d1;
    int32_t d2;

        
    while(1)
    {
        UsartRxByte(USART1, RxUsart.RxBytes, 4);
        AS5600_GetRawAngle(I2C1, &raw_angle_1);
    

    if(raw_angle_1 > RxUsart.TargetAngles[0])
    {
        d1 = raw_angle_1 - RxUsart.TargetAngles[0]; 
        d2 = (4095 - raw_angle_1) + RxUsart.TargetAngles[0]; 
        if(d1 > d2)
        {
            Gpio_Pin_Reset(GPIOB, GPIO_DIR);
        }
        else
        {
            Gpio_Pin_Set(GPIOB, GPIO_DIR);
        }
    }
    else
    {
        d1 = RxUsart.TargetAngles[0] - raw_angle_1; 
        d2 = (4095 - RxUsart.TargetAngles[0]) + raw_angle_1; 
        if(d1 < d2)
        {
            Gpio_Pin_Reset(GPIOB, GPIO_DIR);
        }
        else
        {
            Gpio_Pin_Set(GPIOB, GPIO_DIR);
        }

    }
    
    TIM3->CR1 |= (0b1);

    do
    {

    AS5600_GetRawAngle(I2C1, &raw_angle_1);

    }while((raw_angle_1 <= (RxUsart.TargetAngles[0] - TOLERANCE)) || (raw_angle_1 >= (RxUsart.TargetAngles[0] + TOLERANCE)));

    TIM3->CR1 &= ~(0b1);
    }

    return 0;
}


void USART_INIT()
{
    USART_Config usartconfig;

    USARTxClockControl(USART1, ENABLE);
    GPIOxClockControl(GPIOA, ENABLE);

    GPIOx_Config_t txconfig;
    txconfig.AFNumber = AF07;
    txconfig.Pin = GPIO_PIN9;
    txconfig.Mode = ALTERNATE_FUNCTION_MODE;             

    Gpio_Init(&txconfig,GPIOA);

    GPIOx_Config_t rxconfig;
    rxconfig.AFNumber = AF07;
    rxconfig.Pin = GPIO_PIN10;
    rxconfig.Mode = ALTERNATE_FUNCTION_MODE;             
 
    Gpio_Init(&rxconfig,GPIOA);

    USARTInit(USART1, &usartconfig);
}


void TIMER_INIT()
{

    TIMxClockControl(TIM3, ENABLE);

    GPIOx_Config_t timerPin;   
    timerPin.Pin = GPIO_PIN6;
	timerPin.Mode = ALTERNATE_FUNCTION_MODE;
	timerPin.OutputSpeed = HIGH_OUTPUT_SPEED;
    timerPin.AFOutputType = 0;
    timerPin.AFNumber = AF02;
    

    //GPIOxClockControl(GPIOA, ENABLE);
    Gpio_Init(&timerPin, GPIOA);

    //PSC = 32khz
    TIM3->PSC = 780;

    //ARR = PWM frecuency = 3.2khz
    TIM3->ARR = 9;
    
    //CCR1 = Duty Cycle = 50%
    TIM3->CCR1 = 5;

    //CCMR1 -> OCxM = PWM1 mode
    TIM3->CCMR1 |= (0b110 << 4);

    //CCMR1 ->OC1PE = preload enable
    TIM3->CCMR1 |= (0b1 << 3);

    //ARPE CR1 Auto reload preload enable
    TIM3->CR1 |= (0b1 << 7);

    //EGR UG bit Update generation
    TIM3->EGR |= (0b1);

    //Activate the output CC1E
    TIM3->CCER |= (0b1);
    
    //Activate counter
    //TIM3->CR1 |= (0b1);

    //Deactivate counter

}
void GPIO_INIT()
{
    GPIOx_Config_t dir_pin = {0};  
    dir_pin.Pin = GPIO_PIN2;
    dir_pin.Mode = GENERAL_PURPOSE_OUTPUT_PP_MODE;
    dir_pin.OutputSpeed = HIGH_OUTPUT_SPEED;
    Gpio_Init(&dir_pin,GPIOB);
}

void Setup()
{
    GPIO_INIT();
    USART_INIT();
    TIMER_INIT();

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

    ClockConfig_t clockconfig;
    clockconfig.TargetClockSource = HSE;
    ChangeClockSource(&clockconfig);

}
