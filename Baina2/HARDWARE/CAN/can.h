#ifndef __CAN_H
#define __CAN_H	 
#include "sys.h"	    

 typedef enum  CAN_x	
{
	CAN_1,
	CAN_2

}CAN_x;

#define CAN_250K  	8
#define CAN_500K  	4
#define CAN_1000K   2


//CAN1接收RX0中断使能
#define CAN1_RX0_INT_ENABLE	1		//0,不使能;1,使能.	
#define CAN1_TX_ENABLE      0
				
//CAN2接收RX0中断使能
#define CAN2_RX1_INT_ENABLE	1		//0,不使能;1,使能.	
#define CAN2_TX_ENABLE      0
			

u8 CAN_bound_Init(CAN_x can_x,u32 bound);//CAN初始化

u8 Can_Send_Msg(uint32_t ID,CAN_TypeDef* CAN,u8* msg,u8 len);						//发送数据

u8 Can_Receive_Msg(u8 *buf);							//接收数据
#endif

















