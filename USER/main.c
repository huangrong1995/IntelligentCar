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
#include "exti.h"
#include "pwm_output.h"
#include "usart.h"
#include "stdio.h"
#include "debug.h"

/*
 * ��������main
 * ����  : ������
 * ����  ����
 * ���  : ��
 */
int main(void)
{
    int keyStatus;
    int ledStatus = 0;

	USART_Config();
    LOG("Start init intelligent car system...\n");
    LED_Init();
    SysTick_Init();
    Key_GPIO_Init();
    EXTI_PE5_Init();
    TIM3_PWM_Init();
    
    LOG("Start init OK...\n");
	
    while(1) {
        keyStatus = Key_Scan(GPIOE, GPIO_Pin_5);
        if (keyStatus == KEY_ON) {
            /*LED1��ת*/
            LOG("��תLED[%d]\n", ledStatus);
            ledStatus = GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_3);
            GPIO_WriteBit(GPIOC, GPIO_Pin_3, (BitAction)(1 - ledStatus));
            LOG("��תLED[%d]\n", ledStatus);
        }
    }
    // add your code here ^_^��
}

/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE************/


