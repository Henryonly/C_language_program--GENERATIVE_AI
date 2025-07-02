
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
#include<string.h>

//创建图形元素,并完善图形元素中的信息 
//后面函数调用它时，只需先建立结构体，之后再调用这个函数，就可以完善结构体了。  
void creat_pic(object p,char name[30],int num[3],int x,int y)
{
	
	int i=0;
	
	//逐一赋值
	strcpy(p.name,name);
	
	for(i=0;i<3;i++)
	{
		p.num[i]=num[i];
	} 
	 
	p.x=x;
	p.y=y;
	//赋值完毕，可以按照所画的图来逐一完善结构体
} 




//在已知图形中元素及位置时将具体位置根实际情况据有机调整
//将各个部分的图像有机合并 
//重点是优化升级，进而避免图形的错位 
void merge(object* a)
{
	
	int i=0;
	int j=0;

	switch(a[i])
	{
		case 0:
			
			
	}
}


//画出最终生成的图 
void wen_sheng_tu(int color[4],int a[5],int b[5],int c[5])
{
	int a[8];
	int draw;
	int i;
	int j;
	int p;
	
	//按要求创建背景
	//背景最多2个 
	
	 
	fill_color(0,0,1024,768,color,page,0);//最后一位是0/1不一定
	switch()
	
		
}
