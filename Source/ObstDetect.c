/**********头文件定义******************************/
#include "../Include/ObstDetect.h"

/*********全局变量声明*****************************/

/*********函数定义*************/
/************************************************************************************************************************/
uchar ObstDetect(void)								/***************	障碍检测	*************************************/
{
	uchar InfraredFlag = 0;							/*障碍位置[0:无][1:前][2:前/左][3:前/右][4:前/左/右][5:前/左/右/后]	*/
	uchar RangingFlag = 0;							/*障碍位置[0:无][1:前][2:前/左][3:前/右][4:前/左/右][5:前/左/右/后]	*/
	uchar ObstFlag[16]={0,7,7,7,7,7,7,7,1,7,3,7,2,7,4,5};	
													/*障碍位置[0:无][1:前][2:前/左][3:前/右][4:前/左/右][5:前/左/右/后]	*/
													/*		   0000	 1000	 1100	  1010	   1110			1111		*/

//	InfraredFlag = ObstInfrared();							/*红外避障检测												*/

	InfraredFlag = 0; //test	

	RangingFlag = UltraSonicRanging();						/*超声检测，前，为0则无障碍，不判断							*/

	if((RangingFlag == 1)||(InfraredFlag != 0))
	{														/*前方有障碍，则检查左右									*/
		StGearTurnLeft90();									/*舵机转向，左												*/
		RangingFlag = (RangingFlag<<1)+UltraSonicRanging();	/*超声检测，左												*/

		StGearTurnMid00();									/*辅助舵机转到指定位置										*/
		StGearTurnRight90();								/*舵机转向，右												*/
		RangingFlag = (RangingFlag<<1)+UltraSonicRanging();	/*超声检测，右												*/

		RangingFlag =(RangingFlag<<1)+0;					/*超声波不检查后方，此处凑数补位							*/

		StGearTurnMid00();									/*舵机归中													*/
	}
																						   
	return ObstFlag[RangingFlag|InfraredFlag];				/*返回检测结果												*/
}


