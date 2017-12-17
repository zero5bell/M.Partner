/**********头文件定义******************************/
#include "../Include/SteeringGear.h"

/*********全局变量声明*****************************/
uint guiPwmNum,guiPwmCounter,guiTimeCounter;
uchar gucPwmFlag;

/*********函数定义*********************************/
/********************************************************************************/
void Init_StGear(void)							/*********初始化单片机	*********/
{	
	TMOD=0x11; 									/*定时器0、1为16位不自动重装	*/

	guiPwmCounter = 0;
	guiTimeCounter = 0;
	guiPwmNum = 0;
	gucPwmFlag = 0;
	STGEAR = 0;
												/*初始上电，归中				*/
	StGearTurnMid00();	
}

void StGearTurnMid00(void)					   	/********舵机转向左侧90度********/
{
	gucPwmFlag = 0;
	guiPwmNum = 4;
	STGEAR=1;
	EA=1;
	ET0=1;
	TR0=1;
	while(gucPwmFlag == 0);
	TR0=0;
	ET0=0;
	EA=0;
}

void StGearTurnRight90(void)					/********舵机转向中间00度********/
{
	gucPwmFlag = 0;
	guiPwmNum = 2;
	STGEAR=1;
	EA=1;
	ET0=1;
	TR0=1;
	while(gucPwmFlag == 0);
	TR0=0;
	ET0=0;
	EA=0;
}

void StGearTurnLeft90(void)				   		/********舵机转向右侧90度********/
{
	gucPwmFlag = 0;
	guiPwmNum = 7;
	STGEAR=1;
	EA=1;
	ET0=1;
	TR0=1;
	while(gucPwmFlag == 0);
	TR0=0;
	ET0=0;
	EA=0;
}

void timer0(void) interrupt 1				   /**************定时器0************/
{
	TH0=(65536-300)>>8;	   
	TL0=(65536-300)&0xFF;

	guiPwmCounter++;	
	if(guiPwmCounter == guiPwmNum)
	{	
		STGEAR=~STGEAR;
		guiPwmCounter = 0;
		guiTimeCounter++;
	}	
	if(guiTimeCounter>=200)
	{
		gucPwmFlag = 1;
		guiTimeCounter=0;
	}
}


