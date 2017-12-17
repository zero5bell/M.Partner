/**********ͷ�ļ�����***********/
#include "../Include/Gogogo.h"

/**********ȫ�ֱ�������*********/

/**********��������*************/
/********************************************************************************************/
void WheelLeftForward(void)										/*********���֣�ǰת*********/
{																/*��ת						*/
	IN1_A=0;
	IN2_A=1;
}

void WheelLeftBackward(void)									/*********���֣���ת*********/
{																/*��ת						*/
	IN1_A=1;
	IN2_A=0;
}

void WheelRightForward(void)									/*********���֣�ǰת*********/
{																/*��ת						*/
	IN1_B=0;
	IN2_B=1;
}

void WheelRightBackward(void)									/*********���֣���ת*********/
{																/*��ת						*/
	IN1_B=1;
	IN2_B=0;
}

void WheelEngineStop(void)											/*********	ֹͣ	*********/
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

void WheelForward(void)											/*********���٣�ǰ��*********/
{
	WheelLeftForward();
	WheelRightForward();
	WheelEngineStart(5000);
	WheelEngineStop();
}

void WheelBackward(void)										/*********���٣�����*********/
{
	WheelLeftBackward();
	WheelRightBackward();
	WheelEngineStart(5000);
	WheelEngineStop();
}

void WheelTurnLeft(void)										/*********���٣���ת*********/
{
	WheelLeftBackward();
	WheelRightForward();
	WheelEngineStart(5000);
	WheelEngineStop();
}

void WheelTurnRight(void)										/*********���٣���ת*********/
{
	WheelLeftForward();
	WheelRightBackward();
	WheelEngineStart(5000);
	WheelEngineStop();
}
//
//void WheelAccelerateForward(void)								/*********���٣�ǰ��*********/
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
//void WheelAccelerateBackward(void)							/*********���٣�����*********/
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


