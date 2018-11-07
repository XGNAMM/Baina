#include "can_send.h"
#include "can.h"


#define ID_SEND 0X18F101D3



void CAN_Send_Bainacap()
{
	CanTData TX;
	
	//TX.str.soc =
	//TX.str.life_t =
	//TX.str.sum_dian_h =
	//TX.str.sum_dian_l =
	//TX.str.sum_v_h =
	//TX.str.sum_v_l =
  //TX.str.sys_kai1 =	
	//TX.str.sys_kai2 =

	
	Can_Send_Msg(ID_SEND,CAN1,TX.Data,8);
}











