#include "timer.h"

//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK战舰STM32开发板
//定时器 驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2012/9/4
//版本：V1.1
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2009-2019
//All rights reserved									  
//********************************************************************************
//V1.1 20120904
//1,增加TIM3_PWM_Init函数。
//2,增加LED0_PWM_VAL宏定义，控制TIM3_CH2脉宽									  
//////////////////////////////////////////////////////////////////////////////////   	  
//通用定时器3中断初始化
//这里时钟选择为APB1的2倍，而APB1为36M
//arr：自动重装值。
//psc：时钟预分频数
//这里使用的是定时器3!



float TIM_Period_init;
const float T = 0.001;                            //t为中断定时时间，单位为s
#define TIM_Period_init T*1000*1000-1

void TIM3_Configuration(void)
{
    TIM_TimeBaseInitTypeDef                 TIM;
    NVIC_InitTypeDef         NVIC_InitStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	
    //定时器TIM2初始化
    TIM.TIM_Period = TIM_Period_init;                //设置自动重装载寄存器周期的值   1ms (TIM_Period * TIM_Prescaler)/TIM3 TIM3 = 72;
  	TIM.TIM_Prescaler = 72-1;                        //设置时钟频率除数的预分频值  APB1 is 36MHz
    TIM.TIM_ClockDivision = TIM_CKD_DIV1;            //设置时钟分割	
    TIM.TIM_CounterMode = TIM_CounterMode_Up;        //TIM向上计数
    TIM_TimeBaseInit(TIM3,&TIM);                     //初始化TIM2
	  TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE );        //允许更新中断
	
	  //中断优先级NVIC设置
    NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;                //TIM2 中断
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;      //先占优先级 2 级
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;             //从优先级 2 级
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;                //IRQ 通道被使能
    NVIC_Init(&NVIC_InitStructure);                                //初始化 NVIC 寄存器
   
	  TIM_Cmd(TIM3, ENABLE);                                         //使能TIM2
}





















