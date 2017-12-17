/**********头文件定义******************************/
#include "../Include/UltraSonicRanging.h"

/*********全局变量声明*****************************/
uint32	Dist[3];							/*测距接收缓冲区											*/
uchar gucTimerH,gucTimerL;					/*自定义寄存器												*/
bit SucceedFlag;							/*测量成功标志												*/

/*********函数定义*********************************/
/********************************************************************************************************/
void Init_UltraSonicRanging(void)			/************************超声波初始化************************/
{	  
	Tx=0;       							/*首先拉低脉冲输入引脚										*/
	TMOD=0x11;    							/*定时器0，定时器1，16位工作方式							*/
	IT0=0;        							/*由高电平变低电平，触发外部中断，下降沿触发				*/
	EX0=0;        							/*外部中断													*/
	EA=0;  		  							/*关闭总中断0												*/
}

uchar UltraSonicRanging(void)				/**************************	测距*****************************/
{  
	uint32 dist_data;
 	uchar i;
	uchar ObstFlag = 0; 

	for(i=0;i<=2;i++)
	{
		EA=0;
		Tx=1;
		delay_100us(1);
		Tx=0;         						/*产生一个20us的脉冲，在Tx引脚								*/  
	
	    while(Rx==0); 						/*等待Rx回波引脚变高电平									*/
	    SucceedFlag=0; 						/*清测量成功标志											*/
																								
	    EX0=1;          					/*打开外部中断												*/
	 	TH1=0;          					/*定时器1清零												*/
	    TL1=0;          					/*定时器1清零												*/
	    TF1=0;
	    TR1=1;          					/*启动定时器1												*/
		EA=1;

	    while(TH1<30);						/*等待测量的结果，周期65.535毫秒（可用中断实现）			*/ 
		TR1=0;          					/*关闭定时器1												*/
	    EX0=0;          					/*关闭外部中断0												*/
		EA=0;

		if(SucceedFlag == 1)				/*有回波													*/
		{ 	
			dist_data=gucTimerH;			/*测量结果的高8位											*/
			dist_data<<=8;					/*放入16位的高8位											*/
			dist_data=dist_data|gucTimerL;	/*与低8位合并成为16位结果数据								*/
			dist_data*=12;                 	/*因为定时器默认为12分频									*/
			dist_data/=58;                 	/*微秒的单位除以58等于厘米									*/
		}									/*为什么除以58等于厘米，  Y米=（X秒*344）/2					*/
											/*X秒=（ 2*Y米）/344 ==》X秒=0.0058*Y米 ==》厘米=微秒/58 	*/
		else if(SucceedFlag == 0)
		{
			dist_data=0;					/*没有回波则清零											*/
		}
		else
		{
			return 0x1F;					/*异常保护													*/
		}
	
		Dist[i]=dist_data;					/*将测量结果的数据放入缓冲区								*/
	}
	EA = 0;
	RangingSort();							/*将测量结果排序，最大值输出								*/

	ConvertNumToDisplay(1,1,Dist[1]);		/*测量结果转换+LCD显示										*/      
	     
	if((Dist[1] > 0x012D)||(Dist[1] == 0))
	{
		ObstFlag = 0;
	}
	else
	{
		ObstFlag = 1;
	}
	Dist[0]=0;Dist[1]=0;Dist[2]=0;Dist[3]=0;/*变量清零，避免误判										*/
	EA = 1; 
	return ObstFlag;
}
											/************************测距结果排序************************/
void RangingSort(void)
{  
	uint32 temp;
	if (Dist[0]>Dist[1])
		{temp=Dist[0];Dist[0]=Dist[1];Dist[1]=temp;} 
	if(Dist[0]>Dist[2])
		{temp=Dist[2];Dist[2]=Dist[0];Dist[0]=temp;} 
	if(Dist[1]>Dist[2])
		{temp=Dist[1];Dist[1]=Dist[2];Dist[2]=temp;}  
}

											/*****************外部中断0，用做判断回波电平****************/
INT0_()  interrupt 0   						/* 外部中断0												*/
{    
	gucTimerH =TH1;    						/*取出定时器的值											*/
	gucTimerL =TL1;    						/*取出定时器的值											*/
	SucceedFlag = 1;   						/*置成功测量的标志											*/
	EX0 = 0;								/*关闭外部中断												*/
}


