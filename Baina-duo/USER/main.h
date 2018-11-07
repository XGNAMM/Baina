#ifndef __MAIN_H
#define __MAIN_H	 

#include "led.h"
#include "delay.h"
#include "sys.h"
#include "timer.h"
#include "AD7924.h"
#include "adc.h"
#include "C.h"             //����������������ʼ��
#include "duo_ku.h"
#include "io.h"



void IO_init(void)
{
   AD7924_IO_INIT();		                            //AD7924�˿����� 
// DS18B20_IO_INIT();                               //DS18B20�˿�����
	
	 V_ALARM_IO_INIT();                               //��ѹ�����˿�����
	 TEMP_IO_INIT();                                  //�¶ȱ����˿�����
	 LED_Init();                                      //ָʾ�ƶ˿�����
	 KAIGUAN_IO_INIT();                               //�̵����˿�����
	 Adc_Init();                                      //adc�����ɼ��˿�����B1
	
}


void USER_INIT(void)
{
	 SystemInit();
	 delay_init();	    	                             //��ʱ������ʼ��	  
	 NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 	 //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
 	 IO_init();                                        //ȫ��io�ڳ�ʼ��
   delay_ms(10);	                                   //�˿����ú��һ����ٿ���
   TIM3_Configuration();                             //��ʼ��1ms �ж�
	
}


void IO_init(void);
void USER_INIT(void);




#endif
