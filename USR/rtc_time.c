#include "pbdata.h"


static T_STRUCT Real_Time;

void RTC_Configuration(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR,ENABLE);//开后备电源时钟 让纽扣电池工作
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_BKP,ENABLE);//开后备 域 ，一个存储空间
	PWR_BackupAccessCmd(ENABLE);//允许访问bkp区域
	//BKP_DeInit();//复位bkp//第一次运行要复位 第二次屏蔽掉否则每次重启都是初试时间
	RCC_LSEConfig(RCC_LSE_ON);//开外部晶振 那个圆柱32.768K低速的那个
	while(RCC_GetFlagStatus(RCC_FLAG_LSERDY)==RESET);//等待晶振稳定 就是外部低速晶振就绪就可以执行下一条
	RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);//选择rtc外部时钟为低速晶振
  RCC_RTCCLKCmd(ENABLE);//使能rtc时钟
	
	RTC_WaitForSynchro();//等待rtc寄存器同步 只有apb1和rtc时钟同步才能数据交换，要等待
	RTC_WaitForLastTask();// 等待写rtc寄存器完成 即 写的时候判断是否能够写入，所以要等待上一个任务完成才能写
	
	RTC_ITConfig(RTC_IT_SEC,ENABLE);//使能秒中断，因为对rtc寄存器写了 所以要判断
	RTC_WaitForLastTask();// 等待写rtc寄存器完成 即 写的时候判断是否能够写入，所以要等待上一个任务完成才能写
  
	RTC_SetPrescaler(32767);//设置预分频，同理
	RTC_WaitForLastTask();// 等待写rtc寄存器完成 即 写的时候判断是否能够写入，所以要等待上一个任务完成才能写
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
void RTC2Time(void)//把后备寄存器的值给Real 经过一番判断 再把Real给后备寄存器
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




void Clock_Init(void)//rtc时钟初始化函数，cpu第一次执行的时候要运行上面的函数 断电后由纽扣电池供电，不用执行上面的函数 只执行本函数就可以 要是执行上面的函数就相当于断电后 再启动就从0开始了
{
	if(BKP_ReadBackupRegister(BKP_DR1)!=0xA5A5)//判断BKP_ReadBackupRegister寄存器中的复位标志
	{//第一次运行，则进行初始化设置
		//RTC初始化
		RTC_Configuration();//......
		RTC_WaitForLastTask();//等待写寄存器完成
		Real_Time.year = 2013;
  Real_Time.month = 1;
  Real_Time.day = 1;
  Real_Time.hour = 12;
  Real_Time.minute = 0;
  Real_Time.sec = 0;
  Real_Time.date = 1;
		SetRTCTime(&Real_Time);
		RTC_WaitForLastTask();//等待
		
		BKP_WriteBackupRegister(BKP_DR1,0xA5A5);//写标志配置
  }
 	else
	{
		RTC_WaitForSynchro();//等待rtc寄存器同步 只有apb1和rtc时钟同步才能数据交换，要等待
	  RTC_WaitForLastTask();// 等待写rtc寄存器完成 即 写的时候判断是否能够写入，所以要等待上一个任务完成才能写
	   RTC2Time();
		RTC_ITConfig(RTC_IT_SEC,ENABLE);//使能秒中断，因为对rtc寄存器写了 所以要判断,cpu断电秒中断使能是不保存的
		RTC_WaitForLastTask();
  }
	RCC_ClearFlag();//清楚复位标志
}

