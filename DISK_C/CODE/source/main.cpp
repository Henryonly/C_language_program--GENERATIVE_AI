#include<include.h>

int MouseX=0,MouseY=0,MouseS=0,press;
int MouseX_memory,MouseY_memory;
unsigned int far* buffer;
union REGS our_AI_regs;
int mouse_color[15][22];

int main()
{
	int i=PAGE_START;
	int* page=&i;
	start_SVGA();
	//上面是初始化
	//line_drawing(100,100,500,100,WHITE_,*page);//test
	while(1)
	{
		//change_page(page);
		//line_drawing(100,100,500,100,WHITE_,*page);//test
		//mouseinit(*page);
		//newmouse(&MouseX,&MouseY,&MouseS,*page);
		//delay(20);
		page_start(*page);
		if(*page==PAGE_CLOSE)
		{
			break;
		}
		cleardevice();//Turbo C的库函数
	}
	exit(1);//退出界面
	return 0;
}
