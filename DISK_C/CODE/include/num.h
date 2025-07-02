
#ifndef _new_h_
#define _new_h_

/***************
    PHR结构体：用于存储断句后句子中各个成分的标号，以及替代转化之后的标号
***************/
typedef struct
{
    char* str; //存储段句后的这个短语
    int num_arr[15]; //存储用小数点分隔后的标号，如果没有找到num_arr[0]==0
    int num_pre[15]; //存储一旦可以被关键词替代，替代后的词语的标号
    int x; //用于判断该词是否需要关键词替代，x=1则可以被替代，x=0则不能被替代
    int record;//表示num_pre里面存了多少个数字
} PHR;

/***************
    Temp结构体：用于临时存储搜索文件时暂时搜到的标号+短语或词语
***************/
typedef struct
{
    char num[20];
    char phrase[100];
} Temp;

int atoi_f(char* a, int* num_arr, int n, int ci_xing, int* c);
int atoI(const char* str);
int get_num(char* a);
PHR* remark(char** str);
PHR* mark(char** str, int* ceng);
PHR* input(char** word,char* biaohao);
PHR* input2(char word[1][101],char* biaohao);

#endif 
