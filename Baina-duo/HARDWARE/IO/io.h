#ifndef __IO_H
#define __IO_H

#include "sys.h"

void   V_ALARM_IO_INIT(void);                               //��ѹ�����˿�����
void   TEMP_IO_INIT(void);                                  //�¶ȱ����˿�����
void	 A_IO_INIT(void);                                     //�����˿�����
void	 KAIGUAN_IO_INIT(void);                               //�̵����˿�����

#define ALARM_1 GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_3)     //��ѹ����1
#define ALARM_2 GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)     //��ѹ����2
#define ALARM_3 GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_1)     //��ѹ����3
#define ALARM_4 GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_2)     //��ѹ����4

#define NTC1H GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_4)       //������1�����¶ȱ���
#define NTC1L GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5)       //������1�����¶ȱ���
#define NTC2H GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6)       //������2�����¶ȱ���
#define NTC2L GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_7)       //������2�����¶ȱ���
#define NTC3H GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_4)       //������3�����¶ȱ���
#define NTC3L GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5)       //������3�����¶ȱ���
#define NTC4H GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0)       //������4�����¶ȱ���
#define NTC4L GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6)       //������4�����¶ȱ���

#define  S1_H  GPIO_SetBits(GPIOA,GPIO_Pin_10)                  //�̵��������1��
#define  S1_L  GPIO_ResetBits(GPIOA,GPIO_Pin_10)                //�̵��������1��
#define  S2_H  GPIO_SetBits(GPIOA,GPIO_Pin_9)                   //�̵��������2��
#define  S2_L  GPIO_ResetBits(GPIOA,GPIO_Pin_9)                 //�̵��������2��
#define  S3_H  GPIO_SetBits(GPIOA,GPIO_Pin_8)                   //�̵��������3��
#define  S3_L  GPIO_ResetBits(GPIOA,GPIO_Pin_8)                 //�̵��������3��
#define  S4_H  GPIO_SetBits(GPIOC,GPIO_Pin_7)                   //�̵��������4��
#define  S4_L  GPIO_ResetBits(GPIOC,GPIO_Pin_7)                 //�̵��������4��
#define  S5_H  GPIO_SetBits(GPIOC,GPIO_Pin_8)                   //�̵��������5��
#define  S5_L  GPIO_ResetBits(GPIOC,GPIO_Pin_8)                 //�̵��������5��
#define  S6_H  GPIO_SetBits(GPIOC,GPIO_Pin_9)                   //�̵��������6��
#define  S6_L  GPIO_ResetBits(GPIOC,GPIO_Pin_9)                 //�̵��������6��



#endif



