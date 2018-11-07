#ifndef __C_H	 
#define __C_H	 


typedef struct
	{
		
		/**************读取数据*******************/
			struct
			{
		/*************模拟电路采集数据**************************************/
			  float VADC1;
				float VADC2;
				float VADC3; 
				float VADC4;	
				float TADC;	
				float dianliuADC;
				
				float lv1;
				float lv2;
				float lv3;
				float lv4;
				float lvT;
				float lv_dianliu;
				
				float group1[5];   //数组1代表电压 数组2代表电压报警 数组3代表超温 数组4代表低温
				float group2[5];
				float group3[5];
				float group4[5];
				
				unsigned char updata;
				
			  
				
		/*****************CAN1读取到的数据**************************************************/		
				
				unsigned char CAN1_KMN;          //继电器开关       字节0的低4位
				unsigned char CAN1_T;            //接收的生命周期   字节3的低4位
				unsigned short int duan_time;         //接收到can数据后，生命周期没变的次数。
				
		/*****************CAN2读取到的数据**************************************************/	
			
			
			
			
			}read;
		
		/***************上报的数据***************/
			struct
			{
		//***************第一组数据***************//周期100ms
				
				unsigned char soc;     //0字节开始 以下依次加一
				unsigned char dianliu_l;
				unsigned char dianliu_h;
				unsigned char all_vl;
				unsigned char all_vh; 
				unsigned char KM1;
				unsigned char KM2;
				unsigned char T;
		
     //***************第二组数据**************//周期150ms
				
				unsigned char max_vl;      //0字节开始 以下依次加一
				unsigned char max_vh;
			  unsigned char min_vl;
				unsigned char min_vh;
				
		 //***************第三组数据**************//周期200ms
				
				unsigned char bit4_bit5;   //3字节开始  以下依次加一
			  unsigned char guzhang;     //故障低3个bit 
				unsigned char gaojing;     //告警高7个bit
			 }send_can1;
			
			 struct
			 {
		     unsigned char kong;
	
			 }send_can2;
		
	}DATA;
	
	
	
	
#endif
