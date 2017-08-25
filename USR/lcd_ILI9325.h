#ifndef _LCD_ILI9325_H
#define _LCD_ILI9325_H
#include "pbdata.h"


//6000 0000
//A16  16为通讯

#define Bank1_LCD_D (u32)0x60020000
#define Bank1_LCD_C (u32)0x60000000

#define RGB565(r, g, b) ((r >> 3) << 11 | (g >> 2) << 5 | (b >> 3))//颜色转换

#define RED   RGB565(255,0,0)		//红色  会调用颜色转换函数转换成屏幕颜色
#define GREEN RGB565(0,255,0)		//绿色
#define BLUE  RGB565(0,0,255)		//蓝色
#define BLACK RGB565(0,0,0)			//黑色
#define WHITE RGB565(255,255,255)	//白色
//接下来 画点看。c文件

void ILI9325_Init(void);
void LCD_WR_REG(u16 index);
void LCD_WR_Data(u16 val);
void LCD_WR_CMD(u16 index,u16 val);

void ILI_9325_Draw_Point(u8 x,u16 y,u16 color);
void ILI_9325_CLEAR(u16 color);

void show_Font(u16 x,u16 y,u8 id,u16 qj,u16 bj);
void show_Font1(u16 x,u16 y,u8 id,u16 qj,u16 bj);
void show_Str(u16 x,u16 y,u8 id,u16 qj,u16 bj);
void show_Str1(u16 x,u16 y,u8 id,u16 qj,u16 bj);
void TFT_Draw_Rectangle(u16 x1,u16 y1,u16 x2,u16 y2,u16 color);

#endif
