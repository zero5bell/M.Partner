/**********头文件定义***********/
#include "../Include/Alarm.h"

/**********全局变量声明*********/

/**********函数定义*************/
/************************************************************************************************/
void Alarm(uchar ObstFlag)								/****************告警函数****************/
{
	if(ObstFlag == 0)									/*无障碍，前进							*/
	{
		if(gucTempFlag != ObstFlag)
		{
			Gotoxy(2,1);
			LCD_Write_String("                "); 		/*打印16个空格							*/
			Gotoxy(2,1);
			LCD_Write_String("No Obst,Forward!");	
		}
	}
	else if(ObstFlag == 1)								/*正前方有障碍，左转					*/
	{
		if(gucTempFlag != ObstFlag)
		{
			Gotoxy(2,1);
			LCD_Write_String("                "); 	
			Gotoxy(2,1);
			LCD_Write_String("Obst,Turn Left!");
		}	
	}
	else if(ObstFlag == 2)								/*正前方有障碍，右转					*/
	{
		if(gucTempFlag != ObstFlag)
		{
			Gotoxy(2,1);
			LCD_Write_String("                "); 	
			Gotoxy(2,1);
			LCD_Write_String("Obst,Turn Right!");	
		}
	}
	else if(ObstFlag == 3)								/*前、左、右都有障碍，后退				*/
	{
		if(gucTempFlag != ObstFlag)
		{
			Gotoxy(2,1);
			LCD_Write_String("                "); 		
			Gotoxy(2,1);
			LCD_Write_String("Obst,Backward!");
		}
	}
	else if(ObstFlag == 4)								/*前、后、左、右都有障碍，避障失败		*/
	{
		if(gucTempFlag != ObstFlag)
		{
			Gotoxy(2,1);
			LCD_Write_String("                "); 		
			Gotoxy(2,1);
			LCD_Write_String("AVOID FAILED!");
		}
	}
	else if(ObstFlag == 7)								/*初始化完成							*/
	{
		if(gucTempFlag != ObstFlag)
		{
			Gotoxy(1,1);
			LCD_Write_String("Initial Completed!");
			delay_ms(500);
			LCD_Clear();								/*清屏									*/
		}
	}
	else if(ObstFlag == 7)								/*初始化完成							*/
	{
		if(gucTempFlag != ObstFlag)
		{
			Gotoxy(2,1);
			LCD_Write_String("                "); 	
			Gotoxy(2,1);
			LCD_Write_String("FATAL ERROR!");
		}
	}
	gucTempFlag =  ObstFlag;
}


