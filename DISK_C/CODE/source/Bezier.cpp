
/*
**文件名称：Bezier
**文件目的：画贝塞尔曲线和一些特殊曲线
**时间复杂度：Bezier最低
**空间复杂度：几乎就是一条曲线像素的内存
*/


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


void Bezier(int color, const unsigned int length, int page, int* x, int* y, int status)
{
	int i, size;
	//length小于0报错弹出
	if (length <= 0)
	{
		string_drawing("贝塞尔曲线点数小于零", 0, 0, 32, 20, 12, -8, BLACK_, 128, 12, page, 0);
		delay(1000);
		return;
	}
	//下面属于处理" ... "的内容
	Vec2* temp = new Vec2[length];//每一个Vec2都如此按length排列定义
	//动态分配内存，用new，一会儿用delete
	for (i = 0; i < length; i++)
	{
		temp[i].x = x[i];
		temp[i].y = y[i];
	}
	//length小于1画点
	if (length == 1)
	{
		if (status == 0)
		{
			point_drawing(temp->x, temp->y, color, page);
		}
		else
		{
			if (temp->y <= 575)
			{
				point_drawing(temp->x, temp->y, color, page);
			}
		}
		return;
	}
	Vec2* parent = NULL, * child = NULL;
	Vec2 lastPoint = temp[0];
	double LineNum;
	for (LineNum = 0; LineNum < 1 + 1.0 / 100; LineNum += 1.0 / 100)
	{
		size = length;//计步
		parent = temp;
		while (size > 1)
		{
			//parent是上一代，child是下一代
			child = new Vec2[size - 1];
			for (i = 0; i < size - 1; i++)
			{
				child[i].x = parent[i].x + (parent[i + 1].x - parent[i].x) * LineNum;//$B(x_{child},x_{parent},\eta)$
				child[i].y = parent[i].y + (parent[i + 1].y - parent[i].y) * LineNum;//$B(y_{child},y_{parent},\eta)$
			}
			if (parent != temp)
			{
				delete[] parent;
			}
			parent = child;
			size--;
		}
		size = length;
		line_drawing(lastPoint.x, lastPoint.y, parent->x, parent->y, color, page, status);
		//char tteemmpp[50];
		//itoa(parent[0].x+10,tteemmpp,10);
		//string_drawing(tteemmpp,0,0,48,26,15,0,RED_,1000000,1000000,page);
		//string_drawing("123",0,0,48,26,15,0,RED_,1000000,1000000,page);
		lastPoint.x = parent->x;//lastPoint更新
		lastPoint.y = parent->y;//lastPoint更新
		delete[] parent;
		child = NULL;
	}
	delete[] temp;
}

void fill(int x, int y, int color, int page, int status)
//仅适用于水平对称凸曲边形，x需要在对称轴上 
{
	int i, j, temp;
	if (status == 0)
	{
		for (i = 0;; i++)
		{
			temp = get_pixel_color(x + i, y, page);
			if (temp == color || x + i == 1024)
			{
				break;
			}
			for (j = 0;; j++)
			{
				temp = get_pixel_color(x + i, y + j, page);
				if (temp == color || y + j == 768)
				{
					break;
				}
				point_drawing(x + i, y + j, color, page);
			}
		}
		for (i = 0;; i++)
		{
			temp = get_pixel_color(x + i, y - 1, page);
			if (temp == color || x + i == 1024)
			{
				break;
			}
			for (j = 0;; j--)
			{
				temp = get_pixel_color(x + i, y + j - 1, page);
				if (temp == color || y + j == 0)
				{
					break;
				}
				point_drawing(x + i, y + j - 1, color, page);
			}
		}
		for (i = 0;; i--)
		{
			temp = get_pixel_color(x + i - 1, y, page);
			if (temp == color || x + i - 1 == 0)
			{
				break;
			}
			for (j = 0;; j++)
			{
				temp = get_pixel_color(x + i - 1, y + j, page);
				if (temp == color || y + j == 768)
				{
					break;
				}
				point_drawing(x + i - 1, y + j, color, page);
			}
		}
		for (i = 0;; i--)
		{
			temp = get_pixel_color(x + i - 1, y - 1, page);
			if (temp == color || x + i - 1 == 0)
			{
				break;
			}
			for (j = 0;; j--)
			{
				temp = get_pixel_color(x + i - 1, y + j - 1, page);
				if (temp == color || y + j == 0)
				{
					break;
				}
				point_drawing(x + i - 1, y + j - 1, color, page);
			}
		}
	}
	else if (status == 1)
	{
		for (i = 0;; i++)
		{
			temp = get_pixel_color(x + i, y, page);
			if (temp == color || x + i == 1024)
			{
				break;
			}
			for (j = 0;; j++)
			{
				temp = get_pixel_color(x + i, y + j, page);
				if (temp == color || y + j == 768)
				{
					break;
				}
				if (y + j <= 575)
				{
					point_drawing(x + i, y + j, color, page);
				}
				else
				{
					goto x2;
				}
			}
		}
	x2:for (i = 0;; i++)
	{
		temp = get_pixel_color(x + i, y - 1, page);
		if (temp == color || x + i == 1024)
		{
			break;
		}
		for (j = 0;; j--)
		{
			temp = get_pixel_color(x + i, y + j - 1, page);
			if (temp == color || y + j == 0)
			{
				break;
			}
			if (y + j - 1 <= 575)
			{
				point_drawing(x + i, y + j - 1, color, page);
			}
			else
			{
				goto x3;
			}
		}
	}
x3:for (i = 0;; i--)
{
	temp = get_pixel_color(x + i - 1, y, page);
	if (temp == color || x + i - 1 == 0)
	{
		break;
	}
	for (j = 0;; j++)
	{
		temp = get_pixel_color(x + i - 1, y + j, page);
		if (temp == color || y + j == 768)
		{
			break;
		}
		if (y + j <= 575)
		{
			point_drawing(x + i - 1, y + j, color, page);
		}
		else
		{
			goto x4;
		}
	}
}
x4:for (i = 0;; i--)
{
	temp = get_pixel_color(x + i - 1, y - 1, page);
	if (temp == color || x + i - 1 == 0)
	{
		break;
	}
	for (j = 0;; j--)
	{
		temp = get_pixel_color(x + i - 1, y + j - 1, page);
		if (temp == color || y + j == 0)
		{
			break;
		}
		if (y + j - 1 <= 575)
		{
			point_drawing(x + i - 1, y + j - 1, color, page);
		}
		else
		{
			goto x5;
		}
	}
}
x5:;
	}
}


void fill_1(int color, int page)
{
	int i, j, temp, m, n;
	int kk;
	int record;
	int shuzu[575]={0};

	int k[100];
	for (i = 135; i <= 925; i++)
	{
		//数组初始化 
		for (n = 0; n < 100; n++)
		{
			k[n] = -1;
		}

		m = 0;
		for (j = 105; j <= 489; j++)
		{
			temp = get_pixel_color(i, j, page);
shuzu[j]=temp;
			if (temp == color)
			{
				k[m++] = j;
			}

			if (get_n(color, k, i, page) == 0)
			{
				continue;
			}
if(temp==color)
{
	record=j;
}

			//shuzu[j]=temp;
			if(j==489)
			{
				for(kk=record;kk<489;kk++)
				{
					point_drawing(i,kk,shuzu[kk],page);
				}
				//for(kk=0;kk<575;kk++)
				//{
				//	shuzu[kk]=0;
				//}
			}

			point_drawing(i, j, color, page);

		}

	}



}


int get_n(int color, int* k, int i, int page)
{
	int y = 0;
	int p = 0, q = 0;
	int judge = 0;//判断边界是否有像素连着 
	int m = 0;
	int special[2] = { 0 };

	static int t;
	static int r;

	int memory = 0;

	while (k[p] != -1)
	{
		judge = 0;//复原 

		if ((k[p + 1] - k[p]) == 1)
		{
			for (q = -3; q <= 3; q++)
			{

				if (get_pixel_color(i + 1, k[p] + q, page) == color)
				{
					special[0] = 1;
				}


				if (get_pixel_color(i - 1, k[p] + q, page) == color)
				{
					special[1] = 1;
				}


			}

			if (k[p + 2] - k[p + 1] != 1)
				//判断是不是左右切线 
			{
				if (special[0] == 1 && special[1] == 1)//不是 
				{
					//复原special数组 
					special[0] = 0;
					special[1] = 0;
					//还需考虑左凸切线的情况 
					y = p + 1;
					while ((k[y] - k[y - 1]) == 1)
					{

						/*
							if(get_pixel_color(i-1,k[y],page)==color&&get_pixel_color(i,k[y]-5,page)==color)
							{
								y--;
							}

							//不是左凸切线
							else
							{
								y=0;
								break;
							}
						*/
						
						if (get_pixel_color(i - 1, k[y], page) == color && get_pixel_color(i - 2, k[y], page) == color)
						{
							;
						}
						else
						{
							memory = 1;
						}
						y--;
					}


					//现在两端一个纵坐标是k[y],另一个纵坐标是k[p+1]
					//现在需要添加左凸切线的特征条件
					//还要借助special数组，不过用途与前面完全不同
					for (q = -1; q <= 1; q++)
					{

						if (get_pixel_color(i + 1, k[y] + q, page) == color)
						{
							special[0] = 1;
						}


						if (get_pixel_color(i + 1, k[p + 1] + q, page) == color)
						{
							special[1] = 1;
						}


					}




					if (special[0] == 1 && special[1] == 1 && memory == 0)//是左凸切线
					{
						m--;
					}
					else//不是左凸切线不做处理
					{
						;
						//清零
						memory = 0;
					}
					//复原special数组 
					special[0] = 0;
					special[1] = 0;



					//1.解决左端尖角的问题 
					if (i == t + 1)//重点改变这里 
					{
						y = p + 1;
						while ((k[y] - k[y - 1]) == 1)
						{
							if (k[y] == r || k[y - 1] == r)
							{
								m--;//当作切线处理 
								//t++;
								break;
							}
							else
							{
								y--;
							}

						}
					}
					
					
					
					
					//2.解决右端尖角的问题
					//借用上面的y 
					y=p+1; 
					while((k[y]-k[y-1])==1)
					{
						if(get_pixel_color(i + 1, k[y], page) == color)
						{
							y=-1;
							break;
						}
						
						y--;
					}
					
					if(y==-1)//满足右端尖角的第一个条件 
					{
						//继续用y,提高y的利用率 
						y=p+1;
						while((k[y]-k[y-1])==1)
						{
							for(q=-10;q<=10;q++)
							{
								if(get_pixel_color(i + 2, k[y]+q, page) == color)
								{
									y=-1;
									break;
								}
							}
							
							y--;
						 	
						} 
						
							//满足右端尖角的第二个条件
							if(y!=-1)
							{
								m--;//当作切线处理 
							}
					}

				}
				else		//是			
				{
					m--;
				}
			}

			judge = 1;//说明该边界是由多个点连城的一条线 
		}


		if (judge == 0)//不是一条线，而是一个点！ 
		{

			//标记尖角型切线（只是做准备） 
			if ((k[p + 1] - k[p]) != 1 && (k[p] - k[p - 1]) != 1)
			{
				for (q = -5; q <= 5; q++)
				{

					if (get_pixel_color(i + 1, k[p] + q, page) == color)
					{
						special[0] = 1;
					}



					if (get_pixel_color(i - 1, k[p] + q, page) == color)
					{
						special[1] = 1;
					}



				}
				if (special[0] == 1 && special[1] == 1)
				{
					;
				}
				else if(special[1] == 0)
				{
					m--;
					t = i;
					r = k[p];
				}
				
				//复原 
				special[1]=0;
				special[0]=0;

			}





			m++;

			//复原special数组 
			special[0] = 0;
			special[1] = 0;
		}
		p++;
	}

	if (m % 2 == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}


void ellipse_(int centerx, int centery, int a, int b, int color, int page, int offsetx, int offsety)
//画椭圆
{
	int x[5];
	int y[5];
	x[0] = centerx;
	y[0] = centery + b;
	x[1] = centerx - a;
	y[1] = centery;
	x[2] = centerx;
	y[2] = centery - b;
	x[3] = centerx + a;
	y[3] = centery;
	x[4] = centerx;
	y[4] = centery + b;
	Bezier(color, 5, page, x, y, 1);
	fill(centerx + offsetx, centery + offsety, color, page, 1);
}
