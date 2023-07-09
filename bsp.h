#include <stdint.h>

#ifndef __BSP_H__
#define __BSP_H__

#define BSP_TICKS_PER_SEC 4000U

void BSP_init(void);
void BSP_ledRedOn(void);
void BSP_ledRedOff(void);
void BSP_ledBlueOn(void);
void BSP_ledBlueOff(void);
void BSP_ledGreenOn(void);
void BSP_ledGreenOff(void);
uint32_t BSP_tickCtr(void);
void SysTick_Handler(void);
void BSP_delay(uint32_t ticks);

#endif // __BSP_H__
