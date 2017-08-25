#include "pbdata.h"


static T_STRUCT Real_Time;

void RTC_Configuration(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR,ENABLE);//���󱸵�Դʱ�� ��Ŧ�۵�ع���
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_BKP,ENABLE);//���� �� ��һ���洢�ռ�
	PWR_BackupAccessCmd(ENABLE);//�������bkp����
	//BKP_DeInit();//��λbkp//��һ������Ҫ��λ �ڶ������ε�����ÿ���������ǳ���ʱ��
	RCC_LSEConfig(RCC_LSE_ON);//���ⲿ���� �Ǹ�Բ��32.768K���ٵ��Ǹ�
	while(RCC_GetFlagStatus(RCC_FLAG_LSERDY)==RESET);//�ȴ������ȶ� �����ⲿ���پ�������Ϳ���ִ����һ��
	RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);//ѡ��rtc�ⲿʱ��Ϊ���پ���
  RCC_RTCCLKCmd(ENABLE);//ʹ��rtcʱ��
	
	RTC_WaitForSynchro();//�ȴ�rtc�Ĵ���ͬ�� ֻ��apb1��rtcʱ��ͬ���������ݽ�����Ҫ�ȴ�
	RTC_WaitForLastTask();// �ȴ�дrtc�Ĵ������ �� д��ʱ���ж��Ƿ��ܹ�д�룬����Ҫ�ȴ���һ��������ɲ���д
	
	RTC_ITConfig(RTC_IT_SEC,ENABLE);//ʹ�����жϣ���Ϊ��rtc�Ĵ���д�� ����Ҫ�ж�
	RTC_WaitForLastTask();// �ȴ�дrtc�Ĵ������ �� д��ʱ���ж��Ƿ��ܹ�д�룬����Ҫ�ȴ���һ��������ɲ���д
  
	RTC_SetPrescaler(32767);//����Ԥ��Ƶ��ͬ��
	RTC_WaitForLastTask();// �ȴ�дrtc�Ĵ������ �� д��ʱ���ж��Ƿ��ܹ�д�룬����Ҫ�ȴ���һ��������ɲ���д
}


void GetRTCTime(T_STRUCT* time)
{
        RTC_ITConfig(RTC_IT_SEC, DISABLE);        //?????
        RTC_WaitForLastTask();
        time->year=Real_Time.year;
        time->month=Real_Time.month;
        time->day=Real_Time.day;
        time->hour=Real_Time.hour;
        time->minute=Real_Time.minute;
        time->sec=Real_Time.sec;
        time->date=Real_Time.date;
        RTC_WaitForLastTask();
        RTC_ITConfig(RTC_IT_SEC, ENABLE); //?????
}

const u8 Month2Day_Tab[12]={31,28,31,30,31,30,31,31,30,31,30,31} ;
void RTC2Time(void)//�Ѻ󱸼Ĵ�����ֵ��Real ����һ���ж� �ٰ�Real���󱸼Ĵ���
{
        u32 count;
        u8 tmp,change=0;

        Real_Time.year=BKP_ReadBackupRegister(BKP_TIME_YEAR);
        Real_Time.month=BKP_ReadBackupRegister(BKP_TIME_MONTH);
        Real_Time.day=BKP_ReadBackupRegister(BKP_TIME_DAY);
        Real_Time.date=BKP_ReadBackupRegister(BKP_TIME_DATE);

        RTC_ITConfig(RTC_IT_SEC, DISABLE);       
        count=RTC_GetCounter();
       
        while (count>=0x0001517f)        
        {
                change=1;
                count-=0x0001517f;
               
                if ((++Real_Time.date)>=8)
                        Real_Time.date=1;

               
                if (Real_Time.month==2)
                {
                        if (Real_Time.year%4)
                                tmp=28;
                        else
                                tmp=29;
                }
                else
                {
                        tmp=Month2Day_Tab[Real_Time.month-1];
                }
                if ((++Real_Time.day)>tmp)
                {
                        Real_Time.day=1;

                        if ((++Real_Time.month)>12)
                        {
                                Real_Time.month=1;

                                if ((++Real_Time.year)>=100)
                                {
                                        Real_Time.year=0;
                                }
                        }
                }
        }
        
        Real_Time.hour=count/3600;
        Real_Time.minute=(count%3600)/60;
        Real_Time.sec=(count%3600)%60;

       
        if (change)
        {
                RTC_SetCounter(count);
                BKP_WriteBackupRegister(BKP_TIME_DATE,Real_Time.date);
                BKP_WriteBackupRegister(BKP_TIME_DAY,Real_Time.day);
                BKP_WriteBackupRegister(BKP_TIME_MONTH,Real_Time.month);
                BKP_WriteBackupRegister(BKP_TIME_YEAR,Real_Time.year);
        }
     
        RTC_ITConfig(RTC_IT_SEC, ENABLE);
}


const u8 TAB_DATE[12]={6,2,2,5,0,3,5,1,4,6,2,4,};
u8 GetDate(T_STRUCT* time)
{
        return( (time->year + time->year/4 - ( (time->month<3)&&(time->year%4==0) ) + TAB_DATE[time->month-1] + time->day )%7);
} 


void SetRTCTime(T_STRUCT* time)
{
        u32 count;
        RTC_ITConfig(RTC_IT_SEC, DISABLE);        

        RTC_WaitForLastTask();
        
        Real_Time.year=time->year;
        Real_Time.month=time->month;
        Real_Time.day=time->day;
        Real_Time.hour=time->hour;
        Real_Time.minute=time->minute;
        Real_Time.sec=time->sec;
        
        time->date=Real_Time.date=GetDate(time);

        

        BKP_WriteBackupRegister(BKP_TIME_DATE,Real_Time.date);
//        RTC_WaitForLastTask();
        BKP_WriteBackupRegister(BKP_TIME_DAY,Real_Time.day);
//        RTC_WaitForLastTask();
        BKP_WriteBackupRegister(BKP_TIME_MONTH,Real_Time.month);
//        RTC_WaitForLastTask();
        BKP_WriteBackupRegister(BKP_TIME_YEAR,Real_Time.year);
//        RTC_WaitForLastTask();

       
        count=Real_Time.hour*3600+Real_Time.minute*60+Real_Time.sec;
        RTC_WaitForLastTask();
        RTC_SetCounter(count);
				RTC_WaitForLastTask();
				RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);  
      
       PWR_BackupAccessCmd(ENABLE);
        RTC_WaitForLastTask();
        RTC_ITConfig(RTC_IT_SEC, ENABLE); 
}

 void  RTCTick(void)
{
        u8 tmp;
        if ((++Real_Time.sec)>59)
        {
                Real_Time.sec=0;
                if ((++Real_Time.minute)>59)
                {
                        Real_Time.minute=0;
                        if ((++Real_Time.hour)>23)
                        {
                                Real_Time.hour=0;
                                //????
                                if ((++Real_Time.date)>=8)
                                        Real_Time.date=1;
                                //--??????
                                BKP_WriteBackupRegister(BKP_DR5,Real_Time.date);

                                //???2?,????(?????2099???400????)
                                if (Real_Time.month==2)
                                {
                                        if (Real_Time.year%4)
                                                tmp=28;
                                        else
                                                tmp=29;
                                }
                                else
                                {
                                        tmp=Month2Day_Tab[Real_Time.month-1];
                                }
                                if ((++Real_Time.day)>tmp)
                                {
                                        Real_Time.day=1;
                                        if ((++Real_Time.month)>12)
                                        {
                                                Real_Time.month=1;

                                                if ((++Real_Time.year)>99)
                                                {

                                                        Real_Time.year=0;
                                                }
                                                //--?????
                                                BKP_WriteBackupRegister(BKP_DR2,Real_Time.year);
                                        }
                                        //--?????
                                        BKP_WriteBackupRegister(BKP_DR3,Real_Time.month);
                                }
                                //--?????
                                BKP_WriteBackupRegister(BKP_DR4,Real_Time.day);
                        }
                }
        }
}




void Clock_Init(void)//rtcʱ�ӳ�ʼ��������cpu��һ��ִ�е�ʱ��Ҫ��������ĺ��� �ϵ����Ŧ�۵�ع��磬����ִ������ĺ��� ִֻ�б������Ϳ��� Ҫ��ִ������ĺ������൱�ڶϵ�� �������ʹ�0��ʼ��
{
	if(BKP_ReadBackupRegister(BKP_DR1)!=0xA5A5)//�ж�BKP_ReadBackupRegister�Ĵ����еĸ�λ��־
	{//��һ�����У�����г�ʼ������
		//RTC��ʼ��
		RTC_Configuration();//......
		RTC_WaitForLastTask();//�ȴ�д�Ĵ������
		Real_Time.year = 2013;
  Real_Time.month = 1;
  Real_Time.day = 1;
  Real_Time.hour = 12;
  Real_Time.minute = 0;
  Real_Time.sec = 0;
  Real_Time.date = 1;
		SetRTCTime(&Real_Time);
		RTC_WaitForLastTask();//�ȴ�
		
		BKP_WriteBackupRegister(BKP_DR1,0xA5A5);//д��־����
  }
 	else
	{
		RTC_WaitForSynchro();//�ȴ�rtc�Ĵ���ͬ�� ֻ��apb1��rtcʱ��ͬ���������ݽ�����Ҫ�ȴ�
	  RTC_WaitForLastTask();// �ȴ�дrtc�Ĵ������ �� д��ʱ���ж��Ƿ��ܹ�д�룬����Ҫ�ȴ���һ��������ɲ���д
	   RTC2Time();
		RTC_ITConfig(RTC_IT_SEC,ENABLE);//ʹ�����жϣ���Ϊ��rtc�Ĵ���д�� ����Ҫ�ж�,cpu�ϵ����ж�ʹ���ǲ������
		RTC_WaitForLastTask();
  }
	RCC_ClearFlag();//�����λ��־
}

