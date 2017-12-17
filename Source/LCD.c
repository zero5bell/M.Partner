/**********头文件定义***********/
#include "../Include/LCD.h"

/**********全局变量声明*********/
uchar qian_data,ge_data,shi_data,bai_data ;													/*转换数据定义	*/
//uchar oct_table[10] = {'0','1','2','3','4','5','6','7','8','9'};							/*显示10进制数	*/
//uchar hex_table[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};	/*显示16进制数	*/

/**********函数定义*************/
/************************************************************************************************************/
#ifdef _LCD1602														/*************器件选择编译宏*************/

																	/**********	LCD1602函数定义	*************/
void LCD_Write_Com(uchar com) 
{  
	delay_ms(5);
	RS=0; 
	RW=0; 
	EN=1; 
	P0=com; 
	EN=0;
}

void LCD_Write_Data(uchar Data)										/*写数据函数							*/ 
{ 
	delay_ms(5);
	RS=1; 
	RW=0; 
	EN=1; 
	P0=Data; 
	EN=0;
}

void Gotoxy(uchar x,uchar y)  
{     
	if (x == 1) 
 	{     
		LCD_Write_Com(0x80 + y-1);									/*表示第一行							*/
 	}
	else 
 	{      
 		LCD_Write_Com(0xC0 + y-1);  								/*表示第二行							*/
 	}        
}

void LCD_Write_String(uchar *s)   									/*写字符串函数							*/
{    
	while (*s) 
 	{     
	 	LCD_Write_Data( *s);     
	 	s ++;     
 	}
}

																	/**********	LCD1602初始化函数	*********/
void Init_LCD(void) 
{
	LCD_Write_Com(0x38);    										/*显示模式设置							*/ 
	delay_ms(1); 
	LCD_Write_Com(0x38); 
	delay_ms(1); 
	LCD_Write_Com(0x38); 
	delay_ms(1); 
	LCD_Write_Com(0x38);  
	LCD_Write_Com(0x08);    										/*显示关闭								*/ 
	LCD_Write_Com(0x01);    										/*显示清屏								*/ 
	LCD_Write_Com(0x06);    										/*显示光标移动设置						*/ 
	delay_ms(1); 
	LCD_Write_Com(0x0C);    										/*显示开及光标设置						*/
} 

#endif
																	/**********LCD1602函数定义结束	*********/

#ifdef _LCD12864		   											/*器件选择编译宏						*/

																	/**********	LCD12864函数定义	*********/
void LCD_Write_Com(uchar com) 
{  
 delay_ms(5);
 RS=0; 
 RW=0; 
 EN=1; 
 P0=com; 
 EN=0;
}

void Gotoxy(uchar x,uchar y)  
{     
	if (x == 1) 
 	{     
		LCD_Write_Com(0x80 + y-1);									/*表示第一行							*/
 	}
	else if(x == 2)
 	{      
 		LCD_Write_Com(0x90 + y-1);									/*表示第二行							*/
 	}        
	else if(x == 3)
	{
		LCD_Write_Com(0x88 + y-1);									/*表示第三行							*/
	}
	else if(x == 4)
	{
		LCD_Write_Com(0x98 + y-1);									/*表示第四行							*/
	}
}

void LCD_Write_Data(uchar Data)										/*************写数据函数*****************/ 
{ 
	delay_ms(5);
	RS=1; 
	RW=0; 
	EN=1; 
	P0= Data; 
	EN=0;
}

//void LCD_Write_String(uchar x,uchar y,uchar *s)   /*写字符串函数*/
void LCD_Write_String(uchar *s)   									/**************写字符串函数**************/
{     
//	if (x == 1) 
// 	{     
//		LCD_Write_Com(0x80 + y-1);									/*表示第一行							*/
// 	}
//	else if(x == 2)
// 	{      																	
// 		LCD_Write_Com(0x90 + y-1);									/*表示第二行							*/
// 	}        
//	else if(x == 3)
//	{
//		LCD_Write_Com(0x88 + y-1);									/*表示第三行							*/
//	}
//	else if(x == 4)
//	{																		
//		LCD_Write_Com(0x98 + y-1);									/*表示第四行							*/
//	}        
 	while (*s) 
 	{     
	 	LCD_Write_Data( *s);     
	 	s ++;     
 	}
}

																	/************	初始化函数12864	*********/
void Init_LCD(void) 
{
   LCD_Write_Com(0x30);    											/*显示模式设置							*/ 
   delay_ms(1); 
   LCD_Write_Com(0x30); 
   delay_ms(1); 
     
   LCD_Write_Com(0x08);    											/*显示关闭								*/ 
   LCD_Write_Com(0x10);
   delay_ms(1); 
   LCD_Write_Com(0x0C);    											/*显示开及光标设置						*/
   LCD_Write_Com(0x01);    											/*显示清屏								*/ 
   LCD_Write_Com(0x06);    											/*显示光标移动设置						*/ 
   
}

#endif
																	/**********LCD12864函数定义结束	*********/

																	/******LCD1602+12864的清屏函数***********/
void LCD_Clear(void)
{
	LCD_Write_Com(0x01);
}

																	/***********显示+数据转换程序************/
void ConvertNumToDisplay(uchar x,uchar y,uint Num)  
{
	qian_data=Num/1000 ;													
	Num=Num%1000;   												/*取余运算								*/
	bai_data=Num/100 ;
	Num=Num%100;   													/*取余运算								*/
	shi_data=Num/10 ;
	Num=Num%10;   													/*取余运算								*/
	ge_data=Num;

	Gotoxy(x,y);

	LCD_Write_String("DIST: ");
	LCD_Write_Data(qian_data+0x30);
	LCD_Write_Data(bai_data+0x30);
	LCD_Write_Data(shi_data+0x30);
	LCD_Write_Data('.');
	LCD_Write_Data(ge_data+0x30);
	LCD_Write_String("CM");	
}
//
//																	/************显示10进制数//**************/
//void ConvertOctToDisplay(uchar x,uchar y,uint Octnum)
//{
//	uchar a, b, c, d;
//	
//	a = (Octnum/256)/10; 											/*取高字节的高4位						*/
//	b = (Octnum/256)%10; 											/*取高字节的低4位						*/
//	
//	c = (Octnum%256)/10; 											/*取低字节的高4位					   	*/
//	d = (Octnum%256)%10; 											/*取低字节的低4位						*/
//
//	Gotoxy(x,y);	
//
//	LCD_Write_Data(oct_table[a]);
//	LCD_Write_Data(oct_table[b]);
//	LCD_Write_Data('.');
//	LCD_Write_Data(oct_table[c]);
//	LCD_Write_Data(oct_table[d]);
//}
																	/*************显示16进制数//*************/
//void ConvertHexToDisplay(uchar x,uchar y,uint Hexnum)
//{
//	uchar a, b, c, d;
//																			
//	a = (Hexnum/256)/16; 											/*取高字节的高4位						*/
//	b = (Hexnum/256)%16; 											/*取高字节的低4位
//	
//	c = (Hexnum%256)/16; 											/*取低字节的高4位						*/
//	d = (Hexnum%256)%16; 											/*取低字节的低4位						*/
//
//	Gotoxy(x,y);
//
//	LCD_Write_Data(hex_table[a]);
//	LCD_Write_Data(hex_table[b]);
//	LCD_Write_Data(hex_table[c]);
//	LCD_Write_Data(hex_table[d]);
//}

