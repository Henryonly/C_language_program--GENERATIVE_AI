#ifndef _stceAC_h_
#define _stceAC_h_

#define PAST 0
#define NOW 1
#define FUTURE 2

typedef enum
{
	TENSE_PAST,
	//完成 
	TENSE_PRESENT,//我们默认为这个时态
	//在做 
	TENSE_FUTURE,
	//要去做
	TENSE_NONE
}Tense;

struct TrieNode
{
	struct TrieNode* children[53];//子节点
	//话说一个TrieNode是有128个儿子，NULL的不行，不空才是好儿子(bushi
	struct TrieNode* failure;//失败指针
	//这个指向失败后该去往的地方
	Tense tense;//当前时态
	//时态问题，这个需要次次记录次次调整
	int end;//关键词结束标志
	//结束标志，这个是末尾才变的
};

struct TrieNode* create_node();
void insert_keyword(struct TrieNode* root,const char* word,Tense tense);
Tense detect_tense(struct TrieNode* root,char* input);
struct TrieNode* init_automation(); 
struct TrieNode* init_automation_2();
Tense tense(char* input,TrieNode* tree);
Tense already(char* input,TrieNode* tree);
int beidong(char* str);
void recursiveFunction(TrieNode* node);
 
#endif
