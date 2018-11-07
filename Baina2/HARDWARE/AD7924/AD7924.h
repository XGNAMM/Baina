#ifndef _AD7924_H
#define _AD7924_H

#include "sys.h"

#define  SCLK_H GPIO_SetBits(GPIOC,GPIO_Pin_12)       //ʱ������
#define  SCLK_L GPIO_ResetBits(GPIOC,GPIO_Pin_12)     //ʱ������

#define  DIN_H GPIO_SetBits(GPIOC,GPIO_Pin_11)        //AD7924����������
#define  DIN_L GPIO_ResetBits(GPIOC,GPIO_Pin_11)      //AD7924����������

#define CS_H GPIO_SetBits(GPIOC,GPIO_Pin_10)          //AD7924��ʹ������
#define CS_L GPIO_ResetBits(GPIOC,GPIO_Pin_10)

#define DOUT GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_2) //AD7924�����������

void AD7924_IO_INIT(void);
void Delay(int nCount);

void AD7924_READ(float *V0,float *V1,float *V2,float *V3); //��ʼ��֮��ֱ�ӵ��ô˺����ӿ��Է��ص�ѹֵ

signed short int SPI_ReadWriteByte(signed short int TxData);


#endif
