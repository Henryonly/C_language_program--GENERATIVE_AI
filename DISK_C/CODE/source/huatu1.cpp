
/*
**文件名称：huatu1 
**文件目的：实现文生图的一部分绘画 
**时间复杂度：Bresenham复杂度 
**空间复杂度：Bresenham复杂度 
*/

#include<huatu1.h>
#include<Bezier.h>
#include<draw.h>
#include<stdio.h>
#include<string.h>
#include<alloc.h>
#include<stdlib.h>
#include<color.h>
/*
#define XMAX 300
#define YMAX 300
#define XHALF 150
#define YHALF 150
*/
void background(int x,int y,int page)
{
	fill_color(x,y,x+400,y+400,WHITE_,page,0);
}

void yellow_head(int x,int y,int page)
//黄种人的脸，采用橘色 
{
	ellipse_(x+200,y+200,150,165,TANGERINE_,page,0,0);
}

void brown_head(int x,int y,int page)
//黄种人黝黑的脸，采用褐色 
{
	ellipse_(x+200,y+200,150,165,BROWN_,page,0,0);
}

void black_head(int x,int y,int page)
//黑种人的脸，采用黑色
{
	ellipse_(x+200,y+200,150,165,BLACK_,page,0,0);
}

void white_head(int x,int y,int page)
//白种人的脸或黄种人白净的脸，采用粉扑桃色
{
	ellipse_(x+200,y+200,150,165,PEACH_PUFF_,page,0,0);
}

void black_eye(int x,int y,int page)
{
	ellipse_(x+120,y+60,40,30,WHITE_,page,0,0);
	ellipse_(x+280,y+60,40,30,WHITE_,page,0,0);
	circle_with_drawing(x+120,y+60,20,BLACK_,page,0);
	circle_with_drawing(x+280,y+60,20,BLACK_,page,0);
}

void blue_eye(int x,int y,int page)
{
	ellipse_(x+120,y+60,40,30,WHITE_,page,0,0);
	ellipse_(x+280,y+60,40,30,WHITE_,page,0,0);
	circle_with_drawing(x+120,y+60,20,BLUE_,page,0);
	circle_with_drawing(x+280,y+60,20,BLUE_,page,0);
}

void red_eye(int x,int y,int page)
{
	ellipse_(x+120,y+60,40,30,WHITE_,page,0,0);
	ellipse_(x+280,y+60,40,30,WHITE_,page,0,0);
	circle_with_drawing(x+120,y+60,20,RED_,page,0);
	circle_with_drawing(x+280,y+60,20,RED_,page,0);
}

void nose(int x,int y,int page)
{
	int x0[12];
	int y0[12];
	x0[0]=x+170;
	y0[0]=y+140;
	x0[1]=x+170;
	y0[1]=y+200;
	x0[2]=x+130;
	y0[2]=y+210;
	x0[3]=x+125;
	y0[3]=y+220;
	x0[4]=x+140;
	y0[4]=y+230;
	x0[5]=x+200;
	y0[5]=y+245;
	x0[6]=x+260;
	y0[6]=y+230;
	x0[7]=x+275;
	y0[7]=y+220;
	x0[8]=x+270;
	y0[8]=y+210;
	x0[9]=x+230;
	y0[9]=y+200;
	x0[10]=x+230;
	y0[10]=y+140;
	x0[11]=x+170;
	y0[11]=y+140;
	Bezier(TANGERINE_,12,page,x0,y0,1);
	fill(x+200,y+141,TANGERINE_,page,0);
}

void smile_mouth(int x,int y,int page)
{
	int x0[5];
	int y0[5];
	x0[0]=x+140;
	y0[0]=y+270;
	x0[1]=x+180;
	y0[1]=y+300;
	x0[2]=x+200;
	y0[2]=y+320;
	x0[3]=x+220;
	y0[3]=y+300;
	x0[4]=x+260;
	y0[4]=y+270;
	Bezier(RED_,5,page,x0,y0,1);
}

void laugh_mouth(int x,int y,int page)
{
	int x0[6];
	int y0[6];
	x0[0]=x+140;
	y0[0]=y+270;
	x0[1]=x+180;
	y0[1]=y+320;
	x0[2]=x+200;
	y0[2]=y+340;
	x0[3]=x+220;
	y0[3]=y+320;
	x0[4]=x+260;
	y0[4]=y+270;
	x0[5]=x+140;
	y0[5]=y+270;
	Bezier(RED_,6,page,x0,y0,1);
	fill(x+200,y+271,RED_,page,0);
}

void sad_mouth(int x,int y,int page)
{
	int x0[5];
	int y0[5];
	x0[0]=x+140;
	y0[0]=y+320;
	x0[1]=x+180;
	y0[1]=y+290;
	x0[2]=x+200;
	y0[2]=y+270;
	x0[3]=x+220;
	y0[3]=y+290;
	x0[4]=x+260;
	y0[4]=y+320;
	Bezier(RED_,5,page,x0,y0,1);
}

void boy_hair(int x,int y,int page)
{
	;//待后续调试
}

void girl_hair(int x,int y,int page)
{
	;//待后续调试
}
