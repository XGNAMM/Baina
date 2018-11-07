#ifndef _MAIN_H
#define _MAIN_H

//包含的头文件
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
#include "C.h"                                  //超级电容器变量初始化
#include "baina_task.h"
#include "AD7924.h"
#include "duo_ku.h"
#include "ds18b20.h"


DATA sysdata={{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0}};   //板子内部数据
 

void IO_init(void)
{
	
   AD7924_IO_INIT();		                            //AD7924端口配置 
   DS18B20_Init();                                  //DS18B20端口配置	
	 V_ALARM_IO_INIT();                               //过压报警端口配置
	 TEMP_IO_INIT();                                  //温度报警端口配置
	 LED_Init();                                      //指示灯端口配置
	 KAIGUAN_IO_INIT();                               //继电器端口配置
	 Adc_Init();                                      //adc电流采集端口配置B1
	
}

void USER_INIT(void)
{
	
	 SystemInit();                                     //系统初始化
	 delay_init();	    	                             //延时函数初始化	  
	 NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
 	 IO_init();                                        //全部io口初始化
   delay_ms(10);	                                   //端口配置后等一会儿再控制
	 CAN_bound_Init(CAN_1,CAN_500K);                   //CAN1初始化波特率500K
	 CAN_bound_Init(CAN_2,CAN_500K);                   //CAN2初始化波特率500K
   TIM3_Configuration();                             //初始化1ms 中断
	 
}

void IO_init(void);
void USER_INIT(void);




#endif


