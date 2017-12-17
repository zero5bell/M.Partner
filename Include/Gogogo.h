#ifndef __GOGOGO_H__
#define __GOGOGO_H__

/**********头文件定义*********/
#include "../Include/include.h"
#include "../Include/Delay.h"

/********全局变量声明*********/

/**********函数声明***********/
void WheelLeftForward(void);			/*********左轮，前转*********/
void WheelLeftBackward(void);			/*********左轮，后转*********/
void WheelRightForward(void);			/*********右轮，前转*********/
void WheelRightBackward(void);			/*********右轮，后转*********/
void WheelEngineStart(uint stime);		/*********启动引擎	*********/
void WheelEngineStop(void);				/*********停止引擎	*********/
void WheelForward(void);				/*********匀速，前进*********/
void WheelBackward(void);				/*********匀速，后退*********/
void WheelTurnLeft(void);				/*********匀速，左转*********/
void WheelTurnRight(void);				/*********匀速，右转*********/
void WheelAccelerateForward(void);		/*********加速，前进*********/
void WheelAccelerateBackward(void);		/*********加速，后退*********/

#endif