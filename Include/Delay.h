#ifndef __DELAY_H__
#define __DELAY_H__

/**********头文件定义*********/
#include "../Include/include.h"

/********全局变量声明*********/
extern uint guiTimeNum,guiCounter;
extern uchar gucTimeFlag;
/**********函数声明***********/
/********************************************************************************************************************/
//void delay(uint stime);
void delay_ms(uint mstime);
//void delay_us(uint ustime);
void delay_100us(uint ustime);


#endif