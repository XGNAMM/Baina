#include "can_send.h"
#include "can.h"
#include "C.h"

unsigned char Can1_Send1(volatile DATA *sys)
{	
	u8 mbox;
	u16 i=0;
	CanTxMsg TxMessage;
	TxMessage.ExtId=0x18f101d3;			    // 设置扩展标示符 0x1fffffff
	TxMessage.IDE=CAN_Id_Extended; 	// 扩展帧
	TxMessage.RTR=CAN_RTR_Data;		// 数据帧
	TxMessage.DLC=8;			      	// 要发送的数据长度
	
	sys->send_can1.T++;           //发一次时间加一
	if(sys->send_can1.T > 255)
	  sys->send_can1.T = 0;
	
	TxMessage.Data[0]= sys->send_can1.soc;			
  TxMessage.Data[1]= sys->send_can1.dianliu_l;		
  TxMessage.Data[2]= sys->send_can1.dianliu_h;		
  TxMessage.Data[3]= sys->send_can1.all_vl;		
  TxMessage.Data[4]= sys->send_can1.all_vh;		
  TxMessage.Data[5]= sys->send_can1.KM1;		
  TxMessage.Data[6]= sys->send_can1.KM2;		
	TxMessage.Data[7]= sys->send_can1.T;	
	
	mbox= CAN_Transmit(CAN1, &TxMessage);   
	i=0; 
	while((CAN_TransmitStatus(CAN1, mbox)==CAN_TxStatus_Failed)&&(i<0XFFF))i++;	//等待发送结束
	if(i>=0XFFF)return 1;
	return 0;	 
}



unsigned char Can1_Send2(volatile DATA *sys)
{	
	u8 mbox;
	u16 i=0;
	CanTxMsg TxMessage;
	TxMessage.ExtId=0x18f102d3;			// 设置扩展标示符 0x1fffffff
	TxMessage.IDE=CAN_Id_Extended; 	// 扩展帧
	TxMessage.RTR=CAN_RTR_Data;		  // 数据帧
	TxMessage.DLC=4;				        // 要发送的数据长度
	
	TxMessage.Data[0]= sys->send_can1.max_vl;	
  TxMessage.Data[1]= sys->send_can1.max_vh;		
  TxMessage.Data[2]= sys->send_can1.min_vl;	
  TxMessage.Data[3]= sys->send_can1.min_vl;	
	
	mbox= CAN_Transmit(CAN1, &TxMessage);   
	i=0; 
	while((CAN_TransmitStatus(CAN1, mbox)==CAN_TxStatus_Failed)&&(i<0XFFF))i++;	//等待发送结束
	if(i>=0XFFF)return 1;
	return 0;	 
}

unsigned char Can1_Send3(volatile DATA *sys)
{	
	u8 mbox;
	u16 i=0;
	CanTxMsg TxMessage;
	TxMessage.ExtId=0x18f103d3;			// 设置扩展标示符 0x1fffffff
	TxMessage.IDE=CAN_Id_Extended; 	// 扩展帧
	TxMessage.RTR=CAN_RTR_Data;		  // 数据帧
	TxMessage.DLC=6;				        // 要发送的数据长度
	
	TxMessage.Data[0] = 0;
	TxMessage.Data[1] = 0;
	TxMessage.Data[2] = 0;
	TxMessage.Data[3] = sys->send_can1.bit4_bit5;	
  TxMessage.Data[4] = sys->send_can1.guzhang;		
  TxMessage.Data[5] = sys->send_can1.gaojing;	
	
	mbox= CAN_Transmit(CAN1, &TxMessage);   
	i=0; 
	while((CAN_TransmitStatus(CAN1, mbox)==CAN_TxStatus_Failed)&&(i<0XFFF))i++;	//等待发送结束
	if(i>=0XFFF)return 1;
	return 0;	 
}

unsigned char Can2_Send1(volatile DATA *sys)
{
	;
}


