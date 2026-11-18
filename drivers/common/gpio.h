/**
 * @file gpio.h
 * @brief Peripheral driver function definitions
 * @author Alex
 */

//#ifndef STM32F411_H  look for ways to include a header file once, without adding the other target as well

#ifndef GPIO_H
#define GPIO_H


#ifdef USING_STM32F411
#ifndef STM32F411_H
#include "stm32f411.h"
#endif
/**
 * @brief Configuration struct for a gpio
 */

typedef struct{
	uint8_t Pin;
	uint8_t Mode;
	uint8_t OutputSpeed;
	uint8_t PullOption;
	uint8_t AFOutputType;
    uint8_t AFNumber;
}GPIOx_Config_t;

// Pin Modes
#define INPUT_MODE			                (0b0000)
#define GENERAL_PURPOSE_OUTPUT_PP_MODE      (0b1001)  //The first bit will be used to shift the number in order to know the Output mode
#define GENERAL_PURPOSE_OUTPUT_OD_MODE      (0b1101)
#define ALTERNATE_FUNCTION_MODE             (0b0010)
#define ANALOG_MODE				            (0b0011)

//Output Speed
#define LOW_OUTPUT_SPEED                    (0b00)
#define MEDIUM_OUTPUT_SPEED                 (0b01)
#define FAST_OUTPUT_SPEED                   (0b10)
#define HIGH_OUTPUT_SPEED                   (0b11)

//PULLUP PULL DOWN
#define NO_PU_PD                            (0b00)
#define PULLUP                              (0b01)
#define PULLDOWN                            (0b10)

//Alternate function numbers
#define AF00      ((uint8_t)(0b0000))
#define AF01      ((uint8_t)(0b0001))
#define AF02      ((uint8_t)(0b0010))
#define AF03      ((uint8_t)(0b0011))
#define AF04      ((uint8_t)(0b0100))
#define AF05      ((uint8_t)(0b0101))
#define AF06      ((uint8_t)(0b0110))
#define AF07      ((uint8_t)(0b0111))
#define AF08      ((uint8_t)(0b1000))
#define AF09      ((uint8_t)(0b1001))
#define AF10     ((uint8_t)(0b1010))
#define AF11     ((uint8_t)(0b1011))
#define AF12     ((uint8_t)(0b1100))
#define AF13     ((uint8_t)(0b1101))
#define AF14     ((uint8_t)(0b1110))
#define AF15     ((uint8_t)(0b1111))

//Output type
#define OUTPUT_PUSH_PULL      (0b0)
#define OUTPUT_OPEN_DRAIN     (0b1)

#endif /*USING_STM32F411*/

//#ifdef STM32F103_H
//
//
///**
// * @brief Configuration struct for a gpio
// */
//
//typedef struct{
//
//	uint8_t Pin;
//	uint8_t Mode;
//	uint8_t OutputSpeed;
//
//}GPIOx_Config_t;
//
//// Pin Modes
//#define GENERAL_PURPOSE_OUTPUT_PP	    ((0b00 << 2) | 0b1)
//#define GENERAL_PURPOSE_OUTPUT_OD	    ((0b01 << 2) | 0b1)
//#define ALTERNATE_FUNCTION_OUTPUT_PP	((0b10 << 2) | 0b1)
//#define ALTERNATE_FUNCTION_OUTPUT_OD	((0b11 << 2) | 0b1)
//
//#define ANALOG				            ((0b00 << 2) | 0b00)
//#define INPUT_FLOATING			        ((0b01 << 2) | 0b00)
//#define INPUT_PU_PD			            ((0b10 << 2) | 0b00)
//
////Output Speed
//#define OUTPUT_SPEED_10MHZ		        (0x01)
//#define OUTPUT_SPEED_2MHZ		        (0x02)
//#define OUTPUT_SPEED_50MHZ		        (0x03)
//
//
//#endif /*STM32F103_H*/
//

#include <stdint.h>

//Pin number definitions
#define GPIO_PIN0	((uint8_t)(0x00))
#define GPIO_PIN1	((uint8_t)(0x01))
#define GPIO_PIN2	((uint8_t)(0x02))
#define GPIO_PIN3	((uint8_t)(0x03))
#define GPIO_PIN4	((uint8_t)(0x04))
#define GPIO_PIN5	((uint8_t)(0x05))
#define GPIO_PIN6	((uint8_t)(0x06))
#define GPIO_PIN7	((uint8_t)(0x07))
#define GPIO_PIN8	((uint8_t)(0x08))
#define GPIO_PIN9	((uint8_t)(0x09))
#define GPIO_PIN10	((uint8_t)(0x0A))
#define GPIO_PIN11	((uint8_t)(0x0B))
#define GPIO_PIN12	((uint8_t)(0x0C))
#define GPIO_PIN13	((uint8_t)(0x0D))
#define GPIO_PIN14	((uint8_t)(0x0E))
#define GPIO_PIN15	((uint8_t)(0x0F))


//Functions
void Gpio_Init(GPIOx_Config_t* pGpioConfig, GPIO_t* pGPIO);
void Gpio_Pin_Set(GPIO_t* pGPIO, uint8_t PinNumber);
void Gpio_Pin_Reset(GPIO_t* pGPIO, uint8_t PinNumber);
void Gpio_Pin_Toggle(GPIO_t* pGPIO, uint8_t PinNumber);
#endif /*GPIO_H*/
