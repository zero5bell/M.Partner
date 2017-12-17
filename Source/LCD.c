/**********ͷ�ļ�����***********/
#include "../Include/LCD.h"

/**********ȫ�ֱ�������*********/
uchar qian_data,ge_data,shi_data,bai_data ;													/*ת�����ݶ���	*/
//uchar oct_table[10] = {'0','1','2','3','4','5','6','7','8','9'};							/*��ʾ10������	*/
//uchar hex_table[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};	/*��ʾ16������	*/

/**********��������*************/
/************************************************************************************************************/
#ifdef _LCD1602														/*************����ѡ������*************/

																	/**********	LCD1602��������	*************/
void LCD_Write_Com(uchar com) 
{  
	delay_ms(5);
	RS=0; 
	RW=0; 
	EN=1; 
	P0=com; 
	EN=0;
}

void LCD_Write_Data(uchar Data)										/*д���ݺ���							*/ 
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
		LCD_Write_Com(0x80 + y-1);									/*��ʾ��һ��							*/
 	}
	else 
 	{      
 		LCD_Write_Com(0xC0 + y-1);  								/*��ʾ�ڶ���							*/
 	}        
}

void LCD_Write_String(uchar *s)   									/*д�ַ�������							*/
{    
	while (*s) 
 	{     
	 	LCD_Write_Data( *s);     
	 	s ++;     
 	}
}

																	/**********	LCD1602��ʼ������	*********/
void Init_LCD(void) 
{
	LCD_Write_Com(0x38);    										/*��ʾģʽ����							*/ 
	delay_ms(1); 
	LCD_Write_Com(0x38); 
	delay_ms(1); 
	LCD_Write_Com(0x38); 
	delay_ms(1); 
	LCD_Write_Com(0x38);  
	LCD_Write_Com(0x08);    										/*��ʾ�ر�								*/ 
	LCD_Write_Com(0x01);    										/*��ʾ����								*/ 
	LCD_Write_Com(0x06);    										/*��ʾ����ƶ�����						*/ 
	delay_ms(1); 
	LCD_Write_Com(0x0C);    										/*��ʾ�����������						*/
} 

#endif
																	/**********LCD1602�����������	*********/

#ifdef _LCD12864		   											/*����ѡ������						*/

																	/**********	LCD12864��������	*********/
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
		LCD_Write_Com(0x80 + y-1);									/*��ʾ��һ��							*/
 	}
	else if(x == 2)
 	{      
 		LCD_Write_Com(0x90 + y-1);									/*��ʾ�ڶ���							*/
 	}        
	else if(x == 3)
	{
		LCD_Write_Com(0x88 + y-1);									/*��ʾ������							*/
	}
	else if(x == 4)
	{
		LCD_Write_Com(0x98 + y-1);									/*��ʾ������							*/
	}
}

void LCD_Write_Data(uchar Data)										/*************д���ݺ���*****************/ 
{ 
	delay_ms(5);
	RS=1; 
	RW=0; 
	EN=1; 
	P0= Data; 
	EN=0;
}

//void LCD_Write_String(uchar x,uchar y,uchar *s)   /*д�ַ�������*/
void LCD_Write_String(uchar *s)   									/**************д�ַ�������**************/
{     
//	if (x == 1) 
// 	{     
//		LCD_Write_Com(0x80 + y-1);									/*��ʾ��һ��							*/
// 	}
//	else if(x == 2)
// 	{      																	
// 		LCD_Write_Com(0x90 + y-1);									/*��ʾ�ڶ���							*/
// 	}        
//	else if(x == 3)
//	{
//		LCD_Write_Com(0x88 + y-1);									/*��ʾ������							*/
//	}
//	else if(x == 4)
//	{																		
//		LCD_Write_Com(0x98 + y-1);									/*��ʾ������							*/
//	}        
 	while (*s) 
 	{     
	 	LCD_Write_Data( *s);     
	 	s ++;     
 	}
}

																	/************	��ʼ������12864	*********/
void Init_LCD(void) 
{
   LCD_Write_Com(0x30);    											/*��ʾģʽ����							*/ 
   delay_ms(1); 
   LCD_Write_Com(0x30); 
   delay_ms(1); 
     
   LCD_Write_Com(0x08);    											/*��ʾ�ر�								*/ 
   LCD_Write_Com(0x10);
   delay_ms(1); 
   LCD_Write_Com(0x0C);    											/*��ʾ�����������						*/
   LCD_Write_Com(0x01);    											/*��ʾ����								*/ 
   LCD_Write_Com(0x06);    											/*��ʾ����ƶ�����						*/ 
   
}

#endif
																	/**********LCD12864�����������	*********/

																	/******LCD1602+12864����������***********/
void LCD_Clear(void)
{
	LCD_Write_Com(0x01);
}

																	/***********��ʾ+����ת������************/
void ConvertNumToDisplay(uchar x,uchar y,uint Num)  
{
	qian_data=Num/1000 ;													
	Num=Num%1000;   												/*ȡ������								*/
	bai_data=Num/100 ;
	Num=Num%100;   													/*ȡ������								*/
	shi_data=Num/10 ;
	Num=Num%10;   													/*ȡ������								*/
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
//																	/************��ʾ10������//**************/
//void ConvertOctToDisplay(uchar x,uchar y,uint Octnum)
//{
//	uchar a, b, c, d;
//	
//	a = (Octnum/256)/10; 											/*ȡ���ֽڵĸ�4λ						*/
//	b = (Octnum/256)%10; 											/*ȡ���ֽڵĵ�4λ						*/
//	
//	c = (Octnum%256)/10; 											/*ȡ���ֽڵĸ�4λ					   	*/
//	d = (Octnum%256)%10; 											/*ȡ���ֽڵĵ�4λ						*/
//
//	Gotoxy(x,y);	
//
//	LCD_Write_Data(oct_table[a]);
//	LCD_Write_Data(oct_table[b]);
//	LCD_Write_Data('.');
//	LCD_Write_Data(oct_table[c]);
//	LCD_Write_Data(oct_table[d]);
//}
																	/*************��ʾ16������//*************/
//void ConvertHexToDisplay(uchar x,uchar y,uint Hexnum)
//{
//	uchar a, b, c, d;
//																			
//	a = (Hexnum/256)/16; 											/*ȡ���ֽڵĸ�4λ						*/
//	b = (Hexnum/256)%16; 											/*ȡ���ֽڵĵ�4λ
//	
//	c = (Hexnum%256)/16; 											/*ȡ���ֽڵĸ�4λ						*/
//	d = (Hexnum%256)%16; 											/*ȡ���ֽڵĵ�4λ						*/
//
//	Gotoxy(x,y);
//
//	LCD_Write_Data(hex_table[a]);
//	LCD_Write_Data(hex_table[b]);
//	LCD_Write_Data(hex_table[c]);
//	LCD_Write_Data(hex_table[d]);
//}

