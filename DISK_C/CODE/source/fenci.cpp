
/*
** 函数名称：interrupt
** 函数目的：通过对互信息值的确定，实现断句。
** 时间复杂度：OH(字数)
** 空间复杂度：OH(字数)+6766
*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<page.h>
#include<xiezi.h>
#include<color.h>

#define MI_VALUE 0.0000000000001
#define ROW_LENGTH 87921
#define EACH_LENGTH 13
#define INPUT_SIZE 10000
#define GB2312_NUMBER 6763

double mi_value(int i,int j)
{
	//打开文件 
	FILE *fp;
	if((fp=fopen("C:\\CODE\\data\\tn","rt"))==NULL)
	{
		printf("GB2312互信息值数据库无法打开！任意键退出");
		getchar();
		return -1;
	}
	//找到位置，读取
	long long int calculate;
	calculate=i*ROW_LENGTH+j*EACH_LENGTH+1;
	//calculate=87919;
	fseek(fp,calculate,0);
	//记录字符串，然后变成小数
	char record[12];
	for(i=0;i<12;i++)
	{
		record[i]=fgetc(fp);
	}
	record[12]='\0';
	double result;
	result=atof(record);
	fclose(fp);
	return result;
}


int fenci(char* input,char* eventual)
{
	char arr[GB2312_NUMBER][2];
	FILE *fp;
	int i;
	char zi5[5]={0};
	if((fp=fopen("C:\\CODE\\data\\GB2312","r"))==NULL)
	{
		printf("GB2312数据库无法打开！任意键退出\n");
		getchar();
		return -1;
	}
	for(i=0;i<GB2312_NUMBER;i++)
	{
		for(int j=0;j<2;j++)
		{
			arr[i][j]=fgetc(fp);
		}
	}
	//int *count=(int*)malloc(INPUT_SIZE/2);
	int count[INPUT_SIZE/2];
	int counting=0;
	int flag=0;
	char temp[5];
	for(i=0;i<strlen(input);i+=2)
	{
		if(input[i]>0)//就是不是汉字的意思
		{
			count[counting++]=0;//0是标志句子分开
			//i--;
		}
		else
		{
			for(int j=0;j<GB2312_NUMBER;j++)
			{
				if(input[i]==arr[j][0])
				{
					if(input[i+1]==arr[j][1])
					{
						count[counting++]=j;//最后储存的从0开始储存
					}
				}
			}
		}
		flag++;
		//每执行一遍函数，count多记一个，flag加1,flag的数值等于count数组元素的个数
	}
	for(i=0;i<counting;i++)
	{
		printf("%d",count[i]);
		printf("\n");
	}
	for(i=0;i<strlen(input);i+=2)
	{
		if(input[i]>0)//就是不是汉字的意思
		{
			count[counting++]=0;//0是标志句子分开
			//i--;
		}
		else
		{
			for(int j=0;j<GB2312_NUMBER;j++)
			{
				if(input[i]==arr[j][0])
				{
					if(input[i+1]==arr[j][1])
					{
						count[counting++]=j;//最后储存的从0开始储存
					}
				}
			}
		}
		flag++;
		//每执行一遍函数，count多记一个，flag加1,flag的数值等于count数组元素的个数
	}
	
	int record=-2;
	counting=0;
	unsigned int char_code;
	//下面开始断句的内容
	for(i=0;i<flag+1;i++)
	{
		//标点全断，但是未考虑英文和数字
		if(input[record]>0)
		{
		 	record++;
		 	//printf("||,||");//此处内容还可以根据需求改
		 	strcat(eventual,"||,||");
		}
		//第一个字是汉字，第二个是标点，这样就不在后面断了
		else if(input[record]<0&&input[record+2]>=0)
		{
		 	record+=2;
		 	//printf("%c%c",input[record],input[record+1]);
		 	temp[0]=input[record];
		 	temp[1]=input[record+1];
		 	temp[2]='\0';
		 	strcat(eventual,temp);
		}
		else
		{
			//两个字都是汉字
		 	record+=2;
		 	if(mi_value(count[counting],count[counting+1])==-1)
		 	{
			 	printf("再按一次，彻底退出");
			 	getchar();
			 	return 1;
			}
		 	if(mi_value(count[counting],count[counting+1])>=MI_VALUE)
		 	{
		 		//本应连在一起的字
		 		zi5[0]=input[record];
		 		zi5[1]=input[record+1];
				if(strcmp(zi5,"是")==0||
				strcmp(zi5,"有")==0||
				strcmp(zi5,"谁")==0||
				strcmp(zi5,"啥")==0)
					//常见单音节词，容易连东西，但是应该分开
					//不输入我，你等人称代词，是因为有我们，你们这种集合人称代词
				{
					temp[0]=input[record];
					temp[1]=input[record+1];
					temp[2]='|';
					temp[3]='|';
					temp[4]='\0';
					strcat(eventual,temp);
				}
				else
				{
					zi5[0]=input[record+2];
					zi5[1]=input[record+3];
					if(strcmp(zi5,"是")==0||
					strcmp(zi5,"有")==0||
					strcmp(zi5,"谁")==0||
					strcmp(zi5,"啥")==0)
					{
						temp[0]=input[record];
						temp[1]=input[record+1];
						temp[2]='|';
						temp[3]='|';
						temp[4]='\0';
						strcat(eventual,temp);						
					}
					else
					{
						temp[0]=input[record];
						temp[1]=input[record+1];
						temp[2]='\0';
						strcat(eventual,temp);
					}
				}
			}
			else
			{
				//本不应连在一起的字
				//printf("%c%c||",input[record],input[record+1]);
				temp[0]=input[record];
				temp[1]=input[record+1];
				temp[2]='|';
				temp[3]='|';
				temp[4]='\0';
				strcat(eventual,temp);
			}
		}
		counting++;
	}
	fclose(fp);
	for(i=strlen(eventual)-1;i>=0;i--)
	{
		if(eventual[i]>=0)
		{
			eventual[i]='\0';
		}
		else
		{
			break;
		}
	}
	printf("%s\n",eventual);
	return 0;
}
