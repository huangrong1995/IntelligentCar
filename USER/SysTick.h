#ifndef __SYSTICK_H
#define __SYSTICK_H

#include "stm32f10x.h"

void SysTick_Init(void);
void Delay_Time_US(__IO u32 nTime);
void Delay_Time_MS(__IO u32 nTime);
#endif /* __SYSTICK_H */
