/**********头文件定义***********/
#include "../Include/ObstInfrared.h"

/**********全局变量声明*********/

/**********函数定义*************/
/********************************************************************************************************************/
uchar ObstInfrared(void)						/*******************			红外避障检测		*****************/
{												/*障碍位置[0:无][1:前][2:前/左][3:前/右][4:前/左/右][5:前/左/右/后]	*/
												/*		   0000	 0001	 0011	  0101	   0111			1111		*/
	uchar InfraredFlag;					
	uchar TempFlag;

	if(INFRARED_FRONT == 0)
	{
		InfraredFlag = 0;						/*无障碍															*/
	}
	else if(INFRARED_FRONT == 1)				/*有障碍															*/
	{
		TempFlag = INFRARED_FRONT;				/*前																*/
		InfraredFlag=(InfraredFlag<<1)|TempFlag;
		TempFlag = INFRARED_LEFT;				/*左																*/
		InfraredFlag=(InfraredFlag<<1)|TempFlag;
		TempFlag = INFRARED_RIGHT;				/*右																*/
		InfraredFlag=(InfraredFlag<<1)|TempFlag;
		TempFlag = INFRARED_BEHIND;				/*后																*/
		InfraredFlag=(InfraredFlag<<1)|TempFlag;
	}

	return InfraredFlag;
}



