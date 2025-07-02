
/*
** 文件名称：page 
** 文件目的：实现换页 
** 时间复杂度：OH(1) 
** 空间复杂度：OH(1) 
*/

#include<stdio.h>
#include<pstat.h>
#include<pregi.h>
#include<page.h>
#include<dos.h>
#include<mouse.h>
#include<pchat.h>

void change_page(int *page)//后续还有什么参量往里面加就行，要不就默认别的是void就可以 
{
	//clrmous(MouseX,MouseY,*page);
	static int initial_page=PAGE_START;//起始点开始
	int current_page=*page;
	switch(*page)
	{
		case PAGE_TEST:
			*page=page_test();
			break;
		case PAGE_START:
			*page=page_start(PAGE_START);
			break;
		case PAGE_CHAT1:
			*page=page_chat1();
			clean_chat2();
			break;
		case PAGE_CHAT2:
			*page=page_chat2();
			clean_chat1();
			break;
		case PAGE_EXIT:
			*page=page_exit();
			break;
		case PAGE_BEFORE:
			*page=initial_page;
			break;
		case PAGE_REGISTER:
			*page=register_picture(PAGE_REGISTER);
			break;
		default:
			printf("不知换页到那一页去了！");
	}
	initial_page=current_page;
	mouseinit(*page);
}
