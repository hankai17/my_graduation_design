#include "pbdata.h"
#include "rtc_time.h"
void RCC_Configuration(void);//配置系统时钟
void GPIO_Configuration(void);//端口配置
void NVIC_Configuration(void);//配置中断优先级
void USART_Configuration(void);//串口配置
void ADC_Configuration(void);
void match(void);
void Start_Ad(void);
void KEY_IN(void);
//在公共函数库里定义变量
int data_L,data_H,Sum,max;
int fputc(int ch,FILE *f)
{  USART_SendData(USART1,(u8)ch);
	while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET);//判断数据是否发送完成，否则等待
	//若发送完成
	return ch;
}//进入选项 use micro lib

int main(void)
{
	//int i=0;
	int j=0;
	u8 wd=0;
	u8 sd=0;
	T_STRUCT Set_Time;
	//T_STRUCT Get_Time;
	
   RCC_Configuration();	//系统时钟初始化
   GPIO_Configuration();//端口初始化
   USART_Configuration();
   NVIC_Configuration();
	 ADC_Configuration();
	 RTC_Configuration();
	 Clock_Init();//
	 FSMC_Configuration();
   ILI9325_Init();
   delay_ms(1000);
   ILI_9325_CLEAR(WHITE);
	DHT11_Init();
	
    
	
   while(1)	
	{ 

		DHT11_Read_Data(&wd,&sd);
		show_Font(10,35,7,BLACK,WHITE);
		show_Font(35,35,3,BLACK,WHITE);
		show_Str(60,35,wd/10,BLACK,WHITE);
		show_Str(75,35,wd%10,BLACK,WHITE);
		show_Font(100,35,2,RED,WHITE);
		show_Font(125,35,3,RED,WHITE);
		show_Str(150,35,sd/10,BLACK,WHITE);
		show_Str(165,35,sd%10,BLACK,WHITE);	

		
			KEY_IN();
			if(j<14)
   	  {
				show_Str(10+j*15,10,a1[j],WHITE,WHITE);//显字母
				
				j++;
			}
			else
			{
				j=0;
			}
			Set_Time.year=a1[0]*1000+a1[1]*100+a1[2]*10+a1[3];
			Set_Time.month=a1[4]*10+a1[5];
			Set_Time.day=a1[6]*10+a1[7];
			Set_Time.hour=a1[8]*10+a1[9];
			Set_Time.minute=a1[10]*10+a1[11];
			Set_Time.sec=a1[12]*10+a1[13];
		if(KEY_Scanf()==12)
				
					{	SetRTCTime(&Set_Time);
							//Clock_Init();
					}
		if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5)==Bit_RESET)
		{
			//LED 发光
			GPIO_ResetBits(GPIOB,GPIO_Pin_5);
			match();
			GPIO_SetBits(GPIOB,GPIO_Pin_5);
			data_H=0.8*max;//规则   
			data_L=0.5*max;   
			show_Font(10,230,4,BLACK,WHITE);
		show_Font(35,230,6,BLACK,WHITE);
		show_Font(60,230,8,BLACK,WHITE);
		show_Str(75,230,data_H/1000%10,BLACK,WHITE);
		show_Str(90,230,data_H/100%10,BLACK,WHITE);
		show_Str(105,230,data_H/10%10,BLACK,WHITE);
		show_Str(120,230,data_H/1%10,BLACK,WHITE);
	
		show_Font(10,255,5,BLACK,WHITE);
		show_Font(35,255,6,BLACK,WHITE);
		show_Font(60,255,8,BLACK,WHITE);
		show_Str(75,255,data_L/1000%10,BLACK,WHITE);
		show_Str(90,255,data_L/100%10,BLACK,WHITE);
		show_Str(105,255,data_L/10%10,BLACK,WHITE);
		show_Str(120,255,data_L/1%10,BLACK,WHITE);
		}
		else
		{
		   //LED 熄灭
		   GPIO_SetBits(GPIOB,GPIO_Pin_5);
		}
		
  }
}
void RCC_Configuration(void)
{
    SystemInit();//72m
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//常识pa9pa10
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);//开d和e
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1,ENABLE);//开adc1时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC2,ENABLE);//开adc2时钟
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);//12M 把72M分成12M保证不超过14M
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_FSMC,ENABLE);//fsmc在ahb时钟上
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);//串口1挂在apb2,常识
}


void GPIO_Configuration(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;	
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;//TX
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA,&GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10;//RX
	//注意输入不需要口线翻转速度
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	
	//键盘输出
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1|GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Init(GPIOA,&GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1|GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	//键盘输入
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5|GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	
	
	
	//FSMC  管脚初始化

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_13;//背光源
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;//推完输出
	GPIO_Init(GPIOD,&GPIO_InitStructure);
	GPIO_SetBits(GPIOD,GPIO_Pin_13);//打开背光

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1;//复位是管脚1
	GPIO_Init(GPIOE,&GPIO_InitStructure);//复位管脚 也是推完输出 格式与上一样可以省略
	
	//启用fsmc复用功能 复用上拉模式do---d15

	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_14 //D0
								|GPIO_Pin_15 //D1
								|GPIO_Pin_0	 //D2
								|GPIO_Pin_1	 //D3
								|GPIO_Pin_8	 //D13
								|GPIO_Pin_9	 //D14
								|GPIO_Pin_10;//D15
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;//复用上拉
	GPIO_Init(GPIOD,&GPIO_InitStructure);//d管脚的

	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_7	 //D4
								|GPIO_Pin_8	 //D5
								|GPIO_Pin_9	 //D6
								|GPIO_Pin_10 //D7
								|GPIO_Pin_11 //D8
								|GPIO_Pin_12 //D9
								|GPIO_Pin_13 //D10
								|GPIO_Pin_14 //D11
								|GPIO_Pin_15;//D12
	GPIO_Init(GPIOE,&GPIO_InitStructure);//e管脚的//可以省


	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_11 //RS高数低命
								|GPIO_Pin_4	 //nOE
								|GPIO_Pin_5; //nWE
	GPIO_Init(GPIOD,&GPIO_InitStructure);
  // 两者要分开写
	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_7; //NE1//配置cs
	GPIO_Init(GPIOD,&GPIO_InitStructure);
	/******************ad******************/
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AIN;//模拟量输入模式
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5;//Key
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;;
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_4;//MT
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_OD;
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5;//、、灯   管脚 最高输出频率 以及输入输出方式
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;//上拉推完上拉输出
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	
}

void NVIC_Configuration(void)
{
   	NVIC_InitTypeDef NVIC_InitStructure; 

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1); 

	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn; 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1; 
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
	NVIC_Init(&NVIC_InitStructure);
	//rtc中断优先级设置
	NVIC_InitStructure.NVIC_IRQChannel = RTC_IRQn; 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;//没有串口优先级高 
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
	NVIC_Init(&NVIC_InitStructure);
}

void USART_Configuration(void)
{
    USART_InitTypeDef  USART_InitStructure;

	USART_InitStructure.USART_BaudRate=9600;//96n81格式
	USART_InitStructure.USART_WordLength=USART_WordLength_8b;//8个数据位
	USART_InitStructure.USART_StopBits=USART_StopBits_1;//1个停止位
	USART_InitStructure.USART_Parity=USART_Parity_No;//无校验位
	USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;//无硬件流控制
	USART_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;//发收使能

	USART_Init(USART1,&USART_InitStructure);//初始化
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);//开接受中断，接收到数据就进入中断
	USART_Cmd(USART1,ENABLE);//开串口
	USART_ClearFlag(USART1,USART_FLAG_TC);//清空中断标志位
}

void ADC_Configuration(void)
{		
	ADC_InitTypeDef ADC_InitStructure;
	
	ADC_InitStructure.ADC_Mode=ADC_Mode_Independent;//独立模式
	ADC_InitStructure.ADC_ScanConvMode=DISABLE;//扫描模式，单通道扫描，单次采集
  ADC_InitStructure.ADC_ContinuousConvMode=DISABLE;//单次采集
	ADC_InitStructure.ADC_ExternalTrigConv=ADC_ExternalTrigConv_None;//软件来触发
	ADC_InitStructure.ADC_DataAlign=ADC_DataAlign_Right;//右对齐
	ADC_InitStructure.ADC_NbrOfChannel=1;//通道个数为1
	
	ADC_Init(ADC1,&ADC_InitStructure);
	
	ADC_InitStructure.ADC_Mode=ADC_Mode_Independent;//独立模式
	ADC_InitStructure.ADC_ScanConvMode=DISABLE;//扫描模式，单通道扫描，单次采集
  ADC_InitStructure.ADC_ContinuousConvMode=DISABLE;//单次采集
	ADC_InitStructure.ADC_ExternalTrigConv=ADC_ExternalTrigConv_None;//软件来触发
	ADC_InitStructure.ADC_DataAlign=ADC_DataAlign_Right;//右对齐
	ADC_InitStructure.ADC_NbrOfChannel=1;//通道个数为1
	
	ADC_Init(ADC2,&ADC_InitStructure);
	
//写规则组
	ADC_RegularChannelConfig(ADC1,ADC_Channel_10,1,ADC_SampleTime_239Cycles5);// adc1    10号通道，1个通道，采样间隔时间
	ADC_RegularChannelConfig(ADC2,ADC_Channel_12,1,ADC_SampleTime_239Cycles5);
	ADC_Cmd(ADC1,ENABLE);//使能
  ADC_Cmd(ADC2,ENABLE);
  ADC_ResetCalibration(ADC1);//复位  
	ADC_ResetCalibration(ADC2);
  while(ADC_GetResetCalibrationStatus(ADC1));//是否复位完成ADC_GetResetCalibrationStatus(ADC1)
	while(ADC_GetResetCalibrationStatus(ADC2));
	ADC_StartCalibration(ADC1);//开始校准
	ADC_StartCalibration(ADC2);
	while(ADC_GetCalibrationStatus(ADC1));//是否校准完成
  while(ADC_GetCalibrationStatus(ADC2));
  ADC_SoftwareStartConvCmd(ADC1,ENABLE);//启动ad
	ADC_SoftwareStartConvCmd(ADC2,ENABLE);

}


void KEY_IN(void)
{
	int i1=KEY_Scanf();
	if(i1!=10)
		{
		
		a1[con]=i1;
		con++;		
			if(con==14)
			{
				con=0;
			}
		 }
}

void match()
{
		GPIO_SetBits(GPIOC,GPIO_Pin_4);//开马达
			Start_Ad();
			while(data_L<1800)
			{
				Start_Ad();
			}
			GPIO_ResetBits(GPIOC,GPIO_Pin_4);//关闭马达
			max=0;//脉搏波清零
			while(data_L>900)//放到、90之前都要ad转换
			{
				Start_Ad();
				if(data_L>1800)     
					data_L=1800;    
					
				if(max<data_H)
					max=data_H;//max是脉搏波最大值
			}
		/*
			data_H=0.8*max;//规则   
			data_L=0.5*max;   
			Sum=0.48*max;
			Start_Ad();
			*/
	
}

void Start_Ad()
{
	
	int i;
		for(i=0;i<30;i++)
		{  
			 ADC_SoftwareStartConvCmd(ADC1,ENABLE);//启动ad
			 ADC_SoftwareStartConvCmd(ADC2,ENABLE);
			 //while(!ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC));//没转换完 等待 完了下一句
			 data_L=data_L+ADC_GetConversionValue(ADC1);
			 data_H=data_H+ADC_GetConversionValue(ADC2);
		}
		data_L=data_L/30;
		data_H=data_H/30;
		delay_ms(100);
		//GPIO_SetBits(GPIOB,GPIO_Pin_5);
		show_Font(10,230,4,BLACK,WHITE);
		show_Font(35,230,6,BLACK,WHITE);
		show_Font(60,230,8,BLACK,WHITE);
		show_Str(75,230,data_H/1000%10,BLACK,WHITE);
		show_Str(90,230,data_H/100%10,BLACK,WHITE);
		show_Str(105,230,data_H/10%10,BLACK,WHITE);
		show_Str(120,230,data_H/1%10,BLACK,WHITE);
	
		show_Font(10,255,5,BLACK,WHITE);
		show_Font(35,255,6,BLACK,WHITE);
		show_Font(60,255,8,BLACK,WHITE);
		show_Str(75,255,data_L/1000%10,BLACK,WHITE);
		show_Str(90,255,data_L/100%10,BLACK,WHITE);
		show_Str(105,255,data_L/10%10,BLACK,WHITE);
		show_Str(120,255,data_L/1%10,BLACK,WHITE);
			
		//printf("data_L=%d\r\n",data_L);
		//printf("data_H=%d\r\n",data_H);	
}



