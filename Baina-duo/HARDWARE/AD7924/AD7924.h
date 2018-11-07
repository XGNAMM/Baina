#ifndef _AD7924_H
#define _AD7924_H

#include "sys.h"

#define  SCLK_H GPIO_SetBits(GPIOC,GPIO_Pin_12)       //时钟引脚
#define  SCLK_L GPIO_ResetBits(GPIOC,GPIO_Pin_12)     //时钟引脚

#define  DIN_H GPIO_SetBits(GPIOC,GPIO_Pin_11)        //AD7924的输入引脚
#define  DIN_L GPIO_ResetBits(GPIOC,GPIO_Pin_11)      //AD7924的输入引脚

#define CS_H GPIO_SetBits(GPIOC,GPIO_Pin_10)          //AD7924的使能引脚
#define CS_L GPIO_ResetBits(GPIOC,GPIO_Pin_10)

#define DOUT GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_2) //AD7924数据输出引脚

void AD7924_IO_INIT(void);
void Delay(int nCount);
void AD7924_READ(unsigned int *V0,unsigned int *V1,unsigned int *V2,unsigned int *V3);

signed short int SPI_ReadWriteByte(signed short int TxData);


#endif
