#include "baina_task.h"

const float offset = 0;  //LM317A��ѹ���ֵ
const float KP = 2;      //


void task_1(DATA *sys)  //���ݲɼ�
{
	/***************��ȡ��ǰ��ѹ******************/
	
	// AD7924_READ(&sys->read.VADC1,&sys->read.VADC2,&sys->read.VADC3,&sys->read.VADC4);
	
	 sys->read.group1[1] = sys->read.lv1 / 4096 * 3.3;
	 sys->read.group2[1] = sys->read.lv1 / 4096 * 3.3;
	 sys->read.group3[1] = sys->read.lv1 / 4096 * 3.3;
	 sys->read.group4[1] = sys->read.lv1 / 4096 * 3.3;

	/***************��ѹ�������******************/
	
	 if(ALARM_1)
		 sys->read.group1[2] = 1;
	 else
		 sys->read.group1[2] = 0;
		 
	 if(ALARM_2)
		 sys->read.group2[2] = 1;
	 else
		 sys->read.group2[2] = 0;
	 
	 if(ALARM_3)
		 sys->read.group3[2] = 1;
	 else
		 sys->read.group3[2] = 0;
	 
	 if(ALARM_4)
		 sys->read.group4[2] = 1;
	 else
	 	 sys->read.group4[2] = 0;	 
	 
	/*************��ȡ���±���ֵ*****************/
	 
	if(NTC1H)
		sys->read.group1[3] = 1;
	if(NTC2H)
		sys->read.group2[3] = 1;
	if(NTC3H)
		sys->read.group3[3] = 1;
  if(NTC4H)
		sys->read.group4[3] = 1;
	
	/*************��ȡ���±���ֵ*****************/
	
  if(NTC1L)
		sys->read.group1[4] = 1;
	if(NTC2L)
		sys->read.group2[4] = 1;
	if(NTC3L)
		sys->read.group3[4] = 1;
  if(NTC4L)
		sys->read.group4[4] = 1;
		
    sys->read.updata = 1;   
}

void task_2(DATA *sys)  //�ϱ����ݷ���
{
	  static short int dian_liu = 0;  //����ֵ
	  static short int v_all = 0;     //�ܵ�ѹֵ
	  float maxV = 0;      //4��ģ���е�����ѹ
	  float minV = 0;      //4��ģ���е���С��ѹ
	  float chazhiV = 0;   //����ѹ����С��ѹ�Ĳ�
	  static char  byte4_0 = 0;
	  static char  byte4_1 = 0;
	  static char  byte4_2 = 0;
	
	  static char  byte5_1 = 0;
	  static char  byte5_2 = 0;
	  static char  byte5_3 = 0;
	  static char  byte5_4 = 0;
	  static char  byte5_5 = 0;
	  static char  byte5_6 = 0;
	  static char  byte5_7 = 0;

	//  static REST rest={0,0,0,0,0,0,0,0,0};  //������־λ
	
	  maxV = sys->read.group1[1];
	  minV = sys->read.group1[1];
	
	/*******************************�ϱ���һ������***************************************************/
	
	  v_all = sys->read.group1[1] + sys->read.group2[1] + sys->read.group3[1] + sys->read.group4[1];            //�����ܵ�ѹ
	  sys->send_can1.soc =  (unsigned char)(v_all/6*5);                                                         //ʣ����� real/240*200
	
	  dian_liu = (short int)((sys->read.lv_dianliu / 4096 * 3.3 - offset) * KP /4 *8000);                          //ʵ�ʵ���ֵ
	  sys->send_can1.dianliu_l = (unsigned char)(dian_liu);                                                     //ʵ�ʵ���ֵ�ĵ�8λ
	  sys->send_can1.dianliu_h = (unsigned char)(dian_liu>>8);                                                  //ʵ�ʵ���ֵ�ĸ�8λ
	
	  sys->send_can1.all_vl = (unsigned char)v_all;                                                             //�ܵ�ѹ�ĵ�8λ
	  sys->send_can1.all_vh = (unsigned char)(v_all>>8);	                                                      //�ܵ�ѹ�ĸ�8λ
	
	 if(sys->read.CAN1_KMN == 0x00)       //KM1��KM6�����Ͽ�  δ��Ӷ��߳���
	 {
		  sys->send_can1.KM1 = 0;
		  sys->send_can1.KM2 = 0;
	 }
	 else if(sys->read.CAN1_KMN == 0x08)  //KM1�Ͽ���KM6�պ�
	 {
		  sys->send_can1.KM1 = 0;
		  sys->send_can1.KM2 = 1;
 	 }
	 else if(sys->read.CAN1_KMN == 0x0f)  //KM1�պϣ�KM6�Ͽ�
	 {
		  sys->send_can1.KM1 = 1;
		  sys->send_can1.KM2 = 0;
	 }
	 if(sys->read.duan_time > 1000)          //�������1s����û�н��ܵ��϶˴��������ݣ�LED�𣬷���LED����KM1��KM6�����Ͽ�
	 {
//		  sys->send_can1.KM1 = 0;
//		  sys->send_can1.KM2 = 0;
		  GPIO_ResetBits(GPIOB,GPIO_Pin_11);	
	 }
	 else
		  GPIO_SetBits(GPIOB,GPIO_Pin_11);	
		 
	
		
	/*******************************�ϱ��ڶ�������***************************************************/
	  if(sys->read.group2[1] > maxV)
			maxV = sys->read.group2[1];
		if(sys->read.group3[1] > maxV)
			maxV = sys->read.group3[1];
		if(sys->read.group4[1] > maxV)
			maxV = sys->read.group4[1];                                                                              //��������ѹֵ

	  sys->send_can1.max_vl = (unsigned char)maxV;                                                               //����ѹ�ĵ�8λ
		sys->send_can1.max_vh = (unsigned char)((unsigned short int)maxV>>8);                                      //����ѹ�ĸ�8λ
		
		if(sys->read.group2[1] < minV)
			minV = sys->read.group2[1];
		if(sys->read.group3[1] < minV)
			minV = sys->read.group3[1];
		if(sys->read.group4[1] < minV)
			minV = sys->read.group4[1];                                                                              //������С��ѹֵ
		
		sys->send_can1.min_vl = (unsigned char)minV;                                                               //��С��ѹ�ĵ�8λ
		sys->send_can1.min_vh = (unsigned char)((unsigned short int)minV>>8);                                      //��С��ѹ�ĸ�8λ
	  
	
		chazhiV = maxV - minV;                                                                                     //������С��ֵ
		
		
	/*******************************�ϱ�����������***************************************************/
	
  /*******************************����**************************/		
		
		if(sys->read.lvT > gaowen_guzhang)
		{
       byte4_0 = 1;
			 sys->send_can1.guzhang = sys->send_can1.guzhang | (1<<0);                                               //���ֽ�4λ0��1
		}
    else if(sys->read.lvT < gaowen_guzhang_rest)
    {			
			 byte4_0 = 0;
			 sys->send_can1.guzhang = sys->send_can1.guzhang & 0XFE;   //fE = 1111 1110                              //���ֽ�4λ0��0	
		}
		
		if(sys->read.group1[1] >= gaoya_guzhang||sys->read.group2[1] >= gaoya_guzhang||sys->read.group3[1] >= gaoya_guzhang||sys->read.group4[1] >= gaoya_guzhang) //�жϵ���ģ���ѹ�Ƿ񳬹�49V	
		{
			byte4_1 = 1;	
		  sys->send_can1.guzhang = sys->send_can1.guzhang | (1<<1);                                                //���ֽ�4λ1��1				
		}
		else if(sys->read.group1[1] < gaoya_guzhang_rest&&sys->read.group2[1] < gaoya_guzhang_rest&&sys->read.group3[1] < gaoya_guzhang_rest&&sys->read.group4[1] < gaoya_guzhang_rest)
		{
			byte4_1 = 0;
			sys->send_can1.guzhang = sys->send_can1.guzhang & 0xFD;   //fd = 1111 1101                               //���ֽ�4λ1��0		
		}
		
		if(v_all >= allV_guzhang)                       //�ж��ܵ�ѹ�Ƿ񳬹�625V                                                                                 
		{
			byte4_2 = 1;
		  sys->send_can1.guzhang = sys->send_can1.guzhang | (1<<2);                                                //���ֽ�4λ2��1
		}
    else if(v_all < allV_guzhang_rest)            
		{
			byte4_2 = 0; 
		  sys->send_can1.guzhang = sys->send_can1.guzhang & 0xFB;   //fb = 1111 1011                               //���ֽ�4λ2��0                                     
		}
		if(byte4_0 == 1 || byte4_1 == 1 || byte4_2 == 1)               //���й����ź�ʱ
		{			
      sys->send_can1.bit4_bit5 = sys->send_can1.bit4_bit5 | (1<<4);                                            //���ֽ�3λ4��1
		}
		else
		  sys->send_can1.bit4_bit5 = sys->send_can1.bit4_bit5 & 0xEF;  //  FE = 1110  1111                         //���ֽ�3λ4��0
		
			
  /******************************�澯****************************/
		
		if(maxV >= gaoya_gaojing)           //��ѹ�澯
			byte5_1 = 1;
		else if(maxV < gaoya_gaojing_rest)
			byte5_1 = 0;
		
		if(minV <= diya_gaojing)            //���¸澯
			byte5_2 = 1;
		else if(minV > diya_gaojing_rest)
			byte5_2 = 0;
		
		if(v_all >= allV_gao_gaojing)       //��ѹ��ѹ�澯
			byte5_3 = 1;
		else if(v_all < allV_gao_gaojing_rest)
			byte5_3 = 0;
		
		if(v_all <= allV_di_gaojing)        //��ѹ��ѹ�澯
			byte5_4 = 1;
		else if(v_all > allV_di_gaojing_rest)
			byte5_4 = 0;
		
		if(chazhiV >= chazhi_gaojing)
			byte5_5 = 1;
		else if(chazhiV < chazhi_gaojing_rest)
			byte5_5 = 0;	
		
		if(dian_liu >= dianliu_gaojing)     //�����澯
			byte5_7 = 1;
		else if(dian_liu < dianliu_gaojing_rest)
			byte5_7 = 0;
			
		if(byte5_1 == 1||byte5_2 == 1||byte5_3 == 1||byte5_4 == 1||byte5_5 == 1||byte5_6 == 1||byte5_7 == 1)       //�и澯�ź�     
			sys->send_can1.bit4_bit5 = sys->send_can1.bit4_bit5 | (1<<5);                                            //���ֽ�3λ5��1
		else                            																																					 //�޸澯�ź�
			sys->send_can1.bit4_bit5 = sys->send_can1.bit4_bit5 & 0xDF;         //DF = 1101 1111                     //���ֽ�3λ5��0
		
}

void task_3(DATA *sys)  //�̵�������
{
	//************************��ϵͳ����Ԥ��翪��****************************// s1 �� s6
	if(sys->send_can1.KM1 == 1)
		S1_H;
	else 
		S1_L;
	
	if(sys->send_can1.KM2 == 1)
		S6_H;
	else
		S6_L;	

	//****************************ϵͳ����***************************************//	s2
	
	if((sys->send_can1.bit4_bit5&0x10) == 1)      //3�ֽڵĵ�4λΪ1˵���й���
		 S2_H;
	else
		 S2_L;
	
	//******************************����*****************************************// s3
	
	if(sys->read.group1[3] || sys->read.group2[3] || sys->read.group3[3] || sys->read.group4[3])        //�г�42�ȾͿ�����
		 S3_H; 
	else if(sys->read.group1[4] && sys->read.group2[4] && sys->read.group3[4] && sys->read.group4[4])   //������38�ȹط���
		 S3_L;
	
	
}










