#ifndef __UltraSonicRanging_H__
#define __UltraSonicRanging_H__

/**********ͷ�ļ�����*********/
#include "../Include/include.h"
#include "../Include/LCD.h"
#include "../Include/UltraSonicRanging.h"
#include "../Include/Delay.h"

/********ȫ�ֱ�������*********/

/**********��������***********/
/****************************************************************************************/
void Init_UltraSonicRanging(void);					/*��ʼ����							*/
uchar UltraSonicRanging(void);						/*������							*/
void RangingSort(void);								/*���������						*/

#endif