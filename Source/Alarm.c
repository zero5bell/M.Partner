/**********ͷ�ļ�����***********/
#include "../Include/Alarm.h"

/**********ȫ�ֱ�������*********/

/**********��������*************/
/************************************************************************************************/
void Alarm(uchar ObstFlag)								/****************�澯����****************/
{
	if(ObstFlag == 0)									/*���ϰ���ǰ��							*/
	{
		if(gucTempFlag != ObstFlag)
		{
			Gotoxy(2,1);
			LCD_Write_String("                "); 		/*��ӡ16���ո�							*/
			Gotoxy(2,1);
			LCD_Write_String("No Obst,Forward!");	
		}
	}
	else if(ObstFlag == 1)								/*��ǰ�����ϰ�����ת					*/
	{
		if(gucTempFlag != ObstFlag)
		{
			Gotoxy(2,1);
			LCD_Write_String("                "); 	
			Gotoxy(2,1);
			LCD_Write_String("Obst,Turn Left!");
		}	
	}
	else if(ObstFlag == 2)								/*��ǰ�����ϰ�����ת					*/
	{
		if(gucTempFlag != ObstFlag)
		{
			Gotoxy(2,1);
			LCD_Write_String("                "); 	
			Gotoxy(2,1);
			LCD_Write_String("Obst,Turn Right!");	
		}
	}
	else if(ObstFlag == 3)								/*ǰ�����Ҷ����ϰ�������				*/
	{
		if(gucTempFlag != ObstFlag)
		{
			Gotoxy(2,1);
			LCD_Write_String("                "); 		
			Gotoxy(2,1);
			LCD_Write_String("Obst,Backward!");
		}
	}
	else if(ObstFlag == 4)								/*ǰ�������Ҷ����ϰ�������ʧ��		*/
	{
		if(gucTempFlag != ObstFlag)
		{
			Gotoxy(2,1);
			LCD_Write_String("                "); 		
			Gotoxy(2,1);
			LCD_Write_String("AVOID FAILED!");
		}
	}
	else if(ObstFlag == 7)								/*��ʼ�����							*/
	{
		if(gucTempFlag != ObstFlag)
		{
			Gotoxy(1,1);
			LCD_Write_String("Initial Completed!");
			delay_ms(500);
			LCD_Clear();								/*����									*/
		}
	}
	else if(ObstFlag == 7)								/*��ʼ�����							*/
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


