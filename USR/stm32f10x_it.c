/**
  ******************************************************************************
  * @file GPIO/IOToggle/stm32f10x_it.c 
  * @author  MCD Application Team
  * @version  V3.0.0
  * @date  04/06/2009
  * @brief  Main Interrupt Service Routines.
  *         This file provides template for all exceptions handler and 
  *         peripherals interrupt service routine.
  ******************************************************************************
  * @copy
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2009 STMicroelectronics</center></h2>
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h"	 
#include "stm32f10x_exti.h"
#include "stm32f10x_rcc.h"
#include "misc.h"
#include "pbdata.h"
#include "rtc_time.h"
void NMI_Handler(void)
{
}

void USART1_IRQHandler(void)
{
   if(USART_GetITStatus(USART1,USART_IT_RXNE)!=RESET)//��⺯�����Ѿ��յ�������
   {
		USART_SendData(USART1,USART_ReceiveData(USART1));//�� �Ӵ���1�ж������� �ٴӴ���1�ͳ�ȥ
		while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET);//�ж������Ƿ�����ɣ�����ȴ�
   }
}


/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval : None
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
  * @retval : None
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
  * @retval : None
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
  * @retval : None
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
  * @retval : None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval : None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSV_Handler exception.
  * @param  None
  * @retval : None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval : None
  */
void SysTick_Handler(void)
{
}

void TIM3_IRQHandler(void)
{
	

}
/****************************************************************************
* ��    �ƣ�void EXTI9_5_IRQHandler(void)
* ��    �ܣ�EXTI9-5�жϴ������
* ��ڲ�������
* ���ڲ�������
* ˵    ����
* ���÷������� 
****************************************************************************/
void EXTI9_5_IRQHandler(void)
{
}

/****************************************************************************
* ��    �ƣ�void EXTI1_IRQHandler(void)
* ��    �ܣ�EXTI2�жϴ������
* ��ڲ�������
* ���ڲ�������
* ˵    ����
* ���÷������� 
****************************************************************************/
void EXTI1_IRQHandler(void)
{
    
}

/****************************************************************************
* ��    �ƣ�void EXTI2_IRQHandler(void)
* ��    �ܣ�EXTI2�жϴ������
* ��ڲ�������
* ���ڲ�������
* ˵    ����
* ���÷������� 
****************************************************************************/
void EXTI2_IRQHandler(void)
{
    
}

/****************************************************************************
* ��    �ƣ�void EXTI3_IRQHandler(void)
* ��    �ܣ�EXTI3�жϴ������
* ��ڲ�������
* ���ڲ�������
* ˵    ����
* ���÷������� 
****************************************************************************/
void EXTI3_IRQHandler(void)
{
   
}

void RTC_IRQHandler(void)//û���ж���ں��� �Լ�д
{
	int i=0;
	T_STRUCT Get_Time;
	if(RTC_GetITStatus(RTC_IT_SEC)!=RESET)//���ж���
	{
		RTC_ClearITPendingBit(RTC_IT_SEC);//����жϱ�־
		tim_bz=1;//���жϱ�־
    RTCTick();
  }
	GetRTCTime(&Get_Time);
	  a[0]=Get_Time.year/1000%10;
			a[1]=Get_Time.year/100%10;
			a[2]=Get_Time.year/10%10;
			a[3]=Get_Time.year/1%10;
			a[4]=Get_Time.month/10%10;
			a[5]=Get_Time.month/1%10;
			a[6]=Get_Time.day/10%10;
			a[7]=Get_Time.day/1%10;
			a[8]=Get_Time.hour/10%10;
			a[9]=Get_Time.hour/1%10;
			a[10]=Get_Time.minute/10%10;
			a[11]=Get_Time.minute/1%10;
			a[12]=Get_Time.sec/10%10;
			a[13]=Get_Time.sec/1%10;
			a[14]=Get_Time.date;
			for(i=0;i<14;i++)
   	  {
				show_Str(10+i*15,100,a[i],RED,WHITE);//����ĸ
			}
			show_Str1(20,150,a[8],BLACK,WHITE);
			show_Str1(45,150,a[9],BLACK,WHITE);
			show_Str1(63,150,10,BLACK,WHITE);
			show_Str1(80,150,a[10],BLACK,WHITE);
			show_Str1(105,150,a[11],BLACK,WHITE);
			
			show_Font1(20,200,10+a[5],BLACK,WHITE);
			show_Font1(28,200,7,BLACK,WHITE);
			show_Font1(43,200,10+a[6],BLACK,WHITE);
			show_Font1(49,200,10+a[7],BLACK,WHITE);
			show_Font1(57,200,6,BLACK,WHITE);
			show_Font1(72,200,9,BLACK,WHITE);
			show_Font1(85,200,a[14]-2,BLACK,WHITE);
}
