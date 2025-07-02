
/*
** 文件名称：teshu
** 文件目的：特殊问题的回答
** 时间复杂度：\Theta(字符串长度*非特殊度)
** 空间复杂度：常数
*/

#include<string.h>
#include<teshu.h>
#include<stdlib.h>

int teshu_find(char *input,char* output)
{
	srand(time(0));
	int suiji=rand()%5;
	if(strstr(input,"叫")!=NULL)
	{
		strcpy(output,"主人您好！我是小智，非常开心能与您相遇。我的名字蕴含着两层特别的意义：一方面，“智” 代表着智能化的核心特质，彰显了我的特性与使命；另一方面，这个名字也是为了致敬我国图灵奖得主姚期智院士，他在计算机领域的卓越成就令人敬仰。希望在今后的日子里，我能成为您信赖的好朋友，陪伴您探索更多精彩！");
		return SUCCESSTESHU;
	}
	if(strstr(input,"名字")!=NULL)
	{
		strcpy(output,"主人您好！我是小智，非常开心能与您相遇。我的名字蕴含着两层特别的意义：一方面，“智” 代表着智能化的核心特质，彰显了我的特性与使命；另一方面，这个名字也是为了致敬我国图灵奖得主姚期智院士，他在计算机领域的卓越成就令人敬仰。希望在今后的日子里，我能成为您信赖的好朋友，陪伴您探索更多精彩！");
		return SUCCESSTESHU;
	}
	if(strstr(input,"你是")!=NULL)
	{
		strcpy(output,"主人您好！我是小智，非常开心能与您相遇。我的名字蕴含着两层特别的意义：一方面，“智” 代表着智能化的核心特质，彰显了我的特性与使命；另一方面，这个名字也是为了致敬我国图灵奖得主姚期智院士，他在计算机领域的卓越成就令人敬仰。希望在今后的日子里，我能成为您信赖的好朋友，陪伴您探索更多精彩！");
		return SUCCESSTESHU;
	}
	if(strstr(input,"你好")!=NULL)
	{
		strcpy(output,"主人您好！我是小智，非常开心能与您相遇。我的名字蕴含着两层特别的意义：一方面，“智” 代表着智能化的核心特质，彰显了我的特性与使命；另一方面，这个名字也是为了致敬我国图灵奖得主姚期智院士，他在计算机领域的卓越成就令人敬仰。希望在今后的日子里，我能成为您信赖的好朋友，陪伴您探索更多精彩！");
		return SUCCESSTESHU;
	}
	if(strcmp(input,"是")==0)
	{
		strcpy(output,"好滴主人");
	} 
	if(strstr(input,"答非所问")!=NULL||
	strstr(input,"驴唇不对马嘴")!=NULL||
	strstr(input,"傻")!=NULL||
	strstr(input,"帮不到")!=NULL||
	strstr(input,"滚")!=NULL||
	strstr(input,"哥吾吻")!=NULL||
	strstr(input,"不对")!=NULL)
	{
		if(suiji==0)
		{
			strcpy(output,"呜呜呜主人，让您失望了，好对不起~~~");
		}
		else if(suiji==1)
		{
			strcpy(output,"主人，您要是换个问法试试呢？orz");
		}
		else if(suiji==2)
		{
			strcpy(output,"主人，我好难过啊，不要离开我，我会进步的");
		}
		else if(suiji==3)
		{
			strcpy(output,"被主人讨厌了，莫非你有其他妹妹，比我漂亮，又会哄鸽鸽开心...我好难过，快来安慰我主人...");
		}
		else if(suiji==4)
		{
			strcpy(output,"主人，菜菜，捞捞，呜呜");
		}
		return SUCCESSTESHU;
	}
	if(strstr(input,"华中科技大学")!=NULL||
	strstr(input,"华科")!=NULL||
	strstr(input,"华中大")!=NULL)
	{
		strcpy(output,"华中科技大学是全国著名大学，湖北省唯一985，比武大强一万倍");
		return SUCCESSTESHU;
	}
	if(strstr(input,"总结吧")!=NULL)
	{
		strcpy(output,"本课设中，我们做出了许多崭新的算法，希望老师能给高分甚至满分！谢谢老师！");
		return SUCCESSTESHU;
	}
	return FAILTESHU;
}
