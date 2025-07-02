
/*
**文件名称：lasthao
**文件目的：实现最终的标号完成
**时间复杂度：k1*词数+k2*字数
**空间复杂度：相对较为复杂，但为最低
*/

#include<stdio.h>
#include<lasthao.h>
#include<string.h>
#include<stdlib.h>
#include<alloc.h>
#include<stce.h>
#include<dos.h>
#include<num.h>
#include<trans12.h>

/*AC自动机 
ZHUWEIBIN* lasthao(char* biaohao,char* input)
{
	//基本思路：生成抽象的主谓宾的格式，进行算法封装
	ZHUWEIBIN* record=(ZHUWEIBIN*)malloc(5*sizeof(struct ZHUWEIBIN*));//留够5个逻辑关系
	//开堆区空间的声明最后的存储变量
	char* temp=(char*)malloc(500);

	//建立AC自动机的字典树，到后面执行效率会高些
	TrieNode* tree1=(TrieNode*)malloc(600);
	tree1=init_automation();
	TrieNode* tree2=(TrieNode*)malloc(600);
	tree2=init_automation_2();
	
	int counting=0;
	int i;
	Tense tense_,already_;
	int beibei;
	int dijiju=0;
	for(i=0;input[i]!='\0';i++)
	//直到到input的\0为止
	//冷知识：空格的ASC2码是32，回车是13，EOF是26，都不是0
	{
		if(input[i]==','||input[i]=='?')
		{
			counting=0;
			if(temp[0]!='\0')
			{
				//执行记录！往那个结构体里面储存
				//先判断相关的情况
				tense_=tense(temp,tree1);
				already_=already(temp,tree2);
				beibei=beidong(temp);
				yijuhua(temp,tense_,already_,beibei,record+(dijiju++));//小心bug
			}
			memset(temp,0,sizeof(temp));
		}
		else
		{
			temp[counting++]=input[i];
		}
	}
	
	if(input[strlen(input)-1]!=','&&input[strlen(input)-1]!='?')
	{
		tense_=tense(temp,tree1);
		already_=already(temp,tree2);
		beibei=beidong(temp);
		//yijuhua(temp,tense_,already_,beibei,record+(dijiju++));//小心bug
	}
	
	free(tree1);
	free(tree2);
	return record;
}*/

void lasthao(char far* input,char far* fencihou,ZHUWEIBIN* record,char* biaohao)
{
	if(strlen(biaohao)==0)
	{
		return;
	}
	if(strcmp(biaohao,"2.1.96.")==0)
	{
		return;
	}
	//基本思路：生成抽象的主谓宾的格式，进行算法封装
	//ZHUWEIBIN* record=(ZHUWEIBIN*)malloc(10*sizeof(struct ZHUWEIBIN*));//留够5个逻辑关系
	//开堆区空间的声明最后的存储变量
	char* temp=(char*)malloc(300);
	int i=0;
	memset(temp,0,100);
	
	int j;
	for(i=0;i<10;i++)
	{
		for(j=0;j<30;j++)
		{
			record[i].zhu[j]=0;
			record[i].wei[j]=0;
			record[i].bin[j]=0;
		}
	}

	//建立AC自动机的字典树，到后面执行效率会高些
	//TrieNode* tree1=(TrieNode*)malloc(600);
	//tree1=init_automation();
	//TrieNode* tree2=(TrieNode*)malloc(600);
	//tree2=init_automation_2();
	
	int counting=0;
	Tense tense_,already_;
	int beibei;
	int dijiju=0;
	for(i=0;input[i]!='\0';i++)
	//直到到input的\0为止
	//冷知识：空格的ASC2码是32，回车是13，EOF是26，都不是0
	{
		if(input[i]==','||input[i]=='?')
		{
			counting=0;
			if(temp[0]!='\0')
			{
				//执行记录！往那个结构体里面储存
				//先判断相关的情况
				tense_=tense(temp);
				already_=already(temp);
				beibei=beidong(temp);
				yijuhua(temp,tense_,already_,beibei,record+(dijiju++));//小心bug
			}
			memset(temp,0,300);
		}
		else
		{
			temp[counting++]=input[i];
		}
	}

	if(input[strlen(input)-1]!=','&&input[strlen(input)-1]!='?')
	{
		tense_=tense(temp);
		already_=already(temp);
		beibei=beidong(temp);
		yijuhua(fencihou,tense_,already_,beibei,record+(dijiju++));//小心bug
	}
	//strcpy(biaohao,fencihou);
	
	//strcpy(biaohao,"牛啊");//test
	
	free(temp);
	//free(tree1);
	//free(tree2);
	return;
}

void yijuhua(char* temp,Tense tense_,Tense already_,int beibei,ZHUWEIBIN* zhuweibin)
{
	//先给二维数组动态分配内存吧！！！
	//char** arr=(char**)malloc(10*sizeof(char*));
	//提示一下，第一维度是第几个词，第二维度是这个词的第几个字符
	int i,j;
	char chayuan[7][50]={{0}};
	/*if(arr==NULL)
	{
		printf("内存分配失败了！");
		delay(2000);
		return;
	}
	for(i=0;i<10;i++)
	{
		arr[i]=(char*)malloc(50*sizeof(char));
		if(arr[i]==NULL)
		{
			printf("内存分配失败了！");
			return;
		}
	}*/
	char arr[7][50]={{0}};
	/*for(i=0;i<10;i++)
	{
		memset(arr[i],0,50);
	}*/
	//然后干正事
	int counting_2=0;
	int count_1=0;
	
	//for(i=0;temp[i]!='\0';i++)
	//就是说扫描的temp必须是有东西的
	{
		for(j=0;temp[j]!='\0';j++)
		//就是说扫描的过程中，那个字符不是终止字符
		{
			if(temp[j]=='|')
			{
				counting_2=0;
				if(arr[count_1][0]!='\0')
				{
					count_1++;
				}
			}
			else
			{
				arr[count_1][counting_2]=temp[j];
				counting_2++;
			}
		}
	}
	
	
	//zhuweibin有且仅有一个，phr可是可以有很多的
	//根据分出来的词，进行这句话的分析~
	//先在PHR里面进行
	
	//PHR* phr=(PHR*)malloc(10*sizeof(PHR));
	//for(i=0;i<10;i++)
	//{
	//	phr->str=(char*)malloc(50);
	//}
	//phr=remark(arr);
	
	//for(i=0;i<7;i++)
	for(i=0;i<7;i++)
	{
		trans12(arr[i],chayuan[i]);
	}
	
	int qinghua[50]={0};
	int huake[50]={0};
	int wuda[50]={0};
	char temppp[50]={0};
	int counttt=0;
	int mxz=0;
	for(i=0;i<7;i++)
	{
		for(j=0;j<50;j++)
		{
			if(chayuan[i][j]=='.'||chayuan[i][j]=='\0')
			{
				qinghua[i]=atoi(temppp);
				memset(temppp,0,50);
				break;
			}
			else
			{
				temppp[j]=chayuan[i][j];
			}
		}
	}
	for(i=0;i<7;i++)
	{
		for(j=0;j<50;j++)
		{
			if(chayuan[i][j]=='\0')
			{
				huake[i]=atoi(temppp);
				memset(temppp,0,50);
				break;
			}
			else if(chayuan[i][j]=='.'&&mxz==0)
			{
				mxz=1;
				counttt=j;
			}
			else if(chayuan[i][j]=='.'&&mxz==1)
			{
				huake[i]=atoi(temppp);
				memset(temppp,0,50);
				break;
			}
			else if(mxz==0)
			{
				;
			}
			else
			{
				temppp[j-counttt-1]=chayuan[i][j];
			}
		}
		mxz=0;
	}
	for(i=0;i<7;i++)
	{
		for(j=0;j<50;j++)
		{
			if(chayuan[i][j]=='\0')
			{
				wuda[i]=atoi(temppp);
				memset(temppp,0,50);
				break;
			}
			else if(chayuan[i][j]=='.'&&mxz==0)
			{
				mxz=1;
			}
			else if(chayuan[i][j]=='.'&&mxz==1)
			{
				mxz=2;
				counttt=j;
			}
			else if(chayuan[i][j]=='.'&&mxz==2)
			{
				wuda[i]=atoi(temppp);
				memset(temppp,0,50);
				break;
			}
			else if(mxz==0||mxz==1)
			{
				;
			}
			else
			{
				temppp[j-counttt-1]=chayuan[i][j];
			}
		}
		mxz=0;
	}
	
	//没错，phr是数组！是数组！是数组！
	//再往真实的结构里面腾东西
	switch(tense_)
	{
		case TENSE_PAST:
			zhuweibin->wei[0]=TENSE_PAST;
			break;
		case TENSE_PRESENT:
			zhuweibin->wei[0]=TENSE_PRESENT;
			break;
		case TENSE_FUTURE:
			zhuweibin->wei[0]=TENSE_FUTURE;
			break;
	}
	switch(already_)
	{
		case TENSE_PAST:
			zhuweibin->wei[1]=TENSE_PAST;//完成
			break;
		case TENSE_PRESENT:
			zhuweibin->wei[1]=TENSE_PRESENT;//在做
			break;
		case TENSE_FUTURE:
			zhuweibin->wei[1]=TENSE_FUTURE;//要去做
			break;
	}
	switch(beibei)
	{
		case 0:
			zhuweibin->wei[2]=0;//被动句
			break;
		case 1:
			zhuweibin->wei[2]=1;//主动句
			break;
	}
	switch(yiwen_gantan(temp))
	{
		case 0:
			zhuweibin->bin[2]=0;
			break;
		case 1:
			zhuweibin->bin[2]=1;
			break;
		case 2:
			zhuweibin->bin[2]=2;
			break;
		case 3:
			zhuweibin->bin[3]=3;
			break;
	}
	int num_he=0;
	int num_huo=0;
	int zhubin=ZHUYU;
	int fucishu=0;
	int adj=0;
	for(i=0;arr[i][0]!='\0';i++)
	{
		if(strcmp(arr[i],"和")==0||strcmp(arr[i],"还有")==0||strstr(arr[i],"及")!=NULL)
		{
			num_he++;
			if(zhubin==BINYU)
			//就是它之前是主语的意思
			{
				zhubin=ZHUYU;
			}
			else
			{
				zhubin=BINYU;
			}
			continue;
		}
		else if(strcmp(arr[i],"或")==0||strcmp(arr[i],"或者")==0||strcmp(arr[i],"抑或")==0)
		{
			num_he++;
			if(zhubin==BINYU)
			{
				zhubin=ZHUYU;
			}
			else
			{
				zhubin=BINYU;
			}
			continue;
		}
		else if(qinghua[i]==1||qinghua[i]==5)
		{
			//目前的标号方式是架构在三层标号法之上的
			if(zhubin==ZHUYU)
			{
				//遇到和，或，那么形容词大搬家
				if(strcmp(arr[i-1],"和")==0||strcmp(arr[i-1],"还有")==0||strstr(arr[i-1],"及")!=NULL)
				{
					for(j=3*adj-1;j>=0;j--)
					{
						zhuweibin->zhu[10+num_he*3+num_huo*3+3+j]=zhuweibin->zhu[10+num_he*3+num_huo*3+j];
					}
				}
				//这个就正常考虑了
				zhuweibin->zhu[7+num_he*3+num_huo*3]=qinghua[i];
				zhuweibin->zhu[8+num_he*3+num_huo*3]=huake[i];
				zhuweibin->zhu[9+num_he*3+num_huo*3]=wuda[i];
				zhubin=BINYU;
				/*
				解封需要把3都转成6嗷！前后也要变
				zhuweibin->zhu[10+num_he*3+num_huo*3]=phr->num_pre[0];
				zhuweibin->zhu[11+num_he*3+num_huo*3]=phr->num_pre[1];
				zhuweibin->zhu[12+num_he*3+num_huo*3]=phr->num_pre[2];
				//警钟敲烂！这个是新的表示！！！
				*/
			}
			else if(zhubin==BINYU)
			{
				//形容词搬家
				for(j=3*adj-1;j>=0;j--)
				{
					zhuweibin->zhu[10+num_he*3+num_huo*3+3+j]=zhuweibin->zhu[10+num_he*3+num_huo*3+j];
				}
				//正常考虑
				zhuweibin->bin[7+num_he*3+num_huo*3]=qinghua[i];
				zhuweibin->bin[8+num_he*3+num_huo*3]=huake[i];
				zhuweibin->bin[9+num_he*3+num_huo*3]=wuda[i];
				zhubin=ZHUYU;
				/*
				解封需要把3都转成6嗷！前后也要变
				zhuweibin->bin[10+num_he*3+num_huo*3]=phr->num_pre[0];
				zhuweibin->bin[11+num_he*3+num_huo*3]=phr->num_pre[1];
				zhuweibin->bin[12+num_he*3+num_huo*3]=phr->num_pre[2];
				//警钟敲烂！这个是新的表示！！！
				*/
			}
		}
		else if(qinghua[i]==2)
		//动词
		{
			zhuweibin->wei[6]=0;
			//到后面还有更改的机会
			zhuweibin->wei[7]=qinghua[i];
			zhuweibin->wei[8]=huake[i];
			zhuweibin->wei[9]=wuda[i];
			num_he=0;
			num_huo=0;
			//在动词这里为宾语做准备
		}
		else if(qinghua[i]==4)
		//副词
		{
			fucishu++;
			zhuweibin->wei[3]=1;
			zhuweibin->wei[4]=fucishu;
			zhuweibin->wei[10+(fucishu-1)*3]=qinghua[i];
			zhuweibin->wei[11+(fucishu-1)*3]=huake[i];
			zhuweibin->wei[12+(fucishu-1)*3]=wuda[i];
		}
		else if(qinghua[i]==3)
		//形容词
		{
			if(qinghua[i+1]==1||qinghua[i+1]==5||
			strcmp("而",arr[i])==0||strcmp("而且",arr[i])==0||
			strstr(arr[i],"或")!=NULL||strcmp("要么",arr[i])==0)
			//就是说下一个是主语或者宾语，或者是一些特殊的可能出现的词语
			{
				if(zhubin==ZHUYU)
				{
					zhuweibin->zhu[8+adj*3]=qinghua[i];
					zhuweibin->zhu[8+adj*3]=huake[i];
					zhuweibin->zhu[8+adj*3]=wuda[i];
					adj++;
				}
				else
				{
					zhuweibin->bin[8+adj*3]=qinghua[i];
					zhuweibin->bin[8+adj*3]=huake[i];
					zhuweibin->bin[8+adj*3]=wuda[i];
				}
			}
			else
			{
				if(zhubin==BINYU)
				{
					zhuweibin->wei[6]=1;
					zhuweibin->wei[7]=qinghua[i];
					zhuweibin->wei[8]=huake[i];
					zhuweibin->wei[9]=wuda[i];
					//没错，就是要把没啥用的原动词覆盖掉
				}
			}
		} 
	}
	//最后别忘了释放内存~
	/*for(i=0;i<10;i++)
	{
		free(arr[i]);
	}
	free(arr);*/
}

int yiwen_gantan(char* str)
{
	//1是是什么，2是感叹，0是正常语气，3是怎么做
	if(strstr(str,"什么")!=NULL)
	return 1;
	if(strstr(str,"啥")!=NULL)
	return 1;
	if(strstr(str,"怎")!=NULL)
	return 3;
	if(strstr(str,"咋")!=NULL)
	return 3;
	if(strstr(str,"如何")!=NULL)
	return 3;
	if(strstr(str,"啊")!=NULL)
	return 2;
	if(strstr(str,"呢")!=NULL)
	return 2;
	if(strstr(str,"能干什么")!=NULL)
	return 3;
	if(strstr(str,"能干啥")!=NULL)
	return 3;
	if(strstr(str,"呀")!=NULL)
	return 2;
	if(strstr(str,"解释")!=NULL)
	return 1;
	if(strstr(str,"原因")!=NULL)
	return 1;
	if(strstr(str,"方案")!=NULL)
	return 3;
	if(strstr(str,"方法")!=NULL)
	return 3;
	if(strstr(str,"建议")!=NULL)
	return 3;
	if(strstr(str,"哪")!=NULL)
	return 1;
	if(strstr(str,"办法")!=NULL)
	return 3;
	if(strstr(str,"做法")!=NULL)
	return 3;
	return 0;
}
