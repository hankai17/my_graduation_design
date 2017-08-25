#include "pbdata.h"
const u8 font[9][72]={
{0x00,0x00,0x00,0x00,0x00,0x40,0x04,0x00,0x40,0x05,0xFE,0x40,0x04,0x92,0x40,0x04,0x92,0x40,

0x7F,0x13,0xFE,0x3F,0x13,0xFE,0x04,0x92,0x40,0x08,0x92,0x40,0x09,0xFE,0x40,0x04,0x04,0xC0,
0x04,0x04,0x40,0x04,0x44,0x00,0x04,0x44,0x00,0x7F,0xFF,0xFE,0x3F,0xFF,0xFC,0x04,0x44,0x20,
	0x04,0x44,0x20,0x04,0x44,0x30,0x08,0x84,0xF0,0x00,0x0F,0xC0,0x00,0x00,0x00,0x00,0x00,0x00},/*

"?",0*/
{0x00,0x00,0x00,0x01,0x20,0x00,0x1F,0xA3,0xFC,0x01,0x23,0xFC,0x01,0x22,0x08,0x01,0x22,0x10,

0x3F,0x22,0x10,0x21,0x22,0x12,0x01,0x22,0x22,0x01,0x7F,0x24,0x1F,0xBE,0x48,0x00,0x00,0x30,
	0x00,0x01,0xE0,0x1F,0xFF,0x80,0x08,0x00,0x00,0x08,0x00,0x00,0x08,0x00,0x00,0x08,0x00,0x00,
	0x1F,0xFF,0xFC,0x00,0x00,0x04,0x00,0x00,0x04,0x00,0x00,0x1C,0x00,0x00,0x04,0x00,0x00,0x00},/*

"?",1*/
{0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x80,0x88,0x20,0xE1,0xFC,0x18,0x43,0xC0,0x0C,0x1C,0x00,
	0x01,0xE0,0x02,0x02,0x04,0x02,0x00,0x03,0x02,0x1F,0xF1,0xE2,0x1F,0xF0,0x42,0x11,0x20,0x02,
	0x11,0x3F,0xFC,0x11,0x20,0x02,0x11,0x20,0x02,0x11,0x30,0x02,0x11,0x2F,0xFC,0x11,0x20,0x22,
0x11,0x20,0x42,0x3F,0xE1,0x82,0x10,0x07,0x04,0x00,0x06,0x04,0x00,0x00,0x00,0x00,0x00,0x00},/*"?",0*/
{0x00,0x00,0x00,0x00,0x00,0x06,0x00,0x00,0x18,0x00,0x03,0xE0,0x0F,0xFF,0x00,0x08,0x40,0x02,
	0x08,0x40,0x02,0x08,0x42,0x02,0x08,0x42,0x02,0x0C,0x42,0x04,0x0B,0xFB,0x84,0x4A,0x4A,0x48,
	0x38,0x4A,0x28,0x18,0x4A,0x10,0x08,0x4A,0x38,0x08,0x4A,0x68,0x0B,0xFB,0xCC,0x0A,0x43,0x04,
0x08,0x42,0x04,0x08,0x80,0x06,0x19,0x80,0x06,0x08,0x80,0x04,0x00,0x00,0x04,0x00,0x00,0x00},/*"?",1*/
//gao di ya wen :
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x0F,0xFE,0x04,0x07,0xFE,0x04,0x04,0x00,0x07,0xF4,0x00,0x05,0xE4,0x00,0x05,0x25,0xF0,0x05,0x25,0x10,0x45,0x25,0x10,0x35,0x25,0x10,0x15,0x25,0x10,0x05,0x25,0x10,0x05,0x25,0x10,0x05,0x27,0xF0,0x07,0xF4,0x04,0x05,0x04,0x04,0x04,0x04,0x04,0x04,0x07,0xFE,0x08,0x0F,0xFE,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"?",0*/
{0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x20,0x00,0x00,0xC0,0x00,0x03,0xFF,0xFE,0x0F,0xFF,0xFE,0x78,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x07,0xFF,0xFC,0x04,0x10,0x18,0x04,0x10,0x10,0x04,0x10,0x28,0x04,0x10,0x28,0x0E,0x10,0x46,0x0F,0xFE,0x00,0x08,0x13,0xC0,0x10,0x10,0x70,0x10,0x10,0x38,0x10,0x10,0x0C,0x00,0x30,0x0C,0x00,0x10,0x3C,0x00,0x00,0x00,0x00,0x00,0x00},/*"?",1*/
{0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x0C,0x00,0x00,0x30,0x1F,0xFF,0xC0,0x1F,0xFC,0x04,0x10,0x00,0x04,0x10,0x10,0x04,0x10,0x10,0x04,0x10,0x10,0x04,0x10,0x10,0x04,0x10,0x10,0x04,0x17,0xFF,0xF8,0x17,0xFF,0xF8,0x10,0x10,0x04,0x10,0x10,0x04,0x10,0x12,0x04,0x10,0x11,0x84,0x10,0x10,0xE4,0x30,0x10,0x44,0x30,0x00,0x08,0x10,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00},/*"?",2*/
{0x00,0x00,0x00,0x00,0x80,0x80,0x00,0xC0,0x80,0x20,0x60,0xFC,0x10,0x01,0xFC,0x1C,0x1E,0x02,0x01,0xE0,0x02,0x02,0x04,0x02,0x00,0x03,0xFC,0x1F,0xF2,0x02,0x11,0x12,0x02,0x11,0x12,0x02,0x11,0x13,0xFC,0x11,0x12,0x02,0x11,0x12,0x02,0x11,0x13,0xFC,0x11,0x12,0x02,0x11,0x12,0x02,0x1F,0xF2,0x02,0x10,0x07,0xFC,0x00,0x02,0x02,0x00,0x00,0x04,0x00,0x00,0x04,0x00,0x00,0x00},/*"?",3*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x18,0x00,0x07,0x38,0x00,0x07,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*":",4*/




};//�ȶ���2ά���� 4����һ����72���ֽ�

const u8 font_samll[20][24]={
{0x00,0x00,0x04,0x00,0x04,0x00,0x04,0x00,0x04,0x00,0x04,0x00,0x04,0x00,0x04,0x00,0x04,0x00,0x04,0x00,0x04,0x00,0x04,0x00},/*"?",0*/
{0x00,0x00,0x00,0x80,0x20,0x80,0x20,0x80,0x20,0x80,0x20,0x80,0x20,0x80,0x20,0x80,0x20,0x80,0x20,0x80,0x20,0x80,0x00,0x80},/*"?",1*/
{0x00,0x00,0x00,0x80,0x20,0x80,0x24,0x80,0x24,0x80,0x24,0x80,0x24,0x80,0x24,0x80,0x24,0x80,0x24,0x80,0x20,0x80,0x00,0x80},/*"?",2*/
{0x00,0x00,0x00,0x00,0x3F,0xC0,0x22,0x80,0x3C,0x80,0x20,0x80,0x20,0x80,0x3C,0x80,0x22,0x80,0x22,0x80,0x3F,0x80,0x00,0x00},/*"?",3*/
{0x00,0x00,0x00,0x00,0x00,0x80,0x24,0x80,0x25,0x80,0x3E,0x80,0x24,0x80,0x24,0x80,0x24,0x80,0x27,0x80,0x00,0x80,0x00,0x00},/*"?",4*/
{0x00,0x00,0x00,0x40,0x08,0x80,0x09,0x00,0x0A,0x00,0x48,0x00,0x28,0x00,0x08,0x00,0x0A,0x00,0x09,0x00,0x08,0x80,0x00,0x00},/*"?",5*/
{0x00,0x00,0x00,0x00,0x3F,0xC0,0x24,0x80,0x24,0x80,0x24,0x80,0x24,0x80,0x24,0x80,0x24,0x80,0x24,0x80,0x3F,0xC0,0x00,0x00},/*"?",6*/
{0x00,0x00,0x00,0x40,0x00,0x80,0x7F,0x00,0x4A,0x00,0x4A,0x00,0x4A,0x00,0x4A,0x00,0x4A,0x40,0x7F,0xC0,0x00,0x00,0x00,0x00},/*"?",7*/
{0x00,0x00,0x00,0x00,0x3F,0xC0,0x24,0x80,0x24,0x80,0x24,0x80,0x24,0x80,0x24,0x80,0x24,0x80,0x24,0x80,0x3F,0xC0,0x00,0x00},/*"?",8*/
{0x00,0x00,0x00,0x40,0x7F,0x80,0x40,0x00,0x53,0x00,0x56,0x80,0x7A,0x80,0x56,0x80,0x57,0x00,0x50,0x40,0x7F,0xC0,0x40,0x00},/*"?",9*/
{0x00,0x00,0x3F,0x00,0x20,0x80,0x40,0x80,0x40,0x80,0x31,0x00},/*"0",10*/
{0x00,0x00,0x20,0x00,0x20,0x00,0x7F,0x80,0x00,0x00,0x00,0x00},/*"1",11*/
{0x00,0x00,0x21,0x80,0x42,0x80,0x42,0x80,0x44,0x80,0x38,0x80},/*"2",12*/
{0x00,0x00,0x00,0x80,0x40,0x80,0x44,0x80,0x4C,0x80,0x33,0x00},/*"3",13*/
{0x02,0x00,0x05,0x00,0x09,0x00,0x11,0x00,0x21,0x00,0x7F,0x80},/*"4",14*/
{0x00,0x00,0x38,0x80,0x44,0x80,0x44,0x80,0x44,0x80,0x47,0x00},/*"5",15*/
{0x00,0x00,0x1F,0x00,0x24,0x80,0x48,0x80,0x48,0x80,0x44,0x80},/*"6",16*/
{0x40,0x00,0x40,0x00,0x41,0x80,0x46,0x00,0x58,0x00,0x60,0x00},/*"7",17*/
{0x00,0x00,0x37,0x00,0x48,0x80,0x44,0x80,0x44,0x80,0x3C,0x80},/*"8",18*/
{0x00,0x00,0x3C,0x80,0x44,0x80,0x42,0x80,0x44,0x80,0x37,0x00},/*"9",19*/

};



const u8 str[10][36]={
	{0x00,0x00,0x00,0x00,0x7F,0x80,0x01,0xFF,0xE0,0x03,0x80,0x70,0x06,0x00,0x18,0x04,0x00,0x08,0x04,0x00,0x08,0x06,0x00,0x18,0x03,0x80,0x70,0x01,0xFF,0xE0,0x00,0x7F,0x80,0x00,0x00,0x00},/*"0",0*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x08,0x01,0x00,0x08,0x01,0x00,0x08,0x03,0xFF,0xF8,0x07,0xFF,0xF8,0x00,0x00,0x08,0x00,0x00,0x08,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00},/*"1",1*/
{0x00,0x00,0x00,0x01,0xC0,0x38,0x02,0xC0,0x58,0x04,0x00,0x98,0x04,0x01,0x18,0x04,0x02,0x18,0x04,0x04,0x18,0x06,0x1C,0x18,0x03,0xF8,0x18,0x01,0xE0,0xF8,0x00,0x00,0x00,0x00,0x00,0x00},/*"2",2*/
{0x00,0x00,0x00,0x01,0xC0,0xE0,0x03,0xC0,0xF0,0x04,0x00,0x08,0x04,0x08,0x08,0x04,0x08,0x08,0x06,0x18,0x08,0x03,0xF4,0x18,0x01,0xE7,0xF0,0x00,0x01,0xE0,0x00,0x00,0x00,0x00,0x00,0x00},/*"3",3*/
{0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x0D,0x00,0x00,0x11,0x00,0x00,0x61,0x00,0x00,0x81,0x08,0x03,0x01,0x08,0x07,0xFF,0xF8,0x0F,0xFF,0xF8,0x00,0x01,0x08,0x00,0x01,0x08,0x00,0x00,0x00},/*"4",4*/
{0x00,0x00,0x00,0x00,0x00,0xE0,0x07,0xFC,0xD0,0x06,0x08,0x08,0x06,0x10,0x08,0x06,0x10,0x08,0x06,0x10,0x08,0x06,0x18,0x38,0x06,0x0F,0xF0,0x06,0x07,0xC0,0x00,0x00,0x00,0x00,0x00,0x00},/*"5",5*/
{0x00,0x00,0x00,0x00,0x3F,0x80,0x01,0xFF,0xE0,0x03,0x84,0x30,0x02,0x08,0x18,0x04,0x10,0x08,0x04,0x10,0x08,0x04,0x10,0x08,0x07,0x18,0x10,0x03,0x0F,0xF0,0x00,0x07,0xC0,0x00,0x00,0x00},/*"6",6*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xC0,0x00,0x07,0x00,0x00,0x06,0x00,0x00,0x06,0x00,0xF8,0x06,0x07,0xF8,0x06,0x18,0x00,0x06,0xE0,0x00,0x07,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x00},/*"7",7*/
{0x00,0x00,0x00,0x01,0xE1,0xE0,0x03,0xF7,0xF0,0x06,0x34,0x10,0x04,0x18,0x08,0x04,0x18,0x08,0x04,0x0C,0x08,0x04,0x0C,0x08,0x06,0x16,0x18,0x03,0xF3,0xF0,0x01,0xC1,0xE0,0x00,0x00,0x00},/*"8",8*/
{0x00,0x00,0x00,0x00,0xF8,0x00,0x03,0xFC,0x30,0x03,0x06,0x38,0x04,0x02,0x08,0x04,0x02,0x08,0x04,0x02,0x08,0x04,0x04,0x10,0x03,0x08,0xF0,0x01,0xFF,0xC0,0x00,0x7F,0x00,0x00,0x00,0x00}/*"9",9*/
};

const u8 str1[11][72]={
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xF8,0x00,0x00,0x00,0x07,0xFF,0xFF,0xC0,0x00,0x00,0x3C,0x00,0x00,0xF0,0x00,0x00,0x60,0x00,0x00,0x38,0x00,0x00,0xC0,0x00,0x00,0x0C,0x00,0x01,0x80,0x00,0x00,0x0C,0x00,0x01,0x80,0x00,0x00,0x06,0x00,0x01,0x80,0x00,0x00,0x0C,0x00,0x00,0xC0,0x00,0x00,0x1C,0x00,0x00,0x70,0x00,0x00,0x78,0x00,0x00,0x3F,0x80,0x07,0xE0,0x00},/*"0",0*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"1",1*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x00,0x00,0x30,0x00,0x01,0xFC,0x00,0x00,0x60,0x00,0x07,0x0C,0x00,0x00,0xC0,0x00,0x0C,0x0C,0x00,0x00,0xC0,0x00,0x38,0x0C,0x00,0x01,0x80,0x00,0x70,0x0C,0x00,0x01,0x80,0x00,0xC0,0x0C,0x00,0x01,0xC0,0x01,0x80,0x0C,0x00,0x00,0xC0,0x07,0x00,0x0C,0x00,0x00,0x70,0x1E,0x00,0x0C,0x00,0x00,0x3F,0xF8,0x00,0x0C,0x00},/*"2",2*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x1C,0x00,0x00,0xC0,0x06,0x00,0x0C,0x00,0x00,0xC0,0x06,0x00,0x0C,0x00,0x01,0x80,0x06,0x00,0x06,0x00,0x01,0x80,0x06,0x00,0x04,0x00,0x01,0x80,0x07,0x00,0x0C,0x00,0x00,0xC0,0x0F,0x00,0x0C,0x00,0x00,0xE0,0x19,0x80,0x18,0x00,0x00,0x3F,0xF0,0xE0,0x70,0x00,0x00,0x07,0x00,0x7F,0xC0,0x00},/*"3",3*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x00,0x00,0x00,0x00,0x00,0x7C,0x00,0x00,0x00,0x00,0x01,0xCC,0x00,0x00,0x00,0x00,0x07,0x0C,0x00,0x00,0x00,0x00,0x1C,0x0C,0x00,0x00,0x00,0x00,0x70,0x0C,0x00,0x00,0x00,0x03,0xC0,0x0C,0x00,0x00,0x00,0x0E,0x00,0x0C,0x00,0x00,0x00,0x78,0x00,0x0C,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFC,0x00,0x00,0x00,0x00,0x0C,0x00,0x00},/*"4",4*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x00,0x00,0xFF,0xFC,0x00,0x0C,0x00,0x00,0xF8,0x0C,0x00,0x0C,0x00,0x00,0xC0,0x0C,0x00,0x06,0x00,0x00,0xC0,0x0C,0x00,0x06,0x00,0x00,0xC0,0x0C,0x00,0x0C,0x00,0x00,0xC0,0x0E,0x00,0x0C,0x00,0x00,0xC0,0x07,0x00,0x18,0x00,0x00,0xC0,0x03,0x80,0x70,0x00,0x00,0xC0,0x01,0xFF,0xE0,0x00},/*"5",5*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x80,0x00,0x00,0x0F,0xC1,0xC1,0xF0,0x00,0x00,0x3C,0x06,0x00,0x38,0x00,0x00,0x70,0x0C,0x00,0x0C,0x00,0x00,0xE0,0x18,0x00,0x0C,0x00,0x00,0xC0,0x18,0x00,0x06,0x00,0x01,0x80,0x18,0x00,0x0C,0x00,0x01,0x80,0x1C,0x00,0x0C,0x00,0x01,0x80,0x0E,0x00,0x18,0x00,0x00,0xC0,0x07,0x80,0xF0,0x00},/*"6",6*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x3C,0x00,0x00,0xC0,0x00,0x07,0xFC,0x00,0x00,0xC0,0x00,0x7E,0x00,0x00,0x00,0xC0,0x07,0xE0,0x00,0x00,0x00,0xC0,0x3E,0x00,0x00,0x00,0x00,0xC1,0xE0,0x00,0x00,0x00,0x00,0xCF,0x00,0x00,0x00,0x00,0x00,0xF8,0x00,0x00,0x00,0x00},/*"7",7*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0E,0x00,0x00,0x00,0x0F,0xC0,0x7F,0xE0,0x00,0x00,0x3F,0xF1,0xC0,0x78,0x00,0x00,0xE0,0x1B,0x00,0x1C,0x00,0x00,0xC0,0x0E,0x00,0x0C,0x00,0x01,0x80,0x06,0x00,0x0C,0x00,0x01,0x80,0x06,0x00,0x04,0x00,0x01,0x80,0x06,0x00,0x0C,0x00,0x00,0xC0,0x0F,0x00,0x0C,0x00,0x00,0x70,0x3B,0x80,0x18,0x00,0x00,0x3F,0xE0,0xF0,0xF0,0x00},/*"8",8*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xE0,0x00,0x00,0x00,0x00,0x1F,0xFE,0x00,0x1C,0x00,0x00,0x78,0x07,0x80,0x0C,0x00,0x00,0xE0,0x01,0xC0,0x0C,0x00,0x00,0xC0,0x00,0xC0,0x06,0x00,0x01,0x80,0x00,0xE0,0x0C,0x00,0x01,0x80,0x00,0x40,0x0C,0x00,0x01,0xC0,0x00,0xC0,0x1C,0x00,0x00,0xC0,0x01,0xC0,0x38,0x00,0x00,0x70,0x03,0x00,0xE0,0x00,0x00,0x3F,0xFC,0x3F,0x80,0x00},/*"9",9*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x00,0x1C,0x00,0x00,0x00,0xF0,0x00,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*":",0*/


};

void LCD_WR_REG(u16 index)
{
	*(__IO u16 *)(Bank1_LCD_C)=index;//ǿ��ת����ָ�����ͣ�ָ����Ļ�С��������ƣ�д�����������
}

void LCD_WR_Data(u16 val)
{
   *(__IO u16 *)(Bank1_LCD_D)=val;
}

void LCD_WR_CMD(u16 index,u16 val)
{
   *(__IO u16 *)(Bank1_LCD_C)=index;
   *(__IO u16 *)(Bank1_LCD_D)=val;
}


void ILI9325_Init(void)
{
    GPIO_ResetBits(GPIOE, GPIO_Pin_1);	  //Ӳ����λ
    delay(0xAFFf);					   
    GPIO_SetBits(GPIOE, GPIO_Pin_1 );		 
	delay(0xAFFf);	
	
	LCD_WR_CMD(0x0001, 0x0100); // set SS and SM bit
	LCD_WR_CMD(0x0002, 0x0700); // set 1 line inversion
	LCD_WR_CMD(0x0003, 0x1030); // set GRAM write direction and BGR=1.
	LCD_WR_CMD(0x0004, 0x0000); // Resize register
	LCD_WR_CMD(0x0008, 0x0207); // set the back porch and front porch
	LCD_WR_CMD(0x0009, 0x0000); // set non-display area refresh cycle ISC[3:0]
	LCD_WR_CMD(0x000A, 0x0000); // FMARK function
	LCD_WR_CMD(0x000C, 0x0000); // RGB interface setting
	LCD_WR_CMD(0x000D, 0x0000); // Frame marker Position
	LCD_WR_CMD(0x000F, 0x0000); // RGB interface polarity
	
	LCD_WR_CMD(0x0010, 0x0000); // SAP, BT[3:0], AP, DSTB, SLP, STB
	LCD_WR_CMD(0x0011, 0x0007); // DC1[2:0], DC0[2:0], VC[2:0]
	LCD_WR_CMD(0x0012, 0x0000); // VREG1OUT voltage
	LCD_WR_CMD(0x0013, 0x0000); // VDV[4:0] for VCOM amplitude
	LCD_WR_CMD(0x0007, 0x0001);
	delay(12000); // Dis-charge capacitor power voltage
	LCD_WR_CMD(0x0010, 0x1490); // SAP, BT[3:0], AP, DSTB, SLP, STB
	LCD_WR_CMD(0x0011, 0x0227); // DC1[2:0], DC0[2:0], VC[2:0]
	delay(15500); // Delay 50ms
	LCD_WR_CMD(0x0012, 0x001C); // Internal reference voltage= Vci;
	delay(15000); // Delay 50ms
	LCD_WR_CMD(0x0013, 0x1A00); // Set VDV[4:0] for VCOM amplitude
	LCD_WR_CMD(0x0029, 0x0025); // Set VCM[5:0] for VCOMH
	LCD_WR_CMD(0x002B, 0x000C); // Set Frame Rate
	delay(15000); // Delay 50ms
	LCD_WR_CMD(0x0020, 0x0000); // GRAM horizontal Address
	LCD_WR_CMD(0x0021, 0x0000); // GRAM Vertical Address
	// ----------- Adjust the Gamma Curve ----------//
	LCD_WR_CMD(0x0030, 0x0000);
	LCD_WR_CMD(0x0031, 0x0506);
	LCD_WR_CMD(0x0032, 0x0104);
	LCD_WR_CMD(0x0035, 0x0207);
	LCD_WR_CMD(0x0036, 0x000F);
	LCD_WR_CMD(0x0037, 0x0306);
	LCD_WR_CMD(0x0038, 0x0102);
	LCD_WR_CMD(0x0039, 0x0707);
	LCD_WR_CMD(0x003C, 0x0702);
	LCD_WR_CMD(0x003D, 0x1604);
	//------------------ Set GRAM area ---------------//
	LCD_WR_CMD(0x0050, 0x0000); // Horizontal GRAM Start Address
	LCD_WR_CMD(0x0051, 0x00EF); // Horizontal GRAM End Address
	LCD_WR_CMD(0x0052, 0x0000); // Vertical GRAM Start Address
	LCD_WR_CMD(0x0053, 0x013F); // Vertical GRAM Start Address
	LCD_WR_CMD(0x0060, 0xA700); // Gate Scan Line
	LCD_WR_CMD(0x0061, 0x0001); // NDL,VLE, REV

	LCD_WR_CMD(0x006A, 0x0000); // set scrolling line
	//-------------- Partial Display Control ---------//
	LCD_WR_CMD(0x0080, 0x0000);
	LCD_WR_CMD(0x0081, 0x0000);
	LCD_WR_CMD(0x0082, 0x0000);
	LCD_WR_CMD(0x0083, 0x0000);
	LCD_WR_CMD(0x0084, 0x0000);			   
	LCD_WR_CMD(0x0085, 0x0000);
	//-------------- Panel Control -------------------//
	LCD_WR_CMD(0x0090, 0x0010);
	LCD_WR_CMD(0x0092, 0x0600);
	LCD_WR_CMD(0x0007, 0x0133); // 262K color and display ON	  
}

//240*320

void ILI_9325_Draw_Point(u8 x,u16 y,u16 color)//
{
	LCD_WR_CMD(0x50,x);	//x��ʼ�����д�x��ַ��ʼ��0x50�ǳ��õ�����
	LCD_WR_CMD(0x51,x);	//x���������е�x��ַ����
	LCD_WR_CMD(0x52,y);	//y��ʼ
	LCD_WR_CMD(0x53,y);	//y����
//��ɻ�����
	LCD_WR_CMD(0x20,x);//�е�ַ
	LCD_WR_CMD(0x21,y);//�е�ַ����ȷ��ĳ����
	LCD_WR_REG(0x22);//д���ݵ�gram
	LCD_WR_Data(color);//д����
}

void ILI_9325_CLEAR(u16 color)//���� ͬһ����ɫ
{
	u16 i=0,j=0;//ѭ��

	for(i=0;i<240;i++)
	{
		for(j=0;j<320;j++)
		{
			ILI_9325_Draw_Point(i,j,color);
		}
	}
}
//����������
void show_Font(u16 x,u16 y,u8 id,u16 qj,u16 bj)//����ʾ��λ�� id�Ǽ����ǵڼ�����
// ǰ����ɫ ������ɫ
{
	u8 k=0,temp=0,t=0,y0=0;//

	y0=y;//��ֵ

	for(k=0;k<72;k++)
	{
		temp=font[id][k];
		for(t=0;t<8;t++)//ÿ���ֽڶ���8λ ��λ��ǰ
		{
			if(temp&0x80)//������
			 	ILI_9325_Draw_Point(x,y,qj);//�е����ǰ��ɫ
			else
				ILI_9325_Draw_Point(x,y,bj);//�޵���Ǳ���ɫ

			temp<<=1;//������һλ
			y++;
			if((y-y0)==24)//һ�����꣬�����Ͻ�������
			{
				y=y0;//y����0,x+1
				x++;
				break;//����for
			}
		}
	}
}

void show_Str(u16 x,u16 y,u8 id,u16 qj,u16 bj)//��ʾ��ģ��������һ��
{
	u8 k=0,temp=0,t=0,y0=0;

	y0=y;//��ֵ

	for(k=0;k<36;k++)
	{
		temp=str[id][k];
		for(t=0;t<8;t++)
		{
			if(temp&0x80)
			 	ILI_9325_Draw_Point(x,y,qj);
			else
				ILI_9325_Draw_Point(x,y,bj);

			temp<<=1;
			y++;
			if((y-y0)==24)
			{
				y=y0;
				x++;
				break;
			}
		}
	}
}

void TFT_Draw_Rectangle(u16 x1,u16 y1,u16 x2,u16 y2,u16 color)//��ʾɫ��
{
	u16 i=0,j=0;

	for(i=x1;i<x2;i++)
	{
		for(j=y1;j<y2;j++)
		{
			ILI_9325_Draw_Point(i,j,color);
		}
	}
}

void show_Str_Big(u16 x,u16 y,u8 id,u16 qj,u16 bj)//��ʾ��ģ��������һ��
{
	u8 k=0,temp=0,t=0,y0=0;

	y0=y;//��ֵ

	for(k=0;k<36;k++)
	{
		temp=str[id][k];
		for(t=0;t<8;t++)
		{
			if(temp&0x80)
			 	ILI_9325_Draw_Point(x,y,qj);
			else
				ILI_9325_Draw_Point(x,y,bj);

			temp<<=1;
			y++;
			if((y-y0)==24)
			{
				y=y0;
				x++;
				break;
			}
		}
	}
}

void show_Str1(u16 x,u16 y,u8 id,u16 qj,u16 bj)
{
	u8 k=0,temp=0,t=0,y0=0;

	y0=y;//��ֵ

	for(k=0;k<72;k++)
	{
		temp=str1[id][k];
		for(t=0;t<8;t++)
		{
			if(temp&0x80)
			 	ILI_9325_Draw_Point(x,y,qj);
			else
				ILI_9325_Draw_Point(x,y,bj);

			temp<<=1;
			y++;
			if((y-y0)==48)
			{
				y=y0;
				x++;
				break;
			}
		}
	}
}

void show_Font1(u16 x,u16 y,u8 id,u16 qj,u16 bj)//����ʾ��λ�� id�Ǽ����ǵڼ�����
// ǰ����ɫ ������ɫ
{
	u8 k=0,temp=0,t=0,y0=0;//

	y0=y;//��ֵ

	for(k=0;k<24;k++)
	{
		temp=font_samll[id][k];
		for(t=0;t<8;t++)//ÿ���ֽڶ���8λ ��λ��ǰ
		{
			if(temp&0x80)//������
			 	ILI_9325_Draw_Point(x,y,qj);//�е����ǰ��ɫ
			else
				ILI_9325_Draw_Point(x,y,bj);//�޵���Ǳ���ɫ

			temp<<=1;//������һλ
			y++;
			if((y-y0)==12)//һ�����꣬�����Ͻ�������
			{
				y=y0;//y����0,x+1
				x++;
				break;//����for
			}
		}
	}
}

