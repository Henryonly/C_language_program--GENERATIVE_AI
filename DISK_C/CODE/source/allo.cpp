




#include<graphics.h>
#include<draw.h>
#include<stdarg.h>
#include<conio.h>
#include<Bezier.h>
#include<xiezi.h>
#include<color.h>
#include<dos.h>
#include<stddef.h>
#include<mouse.h>
#include<stdlib.h>
#include<car.h>
#include<dog.h>
#include<boy.h>
#include<fish.h>
#include<allo.h>
#include<view.h>
/********************
	
函数目的：重新定位（按照不同的要求） 
	
	x,y:该图像原点（放缩的点）所处位置，用于后面画图
	即car(int x,int y,float k,int color,int page)里面的x,y 

	k:放缩倍数 
	
	posi:提供定位数据的数组 
			posi[0]：上 
			posi[1]：下
			posi[2]：左
			posi[3]：右 
			posi[4]：中x
			posi[5]：中y			
			
	p0:原图中的初始坐标（刚画出来的） 
			p0[0]：上 
			p0[1]：下
			p0[2]：左
			p0[3]：右 
			p0[4]：中x
			p0[5]：中y	
			
	xy0:原图中的原点坐标（刚画出来的） 	
			
	judge[0]： 确定需要根据什么定位（只是定位，不包括放缩） 
	
			1：按照 左、上 定位（停靠） 
			2：按照 右、上 定位（停靠） 
			3：按照 左、下 定位（停靠） 
			4：按照 右、下 定位（停靠） 
			5：按照 中心定位（中心停靠） 
			
	judge[1]: 既控制位置，又限制大小，该函数负责限制大小 
			如果要是上下左右都想限制的话，横纵比很有可能不一样，图形的形状就会出问题，所以特别设立这几种情况 
		
			1：按 上、下 控制大小
			2：按 左、右 控制大小
140********************/

void allo(int* x,int* y,float* k,int page,int* posi,int* p0,int* xy0,int* judge)
{
	/******
	等式方程 
	posi[0] = k*(*y-xy0[1]+p0[0])-*y*(k-1) = (p0[0]-xy0[1])*k+*y
	posi[1] = k*(*y-xy0[1]+p0[1])-*y*(k-1) = (p0[1]-xy0[1])*k+*y
	posi[2] = k*(*x-xy0[0]+p0[2])-*x*(k-1) = (p0[2]-xy0[0])*k+*x
	posi[3] = k*(*x-xy0[0]+p0[3])-*x*(k-1) = (p0[3]-xy0[0])*k+*x

	posi[4] = k*(*x-xy0[0]+p0[4])-*x*(k-1) = ((posi[2]+posi[3])/2-xy0[0])*k+*x
	posi[5] = k*(*y-xy0[1]+p0[5])-*y*(k-1) = ((posi[0]+posi[1])/2-xy0[1])*k+*y
	******/	

/*	
解得： 
	*y=posi[0]-(p0[0]-xy0[1])*k;
	*y=posi[1]-(p0[1]-xy0[1])*k;
	*x=posi[2]-(p0[2]-xy0[0])*k;
	*x=posi[3]-(p0[3]-xy0[0])*k;
	
	*x=posi[4]-((posi[2]+posi[3])/2-xy0[0])*k;
	*y=posi[5]-((posi[0]+posi[1])/2-xy0[1])*k;
*/	

	//处理放缩的倍数 
	switch(judge[1])
	{
		case 1:
			*k=((float)(posi[1]-posi[0]))/((float)(p0[1]-p0[0])); 
			break;
		case 2:
			*k=((float)(posi[3]-posi[2]))/((float)(p0[3]-p0[2])); 
			break;	
		default:
			*k=((float)(posi[3]-posi[2]))/((float)(p0[3]-p0[2])); 
			break;
	}
	
	//具体定位图形位置 
	switch(judge[0])
	{
		case 1:
			*y=posi[0]-(p0[0]-xy0[1])*(*k);
			*x=posi[2]-(p0[2]-xy0[0])*(*k);
			posi[1]=posi[0]+*k*(p0[1]-p0[0]);
			posi[3]=posi[2]+*k*(p0[3]-p0[2]);
			break;
		case 2:
			*y=posi[0]-(p0[0]-xy0[1])*(*k);
			*x=posi[3]-(p0[3]-xy0[0])*(*k);
			posi[1]=posi[0]+*k*(p0[1]-p0[0]);
			posi[2]=posi[3]-*k*(p0[3]-p0[2]);
			break;
		case 3:
			*y=posi[1]-(p0[1]-xy0[1])*(*k);
			*x=posi[2]-(p0[2]-xy0[0])*(*k);
			posi[0]=posi[1]-*k*(p0[1]-p0[0]);
			posi[3]=posi[2]+*k*(p0[3]-p0[2]);
			break;
		case 4:
			*y=posi[1]-(p0[1]-xy0[1])*(*k);
			*x=posi[3]-(p0[3]-xy0[0])*(*k);
			posi[0]=posi[1]-*k*(p0[1]-p0[0]);
			posi[2]=posi[3]-*k*(p0[3]-p0[2]);
			break;
		case 5:
			*x=posi[4]-(p0[4]-xy0[0])*(*k);
			*y=posi[5]-(p0[5]-xy0[1])*(*k);
			posi[0]=posi[5]-*k*(p0[5]-p0[0]);
			posi[1]=posi[5]+*k*(p0[1]-p0[5]);
			posi[2]=posi[4]-*k*(p0[4]-p0[2]);
			posi[3]=posi[4]+*k*(p0[3]-p0[4]);
			break;

		default:
			*x=posi[4]-(p0[4]-xy0[0])*(*k);
			*y=posi[5]-(p0[5]-xy0[1])*(*k);
			posi[0]=posi[5]-*k*(p0[5]-p0[0]);
			posi[1]=posi[5]+*k*(p0[1]-p0[5]);
			posi[2]=posi[4]-*k*(p0[4]-p0[2]);
			posi[3]=posi[4]+*k*(p0[3]-p0[4]);
			break;
	}
} 




//画小汽车朝左 
void put_picture_car1(int* posi,int* judge,int page,int color)
{
	
	int x=0;
	int y=0;
	float k=1.0;
	int xy0[2]={304,618};
	int p0[6]={362,662,207,683,445,512};
			
	allo(&x,&y,&k,page,posi, p0, xy0,judge);
 	secure(posi);
 	allo(&x,&y,&k,page,posi, p0, xy0,judge);
	car(x,y,k,color,page,0);
	car_light(x,y,k,color,page,0); 
	car_windows(x,y,k,color,page,0); 
}

//画小汽车朝右 
void put_picture_car2(int* posi,int* judge,int page,int color)
{
	
	int x=0;
	int y=0;
	float k=1.0;
	int xy0[2]={304,618};
	int p0[6]={362,662,207,683,445,512};
			
	allo(&x,&y,&k,page,posi, p0, xy0,judge);
 	secure(posi);
 	allo(&x,&y,&k,page,posi, p0, xy0,judge);
	car(x,y,k,color,page,1);
	car_light(x,y,k,color,page,1); 
	car_windows(x,y,k,color,page,1); 
}


//画小男孩 
void put_picture_boy(int* posi,int* judge,int page,int color)	
{
	int x=0;
	int y=0;
	float k=1.0;
	int xy0[2]={524,353};
	int p0[6]={350,689,442,585,513,520};	
 
 	allo(&x,&y,&k,page,posi, p0, xy0,judge);
	secure(posi);	
	allo(&x,&y,&k,page,posi, p0, xy0,judge);
	boy(x,y,k,color,page);	
}


//画小狗（右） 
void put_picture_dog1(int* posi,int* judge,int page,int color)
{
 	int x=0;
 	int y=0;
 	float k=1.0;
 	int xy0[2]={414,245};
 	int p0[6]={70,470,216,610,413,270};	
 	
 	allo(&x,&y,&k,page,posi, p0, xy0,judge);
 	dog_body(x,y,k,color,page,0);	
	dog_eyes(x,y,k,color,page,0);	
}

//画填充小狗（右） 
void put_picture_dog1_fill(int* posi,int* judge,int page,int color)
{
 	int x=0;
 	int y=0;
 	float k=1.0;
 	int xy0[2]={414,245};
 	int p0[6]={70,470,216,610,413,270};	
 	
 	allo(&x,&y,&k,page,posi, p0, xy0,judge);
 	dog_body(x,y,k,color,page,0);	
 	fill_1(color,page);
	dog_eyes(x,y,k,color,page,0);
}
 
//画小狗（左） 
void put_picture_dog2(int* posi,int* judge,int page,int color)
{
 	int x=0;
 	int y=0;
 	float k=1.0;
 	int xy0[2]={414,245};
 	int p0[6]={70,470,216,610,413,270};	
 	
 	allo(&x,&y,&k,page,posi, p0, xy0,judge);
 	dog_body(x,y,k,color,page,1);	
 	dog_eyes(x,y,k,color,page,1);
}

//画填充小狗（左） 
void put_picture_dog2_fill(int* posi,int* judge,int page,int color)
{
 	int x=0;
 	int y=0;
 	float k=1.0;
 	int xy0[2]={414,245};
 	int p0[6]={70,470,216,610,413,270};	
 	
 	allo(&x,&y,&k,page,posi, p0, xy0,judge);
 	dog_body(x,y,k,color,page,1);
 	fill_1(color,page);
	dog_eyes(x,y,k,color,page,1);	
}

//画鱼(左) 
void put_picture_fish1(int* posi,int* judge,int page,int color)	
{
 	int x=0;
 	int y=0;
 	float k=1.0;
 	int xy0[2]={497,411};
 	int p0[6]={411,490,445,635,540,450};	
 	
 	allo(&x,&y,&k,page,posi, p0, xy0,judge);
 	secure(posi);
 	allo(&x,&y,&k,page,posi, p0, xy0,judge);
 	fish(x,y,k,color,page,0);	
 	fish_head(x,y,k,color+1,page,0);
 	fish_eye(x,y,k,color+2,page,0);
}
 

//画鱼(右) 
void put_picture_fish2(int* posi,int* judge,int page,int color)	
{
 	int x=0;
 	int y=0;
 	float k=1.0;
 	int xy0[2]={497,411};
 	int p0[6]={411,490,445,635,540,450};	
 	
 	allo(&x,&y,&k,page,posi, p0, xy0,judge);
 	secure(posi);
 	allo(&x,&y,&k,page,posi, p0, xy0,judge);
 	fish(x,y,k,color,page,1);	
 	fish_head(x,y,k,color+1,page,1);
 	fish_eye(x,y,k,color+1,page,1);
}
 
//画连绵不断的山（放缩倍数k为1是从最左面连到最右面） 
void put_picture_mountain(int* posi,int* judge,int page,int color)	
 {	int x=0;
 	int y=0;
 	float k=1.0;
 	int xy0[2]={1,343};
 	int p0[6]={0,689,1,1024,512,363};	
 	
 	allo(&x,&y,&k,page,posi, p0, xy0,judge);
 	mountain(x,y,k,color,page);
}


//画水的波纹 
void put_picture_water(int* posi,int* judge,int page,int color)
{
	int x=0;
 	int y=0;
 	float k=1.0;
 	int xy0[2]={1,343};
 	int p0[6]={653,697,214,620,417,675};	
 	
 	allo(&x,&y,&k,page,posi, p0, xy0,judge);
 	water(x,y,k,color,page);
}


//画天空中的云 
void put_picture_cloud(int* posi,int* judge,int page,int color)
{
 	int x=0;
 	int y=0;
 	float k=1.0;
 	int xy0[2]={1,343};
 	int p0[6]={39,125,186,302,244,164};	
 	
 	allo(&x,&y,&k,page,posi, p0, xy0,judge);
 	cloud(x,y,k,color,page);
}

//防止图形越界 
void secure(int* posi)
{
	if(posi[0]<=105)
	{
		posi[1]+=(105-posi[0]);
		posi[0]=105;
	}
	if(posi[1]>=489)
	{
		posi[0]-=(posi[1]-489);
		posi[1]=489;
	}
	if(posi[2]<=135)
	{
		posi[3]+=(135-posi[2]);
		posi[2]=135;
	}
	if(posi[3]>=925)
	{
		posi[2]-=(posi[3]-925);
		posi[3]=925;
	} 
}
