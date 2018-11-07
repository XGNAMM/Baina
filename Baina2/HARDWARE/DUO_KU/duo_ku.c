#include "duo_ku.h"
#include "AD7924.h"
#include "ds18b20.h"
#include "adc.h"


void ce_zhouqi(void)//计算函数执行的周期
{
	static char fan = 1;	  
	
		fan = -fan; 
			if(fan==1)		
					GPIO_SetBits(GPIOB,GPIO_Pin_10);	
			else
					GPIO_ResetBits(GPIOB,GPIO_Pin_10);
}

void led1(void)//计算函数执行的周期
{
	static char fan = 1;	  
	
		fan = -fan; 
			if(fan==1)		
					GPIO_SetBits(GPIOB,GPIO_Pin_11);	
			else
					GPIO_ResetBits(GPIOB,GPIO_Pin_11);
}

void led2(void)//计算函数执行的周期
{
	static char fan = 1;	  
	
		fan = -fan; 
			if(fan==1)		
					GPIO_SetBits(GPIOB,GPIO_Pin_14);	
			else
					GPIO_ResetBits(GPIOB,GPIO_Pin_14);
}

void led3(void)//计算函数执行的周期
{
	static char fan = 1;	  
	
		fan = -fan; 
			if(fan==1)		
					GPIO_SetBits(GPIOB,GPIO_Pin_15);	
			else
					GPIO_ResetBits(GPIOB,GPIO_Pin_15);
}





void ave_lvbo(DATA *sys,short int times)
{
	static float sum1 = 0,sum2 = 0,sum3 = 0,sum4 = 0,sum5 = 0,sum6 = 0;
	short int i = 0;
	
	for(i = 0; i<times ;i++)
	{
	  AD7924_READ(&sys->read.VADC1,&sys->read.VADC2,&sys->read.VADC3,&sys->read.VADC4);	//2.87	
		sys->read.TADC = DS18B20_Get_Temp();
		sys->read.dianliuADC = Get_Adc(9);
			
	
		sum1 += sys->read.VADC1;
		sum2 += sys->read.VADC2;
		sum3 += sys->read.VADC3;
		sum4 += sys->read.VADC4;
		sum5 += sys->read.TADC;
		sum6 += sys->read.dianliuADC;
		
	}
	
	sys->read.lv1 = (short int)(sum1/times);
	sys->read.lv2 = (short int)(sum2/times);
	sys->read.lv3 = (short int)(sum3/times);
	sys->read.lv4 = (short int)(sum4/times);
	sys->read.lvT = (short int)(sum5/times);
	sys->read.lv_dianliu = (short int)(sum6/times);
	
	sum1 = 0;
	sum2 = 0;
	sum3 = 0;
	sum4 = 0;
	sum5 = 0;
	sum6 = 0;

}









