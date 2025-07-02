
/*
**文件名称：trans12
**文件目的：实现第1、2步的衔接
**时间复杂度：k1*字数+k2*词数
**空间复杂度：正比于字数
*/

#include<stdio.h>
#include<string.h>
#include<trans12.h>
#include<alloc.h>
#include<stdlib.h>
#include<num.h>

void trans12(char *eventual,char *biaohao)
{
	memset(biaohao,0,sizeof(biaohao));
	int i=0,j=0,m=0;
	char temp[100]={0};
	int count=0;
	//char** str=(char**)malloc(1*sizeof(char*));
	//提示一下，第一维度是第几个词，第二维度是这个词的第几个字符
	/*if(str==NULL)
	{
		printf("内存分配失败了！");
		//delay(2000);
		return;
	}
	for(i=0;i<1;i++)
	{
		str[i]=(char*)malloc(101*sizeof(char));
		if(str[i]==NULL)
		{
			printf("内存分配失败了！");
			return;
		}
	}*/
	char str[1][101]={0};
	/*for(i=0;i<1;i++)
	{
		memset(str[i],0,101);
	}*/
	int ceng[8]={0};
	char nownownow[100]={0};
	for(i=0;i<strlen(eventual);i++)
	{
		if(eventual[i]!='|'&&eventual[i]!=','&&eventual[i]!='?')
		{
			temp[count++]=eventual[i];
		}
		else if(eventual[i]=='|'&&eventual[i+1]=='|')
		{
			strcpy(str[0],temp);
			//strcat(biaohao,"我");
			for(j=0;j<1;j++)
			{
				//strcat(biaohao,"你");
				//PHR* structure=input(str,biaohao);//BC叫我structure，那我就叫它structure
				input2(str,nownownow);
				if(nownownow[0]!='\0')
				{
					strcat(biaohao,nownownow);
				}
				//strcat(biaohao,".");//在最后的最后还有一个"."，比如"1.52.43."这样
			}
		}
		else if(eventual[i]=='|'&&eventual[i+1]!='|')
		{
			for(m=0;m<100;m++)
			{
				temp[m]='\0';
				nownownow[m]='\0';
			}
			for(m=0;m<101;m++)
			{
				str[0][m]='\0';
			}
			count=0;
		}
		else
		{
			memset(temp,0,100);
			count=0;
			strcat(biaohao,",,");
		}
	}
	//if(biaohao[0]=='\0')
	{
		strcpy(str[0],temp);
		
		//for(j=0;j<remark(str)->record;j++)
		for(j=0;j<1;j++)
		{
			//strcat(biaohao,"你");
			//PHR* structure=input(str,biaohao);//BC叫我structure，那我就叫它structure
			input2(str,nownownow);
			if(nownownow[0]!='\0')
			{
				strcat(biaohao,nownownow);
			}
			//strcat(biaohao,".");//在最后的最后还有一个"."，比如"1.52.43."这样
			memset(temp,0,100);
			count=0;
		}
	}
	//strcpy(biaohao,str[0]);
}
//最后的格式就是sentence的标号了
