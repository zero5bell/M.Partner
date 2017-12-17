/**********头文件定义***********/
#include "../Include/ObstAvoid.h"

/**********全局变量声明*********/

/**********函数定义*************/
/********************************************************************************/
void ObstAvoid(uchar ObstFlag)				/*********	避障函数	*************/
{
	if(ObstFlag == 0)						/*无障碍，前进						*/
	{
		WheelForward();
	}
	else if(ObstFlag == 1)					/*障碍：前，左/右转皆可，默认左转	*/
	{
		WheelTurnLeft();
	}
	else if(ObstFlag == 2)					/*障碍：前/左，右转					*/
	{
		WheelTurnRight();
	}	
	else if(ObstFlag == 3)					/*障碍：前/右，左转					*/
	{
		WheelTurnLeft();
	}	
	else if(ObstFlag == 4)					/*障碍：前、左、右，后退			*/
	{
		WheelBackward();
	}	
	else
	{
	 	WheelEngineStop();					/*障碍在：前、后、左、右，停止		*/
	}
}

