#ifndef _queue_h_
#define _queue_h_

struct QueueNode
{
	struct TrieNode* data;
	struct QueueNode* next;
};
//链表形式，知道自己是谁，知道下一个是谁 

typedef struct
{
	QueueNode* front;//队列之首 
	QueueNode* rear;//队列之尾 
}Queue;
//链表形式，知道第一个是谁，也知道最后一个是谁 

void initqueue(Queue* q);
void push(Queue* q,struct TrieNode* node);
struct TrieNode* pop(Queue* q);
int queue_empty(Queue* q);

#endif
