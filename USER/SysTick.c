/******************** (C) COPYRIGHT 2012 WildFire Team ***************************
 * �ļ���  ��SysTick.c
 * ����    ��SysTick ϵͳ�δ�ʱ��10us�жϺ�����,�ж�ʱ����������ã�
 *           ���õ��� 1us 10us 1ms �жϡ�
 * ʵ��ƽ̨��Ұ��STM32������
 * Ӳ�����ӣ�-----------------
 *          |                 |
 *          |      ��         |
 *          |                 |
 *           -----------------
 * ��汾  ��ST3.5.0
 * ����    ��wildfire team
 * ��̳    ��http://www.amobbs.com/forum-1008-1.html
 * �Ա�    ��http://firestm32.taobao.com
**********************************************************************************/
#include "SysTick.h"

static __IO u32 TimeDelayUS;
static __IO u32 TimeDelayMS;
/*
 * ��������SysTick_Init
 * ����  ������ϵͳ�δ�ʱ�� SysTick
 * ����  ����
 * ���  ����
 * ����  ���ⲿ����
 */
void SysTick_Init(void)
{
	/* SystemFrequency / 1000    1ms�ж�һ��
	 * SystemFrequency / 100000	 10us�ж�һ��
	 * SystemFrequency / 1000000 1us�ж�һ��
	 */
//	if (SysTick_Config(SystemFrequency / 100000))	// ST3.0.0��汾
	if (SysTick_Config(SystemCoreClock / 100000))	// ST3.5.0��汾
	{
		/* Capture error */
		while (1);
	}
		// �رյδ�ʱ��
	SysTick->CTRL &= ~ SysTick_CTRL_ENABLE_Msk;
}


/*
 * ��������Delay_Time_US
 * ����  ��us��ʱ����,10usΪһ����λ
 * ����  ��- nTime
 * ���  ����
 * ����  ��Delay_Time_US( 1 ) ��ʵ�ֵ���ʱΪ 1 * 10us = 10us
 *       ���ⲿ����
 */

void Delay_Time_US(__IO u32 nTime)
{
	TimeDelayUS = nTime;

	// ʹ�ܵδ�ʱ��
	SysTick->CTRL |=  SysTick_CTRL_ENABLE_Msk;

	while(TimeDelayUS != 0);
}

/*
 * ��������Delay_Time_MS
 * ����  ��us��ʱ����,10usΪһ����λ
 * ����  ��- nTime
 * ���  ����
 * ����  ��Delay_Time_MS( 1 ) ��ʵ�ֵ���ʱΪ 1 * 10us = 10us
 *       ���ⲿ����
 */

void Delay_Time_MS(__IO u32 nTime)
{
	TimeDelayUS = nTime * 100;

	// ʹ�ܵδ�ʱ��
	SysTick->CTRL |=  SysTick_CTRL_ENABLE_Msk;

	while(TimeDelayUS != 0);
}

/*
 * ��������TimingDelay_Decrement
 * ����  ����ȡ���ĳ���
 * ����  ����
 * ���  ����
 * ����  ���� SysTick �жϺ��� SysTick_Handler()����
 */
void TimeDelay_Decrement(void)
{
	if (TimeDelayUS != 0x00) {
		TimeDelayUS--;
	}
}
/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE************/
