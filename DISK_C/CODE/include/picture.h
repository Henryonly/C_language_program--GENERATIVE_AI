#ifndef _pic_h
#define _pic_h

//创建每个基本元素的结构体
typedef struct {

//下面是这个图形元素初始的性质
	char name[30];//记录名称

	//num[0]为该基本元素的第一层分类
	//num[1]为该基本元素的第二层分类
	//搜索的时候重点运用这个来搜索
	int num[3];

	//初始固定点的横纵坐标（就是第一笔画的那个起始点）
	int x;
	int y;



//下面是画图的时候根据要求可调的
	//指定后的横纵坐标
	//也就是指定的确切位置
	int x1;
	int y1;

	//int color;//图形颜色

	//判断大小，就是放缩的倍数k
	int size;

	//存储该元素的优先级
	//数值越大优先级越高，越靠后显示
	int level;

} object;




//创建节点，用于搜索生成什么图片
//用于查找时较为方便
typedef struct 
{

	object a;//二级结构体

	int kind;//记录图像具体分类，降低查找的时间复杂度

} node;


void wen_sheng_tu(int color, int a[][5]);

void creat_pic(object p,char name[30],int num[3],int x,int y);
#endif
