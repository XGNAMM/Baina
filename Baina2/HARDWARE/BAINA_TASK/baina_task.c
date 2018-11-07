#include "baina_task.h"

const float offset = 0;  //LM317A分压输出值
const float KP = 2;      //


void task_1(DATA *sys)  //数据采集
{
	/***************读取当前电压******************/
	
	// AD7924_READ(&sys->read.VADC1,&sys->read.VADC2,&sys->read.VADC3,&sys->read.VADC4);
	
	 sys->read.group1[1] = sys->read.lv1 / 4096 * 3.3;
	 sys->read.group2[1] = sys->read.lv1 / 4096 * 3.3;
	 sys->read.group3[1] = sys->read.lv1 / 4096 * 3.3;
	 sys->read.group4[1] = sys->read.lv1 / 4096 * 3.3;

	/***************超压报警检测******************/
	
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
	 
	/*************读取超温报警值*****************/
	 
	if(NTC1H)
		sys->read.group1[3] = 1;
	if(NTC2H)
		sys->read.group2[3] = 1;
	if(NTC3H)
		sys->read.group3[3] = 1;
  if(NTC4H)
		sys->read.group4[3] = 1;
	
	/*************读取低温报警值*****************/
	
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

void task_2(DATA *sys)  //上报数据分析
{
	  static short int dian_liu = 0;  //电流值
	  static short int v_all = 0;     //总电压值
	  float maxV = 0;      //4组模块中的最大电压
	  float minV = 0;      //4组模块中的最小电压
	  float chazhiV = 0;   //最大电压与最小电压的差
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

	//  static REST rest={0,0,0,0,0,0,0,0,0};  //警报标志位
	
	  maxV = sys->read.group1[1];
	  minV = sys->read.group1[1];
	
	/*******************************上报第一组数据***************************************************/
	
	  v_all = sys->read.group1[1] + sys->read.group2[1] + sys->read.group3[1] + sys->read.group4[1];            //计算总电压
	  sys->send_can1.soc =  (unsigned char)(v_all/6*5);                                                         //剩余电量 real/240*200
	
	  dian_liu = (short int)((sys->read.lv_dianliu / 4096 * 3.3 - offset) * KP /4 *8000);                          //实际电流值
	  sys->send_can1.dianliu_l = (unsigned char)(dian_liu);                                                     //实际电流值的低8位
	  sys->send_can1.dianliu_h = (unsigned char)(dian_liu>>8);                                                  //实际电流值的高8位
	
	  sys->send_can1.all_vl = (unsigned char)v_all;                                                             //总电压的低8位
	  sys->send_can1.all_vh = (unsigned char)(v_all>>8);	                                                      //总电压的高8位
	
	 if(sys->read.CAN1_KMN == 0x00)       //KM1和KM6，都断开  未添加断线程序
	 {
		  sys->send_can1.KM1 = 0;
		  sys->send_can1.KM2 = 0;
	 }
	 else if(sys->read.CAN1_KMN == 0x08)  //KM1断开，KM6闭合
	 {
		  sys->send_can1.KM1 = 0;
		  sys->send_can1.KM2 = 1;
 	 }
	 else if(sys->read.CAN1_KMN == 0x0f)  //KM1闭合，KM6断开
	 {
		  sys->send_can1.KM1 = 1;
		  sys->send_can1.KM2 = 0;
	 }
	 if(sys->read.duan_time > 1000)          //如果持续1s以上没有接受到上端传来的数据，LED灭，否则LED亮，KM1和KM6，都断开
	 {
//		  sys->send_can1.KM1 = 0;
//		  sys->send_can1.KM2 = 0;
		  GPIO_ResetBits(GPIOB,GPIO_Pin_11);	
	 }
	 else
		  GPIO_SetBits(GPIOB,GPIO_Pin_11);	
		 
	
		
	/*******************************上报第二组数据***************************************************/
	  if(sys->read.group2[1] > maxV)
			maxV = sys->read.group2[1];
		if(sys->read.group3[1] > maxV)
			maxV = sys->read.group3[1];
		if(sys->read.group4[1] > maxV)
			maxV = sys->read.group4[1];                                                                              //计算最大电压值

	  sys->send_can1.max_vl = (unsigned char)maxV;                                                               //最大电压的低8位
		sys->send_can1.max_vh = (unsigned char)((unsigned short int)maxV>>8);                                      //最大电压的高8位
		
		if(sys->read.group2[1] < minV)
			minV = sys->read.group2[1];
		if(sys->read.group3[1] < minV)
			minV = sys->read.group3[1];
		if(sys->read.group4[1] < minV)
			minV = sys->read.group4[1];                                                                              //计算最小电压值
		
		sys->send_can1.min_vl = (unsigned char)minV;                                                               //最小电压的低8位
		sys->send_can1.min_vh = (unsigned char)((unsigned short int)minV>>8);                                      //最小电压的高8位
	  
	
		chazhiV = maxV - minV;                                                                                     //计算最小差值
		
		
	/*******************************上报第三组数据***************************************************/
	
  /*******************************故障**************************/		
		
		if(sys->read.lvT > gaowen_guzhang)
		{
       byte4_0 = 1;
			 sys->send_can1.guzhang = sys->send_can1.guzhang | (1<<0);                                               //对字节4位0置1
		}
    else if(sys->read.lvT < gaowen_guzhang_rest)
    {			
			 byte4_0 = 0;
			 sys->send_can1.guzhang = sys->send_can1.guzhang & 0XFE;   //fE = 1111 1110                              //对字节4位0置0	
		}
		
		if(sys->read.group1[1] >= gaoya_guzhang||sys->read.group2[1] >= gaoya_guzhang||sys->read.group3[1] >= gaoya_guzhang||sys->read.group4[1] >= gaoya_guzhang) //判断单个模块电压是否超过49V	
		{
			byte4_1 = 1;	
		  sys->send_can1.guzhang = sys->send_can1.guzhang | (1<<1);                                                //对字节4位1置1				
		}
		else if(sys->read.group1[1] < gaoya_guzhang_rest&&sys->read.group2[1] < gaoya_guzhang_rest&&sys->read.group3[1] < gaoya_guzhang_rest&&sys->read.group4[1] < gaoya_guzhang_rest)
		{
			byte4_1 = 0;
			sys->send_can1.guzhang = sys->send_can1.guzhang & 0xFD;   //fd = 1111 1101                               //对字节4位1置0		
		}
		
		if(v_all >= allV_guzhang)                       //判断总电压是否超过625V                                                                                 
		{
			byte4_2 = 1;
		  sys->send_can1.guzhang = sys->send_can1.guzhang | (1<<2);                                                //对字节4位2置1
		}
    else if(v_all < allV_guzhang_rest)            
		{
			byte4_2 = 0; 
		  sys->send_can1.guzhang = sys->send_can1.guzhang & 0xFB;   //fb = 1111 1011                               //对字节4位2置0                                     
		}
		if(byte4_0 == 1 || byte4_1 == 1 || byte4_2 == 1)               //当有故障信号时
		{			
      sys->send_can1.bit4_bit5 = sys->send_can1.bit4_bit5 | (1<<4);                                            //对字节3位4置1
		}
		else
		  sys->send_can1.bit4_bit5 = sys->send_can1.bit4_bit5 & 0xEF;  //  FE = 1110  1111                         //对字节3位4置0
		
			
  /******************************告警****************************/
		
		if(maxV >= gaoya_gaojing)           //超压告警
			byte5_1 = 1;
		else if(maxV < gaoya_gaojing_rest)
			byte5_1 = 0;
		
		if(minV <= diya_gaojing)            //低温告警
			byte5_2 = 1;
		else if(minV > diya_gaojing_rest)
			byte5_2 = 0;
		
		if(v_all >= allV_gao_gaojing)       //总压超压告警
			byte5_3 = 1;
		else if(v_all < allV_gao_gaojing_rest)
			byte5_3 = 0;
		
		if(v_all <= allV_di_gaojing)        //总压低压告警
			byte5_4 = 1;
		else if(v_all > allV_di_gaojing_rest)
			byte5_4 = 0;
		
		if(chazhiV >= chazhi_gaojing)
			byte5_5 = 1;
		else if(chazhiV < chazhi_gaojing_rest)
			byte5_5 = 0;	
		
		if(dian_liu >= dianliu_gaojing)     //电流告警
			byte5_7 = 1;
		else if(dian_liu < dianliu_gaojing_rest)
			byte5_7 = 0;
			
		if(byte5_1 == 1||byte5_2 == 1||byte5_3 == 1||byte5_4 == 1||byte5_5 == 1||byte5_6 == 1||byte5_7 == 1)       //有告警信号     
			sys->send_can1.bit4_bit5 = sys->send_can1.bit4_bit5 | (1<<5);                                            //对字节3位5置1
		else                            																																					 //无告警信号
			sys->send_can1.bit4_bit5 = sys->send_can1.bit4_bit5 & 0xDF;         //DF = 1101 1111                     //对字节3位5置0
		
}

void task_3(DATA *sys)  //继电器动作
{
	//************************主系统充电和预充电开关****************************// s1 和 s6
	if(sys->send_can1.KM1 == 1)
		S1_H;
	else 
		S1_L;
	
	if(sys->send_can1.KM2 == 1)
		S6_H;
	else
		S6_L;	

	//****************************系统故障***************************************//	s2
	
	if((sys->send_can1.bit4_bit5&0x10) == 1)      //3字节的第4位为1说明有故障
		 S2_H;
	else
		 S2_L;
	
	//******************************风扇*****************************************// s3
	
	if(sys->read.group1[3] || sys->read.group2[3] || sys->read.group3[3] || sys->read.group4[3])        //有超42度就开风扇
		 S3_H; 
	else if(sys->read.group1[4] && sys->read.group2[4] && sys->read.group3[4] && sys->read.group4[4])   //都低于38度关风扇
		 S3_L;
	
	
}










