#ifndef __LED_H
#define __LED_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEKս��STM32������
//LED��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/9/2
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 
#define LED0 PBout(5)// PB5
#define LED1 PBout(4)// PE5	

void LED_Init(void);//��ʼ��


#define  LED1_H      GPIO_SetBits(GPIOB,GPIO_Pin_10)	 
#define  LED1_L      GPIO_ResetBits(GPIOB,GPIO_Pin_10)
#define  LED2_H      GPIO_SetBits(GPIOB,GPIO_Pin_11)	 
#define  LED2_L      GPIO_ResetBits(GPIOB,GPIO_Pin_11)
#define  LED3_H      GPIO_SetBits(GPIOB,GPIO_Pin_14)	 
#define  LED3_L      GPIO_ResetBits(GPIOB,GPIO_Pin_14)
#define  LED4_H      GPIO_SetBits(GPIOB,GPIO_Pin_15)	 
#define  LED4_L      GPIO_ResetBits(GPIOB,GPIO_Pin_15)

 				    
#endif






