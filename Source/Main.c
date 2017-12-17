/**********头文件定义************/
#include "../Include/include.h"
#include "../Include/LCD.h"
#include "../Include/ObstDetect.h"
#include "../Include/ObstAvoid.h"
#include "../Include/SteeringGear.h"
#include "../Include/Gogogo.h"
#include "../Include/Alarm.h"
/**********全局变量声明**********/
uchar gucObstFlag = 0;			 /*上电默认存在障碍//[0:无障碍][1:左转][2:右转][3:后退][7:初始化完成][其它:停止]*/
uchar gucTempFlag = 0;
/**********函数定义**************/
/****************************************************************************************************************/
void main()
{														/***************************系统初始化*******************/ 	
	Init_LCD();											/*LCD初始化												*/
	Init_UltraSonicRanging();							/*超声波测距初始化										*/
	Init_StGear();										/*舵机初始化											*/
	Alarm(7);											/*初始化完成告警										*/
	while(1)								
	{ 													/***************************检测，避障*******************/		
		gucObstFlag = ObstDetect();						/*检查是否有障碍										*/						  		
		ObstAvoid(gucObstFlag);							/*避障操作												*/
		Alarm(gucObstFlag);								/*告警													*/
	}	
}

