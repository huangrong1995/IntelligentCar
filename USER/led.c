#include "led.h"

void LED_Init()
{
    GPIO_InitTypeDef GPIO_InitStruct;

    //1.����ʱ��
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

    //2.������Ҫ���Ƶ�����
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_3;

    //3.������������
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;

    //4.�������ģʽ
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;

    //5.��ʼ��GPIO
    GPIO_Init(GPIOC, &GPIO_InitStruct);

    return;
}
