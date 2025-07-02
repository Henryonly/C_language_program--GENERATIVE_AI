
/*
**文件名称：ptext
**文件目的：实现对话框的构建
**时间复杂度：最小，但是正比于字符串长度
**空间复杂度：\Theta(像素存储个数)
*/

#include<Bezier.h>
#include<ptext.h>
#include<string.h>
#include<stdlib.h>
#include<alloc.h>
#include<stdio.h>
#include<draw.h>
#include<xiezi.h>
#include<color.h>

//extern char far input[21][421];//test

void robot_avatar(int x,int y,int page)
//x,y是圆心位置
{
	circle_with_drawing(x,y,50,WHITE_,page,1);
	fill_color(x-37,y-22,x+41,y+30,GAINSBORO_,page,1);
	circle_with_drawing(x-24,y,15,YELLOW_,page,1);
	circle_with_drawing(x+24,y,15,YELLOW_,page,1);
	circle_with_drawing(x-24,y,4,RED_,page,1);
	circle_with_drawing(x+24,y,4,RED_,page,1);
	static int x0[3];
	static int y0[3];
	x0[0]=x-16;
	y0[0]=y+22;
	x0[1]=x;
	y0[1]=y+32;
	x0[2]=x+16;
	y0[2]=y+22;
	Bezier(RED_,3,page,x0,y0,1);
	circle_with_drawing(x-24,y-35,5,SPRING_GREEN_,page,1);
	circle_with_drawing(x+24,y-35,5,SPRING_GREEN_,page,1);
	line_drawing(x-24,y-22,x-24,y-30,BROWN_,page,1);
	line_drawing(x+24,y-22,x+24,y-30,BROWN_,page,1);
}

void user_avatar(int x,int y,int page)
//x,y是圆心位置
{
	circle_with_drawing(x,y,50,YELLOW_,page,1);
	circle_with_drawing(x-30,y-20,15,WHITE_,page,1);
	circle_with_drawing(x+30,y-20,15,WHITE_,page,1);
	circle_with_drawing(x-30,y-20,4,BLACK_,page,1);
	circle_with_drawing(x+30,y-20,4,BLACK_,page,1);
	static int x0[3];
	static int y0[3];
	x0[0]=x-25;
	y0[0]=y+10;
	x0[1]=x;
	y0[1]=y+50;
	x0[2]=x+25;
	y0[2]=y+10;
   Bezier(RED_,3,page,x0,y0,1);
}

void text_rectangle(int RAM,int mode,int page,int y,int sum,int status)
//其中的y需要通过鼠标拖动的逻辑算出来
//字符串从文件里读取
//!!!此时的文件里面字母都是重复两遍的!!!
{
	char paths[50]={0};
	sprintf(paths,"C:\\CODE\\chat\\chat%d",RAM);
	FILE *fp;
	fp=fopen(paths,"rt+");//可读可写
	char display[10001];//支持5000汉字
	char temp=1;
	int count=0;
	while(temp!=0)
	{
		temp=fgetc(fp);
		display[count++]=temp;
	}
	count--;
	//这时候，count就是字符串里面不算上\0的长度

	//计算输入法框框的大小
	int hanzishu=count/2-sum;
	int ascshu=sum;
	int height=(hanzishu+ascshu)/TEXTWORD+1;
	if(mode==USER)
	{
		draw_final0(display,height,y,page,status);
	}
	if(mode==ROBOT)
	{
		draw_final1(display,height,y,page,status);
	}
	fclose(fp);
}

void draw_final0(char *display,int height,int y,int page,int status)
//y是起始点，可以为负数
{
	//图像与对话框
	robot_avatar(55,y+35,page);
	int i;
	for(i=-1;i<=1;i++)
	{
		line_drawing(104,y+35,135,y+15,WHITE_,page,1);
		line_drawing(104,y+35,135,y+40,WHITE_,page,1);
		line_drawing(135,y+15,800,y+15,WHITE_,page,1);
	}
	fill_color(135,y+15,950,y+15+height*WORDWIDTH,WHITE_,page,1);
	for(i=16;i<40;i++)
	{
		line_drawing(104,y+35,135,y+i,WHITE_,page,1);
	}
	//else if(status==NONFILL_STATUS)
	//{
	//	fill(120,1,WHITE_,page,1);
	//	;
	//}
	line_drawing(104,y+35,135,y+15,BLACK_,page,1);
	line_drawing(104,y+35,135,y+40,BLACK_,page,1);
	line_drawing(135,y+15,950,y+15,BLACK_,page,1);
	line_drawing(950,y+15,950,y+15+height*WORDWIDTH,BLACK_,page,1);
	line_drawing(950,y+15+height*WORDWIDTH,135,y+15+height*WORDWIDTH,BLACK_,page,1);
	line_drawing(135,y+20,135,y+15,BLACK_,page,1);
	line_drawing(135,y+40,135,y+15+height*WORDWIDTH,BLACK_,page,1);
	//显示汉字
	int pointer=0;
	int recordx=0;
	int recordy=0;
	char duanju[47]={0};
	int jilu=0;
	int yhuanhang=0;
	int yzhendehuanhang=0;
	int length=strlen(display);
	char temp[3]={0};
	int j,m=0;
	for(i=0;i<length;i+=2)
	{
		temp[0]=display[i];
		temp[1]=display[i+1];
		if(temp[0]>0)
		{
			temp[1]='\0';
			i--;
		}
		if(yhuanhang==23)
		{
			yhuanhang=0;
			recordx=0;
			yzhendehuanhang++;
		}
		else
		{
			yhuanhang++;
		}
		string_drawing(temp,165+recordx,y+32*yzhendehuanhang+15,32,20,12,-8,BLACK_,23,23,page,1);
		m++;
		if(temp[0]>0)
		{
			recordx+=24;
		}
		else
		{
			recordx+=32;
		}
		if(recordx==TEXTWORD)
		{
			recordx=0;
			recordy++;
		}
	}
}

void draw_final1(char *display,int height,int y,int page,int status)
//y是起始点，可以为负数
{
	//图像与对话框
	user_avatar(969,y+35,page);
	int i;
	for(i=-1;i<=1;i++)
	{
		line_drawing(920,y+35,889,y+20,WHITE_,page,1);
		line_drawing(920,y+35,889,y+40,WHITE_,page,1);
		line_drawing(889,y+15,224,y+15,WHITE_,page,1);
	}
	fill_color(142,y+15,889,y+15+height*WORDWIDTH,WHITE_,page,1);
	for(i=21;i<40;i++)
	{
		line_drawing(920,y+35,889,y+i,WHITE_,page,1);
	}
	line_drawing(920,y+35,889,y+20,BLACK_,page,1);
	line_drawing(920,y+35,889,y+40,BLACK_,page,1);
	line_drawing(889,y+15,224,y+15,BLACK_,page,1);
	line_drawing(142,y+15,889,y+15,BLACK_,page,1);
	line_drawing(889,y+15+height*WORDWIDTH,142,y+15+height*WORDWIDTH,BLACK_,page,1);
	line_drawing(142,y+15,142,y+15+height*WORDWIDTH,BLACK_,page,1);
	line_drawing(889,y+15+height*WORDWIDTH,889,y+40,BLACK_,page,1);
	line_drawing(889,y+15,889,y+20,BLACK_,page,1);
	//string_drawing(input[1],0,0,32,20,12,-8,BLACK_,32*23,10000,page,0);//test
	//显示汉字
	int pointer=0;
	int recordx=0;
	int recordy=0;
	char duanju[47]={0};
	int jilu=0;
	int yhuanhang=0;
	int yzhendehuanhang=0;
	int length=strlen(display);
	char temp[3]={0};
	int j,m=0;
	for(i=0;i<length;i+=2)
	{
		temp[0]=display[i];
		temp[1]=display[i+1];
		if(temp[0]>0)
		{
			temp[1]='\0';
			i--;
		}
		if(yhuanhang==23)
		{
			yhuanhang=0;
			recordx=0;
			yzhendehuanhang++;
		}
		else
		{
			yhuanhang++;
		}
		string_drawing(temp,165+recordx,y+32*yzhendehuanhang+15,32,20,12,-8,BLACK_,23,23,page,1);
		m++;
		if(temp[0]>0)
		{
			recordx+=24;
		}
		else
		{
			recordx+=32;
		}
		if(recordx==TEXTWORD)
		{
			recordx=0;
			recordy++;
		}
	}
}
