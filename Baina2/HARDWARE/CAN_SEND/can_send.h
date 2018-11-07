#ifndef __CAN_SEND_H
#define __CAN_SEND_H


#include "C.h"  

#define ID_SEND 0X1FF

#define  RECEIVE1_ID  0x18F110D3
#define  RECEIVE2_ID  0x1FF



unsigned char Can1_Send1(volatile DATA *sys);
unsigned char Can1_Send2(volatile DATA *sys);
unsigned char Can1_Send3(volatile DATA *sys);
unsigned char Can2_Send1(volatile DATA *sys);
	
#endif


