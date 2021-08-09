/******************** (C) COPYRIGHT 2012 WildFire Team **************************
 * �ļ���  ��main.c
 * ����    ����3.5.0�汾���Ĺ���ģ�塣
 * ʵ��ƽ̨��Ұ��STM32������
 * ��汾  ��ST3.5.0
 *
 * ����    ��wildfire team
 * ��̳    ��http://www.amobbs.com/forum-1008-1.html
 * �Ա�    ��http://firestm32.taobao.com
**********************************************************************************/
#include "stm32f10x.h"
#include "led.h"
#include "SysTick.h"
#include "key.h"
/*
 * ��������main
 * ����  : ������
 * ����  ����
 * ���  : ��
 */
int main(void)
{
    int keyStatus;

    LED_Init();
    SysTick_Init();
    Key_GPIO_Init();

    while(1) {
        if (Key_Scan(GPIOE, GPIO_Pin_5) == KEY_ON) {
            /*LED1��ת*/
            keyStatus = GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_3);
            GPIO_WriteBit(GPIOC, GPIO_Pin_3, (BitAction)(1 - keyStatus));
        }
    }
    // add your code here ^_^��
}

/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE************/

