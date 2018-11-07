#ifndef __CAN_SEND_H
#define __CAN_SEND_H

typedef union
{
	unsigned char Data[8];
	struct
	{
		unsigned char   soc :8;    
		unsigned char   sum_dian_l :8; 
		unsigned char   sum_dian_h :8;
		unsigned char   sum_v_l :8;   
    unsigned char   sum_v_h :8; 
    unsigned char   sys_kai1 :8;
    unsigned char   sys_kai2 :8;	
    unsigned char		life_t   :8;   
	}str;
}CanTData;













#endif


