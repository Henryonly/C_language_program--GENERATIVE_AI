
/*
**文件名称：logic
**文件目的：实现逻辑链的搭建 
**时间复杂度：\Theta (句子数)
**空间复杂度：\Theta (句子数) 
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<alloc.h>
#include<lasthao.h>
#include<find.h>
#include<logic.h>

//算法的基本思路：引入"虚拟词汇"的概念，用虚拟的词汇进行分析

//函数名称：virtual_word
//函数目的：实现虚拟词汇的架构

int virtual_word(ZHUWEIBIN* arr,ZHUWEIBIN* virtual_arr)
{
	//static ZHUWEIBIN virtual_arr[200];
	int jushu;
	for(jushu=0;;jushu++)
	{
		if(panduanNULL(arr[jushu])==0)
		{
			break;
		}
	}
	jushu=jushu-1;
	int i,j;
	for(i=0;i<jushu-1;i++)
	{
		for(j=0;j<40;j++)
		{
			virtual_arr[i].zhu[j]=arr[i].bin[j];
		}
	}
	//留一个virtual_arr[jushu-1]的主语不变
	return jushu;
}

//函数名称：virtual_logic
//函数目的：实现虚拟词汇逻辑上的架构 

void virtual_logic(ZHUWEIBIN* arr,ZHUWEIBIN* virtual_arr)
{
	int jushu=virtual_word(arr,virtual_arr);
	int i,j;
	for(i=0;i<jushu;i++)
	{
		int pronn=pron(arr[i]);
		if(pronn==1)
		{
			for(j=0;j<40;j++)
			{
				virtual_arr[jushu-1].zhu[j]=arr[i].bin[j];
				virtual_arr[jushu-1].wei[j]=arr[i].wei[j];
			}
		}
		else if(pronn==2)
		{
			for(j=0;j<40;j++)
			{
				virtual_arr[jushu-1].zhu[j]=arr[i].bin[j];
				virtual_arr[jushu-1].wei[j]=arr[i].wei[j];
			}
			//变成被动 
			virtual_arr[jushu-1].wei[2]=1-virtual_arr[jushu-1].wei[2];
		}
	}
	//不能太多的逻辑连续，不然容易造成雪崩效应，2个是极限
	int m;
	for(m=0;m<2;m++)
	{
		for(i=0;i<jushu-1;i++)
		{
			if(zhuweibin_same(virtual_arr[jushu-1].zhu,arr[i].zhu))
			{
				for(j=0;j<40;j++)
				{
					virtual_arr[jushu-1].zhu[j]=arr[i].bin[j];
					virtual_arr[jushu-1].wei[j]=arr[i].wei[j];
					//记录它谓语干了什么，反正virtual_arr的谓语没啥用
				}
			}
			else if(zhuweibin_same(virtual_arr[jushu-1].zhu,arr[i].bin))
			{
				for(j=0;j<40;j++)
				{
					virtual_arr[jushu-1].zhu[j]=arr[i].zhu[j];
					virtual_arr[jushu-1].wei[j]=arr[i].wei[j];
				}
				//变成被动 
				virtual_arr[jushu-1].wei[2]=1-virtual_arr[jushu-1].wei[2];
			}
		}	
	}
}

//函数名称：zhuweibin_same
//函数目的：判断ZHUWEIBIN里的元素是否相同

int zhuweibin_same(int* arr1,int* arr2)
{
	int i,temp=0;
	for(i=0;i<40;i++)
	{
		if(arr1[i]!=arr2[i])
		{
			temp=1;
			break;
		}
	}
	return temp;
	//1不同，0相同 
} 

//函数名称：pron
//函数目的：判断句子当中是否存在指他性代词

int pron(ZHUWEIBIN arr)
{
	if(arr.zhu[6]==5)
	{
		if(arr.zhu[7]==1)
		{
			if(arr.zhu[8]>=3&&arr.zhu[8]<=5)
			{
				return 1;
			}
			else if(arr.zhu[8]>=8&&arr.zhu[8]<=10)
			{
				return 1;
			}
			else if(arr.zhu[8]==16)
			{
				return 1;
			}
		}
	}
	if(arr.bin[6]==5)
	{
		if(arr.bin[7]==1)
		{
			if(arr.bin[8]>=3&&arr.bin[8]<=5)
			{
				return 2;
			}
			else if(arr.bin[8]>=8&&arr.bin[8]<=10)
			{
				return 2;
			}
			else if(arr.bin[8]==16)
			{
				return 2;
			}
		}
	}
	return 0;
	//0是没有,1是作为主语,2是作为宾语 
} 
