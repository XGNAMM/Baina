#ifndef _MAIN_H
#define _MAIN_H

//������ͷ�ļ�
#include "stm32f10x.h"
#include "timer.h"
#include "adc.h"
#include "delay.h"
#include "can.h"
#include "usart.h"	
#include "sys.h"
#include "stmflash.h"
#include "wdg.h"
#include "can_send.h"
#include "io.h"
#include "led.h"
#include "C.h"                                  //����������������ʼ��
#include "baina_task.h"
#include "AD7924.h"
#include "duo_ku.h"
#include "ds18b20.h"


DATA sysdata={{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0}};   //�����ڲ�����
 

void IO_init(void)
{
	
   AD7924_IO_INIT();		                            //AD7924�˿����� 
   DS18B20_Init();                                  //DS18B20�˿�����	
	 V_ALARM_IO_INIT();                               //��ѹ�����˿�����
	 TEMP_IO_INIT();                                  //�¶ȱ����˿�����
	 LED_Init();                                      //ָʾ�ƶ˿�����
	 KAIGUAN_IO_INIT();                               //�̵����˿�����
	 Adc_Init();                                      //adc�����ɼ��˿�����B1
	
}

void USER_INIT(void)
{
	
	 SystemInit();                                     //ϵͳ��ʼ��
	 delay_init();	    	                             //��ʱ������ʼ��	  
	 NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 	 //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
 	 IO_init();                                        //ȫ��io�ڳ�ʼ��
   delay_ms(10);	                                   //�˿����ú��һ����ٿ���
	 CAN_bound_Init(CAN_1,CAN_500K);                   //CAN1��ʼ��������500K
	 CAN_bound_Init(CAN_2,CAN_500K);                   //CAN2��ʼ��������500K
   TIM3_Configuration();                             //��ʼ��1ms �ж�
	 
}

void IO_init(void);
void USER_INIT(void);




#endif


