/**********ͷ�ļ�����***********/
#include "../Include/ObstAvoid.h"

/**********ȫ�ֱ�������*********/

/**********��������*************/
/********************************************************************************/
void ObstAvoid(uchar ObstFlag)				/*********	���Ϻ���	*************/
{
	if(ObstFlag == 0)						/*���ϰ���ǰ��						*/
	{
		WheelForward();
	}
	else if(ObstFlag == 1)					/*�ϰ���ǰ����/��ת�Կɣ�Ĭ����ת	*/
	{
		WheelTurnLeft();
	}
	else if(ObstFlag == 2)					/*�ϰ���ǰ/����ת					*/
	{
		WheelTurnRight();
	}	
	else if(ObstFlag == 3)					/*�ϰ���ǰ/�ң���ת					*/
	{
		WheelTurnLeft();
	}	
	else if(ObstFlag == 4)					/*�ϰ���ǰ�����ң�����			*/
	{
		WheelBackward();
	}	
	else
	{
	 	WheelEngineStop();					/*�ϰ��ڣ�ǰ�������ң�ֹͣ		*/
	}
}

