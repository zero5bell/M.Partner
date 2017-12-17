/**********ͷ�ļ�����************/
#include "../Include/include.h"
#include "../Include/LCD.h"
#include "../Include/ObstDetect.h"
#include "../Include/ObstAvoid.h"
#include "../Include/SteeringGear.h"
#include "../Include/Gogogo.h"
#include "../Include/Alarm.h"
/**********ȫ�ֱ�������**********/
uchar gucObstFlag = 0;			 /*�ϵ�Ĭ�ϴ����ϰ�//[0:���ϰ�][1:��ת][2:��ת][3:����][7:��ʼ�����][����:ֹͣ]*/
uchar gucTempFlag = 0;
/**********��������**************/
/****************************************************************************************************************/
void main()
{														/***************************ϵͳ��ʼ��*******************/ 	
	Init_LCD();											/*LCD��ʼ��												*/
	Init_UltraSonicRanging();							/*����������ʼ��										*/
	Init_StGear();										/*�����ʼ��											*/
	Alarm(7);											/*��ʼ����ɸ澯										*/
	while(1)								
	{ 													/***************************��⣬����*******************/		
		gucObstFlag = ObstDetect();						/*����Ƿ����ϰ�										*/						  		
		ObstAvoid(gucObstFlag);							/*���ϲ���												*/
		Alarm(gucObstFlag);								/*�澯													*/
	}	
}

