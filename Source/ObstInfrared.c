/**********ͷ�ļ�����***********/
#include "../Include/ObstInfrared.h"

/**********ȫ�ֱ�������*********/

/**********��������*************/
/********************************************************************************************************************/
uchar ObstInfrared(void)						/*******************			������ϼ��		*****************/
{												/*�ϰ�λ��[0:��][1:ǰ][2:ǰ/��][3:ǰ/��][4:ǰ/��/��][5:ǰ/��/��/��]	*/
												/*		   0000	 0001	 0011	  0101	   0111			1111		*/
	uchar InfraredFlag;					
	uchar TempFlag;

	if(INFRARED_FRONT == 0)
	{
		InfraredFlag = 0;						/*���ϰ�															*/
	}
	else if(INFRARED_FRONT == 1)				/*���ϰ�															*/
	{
		TempFlag = INFRARED_FRONT;				/*ǰ																*/
		InfraredFlag=(InfraredFlag<<1)|TempFlag;
		TempFlag = INFRARED_LEFT;				/*��																*/
		InfraredFlag=(InfraredFlag<<1)|TempFlag;
		TempFlag = INFRARED_RIGHT;				/*��																*/
		InfraredFlag=(InfraredFlag<<1)|TempFlag;
		TempFlag = INFRARED_BEHIND;				/*��																*/
		InfraredFlag=(InfraredFlag<<1)|TempFlag;
	}

	return InfraredFlag;
}



