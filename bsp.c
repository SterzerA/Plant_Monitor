#include <stdint.h>
#include "stm32wb55xx.h"
#include "system_stm32wbxx.h"
#include "bsp.h"

static uint32_t volatile l_tickCtr;

void SysTick_Handler(void) {
    ++l_tickCtr;
}

uint32_t BSP_tickCtr(void) {
    uint32_t tickCtr;

    __disable_irq();
    tickCtr = l_tickCtr;
    __enable_irq();

    return tickCtr;
}

void BSP_delay(uint32_t ticks) {
    uint32_t start = BSP_tickCtr();
    while ((BSP_tickCtr() - start) < ticks) {
    }
}

void BSP_init(void) {
	
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
	GPIOB->MODER &= ~(GPIO_MODER_MODE0_Msk|GPIO_MODER_MODE1_Msk|GPIO_MODER_MODE5_Msk);
	GPIOB->MODER |= GPIO_MODER_MODE0_0 | GPIO_MODER_MODE1_0 | GPIO_MODER_MODE5_0;

	SystemCoreClockUpdate();	
	SysTick_Config(SystemCoreClock / BSP_TICKS_PER_SEC);  

    __enable_irq();
}

void BSP_ledRedOn(void) {
    GPIOB->BSRR = GPIO_BSRR_BS1;
}

void BSP_ledRedOff(void) {
    GPIOB->BSRR = GPIO_BSRR_BR1;
}

void BSP_ledBlueOn(void) {
    GPIOB->BSRR = GPIO_BSRR_BS5;
}

void BSP_ledBlueOff(void) {
    GPIOB->BSRR = GPIO_BSRR_BR5;
}

void BSP_ledGreenOn(void) {
    GPIOB->BSRR = GPIO_BSRR_BS0;
}

void BSP_ledGreenOff(void) {
    GPIOB->BSRR = GPIO_BSRR_BR0;
}
