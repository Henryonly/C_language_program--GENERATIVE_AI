#ifndef _lasthao_h_
#define _lasthao_h_

#include"stce.h"

#define ZHUYU 0
#define BINYU 1

struct ZHUWEIBIN
{
	int zhu[30];
	int wei[30];
	int bin[30];
};

void lasthao(char far* input,char far* fencihou,ZHUWEIBIN* record,char* biaohao);
void yijuhua(char* temp,Tense,Tense,int beibei,ZHUWEIBIN* zhuweibin);
int yiwen_gantan(char* str);

#endif 
