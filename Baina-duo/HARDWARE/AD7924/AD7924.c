#include "AD7924.h"


/****************************************************
*                  名遁科技
*函数名称：SPI_ReadWriteByte
*功能说明：SPI协议向从机发送和读取数据
*参数说明：从机寄存器赋值
*函数返回：寄存器返回值
*修改时间：2018/10/21    V1.0    WHD
*备    注: 无
****************************************************/

signed short int SPI_ReadWriteByte(signed short int TxData)                                      
{		
	u16 bit_ctr;
	
	  CS_L;    //使能spi输出
	
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
		
		CS_H;    //禁止spi输出

    return(TxData);           		  		    
}

/****************************************************
*                  名遁科技
*函数名称：AD7924_READ
*功能说明：AD7924通道采集到的ADC值  范围0-4096
*参数说明：从机寄存器赋值
*函数返回：寄存器返回值
*修改时间：2018/10/21    V1.0    WHD
*备    注: 无
****************************************************/

void AD7924_READ(unsigned int *V0_ADC,unsigned int *V1_ADC,unsigned int *V2_ADC,unsigned int *V3_ADC)
{
	  *V3_ADC = SPI_ReadWriteByte(0x8310)&0X0FFF;    //通道0的配置是0x8310 ad7924的返回值是上一次设定的通道配置。
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

/*******************初始化spi通讯io口****************************/
void AD7924_IO_INIT(void)
{
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOD, ENABLE);	
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12;				
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOC, &GPIO_InitStructure);					 
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;				
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		   //上拉输入
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOD, &GPIO_InitStructure);			
	
	CS_H;          //防止对控制寄存器误操作
	SCLK_H;  
  Delay(0xff);
  Delay(0xff);	 //时钟信号待命状态

}









