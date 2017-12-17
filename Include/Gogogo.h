#ifndef __GOGOGO_H__
#define __GOGOGO_H__

/**********ͷ�ļ�����*********/
#include "../Include/include.h"
#include "../Include/Delay.h"

/********ȫ�ֱ�������*********/

/**********��������***********/
void WheelLeftForward(void);			/*********���֣�ǰת*********/
void WheelLeftBackward(void);			/*********���֣���ת*********/
void WheelRightForward(void);			/*********���֣�ǰת*********/
void WheelRightBackward(void);			/*********���֣���ת*********/
void WheelEngineStart(uint stime);		/*********��������	*********/
void WheelEngineStop(void);				/*********ֹͣ����	*********/
void WheelForward(void);				/*********���٣�ǰ��*********/
void WheelBackward(void);				/*********���٣�����*********/
void WheelTurnLeft(void);				/*********���٣���ת*********/
void WheelTurnRight(void);				/*********���٣���ת*********/
void WheelAccelerateForward(void);		/*********���٣�ǰ��*********/
void WheelAccelerateBackward(void);		/*********���٣�����*********/

#endif