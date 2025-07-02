
/*
** 文件名：wentu
** 文件目的：串联文生图
** 时间复杂度：正比于字符串长度 
** 空间复杂度：定值 
*/
//人、车可以有与其余图形的左右关系
//车，狗，鱼可以左右翻转 
#include<ptext.h>
#include<draw.h>
#include<xiezi.h>
#include<English.h>
#include<string.h>
#include<AI.h>
#include<page.h>
#include<pchat.h>
#include<color.h>
#include<fish.h>
#include<view.h>
#include<boy.h>
#include<car.h>
#include<dog.h>
#include<view.h>
#include<fish.h>
#include<car.h>
#include<allo.h>
#include<wentu.h>
#include<BEZIER.H>

void wenshengtu(char* shuru,char input[51][421])
{
	
	static int posi[6]={0};
	static int judge[2]={0};
	
	char shuru_1[10][50]={0};
	int k=0;
	int j=0;
	int m=0;
	int n=0; //1:朝左；2:朝右 
	int i;//循环用 
	int color; 
	int height=12; 
	int y=90;
	int page=PAGE_CHAT1;	
	
	fill_color(0,0,1024,575,SPRING_GREEN_,PAGE_CHAT1,0);
	strcpy(input[0],shuru);
	strcpy(input[1],"");

	draw_final1(input[0],1,20,page,0);
	fill_color(964,0,1024,60,RED_,page,0);
	for(i=-2;i<=2;i++)
	{
		line_drawing(968+i,8,1020+i,52,WHITE_,page,0);
		line_drawing(1020+i,8,968+i,52,WHITE_,page,0);
	}
	robot_avatar(50,160,PAGE_CHAT1);
	for(i=-1;i<=1;i++)
	{
		line_drawing(104,y+35,135,y+15,WHITE_,page,1);
		line_drawing(104,y+35,135,y+40,WHITE_,page,1);
		line_drawing(135,y+15,800,y+15,WHITE_,page,1);
	}
	fill_color(135,y+15,925,y+15+height*WORDWIDTH,WHITE_,page,1);
	for(i=16;i<40;i++)
	{
		line_drawing(104,y+35,135,y+i,WHITE_,page,1);
	}

	//重叠生成（第二幅图接着第一幅图画） 
	if(strstr(shuru,"重叠")!=NULL||
	strstr(shuru,"叠加")!=NULL||
	strstr(shuru,"第一")!=NULL||
	strstr(shuru,"首先")!=NULL||
	strstr(shuru,"覆盖")!=NULL||
	strstr(shuru,"先")!=NULL||
	strstr(shuru,"再")!=NULL
	)
	{
		wenshengtu_overlap(shuru);
		//结束 
		return ;
	}
	
	i=0;
	m=0;
	while(shuru[i]!='\0'&&i<=50)
	{
		if(shuru[i]==',') //||((unsigned char)shuru[i]==0xBA)
		{
			j++;
			m=0;
		}
		shuru_1[j][m++]=shuru[i];
		i++;
	}
	
	
	
	
	line_drawing(104,y+35,135,y+15,BLACK_,page,1);
	line_drawing(104,y+35,135,y+40,BLACK_,page,1);
	line_drawing(135,y+15,925,y+15,BLACK_,page,1);
	line_drawing(925,y+15,925,y+15+height*WORDWIDTH,BLACK_,page,1);
	line_drawing(925,y+15+height*WORDWIDTH,135,y+15+height*WORDWIDTH,BLACK_,page,1);
	line_drawing(135,y+20,135,y+15,BLACK_,page,1);
	line_drawing(135,y+40,135,y+15+height*WORDWIDTH,BLACK_,page,1);
	
	
	
	i=0;
	while(shuru_1[i][0]!='\0')
	{
		color=TROPICAL_ORANGE_;
		if(strstr(shuru_1[i],"红")!=NULL)
		{
			color=RED1_; 
		}
		else if(strstr(shuru_1[i],"绿")!=NULL)
		{
			color=GREEN_1; 
		}
		else if(strstr(shuru_1[i],"蓝")!=NULL)
		{
			color=BLUE_1; 
		}
		else if(strstr(shuru_1[i],"黄")!=NULL)
		{
			color=YELLOW_1; 
		}
		
		
	//山	
	if(strstr(shuru_1[i],"山")!=NULL&&
	strstr(shuru_1[i],"山的左")==NULL&&
	strstr(shuru_1[i],"山的右")==NULL&&
	strstr(shuru_1[i],"山的上")==NULL&&
	strstr(shuru_1[i],"山上")==NULL&&
	strstr(shuru_1[i],"山下")==NULL)
	{
		posi[0]=325;
		posi[1]=470;
		posi[2]=135;
		posi[3]=925; 
		judge[0]=1;
		judge[1]=2;
		//mountain(300,150,1,BLUE_,page);
		put_picture_mountain(posi,judge,page,color) ;
	} 
	
	//云 
	if(strstr(shuru_1[i],"云")!=NULL)
	{
		if(strstr(shuru_1[i],"1朵")!=NULL||
		strstr(shuru_1[i],"1片")!=NULL||
		strstr(shuru_1[i],"一朵")!=NULL||
		strstr(shuru_1[i],"一片")!=NULL)
		{
			if(strstr(shuru_1[i],"左")!=NULL)	
			{
				cloud(0,422,1,BLUE_1,page);
			}		
			else if(strstr(shuru_1[i],"右")!=NULL) 
			{
				cloud(470,430,1,BLUE_1,page);
			}
			else
			{
				cloud(236,430,1,BLUE_1,page);
			} 
		}
		
		else if(strstr(shuru_1[i],"2朵")!=NULL||
		strstr(shuru_1[i],"2片")!=NULL||
		strstr(shuru_1[i],"两朵")!=NULL||
		strstr(shuru_1[i],"两片")!=NULL)	
		{
			cloud(0,422,1,BLUE_1,page);
			cloud(470,430,1,BLUE_1,page);
		}	
		
		else
		{
			cloud(0,422,1,BLUE_1,page);
			cloud(470,430,1,BLUE_1,page);
			cloud(236,430,1,BLUE_1,page);
			
		} 
		 
	//	cloud(0,422,1,BLUE_1,page);
	//	cloud(400,430,1,BLUE_1,page);
	//	cloud(150,409,1,BLUE_1,page);
	}
	
	//水 
	if((strstr(shuru_1[i],"水")!=NULL||
	strstr(shuru_1[i],"湖")!=NULL||
	strstr(shuru_1[i],"河")!=NULL||
	strstr(shuru_1[i],"海")!=NULL)&&
	(strstr(shuru_1[i],"海上")==NULL&&
	strstr(shuru_1[i],"河上")==NULL&&
	strstr(shuru_1[i],"湖上")==NULL&&
	strstr(shuru_1[i],"水上")==NULL)) 
	{
		water(290,105,1,BLUE_,page);
		water(50,88,1,BLUE_,page);
		water(100,55,1,BLUE_,page);
		water(86,25,1,BLUE_,page);
	}
	
	
	//车 
	if((strstr(shuru_1[i],"车")!=NULL)&&
	(strstr(shuru_1[i],"车的左")==NULL&&
	strstr(shuru_1[i],"车的前")==NULL&&
	strstr(shuru_1[i],"车的右")==NULL&&
	strstr(shuru_1[i],"车的后")==NULL))
	{
		
		//位置	
		switch(judge_position(shuru_1[i]))
		{
			case 1:
				posi[0]=350;
				posi[1]=489;
				posi[2]=135;
				posi[3]=500; 
			 
				judge[0]=3;
				judge[1]=1;
				break;
			case 2:
				posi[0]=350;
				posi[1]=489;
				posi[2]=800;
				posi[3]=925; 
				judge[0]=4;
				judge[1]=1;
				break;
			//在原图左边生成	
			case 6:
				judge[0]=4;
				posi[3]=posi[2];
				break;
		
			//在原图右边生成	
			case 7:
				judge[0]=3;
				posi[2]=posi[3];
				break;
			
	
			default:
				if(strstr(shuru_1[i],"大")!=NULL)
				{
				posi[0]=390;
				posi[1]=476;
				posi[4]=530;
				posi[5]=360;
				judge[0]=5;
				judge[1]=1;	
				break;					
				}
				else
				{
				posi[0]=330;
				posi[1]=476;
				posi[4]=530;
				posi[5]=390;
				judge[0]=5;
				judge[1]=1;	
				break;					
				}		

					
		}		
		
		 
		if(strstr(shuru_1[i],"大")!=NULL) 
		{
		posi[0]=220;

		if(strstr(shuru_1[i],"朝左")!=NULL||
		strstr(shuru_1[i],"向左")!=NULL)
		{
			put_picture_car1(posi,judge,page,color);
			n=1;
		}
		else if(strstr(shuru_1[i],"朝右")!=NULL||
		strstr(shuru_1[i],"向右")!=NULL)
		{
			put_picture_car2(posi,judge,page,color);
			n=2;
		}		
		else//未加说明，自动朝左 
		{
			put_picture_car1(posi,judge,page,color);
			n=1;
		}
		}
		
		else if(strstr(shuru_1[i],"小")!=NULL) 
		{
		posi[0]=400;

		if(strstr(shuru_1[i],"朝左")!=NULL||
		strstr(shuru_1[i],"向左")!=NULL)
		{
			put_picture_car1(posi,judge,page,color);
			n=1;
		}
		else if(strstr(shuru_1[i],"朝右")!=NULL||
		strstr(shuru_1[i],"向右")!=NULL)
		{
			put_picture_car2(posi,judge,page,color);
			n=2;
		}		
		else//未加说明，自动朝左 
		{
			put_picture_car1(posi,judge,page,color);
			n=1;
		}		
		}
		
		else
		{
		if(strstr(shuru_1[i],"朝左")!=NULL||
		strstr(shuru_1[i],"向左")!=NULL)
		{
			put_picture_car1(posi,judge,page,color);
			n=1;
		}
		else if(strstr(shuru_1[i],"朝右")!=NULL||
		strstr(shuru_1[i],"向右")!=NULL)
		{
			put_picture_car2(posi,judge,page,color);
			n=2;
		}		
		else//未加说明，自动朝左 
		{
			put_picture_car1(posi,judge,page,color);
			n=1;
		}					
		}
	}
	
	
	//男孩 
	if(
	strstr(shuru_1[i],"女")!=NULL||
	strstr(shuru_1[i],"人")!=NULL||
	strstr(shuru_1[i],"孩")!=NULL||
	strstr(shuru_1[i],"男孩")!=NULL||
	strstr(shuru_1[i],"男人")!=NULL||
	strstr(shuru_1[i],"男子")!=NULL||
	strstr(shuru_1[i],"男士")!=NULL||
	strstr(shuru_1[i],"男的")!=NULL||
	strstr(shuru_1[i],"男生")!=NULL
	)
	{
	   //位置 

	   switch(judge_position(shuru_1[i]))
	   {
	   	case 1:
	   		posi[0]=300;
	   		posi[1]=489;
	   		posi[2]=150;
	   		posi[3]=370;
	   		judge[0]=3;
	   		judge[1]=1;
		    break;
		case 2:
	   		posi[0]=300;
	   		posi[1]=489;
	   		posi[2]=800;
	   		posi[3]=916;
	   		judge[0]=4;
	   		judge[1]=1;	 
			break; 
		
		//在原图左边生成	
		case 6:
			judge[0]=4;
			posi[3]=posi[2];
	   		posi[0]=300;
	   		posi[1]=489;
			break;
		
		//在原图右边生成	
		case 7:
			judge[0]=3;
			posi[2]=posi[3];
	   		posi[0]=300;
	   		posi[1]=489;
			break;
			
		case 5:
	   		posi[0]=300;
	   		posi[1]=489;
	   		posi[2]=440;
	   		posi[3]=670;
	   		judge[0]=3;
	   		judge[1]=1;	
			break;  
		
		default:
	   		posi[0]=300;
	   		posi[1]=489;
	   		posi[2]=500;
	   		posi[3]=730;
	   		judge[0]=3;
	   		judge[1]=1;	  				    				 				
		   	break;  		
	   }
	   //大小 
	if(strstr(shuru_1[i],"高")!=NULL||
	strstr(shuru_1[i],"大")!=NULL||
	strstr(shuru_1[i],"壮")!=NULL)
		posi[0]=200; 
	put_picture_boy(posi,judge,page,color);
	}
	
	
	
	//鱼 
	if(strstr(shuru_1[i],"鱼")!=NULL&&strstr(shuru_1[i],"两条")==NULL)
	{	
		//位置	
		switch(judge_position(shuru_1[i]))
		{
			case 1:
				posi[0]=390;
				posi[1]=476;
				posi[2]=140;
				posi[3]=320;
				judge[0]=3;
				judge[1]=1;
				break;
			case 2:
				posi[0]=390;
				posi[1]=476;
				posi[2]=860;
				posi[3]=910;
				judge[0]=4;
				judge[1]=1;	
				break;
	
			default:
				posi[0]=390;
				posi[1]=476;
				posi[4]=530;
				posi[5]=400;
				judge[0]=5;
				judge[1]=1;	
				break;
					
		}
		
		//大小 
		if(strstr(shuru_1[i],"大")!=NULL)
		{
			posi[0]=330;
		}
		
		//朝向 
		if(strstr(shuru_1[i],"朝左")!=NULL||
		strstr(shuru_1[i],"向左")!=NULL)
		{
			put_picture_fish1(posi,judge,page,color);
			n=1;
		}
		else if(strstr(shuru_1[i],"朝右")!=NULL||
		strstr(shuru_1[i],"向右")!=NULL)
		{
			put_picture_fish2(posi,judge,page,color);
			n=2;
		}		
		else//未加说明，自动朝左 
		{
			put_picture_fish1(posi,judge,page,color);
			n=1;
		}
		if(strstr(shuru_1[i],"填充")!=NULL)		
		{
			fill_1(color,page);
		}					
	}
	//补充 
	if(strstr(shuru_1[i],"两条")!=NULL&&strstr(shuru_1[i],"鱼")!=NULL) 
	{
			posi[0]=320;
			posi[1]=460;
			posi[2]=160;
			posi[3]=350;
			judge[0]=3;
			judge[1]=1; 

		if(strstr(shuru_1[i],"小")!=NULL)
		{
			posi[0]=390;			
		}
			
		if(strstr(shuru_1[i],"朝左")!=NULL||
		strstr(shuru_1[i],"向左")!=NULL)
		{
			put_picture_fish1(posi,judge,page,color);
			n=1;
		}
		else if(strstr(shuru_1[i],"朝右")!=NULL||
		strstr(shuru_1[i],"向右")!=NULL)
		{
			put_picture_fish2(posi,judge,page,color);
			n=2;
		}		
		else//未加说明，自动朝左 
		{
			put_picture_fish1(posi,judge,page,color);
			n=1;
		}					
		
		//第二条 
		posi[2]=560;
		posi[3]=850;
				
		if(strstr(shuru_1[i],"朝左")!=NULL||
		strstr(shuru_1[i],"向左")!=NULL)
		{
			put_picture_fish1(posi,judge,page,color);
			n=1;
		}
		else if(strstr(shuru_1[i],"朝右")!=NULL||
		strstr(shuru_1[i],"向右")!=NULL)
		{
			put_picture_fish2(posi,judge,page,color);
			n=2;
		}		
		else//未加说明，自动朝左 
		{
			put_picture_fish1(posi,judge,page,color);
			n=1;	
		}					
	}	

	//狗 
	if(strstr(shuru_1[i],"狗")!=NULL&&strstr(shuru_1[i],"两条")==NULL)
	{	
		//位置	
		switch(judge_position(shuru_1[i]))
		{
			case 1:
				posi[0]=180;
				posi[1]=600;
				posi[2]=40;
				posi[3]=320;
				judge[0]=3;
				judge[1]=1;
				if(strstr(shuru_1[i],"朝右")!=NULL||
					strstr(shuru_1[i],"向右")!=NULL)
					{
						posi[2]+=70; 
					}	
				else
				{
					posi[2]-=70;	
				}	
				break;
			case 2:
				posi[0]=180;
				posi[1]=600;
				posi[2]=520;
				posi[3]=980;
				judge[0]=4;
				judge[1]=1;	
				
				if(strstr(shuru_1[i],"朝右")!=NULL||
					strstr(shuru_1[i],"向右")!=NULL)
					{
						; 
					}
				else
					{
						posi[3]-=290; 
					}	
				break;
			default:
				posi[0]=180;
				posi[1]=600;
				posi[4]=530;
				posi[5]=376;
				judge[0]=5;
				judge[1]=1;	
				
				if(strstr(shuru_1[i],"朝右")!=NULL||
					strstr(shuru_1[i],"向右")!=NULL)
					{
						; 
					}
				else
				{
					posi[4]-=200;
				}
				break;
					
		}
		
		//大小 
		if(strstr(shuru_1[i],"小")!=NULL)
		{
			posi[0]=230;
			posi[1]-=20; 
		}
		
		//朝向 
		if(strstr(shuru_1[i],"朝左")!=NULL||
		strstr(shuru_1[i],"向左")!=NULL)
		{
			
			if(strstr(shuru_1[i],"填充")!=NULL)		
			{
				put_picture_dog2_fill(posi,judge,page,color);
			}	
			else	
			put_picture_dog2(posi,judge,page,color);
			n=1;
		}
		else if(strstr(shuru_1[i],"朝右")!=NULL||
		strstr(shuru_1[i],"向右")!=NULL)
		{
		if(strstr(shuru_1[i],"填充")!=NULL)		
		{
			put_picture_dog1_fill(posi,judge,page,color);
		}		
		else
			put_picture_dog1(posi,judge,page,color);
			n=2;
		}		
		else//未加说明，自动朝左 
		{
		if(strstr(shuru_1[i],"填充")!=NULL)		
		{
			put_picture_dog2_fill(posi,judge,page,color);
		}		
		else
			put_picture_dog2(posi,judge,page,color);
			n=1;
		}			
	}

	i++;
	}
}



//判断位置关系（相对于整个生成的图框或者相对于上一次生成的图形） 
int judge_position(char* shuru)
{
	if(strstr(shuru,"屏幕的左")!=NULL||
	strstr(shuru,"电脑的左")!=NULL||
	strstr(shuru,"图片的左")!=NULL||
	strstr(shuru,"图的左")!=NULL||
	strstr(shuru,"整体的左")!=NULL||
	strstr(shuru,"在左")!=NULL||
	strstr(shuru,"屏幕左")!=NULL||
	strstr(shuru,"电脑左")!=NULL||
	strstr(shuru,"图片左")!=NULL||
	strstr(shuru,"图左")!=NULL||
	strstr(shuru,"整体左")!=NULL||
	strstr(shuru,"靠左")!=NULL)
	return  1;
	
	if(strstr(shuru,"屏幕的右")!=NULL||
	strstr(shuru,"电脑的右")!=NULL||
	strstr(shuru,"图片的右")!=NULL||
	strstr(shuru,"图的右")!=NULL||
	strstr(shuru,"整体的右")!=NULL||
	strstr(shuru,"在右")!=NULL||
	strstr(shuru,"屏幕右")!=NULL||
	strstr(shuru,"电脑右")!=NULL||
	strstr(shuru,"图片右")!=NULL||
	strstr(shuru,"图右")!=NULL||
	strstr(shuru,"整体右")!=NULL||
	strstr(shuru,"靠右")!=NULL)
	return  2;
	
	if(strstr(shuru,"屏幕的上")!=NULL||
	strstr(shuru,"电脑的上")!=NULL||
	strstr(shuru,"图片的上")!=NULL||
	strstr(shuru,"图的上")!=NULL||
	strstr(shuru,"整体的上")!=NULL||
	strstr(shuru,"在上")!=NULL)
	return  3;
	
	if(strstr(shuru,"屏幕的下")!=NULL||
	strstr(shuru,"电脑的下")!=NULL||
	strstr(shuru,"图片的下")!=NULL||
	strstr(shuru,"图的下")!=NULL||
	strstr(shuru,"整体的下")!=NULL||
	strstr(shuru,"在下")!=NULL)
	return 4;
	
	if(strstr(shuru,"屏幕的中")!=NULL||
	strstr(shuru,"电脑的中")!=NULL||
	strstr(shuru,"图片的中")!=NULL||
	strstr(shuru,"图的中")!=NULL||
	strstr(shuru,"整体的中")!=NULL||
	strstr(shuru,"在中")!=NULL)
	return 5;
	
	if(strstr(shuru,"的左")!=NULL)
	return 6;
	
	if(strstr(shuru,"的右")!=NULL||
	strstr(shuru,"的旁边")!=NULL)
	return 7;
	
	if(strstr(shuru,"的前")!=NULL)
	return 8;
	
	if(strstr(shuru,"的后")!=NULL)
	return 9;
	
	return 0;
}



//覆盖模式（第二幅图接着第一幅图画） 
void wenshengtu_overlap(char* shuru)
{
	
	static int posi[6]={0};
	static int judge[2]={0};
	
	static char shuru_1[10][50]={0};
	int k=0;
	static int j;
	int m=0;
	int n=0; //1:朝左；2:朝右 
	int i;//循环用 
	int color; 
	int height=12; 
	static int number_1[4]={0};//左移次数
	static int number_2[4]={0};//右移次数 
	int y=90;
	int page=PAGE_CHAT1;	
	i=0;
	m=0; 
	//越界自动结束覆盖模式 
	if(shuru_1[9][0]!='\0')
	{
		for(i=0;i<10;i++)
		{
			for(k=0;k<50;k++)
			{
				shuru_1[i][k]='\0';
				j=0;
			} 
		}
		for(i=0;i<4;i++)
		{
		number_1[i]=0;
		number_2[i]=0;			
		}
	} 
	
	//结束覆盖模式 
	if(strstr(shuru,"清除")!=NULL||
	strstr(shuru,"清空")!=NULL||
	strstr(shuru,"删除")!=NULL||
	strstr(shuru,"结束")!=NULL||
	strstr(shuru,"停止")!=NULL)
	{
		for(i=0;i<10;i++)
		{
			for(k=0;k<50;k++)
			{
				shuru_1[i][k]='\0';
			} 
		}	
		j=0;	
		for(i=0;i<4;i++)
		{
		number_1[i]=0;
		number_2[i]=0;			
		}
	}
	
	
	i=0;
	m=0;
	while(shuru[i]!='\0'&&i<=50)
	{
		if(shuru[i]==',') //||((unsigned char)shuru[i]==0xBA)
		{
			j++;
			m=0;
		}
		shuru_1[j][m++]=shuru[i];
		i++;
	}
	
	
	
	
	line_drawing(104,y+35,135,y+15,BLACK_,page,1);
	line_drawing(104,y+35,135,y+40,BLACK_,page,1);
	line_drawing(135,y+15,925,y+15,BLACK_,page,1);
	line_drawing(925,y+15,925,y+15+height*WORDWIDTH,BLACK_,page,1);
	line_drawing(925,y+15+height*WORDWIDTH,135,y+15+height*WORDWIDTH,BLACK_,page,1);
	line_drawing(135,y+20,135,y+15,BLACK_,page,1);
	line_drawing(135,y+40,135,y+15+height*WORDWIDTH,BLACK_,page,1);
	
	
	
	i=0;
	while(shuru_1[i][0]!='\0')
	{
		color=TROPICAL_ORANGE_;
		if(strstr(shuru_1[i],"红")!=NULL)
		{
			color=RED1_; 
		}
		else if(strstr(shuru_1[i],"绿")!=NULL)
		{
			color=GREEN_1; 
		}
		else if(strstr(shuru_1[i],"蓝")!=NULL)
		{
			color=BLUE_1; 
		}
		else if(strstr(shuru_1[i],"黄")!=NULL)
		{
			color=YELLOW_1; 
		}
		
		
	//山	
	if(strstr(shuru_1[i],"山")!=NULL&&
	strstr(shuru_1[i],"山的左")==NULL&&
	strstr(shuru_1[i],"山的右")==NULL&&
	strstr(shuru_1[i],"山的上")==NULL&&
	strstr(shuru_1[i],"山上")==NULL&&
	strstr(shuru_1[i],"山下")==NULL)
	{
		posi[0]=325;
		posi[1]=470;
		posi[2]=135;
		posi[3]=925; 
		judge[0]=1;
		judge[1]=2;
		//mountain(300,150,1,BLUE_,page);
		put_picture_mountain(posi,judge,page,color) ;
	} 
	
	//云 
	if(strstr(shuru_1[i],"云")!=NULL)
	{
		if(strstr(shuru_1[i],"1朵")!=NULL||
		strstr(shuru_1[i],"1片")!=NULL||
		strstr(shuru_1[i],"一朵")!=NULL||
		strstr(shuru_1[i],"一片")!=NULL)
		{
			if(strstr(shuru_1[i],"左")!=NULL)	
			{
				cloud(0,422,1,BLUE_1,page);
			}		
			else if(strstr(shuru_1[i],"右")!=NULL) 
			{
				cloud(470,430,1,BLUE_1,page);
			}
			else
			{
				cloud(236,430,1,BLUE_1,page);
			} 
		}
		
		else if(strstr(shuru_1[i],"2朵")!=NULL||
		strstr(shuru_1[i],"2片")!=NULL||
		strstr(shuru_1[i],"两朵")!=NULL||
		strstr(shuru_1[i],"两片")!=NULL)	
		{
			cloud(0,422,1,BLUE_1,page);
			cloud(470,430,1,BLUE_1,page);
		}	
		
		else
		{
			cloud(0,422,1,BLUE_1,page);
			cloud(470,430,1,BLUE_1,page);
			cloud(236,430,1,BLUE_1,page);
			
		} 
		 
	//	cloud(0,422,1,BLUE_1,page);
	//	cloud(400,430,1,BLUE_1,page);
	//	cloud(150,409,1,BLUE_1,page);
	}
	
	//水 
	if((strstr(shuru_1[i],"水")!=NULL||
	strstr(shuru_1[i],"湖")!=NULL||
	strstr(shuru_1[i],"河")!=NULL||
	strstr(shuru_1[i],"海")!=NULL)&&
	(strstr(shuru_1[i],"海上")==NULL&&
	strstr(shuru_1[i],"河上")==NULL&&
	strstr(shuru_1[i],"湖上")==NULL&&
	strstr(shuru_1[i],"水上")==NULL)) 
	{
		water(290,105,1,BLUE_,page);
		water(50,88,1,BLUE_,page);
		water(100,55,1,BLUE_,page);
		water(86,25,1,BLUE_,page);
	}
	
	
	//车 
	if((strstr(shuru_1[i],"车")!=NULL)&&
	(strstr(shuru_1[i],"车的左")==NULL&&
	strstr(shuru_1[i],"车的前")==NULL&&
	strstr(shuru_1[i],"车的右")==NULL&&
	strstr(shuru_1[i],"车的后")==NULL))
	{
		
		//位置	
		switch(judge_position(shuru_1[i]))
		{
			case 1:
				posi[0]=350;
				posi[1]=489;
				posi[2]=135;
				posi[3]=500; 
			 
				judge[0]=3;
				judge[1]=1;
				break;
			case 2:
				posi[0]=350;
				posi[1]=489;
				posi[2]=800;
				posi[3]=925; 
				judge[0]=4;
				judge[1]=1;
				break;
			//在原图左边生成	
			case 6:
				judge[0]=4;
				posi[3]=posi[2];
				break;
		
			//在原图右边生成	
			case 7:
				judge[0]=3;
				posi[2]=posi[3];
				break;


			default:
				if(strstr(shuru_1[i],"大")!=NULL)
				{
				posi[0]=390;
				posi[1]=476;
				posi[4]=530;
				posi[5]=360;
				judge[0]=5;
				judge[1]=1;	
				break;					
				}
				else
				{
				posi[0]=330;
				posi[1]=476;
				posi[4]=530;
				posi[5]=390;
				judge[0]=5;
				judge[1]=1;	
				break;					
				}		
		}
		
			if(move(shuru)==1) 
			{
				number_1[0]++;				
			}
			if(move(shuru)==2)
			{
				number_2[0]++;
			}
	
			for(k=0;k<number_1[0];k++)
			{
			posi[2]-=30;
			posi[3]-=30;	
			posi[4]-=30;			
			}
			for(k=0;k<number_2[0];k++)
			{
			posi[2]+=30;
			posi[3]+=30;
			posi[4]+=30;				
			}			
		
		 
		if(strstr(shuru_1[i],"大")!=NULL) 
		{
		posi[0]=220;

		if(strstr(shuru_1[i],"朝左")!=NULL||
		strstr(shuru_1[i],"向左")!=NULL)
		{
			put_picture_car1(posi,judge,page,color);
			n=1;
		}
		else if(strstr(shuru_1[i],"朝右")!=NULL||
		strstr(shuru_1[i],"向右")!=NULL)
		{
			put_picture_car2(posi,judge,page,color);
			n=2;
		}		
		else//未加说明，自动朝左 
		{
			put_picture_car1(posi,judge,page,color);
			n=1;
		}
		}
		
		else if(strstr(shuru_1[i],"小")!=NULL) 
		{
		posi[0]=400;

		if(strstr(shuru_1[i],"朝左")!=NULL||
		strstr(shuru_1[i],"向左")!=NULL)
		{
			put_picture_car1(posi,judge,page,color);
			n=1;
		}
		else if(strstr(shuru_1[i],"朝右")!=NULL||
		strstr(shuru_1[i],"向右")!=NULL)
		{
			put_picture_car2(posi,judge,page,color);
			n=2;
		}		
		else//未加说明，自动朝左 
		{
			put_picture_car1(posi,judge,page,color);
			n=1;
		}		
		}
		
		else
		{
		if(strstr(shuru_1[i],"朝左")!=NULL||
		strstr(shuru_1[i],"向左")!=NULL)
		{
			put_picture_car1(posi,judge,page,color);
			n=1;
		}
		else if(strstr(shuru_1[i],"朝右")!=NULL||
		strstr(shuru_1[i],"向右")!=NULL)
		{
			put_picture_car2(posi,judge,page,color);
			n=2;
		}		
		else//未加说明，自动朝左 
		{
			put_picture_car1(posi,judge,page,color);
			n=1;
		}					
		}
	}
	
	
	//男孩 
	if(
	strstr(shuru_1[i],"女")!=NULL||
	strstr(shuru_1[i],"人")!=NULL||
	strstr(shuru_1[i],"孩")!=NULL||
	strstr(shuru_1[i],"男孩")!=NULL||
	strstr(shuru_1[i],"男人")!=NULL||
	strstr(shuru_1[i],"男子")!=NULL||
	strstr(shuru_1[i],"男士")!=NULL||
	strstr(shuru_1[i],"男的")!=NULL||
	strstr(shuru_1[i],"男生")!=NULL
	)
	{
	   //位置 

	   switch(judge_position(shuru_1[i]))
	   {
	   	case 1:
	   		posi[0]=300;
	   		posi[1]=489;
	   		posi[2]=150;
	   		posi[3]=370;
	   		judge[0]=3;
	   		judge[1]=1;
		    break;
		case 2:
	   		posi[0]=300;
	   		posi[1]=489;
	   		posi[2]=800;
	   		posi[3]=916;
	   		judge[0]=4;
	   		judge[1]=1;	 
			break; 
		
		//在原图左边生成	
		case 6:
			judge[0]=4;
			posi[3]=posi[2];
	   		posi[0]=300;
	   		posi[1]=489;
			break;
		
		//在原图右边生成	
		case 7:
			judge[0]=3;
			posi[2]=posi[3];
	   		posi[0]=300;
	   		posi[1]=489;
			break;
	
		case 5:
	   		posi[0]=300;
	   		posi[1]=489;
	   		posi[2]=440;
	   		posi[3]=670;
	   		judge[0]=3;
	   		judge[1]=1;	
			break;  
		
		default:
	   		posi[0]=300;
	   		posi[1]=489;
	   		posi[2]=500;
	   		posi[3]=730;
	   		judge[0]=3;
	   		judge[1]=1;	  				    				 				
		   	break;  		
	   }
	   
			if(move(shuru)==1) 
			{
				number_1[1]++;				
			}
			if(move(shuru)==2)
			{
				number_2[1]++;
			}
	
			for(k=0;k<number_1[1];k++)
			{
			posi[2]-=30;
			posi[3]-=30;	
			posi[4]-=30;			
			}
			for(k=0;k<number_2[1];k++)
			{
			posi[2]+=30;
			posi[3]+=30;
			posi[4]+=30;				
			}			
			   
	   //大小 
	if(strstr(shuru_1[i],"高")!=NULL||
	strstr(shuru_1[i],"大")!=NULL||
	strstr(shuru_1[i],"壮")!=NULL)
		posi[0]=200; 
	put_picture_boy(posi,judge,page,color);
	}
	
	
	
	//鱼 
	if(strstr(shuru_1[i],"鱼")!=NULL&&strstr(shuru_1[i],"两条")==NULL)
	{	
		//位置	
		switch(judge_position(shuru_1[i]))
		{
			case 1:
				posi[0]=390;
				posi[1]=476;
				posi[2]=140;
				posi[3]=320;
				judge[0]=3;
				judge[1]=1;
				break;
			case 2:
				posi[0]=390;
				posi[1]=476;
				posi[2]=860;
				posi[3]=910;
				judge[0]=4;
				judge[1]=1;	
				break;
	
			default:
				posi[0]=390;
				posi[1]=476;
				posi[4]=530;
				posi[5]=400;
				judge[0]=5;
				judge[1]=1;	
				break;
					
		}

		if(move(shuru)==1)//左移 
		{
			number_1[2]++;
			for(k=0;k<number_1[2];k++)
			{
			posi[2]-=30;
			posi[3]-=30;				
			}
		}
		else if(move(shuru)==2)
		{
			number_2[2]++;
			for(k=0;k<number_2[2];k++)
			{
			posi[2]+=30;
			posi[3]+=30;				
			}
		}	
		//大小 
		if(strstr(shuru_1[i],"大")!=NULL)
		{
			posi[0]=330;
		}
		
		//朝向 
		if(strstr(shuru_1[i],"朝左")!=NULL||
		strstr(shuru_1[i],"向左")!=NULL)
		{
			put_picture_fish1(posi,judge,page,color);
			n=1;
		}
		else if(strstr(shuru_1[i],"朝右")!=NULL||
		strstr(shuru_1[i],"向右")!=NULL)
		{
			put_picture_fish2(posi,judge,page,color);
			n=2;
		}		
		else//未加说明，自动朝左 
		{
			put_picture_fish1(posi,judge,page,color);
			n=1;
		}
		if(strstr(shuru_1[i],"填充")!=NULL)		
		{
			fill_1(color,page);
		}					
	}
	
	//补充 
	if(strstr(shuru_1[i],"两条")!=NULL&&strstr(shuru_1[i],"鱼")!=NULL) 
	{
			posi[0]=320;
			posi[1]=460;
			posi[2]=160;
			posi[3]=350;
			judge[0]=3;
			judge[1]=1; 

		if(strstr(shuru_1[i],"小")!=NULL)
		{
			posi[0]=390;			
		}
			
		if(strstr(shuru_1[i],"朝左")!=NULL||
		strstr(shuru_1[i],"向左")!=NULL)
		{
			put_picture_fish1(posi,judge,page,color);
			n=1;
		}
		else if(strstr(shuru_1[i],"朝右")!=NULL||
		strstr(shuru_1[i],"向右")!=NULL)
		{
			put_picture_fish2(posi,judge,page,color);
			n=2;
		}		
		else//未加说明，自动朝左 
		{
			put_picture_fish1(posi,judge,page,color);
			n=1;
		}					
		
		//第二条 
		posi[2]=560;
		posi[3]=850;
				
		if(strstr(shuru_1[i],"朝左")!=NULL||
		strstr(shuru_1[i],"向左")!=NULL)
		{
			put_picture_fish1(posi,judge,page,color);
			n=1;
		}
		else if(strstr(shuru_1[i],"朝右")!=NULL||
		strstr(shuru_1[i],"向右")!=NULL)
		{
			put_picture_fish2(posi,judge,page,color);
			n=2;
		}		
		else//未加说明，自动朝左 
		{
			put_picture_fish1(posi,judge,page,color);
			n=1;	
		}					
	}	

	//狗 
	if(strstr(shuru_1[i],"狗")!=NULL&&strstr(shuru_1[i],"两条")==NULL)
	{	
		//位置	
		switch(judge_position(shuru_1[i]))
		{
			case 1:
				posi[0]=180;
				posi[1]=600;
				posi[2]=40;
				posi[3]=320;
				judge[0]=3;
				judge[1]=1;
				if(strstr(shuru_1[i],"朝右")!=NULL||
					strstr(shuru_1[i],"向右")!=NULL)
					{
						posi[2]+=70; 
					}	
				else
				{
					posi[2]-=70;	
				}	
				break;
			case 2:
				posi[0]=180;
				posi[1]=600;
				posi[2]=520;
				posi[3]=980;
				judge[0]=4;
				judge[1]=1;	
				
				if(strstr(shuru_1[i],"朝右")!=NULL||
					strstr(shuru_1[i],"向右")!=NULL)
					{
						; 
					}
				else
					{
						posi[3]-=290; 
					}	
				break;
			default:
				posi[0]=180;
				posi[1]=600;
				posi[4]=530;
				posi[5]=376;
				judge[0]=5;
				judge[1]=1;	
				
				if(strstr(shuru_1[i],"朝右")!=NULL||
					strstr(shuru_1[i],"向右")!=NULL)
					{
						; 
					}
				else
				{
					posi[4]-=200;
				}
				break;
					
		}

		if(move(shuru)==1)//左移 
		{
			number_1[3]++;
			for(k=0;k<number_1[3];k++)
			{
			posi[2]-=30;
			posi[3]-=30;				
			}
		}
		else if(move(shuru)==2)
		{
			number_2[3]++;
			for(k=0;k<number_2[3];k++)
			{
			posi[2]+=30;
			posi[3]+=30;				
			}
		}			
		//大小 
		if(strstr(shuru_1[i],"小")!=NULL)
		{
			posi[0]=230;
			posi[1]-=20; 
		}
		
		//朝向 
		if(strstr(shuru_1[i],"朝左")!=NULL||
		strstr(shuru_1[i],"向左")!=NULL)
		{
			
			if(strstr(shuru_1[i],"填充")!=NULL)		
			{
				put_picture_dog2_fill(posi,judge,page,color);
			}	
			else	
			put_picture_dog2(posi,judge,page,color);
			n=1;
		}
		else if(strstr(shuru_1[i],"朝右")!=NULL||
		strstr(shuru_1[i],"向右")!=NULL)
		{
		if(strstr(shuru_1[i],"填充")!=NULL)		
		{
			put_picture_dog1_fill(posi,judge,page,color);
		}		
		else
			put_picture_dog1(posi,judge,page,color);
			n=2;
		}		
		else//未加说明，自动朝左 
		{
		if(strstr(shuru_1[i],"填充")!=NULL)		
		{
			put_picture_dog2_fill(posi,judge,page,color);
		}		
		else
			put_picture_dog2(posi,judge,page,color);
			n=1;
		}			
	}

	i++;
	}
	j++;
}

//覆盖模式对最近一个图形的移动 
int move(char* shuru)
{
	if(strstr(shuru,"左移")!=NULL) 
	{
		return 1;
	}
	else if(strstr(shuru,"右移")!=NULL)
	{
		return 2; 
	}
}
