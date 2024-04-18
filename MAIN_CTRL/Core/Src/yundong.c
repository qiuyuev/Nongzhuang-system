#include "yundong.h"
#include "tim.h"
char dianji[7];
void mfangxiang(char m1,char m2,char m3,char m4)//4个电机正反转，0停止，1正转，2反转
{
    dianji[0]=m1;
    dianji[1]=m2;
    dianji[2]=m3;
    dianji[3]=m4;
}
void msp(char m1sp,char m3sp)//4个电机，两对速度
{
    dianji[4]=m1sp;
    dianji[5]=m3sp;
}
//舵机1，2.5ms 直行，舵机2，2.5ms 90°
void duojijiangdu(char d1,char d2)    //1直行，2转向
{
		if(d1==1)
		__HAL_TIM_SetCompare(&htim4, TIM_CHANNEL_1,135);
		if(d1==2)
		__HAL_TIM_SetCompare(&htim4, TIM_CHANNEL_1,250);		//舵机1
		
		if(d2==1)
		__HAL_TIM_SetCompare(&htim4, TIM_CHANNEL_2,20);
		if(d2==2)
		__HAL_TIM_SetCompare(&htim4, TIM_CHANNEL_2,25);       //舵机2
}
void yundong(char i,char sp)
{
switch(i)
    {
        case 0: {
                mfangxiang(0,0,0,0);
                msp(0,0);//停车状态
                duojijiangdu(0,0);break;
        } 

        case 1:{
                mfangxiang(1,1,1,1);    //前进
                msp(sp,sp);
                duojijiangdu(1,1);break;
                //zitai2(chao2,chao5);
        }

        case 2: {
                mfangxiang(2,2,2,2);    //后退
                msp(sp,sp);
                duojijiangdu(1,1);break;
                //zitai2(chao4,chao6);
        }
        case 3: {
                mfangxiang(1,1,1,1);    //右转
                msp(sp,sp);
                duojijiangdu(2,2);break;
                //zitai1(1,chao3);
        }
        case 4: {
                mfangxiang(2,2,2,2);    //左转
                msp(sp,sp);
                duojijiangdu(2,2);break;
                //zitai1(1,chao3);
        }

    }
}
//姿态调整可以先不开，在上面那个yundong函数打开
void zitai1(char i,float chao3)    //姿态调整，参数1模式：1是右跨龙调整2是左跨龙调整，参数2和3是，1和3号超声波数值  1号数值20cm，3号7cm
{
    float wucha;
    int jiaodu1;
    int jiaodu2;
    if(chao3>7)    //朝内，靠近龙
    {

    }
    if(chao3<7)    //朝外，远离龙
    {

    }
    duojijiangdu(jiaodu1,jiaodu2);
}
void zitai2(char i,float chao1,float chao2)   //i1为前进，i2为后退
{
    int jiaodu1;
    int jiaodu2;
    if(i==1)
    {
        if(chao1>7)    //前轮左偏
        {

        }
        if(chao1<6)    //前轮右偏
        {

        }
        if(chao1>7)    //后轮左偏
        {

        }
        if(chao1<6)    //后轮左偏
        {

        }
        duojijiangdu(jiaodu1,jiaodu2);
    }
}
void test_task(char flag)
{
	//  switch(flag)
//  {
//    case 0:
//      yundong(0);
//      //小延时
//      flag++;
//    
//    case 1:   //直行
//      yundong(1);
//      if(chao1<20)
//      {flag++;}
//      break;
//    
//    case 2:   //右转,跨第一个龙
//      yundong(3);
//      if(chao4<7&&chao6<7)
//      {flag++;}
//      break;

//    case 3:   //后退
//      yundong(2);
//      //定时器小延时
//      if(chao2>60&&chao5>60)
//      {flag++;}

//    case 4:   //左转,跨第二个龙
//      yundong(3);
//      if(chao2<7&&chao5<7)
//      {flag++;}
//      break;
//    
//    case 5:   //后退           
//      yundong(2);
//      //定时器小延时
//      if(chao4>60&&chao6>60)
//      {flag++;}

//    case 6:   //右转,跨第三个龙
//      yundong(3);
//      if(chao4<7&&chao6<7)
//      {flag++;}
//      break;

//    case 7:   //后退
//      yundong(2);
//      //定时器小延时
//      if(chao2>60&&chao5>60)
//      {flag++;}

//    case 8:   //左转,跨第四个龙
//      yundong(3);
//      if(chao2<7&&chao5<7)
//      {flag++;}
//      break;
//    
//    case 9:   //后退           
//      yundong(2);
//      //定时器小延时
//      if(chao4>60&&chao6>60)
//      {flag++;}

//    case 10:   //右转,跨第五个龙
//      yundong(3);
//      if(chao4<7&&chao6<7)
//      {flag++;}
//      break;

//    case 11:   //左转,到入口
//      yundong(3);
//      if(chao2<7&&chao5<7)
//      {flag++;}
//      break;

//    case 12:   //后退           
//      yundong(2);
//      //定时器小延时
//      if(chao4>60&&chao6>60)
//      {flag++;}
//  }
}