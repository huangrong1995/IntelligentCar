/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/stm32f10x_it.c 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h"
#include "debug.h"
/** @addtogroup STM32F10x_StdPeriph_Template
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
__IO uint16_t IC2Value = 0;
__IO uint16_t IC2Value1 = 0;
__IO uint16_t DutyCycle = 0;
__IO uint16_t Frequency = 0;
/* Private function prototypes -----------------------------------------------*/
extern void TimeDelay_Decrement(void);
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
    TimeDelay_Decrement();
}

/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

void EXTI9_5_IRQHandler(void)
{
    int keyStatus;
    if(EXTI_GetITStatus(EXTI_Line5) != RESET) //确保是否产生了EXTI Line中断
    {
      // LED1 取反
      keyStatus = GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_3);
      GPIO_WriteBit(GPIOC, GPIO_Pin_3, (BitAction)(1 - keyStatus));
      EXTI_ClearITPendingBit(EXTI_Line5);     //清除中断标志位
    }
}

/**
  * @brief  This function handles TIM2 global interrupt request.
  * @param  None
  * @retval : None
  */
 #if 1
void TIM2_IRQHandler(void)
{
  /* Clear TIM2 Capture compare interrupt pending bit */
  TIM_ClearITPendingBit(TIM2, TIM_IT_CC2);

  /* Get the Input Capture value */
  IC2Value = TIM_GetCapture2(TIM2);

  if (IC2Value != 0) 
  {
    /* Duty cycle computation */
    TIM_ClearITPendingBit(TIM2, TIM_IT_CC2);
    IC2Value1 = TIM_GetCapture1(TIM2);
    LOG("IC2Value = %d, IC2Value1 = %d\n", IC2Value, IC2Value1);
    DutyCycle = (IC2Value1 * 100) / IC2Value;

    /* Frequency computation */
    Frequency = 1000000 / IC2Value;
  }
  else
  {
    DutyCycle = 0;
    Frequency = 0;
  }

  LOG("DutyCycle = %d, Frequency = %d\n", DutyCycle, Frequency);
}
#else
void TIM2_IRQHandler(void)
{
  /* Clear TIM2 Capture compare interrupt pending bit */
  TIM_ClearITPendingBit(TIM2, TIM_IT_CC2);

  /* Get the Input Capture value */
  IC2Value = TIM_GetCapture2(TIM2) + 243540;

  int count = 0;

  if (IC2Value != 0)
  {
    /* Duty cycle computation */
    // TIM_ClearITPendingBit(TIM2, TIM_IT_CC2);

    IC2Value1 = TIM_GetCapture1(TIM2);
    if (IC2Value1 < 1000)
      IC2Value1 += 65535;
    LOG("IC2Value = %d, IC2Value1 = %d\n", IC2Value, IC2Value1);
    DutyCycle = (IC2Value1 * 100) / IC2Value;

    /* Frequency computation */
    Frequency = 1000000 / IC2Value;
  }
  else
  {
    DutyCycle = 0;
    Frequency = 0;
  }

  LOG("DutyCycle = %d, Frequency = %d\n", DutyCycle, Frequency);
}
#endif

/**
  * @}
  */


/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
