#ifndef _page_h_
#define _page_h_

enum PAGE
{
	PAGE_TEST,
	PAGE_START,
	PAGE_REGISTER,
	PAGE_CHAT1,
	PAGE_CHAT2,
	PAGE_BEFORE,//返回上个界面 
	PAGE_EXIT,//结束界面 
	PAGE_CLOSE// 关闭界面 
};

void change_page(int *page);

#endif
