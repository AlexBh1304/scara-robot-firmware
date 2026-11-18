#include "stm32f411.h"
#include "as5600.h"
#define TOLERANCE 10

void GPIO_INIT();
void USART_INIT();
int main()
{
   
    ClockConfig_t clockconfig;
    clockconfig.TargetClockSource = HSE;
    ChangeClockSource(&clockconfig);

    USART_INIT();
    GPIO_INIT();
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
    

    Timer_Config pTimConfig;

    pTimConfig.ARR = 9;
    pTimConfig.PSC = 780;
    pTimConfig.TimerMode = PWM;
    pTimConfig.CCRx = 5;
    pTimConfig.TimerxChannelx = TimerxChannel1 ;
    pTimConfig.TimerOutput = ENABLE;
    pTimConfig.OutputPinNumber = GPIO_PIN6;
    pTimConfig.AFNumber = AF02;
    pTimConfig.OutputPinPort = GPIOA;

    TimInit(TIM3, &pTimConfig);


    typedef union
    {
        uint8_t RxBytes[4];
        uint16_t TargetAngles[2];
    }RxUsart_t;

    typedef union
    {
        uint8_t TxBytes[4];
        uint16_t CurrentAngles[2];
    }TxUsart_t;

    TxUsart_t TxUsart;
    RxUsart_t RxUsart;
    uint16_t d1;
    uint16_t d2;
    while(1)
    {
        UsartRxByte(USART1, &RxUsart.RxBytes[0], 2);
        AS5600_GetRawAngle(I2C1, &TxUsart.CurrentAngles[0]);
        

        if(TxUsart.CurrentAngles[0] > RxUsart.TargetAngles[0])
        {
            d1 = TxUsart.CurrentAngles[0] - RxUsart.TargetAngles[0]; 
            d2 = (4095 - TxUsart.CurrentAngles[0]) + RxUsart.TargetAngles[0]; 
            if(d1 > d2)
            {
                Gpio_Pin_Set(GPIOB, GPIO_PIN12);
            }
            else
            {
                Gpio_Pin_Reset(GPIOB, GPIO_PIN12);
            }
        }
        else
        {
            d1 = RxUsart.TargetAngles[0] - TxUsart.CurrentAngles[0]; 
            d2 = (4095 - RxUsart.TargetAngles[0]) + TxUsart.CurrentAngles[0]; 
            if(d1 < d2)
            {
                Gpio_Pin_Set(GPIOB, GPIO_PIN12);
            }
            else
            {
                Gpio_Pin_Reset(GPIOB, GPIO_PIN12);
            }
        }
        
        TIMxEnableCounter(TIM3);

        do
        {
            AS5600_GetRawAngle(I2C1, &TxUsart.CurrentAngles[0]);
            UsartSendByte(USART1, &TxUsart.TxBytes[0], 2);

        }while((TxUsart.CurrentAngles[0] <= (RxUsart.TargetAngles[0] - TOLERANCE)) || (TxUsart.CurrentAngles[0] >= (RxUsart.TargetAngles[0] + TOLERANCE)));
        
        TIMxDisableCounter(TIM3);

    }
    while(1);
    return 0;
}


void USART_INIT()
{
    USART_Config usartconfig;

    USARTxClockControl(USART1, ENABLE);

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

void GPIO_INIT()
{
    GPIOx_Config_t dir_pin = {0};  
    dir_pin.Pin = GPIO_PIN12;
    dir_pin.Mode = GENERAL_PURPOSE_OUTPUT_PP_MODE;
    dir_pin.OutputSpeed = HIGH_OUTPUT_SPEED;
    Gpio_Init(&dir_pin,GPIOB);
}

//int main()
//{
//   
//    ClockConfig_t clockconfig;
//    clockconfig.TargetClockSource = HSE;
//    ChangeClockSource(&clockconfig);
//
//    USART_INIT();
//
//    I2C_Config_t I2C_Config = {0};
//    
//    I2C_Config.SCL_AFNumber = AF04;
//    I2C_Config.SCL_PinNumber = GPIO_PIN6;
//    I2C_Config.SCL_PinPort = GPIOB;
//    I2C_Config.SDA_AFNumber = AF04;
//    I2C_Config.SDA_PinNumber = GPIO_PIN7;
//    I2C_Config.SDA_PinPort = GPIOB;
//    I2C_Config.PullUp = DISABLE;
//    I2C_Config.I2C_Mode = I2C_STANDARD_MODE;
//    
//    I2Cx_Init(I2C1, &I2C_Config);
//
//    I2C_Config_t I2C_Config2 = {0};
//    I2C_Config2.SCL_AFNumber = AF04;
//    I2C_Config2.SCL_PinNumber = GPIO_PIN10;
//    I2C_Config2.SCL_PinPort = GPIOB;
//    I2C_Config2.SDA_AFNumber = AF09;
//    I2C_Config2.SDA_PinNumber = GPIO_PIN3;
//    I2C_Config2.SDA_PinPort = GPIOB;
//    I2C_Config2.PullUp = DISABLE;
//    I2C_Config2.I2C_Mode = I2C_STANDARD_MODE;
//                                              
//    I2Cx_Init(I2C2, &I2C_Config2);
//
//
//    Timer_Config pTimConfig;
//
//    pTimConfig.ARR = 9;
//    pTimConfig.PSC = 780;
//    pTimConfig.TimerMode = PWM;
//    pTimConfig.CCRx = 5;
//    pTimConfig.TimerxChannelx = TimerxChannel1 ;
//    pTimConfig.TimerOutput = ENABLE;
//    pTimConfig.OutputPinNumber = GPIO_PIN6;
//    pTimConfig.AFNumber = AF02;
//    pTimConfig.OutputPinPort = GPIOA;
//
//    TimInit(TIM3, &pTimConfig);
//
//    TIMxEnableCounter(TIM3);
//
//    typedef union
//    {
//        uint8_t RxBytes[4];
//        uint16_t TargetAngles[2];
//    }RxUsart_t;
//
//    typedef union
//    {
//        uint8_t TxBytes[4];
//        uint16_t CurrentAngles[2];
//    }TxUsart_t;
//
//    TxUsart_t TxUsart;
//    RxUsart_t RxUsart;
//
//    while(1)
//    {
//        UsartRxByte(USART1, &RxUsart.RxBytes[0], 1);
//
//        if(RxUsart.RxBytes[0] == 49)
//        {
//            AS5600_GetRawAngle(I2C1, &TxUsart.CurrentAngles[0]);
//            AS5600_GetRawAngle(I2C2, &TxUsart.CurrentAngles[1]);
//            UsartSendByte(USART1, &TxUsart.TxBytes[0], 4);
//            TIMxDisableCounter(TIM3);
//        }
//
//    }
//    while(1);
//    return 0;
//}
