/***********************************************
 * LED功能
 * 日期:2021-08-08
 ***********************************************/

#ifndef __LED_H
#define	__LED_H

#include "stm32f10x.h"

/* the macro definition to trigger the led on or off 
 * 1 - off
 - 0 - on
 */
#define ON  1
#define OFF 0

#define LED_Status(cmd) \
    if (cmd)    \
        GPIO_SetBits(GPIOC, GPIO_Pin_3); \
    else    \
        GPIO_ResetBits(GPIOC, GPIO_Pin_3)

void LED_Init(void);

#endif /* __LED_H */
