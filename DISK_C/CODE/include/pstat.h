#ifndef _pstat_h_
#define _pstat_h_

#define BIG_NUMBER 10000

#define LEGAL_INPUT 0
#define ILLEGAL_INPUT 1
#define TEST_INPUT 2 

typedef struct
{
	int num;//用户代号
	char name[15];//用户名
	char password[15];//密码 
	int chattext;//对话对应的文件编号 
}LOGIN;

int page_start(int page);
void mouse_page_start(int page,int* num);
void color_change_mouse(int i,int page);
void string_inspection(int page);
int password_judge(char *str,char *password_record,int *n,int page); 

#endif
