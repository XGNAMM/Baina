#include "duo_ku.h"


void ce_zhouqi(void)//计算函数执行的周期
{
	static char fan = 1;	  
	
		fan = -fan; 
			if(fan==1)		
					GPIO_SetBits(GPIOB,GPIO_Pin_6);	
			else
					GPIO_ResetBits(GPIOB,GPIO_Pin_6);
}

short int ave_lvbo(short int adc_first,short int times)
{
	
	static short int real;
	static float sum;
	short int i = 0;
	for(i = 0; i<times ;i++)
	{
		sum += adc_first;
	}
	real = (short int)(sum/times);
	sum = 0;
	return real;
	
}

short int jiaquan_lvbo(short int adc_first,short int quanshu)
{
	 
	 static short int last_adc;
	 
	
	
	
}











