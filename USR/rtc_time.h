#ifndef _RTC_TIME_H
#define _RTC_TIME_H
#include "pbdata.h"

void Clock_Init(void);
void RTC_Configuration(void);
void GetRTCTime(T_STRUCT* time);
void RTC2Time(void);
u8 GetDate(T_STRUCT* time);
void SetRTCTime(T_STRUCT* time);
 void  RTCTick(void);



#endif
