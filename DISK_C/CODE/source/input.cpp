
/*
/*文件名称：input 
/*文件目的：实现字符在界面上的输入 
/*时间复杂度：正比于牵扯到的像素个数 
/*空间复杂度：OH(1)
*/

#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<draw.h>
#include<color.h>
#include<page.h>
#include<mouse.h>
#include<dos.h>
#include<time.h>
#include<bios.h>
#include<xiezi.h>
#include<pstat.h>
#include<English.h>
#include<pregi.h>
#include<input.h>
#include<conio.h>

//函数名称：visible_input
//函数目的：实现可视输入

int visible_input(char *str,int x,int y,int limit,int color,int color2,int page)
{
	//clrmous(MouseX,MouseY,page);
	int sum=0;
	char keyboard;
	//line_drawing(x+10,y+6,x+10,y+20,color,page);//光标
	//不画第一个
	while(1)
	{
		keyboard=bioskey(0);
		if(sum<limit)
		{
			fill_color(550,175,550+48*6,175+48,SPRING_GREEN_,page,0);
			if(keyboard!='\n'&&keyboard!='\r'&&keyboard!=' '&&keyboard!=0x1b)//换行、空格、退出
			{
				if(keyboard!='\b')
				{
					if((keyboard>='0'&&keyboard<='9')||(keyboard>='A'&&keyboard<='Z')||(keyboard>='a'&&keyboard<='z'))
					{
						//改变字符串的值
						*(str+sum)=keyboard;
						*(str+sum+1)='\0';
						//改变光标位置
						//fill_color(x+8+sum*18,y+3,x+12+sum*18,y+24,SPRING_GREEN_,page);
						English_text_drawing(x+8+sum*18,y-1,str+sum,color,page,0);
						//outtextxy(x+8+sum*18,y-1,str+sum);
						sum++;
						//line_drawing(x+10+sum*18,y+6,x+10+sum*18,y+20,color,page);
					}
					else
					{
						return ILLEGAL_INPUT;
						//啥也不干
					}
				}
				else if(keyboard=='\b'&&sum>0)
				{
					fill_color(x-6+sum*18,y+3,x+12+sum*18,y+32,DARK_GRAY_,page,0);
					//清除上一个输入的字符
					//fill_color(x+8+sum*18,y+3,x+12+sum*18,y+36,color2,page,0);
					sum--; //改变sum值
					//line_drawing(x+10+sum*18,y+6,x+10+sum*18,y+20,color,page);
					//重置光标
					*(str+sum)='\0';
					//改变字符串
				}
			}
			else
			{
				fill_color(x+8+sum*18,y+3,x+12+sum*18,y+24,color2,page,0);
				break;
			}
		}
		else if(sum>=limit)
		{
			if(keyboard!='\n'&&keyboard!='\r'&&keyboard!=' '&&keyboard!=0x1b)
			{
				string_drawing("最多十五位！",550,175,48,26,15,0,RED_,BIG_NUMBER,BIG_NUMBER,page,0);
				while(1)
				{
					if(kbhit())
					{
						char value=bioskey(0);
						if(value==13)
						{
							return LEGAL_INPUT;
						}
						else if(value=='\b')
						{
							fill_color(x-6+sum*18,y+3,x+12+sum*18,y+54,DARK_GRAY_,page,0);
							//fill_color(x-10+sum*18,y+3,x+7+sum*18,y+24,color,page,0);
							sum--;
							//line_drawing(x+10+sum*18,y+6,x+10+sum*18,y+20,color,page);
							*(str+sum)='\0';
							break;
						}
					}
				}
			}
			else
			{
				if(keyboard=='\b'&&sum>0)
				{
					//跟前面的退格一模一样
					fill_color(x-6+sum*18,y+3,x+12+sum*18,y+32,DARK_GRAY_,page,0);
					//fill_color(x-10+sum*18,y+3,x+7+sum*18,y+24,color,page,0);
					sum--;
					//line_drawing(x+10+sum*18,y+6,x+10+sum*18,y+20,color,page);
					*(str+sum)='\0';
				}
				else
				{
					//fill_color(x+8+sum*18,y+3,x+12+sum*18,y+24,color,page,0);
					break;
				}
			}
		}
	}
	return LEGAL_INPUT;
}

//函数名称：invisible_input
//函数目的：实现函数的不可视输入

int invisible_input(char *str,int x,int y,int limit,int color,int color2,int page)
{
	//clrmous(MouseX,MouseY,page);
	int sum=0;
	char keyboard;
	//line_drawing(x+10,y+6,x+10,y+20,color,page);//光标
	//不画第一个
	while(1)
	{
		keyboard=bioskey(0);
		if(sum<limit)
		{
			fill_color(550,175,550+48*6,175+48,SPRING_GREEN_,page,0);
			if(keyboard!='\n'&&keyboard!='\r'&&keyboard!=' '&&keyboard!=0x1b)//换行、空格、退出
			{
				if(keyboard!='\b')
				{
					if((keyboard>='0'&&keyboard<='9')||(keyboard>='A'&&keyboard<='Z')||(keyboard>='a'&&keyboard<='z'))
					{
						//改变字符串的值
						*(str+sum)=keyboard;
						*(str+sum+1)='\0';
						//改变光标位置
						//fill_color(x+8+sum*18,y+3,x+12+sum*18,y+24,SPRING_GREEN_,page);
						English_text_drawing(x+8+sum*18,y+4,"-",color,page,0);
						//outtextxy(x+8+sum*18,y-1,str+sum);
						sum++;
						//line_drawing(x+10+sum*18,y+6,x+10+sum*18,y+20,color,page);
					}
					else
					{
						return ILLEGAL_INPUT;
						//啥也不干
					}
				}
				else if(keyboard=='\b'&&sum>0)
				{
					fill_color(x-6+sum*18,y+3,x+12+sum*18,y+40,DARK_GRAY_,page,0);
					//清除上一个输入的字符
					//fill_color(x+8+sum*18,y+3,x+12+sum*18,y+36,color2,page,0);
					sum--; //改变sum值
					//line_drawing(x+10+sum*18,y+6,x+10+sum*18,y+20,color,page);
					//重置光标
					*(str+sum)='\0';
					//改变字符串
				}
			}
			else
			{
				fill_color(x+8+sum*18,y+3,x+12+sum*18,y+40,color2,page,0);
				break;
			}
		}
		else if(sum>=limit)
		{
			if(keyboard!='\n'&&keyboard!='\r'&&keyboard!=' '&&keyboard!=0x1b)
			{
				string_drawing("最多十五位！",550,175,48,26,15,0,RED_,BIG_NUMBER,BIG_NUMBER,page,0);
				while(1)
				{
					if(kbhit())
					{
						char value=bioskey(0);
						if(value==13)
						{
							return LEGAL_INPUT;
						}
						else if(value=='\b')
						{
							fill_color(x-6+sum*18,y+3,x+12+sum*18,y+64,DARK_GRAY_,page,0);
							//fill_color(x-10+sum*18,y+3,x+7+sum*18,y+24,color,page,0);
							sum--;
							//line_drawing(x+10+sum*18,y+6,x+10+sum*18,y+20,color,page);
							*(str+sum)='\0';
							break;
						}
					}
				}
			}
			else
			{
				if(keyboard=='\b'&&sum>0)
				{
					//跟前面的退格一模一样
					fill_color(x-6+sum*18,y+3,x+12+sum*18,y+32,DARK_GRAY_,page,0);
					//fill_color(x-10+sum*18,y+3,x+7+sum*18,y+24,color,page,0);
					sum--;
					//line_drawing(x+10+sum*18,y+6,x+10+sum*18,y+20,color,page);
					*(str+sum)='\0';
				}
				else
				{
					//fill_color(x+8+sum*18,y+3,x+12+sum*18,y+24,color,page,0);
					break;
				}
			}
		}
	}
	return LEGAL_INPUT;
}

//函数名称：visible_input1
//函数目的：实现可视输入

int visible_input1(char *str,int x,int y,int limit,int color,int color2,int page)
{
	//clrmous(MouseX,MouseY,page);
	int sum=0;
	char keyboard;
	//line_drawing(x+10,y+6,x+10,y+20,color,page);//光标
	//不画第一个
	while(1)
	{
		keyboard=bioskey(0);
		if(sum<limit)
		{
			fill_color(550,20,550+48*6,68,SPRING_GREEN_,page,0);
			if(keyboard!='\n'&&keyboard!='\r'&&keyboard!=' '&&keyboard!=0x1b)//换行、空格、退出
			{
				if(keyboard!='\b')
				{
					if((keyboard>='0'&&keyboard<='9')||(keyboard>='A'&&keyboard<='Z')||(keyboard>='a'&&keyboard<='z'))
					{
						//改变字符串的值
						*(str+sum)=keyboard;
						*(str+sum+1)='\0';
						//改变光标位置
						//fill_color(x+8+sum*18,y+3,x+12+sum*18,y+24,SPRING_GREEN_,page);
						English_text_drawing(x+8+sum*18,y-1,str+sum,color,page,0);
						//outtextxy(x+8+sum*18,y-1,str+sum);
						sum++;
						//line_drawing(x+10+sum*18,y+6,x+10+sum*18,y+20,color,page);
					}
					else
					{
						return ILLEGAL_INPUT;
						//啥也不干
					}
				}
				else if(keyboard=='\b'&&sum>0)
				{
					fill_color(x-6+sum*18,y+3,x+12+sum*18,y+40,GAINSBORO_,page,0);
					//清除上一个输入的字符
					//fill_color(x+8+sum*18,y+3,x+12+sum*18,y+36,color2,page,0);
					sum--; //改变sum值
					//line_drawing(x+10+sum*18,y+6,x+10+sum*18,y+20,color,page);
					//重置光标
					*(str+sum)='\0';
					//改变字符串
				}
			}
			else
			{
				fill_color(x+8+sum*18,y+3,x+12+sum*18,y+24,color2,page,0);
				break;
			}
		}
		else if(sum>=limit)
		{
			if(keyboard!='\n'&&keyboard!='\r'&&keyboard!=' '&&keyboard!=0x1b)
			{
				string_drawing("最多十五位！",550,20,48,26,15,0,RED_,BIG_NUMBER,BIG_NUMBER,page,0);
				while(1)
				{
					if(kbhit())
					{
						char value=bioskey(0);
						if(value==13)
						{
							return LEGAL_INPUT;
						}
						else if(value=='\b')
						{
							fill_color(x-6+sum*18,y+3,x+12+sum*18,y+44,GAINSBORO_,page,0);
							//fill_color(x-10+sum*18,y+3,x+7+sum*18,y+24,color,page,0);
							sum--;
							//line_drawing(x+10+sum*18,y+6,x+10+sum*18,y+20,color,page);
							*(str+sum)='\0';
							break;
						}
					}
				}
			}
			else
			{
				if(keyboard=='\b'&&sum>0)
				{
					//跟前面的退格一模一样
					fill_color(x-6+sum*18,y+3,x+12+sum*18,y+40,GAINSBORO_,page,0);
					//fill_color(x-10+sum*18,y+3,x+7+sum*18,y+24,color,page,0);
					sum--;
					//line_drawing(x+10+sum*18,y+6,x+10+sum*18,y+20,color,page);
					*(str+sum)='\0';
				}
				else
				{
					//fill_color(x+8+sum*18,y+3,x+12+sum*18,y+24,color,page,0);
					break;
				}
			}
		}
	}
	return LEGAL_INPUT;
}

//函数名称：invisible_input
//函数目的：实现函数的不可视输入

int invisible_input1(char *str,int x,int y,int limit,int color,int color2,int page)
{
	//clrmous(MouseX,MouseY,page);
	int sum=0;
	char keyboard;
	//line_drawing(x+10,y+6,x+10,y+20,color,page);//光标
	//不画第一个
	while(1)
	{
		keyboard=bioskey(0);
		if(sum<limit)
		{
			fill_color(550,20,550+48*6,68,SPRING_GREEN_,page,0);
			
			if(keyboard!='\n'&&keyboard!='\r'&&keyboard!=' '&&keyboard!=0x1b)//换行、空格、退出
			{
				if(keyboard!='\b')
				{
					if((keyboard>='0'&&keyboard<='9')||(keyboard>='A'&&keyboard<='Z')||(keyboard>='a'&&keyboard<='z'))
					{
						//改变字符串的值
						*(str+sum)=keyboard;
						*(str+sum+1)='\0';
						//改变光标位置
						//fill_color(x+8+sum*18,y+3,x+12+sum*18,y+24,SPRING_GREEN_,page);
						English_text_drawing(x+8+sum*18,y+4,"-",color,page,0);
						//outtextxy(x+8+sum*18,y-1,str+sum);
						sum++;
						//line_drawing(x+10+sum*18,y+6,x+10+sum*18,y+20,color,page);
					}
					else
					{
						return ILLEGAL_INPUT;
						//啥也不干
					}
				}
				else if(keyboard=='\b'&&sum>0)
				{
					fill_color(x-6+sum*18,y+3,x+12+sum*18,y+44,GAINSBORO_,page,0);
					//清除上一个输入的字符
					//fill_color(x+8+sum*18,y+3,x+12+sum*18,y+36,color2,page,0);
					sum--; //改变sum值
					//line_drawing(x+10+sum*18,y+6,x+10+sum*18,y+20,color,page);
					//重置光标
					*(str+sum)='\0';
					//改变字符串
				}
			}
			else
			{
				fill_color(x+8+sum*18,y+3,x+12+sum*18,y+44,color2,page,0);
				break;
			}
		}
		else if(sum>=limit)
		{
			if(keyboard!='\n'&&keyboard!='\r'&&keyboard!=' '&&keyboard!=0x1b)
			{
				string_drawing("最多十五位！",550,20,48,26,15,0,RED_,BIG_NUMBER,BIG_NUMBER,page,0);
				while(1)
				{
					if(kbhit())
					{
						char value=bioskey(0);
						if(value==13)
						{
							return LEGAL_INPUT;
						}
						else if(value=='\b')
						{
							fill_color(x-6+sum*18,y+3,x+12+sum*18,y+44,GAINSBORO_,page,0);
							//fill_color(x-10+sum*18,y+3,x+7+sum*18,y+24,color,page,0);
							sum--;
							//line_drawing(x+10+sum*18,y+6,x+10+sum*18,y+20,color,page);
							*(str+sum)='\0';
							break;
						}
					}
				}
			}
			else
			{
				if(keyboard=='\b'&&sum>0)
				{
					//跟前面的退格一模一样
					fill_color(x-6+sum*18,y+3,x+12+sum*18,y+44,GAINSBORO_,page,0);
					//fill_color(x-10+sum*18,y+3,x+7+sum*18,y+24,color,page,0);
					sum--;
					//line_drawing(x+10+sum*18,y+6,x+10+sum*18,y+20,color,page);
					*(str+sum)='\0';
				}
				else
				{
					//fill_color(x+8+sum*18,y+3,x+12+sum*18,y+24,color,page,0);
					break;
				}
			}
		}
	}
	return LEGAL_INPUT;
}
