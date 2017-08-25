#include "pbdata.h"
#include "rtc_time.h"
void RCC_Configuration(void);//����ϵͳʱ��
void GPIO_Configuration(void);//�˿�����
void NVIC_Configuration(void);//�����ж����ȼ�
void USART_Configuration(void);//��������
void ADC_Configuration(void);
void match(void);
void Start_Ad(void);
void KEY_IN(void);
//�ڹ����������ﶨ�����
int data_L,data_H,Sum,max;
int fputc(int ch,FILE *f)
{  USART_SendData(USART1,(u8)ch);
	while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET);//�ж������Ƿ�����ɣ�����ȴ�
	//���������
	return ch;
}//����ѡ�� use micro lib

int main(void)
{
	//int i=0;
	int j=0;
	u8 wd=0;
	u8 sd=0;
	T_STRUCT Set_Time;
	//T_STRUCT Get_Time;
	
   RCC_Configuration();	//ϵͳʱ�ӳ�ʼ��
   GPIO_Configuration();//�˿ڳ�ʼ��
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
				show_Str(10+j*15,10,a1[j],WHITE,WHITE);//����ĸ
				
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
			//LED ����
			GPIO_ResetBits(GPIOB,GPIO_Pin_5);
			match();
			GPIO_SetBits(GPIOB,GPIO_Pin_5);
			data_H=0.8*max;//����   
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
		   //LED Ϩ��
		   GPIO_SetBits(GPIOB,GPIO_Pin_5);
		}
		
  }
}
void RCC_Configuration(void)
{
    SystemInit();//72m
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//��ʶpa9pa10
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);//��d��e
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1,ENABLE);//��adc1ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC2,ENABLE);//��adc2ʱ��
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);//12M ��72M�ֳ�12M��֤������14M
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_FSMC,ENABLE);//fsmc��ahbʱ����
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);//����1����apb2,��ʶ
}


void GPIO_Configuration(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;	
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;//TX
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA,&GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10;//RX
	//ע�����벻��Ҫ���߷�ת�ٶ�
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	
	//�������
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1|GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Init(GPIOA,&GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1|GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	//��������
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5|GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	
	
	
	//FSMC  �ܽų�ʼ��

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_13;//����Դ
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;//�������
	GPIO_Init(GPIOD,&GPIO_InitStructure);
	GPIO_SetBits(GPIOD,GPIO_Pin_13);//�򿪱���

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1;//��λ�ǹܽ�1
	GPIO_Init(GPIOE,&GPIO_InitStructure);//��λ�ܽ� Ҳ��������� ��ʽ����һ������ʡ��
	
	//����fsmc���ù��� ��������ģʽdo---d15

	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_14 //D0
								|GPIO_Pin_15 //D1
								|GPIO_Pin_0	 //D2
								|GPIO_Pin_1	 //D3
								|GPIO_Pin_8	 //D13
								|GPIO_Pin_9	 //D14
								|GPIO_Pin_10;//D15
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;//��������
	GPIO_Init(GPIOD,&GPIO_InitStructure);//d�ܽŵ�

	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_7	 //D4
								|GPIO_Pin_8	 //D5
								|GPIO_Pin_9	 //D6
								|GPIO_Pin_10 //D7
								|GPIO_Pin_11 //D8
								|GPIO_Pin_12 //D9
								|GPIO_Pin_13 //D10
								|GPIO_Pin_14 //D11
								|GPIO_Pin_15;//D12
	GPIO_Init(GPIOE,&GPIO_InitStructure);//e�ܽŵ�//����ʡ


	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_11 //RS��������
								|GPIO_Pin_4	 //nOE
								|GPIO_Pin_5; //nWE
	GPIO_Init(GPIOD,&GPIO_InitStructure);
  // ����Ҫ�ֿ�д
	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_7; //NE1//����cs
	GPIO_Init(GPIOD,&GPIO_InitStructure);
	/******************ad******************/
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AIN;//ģ��������ģʽ
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5;//Key
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;;
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_4;//MT
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_OD;
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5;//������   �ܽ� ������Ƶ�� �Լ����������ʽ
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;//���������������
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
	//rtc�ж����ȼ�����
	NVIC_InitStructure.NVIC_IRQChannel = RTC_IRQn; 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;//û�д������ȼ��� 
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
	NVIC_Init(&NVIC_InitStructure);
}

void USART_Configuration(void)
{
    USART_InitTypeDef  USART_InitStructure;

	USART_InitStructure.USART_BaudRate=9600;//96n81��ʽ
	USART_InitStructure.USART_WordLength=USART_WordLength_8b;//8������λ
	USART_InitStructure.USART_StopBits=USART_StopBits_1;//1��ֹͣλ
	USART_InitStructure.USART_Parity=USART_Parity_No;//��У��λ
	USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;//��Ӳ��������
	USART_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;//����ʹ��

	USART_Init(USART1,&USART_InitStructure);//��ʼ��
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);//�������жϣ����յ����ݾͽ����ж�
	USART_Cmd(USART1,ENABLE);//������
	USART_ClearFlag(USART1,USART_FLAG_TC);//����жϱ�־λ
}

void ADC_Configuration(void)
{		
	ADC_InitTypeDef ADC_InitStructure;
	
	ADC_InitStructure.ADC_Mode=ADC_Mode_Independent;//����ģʽ
	ADC_InitStructure.ADC_ScanConvMode=DISABLE;//ɨ��ģʽ����ͨ��ɨ�裬���βɼ�
  ADC_InitStructure.ADC_ContinuousConvMode=DISABLE;//���βɼ�
	ADC_InitStructure.ADC_ExternalTrigConv=ADC_ExternalTrigConv_None;//���������
	ADC_InitStructure.ADC_DataAlign=ADC_DataAlign_Right;//�Ҷ���
	ADC_InitStructure.ADC_NbrOfChannel=1;//ͨ������Ϊ1
	
	ADC_Init(ADC1,&ADC_InitStructure);
	
	ADC_InitStructure.ADC_Mode=ADC_Mode_Independent;//����ģʽ
	ADC_InitStructure.ADC_ScanConvMode=DISABLE;//ɨ��ģʽ����ͨ��ɨ�裬���βɼ�
  ADC_InitStructure.ADC_ContinuousConvMode=DISABLE;//���βɼ�
	ADC_InitStructure.ADC_ExternalTrigConv=ADC_ExternalTrigConv_None;//���������
	ADC_InitStructure.ADC_DataAlign=ADC_DataAlign_Right;//�Ҷ���
	ADC_InitStructure.ADC_NbrOfChannel=1;//ͨ������Ϊ1
	
	ADC_Init(ADC2,&ADC_InitStructure);
	
//д������
	ADC_RegularChannelConfig(ADC1,ADC_Channel_10,1,ADC_SampleTime_239Cycles5);// adc1    10��ͨ����1��ͨ�����������ʱ��
	ADC_RegularChannelConfig(ADC2,ADC_Channel_12,1,ADC_SampleTime_239Cycles5);
	ADC_Cmd(ADC1,ENABLE);//ʹ��
  ADC_Cmd(ADC2,ENABLE);
  ADC_ResetCalibration(ADC1);//��λ  
	ADC_ResetCalibration(ADC2);
  while(ADC_GetResetCalibrationStatus(ADC1));//�Ƿ�λ���ADC_GetResetCalibrationStatus(ADC1)
	while(ADC_GetResetCalibrationStatus(ADC2));
	ADC_StartCalibration(ADC1);//��ʼУ׼
	ADC_StartCalibration(ADC2);
	while(ADC_GetCalibrationStatus(ADC1));//�Ƿ�У׼���
  while(ADC_GetCalibrationStatus(ADC2));
  ADC_SoftwareStartConvCmd(ADC1,ENABLE);//����ad
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
		GPIO_SetBits(GPIOC,GPIO_Pin_4);//�����
			Start_Ad();
			while(data_L<1800)
			{
				Start_Ad();
			}
			GPIO_ResetBits(GPIOC,GPIO_Pin_4);//�ر����
			max=0;//����������
			while(data_L>900)//�ŵ���90֮ǰ��Ҫadת��
			{
				Start_Ad();
				if(data_L>1800)     
					data_L=1800;    
					
				if(max<data_H)
					max=data_H;//max�����������ֵ
			}
		/*
			data_H=0.8*max;//����   
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
			 ADC_SoftwareStartConvCmd(ADC1,ENABLE);//����ad
			 ADC_SoftwareStartConvCmd(ADC2,ENABLE);
			 //while(!ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC));//ûת���� �ȴ� ������һ��
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



