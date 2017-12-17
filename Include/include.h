#ifndef __INCLUDE_H__
#define __INCLUDE_H__
/******************************************头文件定义****************************************/
#include <REG52.h>
#include <intrins.h>

/******************************************编译宏定义****************************************/
#define _LCD1602						/*使用LCD1602										*/
//#define _LCD12864						/*使用LCD12864										*/
#define _STGEAR							/*使用舵机代码										*/

/******************************************宏定义********************************************/
										/*********************SteeringGear*******************/
//#define TIME_PER_SEC 10000			/*每次进入中断的频率，10000Hz，0.1ms				*/
//#define TIME_PER_SEC 50000			/*每次进入中断的频率，50000Hz，0.02ms				*/
//#define TIME_CLOCK 11059200			/*晶振频率											*/
//#define NUM				5			/*（10000HZ）0°，90°，180°：11,6,2;22，13，5		*/ 
//#define NUM				24			/*（20000HZ）0°，90°，180°：11,6,2;40，24，9		*/

/******************************************数据类型定义**************************************/
#define uchar unsigned char
#define uint unsigned int
#define uint32 unsigned long int

/******************************************全局变量声明**************************************/
//extern uchar gucObstFlag;
extern uchar gucTempFlag;

/****************************************单片机IO接口定义************************************/
										/********************	UltraSonic	*****************/
sbit Tx = P3^3; 						/*产生脉冲引脚										*/
sbit Rx = P3^2; 						/*回波引脚											*/

										/********************	LCD1602/12864****************/
sbit RS = P2^3;  
sbit RW = P2^4;
sbit EN = P2^5;

										/***************LN298电机驱动模块IO定义**************/
										/*电机A												*/
sbit IN1_A = P1^0;
sbit IN2_A = P1^1;
										/*电机B												*/
sbit IN1_B = P1^2;
sbit IN2_B = P1^3;

										/******************红外避障模块IO定义****************/
sbit INFRARED_FRONT  	= P0^4;			/*前模块											*/
sbit INFRARED_LEFT		= P0^5;			/*左模块											*/
sbit INFRARED_RIGHT  	= P0^4;			/*右模块											*/
sbit INFRARED_BEHIND 	= P0^5;			/*后模块											*/

										/************SteeringGear舵机模块IO定义**************/
sbit STGEAR = P1^7;						/*舵机控制											*/


#endif