#ifndef __C_H	 
#define __C_H	 


typedef struct
	{
		
		/**************��ȡ����*******************/
			struct
			{
		/*************ģ���·�ɼ�����**************************************/
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
				
				float group1[5];   //����1�����ѹ ����2�����ѹ���� ����3������ ����4�������
				float group2[5];
				float group3[5];
				float group4[5];
				
				unsigned char updata;
				
			  
				
		/*****************CAN1��ȡ��������**************************************************/		
				
				unsigned char CAN1_KMN;          //�̵�������       �ֽ�0�ĵ�4λ
				unsigned char CAN1_T;            //���յ���������   �ֽ�3�ĵ�4λ
				unsigned short int duan_time;         //���յ�can���ݺ���������û��Ĵ�����
				
		/*****************CAN2��ȡ��������**************************************************/	
			
			
			
			
			}read;
		
		/***************�ϱ�������***************/
			struct
			{
		//***************��һ������***************//����100ms
				
				unsigned char soc;     //0�ֽڿ�ʼ �������μ�һ
				unsigned char dianliu_l;
				unsigned char dianliu_h;
				unsigned char all_vl;
				unsigned char all_vh; 
				unsigned char KM1;
				unsigned char KM2;
				unsigned char T;
		
     //***************�ڶ�������**************//����150ms
				
				unsigned char max_vl;      //0�ֽڿ�ʼ �������μ�һ
				unsigned char max_vh;
			  unsigned char min_vl;
				unsigned char min_vh;
				
		 //***************����������**************//����200ms
				
				unsigned char bit4_bit5;   //3�ֽڿ�ʼ  �������μ�һ
			  unsigned char guzhang;     //���ϵ�3��bit 
				unsigned char gaojing;     //�澯��7��bit
			 }send_can1;
			
			 struct
			 {
		     unsigned char kong;
	
			 }send_can2;
		
	}DATA;
	
	
	
	
#endif
