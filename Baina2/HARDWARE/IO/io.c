#include "io.h"

void  V_ALARM_IO_INIT(void)                                //��ѹ�����˿�����
{
	 GPIO_InitTypeDef  GPIO_InitStructure;
 	
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOC, ENABLE);	
		
	 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2;				
	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		       //��������
	 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		   //IO���ٶ�Ϊ50MHz
	 GPIO_Init(GPIOA, &GPIO_InitStructure);					 
		
	 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;				
	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		       //��������
	 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		   //IO���ٶ�Ϊ50MHz
	 GPIO_Init(GPIOC, &GPIO_InitStructure);		
	
}

void  TEMP_IO_INIT(void)                                   //�¶ȱ����˿�����
{
	 GPIO_InitTypeDef  GPIO_InitStructure;
 	
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC, ENABLE);	
		
	 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;				
	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		     //��������
	 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
	 GPIO_Init(GPIOA, &GPIO_InitStructure);					 
		
	 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;				
	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		     //��������
	 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
	 GPIO_Init(GPIOB, &GPIO_InitStructure);	
	
	 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6;				
	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		     //��������
	 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
	 GPIO_Init(GPIOC, &GPIO_InitStructure);		
}

void	 KAIGUAN_IO_INIT(void)                               //�̵����˿�����
{
   GPIO_InitTypeDef  GPIO_InitStructure;
 	
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOC, ENABLE);	
		
	 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10;				
	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
	 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
	 GPIO_Init(GPIOA, &GPIO_InitStructure);					 
		
	 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9;				
	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		   //��������
	 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
	 GPIO_Init(GPIOC, &GPIO_InitStructure);		

}
	

