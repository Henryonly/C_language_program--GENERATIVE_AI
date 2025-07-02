
/*
** 函数名称：SVGA基本逻辑 
** 函数目的：实现SVGA 
** 时间复杂度：公认的最快速度
** 空间复杂度：最小空间 
*/

#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<xiezi.h>
#include<mouse.h>
#include<draw.h>

//函数名称：start_SVGA
//函数目的：初始化65536色SVGA显示
void start_SVGA()
{
	union REGS our_AI_regs;
	our_AI_regs.x.ax=0x4f02;//设置显示模式
	our_AI_regs.x.bx=0x117;//设置成65536色SVGA显示
	int86(0x10,&our_AI_regs,&our_AI_regs);
	//软中断出现SVGA特权功能，寄存器存储值
	if(our_AI_regs.x.ax!=0x004f)
	{
		printf("初始化失败！错误：0x%x！任意键退出",our_AI_regs.x.ax);
		getchar();
		exit(1);
	}
}

//函数名称：examine_start_SVGA
//函数目的：判断是否初始化成功

int examine_start_SVGA()
{
	union REGS our_AI_regs;
	our_AI_regs.x.ax=0x4f03;//读当前显示模式
	int86(0x10,&our_AI_regs,&our_AI_regs);//软中断
	if(our_AI_regs.x.ax!=0x004f)
	{
		printf("初始化失败！错误：0x%x！任意键退出",our_AI_regs.x.ax);
		getchar();
		exit(1);
	}
	return 1;
}

//函数名称：pageturn
//函数目的：换页问题,换到第page页 
/*
void pageturn(register int page)//用寄存器，加快换页速度 
{
	static int flag = 0;  // 0 代表 false，1 代表 true,BC不支持布尔值 
	union REGS our_AI_regs;
	static int whether=0;//这个不能变
	static int initial_page;//这个也需要保持不变 
	our_AI_regs.x.ax=0x4f05;//控制内存页区域切换
	our_AI_regs.x.bx=0;//寄存器设初值为0
	if(whether==0)
	{
		our_AI_regs.x.dx=page;//换页 
		int86(0x10,&our_AI_regs,&our_AI_regs);//软中断 
		flag=1;
		initial_page=page;//数据维护 
	} 
	else if(page!=initial_page)
	{
		our_AI_regs.x.dx=page;
		int86(0x10,&our_AI_regs,&our_AI_regs);
		initial_page=page;
	}
}
*/

void pageturn(register int page)
{
	union REGS our_AI_regs;
	our_AI_regs.x.ax=0x4f05;
	our_AI_regs.x.bx=0;
	our_AI_regs.x.dx=page;
	int86(0x10,&our_AI_regs,&our_AI_regs);
}

//函数名称：point_drawing
//函数目的：由点出线，确定画点函数

int point_drawing(int x,int y,int color,int page)
{
	unsigned int far *const buffer= (unsigned int far*)0xa0000000L;
	//指针首地址，可读不可写可执行 
	if(x<0||x>XMAX||y<0||y>YMAX)//自己要先定义一下！！！ 
	{
		return 0;
	}
	//如果点不在屏幕里面，就不用再算了
	unsigned long long int delta=((unsigned long long int)y<<10)+x;
	//计算像素偏移量delta，1024=2<<10,一个y就是这么多像素
	int i=y/32;
	int eventual_page=(page>>16)+i;//2^16个点换页一次
	pageturn(eventual_page); 
	buffer[delta]=color; 
}

//函数名称：line_drawing
//函数目的：用Bresenham算法画线
int line_drawing(int x1,int y1,int x2,int y2,int color,int page,int status)
{
	int delta_x=abs(x2-x1);
	int delta_y=abs(y2-y1);//计算差值
	int delta_x2,delta_y2;
	int sign_x=0,sign_y=0;
	int i,min,max;
	int error,flag;
	if(status==0)
	{
		if(x1<x2)
		{
			sign_x=1;
		}
		else if(x1>x2)
		{
			sign_x=-1;
		}
		else//竖直线段直接画
		{
			if(y1>y2)
			{
				max=y1;
				min=y2;
			}
			else
			{
				max=y2;
				min=y1;
			}
			for(i=min;i<=max;i++)
			{
				point_drawing(x1,i,color,page);
			}
			//return 0;
		}
		if(y1<y2)
		{
			sign_y=1;
		} 
		else if(y1>y2)
		{
			sign_y=-1;
		}
		else//水平直线直接画 
		{
			if(x1<x2)
			{
				max=x2;
				min=x1;
			} 
			else
			{
				max=x1;
				min=x2;
			}
			for(i=min;i<=max;i++)
			{
				point_drawing(i,y1,color,page);
			}
		}
		point_drawing(x1,y1,color,page);
		delta_x2=delta_x<<1;
		delta_y2=delta_y<<1;//方便后续2倍运算
		if(delta_x>=delta_y)//横坐标适合作为基准
		{
			error=delta_y2-delta_x;//确定误差项
			flag=delta_y2-delta_x2;
			while(delta_x--)//两边x在靠近，要是到0就不执行了
			{
				if(error<=0)
				{
					error+=delta_y2;
				}
				else
				{
					y1+=sign_y;
					error+=flag;
				}
				//平均每走delta_x2-delta_y2/delta_y2+1 个格就画一个点,那个+1就是else里面没有执行可是x还动了一步
				x1+=sign_x;
				point_drawing(x1,y1,color,page);
			}
		}
		else
		{
			error=delta_x2-delta_y;
			flag=delta_x2-delta_y2;
			while(delta_y--)
			{
				if(error<=0)
				{
					error+=delta_x2;
				}
				else
				{
					x1+=sign_x;
					error+=flag;
				}
				y1+=sign_y;
				point_drawing(x1,y1,color,page);
			}
		}		
	}
	else if(status==1)
	{
		if(x1<x2)
		{
			sign_x=1;
		}
		else if(x1>x2)
		{
			sign_x=-1;
		}
		else//竖直线段直接画
		{
			if(y1>y2)
			{
				max=y1;
				min=y2;
			}
			else
			{
				max=y2;
				min=y1;
			}
			for(i=min;i<=max;i++)
			{
				if(i<=565)
				{
					point_drawing(x1,i,color,page);	
				}
			}
			//return 0;
		}
		if(y1<y2)
		{
			sign_y=1;
		} 
		else if(y1>y2)
		{
			sign_y=-1;
		}
		else//水平直线直接画 
		{
			if(x1<x2)
			{
				max=x2;
				min=x1;
			} 
			else
			{
				max=x1;
				min=x2;
			}
			for(i=min;i<=max;i++)
			{
				if(y1<=565)
				{
					point_drawing(i,y1,color,page);	
				}
			}
		}
		if(y1<=565)
		{
			point_drawing(x1,y1,color,page);
		}
		delta_x2=delta_x<<1;
		delta_y2=delta_y<<1;//方便后续2倍运算
		if(delta_x>=delta_y)//横坐标适合作为基准
		{
			error=delta_y2-delta_x;//确定误差项
			flag=delta_y2-delta_x2;
			while(delta_x--)//两边x在靠近，要是到0就不执行了
			{
				if(error<=0)
				{
					error+=delta_y2;
				}
				else
				{
					y1+=sign_y;
					error+=flag;
				}
				//平均每走delta_x2-delta_y2/delta_y2+1 个格就画一个点,那个+1就是else里面没有执行可是x还动了一步
				x1+=sign_x;
				if(y1<=565)
				{
					point_drawing(x1,y1,color,page);
				}
			}
		}
		else
		{
			error=delta_x2-delta_y;
			flag=delta_x2-delta_y2;
			while(delta_y--)
			{
				if(error<=0)
				{
					error+=delta_x2;
				}
				else
				{
					x1+=sign_x;
					error+=flag;
				}
				y1+=sign_y;
				if(y1<=565)
				{
					point_drawing(x1,y1,color,page);	
				}
			}
		}
	}
}

//函数名称：circle_without_drawing
//函数目的：Bresenham算法画圆圈

void circle_without_drawing(int x,int y,int r,int color,int page)
{
	if(r<=0)
	{
		printf("半径为负！任意键退出");
		getchar();
		exit(1);
	}
	int i=r;
	int error=3-2*r;//误差项
	int j;
	for(j=0;j<=i;j++)
	{
		point_drawing(x+j,y+i,color,page);
		point_drawing(x+j,y-i,color,page);
		point_drawing(x-j,y+i,color,page);
		point_drawing(x-j,y-i,color,page);
		point_drawing(x+i,y+j,color,page);
		point_drawing(x+i,y-j,color,page);
		point_drawing(x-i,y+j,color,page);
		point_drawing(x-i,y-j,color,page);
		//圆的对称性画8个对称的点
		if(error<0)
		{
			error+=4*j+6;
		}
		else
		{
			error+=4*(j-i)+10;
			i--;
		}
	}
}

//函数名称：circle_with_drawing
//函数目的：画实心圆

void circle_with_drawing(int x,int y,int r,int color,int page,int status)
{
	int setx=0,sety=r,dx=3,d2=2-2*r,d=1-r;
	if(r<=0)
	{
		printf("半径为负！任意键退出");
		getchar();
		exit(1);
	}
	while(setx<=sety)
	{
		line_drawing(x-setx,y-sety,x+setx,y-sety,color,page,status);
		line_drawing(x-sety,y-setx,x+sety,y-setx,color,page,status);
		line_drawing(x-sety,y+setx,x+sety,y+setx,color,page,status);
		line_drawing(x-setx,y+sety,x+setx,y+sety,color,page,status);
		if(d<0)
		{
			d+=dx;
			dx+=2;
		}
		else
		{
			sety--;
			d+=(dx+d2);
			dx+=2;
			d2+=2;
		}
		setx++;
	}
}

//函数名称：fill_color
//函数目的：实现颜色填充矩形画面

void fill_color(int x1,int y1,int x2,int y2,int color,int page,int status)
{
	int i,j;
	if(status==0)
	{
		for(i=x1;i<=x2;i++)
		{
			for(j=y1;j<=y2;j++)
			{
				point_drawing(i,j,color,page);
			}
		}	
	}
	else
	{
		if(y1<=575&&y2>=575)
		{
			for(i=x1;i<=x2;i++)
			{
				for(j=y1;j<=575;j++)
				{
					point_drawing(i,j,color,page);
				}
			}
		}
		if(y1<=575&&y2<=575)
		{
			for(i=x1;i<=x2;i++)
			{
				for(j=y1;j<=y2;j++)
				{
					point_drawing(i,j,color,page);
				}
			}	
		}
	}
}

//函数名称：exit_SVGA
//函数目的：关闭SVGA

void exit_SVGA()
{
	union REGS our_AI_regs;
	our_AI_regs.h.ah=0;
	our_AI_regs.h.al=0x03;
	int86(0x10,&our_AI_regs,&our_AI_regs);
}
