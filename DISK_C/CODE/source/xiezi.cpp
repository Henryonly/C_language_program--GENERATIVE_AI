
/*
** 文件名称：xiezi
** 文件目的：用输入法输入汉字 
** 时间复杂度：\Theta(1) 
** 空间复杂度：\Theta(1) 
*/

/*比较好看的情况如下，可以直接用这些数据 
**汉字宽度  ：16 | 24 | 32 | 48
**英文宽度  ： 8 | 15 | 20 | 26
**字体大小  ： 6 |  9 | 12 | 15
**纵坐标偏移：-3 | -6 | -8 |  0
*/ 

#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<draw.h>
#include<math.h>
#include<xiezi.h>
#include<English.h>
#include<string.h>

//函数名称：SVGA_string_length
//函数目的：获得字符串在屏幕上显示的长度

int SVGA_string_length(const char *str,int Chinese_length,int English_length)
{
	int sum=0; 
	while(*str!='\0')
	{
		if(*str<0)//就是汉语的意思
		{
			sum+=Chinese_length;
			str+=2;
		}
		else//别的ASC2码里有的字符 
		{
			sum+=English_length;
			str++;
		}
	}
	return sum;
}

//函数名称：string_drawing
//函数目的：绘制字符串

void string_drawing(const char *str,int x,int y,int Chinese_length,int English_length,int size,int deviation,int color,int width,int length,int page,int status)
{
	FILE *phzk=NULL;
	unsigned char quma,weima;
	unsigned long offset;
	int x0=x,y0=y,temp_y;
	unsigned char mask[8]={0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
	char paths[25]={'\0'};
	char data[288];
	char eng[2]={'\0'};
	sprintf(paths,"C:\\CODE\\write\\HZ%d",Chinese_length);
	phzk=fopen(paths,"rb");
	if(phzk==NULL)
	{
		printf("无法打开汉字库！任意键退出");
		getchar();
		exit(1);
	}
	long square=pow(Chinese_length,2)/8;//8是一个字节包括的比特数
	//int driver=IBM8514,mode=IBM8514HI;
	//char path[]="C:\\BORLANDC\\BGI";
	//initgraph(&driver,&mode,path);
	//setcolor(color);
	//settextjustify(LEFT_TEXT, TOP_TEXT);
	//settextstyle(SMALL_FONT,HORIZ_DIR,size);
	int i,j,calculate;
	if(status==0)
	{
		while(x<XMAX&&(*str)!='\0')
		{
			if(str[0]<0)
			{
				if(width>=Chinese_length&&x+Chinese_length>x0+width)//换行功能
				{
					x=x0;
					y+=Chinese_length;
					if(length>=Chinese_length&&y+Chinese_length>y0+length)
					{
						break;
					}
				} 
				temp_y=y;
				quma=str[0]-0xa0;
				weima=str[1]-0xa0;
				offset=(94*(quma-1)+(weima-1))*square;//汉字在字库文件里的偏移运算
				fseek(phzk,offset,SEEK_SET);
				fread(data,square,1,phzk);
				for(i=0;i<Chinese_length;i++)
				{
					calculate=Chinese_length*i/8;
					for(j=0;j<Chinese_length;j++)
					{
						if(mask[j&7]&data[calculate+(j>>3)])//j%8每8个一循环，j/8每2个一循环
						{
							point_drawing(x+j,temp_y,color,page);
						}
					}
					temp_y++;
				}
				x+=Chinese_length;
				str+=2;
			}
			else
			{
				/*
				int driver=IBM8514,mode=IBM8514HI;
				char path[]="C:\\BORLANDC\\BGI";
				initgraph(&driver,&mode,path);
				setcolor(color);
				settextjustify(LEFT_TEXT, TOP_TEXT);
				settextstyle(SMALL_FONT,HORIZ_DIR,size);		
				if((width>=Chinese_length&&x+English_length>x0+width)||str[0]=='\n')
				{
					x=x0;
					y+=English_length;
					if(length>=Chinese_length&&y+Chinese_length>y0+length)//换行功能
					{
						break;
					}
				}
				else if(str[0]!='\n')
				{
					eng[0]=str[0];
					English_drawing(x,y+deviation,eng,page);
					x+=English_length;
				}
				str++;*/
				English_text_drawing(x,y+deviation,str,color,page,status);
				str+=strlen(str);
			}
			//fclose(phzk);//test
		}
		fclose(phzk);	
	}
	else if(status==1)
	{
		while(x<XMAX&&(*str)!='\0')
		{
			if(str[0]<0)
			{
				if(width>=Chinese_length&&x+Chinese_length>x0+width)//换行功能
				{
					x=x0;
					y+=Chinese_length;
					if(length>=Chinese_length&&y+Chinese_length>y0+length)
					{
						break;
					}
				}
				temp_y=y;
				if(y+32<=575)
				{
					quma=str[0]-0xa0;
					weima=str[1]-0xa0;
					offset=(94*(quma-1)+(weima-1))*square;//汉字在字库文件里的偏移运算
					fseek(phzk,offset,SEEK_SET);
					fread(data,square,1,phzk);
					for(i=0;i<Chinese_length;i++)
					{
						calculate=Chinese_length*i/8;
						for(j=0;j<Chinese_length;j++)
						{
							if(mask[j&7]&data[calculate+(j>>3)])//j%8每8个一循环，j/8每2个一循环
							{
								point_drawing(x+j,temp_y,color,page);
							}
						}
						temp_y++;
					}
					x+=Chinese_length;
					str+=2;				
				}
				else
				{
					break;
				}
			}
			else
			{
				/*
				int driver=IBM8514,mode=IBM8514HI;
				char path[]="C:\\BORLANDC\\BGI";
				initgraph(&driver,&mode,path);
				setcolor(color);
				settextjustify(LEFT_TEXT, TOP_TEXT);
				settextstyle(SMALL_FONT,HORIZ_DIR,size);		
				if((width>=Chinese_length&&x+English_length>x0+width)||str[0]=='\n')
				{
					x=x0;
					y+=English_length;
					if(length>=Chinese_length&&y+Chinese_length>y0+length)//换行功能 
					{
						break;
					}
				}
				else if(str[0]!='\n')
				{
					eng[0]=str[0];
					English_drawing(x,y+deviation,eng,page);
					x+=English_length;
				}
				str++;*/
				English_text_drawing(x,y+deviation,str,color,page,status);
				str+=strlen(str);
			}
			//fclose(phzk);//test
		}
		fclose(phzk);
	}
} 
