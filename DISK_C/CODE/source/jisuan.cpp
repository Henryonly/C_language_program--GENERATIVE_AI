
/*
** 函数名称：calculate 
** 函数目的：实现各种复杂的数学计算
** 时间复杂度：最优复杂度
** 空间复杂度：最优复杂度（高精度下） 
*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<jisuan.h>

// 反转字符串
void reverse(char *str) 
{
    int len=strlen(str);
    for (int i=0;i<len/2;i++) 
	{
        char temp=str[i];
        str[i]=str[len-i-1];
        str[len-i-1]=temp;
    }
}

// 比较两个无符号数的大小
int compare(char *num1,char *num2) 
{
    int len1=strlen(num1);
    int len2=strlen(num2);
    if (len1!=len2) 
	{
        return len1-len2;
    }
    return strcmp(num1,num2);
}

// 高精度加法（无符号数）
void add(char *num1,char *num2,char *result) 
{
    int len1=strlen(num1);
    int len2=strlen(num2);
    int carry=0;
    int i=0;
    
    while(i<len1||i<len2||carry) 
	{
        int digit1=(i<len1)?(num1[i]-'0'):0;
        int digit2=(i<len2)?(num2[i]-'0'):0;
        int sum=digit1+digit2+carry;
        result[i]=(sum%10)+'0';
        carry=sum/10;
        i++;
    }
    result[i]='\0';
    reverse(result);
}

// 高精度减法（无符号数，假设 num1 >= num2）
void subtract(char *num1,char *num2,char *result)
{
    int len1=strlen(num1);
    int len2=strlen(num2);
    int borrow=0;
    int i=0;

    while(i<len1)
	{
        int digit1=num1[i]-'0';
        int digit2=(i<len2)?(num2[i]-'0'):0;
        int diff=digit1-digit2-borrow;
        if (diff<0)
		{
            diff+=10;
            borrow=1;
        } 
		else 
		{
            borrow=0;
        }
        result[i]=diff+'0';
        i++;
    }
    // 去除前导零
    while(i>1&&result[i-1]=='0')
	{
        result[i-1]='\0';
        i--;
    }
    result[i]='\0';
    reverse(result);
}

// 处理实数高精度加法，考虑正负号
void real_add(char *num1,char *num2,char *result) 
{
    int sign1=(num1[0]=='-')?-1:1;
    int sign2=(num2[0]=='-')?-1:1;
    if(num1[0]=='-')
	num1++;
    if(num2[0]=='-') 
	num2++;

    // 分离整数部分和小数部分
    char *dot1=strchr(num1,'.');
    char *dot2=strchr(num2,'.');
    char int_part1[1000]={0},frac_part1[1000]={0};
    char int_part2[1000]={0},frac_part2[1000]={0};
    char frac_result[1000]={0},int_result[1000]={0};

    if(dot1) 
	{
        strncpy(int_part1,num1,dot1-num1);
        strcpy(frac_part1,dot1+1);
    } 
	else 
	{
        strcpy(int_part1,num1);
    }

    if(dot2) 
	{
        strncpy(int_part2,num2,dot2-num2);
        strcpy(frac_part2,dot2+1);
    } 
	else 
	{
        strcpy(int_part2,num2);
    }

    // 补齐小数部分长度
    int max_frac_len=strlen(frac_part1)>strlen(frac_part2)?strlen(frac_part1):strlen(frac_part2);
    while(strlen(frac_part1)<max_frac_len) 
	{
        strcat(frac_part1,"0");
    }
    while(strlen(frac_part2)<max_frac_len) 
	{
        strcat(frac_part2,"0");
    }

    // 反转小数部分以便从低位开始相加
    reverse(frac_part1);
    reverse(frac_part2);

    // 处理同号相加
    if(sign1==sign2) 
	{
        add(frac_part1,frac_part2,frac_result);
        reverse(frac_result);

        // 处理小数部分进位
        int carry=0;
        if (strlen(frac_result)>max_frac_len) 
		{
            carry= 1;
            frac_result[strlen(frac_result)-1]='\0';
        }

        // 反转整数部分以便从低位开始相加
        reverse(int_part1);
        reverse(int_part2);
        if(carry) 
		{
            char carry_str[2]="1";
            add(int_part1,carry_str,int_part1);
        }
        add(int_part1,int_part2,int_result);
        reverse(int_result);

        // 合并结果
        if (sign1==-1) 
		{
            strcpy(result, "-");
        } 
		else 
		{
            result[0]='\0';
        }
        strcat(result, int_result);
        if(strlen(frac_result) > 0) 
		{
            strcat(result,".");
            strcat(result, frac_result);
        }
    } 
	else 
	{ // 异号相减
        int cmp=compare(int_part1,int_part2);
        if (cmp==0) 
		{
            cmp=compare(frac_part1,frac_part2);
        }
        if (cmp>=0) 
		{
            subtract(frac_part1,frac_part2,frac_result);
            reverse(frac_result);
            reverse(int_part1);
            reverse(int_part2);
            subtract(int_part1,int_part2,int_result);
            reverse(int_result);
            if (sign1==-1) 
			{
                strcpy(result,"-");
            } 
			else 
			{
                result[0]='\0';
            }
            strcat(result, int_result);
            if (strlen(frac_result) > 0) 
			{
                strcat(result,".");
                strcat(result,frac_result);
            }
        } 
		else 
		{
            subtract(frac_part2,frac_part1,frac_result);
            reverse(frac_result);
            reverse(int_part2);
            reverse(int_part1);
            subtract(int_part2,int_part1,int_result);
            reverse(int_result);
            if (sign2==-1) 
			{
                strcpy(result,"-");
            } 
			else 
			{
                result[0]='\0';
            }
            strcat(result,int_result);
            if (strlen(frac_result) > 0) 
			{
                strcat(result,".");
                strcat(result,frac_result);
            }
        }
    }
}
// 高精度乘法（无符号整数）
void multiply(char *num1,char*num2,char *result) 
{
    int len1=strlen(num1);
    int len2=strlen(num2);
    int *prod=(int *)calloc(len1+len2,sizeof(int));

    for (int i=len1-1;i>=0;i--) 
	{
        for (int j=len2-1;j>=0;j--) 
		{
            int mul=(num1[i]-'0')*(num2[j]-'0');
            int sum=mul+prod[i+j+1];
            prod[i+j+1]=sum%10;
            prod[i+j]+=sum/10;
        }
    }

	i=0;
    while(i<len1+len2&&prod[i]==0) 
	i++;
    if(i==len1+len2) 
	{
        result[0]='0';
        result[1]='\0';
    } 
	else 
	{
        int j=0;
        for(;i<len1+len2;i++) 
		{
            result[j++]=prod[i]+'0';
        }
        result[j]='\0';
    }
    free(prod);
}

// 处理实数高精度乘法，考虑正负号
void real_multiply(char *num1, char *num2, char *result) 
{
    int sign1=(num1[0]=='-')?-1:1;
    int sign2=(num2[0]=='-')?-1:1;
    if (num1[0]=='-') 
	num1++;
    if (num2[0]=='-') 
	num2++;

    // 分离整数部分和小数部分
    char *dot1=strchr(num1,'.');
    char *dot2=strchr(num2,'.');
    char int_part1[1000]={0},frac_part1[1000]={0};
    char int_part2[1000]={0},frac_part2[1000]={0};
    char temp_result[2000]={0};

    if(dot1) 
	{
        strncpy(int_part1,num1,dot1-num1);
        strcpy(frac_part1,dot1+1);
    } 
	else 
	{
        strcpy(int_part1,num1);
    }

    if(dot2) 
	{
        strncpy(int_part2,num2,dot2-num2);
        strcpy(frac_part2,dot2+1);
    } 
	else 
	{
        strcpy(int_part2,num2);
    }

    // 去掉小数点，当成整数相乘
    char combined_num1[2000],combined_num2[2000];
    strcpy(combined_num1,int_part1);
    strcat(combined_num1,frac_part1);
    strcpy(combined_num2,int_part2);
    strcat(combined_num2,frac_part2);

    multiply(combined_num1,combined_num2,temp_result);

    // 确定小数点位置
    int frac_digits=strlen(frac_part1)+strlen(frac_part2);
    int result_len=strlen(temp_result);

    if (frac_digits>0) 
	{
        if (frac_digits>=result_len) 
		{
            char temp[2000];
            strcpy(temp,"0.");
            for (int i = 0;i<frac_digits-result_len;i++) 
			{
                strcat(temp,"0");
            }
            strcat(temp,temp_result);
            strcpy(temp_result, temp);
        } 
		else 
		{
            char temp[2000];
            strncpy(temp, temp_result,result_len-frac_digits);
            temp[result_len - frac_digits]='\0';
            strcat(temp,".");
            strcat(temp,temp_result+result_len-frac_digits);
            strcpy(temp_result,temp);
        }
    }

    // 处理结果符号
    if (sign1*sign2==-1) 
	{
        strcpy(result,"-");
        strcat(result,temp_result);
    } 
	else 
	{
        strcpy(result,temp_result);
    }
}

// 计算字符串表示的实数的倒数
void reciprocal(char *input,char *output) 
{
    // 将输入字符串转换为双精度浮点数
    double num=strtod(input,NULL);

    // 检查输入是否为 0
    if (num==0) 
	{
        strcpy(output,"倒数无意义，输入不能为 0");
    } 
	else 
	{
        // 计算倒数
        double result=1.0/num;
        // 将结果转换为字符串
        sprintf(output,"%lf",result);
    }
}

//判断一个数是否是素数
int isPrime(long long int num)
{
    if(num<=1)
	{
		return 0;
	}
	for (int i=2;i<num;i++)
	{
		if (num%i==0)
		{
			return 0;
		}
	}
	return 1;
} 

// 计算最大公因数
long long int gcd(long long int a,long long int b) 
{
    while(b!=0)
	{
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
//最小公倍数就直接用这个算就行了 
