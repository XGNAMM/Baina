#include "main.h"

int main(void)
 {	
	  
	  static unsigned char f = 1;
 
		USER_INIT();

		while(1)
		{		 	
			  ave_lvbo(&sysdata,5);      //滤波5次，处理ADC值
			  task_1(&sysdata);          //数据采集任务 
			  ce_zhouqi();               //while中时间39.2ms  //开启定时器中断41.6msq
		}
	
}


//定时器3中断服务程序
void TIM3_IRQHandler(void)
{ 
	static TIME TIME_FLAG = {1,1,1,1,1,1};
	static char last_read_T = 0;         //上次的can周期
	
	if (TIM_GetITStatus(TIM3,TIM_IT_Update)!= RESET)
	{		 
		 TIM_ClearFlag(TIM3, TIM_FLAG_Update);	
		
		 if(TIME_FLAG.FIVE++>=5)       //5ms 中断 
		 {
			  TIME_FLAG.FIVE = 1;
        if(sysdata.read.updata == 1)	//ADC数据更新完成
				{ 
          sysdata.read.updata = 0;					
			    task_2(&sysdata);  //上报数据分析任务    //0.025ms
			    task_3(&sysdata);  //数据动作任务	       //0.003ms
				}
		 }	
		 if(TIME_FLAG.CAN1_1T++>=100)  //100ms 中断 
		 {
				TIME_FLAG.CAN1_1T = 1;
				Can1_Send1(&sysdata);	  //8.08us	 	
		 }
		 if(TIME_FLAG.CAN1_2T++>=150)  //150ms 中断 
		 {
				TIME_FLAG.CAN1_2T = 1;
			  Can1_Send2(&sysdata);   //7.33us
		 }
		 if(TIME_FLAG.CAN1_3T++>=200)  //200ms 中断 
		 {
			  TIME_FLAG.CAN1_3T = 1;		
				Can1_Send3(&sysdata);   //7.36us
		 }
		  
		 /********************断线计时*****************************/
		 {
		 	if(sysdata.read.CAN1_T == sysdata.read.CAN1_T)  //当接收到的周期时间与上次一样时丢数据次数+1
				 if(sysdata.read.duan_time++ >2000)
					 sysdata.read.duan_time = 2000;
		   if(sysdata.read.CAN1_T != sysdata.read.CAN1_T)  
				 sysdata.read.duan_time = 0;
			
			 last_read_T = sysdata.read.CAN1_T;
		 }	 
		 
		 
	}
}

void CAN1_RX0_IRQHandler(void)  //接收can1上总控数据
{
	
	CanRxMsg rx_message;
	
	if(CAN_GetITStatus(CAN1,CAN_IT_FMP0)!= RESET) 
	{
		
		CAN_ClearITPendingBit(CAN1, CAN_IT_FMP0);
		CAN_Receive(CAN1, CAN_FIFO0, &rx_message);   
		if(rx_message.ExtId == RECEIVE1_ID) 
		{		
       sysdata.read.CAN1_KMN = rx_message.Data[1];    
			 sysdata.read.CAN1_T   = rx_message.Data[3];
		
		}			
	}
	
}


void CAN2_RX0_IRQHandler(void)  //就收超级电容器can2数据
{
	
	CanRxMsg rx_message;

	if(CAN_GetITStatus(CAN2,CAN_IT_FMP0)!= RESET) 
	{
		CAN_ClearITPendingBit(CAN2, CAN_IT_FMP0);
		CAN_Receive(CAN2, CAN_FIFO0, &rx_message); 
		if(rx_message.StdId == RECEIVE2_ID) 
		{
//	    bb = rx_message.Data[0];
		}			
		
	}
	
	
}



//			  f = -f;
//			  delay_ms(1000);
//			
//				if(f==1)	
//				{
//						S1_H;	 LED1_H ;	  
//						S2_H;  LED2_H ; 
//						S3_H;  LED3_H ;
//						S4_H;  LED4_H ;			 
//						S5_H;  						  
//						S6_H; 
//			 
//				}					
//				
//				else
//				{
//					  S1_L;  LED1_L;
//            S2_L;  LED2_L;
//            S3_L;  LED3_L;
//            S4_L;	 LED4_L;
//            S5_L;	
//            S6_L;					
//				}
//				
//				a[1] = NTC1H;
//				a[2] = NTC1L;
//				a[3] = NTC2H;
//				a[4] = NTC2L;
//				a[5] = NTC3H;
//				a[6] = NTC3L;
//				a[7] = NTC4H;
//				a[8] = NTC4L;
//				
//		    b[1] = ALARM_1;
//				b[2] = ALARM_2;
//				b[3] = ALARM_3;
//				b[4] = ALARM_4;
