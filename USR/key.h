#ifndef _KEY_H
#define _KEY_H
#include "pbdata.h"

#define Hang_00_L  GPIO_ResetBits(GPIOC, GPIO_Pin_1)
#define Hang_00_H  GPIO_SetBits(GPIOC, GPIO_Pin_1)

#define Hang_01_L  GPIO_ResetBits(GPIOC, GPIO_Pin_3)
#define Hang_01_H  GPIO_SetBits(GPIOC, GPIO_Pin_3)

#define Hang_02_L  GPIO_ResetBits(GPIOA, GPIO_Pin_1)
#define Hang_02_H  GPIO_SetBits(GPIOA, GPIO_Pin_1)

#define Hang_03_L  GPIO_ResetBits(GPIOA, GPIO_Pin_3)
#define Hang_03_H  GPIO_SetBits(GPIOA, GPIO_Pin_3)

#define Lie_00_V GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5)
#define Lie_01_V GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_7)
#define Lie_02_V GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5)
#define Lie_03_V GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)
#define  jpys 100


int KEY_Scanf(void);




#endif
