#ifndef __TIMER_H
#define __TIMER_H
#include "sys.h"

//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEKս��STM32������
//��ʱ�� ��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/9/4
//�汾��V1.1
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
//********************************************************************************

typedef struct 
	{  
		unsigned short int  TWO;        
    unsigned short int  FIVE;
    unsigned short int  SIX;		
		
		unsigned short int  CAN1_1T;
		unsigned short int  CAN1_2T;
		unsigned short int  CAN1_3T;
			
  }TIME;



void TIM3_Configuration(void);








#endif
