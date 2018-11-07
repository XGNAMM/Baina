#include "AD7924.h"


/****************************************************
*                  ���ݿƼ�
*�������ƣ�SPI_ReadWriteByte
*����˵����SPIЭ����ӻ����ͺͶ�ȡ����
*����˵�����ӻ��Ĵ�����ֵ
*�������أ��Ĵ�������ֵ
*�޸�ʱ�䣺2018/10/21    V1.0    WHD
*��    ע: ��
****************************************************/

signed short int SPI_ReadWriteByte(signed short int TxData)                                      
{		
	u16 bit_ctr;
	
	  CS_L;    //ʹ��spi���
	
   	for(bit_ctr=0;bit_ctr<16;bit_ctr++) 
   	{
			if(TxData & 0x8000)
				DIN_H;         
			else
				DIN_L;
			TxData = (TxData << 1);           
			SCLK_H; 
			Delay(0xff);
			Delay(0xff);
			if(DOUT)                     
				TxData |= 0x01;       		  
			SCLK_L; 
			Delay(0xff); 
      Delay(0xff);			
   	}
		
		CS_H;    //��ֹspi���

    return(TxData);           		  		    
}

/****************************************************
*                  ���ݿƼ�
*�������ƣ�AD7924_READ
*����˵����AD7924ͨ���ɼ�����ADCֵ  ��Χ0-4096
*����˵�����ӻ��Ĵ�����ֵ
*�������أ��Ĵ�������ֵ
*�޸�ʱ�䣺2018/10/21    V1.0    WHD
*��    ע: ��
****************************************************/

void AD7924_READ(unsigned int *V0_ADC,unsigned int *V1_ADC,unsigned int *V2_ADC,unsigned int *V3_ADC)
{
	  *V3_ADC = SPI_ReadWriteByte(0x8310)&0X0FFF;    //ͨ��0��������0x8310 ad7924�ķ���ֵ����һ���趨��ͨ�����á�
		Delay(0xff);
		Delay(0xff);
		*V0_ADC = SPI_ReadWriteByte(0x8710)&0X0FFF;
		Delay(0xff);
		Delay(0xff);
		*V1_ADC = SPI_ReadWriteByte(0x8B10)&0X0FFF;
		Delay(0xff);
		Delay(0xff);
		*V2_ADC = SPI_ReadWriteByte(0x8F10)&0X0FFF;
		Delay(0xff);		
		Delay(0xff);
}

void Delay(int nCount)
{
  for(; nCount != 0; nCount--);
}

/*******************��ʼ��spiͨѶio��****************************/
void AD7924_IO_INIT(void)
{
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOD, ENABLE);	
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12;				
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
 GPIO_Init(GPIOC, &GPIO_InitStructure);					 
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;				
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		   //��������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
 GPIO_Init(GPIOD, &GPIO_InitStructure);			
	
	CS_H;          //��ֹ�Կ��ƼĴ��������
	SCLK_H;  
  Delay(0xff);
  Delay(0xff);	 //ʱ���źŴ���״̬

}









