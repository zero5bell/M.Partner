/**********ͷ�ļ�����******************************/
#include "../Include/SteeringGear.h"

/*********ȫ�ֱ�������*****************************/
uint guiPwmNum,guiPwmCounter,guiTimeCounter;
uchar gucPwmFlag;

/*********��������*********************************/
/********************************************************************************/
void Init_StGear(void)							/*********��ʼ����Ƭ��	*********/
{	
	TMOD=0x11; 									/*��ʱ��0��1Ϊ16λ���Զ���װ	*/

	guiPwmCounter = 0;
	guiTimeCounter = 0;
	guiPwmNum = 0;
	gucPwmFlag = 0;
	STGEAR = 0;
												/*��ʼ�ϵ磬����				*/
	StGearTurnMid00();	
}

void StGearTurnMid00(void)					   	/********���ת�����90��********/
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

void StGearTurnRight90(void)					/********���ת���м�00��********/
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

void StGearTurnLeft90(void)				   		/********���ת���Ҳ�90��********/
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

void timer0(void) interrupt 1				   /**************��ʱ��0************/
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


