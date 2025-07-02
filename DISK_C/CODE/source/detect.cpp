
/*
**文件名称：detect
**文件目的：检测有没有其他类型的字符并改变，记录数字
**时间复杂度：正比于字数和特殊字符数
**空间复杂度：正比于字数和特殊字符数
*/

#include<stdio.h>
#include<string.h>
#include<detect.h>

//还需添加空格，标点等特殊字符的处理，空格是去掉或换为句号，标点是两倍
int detect(char* input,int* strategy)
{
	int sum=0;
	*strategy=CHINESE;
	int length=strlen(input);
	int i,j;
	for(i=0;i<length;i++)
	{
		if(input[i]<0)
		{
			continue;
		}
		else if(input[i]>='0'&&input[i]<='9')
		{
			sum++;
			*strategy=CALCULATE;
			//将阿拉伯数字重复一遍，以适应GB2312的字节数
			//strcpy(input,"啊哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈");//test
			/*
			input[length+1]='\0';
			for(j=length-1;j>=i+1;j--)
			{
				input[j+1]=input[j];
			}
			input[i+1]=input[i];
			length++;
			*/
		}
		else if(input[i]=='+'||input[i]=='='||input[i]=='-'||input[i]=='*'||input[i]=='/')
		{
			sum++;
			*strategy=CALCULATE;
		}
		else if((input[i]>='a'&&input[i]<='z')||(input[i]>='A'&&input[i]<='Z'))
		{
			//strcpy(input,"这是英语！");//test
			sum++;
			//*strategy=ENGLISH;
			//将英文字母重复一遍，以适应GB2312的字节数
			/*
			input[length+1]=0;
			for(j=length-1;j>=i+1;j--)
			{
				input[j+1]=input[j];
			}
			input[i+1]=input[i];
			length++;
			*/
		} 
	}
	return sum;//返回ASC2字符的总数
}

int ddetect(char* input)
{
	int length=strlen(input);
	int i,j;
	for(i=0;i<length;i++)
	{
		if(input[i]<0)
		{
			continue;
		}
		else
		{
			input[length+1]='\0';
			for(j=length-1;j>=i+1;j--)
			{
				input[j+1]=input[j];
			}
			input[i+1]=input[i];
			length++;			
		}
	}
}
