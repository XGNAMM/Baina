#ifndef __C_H	 
#define __C_H	 



typedef struct 
	{
		unsigned int  ADC;         //AD7924返回的ad值,范围0-4095;
		float         V_REAL;      //电容两端的电压值
		float         V_LVBO;      //软件滤波后的电压值
  }C;
	
C C0,C1,C2,C3;

	
#endif
