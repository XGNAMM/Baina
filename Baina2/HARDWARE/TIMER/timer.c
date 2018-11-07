#include "timer.h"

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
//V1.1 20120904
//1,����TIM3_PWM_Init������
//2,����LED0_PWM_VAL�궨�壬����TIM3_CH2����									  
//////////////////////////////////////////////////////////////////////////////////   	  
//ͨ�ö�ʱ��3�жϳ�ʼ��
//����ʱ��ѡ��ΪAPB1��2������APB1Ϊ36M
//arr���Զ���װֵ��
//psc��ʱ��Ԥ��Ƶ��
//����ʹ�õ��Ƕ�ʱ��3!



float TIM_Period_init;
const float T = 0.001;                            //tΪ�ж϶�ʱʱ�䣬��λΪs
#define TIM_Period_init T*1000*1000-1

void TIM3_Configuration(void)
{
    TIM_TimeBaseInitTypeDef                 TIM;
    NVIC_InitTypeDef         NVIC_InitStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	
    //��ʱ��TIM2��ʼ��
    TIM.TIM_Period = TIM_Period_init;                //�����Զ���װ�ؼĴ������ڵ�ֵ   1ms (TIM_Period * TIM_Prescaler)/TIM3 TIM3 = 72;
  	TIM.TIM_Prescaler = 72-1;                        //����ʱ��Ƶ�ʳ�����Ԥ��Ƶֵ  APB1 is 36MHz
    TIM.TIM_ClockDivision = TIM_CKD_DIV1;            //����ʱ�ӷָ�	
    TIM.TIM_CounterMode = TIM_CounterMode_Up;        //TIM���ϼ���
    TIM_TimeBaseInit(TIM3,&TIM);                     //��ʼ��TIM2
	  TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE );        //��������ж�
	
	  //�ж����ȼ�NVIC����
    NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;                //TIM2 �ж�
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;      //��ռ���ȼ� 2 ��
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;             //�����ȼ� 2 ��
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;                //IRQ ͨ����ʹ��
    NVIC_Init(&NVIC_InitStructure);                                //��ʼ�� NVIC �Ĵ���
   
	  TIM_Cmd(TIM3, ENABLE);                                         //ʹ��TIM2
}





















