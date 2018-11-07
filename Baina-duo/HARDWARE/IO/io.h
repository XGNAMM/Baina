#ifndef __IO_H
#define __IO_H

#include "sys.h"

void   V_ALARM_IO_INIT(void);                               //过压报警端口配置
void   TEMP_IO_INIT(void);                                  //温度报警端口配置
void	 A_IO_INIT(void);                                     //电流端口配置
void	 KAIGUAN_IO_INIT(void);                               //继电器端口配置

#define ALARM_1 GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_3)     //电压报警1
#define ALARM_2 GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)     //电压报警2
#define ALARM_3 GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_1)     //电压报警3
#define ALARM_4 GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_2)     //电压报警4

#define NTC1H GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_4)       //电容器1上限温度报警
#define NTC1L GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5)       //电容器1下限温度报警
#define NTC2H GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6)       //电容器2上限温度报警
#define NTC2L GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_7)       //电容器2下限温度报警
#define NTC3H GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_4)       //电容器3上限温度报警
#define NTC3L GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5)       //电容器3下限温度报警
#define NTC4H GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0)       //电容器4上限温度报警
#define NTC4L GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6)       //电容器4下限温度报警

#define  S1_H  GPIO_SetBits(GPIOA,GPIO_Pin_10)                  //继电器输出口1开
#define  S1_L  GPIO_ResetBits(GPIOA,GPIO_Pin_10)                //继电器输出口1关
#define  S2_H  GPIO_SetBits(GPIOA,GPIO_Pin_9)                   //继电器输出口2开
#define  S2_L  GPIO_ResetBits(GPIOA,GPIO_Pin_9)                 //继电器输出口2关
#define  S3_H  GPIO_SetBits(GPIOA,GPIO_Pin_8)                   //继电器输出口3开
#define  S3_L  GPIO_ResetBits(GPIOA,GPIO_Pin_8)                 //继电器输出口3关
#define  S4_H  GPIO_SetBits(GPIOC,GPIO_Pin_7)                   //继电器输出口4开
#define  S4_L  GPIO_ResetBits(GPIOC,GPIO_Pin_7)                 //继电器输出口4关
#define  S5_H  GPIO_SetBits(GPIOC,GPIO_Pin_8)                   //继电器输出口5开
#define  S5_L  GPIO_ResetBits(GPIOC,GPIO_Pin_8)                 //继电器输出口5关
#define  S6_H  GPIO_SetBits(GPIOC,GPIO_Pin_9)                   //继电器输出口6开
#define  S6_L  GPIO_ResetBits(GPIOC,GPIO_Pin_9)                 //继电器输出口6关



#endif



