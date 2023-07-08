/******************** (C) COPYRIGHT 2012 WildFire Team **************************
 * 文件名  ：main.c
 * 描述    ：用3.5.0版本建的工程模板。
 * 实验平台：野火STM32开发板
 * 库版本  ：ST3.5.0
 *
 * 作者    ：wildfire team
 * 论坛    ：http://www.amobbs.com/forum-1008-1.html
 * 淘宝    ：http://firestm32.taobao.com
**********************************************************************************/
#include "stm32f10x.h"
#include "led.h"
#include "SysTick.h"
#include "key.h"
#include "exti.h"
#include "pwm_output.h"
#include "usart.h"
#include "pwm_input.h"

#include "stdio.h"
#include "debug.h"

/*
 * 函数名：main
 * 描述  : 主函数
 * 输入  ：无
 * 输出  : 无
 */
int main(void)
{
    int keyStatus;
    int ledStatus = 0;

    USART_Config();
    LOG("\r\n");
    LOG("Start init intelligent car system...\n");
    LED_Init();
    SysTick_Init();
    Key_GPIO_Init();
    EXTI_PE5_Init();
    TIM3_PWM_Init();
    PWM_InputInit();
    
    LOG("Start init OK...\n");

    while(1) {
        keyStatus = Key_Scan(GPIOE, GPIO_Pin_5);
        if (keyStatus == KEY_ON) {
            /*LED1反转*/
            LOG("Revert LED[%d]\n", ledStatus);
            ledStatus = GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_3);
            GPIO_WriteBit(GPIOC, GPIO_Pin_3, (BitAction)(1 - ledStatus));
            LOG("Revert LED[%d]\n", ledStatus);
        }
    }
    // add your code here ^_^。
}

/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE************/


