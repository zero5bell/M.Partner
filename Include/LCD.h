#ifndef _LCD_H_
#define _LCD_H_

/**********头文件定义*********/
#include "../Include/include.h"
#include "../Include/Delay.h"

/********全局变量声明*********/

/**********函数声明***********/
/********************************************************************************************************/
void LCD_Write_Data(uchar Data);							/*写数据函数								*/
void LCD_Write_String(uchar *s);							/*写字符串函数								*/
void LCD_Clear(void);										/*LCD清屏									*/
void Init_LCD(void); 										/*LCD初始化									*/
void Gotoxy(uchar x,uchar y); 								/*光标移动函数								*/

void ConvertNumToDisplay(uchar x,uchar y,uint Num);			/*在指定位置，显示10进制数据转换，非高低8位	*/
//void ConvertOctToDisplay(uchar x,uchar y,uint Octnum);	/*在指定位置，显示10进制数据转换，高低8位	*/
void ConvertHexToDisplay(uchar x,uchar y,uint Hexnum);		/*在指定位置，显示16进制数据转换，高低8位	*/

#endif