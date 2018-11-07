#include "main.h"



int main(void)
 {	
	  
	  static unsigned char f = 1;
	  
		USER_INIT();

		while(1)
		{
			
			  f = -f;
			  delay_ms(1000);
			
				if(f==1)	
				{
						S1_H;	 LED1_H ;	  
						S2_H;  LED2_H ; 
						S3_H;  LED3_H ;
						S4_H;  LED4_H ;			 
						S5_H;  						  
						S6_H; 
							 
				}					
				
				else
				{
					  S1_L;  LED1_L;
            S2_L;  LED2_L;
            S3_L;  LED3_L;
            S4_L;	 LED4_L;
            S5_L;	
            S6_L;					
				}

				
     
				
		 

		}
	
}



