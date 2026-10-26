#include <stdint.h>

#define GPIOC_BASE_ADDRESS 0x40020800
#define GPIOC_ODR 0x40020814

void delay();
uint32_t main()
{
    
    //Turn on peripheral clock
    //set c13 as otuput push pull
    //toggle the led

    *((volatile uint32_t*)0x40023830) |= (1 << 2);

    *((volatile uint32_t*)GPIOC_BASE_ADDRESS) |= (0b01 << 26);
       

    while(1)
    {
        delay();
        *((volatile uint32_t*)GPIOC_ODR ) ^= (1 << 13);

    }

    return 0;
}

void delay()
{
    for(volatile uint32_t i = 0; i < 500000; i++);
}
