#ifndef __DHT11_H
#define __DHT11_H 
#include "pbdata.h"

#define IO_DHT11 GPIO_Pin_4
#define GPIO_DHT11 GPIOE

#define DHT11_DQ_High GPIO_SetBits(GPIO_DHT11,IO_DHT11)
#define DHT11_DQ_Low  GPIO_ResetBits(GPIO_DHT11,IO_DHT11)

void DHT11_IO_OUT(void);
void DHT11_IO_IN(void);
void DHT11_Init(void);//初始化DHT11
u8   DHT11_Read_Data(u8 *temp,u8 *humi);//读取温湿度
u8   DHT11_Read_Byte(void);//读出一个字节
u8   DHT11_Read_Bit(void);//读出一个位
u8   DHT11_Check(void);//检测是否存在DHT11
void DHT11_Rst(void);//复位DHT11    
#endif


