/**********ͷ�ļ�����***********/
#include "../Include/Delay.h"

/**********ȫ�ֱ�������*********/
uint guiTimeNum,guiCounter;
uchar gucTimeFlag;

/***********��������************/
/*******************************************************************************************/
//void delay(uint stime)				/*********	s��ʱ	*********/
//{
//	gucTimeFlag = 0;
//	guiTimeNum = stime*1000;
//	EA=1;
//	ET2=1;
//	TR2=1;
//	while(gucTimeFlag == 0);
//	TR2=0;
//	ET2=0;
//	EA=0;
//}
										/*********ms������ʱ*********/
void delay_ms(uint mstime)
{
	gucTimeFlag = 0;
	guiTimeNum = mstime*10;
	EA=1;
	ET2=1;
	TR2=1;
	while(gucTimeFlag == 0);
	TR2=0;
	ET2=0;
	EA=0;
}
//
//										/*********us΢����ʱ*********/
//void delay_us(uint ustime)
//{
//	while(ustime--);
//}
//
//										/*********200us��ʱ	*********/
void delay_100us(uint ustime)
{  
	gucTimeFlag = 0;
	guiTimeNum = ustime;
	EA=1;
	ET2=1;
	TR2=1;
	while(gucTimeFlag == 0);
	TR2=0;
	ET2=0;
	EA=0;
}

void timer2(void) interrupt 5			/********��չ��ʱ��2*********/
{
	TF2 = 0;							/*�����Ǳ����ڴ�����		*/

	TH2=(65536-100)>>8;		  		/*��ʱ1ms					*/
	TL2=(65536-100)&0xFF;

	guiCounter++;
	if(guiCounter >= guiTimeNum)
	{
		guiCounter = 0;
		gucTimeFlag = 1;
	}
}

