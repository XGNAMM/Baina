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



/*************************故障**********************************/

#define gaowen_guzhang        60    //超温故障
#define gaowen_guzhang_rest   59    //当温度从60度降低到58度以下时认为故障解除
#define gaoya_guzhang         49    //高压故障
#define gaoya_guzhang_rest    48    //当电压从49V降低到48V以下时认为故障解除
#define allV_guzhang          625   //总压故障
#define allV_guzhang_rest     624   //总压故障解除

/*************************告警**********************************/

#define gaoya_gaojing         47.5  //超压告警
#define gaoya_gaojing_rest    46.5  //当电压从47.5V降低到46.5V以下时候认为告警解除
#define diya_gaojing          15    //低压报警
#define diya_gaojing_rest     16    //当电压从15V上升到16V时认为告警解除
#define allV_gao_gaojing      610   //超压报警
#define allV_gao_gaojing_rest 608   //当电压从610V降低到608V时认为告警解除
#define allV_di_gaojing       200   //低压告警
#define allV_di_gaojing_rest  202   //当电压从200V上升到202V时认为告警解除
#define chazhi_gaojing        10    //差值告警
#define chazhi_gaojing_rest   9     //当电压差值从10V降低到9V时认为告警解除
#define dianliu_gaojing       390   //超电流告警
#define dianliu_gaojing_rest  389   //当电流从390A降低到389A时认为告警解除


void task_1(DATA *sys);
void task_2(DATA *sys);
void task_3(DATA *sys);
	

#endif


