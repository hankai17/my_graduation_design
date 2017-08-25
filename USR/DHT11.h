#ifndef __DHT11_H
#define __DHT11_H 
#include "pbdata.h"

#define IO_DHT11 GPIO_Pin_4
#define GPIO_DHT11 GPIOE

#define DHT11_DQ_High GPIO_SetBits(GPIO_DHT11,IO_DHT11)
#define DHT11_DQ_Low  GPIO_ResetBits(GPIO_DHT11,IO_DHT11)

void DHT11_IO_OUT(void);
void DHT11_IO_IN(void);
void DHT11_Init(void);//��ʼ��DHT11
u8   DHT11_Read_Data(u8 *temp,u8 *humi);//��ȡ��ʪ��
u8   DHT11_Read_Byte(void);//����һ���ֽ�
u8   DHT11_Read_Bit(void);//����һ��λ
u8   DHT11_Check(void);//����Ƿ����DHT11
void DHT11_Rst(void);//��λDHT11    
#endif


