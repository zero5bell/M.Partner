/**********ͷ�ļ�����******************************/
#include "../Include/ObstDetect.h"

/*********ȫ�ֱ�������*****************************/

/*********��������*************/
/************************************************************************************************************************/
uchar ObstDetect(void)								/***************	�ϰ����	*************************************/
{
	uchar InfraredFlag = 0;							/*�ϰ�λ��[0:��][1:ǰ][2:ǰ/��][3:ǰ/��][4:ǰ/��/��][5:ǰ/��/��/��]	*/
	uchar RangingFlag = 0;							/*�ϰ�λ��[0:��][1:ǰ][2:ǰ/��][3:ǰ/��][4:ǰ/��/��][5:ǰ/��/��/��]	*/
	uchar ObstFlag[16]={0,7,7,7,7,7,7,7,1,7,3,7,2,7,4,5};	
													/*�ϰ�λ��[0:��][1:ǰ][2:ǰ/��][3:ǰ/��][4:ǰ/��/��][5:ǰ/��/��/��]	*/
													/*		   0000	 1000	 1100	  1010	   1110			1111		*/

//	InfraredFlag = ObstInfrared();							/*������ϼ��												*/

	InfraredFlag = 0; //test	

	RangingFlag = UltraSonicRanging();						/*������⣬ǰ��Ϊ0�����ϰ������ж�							*/

	if((RangingFlag == 1)||(InfraredFlag != 0))
	{														/*ǰ�����ϰ�����������									*/
		StGearTurnLeft90();									/*���ת����												*/
		RangingFlag = (RangingFlag<<1)+UltraSonicRanging();	/*������⣬��												*/

		StGearTurnMid00();									/*�������ת��ָ��λ��										*/
		StGearTurnRight90();								/*���ת����												*/
		RangingFlag = (RangingFlag<<1)+UltraSonicRanging();	/*������⣬��												*/

		RangingFlag =(RangingFlag<<1)+0;					/*�����������󷽣��˴�������λ							*/

		StGearTurnMid00();									/*�������													*/
	}
																						   
	return ObstFlag[RangingFlag|InfraredFlag];				/*���ؼ����												*/
}


