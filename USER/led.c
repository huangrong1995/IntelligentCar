#include "led.h"

void LED_Init()
{
    GPIO_InitTypeDef GPIO_InitStruct;

    //1.设置时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

    //2.设置需要控制的引脚
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_3;

    //3.设置引脚速率
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;

    //4.设置输出模式
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;

    //5.初始化GPIO
    GPIO_Init(GPIOC, &GPIO_InitStruct);

    return;
}
