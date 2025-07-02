
/*
**文件名称：stceAC
**文件目的：时态等相关内容的判断
**空间复杂度：句子标号长度
**时间复杂度：\Theta(1)
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<alloc.h>
#include<queue.h>
#include<stce.h>

//用AC自动机，速度真的快（别是WA自动机就行bushi）

//函数名称：create_node
//函数目的：创建新节点
//最终效果：
// 1 -> 2
//基本思路：
// 对于新节点，先上时态，end标注还不是末尾（待标注为末尾），
// failure失败指针有，但是没有添加，然后返回这个节点本身就行了
struct TrieNode* create_node()
{
	TrieNode* node=(TrieNode*)malloc(sizeof(TrieNode));
	
	//test!!!
	
	for(int i=0;i<53;i++)
	{
		node->children[i]=(TrieNode*)malloc(sizeof(TrieNode));
	}
	node->failure=(TrieNode*)malloc(sizeof(TrieNode));
	node->tense=TENSE_NONE;
	node->end=0;
	node->failure=NULL;
	return node;
}

//函数名称：insert_keyword
//函数目的：插入关键词，维护优先级
//最终效果： 
// 1-> 2 -> 3
// |   L---> 4 -> 5
// |
// L---> 6 -> 7
//基本思路：
// 1.词汇从前往后遍历，所以要写循环；
// 2.node往下降一级，如果没有这个"字母"对应的children就女娲造人
// 3.语法继承上一辈的情况：现在的这个孩子的语法大于biaohao语法的enum值（甚至是最大的none）
// 4.考虑end，这回必是末尾

void insert_keyword(struct TrieNode* root,const char* word,Tense tense)
{
	TrieNode* node=root;
	int i;
	unsigned char temp;
	for(i=0;word[i]!='\0';i++)
	{
		temp=word[i];
		if(node->children[temp]==NULL)
		{
			node->children[temp]=create_node();
		}
		node=node->children[temp];//往儿子方向走
	}
	if(tense<node->tense||node->tense==TENSE_NONE)
	{
		node->tense=tense;//继承父辈的语法
	}
	node->end=0;//是最后了，因为没有nil
}

//函数名称：build_failure_links
//函数目的：构建失败指针
//最终效果： 
// @
//  1<-> 2 <-> 3
//  |    L<---> 4 -> 5	_______\   2
//  |                          /
//  L<---> 6 <-> 7   _______\
//基本思路：                /  1
// 1.创建队列
// 2.根节点的失败指针指向自己，根节点但凡有个孩子（循环遍历去看，要求不空），failure指向根节点，放入队列,队列就是"待办事项",而且是BFS的层次遍历
// 3.只要队列不空，就接着查找，构建一个这样的循环，然后标记一下队列最前面的是谁，把它移掉（一次性，用完就扔），因为不用再搞第二遍了嗷！┗|｀O′|┛
// 4.找curr的子节点，循环去找，但凡有个孩子就定义它是child，再定义当前节点的失败指针，然后一路往上追溯，fail是fail的失败指针，层层往上追溯 
// 追溯到什么时候为止呢？直到fail是root（去root即可）或者fail的children有它对应的第几个字母（那就去那个对应字母了）
// 5.要是fail有children[i]，那就去fail的children就行了，不然就去root
// 6.孩子的时态就是孩子失败指针的时态
// 7.子节点入队，以期这次BFS完了马上就搞下一个BFS

void build_failure_links(struct TrieNode* root)
{
	Queue* q;
	q;//test
	q->front;//test
	q->rear;//test
	//创建队列方便后续BFS
	root->failure=root;
	//根节点的失败指针指向自己
	int i;
	struct TrieNode* child;
	struct TrieNode* fail;
	for(i=0;i<70;i++)
	{
		if(root->children[i]!=NULL)
		{
			root->children[i]->failure=root;//有第一层子节点的话，指向根节点
			push(q,root->children[i]);//把第一层子节点放队列里面
			//节点放在队列尾部
		}
	}
	
	
	//划掉下面的循环可以跑！
	
	 
	//第一层子节点的失败指针指向根节点
	//BFS
	
	while(queue_empty(q)==0)
	//判断队列是否为空，队列不为空时循环
	{
		//队列的队首节点是curr
		struct TrieNode* curr=pop(q);
		//获取队首节点（不删版本）并移除队列队首节点
		for(i=0;i<128;i++)
		{
			if(curr->children[i]!=NULL)
			{
				//子节点
				child=curr->children[i];
				//当前节点的失败指针
				fail=curr->failure;
				while(fail!=root&&fail->children[i]==NULL)
				//意思就是把这一根扫描满了
				{
					fail=fail->failure;
					//fail是fail的失败指针
				}
				//要是还有孩子，那就让fail往下走，不然就回root
				child->failure=fail->children[i]?fail->children[i]:root;
				if(child->failure->tense!=child->tense)
				{
					child->tense=child->failure->tense;
				}
				//子节点，入队！等候总司令对队列的进一步命令！
				//push(q,child);
			}
		}
	}
}

//函数名称：detect_tense 
//函数目的：自动机搜索
//基本思路：
// 1.现把时态搞成NONE
// 2.从上往下依次遍历，如果不是root或者children没有找到，就往下走，找failure
// 3.如果下面还有的话，curr就是children了，往下再走一步
// 4.然后定义一个once，once是用来看时态的，通过改result搞时态，只要once不回到root，就一直执行下面的这个程序
// 5.如果once是末端点了（end等于1），那么时态是过去时的返回过去时，要不然result就是once的时态（要求是result就是个NONE或者once的时态enum比result小即优先级更大）
// 6.无论如何，once变成once对应的failure，也就是往错误指针走，继续执行，直到走到root为止
// 7.返回once对应的时态

Tense detect_tense(struct TrieNode* root,char* biaohao)
{
	Tense result=TENSE_NONE;//先搞到默认状态再说
	struct TrieNode* curr=root;
	int i;
	unsigned char temp;
	for(i=0;biaohao[i]!='\0';i++)
	{
		temp=biaohao[i];
		while(curr!=root&&curr->children[temp]==NULL)
		//就是说是不是根节点的结尾
		{
			curr=curr->failure;
		}
		if(curr->children!=NULL)
		{
			curr=curr->children[temp];
		}
		struct TrieNode* once=curr;
		while(once!=root)
		{
			if(once->end==1)
			{
				if(once->tense==TENSE_PAST)
				{
					return TENSE_PAST;
				}
				if(once->tense<result||result==TENSE_NONE)
				{
					result=once->tense;
				}
			}
			once=once->failure;
		}
	}
	return (result!=TENSE_NONE)?result:TENSE_PRESENT;
}

//函数名称：init_automation
//函数目的：Tense数据的初始化

struct TrieNode* init_automation()
{
	struct TrieNode* root=create_node();
	
	//我们直接把这个给放在代码段而非放在文件，方便形成一个树进行查找
	insert_keyword(root,"曾",TENSE_PAST);
	insert_keyword(root,"已",TENSE_PAST);
	insert_keyword(root,"了",TENSE_PAST);
	insert_keyword(root,"过",TENSE_PAST);
	insert_keyword(root,"刚",TENSE_PAST);
	insert_keyword(root,"才",TENSE_PAST);
	insert_keyword(root,"先",TENSE_PAST);
	insert_keyword(root,"先前",TENSE_PAST);
	insert_keyword(root,"之前",TENSE_PAST);
	insert_keyword(root,"从前",TENSE_PAST);
	insert_keyword(root,"过去",TENSE_PAST);
	insert_keyword(root,"上回",TENSE_PAST);
	insert_keyword(root,"上次",TENSE_PAST);
	insert_keyword(root,"那时",TENSE_PAST);
	insert_keyword(root,"当时",TENSE_PAST);
	insert_keyword(root,"昨天",TENSE_PAST);
	insert_keyword(root,"前天",TENSE_PAST);
	insert_keyword(root,"去年",TENSE_PAST);
	insert_keyword(root,"前年",TENSE_PAST);
	insert_keyword(root,"上周",TENSE_PAST);
	insert_keyword(root,"当年",TENSE_PAST);
	insert_keyword(root,"以前",TENSE_PAST);
	insert_keyword(root,"之前",TENSE_PAST);
	insert_keyword(root,"那年",TENSE_PAST);
	insert_keyword(root,"那天",TENSE_PAST);
	insert_keyword(root,"当时",TENSE_PAST);
	
	insert_keyword(root,"未来",TENSE_FUTURE);
	insert_keyword(root,"将来",TENSE_FUTURE);
	insert_keyword(root,"明天",TENSE_FUTURE);
	insert_keyword(root,"后天",TENSE_FUTURE);
	insert_keyword(root,"明年",TENSE_FUTURE);
	insert_keyword(root,"下周",TENSE_FUTURE);
	insert_keyword(root,"往后",TENSE_FUTURE);
	insert_keyword(root,"今后",TENSE_FUTURE);
	insert_keyword(root,"迟早",TENSE_FUTURE);
	insert_keyword(root,"早晚",TENSE_FUTURE);
	insert_keyword(root,"远期",TENSE_FUTURE);
	insert_keyword(root,"远景",TENSE_FUTURE);
	insert_keyword(root,"此后",TENSE_FUTURE);
	insert_keyword(root,"往后",TENSE_FUTURE);
	insert_keyword(root,"以后",TENSE_FUTURE);
	insert_keyword(root,"展望",TENSE_FUTURE);
	insert_keyword(root,"畅想",TENSE_FUTURE);
	insert_keyword(root,"之后",TENSE_FUTURE);
	
	insert_keyword(root,"现在",TENSE_PRESENT);
	insert_keyword(root,"此刻",TENSE_PRESENT);
	insert_keyword(root,"此时",TENSE_PRESENT);
	insert_keyword(root,"当下",TENSE_PRESENT);
	insert_keyword(root,"目前",TENSE_PRESENT);
	insert_keyword(root,"即刻",TENSE_PRESENT);
	insert_keyword(root,"随即",TENSE_PRESENT);
	insert_keyword(root,"此刻",TENSE_PRESENT);
	insert_keyword(root,"今",TENSE_PRESENT);	
	
	build_failure_links(root);
	return root;
}

//函数名称：init_automation_2
//函数目的：实现已然未然判断的初始化

struct TrieNode* init_automation_2()
//完成就是TENSE_PAST
//在做就是TENSE_PRESENT
//要去做就是TENSE_FUTURE
{
	struct TrieNode* root2=create_node();
	
	insert_keyword(root2,"了",TENSE_PAST);
	insert_keyword(root2,"过",TENSE_PAST);
	insert_keyword(root2,"已经",TENSE_PAST);
	insert_keyword(root2,"刚刚",TENSE_PAST);
	insert_keyword(root2,"来着",TENSE_PAST);
	insert_keyword(root2,"方",TENSE_PAST);
	insert_keyword(root2,"毕",TENSE_PAST);
	insert_keyword(root2,"已",TENSE_PAST);
	insert_keyword(root2,"曾",TENSE_PAST);
	insert_keyword(root2,"刚",TENSE_PAST);
	insert_keyword(root2,"才",TENSE_PAST);
	insert_keyword(root2,"都",TENSE_PAST);
	insert_keyword(root2,"罢",TENSE_PAST);
	insert_keyword(root2,"完",TENSE_PAST);
	insert_keyword(root2,"成",TENSE_PAST);
	insert_keyword(root2,"终于",TENSE_PAST);
	insert_keyword(root2,"终究",TENSE_PAST);
	insert_keyword(root2,"算是",TENSE_PAST);
	insert_keyword(root2,"讫",TENSE_PAST);
	insert_keyword(root2,"之后",TENSE_PAST);
	insert_keyword(root2,"以来",TENSE_PAST);
	insert_keyword(root2,"就",TENSE_PAST);
	insert_keyword(root2,"便",TENSE_PAST);
	
	insert_keyword(root2,"马上",TENSE_FUTURE);
	insert_keyword(root2,"立刻",TENSE_FUTURE);
	insert_keyword(root2,"即将",TENSE_FUTURE);
	insert_keyword(root2,"就要",TENSE_FUTURE);
	insert_keyword(root2,"准备",TENSE_FUTURE);
	insert_keyword(root2,"打算",TENSE_FUTURE);
	insert_keyword(root2,"计划",TENSE_FUTURE);
	insert_keyword(root2,"正欲",TENSE_FUTURE);
	insert_keyword(root2,"要",TENSE_FUTURE);
	insert_keyword(root2,"想",TENSE_FUTURE);
	insert_keyword(root2,"去",TENSE_FUTURE);
	insert_keyword(root2,"眼看",TENSE_FUTURE);
	insert_keyword(root2,"行将",TENSE_FUTURE);
	insert_keyword(root2,"决意",TENSE_FUTURE);
	insert_keyword(root2,"立意",TENSE_FUTURE);
	insert_keyword(root2,"着手",TENSE_FUTURE);
	insert_keyword(root2,"动手",TENSE_FUTURE);
	insert_keyword(root2,"开手",TENSE_FUTURE);
	insert_keyword(root2,"欲",TENSE_FUTURE);
	insert_keyword(root2,"拟",TENSE_FUTURE);	
	
	insert_keyword(root2,"着",TENSE_PRESENT);
	insert_keyword(root2,"呢",TENSE_PRESENT);
	insert_keyword(root2,"正",TENSE_PRESENT);
	insert_keyword(root2,"现在",TENSE_PRESENT);
	insert_keyword(root2,"当下",TENSE_PRESENT);
	insert_keyword(root2,"眼下",TENSE_PRESENT);
	insert_keyword(root2,"之际",TENSE_PRESENT);
	insert_keyword(root2,"这会",TENSE_PRESENT);
	insert_keyword(root2,"这时",TENSE_PRESENT);
	
	build_failure_links(root2);
	return root2;
}

//警告！以下函数只能一个句子一个句子的分析！！！ 

//函数名称：tense
//函数目的：判断时态
Tense tense(char* biaohao,TrieNode* tree)
{
	/*
	TrieNode* tree=(TrieNode*)malloc(1000);
	tree=init_automation();
	*///这一块可以在执行函数里面添加，会快的多
	Tense tense_;
	tense_=detect_tense(tree,biaohao);
	return tense_;
}

//函数名称：already
//函数目的：判断已然与未然
Tense already(char* biaohao,TrieNode* tree)
{
	/*
	TrieNode* tree=(TrieNode*)malloc(1000);
	tree=init_automation_2();
	*///这一块也可以在那个执行函数里面添加
	Tense tense_;
	tense_=detect_tense(tree,biaohao);
	return tense_;
} 

//函数名称：beidong
//函数目的：判断是不是被动句

int beidong(char* str)
{
	if(strstr(str,"被")!=NULL)
	{
		if(strstr(str,"被子")==NULL)
		{
			return 1;
			//1对应被动句
		}
	}
	return 0;
	//0对应主动句
}

void recursiveFunction(TrieNode* node)
{
    if (node == NULL) 
	{  
	// 空节点作为一种可能的退出条件
        return;
    }
    // 其他递归逻辑
    // 例如遍历子节点
    for (int i = 0; i < 256; i++) 
	{
        if (node->children[i] != NULL) 
		{
            recursiveFunction(node->children[i]);
        }
    }
}
