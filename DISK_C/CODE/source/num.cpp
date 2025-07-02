#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char weixian[93][20]={0};
	for(int i=0;i<31;i++)
	{
		scanf("%s",weixian[i]);
	}
	char meiyong[100];
	char pingfen[93][100]={0};
	int pingfenshu[93]={0};
	for(int i=0;i<93;i++)
	{
		scanf("%s",meiyong);
		scanf("%s",meiyong);
		scanf("%s",meiyong);
		scanf("%s",pingfen[i]);
		scanf("%s",meiyong);
		if(strcmp(meiyong,"Negative")==0)
		{
			pingfenshu[i]=0;
		}
		else
		{
			pingfenshu[i]=1;
		}
	}
	for(int i=0;i<93;i++)
	{
		if(i<31)
		{
			printf(weixian[i]);
			printf("等级1:");
			if(pingfenshu[i]==0)
			{
				printf("减去%s",pingfen[i]);
			}
			else
			{
				printf("加上%s",pingfen[i]);
			}
			printf("\n");
		}
		else if(i>31&&i<62)
		{
			printf(weixian[i-32]);
			printf("等级2:");
			if(pingfenshu[i]==0)
			{
				printf("减去%s",pingfen[i]);
			}
			else
			{
				printf("加上%s",pingfen[i]);
			}			
			printf("\n");
		}
		else if(i>62&&i<93)
		{
			printf(weixian[i-63]);
			printf("等级3:");
			if(pingfenshu[i]==0)
			{
				printf("减去%s",pingfen[i]);
			}
			else
			{
				printf("加上%s",pingfen[i]);
			}	
			printf("\n");		
		}		
	}
} 
