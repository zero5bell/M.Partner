#ifndef __DELAY_H__
#define __DELAY_H__

/**********ͷ�ļ�����*********/
#include "../Include/include.h"

/********ȫ�ֱ�������*********/
extern uint guiTimeNum,guiCounter;
extern uchar gucTimeFlag;
/**********��������***********/
/********************************************************************************************************************/
//void delay(uint stime);
void delay_ms(uint mstime);
//void delay_us(uint ustime);
void delay_100us(uint ustime);


#endif