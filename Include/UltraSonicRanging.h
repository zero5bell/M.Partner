#ifndef __UltraSonicRanging_H__
#define __UltraSonicRanging_H__

/**********头文件定义*********/
#include "../Include/include.h"
#include "../Include/LCD.h"
#include "../Include/UltraSonicRanging.h"
#include "../Include/Delay.h"

/********全局变量声明*********/

/**********函数声明***********/
/****************************************************************************************/
void Init_UltraSonicRanging(void);					/*初始化测							*/
uchar UltraSonicRanging(void);						/*测距程序							*/
void RangingSort(void);								/*测距结果排序						*/

#endif