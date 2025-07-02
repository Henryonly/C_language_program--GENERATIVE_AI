
/*
**文件名称：queue
**文件目的：实现队列的排序
**时间复杂度：最低
**空间复杂度：最低
*/

#include<stdlib.h>
#include<queue.h>
#include<stce.h>

//函数名称：initqueue
//函数目的：实现队列的初始化

void initqueue(Queue* q)
{
	//就是空的，因为啥都没加
	q->front=q->rear=NULL;
}

//函数名称：push
//函数目的：插入队列

void push(Queue* q,struct TrieNode* node)
{
	//QueueNode* newNode=(QueueNode*)malloc(sizeof(QueueNode));
	QueueNode* newNode=(QueueNode*)malloc(sizeof(QueueNode));
	//QueueNode* newNode=(QueueNode*)malloc(8);
	newNode->data=node;//newNode的数据就是node本身
	newNode->next=NULL;//newNode的下一个就是空的，因为啥都没有
	if(q->rear==NULL)//就是这个表是空的
	{
		q->front=q->rear=newNode;//最初和最后的那个就都得是newNode
	}
	else//要是不是空的
	{
		q->rear->next=newNode;//最后那个下一个是newNode，无限循环
		q->rear=newNode;//最后的那个就是newNode
	}
}

//函数名称：pop
//函数目的：删除首个节点

struct TrieNode* pop(Queue* q)
{
	if(q->front==NULL)
	{
		return NULL;//如果最初的那个都空了，就没什么可以删的了
	}
	QueueNode* temp=q->front;
	struct TrieNode* node=temp->data;
	q->front=q->front->next;
	//直接把q->front往后移，就再也用不到q->front了，然后q->front->next就顺理成章成为了那个front
	if(q->front==NULL)
	{
		q->rear=NULL;//但是要考虑front清完之后要是本身空了，那就把rear设为空吧！
	}
	free(temp);//内存管理问题
	return node;
}

//函数名称：queue_empty
//函数目的：判断队列是否为空

int queue_empty(Queue* q)
{
	if(q->front==NULL)
	{
		return 1;
	} 
	else
	{
		return 0;
	}
} 
