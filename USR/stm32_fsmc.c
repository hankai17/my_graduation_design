#include "pbdata.h"

void FSMC_Configuration(void)
{
  FSMC_NORSRAMInitTypeDef  FSMC_NORSRAMInitStructure;
  FSMC_NORSRAMTimingInitTypeDef  p;  

  p.FSMC_AddressSetupTime = 0x02;//��ַ����ʱ��
  p.FSMC_AddressHoldTime = 0x00;//��ַ����ʱ��
  p.FSMC_DataSetupTime = 0x05;//���ݽ���ʱ��
  p.FSMC_BusTurnAroundDuration = 0x00;//���߻ָ�ʱ��
  p.FSMC_CLKDivision = 0x00;//ʱ�ӷ�Ƶ
  p.FSMC_DataLatency = 0x00;//���ݱ���ʱ��
  p.FSMC_AccessMode = FSMC_AccessMode_B;

  //NOR FLASH �� BANK1
  FSMC_NORSRAMInitStructure.FSMC_Bank = FSMC_Bank1_NORSRAM1;
  //���������ַ�߲�����
  FSMC_NORSRAMInitStructure.FSMC_DataAddressMux = FSMC_DataAddressMux_Disable;
  //�洢������ NOR FLASH
  FSMC_NORSRAMInitStructure.FSMC_MemoryType = FSMC_MemoryType_NOR;
  //���ݿ��Ϊ 16 λ
  FSMC_NORSRAMInitStructure.FSMC_MemoryDataWidth = FSMC_MemoryDataWidth_16b;
  //ʹ���첽дģʽ����ֹͻ��ģʽ
  FSMC_NORSRAMInitStructure.FSMC_BurstAccessMode = FSMC_BurstAccessMode_Disable;
  //����Ա������ֻ��ͻ��ģʽ����Ч���ȴ��źż���Ϊ��
  FSMC_NORSRAMInitStructure.FSMC_WaitSignalPolarity = FSMC_WaitSignalPolarity_Low;
  //��ֹ�Ƕ���ͻ��ģʽ
  FSMC_NORSRAMInitStructure.FSMC_WrapMode = FSMC_WrapMode_Disable;
  //����Ա���ý���ͻ��ģʽ����Ч��NWAIT �ź���ʲôʱ�ڲ���
  FSMC_NORSRAMInitStructure.FSMC_WaitSignalActive = FSMC_WaitSignalActive_BeforeWaitState;
  //����Ա������ֻ��ͻ��ģʽ����Ч������ NWAIT �ź�
  FSMC_NORSRAMInitStructure.FSMC_WriteOperation = FSMC_WriteOperation_Enable;
  //��ֹͻ��д����
  FSMC_NORSRAMInitStructure.FSMC_WaitSignal = FSMC_WaitSignal_Disable;
  //дʹ��
  FSMC_NORSRAMInitStructure.FSMC_ExtendedMode = FSMC_ExtendedMode_Disable;
  //��ֹ��չģʽ����չģʽ����ʹ�ö����Ķ���дģʽ
  FSMC_NORSRAMInitStructure.FSMC_WriteBurst = FSMC_WriteBurst_Disable;
  //���ö�дʱ��
  FSMC_NORSRAMInitStructure.FSMC_ReadWriteTimingStruct = &p;
  //����дʱ��
  FSMC_NORSRAMInitStructure.FSMC_WriteTimingStruct = &p;

  //��ʼ��FSMC
  FSMC_NORSRAMInit(&FSMC_NORSRAMInitStructure); 
  //ʹ��FSMC BANK1_SRAM ģʽ
  FSMC_NORSRAMCmd(FSMC_Bank1_NORSRAM1, ENABLE);  
}
