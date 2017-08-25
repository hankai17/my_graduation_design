#ifndef _pbdata_H
#define _pbdata_H

#include "stm32f10x.h"
#include "misc.h"
#include "stm32f10x_exti.h"
#include "stm32f10x_tim.h"
#include "stm32f10x_usart.h"
#include "stdio.h"//printf函数
#include "stm32f10x_adc.h"
#include "stm32f10x_rtc.h"
#include "stm32f10x_pwr.h"
#include "stm32f10x_bkp.h"
#include "stm32f10x_fsmc.h"
#include "stm32f10x_adc.h"
#include "stm32_fsmc.h"
#include "lcd_ILI9325.h"
#include "key.h"
#include "DHT11.h"

// 这种错误 错了几遍了 不要先按编译 先保存 再编译
//定义变量
#define  BKP_TIME_FLAG            BKP_DR1
#define  BKP_TIME_YEAR            BKP_DR2
#define  BKP_TIME_MONTH           BKP_DR3
#define  BKP_TIME_DAY             BKP_DR4
#define  BKP_TIME_DATE            BKP_DR5

static int a[15];
static int a1[14];
static int con=0;

typedef struct T_STRUCT
{
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int sec;
	int date;
}T_STRUCT;
//static T_STRUCT Real_Time;
//static T_STRUCT Set_Time;
extern void RTCTick(void);
extern u8 dt;
extern u8 tim_bz;


//定义函数

void RCC_HSE_Configuration(void);
void delay(u32 nCount);
void delay_us(u32 nus);
void delay_ms(u16 nms);

#endif
