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
			printf("�ȼ�1:");
			if(pingfenshu[i]==0)
			{
				printf("��ȥ%s",pingfen[i]);
			}
			else
			{
				printf("����%s",pingfen[i]);
			}
			printf("\n");
		}
		else if(i>31&&i<62)
		{
			printf(weixian[i-32]);
			printf("�ȼ�2:");
			if(pingfenshu[i]==0)
			{
				printf("��ȥ%s",pingfen[i]);
			}
			else
			{
				printf("����%s",pingfen[i]);
			}			
			printf("\n");
		}
		else if(i>62&&i<93)
		{
			printf(weixian[i-63]);
			printf("�ȼ�3:");
			if(pingfenshu[i]==0)
			{
				printf("��ȥ%s",pingfen[i]);
			}
			else
			{
				printf("����%s",pingfen[i]);
			}	
			printf("\n");		
		}		
	}
} 
