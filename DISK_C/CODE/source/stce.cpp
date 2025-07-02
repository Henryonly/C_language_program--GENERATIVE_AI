
/*
**文件名称：stceAC
**文件目的：时态等相关内容的判断
**空间复杂度：句子标号长度
**时间复杂度：\Theta(1)
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<alloc.h>
#include<queue.h>
#include<stce.h>

int tense(char*temp)
{
	// 处理过去时态关键词
	if(strstr(temp,"曾") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"已") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"了") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"过") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"刚") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"才") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"先") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"先前") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"之前") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"从前") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"过去") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"上回") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"上次") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"那时") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"当时") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"昨天") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"前天") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"去年") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"前年") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"上周") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"当年") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"以前") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"之前") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"那年") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"那天") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"当时") != NULL)
	    return TENSE_PAST;
	
	// 处理将来时态关键词
	if(strstr(temp,"未来") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"将来") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"明天") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"后天") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"明年") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"下周") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"往后") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"今后") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"迟早") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"早晚") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"远期") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"远景") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"此后") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"往后") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"以后") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"展望") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"畅想") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"之后") != NULL)
	    return TENSE_FUTURE;
	
	// 处理现在时态关键词
	if(strstr(temp,"现在") != NULL)
	    return TENSE_PRESENT;
	if(strstr(temp,"此刻") != NULL)
	    return TENSE_PRESENT;
	if(strstr(temp,"此时") != NULL)
	    return TENSE_PRESENT;
	if(strstr(temp,"当下") != NULL)
	    return TENSE_PRESENT;
	if(strstr(temp,"目前") != NULL)
	    return TENSE_PRESENT;
	if(strstr(temp,"即刻") != NULL)
	    return TENSE_PRESENT;
	if(strstr(temp,"随即") != NULL)
	    return TENSE_PRESENT;
	if(strstr(temp,"此刻") != NULL)
	    return TENSE_PRESENT;
	if(strstr(temp,"今") != NULL)
	    return TENSE_PRESENT;
	return 4;
}

int already(char* temp)
{
	// 处理已做关键词
	if(strstr(temp,"了") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"过") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"已经") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"刚刚") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"来着") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"方") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"毕") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"已") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"曾") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"刚") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"才") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"都") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"罢") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"完") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"成") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"终于") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"终究") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"算是") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"讫") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"之后") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"以来") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"就") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"便") != NULL)
	    return TENSE_PAST;
	
	// 处理要做关键词
	if(strstr(temp,"马上") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"立刻") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"即将") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"就要") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"准备") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"打算") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"计划") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"正欲") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"要") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"想") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"去") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"眼看") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"行将") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"决意") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"立意") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"着手") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"动手") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"开手") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"欲") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"拟") != NULL)
	    return TENSE_FUTURE;
	
	// 处理在做关键词
	if(strstr(temp,"着") != NULL)
	    return TENSE_PRESENT;
	if(strstr(temp,"呢") != NULL)
	    return TENSE_PRESENT;
	if(strstr(temp,"正") != NULL)
	    return TENSE_PRESENT;
	if(strstr(temp,"现在") != NULL)
	    return TENSE_PRESENT;
	if(strstr(temp,"当下") != NULL)
	    return TENSE_PRESENT;
	if(strstr(temp,"眼下") != NULL)
	    return TENSE_PRESENT;
	if(strstr(temp,"之际") != NULL)
	    return TENSE_PRESENT;
	if(strstr(temp,"这会") != NULL)
	    return TENSE_PRESENT;
	if(strstr(temp,"这时") != NULL)
	    return TENSE_PRESENT;
}

int beidong(char* str)
{
	if(strstr(str,"被")!=NULL)
	{
		if(strstr(str,"被子")==NULL)
		{
			return 1;
			//1对应被动句
		}
	}
	return 0;
	//0对应主动句
}
