/**********头文件定义***********/
#include "../Include/Gogogo.h"

/**********全局变量声明*********/

/**********函数定义*************/
/********************************************************************************************/
void WheelLeftForward(void)										/*********左轮，前转*********/
{																/*正转						*/
	IN1_A=0;
	IN2_A=1;
}

void WheelLeftBackward(void)									/*********左轮，后转*********/
{																/*反转						*/
	IN1_A=1;
	IN2_A=0;
}

void WheelRightForward(void)									/*********右轮，前转*********/
{																/*正转						*/
	IN1_B=0;
	IN2_B=1;
}

void WheelRightBackward(void)									/*********右轮，后转*********/
{																/*反转						*/
	IN1_B=1;
	IN2_B=0;
}

void WheelEngineStop(void)											/*********	停止	*********/
{
	IN1_A=0;
	IN2_A=0;
	IN1_B=0;
	IN2_B=0;
}

void WheelEngineStart(uint stime)
{
	gucTimeFlag = 0;
	guiTimeNum = stime*10;
	EA=1;
	ET2=1;
	TR2=1;
	while(gucTimeFlag == 0);
	TR2=0;
	ET2=0;
	EA=0;
}

void WheelForward(void)											/*********匀速，前进*********/
{
	WheelLeftForward();
	WheelRightForward();
	WheelEngineStart(5000);
	WheelEngineStop();
}

void WheelBackward(void)										/*********匀速，后退*********/
{
	WheelLeftBackward();
	WheelRightBackward();
	WheelEngineStart(5000);
	WheelEngineStop();
}

void WheelTurnLeft(void)										/*********匀速，左转*********/
{
	WheelLeftBackward();
	WheelRightForward();
	WheelEngineStart(5000);
	WheelEngineStop();
}

void WheelTurnRight(void)										/*********匀速，右转*********/
{
	WheelLeftForward();
	WheelRightBackward();
	WheelEngineStart(5000);
	WheelEngineStop();
}
//
//void WheelAccelerateForward(void)								/*********加速，前进*********/
//{
//	uint cycle=0,T=2048;
//
//	WheelLeftForward();
//	WheelRightForward();
//
//	while(cycle!=T)
//	{
//		delay_us(cycle++);
//		delay_us(T-cycle);
//	}
//}
//
//void WheelAccelerateBackward(void)							/*********加速，后退*********/
//{
//	uint cycle=0,T=2048;
//
//	WheelLeftBackward();
//	WheelRightBackward();
//
//	while(cycle!=T)
//	{
//		delay_us(cycle++);
//		delay_us(T-cycle);
//	}  
//}


