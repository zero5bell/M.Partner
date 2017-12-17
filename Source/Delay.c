/**********头文件定义***********/
#include "../Include/Delay.h"

/**********全局变量声明*********/
uint guiTimeNum,guiCounter;
uchar gucTimeFlag;

/***********函数定义************/
/*******************************************************************************************/
//void delay(uint stime)				/*********	s延时	*********/
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
										/*********ms毫秒延时*********/
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
//										/*********us微秒延时*********/
//void delay_us(uint ustime)
//{
//	while(ustime--);
//}
//
//										/*********200us延时	*********/
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

void timer2(void) interrupt 5			/********扩展定时器2*********/
{
	TF2 = 0;							/*溢出标记必须在此清零		*/

	TH2=(65536-100)>>8;		  		/*定时1ms					*/
	TL2=(65536-100)&0xFF;

	guiCounter++;
	if(guiCounter >= guiTimeNum)
	{
		guiCounter = 0;
		gucTimeFlag = 1;
	}
}

