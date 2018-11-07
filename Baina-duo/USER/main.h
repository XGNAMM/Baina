#ifndef __MAIN_H
#define __MAIN_H	 

#include "led.h"
#include "delay.h"
#include "sys.h"
#include "timer.h"
#include "AD7924.h"
#include "adc.h"
#include "C.h"             //超级电容器变量初始化
#include "duo_ku.h"
#include "io.h"



void IO_init(void)
{
   AD7924_IO_INIT();		                            //AD7924端口配置 
// DS18B20_IO_INIT();                               //DS18B20端口配置
	
	 V_ALARM_IO_INIT();                               //过压报警端口配置
	 TEMP_IO_INIT();                                  //温度报警端口配置
	 LED_Init();                                      //指示灯端口配置
	 KAIGUAN_IO_INIT();                               //继电器端口配置
	 Adc_Init();                                      //adc电流采集端口配置B1
	
}


void USER_INIT(void)
{
	 SystemInit();
	 delay_init();	    	                             //延时函数初始化	  
	 NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
 	 IO_init();                                        //全部io口初始化
   delay_ms(10);	                                   //端口配置后等一会儿再控制
   TIM3_Configuration();                             //初始化1ms 中断
	
}


void IO_init(void);
void USER_INIT(void);




#endif
