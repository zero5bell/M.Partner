#ifndef _LCD_H_
#define _LCD_H_

/**********ͷ�ļ�����*********/
#include "../Include/include.h"
#include "../Include/Delay.h"

/********ȫ�ֱ�������*********/

/**********��������***********/
/********************************************************************************************************/
void LCD_Write_Data(uchar Data);							/*д���ݺ���								*/
void LCD_Write_String(uchar *s);							/*д�ַ�������								*/
void LCD_Clear(void);										/*LCD����									*/
void Init_LCD(void); 										/*LCD��ʼ��									*/
void Gotoxy(uchar x,uchar y); 								/*����ƶ�����								*/

void ConvertNumToDisplay(uchar x,uchar y,uint Num);			/*��ָ��λ�ã���ʾ10��������ת�����Ǹߵ�8λ	*/
//void ConvertOctToDisplay(uchar x,uchar y,uint Octnum);	/*��ָ��λ�ã���ʾ10��������ת�����ߵ�8λ	*/
void ConvertHexToDisplay(uchar x,uchar y,uint Hexnum);		/*��ָ��λ�ã���ʾ16��������ת�����ߵ�8λ	*/

#endif