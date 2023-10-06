#include "apm32f00x_gpio.h"
#include "apm32f00x_eint.h"
#include "apm32f00x_misc.h"
#include "apm32f00x_rcm.h"

unsigned char pattern[] = "#.#.#..###.###.###..#.#.#.....";

volatile unsigned int ticks;

void delay(unsigned int t) {
    ticks = t;
    while(ticks);
}

int main(void) 
{
    GPIO_Config_T gpioConfig;

    gpioConfig.mode = GPIO_MODE_IN_PU;
    gpioConfig.pin = GPIO_PIN_ALL;			
    GPIO_Config(GPIOA, &gpioConfig);							
    GPIO_Config(GPIOB, &gpioConfig);					
    GPIO_Config(GPIOC, &gpioConfig);

    gpioConfig.pin = ((uint8_t)0XF9); 
    GPIO_Config(GPIOD, &gpioConfig);

    // GPIOD4 - pin 1
    gpioConfig.pin = GPIO_PIN_4;
    gpioConfig.mode = GPIO_MODE_OUT_PP;
    GPIO_Config(GPIOD, &gpioConfig);

    SysTick_Config(RCM_GetMasterClockFreq() / 1000);
    
    while(1)
    {
        for (int i = 0; i < sizeof(pattern)/sizeof(pattern[0]); i++) {
            if (pattern[i] == '#') {
                GPIO_SetBit(GPIOD, GPIO_PIN_4);
            } else {
                GPIO_ClearBit(GPIOD, GPIO_PIN_4);
            }
            delay(200);
        }
    }
}

void SysTick_Handler(void) {
    if (ticks > 0) {
        ticks --;
    }
}
