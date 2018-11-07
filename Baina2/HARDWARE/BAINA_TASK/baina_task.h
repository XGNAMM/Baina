#ifndef BAINA_TASK_H
#define BAINA_TASK_H

#include "C.h"
#include "io.h"
#include "led.h"
#include "adc.h"
#include "AD7924.h"


//typedef struct 
//{
//	char gz_gaowen_flag;
//	char gz_gaoya_flag;
//	char gz_ALLV_chao_flag;
//	
//	char gj_gaoya_flag;
//	char gj_diya_flag;
//	char gj_ALLV_chao_flag;
//	char gj_ALLV_di_flag;
//	char gj_chazhi_flag;
//	char gj_dianliu_flag;
//}REST;



/*************************����**********************************/

#define gaowen_guzhang        60    //���¹���
#define gaowen_guzhang_rest   59    //���¶ȴ�60�Ƚ��͵�58������ʱ��Ϊ���Ͻ��
#define gaoya_guzhang         49    //��ѹ����
#define gaoya_guzhang_rest    48    //����ѹ��49V���͵�48V����ʱ��Ϊ���Ͻ��
#define allV_guzhang          625   //��ѹ����
#define allV_guzhang_rest     624   //��ѹ���Ͻ��

/*************************�澯**********************************/

#define gaoya_gaojing         47.5  //��ѹ�澯
#define gaoya_gaojing_rest    46.5  //����ѹ��47.5V���͵�46.5V����ʱ����Ϊ�澯���
#define diya_gaojing          15    //��ѹ����
#define diya_gaojing_rest     16    //����ѹ��15V������16Vʱ��Ϊ�澯���
#define allV_gao_gaojing      610   //��ѹ����
#define allV_gao_gaojing_rest 608   //����ѹ��610V���͵�608Vʱ��Ϊ�澯���
#define allV_di_gaojing       200   //��ѹ�澯
#define allV_di_gaojing_rest  202   //����ѹ��200V������202Vʱ��Ϊ�澯���
#define chazhi_gaojing        10    //��ֵ�澯
#define chazhi_gaojing_rest   9     //����ѹ��ֵ��10V���͵�9Vʱ��Ϊ�澯���
#define dianliu_gaojing       390   //�������澯
#define dianliu_gaojing_rest  389   //��������390A���͵�389Aʱ��Ϊ�澯���


void task_1(DATA *sys);
void task_2(DATA *sys);
void task_3(DATA *sys);
	

#endif


