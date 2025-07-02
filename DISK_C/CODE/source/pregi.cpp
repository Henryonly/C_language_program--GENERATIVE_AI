
/*
/*文件名称：pregi
/*文件目的：实现注册界面 
/*时间复杂度：\Theta(1) 
/*空间复杂度：\Theta(1024*768) 
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
#include<ptext.h>
#include<pregi.h>
#include<input.h>
#include<pchat.h>
 
extern int MouseX,MouseY,MouseS,press;
extern void* buffer;
extern union REGS our_AI_regs;
extern int MouseX_memory,MouseY_memory;

//函数名称：register_picture
//函数目的：实现注册界面

int register_picture(int page)
{
	//mread(&MouseX,&MouseY,&MouseS);
	//clrmous(MouseX,MouseY,page);
	delay(20);
	//save_bk_mou(MouseX,MouseY);
	//鼠标部分
	fill_color(0,0,1024,768,SPRING_GREEN_,page,0);
	
	robot_avatar(55,35+80,page);
	int i;
	for(i=-1;i<=1;i++)
	{
		line_drawing(104,35+80,135,15+80,WHITE_,page,1);
		line_drawing(104,35+80,135,40+80,WHITE_,page,1);
		line_drawing(135,15+80,475,15+80,WHITE_,page,1);
	}
	fill_color(135,15+80,475,15+80+WORDWIDTH,WHITE_,page,1);
	for(i=16;i<40;i++)
	{
		line_drawing(104,35+80,135,i+80,WHITE_,page,1);
	}
	//else if(status==NONFILL_STATUS)
	//{
	//	fill(120,1,WHITE_,page,1);
	//	;
	//}
	line_drawing(104,35+80,135,15+80,BLACK_,page,1);
	line_drawing(104,35+80,135,40+80,BLACK_,page,1);
	line_drawing(135,15+80,400,15+80,BLACK_,page,1);
	line_drawing(135,15+80,475,15+80,BLACK_,page,1);
	line_drawing(475,15+80,475,15+80+WORDWIDTH,BLACK_,page,1);
	line_drawing(475,15+80+WORDWIDTH,135,15+80+WORDWIDTH,BLACK_,page,1);
	line_drawing(135,20+80,135,15+80,BLACK_,page,1);
	line_drawing(135,40+80,135,15+80+WORDWIDTH,BLACK_,page,1);
	string_drawing("请注册！",140,13+80,32,20,12,-8,RED_,32*23,10000,page,1);

	string_drawing("用户名：",196,290,32,20,12,-8,RED_,BIG_NUMBER,BIG_NUMBER,page,0);
	string_drawing("密码：",228,410,32,20,12,-8,RED_,BIG_NUMBER,BIG_NUMBER,page,0);
	string_drawing("再次确认密码：",100,530,32,20,12,-8,RED_,BIG_NUMBER,BIG_NUMBER,page,0);
	fill_color(350,260,900,360,TROPICAL_ORANGE_,page,0);
	fill_color(350,380,900,480,TROPICAL_ORANGE_,page,0);
	fill_color(350,500,900,600,TROPICAL_ORANGE_,page,0);
	fill_color(300,650,600,720,TROPICAL_ORANGE_,page,0);
	fill_color(964,0,1024,60,RED_,page,0);
	for(i=-2;i<=2;i++)
	{
		line_drawing(968+i,8,1020+i,52,WHITE_,page,0);
		line_drawing(1020+i,8,968+i,52,WHITE_,page,0);
	}
	string_drawing("注册",400,670,32,20,12,-8,WHITE_,BIG_NUMBER,BIG_NUMBER,page,0);
	//以上是画图部分
	int status=0;
	int position=0;
	char name_input[16]={'\0'};
	char password_input[16]={'\0'};
	char password_again_input[16]={'\0'};
	int error1;
	int error2;
	int error3;
	int error4;
	mouseinit(page);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press,page);
		//mread(&MouseX,&MouseY,&press);
		memory_mouse(MouseX,MouseY,page);
		//drawmous(MouseX,MouseY,page);
		mouse_drawing(MouseX,MouseY,page);
		delay(20);
		truly_clean_mouse(MouseX,MouseY,page);
		//退出
		if(MouseX>=964&&MouseX<=1024&&MouseY>=0&&MouseY<=60)
		{
			if(mouse_press(964,0,1024,60)==2)
			{
				//if(status==0)
				{
					MouseS=1;
					status=4;
				}
				continue;
			}
			else if(mouse_press(964,0,1024,60)==1)
			{
				register_color_change_mouse(4,page);
				status=4;
				MouseS=0;
				page=PAGE_START;
				change_page(&page);
			}
		}
		//用户名
		else if(MouseX>=350&&MouseX<=900&&MouseY>=260&&MouseY<=360)
		{
			if(mouse_press(350,260,900,360)==2)
			{
				MouseS=2;
				if(status==0&&position==0)
				{
					status=1;
				}
				continue;
			}
			else if(mouse_press(350,260,900,360)==1)
			{
				status=1;
				MouseS=0;
				register_color_change_mouse(1,page);
				name_input[0]='\0';
				visible_input(name_input,350,260,15,BLACK_,DARK_GRAY_,page);
				error1=check_law(name_input,page);
				continue;
			}
		}
		//密码
		else if(MouseX>=350&&MouseX<=900&&MouseY>=380&&MouseY<=480)
		{
			if(mouse_press(350,380,900,480)==2)
			{
				MouseS=2;
				if(status==0&&position==0)
				{
					status=2;
				}
				continue;
			}
			else if(mouse_press(350,380,900,480)==1)
			{
				status=2;
				MouseS=0;
				register_color_change_mouse(2,page);
				password_input[0]='\0';
				invisible_input(password_input,350,380,15,BLACK_,DARK_GRAY_,page);
				error2=check_law(password_input,page);
				error4=check_password1(password_again_input,password_input,page);
				continue;
			}
		}
		//再次输入密码
		else if(MouseX>=350&&MouseX<=900&&MouseY>=500&&MouseY<=600)
		{
			if(mouse_press(350,500,900,600)==2)
			{
				MouseS=2;
				if(status==0&&position==0)
				{
					status=3;
				}
				continue;
			}
			else if(mouse_press(350,500,900,600)==1)
			{
				status=3;
				MouseS=0;
				register_color_change_mouse(3,page);
				password_again_input[0]='\0';
				invisible_input(password_again_input,350,500,15,BLACK_,DARK_GRAY_,page);
				error3=check_law(password_again_input,page);
				error4=check_password(password_again_input,password_input,page);
				continue;
			}
		}
		//注册区域
		else if(MouseX>=300&&MouseX<=650&&MouseY>=600&&MouseY<=720)
		{
			if(mouse_press(300,650,600,720)==2)
			{
				MouseS=1;
				if(status==0&&position==0)
				{
					status=1;
				}
				continue;
			}
			else if(mouse_press(300,650,600,720)==1)
			{
				MouseS=0;
				register_color_change_mouse(5,page);
				if(error1==0&&error2==0&&error3==0&&error4==0)
				{
					text_register(name_input,password_input);
					page=PAGE_START;
					fill_color(600,55,600+48*5,55+48,SPRING_GREEN_,page,0);
					string_drawing("注册成功！",600,55,48,26,15,0,RED_,BIG_NUMBER,BIG_NUMBER,page,0);
					change_page(&page);
				}
				else
				{
					string_drawing("注册有误！",600,55,48,26,15,0,RED_,BIG_NUMBER,BIG_NUMBER,page,0);
					fill_color(350,260,900,360,TROPICAL_ORANGE_,page,0);
					fill_color(350,380,900,480,TROPICAL_ORANGE_,page,0);
					fill_color(350,500,900,600,TROPICAL_ORANGE_,page,0);
					fill_color(300,650,600,720,TROPICAL_ORANGE_,page,0);
					string_drawing("注册",400,670,32,20,12,-8,WHITE_,BIG_NUMBER,BIG_NUMBER,page,0);
				}
				continue;
			}
		}
		//其他区域
		else
		{
			/*
			switch(status)
			{
				case 1:
					back_register_color(1,page);
					break;
				case 2:
					back_register_color(2,page);
					break;
				case 3:
					back_register_color(3,page);
					break;
			}
			*/
			MouseS=0;
			status=4;
		} 
	}
	return PAGE_REGISTER;
}

//函数名称：register_color_change_mouse
//函数目的：实现注册页的鼠标改图标颜色

void register_color_change_mouse(int i,int page)
{
	//clrmous(MouseX,MouseY,page);
	delay(10);
	switch(i)
	{
		//用户名
		case 1:
			fill_color(350,260,900,360,DARK_GRAY_,page,0);
			break;
		//密码
		case 2:
			fill_color(350,380,900,480,DARK_GRAY_,page,0);
			break;
		//再次确认密码
		case 3:
			fill_color(350,500,900,600,DARK_GRAY_,page,0);
			break;
		//退出
		case 4:
			fill_color(964,0,1024,60,DARK_GRAY_,page,0);
			break;
		//注册
		case 5:
			fill_color(300,650,600,720,DARK_GRAY_,page,0);
			break;
	}
}

//函数名称：check_law
//函数目的：判断用户名和密码是否符合命名规范

int check_law(char *input,int page)
{
	int length=strlen(input);
	int i;
	if(length>=15)
	{
		string_drawing("最多十五位！",550,175,48,26,15,0,RED_,BIG_NUMBER,BIG_NUMBER,page,0);
		return 1;
	}
	for(i=0;i<length;i++)
	{
		if((input[i]>='0'&&input[i]<='9')||(input[i]>='a'&&input[i]<='z')||(input[i]>='A'&&input[i]<='Z'))
		{
			//无事发生
		}
		else
		{
			string_drawing("只能输入字母和数字！",100,75,48,26,15,0,RED_,BIG_NUMBER,BIG_NUMBER,page,0);
			input[i]='\0';
			return 1;
		}
	}
	return 0;
	//0是没问题，1是有问题
}

//函数名称：check_password
//函数目的：检查密码是否再次输入与首次输入一致

int check_password(char *arr1,char *arr2,int page)
{
	if(strcmp(arr1,arr2)==0)
	{
		return 0;
	}
	else
	{
		string_drawing("两次密码不一致！",550,115,48,26,15,0,RED_,BIG_NUMBER,BIG_NUMBER,page,0);
		return 1;
	}
	//同样地，0是没问题，1是有问题
}

//函数名称：check_password1
//函数目的：检查密码是否再次输入与首次输入一致

int check_password1(char *arr1,char *arr2,int page)
{
	if(strcmp(arr1,arr2)==0)
	{
		return 0;
	}
	else
	{
		//string_drawing("两次密码不一致！",550,115,48,26,15,0,RED_,BIG_NUMBER,BIG_NUMBER,page,0);
		return 1;
	}
	//同样地，0是没问题，1是有问题 
}

//函数名称：text_register
//函数目的：把信息写入文件

void text_register(char *arr1,char *arr2)
{
	LOGIN* log;
	FILE* fp;
	if((fp=fopen("C:\\CODE\\data\\password.dat","rb+"))==NULL)
	{
		printf("密码数据库无法打开！任意键退出");
		getchar();
		exit(1);
	}
	if((log=(LOGIN*)malloc(sizeof(LOGIN)))==NULL)//分配空间
	{
		printf("密码内存分配不足！任意键退出");
		getchar();
		exit(1);
	}
	fseek(fp,0,SEEK_END);
	int sum=ftell(fp)/sizeof(LOGIN);
	log->num=sum+1;
	strcpy(log->name,arr1);
	strcpy(log->password,arr2);
	log->chattext=0;
	fseek(fp,0,SEEK_END);
	fwrite(log,sizeof(LOGIN),1,fp);
	if(log!=NULL)
	{
		free(log);
		log=NULL;
	}
	if(fclose(fp)!=0)
	{
		printf("密码数据库文件关不掉！任意键退出");
		getchar();
		exit(1);
	}
}

//函数名称：back_register_color
//函数目的：将变化颜色的注册按键复原
void back_register_color(int i,int page)
{
	switch(i)
	{
		case 1:
			fill_color(350,260,900,360,TROPICAL_ORANGE_,page,0);
			break;
		case 2:
			fill_color(350,380,900,480,TROPICAL_ORANGE_,page,0);
			break;
		case 3:
			fill_color(350,500,900,600,TROPICAL_ORANGE_,page,0);
			break;
	}
} 

int page_test()
{
	return PAGE_TEST;
}
int page_chat2()
{
	return PAGE_CHAT2;
}
int page_exit()
{
	return PAGE_EXIT;
}
void clean_chat1()
{
	
}
void clean_chat2()
{
	
}
