#include<huatu1.h>
#include<Bezier.h>
#include<draw.h>
#include<stdio.h>
#include<string.h>
#include<alloc.h>
#include<stdlib.h>
#include<color.h>
#include<graphics.h>
#include<stdarg.h>
#include<conio.h>
#include<Bezier.h>
#include<xiezi.h>
#include<dos.h>
#include<stddef.h>
#include<mouse.h>
#include<dog.h>
#include<boy.h>

//上：362
//下：662
//左：207
//右：683 
//原点在（304，618） 
void car(int x,int y,float k,int color,int page,int j)
{
	int x0[29];
	int y0[29];
	
	int x1[16];
	int y1[16];	
	
	int x2[12];
	int y2[12];
	
	int x3[26];
	int y3[26];
	
	int x4[21];
	int y4[21];
	
	int i;
	x=x-304;
	y=y-618;
	
	int h= (k*(x+445)-(x+304)*(k-1))*2;
	
	if(j==0)
		line_drawing(k*(x+304)-(x+304)*(k-1),k*(y+618)-(y+618)*(k-1),k*(x+236)-(x+304)*(k-1),k*(y+618)-(y+618)*(k-1),color,page,1);
	else
		line_drawing(h-k*(x+304)+(x+304)*(k-1),k*(y+618)-(y+618)*(k-1),h-k*(x+236)+(x+304)*(k-1),k*(y+618)-(y+618)*(k-1),color,page,1);
	
	x0[0]=k*(x+236);
	y0[0]=k*(y+618);
	
	x0[1]=k*(x+228);
	y0[1]=k*(y+614);
	
	x0[2]=k*(x+223);
	y0[2]=k*(y+606);
	
	x0[3]=k*(x+222);
	y0[3]=k*(y+596);
	
	x0[4]=k*(x+225);
	y0[4]=k*(y+589);
	
	x0[5]=k*(x+226);
	y0[5]=k*(y+585);
	
	x0[6]=k*(x+228);
	y0[6]=k*(y+583);
	
	x0[7]=k*(x+229);
	y0[7]=k*(y+580);
	
	x0[8]=k*(x+231);
	y0[8]=k*(y+573);
	
	x0[9]=k*(x+236);
	y0[9]=k*(y+563);
	
	x0[10]=k*(x+239);
	y0[10]=k*(y+555);
	
	x0[11]=k*(x+242);
	y0[11]=k*(y+549);
	
	x0[12]=k*(x+245);
	y0[12]=k*(y+543);
	
	x0[13]=k*(x+251);
	y0[13]=k*(y+533);
	
	x0[14]=k*(x+256);
	y0[14]=k*(y+527);
	
	x0[15]=k*(x+261);
	y0[15]=k*(y+519);
	
	x0[16]=k*(x+265);
	y0[16]=k*(y+513);
	
	x0[17]=k*(x+274);
	y0[17]=k*(y+502);
	
	x0[18]=k*(x+282);
	y0[18]=k*(y+497);
	
	x0[19]=k*(x+287);
	y0[19]=k*(y+493);
	
	x0[20]=k*(x+292);
	y0[20]=k*(y+490);
	
	x0[21]=k*(x+296);
	y0[21]=k*(y+486);
	
	//把放缩后的顶点复原 
	for(i=0;i<22;i++)
	{
		x0[i]=x0[i]-(x+304)*(k-1);
		y0[i]=y0[i]-(y+618)*(k-1);
	}	
	
	if(j==0)
		Bezier(color,22,page,x0,y0,0);	
	else
	{
		for(i=0;i<22;i++)
		{
			x0[i]=h-x0[i];
			y0[i]=y0[i];
		}			
		Bezier(color,22,page,x0,y0,0);
	}
	
	if (j==0)
		line_drawing(k*(x+296)+(x+304)*(k-1),k*(y+486)-(y+618)*(k-1),k*(x+314)+(x+304)*(k-1),k*(y+486)-(y+618)*(k-1),color,page,1);
	else
		line_drawing(h-k*(x+296)+(x+304)*(k-1),k*(y+486)-(y+618)*(k-1),h-k*(x+314)+(x+304)*(k-1),k*(y+486)-(y+618)*(k-1),color,page,1);
	
	x1[0]=k*(x+314);
	y1[0]=k*(y+460);
	
	x1[1]=k*(x+317);
	y1[1]=k*(y+454);
	
	x1[2]=k*(x+320);
	y1[2]=k*(y+442);
	
	x1[3]=k*(x+324);
	y1[3]=k*(y+434);
	
	x1[4]=k*(x+326);
	y1[4]=k*(y+426);
	
	x1[5]=k*(x+330);
	y1[5]=k*(y+419);
	
	x1[6]=k*(x+334);
	y1[6]=k*(y+411);
	
	x1[7]=k*(x+339);
	y1[7]=k*(y+405);
	
	x1[8]=k*(x+343);
	y1[8]=k*(y+400);
	
	x1[9]=k*(x+349);
	y1[9]=k*(y+399);
	
	x1[10]=k*(x+351);
	y1[10]=k*(y+394);
	
	x1[11]=k*(x+356);
	y1[11]=k*(y+391);
	
	x1[12]=k*(x+364);
	y1[12]=k*(y+386);
	
	x1[13]=k*(x+366);
	y1[13]=k*(y+384);
	
	x1[14]=k*(x+374);
	y1[14]=k*(y+383);
	
	x1[15]=k*(x+377);
	y1[15]=k*(y+382);

	//把放缩后的顶点复原 
	for(i=0;i<16;i++)
	{
		x1[i]=x1[i]-(x+304)*(k-1);
		y1[i]=y1[i]-(y+618)*(k-1);
	}	
	//Bezier(color,16,page,x1,y1,0);
	
	if(j==0)
	line_drawing(k*(x+296)-(x+304)*(k-1),k*(y+486)-(y+618)*(k-1),k*(x+314)-(x+304)*(k-1),k*(y+486)-(y+618)*(k-1),color,page,1);
	//else
	//line_drawing(h-k*(x+296)+(x+304)*(k-1),k*(y+486)-(y+618)*(k-1),h-k*(x+314)+(x+304)*(k-1),k*(y+486)-(y+618)*(k-1),color,page,1);
	
	if(j==0) 
	line_drawing(k*(x+314)-(x+304)*(k-1),k*(y+486)-(y+618)*(k-1),k*(x+314)-(x+304)*(k-1),k*(y+460)-(y+618)*(k-1),color,page,1);	
	else
	line_drawing(h-k*(x+314)+(x+304)*(k-1),k*(y+486)-(y+618)*(k-1),h-k*(x+314)+(x+304)*(k-1),k*(y+460)-(y+618)*(k-1),color,page,1);
	x2[0]=k*(x+314);
	y2[0]=k*(y+460);
	
	x2[1]=k*(x+315);
	y2[1]=k*(y+452);
	
	x2[2]=k*(x+317);
	y2[2]=k*(y+439);
	
	x2[3]=k*(x+319);
	y2[3]=k*(y+432);
	
	x2[4]=k*(x+323);
	y2[4]=k*(y+428);
	
	x2[5]=k*(x+328);
	y2[5]=k*(y+422);
	
	x2[6]=k*(x+336);
	y2[6]=k*(y+411);
	
	x2[7]=k*(x+341);
	y2[7]=k*(y+402);
	
	x2[8]=k*(x+348);
	y2[8]=k*(y+399);
	
	x2[9]=k*(x+355);
	y2[9]=k*(y+390);
	
	x2[10]=k*(x+365);
	y2[10]=k*(y+387);
	
	x2[11]=k*(x+366);
	y2[11]=k*(y+384);

	//把放缩后的顶点复原 
	for(i=0;i<12;i++)
	{
		x2[i]=x2[i]-(x+304)*(k-1);
		y2[i]=y2[i]-(y+618)*(k-1);
	}	
	if(j==0)
		Bezier(color,12,page,x2,y2,0);
	else
	{
		for(i=0;i<12;i++)
		{
			x2[i]=h-x2[i];
			y2[i]=y2[i];
		}			
		Bezier(color,12,page,x2,y2,0);
	}
	if(j==0)
	{ 
		line_drawing(k*(x+366)-(x+304)*(k-1),k*(y+384)-(y+618)*(k-1),k*(x+478)-(x+304)*(k-1),k*(y+384)-(y+618)*(k-1),color,page,1);
		line_drawing(k*(x+439)-(x+304)*(k-1),k*(y+384)-(y+618)*(k-1),k*(x+460)-(x+304)*(k-1),k*(y+311)-(y+618)*(k-1),color,page,1);
	}
	else
	{
		line_drawing(h-k*(x+366)+(x+304)*(k-1),k*(y+384)-(y+618)*(k-1),h-k*(x+478)+(x+304)*(k-1),k*(y+384)-(y+618)*(k-1),color,page,1);
		line_drawing(h-k*(x+439)+(x+304)*(k-1),k*(y+384)-(y+618)*(k-1),h-k*(x+460)+(x+304)*(k-1),k*(y+311)-(y+618)*(k-1),color,page,1);
	}
	x3[0]=k*(x+478);
	y3[0]=k*(y+384);
	
	x3[1]=k*(x+486);
	y3[1]=k*(y+384);
	
	x3[2]=k*(x+492);
	y3[2]=k*(y+384);
	
	x3[3]=k*(x+496);
	y3[3]=k*(y+384);
	
	x3[4]=k*(x+502);
	y3[4]=k*(y+386);
	
	x3[5]=k*(x+511);
	y3[5]=k*(y+388);
	
	x3[6]=k*(x+516);
	y3[6]=k*(y+390);
	
	x3[7]=k*(x+520);
	y3[7]=k*(y+392);
	
	x3[8]=k*(x+531);
	y3[8]=k*(y+397);
	
	x3[9]=k*(x+538);
	y3[9]=k*(y+402);
	
	x3[10]=k*(x+543);
	y3[10]=k*(y+408);
	
	x3[11]=k*(x+547);
	y3[11]=k*(y+412);
	
	x3[12]=k*(x+554);
	y3[12]=k*(y+415);
	
	x3[13]=k*(x+558);
	y3[13]=k*(y+418);
	
	x3[14]=k*(x+556);
	y3[14]=k*(y+419);
	
	x3[15]=k*(x+560);
	y3[15]=k*(y+420);
	
	x3[16]=k*(x+564);
	y3[16]=k*(y+424);
	
	x3[17]=k*(x+566);
	y3[17]=k*(y+427);
	
	x3[18]=k*(x+569);
	y3[18]=k*(y+432);
	
	x3[19]=k*(x+574);
	y3[19]=k*(y+437);
	
	x3[20]=k*(x+578);
	y3[20]=k*(y+441);
	
	x3[21]=k*(x+580);
	y3[21]=k*(y+446);
	
	x3[22]=k*(x+584);
	y3[22]=k*(y+452);
	
	x3[23]=k*(x+589);
	y3[23]=k*(y+457);
	
	x3[24]=k*(x+588);
	y3[24]=k*(y+462);
	
	x3[25]=k*(x+589);
	y3[25]=k*(y+460);

	//把放缩后的顶点复原 
	for(i=0;i<26;i++)
	{
		x3[i]=x3[i]-(x+304)*(k-1);
		y3[i]=y3[i]-(y+618)*(k-1);
	}
	if(j==0)	
		Bezier(color,26,page,x3,y3,0);
	else
	{
		for(i=0;i<26;i++)
		{
			x3[i]=h-x3[i];
			y3[i]=y3[i];
		}			
		Bezier(color,26,page,x3,y3,0);
	}
	if(j==0)
	{
	line_drawing(k*(x+589)-(x+304)*(k-1),k*(y+460)-(y+618)*(k-1),k*(x+589)-(x+304)*(k-1),k*(y+486)-(y+618)*(k-1),color,page,1);	
	line_drawing(k*(x+589)-(x+304)*(k-1),k*(y+486)-(y+618)*(k-1),k*(x+619)-(x+304)*(k-1),k*(y+486)-(y+618)*(k-1),color,page,1);	
	}
	else
	{
		line_drawing(h-k*(x+589)+(x+304)*(k-1),k*(y+460)-(y+618)*(k-1),h-k*(x+589)+(x+304)*(k-1),k*(y+486)-(y+618)*(k-1),color,page,1);	
		line_drawing(h-k*(x+589)+(x+304)*(k-1),k*(y+486)-(y+618)*(k-1),h-k*(x+619)+(x+304)*(k-1),k*(y+486)-(y+618)*(k-1),color,page,1);	
	}
	x4[0]=k*(x+619);
	y4[0]=k*(y+486);
	
	x4[1]=k*(x+629);
	y4[1]=k*(y+490);
	
	x4[2]=k*(x+633);
	y4[2]=k*(y+492);
	
	x4[3]=k*(x+635);
	y4[3]=k*(y+495);
	
	x4[4]=k*(x+641);
	y4[4]=k*(y+502); 

	x4[5]=k*(x+643);
	y4[5]=k*(y+507);
	
	x4[6]=k*(x+648);
	y4[6]=k*(y+511);
	
	x4[7]=k*(x+654);
	y4[7]=k*(y+519);
	
	x4[8]=k*(x+656);
	y4[8]=k*(y+523);
	
	x4[9]=k*(x+658);
	y4[9]=k*(y+528);
	
	x4[10]=k*(x+662);
	y4[10]=k*(y+534);
	
	x4[11]=k*(x+664);
	y4[11]=k*(y+543);
	
	x4[12]=k*(x+665);
	y4[12]=k*(y+551);
	
	x4[13]=k*(x+664);
	y4[13]=k*(y+560);
	
	x4[14]=k*(x+663);
	y4[14]=k*(y+658);
	
	x4[15]=k*(x+664);
	y4[15]=k*(y+577);
	
	x4[16]=k*(x+660);
	y4[16]=k*(y+585);
	
	x4[17]=k*(x+659);
	y4[17]=k*(y+592);
	
	x4[18]=k*(x+657);
	y4[18]=k*(y+596);
	
	x4[19]=k*(x+654);
	y4[19]=k*(y+603);
	
	x4[20]=k*(x+639);
	y4[20]=k*(y+618);

	//把放缩后的顶点复原 
	for(i=0;i<21;i++)
	{
		x4[i]=x4[i]-(x+304)*(k-1);
		y4[i]=y4[i]-(y+618)*(k-1);
	}	
	if(j==0)
	{
	Bezier(color,21,page,x4,y4,0);
	}
	else
	{
		for(i=0;i<21;i++)
		{
			x4[i]=h-x4[i];
			y4[i]=y4[i];
		}			
		Bezier(color,21,page,x4,y4,0);
	}
	if(j==0)
	{
	line_drawing(k*(x+639)-(x+304)*(k-1),k*(y+618)-(y+618)*(k-1),k*(x+587)-(x+304)*(k-1),k*(y+618)-(y+618)*(k-1),color,page,1);	
	circle_without_drawing(k*(x+547)-(x+304)*(k-1),k*(y+618)-(y+618)*(k-1),40*k,color,page);	
	circle_without_drawing(k*(x+344)-(x+304)*(k-1),k*(y+618)-(y+618)*(k-1),40*k,color,page);
	circle_without_drawing(k*(x+547)-(x+304)*(k-1),k*(y+618)-(y+618)*(k-1),20*k,color,page);	
	circle_without_drawing(k*(x+344)-(x+304)*(k-1),k*(y+618)-(y+618)*(k-1),20*k,color,page);	
	}
	else
	{
		line_drawing(h-k*(x+639)+(x+304)*(k-1),k*(y+618)-(y+618)*(k-1),h-k*(x+587)+(x+304)*(k-1),k*(y+618)-(y+618)*(k-1),color,page,1);	
		circle_without_drawing(h-k*(x+547)+(x+304)*(k-1),k*(y+618)-(y+618)*(k-1),40*k,color,page);	
		circle_without_drawing(h-k*(x+344)+(x+304)*(k-1),k*(y+618)-(y+618)*(k-1),40*k,color,page);
		circle_without_drawing(h-k*(x+547)+(x+304)*(k-1),k*(y+618)-(y+618)*(k-1),20*k,color,page);	
		circle_without_drawing(h-k*(x+344)+(x+304)*(k-1),k*(y+618)-(y+618)*(k-1),20*k,color,page);
	}
	if(j==0)
	{
		line_drawing(k*(x+384)-(x+304)*(k-1),k*(y+618)-(y+618)*(k-1),k*(x+507)-(x+304)*(k-1),k*(y+618)-(y+618)*(k-1),color,page,1);	
	}
	else
		line_drawing(h-k*(x+384)+(x+304)*(k-1),k*(y+618)-(y+618)*(k-1),h-k*(x+507)+(x+304)*(k-1),k*(y+618)-(y+618)*(k-1),color,page,1);	
}

void car_light(int x,int y,float k,int color,int page,int j)
{
	int i=0;
	int x0[19];
	int y0[19];

	x=x-304;
	y=y-618; 
	int h= (k*(x+445)-(x+304)*(k-1))*2;
	x0[0]=k*(x+232);
	y0[0]=k*(y+567);
	
	x0[1]=k*(x+226);
	y0[1]=k*(y+563);
	
	x0[2]=k*(x+220);
	y0[2]=k*(y+556);
	
	x0[3]=k*(x+215);
	y0[3]=k*(y+552);
	
	x0[4]=k*(x+211);
	y0[4]=k*(y+547);
	
	x0[5]=k*(x+209);
	y0[5]=k*(y+540);
	
	x0[6]=k*(x+208);
	y0[6]=k*(y+532);
	
	x0[7]=k*(x+209);
	y0[7]=k*(y+524);
	
	x0[8]=k*(x+213);
	y0[8]=k*(y+516);
	
	x0[9]=k*(x+219);
	y0[9]=k*(y+508);
	
	x0[10]=k*(x+227);
	y0[10]=k*(y+504);
	
	x0[11]=k*(x+235);
	y0[11]=k*(y+504);
	
	x0[12]=k*(x+241);
	y0[12]=k*(y+503);
	
	x0[13]=k*(x+246);
	y0[13]=k*(y+501);
	
	x0[14]=k*(x+250);
	y0[14]=k*(y+503);
	
	x0[15]=k*(x+257);
	y0[15]=k*(y+507);
	
	x0[16]=k*(x+259);
	y0[16]=k*(y+508);
	
	x0[17]=k*(x+264);
	y0[17]=k*(y+508);
	
	x0[18]=k*(x+266);
	y0[18]=k*(y+512);
	
	//把放缩后的顶点复原 
	for(i=0;i<19;i++)
	{
		x0[i]=x0[i]-(x+304)*(k-1);
		y0[i]=y0[i]-(y+618)*(k-1);
	}	
	if(j==0)
	Bezier(color,19,page,x0,y0,0);
	else
	{
		for(i=0;i<19;i++)
		{
			x0[i]=h-x0[i];
			y0[i]=y0[i];
		}
		Bezier(color,19,page,x0,y0,0);			
	}
}

void car_windows(int x,int y,float k,int color,int page,int j)
{
	int i=0;
	int x0[14];
	int y0[14];
	
	int x1[14];
	int y1[14];
	
	
	x=x-304;
	y=y-618;
	 
	int h= (k*(x+445)-(x+304)*(k-1))*2;	
	
	x0[0]=k*(x+340);
	y0[0]=k*(y+495);
	
	x0[1]=k*(x+344);
	y0[1]=k*(y+482);
	
	x0[2]=k*(x+348);
	y0[2]=k*(y+472);
	
	x0[3]=k*(x+352);
	y0[3]=k*(y+462);
	
	x0[4]=k*(x+357);
	y0[4]=k*(y+454);
	
	x0[5]=k*(x+359);
	y0[5]=k*(y+448);
	
	x0[6]=k*(x+363);
	y0[6]=k*(y+442);
	
	x0[7]=k*(x+371);
	y0[7]=k*(y+438);
	
	x0[8]=k*(x+376);
	y0[8]=k*(y+433);
	
	x0[9]=k*(x+380);
	y0[9]=k*(y+431);
	
	x0[10]=k*(x+389);
	y0[10]=k*(y+427);
	
	x0[11]=k*(x+395);
	y0[11]=k*(y+426);
	
	x0[12]=k*(x+401);
	y0[12]=k*(y+424);
	
	x0[13]=k*(x+409);
	y0[13]=k*(y+422);
	
	
	//把放缩后的顶点复原 
	for(i=0;i<14;i++)
	{
		x0[i]=x0[i]-(x+304)*(k-1);
		y0[i]=y0[i]-(y+618)*(k-1);
	}	
	if(j==0)
	Bezier(color,14,page,x0,y0,0);	
	else
	{
	for(i=0;i<14;i++)
	{
		x0[i]=h-x0[i];
		y0[i]=y0[i];
	}		
		Bezier(color,14,page,x0,y0,0);		
	}
	x1[0]=k*(x+463);
	y1[0]=k*(y+422);
		
	x1[1]=k*(x+473);
	y1[1]=k*(y+422);
	
	x1[2]=k*(x+481);
	y1[2]=k*(y+423);
	
	x1[3]=k*(x+487);
	y1[3]=k*(y+423);
	
	x1[4]=k*(x+492);
	y1[4]=k*(y+424);
	
	x1[5]=k*(x+497);
	y1[5]=k*(y+427);
	
	x1[6]=k*(x+503);
	y1[6]=k*(y+431);
	
	x1[7]=k*(x+508);
	y1[7]=k*(y+434);
	
	x1[8]=k*(x+510);
	y1[8]=k*(y+436);
	
	x1[9]=k*(x+516);
	y1[9]=k*(y+439);
	
	x1[10]=k*(x+520);
	y1[10]=k*(y+444);
	
	x1[11]=k*(x+524);
	y1[11]=k*(y+448);
	
	x1[12]=k*(x+526);
	y1[12]=k*(y+489);
	
	x1[13]=k*(x+533);
	y1[13]=k*(y+495);

	//把放缩后的顶点复原 
	for(i=0;i<14;i++)
	{
		x1[i]=x1[i]-(x+304)*(k-1);
		y1[i]=y1[i]-(y+618)*(k-1);
	}	
	if(j==0)
	Bezier(color,14,page,x1,y1,0);	
	else
	{
	for(i=0;i<14;i++)
	{
		x1[i]=h-x1[i];
		y1[i]=y1[i];
	}
	Bezier(color,14,page,x1,y1,0);	
	}	
	if(j==0)
	{	
	line_drawing(k*(x+340)-(x+304)*(k-1),k*(y+495)-(y+618)*(k-1),k*(x+409)-(x+304)*(k-1),k*(y+495)-(y+618)*(k-1),color,page,1);	
	line_drawing(k*(x+409)-(x+304)*(k-1),k*(y+495)-(y+618)*(k-1),k*(x+409)-(x+304)*(k-1),k*(y+422)-(y+618)*(k-1),color,page,1);	
	line_drawing(k*(x+463)-(x+304)*(k-1),k*(y+422)-(y+618)*(k-1),k*(x+463)-(x+304)*(k-1),k*(y+495)-(y+618)*(k-1),color,page,1);	
	line_drawing(k*(x+463)-(x+304)*(k-1),k*(y+495)-(y+618)*(k-1),k*(x+533)-(x+304)*(k-1),k*(y+495)-(y+618)*(k-1),color,page,1);	
	}
	else
	{
	line_drawing(h-k*(x+340)+(x+304)*(k-1),k*(y+495)-(y+618)*(k-1),h-k*(x+409)+(x+304)*(k-1),k*(y+495)-(y+618)*(k-1),color,page,1);	
	line_drawing(h-k*(x+409)+(x+304)*(k-1),k*(y+495)-(y+618)*(k-1),h-k*(x+409)+(x+304)*(k-1),k*(y+422)-(y+618)*(k-1),color,page,1);	
	line_drawing(h-k*(x+463)+(x+304)*(k-1),k*(y+422)-(y+618)*(k-1),h-k*(x+463)+(x+304)*(k-1),k*(y+495)-(y+618)*(k-1),color,page,1);	
	line_drawing(h-k*(x+463)+(x+304)*(k-1),k*(y+495)-(y+618)*(k-1),h-k*(x+533)+(x+304)*(k-1),k*(y+495)-(y+618)*(k-1),color,page,1);	
		
	}


}

















