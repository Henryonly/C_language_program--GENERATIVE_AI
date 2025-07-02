
/*
** 函数名称：GB2312互信息值训练函数 main 
** 程序作用：训练GB2312互信息值数据库，获得不同汉字间的互信息值，从而为后续断句分词打下基础。 
** 时间复杂度：字数×(6766+6766)
** 空间复杂度：6766×6767 
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>

#define GB_NUMBER 6763
#define INPUT_NUMBER 186962*2+1//比特位个数，就是汉字总数×2+1

void match(double num,char *array);

int main()
{
	int i,j,m;
	long long int jishu=0;
	//打开文件，配环境
	FILE *fp;
	setlocale(LC_ALL, "zh_CN.gb2312");
	if((fp=fopen("D:\\BC\\DISK_C\\CODE\\data\\GB2312.txt","rt+"))==NULL)
	{
		printf("GB2312数据库无法打开！任意键退出");
		getchar();
		exit(1);
	}
	FILE *fp2;
	setlocale(LC_ALL, "zh_CN.gb2312");
	if((fp2=fopen("D:\\BC\\DISK_C\\CODE\\train\\互信息值训练数据.txt","rt+"))==NULL)
	{
		printf("目标数据库无法打开！任意键退出");
		getchar();
		exit(1);
	}
	//输入训练字符串，采用动态内存分配 
	char *arr=(char*)malloc(1000000*sizeof(char));
	if(arr==NULL)
	{
		printf("内存分配失败！任意键退出");
		getchar();
		exit(1);
	}
	FILE *fp3;
	if((fp3=fopen("D:\\BC\\DISK_C\\CODE\\data\\tn.txt","rt+"))==NULL)
	{
		printf("互信息值训练数据无法打开！任意键退出");
		getchar();
		exit(1);
	}
	for(i=0;!feof(fp2);i++)
	{
		arr[i]=fgetc(fp2);
	}
	//分配堆区内存实现：double count[GB_NUMBER][GB_NUMBER+1]={0}; 
	double **count=(double**)malloc(GB_NUMBER*sizeof(double*));
	if(count==NULL)
	{
		printf("内存分配失败！任意键退出");
		getchar();
		return 1;
	}
	for(i=0;i<GB_NUMBER;i++) 
	{
		count[i]=(double*)malloc((GB_NUMBER+1)*sizeof(double));
		if(count[i]==NULL)
		{
			printf("内存分配失败！任意键退出");
			// 释放之前分配的内存
			for(j=0;j<i;j++)
			{
				free(count[j]);
			}
			free(count);
			getchar();
			return 1;
		}
	}
	for(i=0;i<GB_NUMBER;i++)
	{
		for(j=0;j<GB_NUMBER+1;j++)
		{
			count[i][j]=0;
		}
	}
	//从上到下，count对应的汉字与原文件汉字排列顺序相同;
	//从左到右，count对应的汉字与原文件汉字排列顺序相同，最后一个是总数
	//统计汉字出现的个数，以及两个汉字出现的个数
	for(i=0;i<strlen(arr);i+=2)
	{//每个汉字循环一次，由于GB2312汉字（非ASC2码部分）对应2 bites,所以步长是2
		for(j=0;j<GB_NUMBER*2;j+=2)
		{
			fseek(fp,j,0);//在文件里面一个汉字一个汉字的找
			char temp_char=fgetc(fp);
			char temp_char_after=fgetc(fp);//先固定住文件中汉字对应的二进制表示
			if(temp_char==arr[i]&&temp_char_after==arr[i+1])
			{
				//当汉字一样时，可以记录总数加1并维护
				count[j/2][GB_NUMBER]++;
				printf("%d\n",j);//debug
				//下面是填写与下个字符关系所用，如果下个字符是\0,那自然没事的
				for(m=0;m<GB_NUMBER*2;m+=2)
				{
					fseek(fp,m,0);//照样一个汉字一个汉字的找
					char temp_char_2=fgetc(fp);
					char temp_char_after_2=fgetc(fp);//固定
					if(temp_char_2==arr[i+2]&&temp_char_after_2==arr[i+3])
					{
						count[j/2][m/2]++;//给互信息值对应的部分+1
						break;
					}
				}
				break;
			}
		}
	}
	fclose(fp2);
	fclose(fp);
	free(arr);
	//这一步是算出各个字符对应的出现频率
	double sum=0;
	for(i=0;i<GB_NUMBER;i++)
	{
		sum+=count[i][GB_NUMBER];
	}
	
	//这一步是算出互信息值个数对应的频率，进行替换
	for(i=0;i<GB_NUMBER;i++)
	{
		for(j=0;j<GB_NUMBER;j++)
		{
			if(count[i][GB_NUMBER]!=0)
			{
				count[i][j]/=count[i][GB_NUMBER];
			}
			else
			{
				count[i][j]=0;
			}
		}
	}
	for(i=0;i<GB_NUMBER;i++)
	{
		for(j=0;j<GB_NUMBER;j++)
		{
			if(count[j][GB_NUMBER]!=0)
			{
				count[i][j]/=count[j][GB_NUMBER];
			}
			else
			{
				count[i][j]=0;
			}
		}
	}
	for(i=0;i<GB_NUMBER;i++)
	{
		if(sum!=0)
		{
			count[i][GB_NUMBER]/=sum;
		}
		else
		{
			count[i][GB_NUMBER]=0;
		}
	}
	count[GB_NUMBER-1][GB_NUMBER]=1;
	
	//这一步是用固定的格式打印出所需要的互信息值数据库表格 
	char array[13];
	for(i=0;i<GB_NUMBER;i++)
	{
		fputs("{",fp3);
		match(count[i][0],array);
		fputs(array,fp3);
		for(j=1;j<GB_NUMBER;j++)
		{
			match(count[i][j],array);
			fputs(array,fp3);
		}
		fputs("}",fp3);
	}
	return 0;
}

void match(double num,char *array)
{
	int i;
	array[0]='0';
	array[1]='.'; 
	for(i=1;i<11;i++)
	{
		num*=10;
		array[i+1]=(int)num+'0';
		num-=(int)num;
	}
	array[12]=',';
	array[13]='\0';
}
