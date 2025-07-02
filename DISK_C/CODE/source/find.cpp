
/*
**文件名称：find
**文件目的：获得lasthao相对应的逻辑词语
**时间复杂度：k1*树的高度+k2*词语个数
**空间复杂度：常数
*/

#include<lasthao.h>
#include<stdio.h>
#include<string.h>
#include<alloc.h>
#include<stdlib.h>
#include<time.h>
#include<find.h>
#include<xiezi.h>
#include<page.h>
#include<dos.h>

//函数名称：find_logic
//函数目的：实现单个句子的文献查找
 
char* find_logic(ZHUWEIBIN arr,char* eventual,char* result)
{
	int i;
	FILE* fphhh;
	char temp;
	char rchar;
	int rrr;
	int counting=0;
	int cishu=0;
	char shuzu[400]={0};
	for(i=0;i<400;i++)
	{
		shuzu[i]='\0';
	}
	char weiyucici[50];
	char binyucici[50];
	memset(weiyucici,0,50);
	memset(binyucici,0,50);
	char transit[200]={0};
	char str[100]={0};
	int branch=panduanshenmeci(arr);
	strcpy(str,file_zhu(arr));
	
	char filechar;
	int suiji;
	int filenum=0;
	int zanghua=0;
	int sss=0;
	
	//char hahaha[100]={0};
	//itoa(arr.wei[1],hahaha,10);
	//strcpy(shuzu,str);
	//return shuzu;
	
	if(arr.zhu[7]<=0||arr.zhu[7]>11)
	{
		goto tiaoyixia;
	}
	
	fphhh=fopen(str,"rb");
	//delay(10);
	if(fphhh==NULL)
	{
		tiaoyixia:
		if(strstr(eventual,"我靠")!=NULL)
		{
			strcpy(shuzu,"莫说脏话！");
			zanghua=10;
			sss=1;
		}
		else if(strstr(eventual,"傻逼")!=NULL)
		{
			strcpy(shuzu,"莫说脏话！");
			zanghua=10;
		}
		else if(strstr(eventual,"我草")!=NULL)
		{
			strcpy(shuzu,"莫说脏话！");
			zanghua=10;
			sss=1;
		}
		else if(strstr(eventual,"妈的")!=NULL)
		{
			strcpy(shuzu,"莫说脏话！");
			zanghua=10;
		}
		if(strstr(eventual,"请你")!=NULL)
		{
			if(sss==1)
			{
				goto shelter;
			}
			replace(eventual,"请你","这就");
			strcpy(shuzu,eventual);
			replace(eventual,"这就","请你");
			//fclose(fphhh);
			return shuzu;
		}
		if(strstr(eventual,"我")!=NULL)
		{
			if(sss==1)
			{
				goto shelter;
			}
			if(strstr(eventual,"你")==NULL)
			{
				replace(eventual,"我","你");
				strcpy(shuzu,eventual);
				replace(eventual,"你","我");
				//fclose(fphhh);
				return shuzu;
			}
		}
		if(strstr(eventual,"你")!=NULL)
		{
			if(sss==1)
			{
				goto shelter;
			}
			if(strstr(eventual,"我")==NULL)
			{
				replace(eventual,"你","我");
				strcpy(shuzu,eventual);
				replace(eventual,"我","你");
				//fclose(fphhh);
				return shuzu;
			}
		}
		shelter:
		srand(time(0));
		suiji=rand()%5;
		if(suiji==0)
		{
			strcpy(shuzu,"抱歉我没听懂你的意思");
		}
		else if(suiji==1)
		{
			strcpy(shuzu,"抱一丝没听懂");
		}
		else if(suiji==2)
		{
			strcpy(shuzu,"你说的啥？木有搞懂");
		}
		else if(suiji==3)
		{
			strcpy(shuzu,"单纯的小AI我听不懂聪明的你的话语");
		} 
		else if(suiji==4)
		{
			strcpy(shuzu,"啥？？？没听懂");
		}
		if(fphhh!=NULL)
			fclose(fphhh);
		return shuzu;
	}
	

	
	//找疑问语气的内容
	if(branch==0)
	{
		if(strstr(eventual,"我靠")!=NULL)
		{
			strcpy(shuzu,"首先请文明的你不要说脏话。");
			zanghua=26;
		}
		else if(strstr(eventual,"傻逼")!=NULL)
		{
			strcpy(shuzu,"首先请文明的你不要说脏话。");
			zanghua=26;
		}
		else if(strstr(eventual,"我草")!=NULL)
		{
			strcpy(shuzu,"首先请文明的你不要说脏话。");
			zanghua=26;
		}
		else if(strcpy(eventual,"妈的")!=NULL)
		{
			strcat(shuzu,"首先请文明的你不要说脏话。");
			zanghua=26;
		}
		
		//strcpy(shuzu,"branch=0");
		//return shuzu;
		
		if(strstr(eventual,"是")!=NULL)
		{
			while(1)
			{
				filechar=fgetc(fphhh);
				if(filechar=='5')
				{
					if(filenum==0)
					{
						filenum=1;
					}
				}
				else if(filechar=='$'&&filenum==1)
				{
					fclose(fphhh);
					goto x;
				}
				if(filenum==1)
				{
					shuzu[strlen(shuzu)]=filechar;
					//shuzu[strlen(shuzu)]='\0';
				}
			}
		}
		
		if(strstr(eventual,"什么")!=NULL)
		{
			//memset(shuzu,0,500);
			while(1)
			{
				filechar=fgetc(fphhh);
				if(filechar=='5')
				{
					if(filenum==0)
					{
						filenum=1;
						//exit(0);
					}
				}
				else if(filechar=='9'&&filenum==1)
				{
					fclose(fphhh);
					goto x1;
					break;
				}
				else if(filenum==1)
				{
					shuzu[strlen(shuzu)]=filechar;
					//shuzu[strlen(shuzu)]='\0';
				}
			}
		}
		
		else if(strstr(eventual,"怎")!=NULL)
		{
			while(1)
			{
				filechar=fgetc(fphhh);
				if(filechar=='5')
				{
					if(filenum==0||filenum==1)
					{
						filenum++;
					}
				}
				else if(filechar=='$'&&filenum==2)
				{
					fclose(fphhh);
					goto x;
				}
				else if(filenum==2)
				{
					shuzu[strlen(shuzu)]=filechar;
					//shuzu[strlen(shuzu)]='\0';
				}
			}
		}
		
		else if(strstr(eventual,"如何")!=NULL)
		{
			while(1)
			{
				filechar=fgetc(fphhh);
				if(filechar=='5')
				{
					if(filenum==0||filenum==1)
					{
						filenum++;
					}
				}
				else if(filechar=='$'&&filenum==2)
				{
					fclose(fphhh);
					goto x;
				}
				else if(filenum==2)
				{
					shuzu[strlen(shuzu)]=filechar;
					//shuzu[strlen(shuzu)]='\0';
				}
			}
		}
		
		else if(strstr(eventual,"咋")!=NULL)
		{
			while(1)
			{
				filechar=fgetc(fphhh);
				if(filechar=='5')
				{
					if(filenum==0||filenum==1)
					{
						filenum++;
					}
				}
				else if(filechar=='$'&&filenum==2)
				{
					fclose(fphhh);
					goto x;
				}
				else if(filenum==2)
				{
					shuzu[strlen(shuzu)]=filechar;
					//shuzu[strlen(shuzu)]='\0';
				}
			}
			
			x:
				shuzu[strlen(shuzu)-1]='\0';
				return shuzu;
				
		}
		
		goto gogogo;
		//这就是只有主语
	}
	
	else if(branch==1)
	{
		if(strstr(eventual,"我靠")!=NULL)
		{
			strcpy(shuzu,"首先请文明的你不要说脏话。");
			zanghua=26;
		}
		else if(strstr(eventual,"傻逼")!=NULL)
		{
			strcpy(shuzu,"首先请文明的你不要说脏话。");
			zanghua=26;
		}
		else if(strstr(eventual,"我草")!=NULL)
		{
			strcpy(shuzu,"首先请文明的你不要说脏话。");
			zanghua=26;
		}
		else if(strstr(eventual,"妈的")!=NULL)
		{
			strcpy(shuzu,"首先请文明的你不要说脏话。");
			zanghua=26;
		}
		
		//strcpy(shuzu,"branch=1");
		//return shuzu;
		
		if(strstr(eventual,"是")!=NULL)
		{
			//memset(shuzu,0,500);
			while(1)
			{
				filechar=fgetc(fphhh);
				if(filechar=='5')
				{
					if(filenum==0)
					{
						filenum=1;
						//exit(0);
					}
				}
				else if(filechar=='9'&&filenum==1)
				{
					fclose(fphhh);
					goto x1;
					break;
				}
				else if(filenum==1)
				{
					shuzu[strlen(shuzu)]=filechar;
					//shuzu[strlen(shuzu)]='\0';
				}
			}
		}
		
		if(strstr(eventual,"什么")!=NULL)
		{
			//memset(shuzu,0,500);
			while(1)
			{
				filechar=fgetc(fphhh);
				if(filechar=='5')
				{
					if(filenum==0)
					{
						filenum=1;
						//exit(0);
					}
				}
				else if(filechar=='9'&&filenum==1)
				{
					fclose(fphhh);
					goto x1;
					break;
				}
				else if(filenum==1)
				{
					shuzu[strlen(shuzu)]=filechar;
					//shuzu[strlen(shuzu)]='\0';
				}
			}
		}
		
		else if(strstr(eventual,"怎")!=NULL)
		{
			while(1)
			{
				filechar=fgetc(fphhh);
				if(filechar=='5')
				{
					if(filenum==0||filenum==1)
					{
						filenum++;
					}
				}
				else if(filechar=='$'&&filenum==2)
				{
					fclose(fphhh);
					goto x;
				}
				else if(filenum==2)
				{
					shuzu[strlen(shuzu)]=filechar;
					//shuzu[strlen(shuzu)]='\0';
				}
			}
		}
		
		else if(strstr(eventual,"如何")!=NULL)
		{
			while(1)
			{
				filechar=fgetc(fphhh);
				if(filechar=='5')
				{
					if(filenum==0||filenum==1)
					{
						filenum++;
					}
				}
				else if(filechar=='$'&&filenum==2)
				{
					fclose(fphhh);
					goto x;
				}
				else if(filenum==2)
				{
					shuzu[strlen(shuzu)]=filechar;
					//shuzu[strlen(shuzu)]='\0';
				}
			}
		}
		
		else if(strstr(eventual,"咋")!=NULL)
		{
			while(1)
			{
				filechar=fgetc(fphhh);
				if(filechar=='5')
				{
					if(filenum==0||filenum==1)
					{
						filenum++;
					}
				}
				else if(filechar=='$'&&filenum==2)
				{
					fclose(fphhh);
					goto x;
				}
				else if(filenum==2)
				{
					shuzu[strlen(shuzu)]=filechar;
					//shuzu[strlen(shuzu)]='\0';
				}
			}
			
			x1:
				shuzu[strlen(shuzu)-1]='\0';
				//fclose(fphhh);
				return shuzu;
				
		}
		
		goto gogogo;
	}
	
	else
	{
		gogogo:
		
		if(strstr(eventual,"我靠")!=NULL)
		{
			strcpy(shuzu,"首先请文明的你不要说脏话。");
			zanghua=26;
		}
		else if(strstr(eventual,"傻逼")!=NULL)
		{
			strcpy(shuzu,"首先请文明的你不要说脏话。");
			zanghua=26;
		}
		else if(strstr(eventual,"我草")!=NULL)
		{
			strcpy(shuzu,"首先请文明的你不要说脏话。");
			zanghua=26;
		}
		else if(strstr(eventual,"妈的")!=NULL)
		{
			strcpy(shuzu,"首先请文明的你不要说脏话。");
			zanghua=26;
		}
			
		if(strstr(eventual,"是")!=NULL)
		{
			//memset(shuzu,0,500);
			while(1)
			{
				filechar=fgetc(fphhh);
				if(filechar=='5')
				{
					if(filenum==0)
					{
						filenum=1;
						//exit(0);
					}
				}
				else if(filechar=='9'&&filenum==1)
				{
					fclose(fphhh);
					//shuzu[strlen(shuzu)-1]='\0';
					goto x1;
					break;
				}
				else if(filenum==1)
				{
					shuzu[strlen(shuzu)]=filechar;
					//shuzu[strlen(shuzu)]='\0';
				}
			}
		}
		
		if(strstr(eventual,"什么")!=NULL)
		{
			//memset(shuzu,0,500);
			while(1)
			{
				filechar=fgetc(fphhh);
				if(filechar=='5')
				{
					if(filenum==0)
					{
						filenum=1;
						//exit(0);
					}
				}
				else if(filechar=='9'&&filenum==1)
				{
					fclose(fphhh);
					goto x1;
					break;
				}
				else if(filenum==1)
				{
					shuzu[strlen(shuzu)]=filechar;
					//shuzu[strlen(shuzu)]='\0';
				}
			}
		}
		
		if(strstr(eventual,"怎")!=NULL)
		{
			while(1)
			{
				filechar=fgetc(fphhh);
				if(filechar=='5')
				{
					if(filenum==0||filenum==1)
					{
						filenum++;
					}
				}
				else if(filechar=='$'&&filenum==2)
				{
					fclose(fphhh);
					goto x2;
				}
				else if(filenum==2)
				{
					shuzu[strlen(shuzu)]=filechar;
					//shuzu[strlen(shuzu)]='\0';
				}
			}
			
			x2:
				shuzu[strlen(shuzu)-1]='\0';
				//fclose(fphhh);
				return shuzu;
		}
		
		if(strstr(eventual,"如何")!=NULL)
		{
			while(1)
			{
				filechar=fgetc(fphhh);
				if(filechar=='5')
				{
					if(filenum==0||filenum==1)
					{
						filenum++;
					}
				}
				else if(filechar=='$'&&filenum==2)
				{
					fclose(fphhh);
					goto x3;
				}
				else if(filenum==2)
				{
					shuzu[strlen(shuzu)]=filechar;
					//shuzu[strlen(shuzu)]='\0';
				}
			}
			
			x3:
				shuzu[strlen(shuzu)-1]='\0';
				//fclose(fphhh);
				return shuzu;
		}
		
		if(strstr(eventual,"咋")!=NULL)
		{
			while(1)
			{
				filechar=fgetc(fphhh);
				if(filechar=='5')
				{
					if(filenum==0||filenum==1)
					{
						filenum++;
					}
				}
				else if(filechar=='$'&&filenum==2)
				{
					fclose(fphhh);
					goto x4;
				}
				else if(filenum==2)
				{
					shuzu[strlen(shuzu)]=filechar;
					//shuzu[strlen(shuzu)]='\0';
				}
			}
			
			x4:
				shuzu[strlen(shuzu)-1]='\0';
				//fclose(fphhh);
				return shuzu;
		}
		
		memset(shuzu,0,400);
		//所谓有宾语，无非是观察词与词的联系
		if(arr.bin[2]==1)
		{
			while(1)
			{
				temp=fgetc(fphhh);
				if(strstr(str,"$")==NULL)
				{
					if(temp=='$')
					{
						strcat(str,"$");
					}
					continue;
				}
				if(strstr(str,"$")!=NULL&&strstr(str,"$9")==NULL)
				{
					if(temp=='9')
					{
						strcat(str,"9");
					}
					else
					{
						str[0]='\0';
					}
					continue;
				}
				if(strstr(str,"$9")!=NULL&&strstr(str,"$98")==NULL)
				{
					if(temp=='8')
					{
						strcat(str,"8");
					}
					else
					{
						str[0]='\0';
						str[1]='\0';
					}
					continue;
				}
				if(strstr(str,"$98")!=NULL&&strstr(str,"$985")==NULL)
				{
					if(temp=='5')
					{
						str[0]='\0';
						str[1]='\0';
						str[2]='\0';
						break;
					}
					else
					{
						str[0]='\0';
						str[1]='\0';
						str[2]='\0';
						continue;
					}
				}
				if(feof(fphhh))
				{
					break;
				}
			}
			while(1)
			{
				temp=fgetc(fphhh);
				if(temp=='$')
				{
					counting=0;
					break;
				}
				else
				{
					result[counting++]=temp;
				}
				if(feof(fphhh))
				{
					break;
				}
			}
			strcpy(shuzu,result);
			fclose(fphhh);
			return shuzu;
		}
		//怎么做部分
		else if(arr.bin[2]==3)
		{
			while(1)
			{
				temp=fgetc(fphhh);
				if(strstr(str,"$")==NULL)
				{
					if(temp=='$')
					{
						strcat(str,"$");
					}
					continue;
				}
				if(strstr(str,"$")!=NULL&&strstr(str,"$9")==NULL)
				{
					if(temp=='9')
					{
						strcat(str,"9");
					}
					else
					{
						str[0]='\0';
					}
					continue;
				}
				if(strstr(str,"$9")!=NULL&&strstr(str,"$98")==NULL)
				{
					if(temp=='8')
					{
						strcat(str,"8");
					}
					else
					{
						str[0]='\0';
						str[1]='\0';
					}
					continue;
				}
				if(strstr(str,"$98")!=NULL&&strstr(str,"$985")==NULL)
				{
					if(temp=='5')
					{
						if(cishu==0)
						{
							str[0]='\0';
							str[1]='\0';
							str[2]='\0';
							cishu++;
						}
						else
						{
							cishu=0;
							str[0]='\0';
							str[1]='\0';
							str[2]='\0';
							break;
						}
					}
					else
					{
						str[0]='\0';
						str[1]='\0';
						str[2]='\0';
						continue;
					}
				}
				if(feof(fphhh))
				{
					break;
				}
			}
			while(1)
			{
				temp=fgetc(fphhh);
				if(temp=='$')
				{
					counting=0;
					break;
				}
				else
				{
					result[counting++]=temp;	
				}
				if(feof(fphhh))
				{
					break;
				}
			}
			strcpy(shuzu,result);
			fclose(fphhh);
			return shuzu;
		}
		//其他部分
		else
		{
			while(1)
			{
				temp=fgetc(fphhh);
				
				if(feof(fphhh))
				{
					goto shelter;
					break;
				}
				
				if(strstr(str,"$")==NULL)
				{
					if(temp=='$')
					{
						strcat(str,"$");
					}
					//goto shelter;
					continue;
				}
				if(strstr(str,"$")!=NULL&&strstr(str,"$9")==NULL)
				{
					if(temp=='9')
					{
						strcat(str,"9");
					}
					else
					{
						str[0]='\0';
					}
					//goto shelter;
					continue;
				}
				if(strstr(str,"$9")!=NULL&&strstr(str,"$98")==NULL)
				{
					if(temp=='8')
					{
						strcat(str,"8");
					}
					else
					{
						str[0]='\0';
						str[1]='\0';
					}
					//goto shelter;
					continue;
				}
				if(strstr(str,"$98")!=NULL&&strstr(str,"$985")==NULL)
				{
					if(temp=='5')
					{
						if(cishu==0||cishu==1)
						{
							str[0]='\0';
							str[1]='\0';
							str[2]='\0';
							cishu++;
							//goto shelter;
							continue;
						}
						else
						{
							cishu=0;
							str[0]='\0';
							str[1]='\0';
							str[2]='\0';
							//goto shelter;
							break;
						}
					}
					else
					{
						str[0]='\0';
						str[1]='\0';
						str[2]='\0';
						//goto shelter;
						continue;
					}
				}
			}
			strcpy(weiyucici,weiyuci(arr));
			FILE *fphhhwei;
			fphhhwei=fopen(weiyucici,"rt+");
			if(fphhhwei==NULL)
			{
				goto shelter;
			}
			char weiyurecord[50]={0};
			int hhh;
			char hhhwei;
			for(hhh=0;;hhh++)
			{
				hhhwei=fgetc(fphhhwei);
				if(hhhwei!='$')
				{
					weiyurecord[hhh]=hhhwei;
				}
				else
				{
					break;
				}
			}
			
			strcpy(weiyucici,weiyurecord);
			
			//上面成功把指针引到了最后的部分
			while(1)
			{
				temp=fgetc(fphhh);
				//此处须改变一下，后面的那个改成编码
				if(strstr(str,"-")==NULL)
				{
					if(temp=='-')
					{
						strcat(str,"-");
					}
					continue;
				}
				if(strstr(str,"-=")==NULL&&strstr(str,"-")!=NULL)
				{
					if(temp=='=')
					{
						strcat(str,"=");
					}
					else
					{
						str[0]='\0';
					}
					continue;
				}
				if(strstr(str,"-=")!=NULL&&strstr(str,"-=+")==NULL)
				{
					if(temp=='+')
					{
						strcat(str,"+");
						continue;
					}
					else
					{
						result[counting++]=temp;
						//result[counting++]='\0';
						continue;
					}
				}
				if(strstr(str,"-=+")!=NULL&&strstr(str,"-=+=")==NULL)
				{
					if(temp=='='&&!feof(fphhh))
					{
						result[counting++]='\0';
						
						if(strstr(weiyucici,result)!=NULL)
						{
							rrr=0;
							while(1)
							{
								rchar=fgetc(fphhh);
								if(rchar!='-')
								{
									shuzu[rrr++]=rchar;
								}
								else
								{
									shuzu[rrr]='\0';
									break;
								}
							}
							fclose(fphhh);
							fclose(fphhhwei);
							return shuzu;
						}
						//result[counting++]=temp;
						//continue;
					}
					else if(feof(fphhh))//到达文件末尾
					{
						//此为异常情况，进行标记，因为宾语为空 
						int j;
						shuzu[0]=1;
						shuzu[1]=1;
						shuzu[2]=4;
						shuzu[3]=5;
						shuzu[4]=1;
						shuzu[5]=4;
						goto shelter;
						break;
					}
					else
					{
						str[0]='\0';
						str[1]='\0';
						str[2]='\0';
						memset(result,0,sizeof(result));
						continue;
					}
				}/*
				if(strstr(str,"-=+=")!=NULL&&strstr(str,"-=+=-")==NULL)
				{
					if(temp=='-'&&!feof(fphhh))
					{
						strcat(str,"-");
						continue;
					}
					else if(feof(fphhh))
					{
						if(strcmp(weiyucici,result)==0)
						{
							strcpy(shuzu,result);
						}
						else
						{
							//没找到词的话......
							goto shelter;
						}
						break;
					}
					else
					{
						result[counting++]=temp;
						continue;
					}
				}
				if(strstr(str,"-=+=-")!=NULL)
				{
					if(temp=='=')
					{
						int j;
						for(j=2;j<6;j++)
						{
							str[j]='\0';
						}
						//注意下一次还得用str[0]和str[1]呢！
						if(strcmp(result,weiyucici)==0)
						{
							strcpy(shuzu,result);
							memset(result,0,sizeof(result));
							break;
						}
						else
						{
							counting=0;
							continue;
						}
					}
					else
					{
						str[4]='\0';
						result[counting++]='-';
						result[counting++]=temp;
					}
				}*/
			}
		}
		//以上的基本假设是，里面不会有-=,+=符号的真正内容
		fclose(fphhh);

		return shuzu;
	}
	fclose(fphhh);
	return shuzu;
}

//函数名称：file_zhu
//函数目的：得出主语的文件名

char* file_zhu(ZHUWEIBIN arr)
{
	char str1[100];
	char str2[100];
	char str3[100];
	char str4[100];
	itoa(arr.zhu[7],str2,10);
	itoa(arr.zhu[8],str3,10);
	itoa(arr.zhu[9],str4,10);
	strcpy(str1,"C:\\CODE\\inf\\");
	strcat(str1,str2);
	strcat(str1,"\\");
	strcat(str1,str2);
	strcat(str1,"-");
	strcat(str1,str3);
	strcat(str1,"\\");
	strcat(str1,str2);
	strcat(str1,"-");
	strcat(str1,str3);
	strcat(str1,"-");
	strcat(str1,str4);
	strcat(str1,".txt");
	return str1;
}

//函数名称：file_wei
//函数目的：得出谓语的文件名 

char* file_wei(ZHUWEIBIN arr)
{
	char str11[100];
	char str2[100];
	char str3[100];
	char str4[100];	
	itoa(arr.wei[6],str2,10);
	itoa(arr.wei[7],str3,10);
	itoa(arr.wei[8],str4,10);
	strcpy(str11,"C:\\CODE\\inf\\");
	strcat(str11,str2);
	strcat(str11,"\\");
	strcat(str11,str2);
	strcat(str11,"-");
	strcat(str11,str3);
	strcat(str11,"\\");
	strcat(str11,str2);
	strcat(str11,"-");
	strcat(str11,str3);
	strcat(str11,"-");
	strcat(str11,str4);
	strcat(str11,".txt");
	return str11;
}

//函数名称：file_bin 
//函数目的：得出宾语的文件名 

char* file_bin(ZHUWEIBIN arr)
{
	char str111[100];
	char str2[100];
	char str3[100];
	char str4[100];
	itoa(arr.zhu[6],str2,10);
	itoa(arr.zhu[7],str3,10);
	itoa(arr.zhu[8],str4,10);
	strcpy(str111,"C:\\CODE\\inf\\");
	strcat(str111,str2);
	strcat(str111,"\\");
	strcat(str111,str2);
	strcat(str111,"-");
	strcat(str111,str3);
	strcat(str111,"\\");
	strcat(str111,str2);
	strcat(str111,"-");
	strcat(str111,str3);
	strcat(str111,"-");
	strcat(str111,str4);
	strcat(str111,".txt");
	return str111;
}

//函数名称：weiyuci 
//函数目的：得出谓语词标号对应的char*字符串 

char* weiyuci(ZHUWEIBIN arr)
{
	static char temp1[50];
	memset(temp1,0,50);
	char shuzu1[50];
	char shuzu2[50];
	char shuzu3[50];
	itoa(arr.wei[7],shuzu1,10);
	itoa(arr.wei[8],shuzu2,10);
	itoa(arr.wei[9],shuzu3,10);
	strcpy(temp1,"C:\\CODE\\inf\\");
	strcat(temp1,shuzu1);
	strcat(temp1,"\\");
	strcat(temp1,shuzu1);
	strcat(temp1,"-");
	strcat(temp1,shuzu2);
	strcat(temp1,"\\");
	strcat(temp1,shuzu1);
	strcat(temp1,"-");
	strcat(temp1,shuzu2);
	strcat(temp1,"-");
	strcat(temp1,shuzu3);
	strcat(temp1,".txt");
	return temp1;
}

//函数名称：binyuci 
//函数目的：得出宾语词标号对应的char*字符串

char* binyuci(ZHUWEIBIN arr)
{
	static char temp1[50];
	memset(temp1,0,50);
	char shuzu1[50];
	char shuzu2[50];
	char shuzu3[50];
	itoa(arr.wei[6],shuzu1,10);
	itoa(arr.wei[7],shuzu2,10);
	itoa(arr.wei[8],shuzu3,10);
	strcpy(temp1,"C:\\CODE\\inf\\");
	strcat(temp1,shuzu1);
	strcat(temp1,"\\");
	strcat(temp1,shuzu1);
	strcat(temp1,"-");
	strcat(temp1,shuzu2);
	strcat(temp1,"\\");
	strcat(temp1,shuzu1);
	strcat(temp1,"-");
	strcat(temp1,shuzu2);
	strcat(temp1,"-");
	strcat(temp1,shuzu3);
	strcat(temp1,".txt");
	return temp1;
}

//函数名称：panduanNULL 
//函数目的：判断一个句子里面有没有空的部分

int panduanNULL(ZHUWEIBIN arr)
{
	//1是非空，0是空 
	int i;
	for(i=0;i<40;i++)
	{
		if(arr.zhu[i]!=0)
		{
			return 1;
		}
	}
	for(i=0;i<40;i++)
	{
		if(arr.wei[i]!=0)
		{
			return 1;
		}
	}
	for(i=0;i<40;i++)
	{
		if(arr.bin[i]!=0)
		{
			return 1;
		}
	}
	return 0;
}

//函数名称：shenmeci 
//函数目的：直接查找相对应的谓语/宾语词 

char* shenmeci(ZHUWEIBIN arr)
{
	int temp=0,i;
	for(i=0;i<40;i++)
	{
		if(arr.bin[i]!=0)
		{
			temp=1;
		}
	}
	if(temp==1)
	{
		static char tempp[50];
		strcpy(tempp,weiyuci(arr));
		return tempp;
		//查找谓语词 
	}
	if(temp==0)
	{
		static char tempp[50];
		strcpy(tempp,binyuci(arr));
		return tempp;
		//查找宾语词 
	}
}

//函数名称：panduanshenmeci
//函数目的：通过一个句子里面某些部分词空不空，来进行判断

int panduanshenmeci(ZHUWEIBIN arr)
{
	int temp=0,i,tteemmpp=0;
	for(i=0;i<30;i++)
	{
		if(arr.bin[i]!=0)
		{
			temp=1;
		}
	}
	for(i=0;i<30;i++)
	{
		if(arr.wei[i]!=0)
		{
			tteemmpp=1;
		}
	}
	if(temp==0&&tteemmpp==0)
	{
		return 0;
		//只有主语
	}
	if(temp==0&&tteemmpp==1)
	{
		return 1;
		//有谓语，无宾语
	}
	if(temp==1&&tteemmpp==0)
	{
		return 2;
		//有宾语，无谓语
	}
	if(temp==1&&tteemmpp==1)
	{
		return 3;
		//有宾语，有谓语
	}
}

void replace(char *str,const char *s1,const char *s2)
{
	int i;
	int size1 = strlen(s1), size2 = strlen(s2);
	int delta = size2 - size1;
	char *pfind = strstr(str, s1);
	char *p;
	
	while(pfind)
	{
		//移动替换位置之后的字符，为替换字符串留出空间
		//向前/向后移动时，p指针移动方向不同，
		if(delta>0)
		{
			for(p=str+strlen(str);p>=pfind+size1;p--)
			{
				*(p+delta)=*p;
			}
		}
		else if(delta<0)
		{
			for(p=pfind+size1;p<=str+strlen(str);p++)
			{
				*(p+delta)=*p;
			}
		}
		
		for(i=0;i<size2;i++)
		{
			*(pfind+i)=*(s2+i);
		}
		
		pfind=strstr(pfind+1,s1);
	}
}
