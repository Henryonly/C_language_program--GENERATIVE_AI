#ifndef _printbase_h_
#define _printfbase_h_

#define XMAX 1024
#define YMAX 768
/*
typedef struct
{
	unsigned char TRANSPARENT;
	unsigned char BLUE;
	unsigned char GREEN;
	unsigned char RED;
}COLORBIN;
*/
void start_SVGA();
int examine_start_SVGA();
void pageturn(register int page);
int point_drawing(int x,int y,int color,int page);
int picture_input(int x,int y,const char* path);
int line_drawing(int x1,int y1,int x2,int y2,int color,int page,int status);//status=1,则为对话框绘制 
void circle_without_drawing(int x,int y,int r,int color,int page);
void circle_with_drawing(int x,int y,int r,int color,int page,int status);
void exit_SVGA(); 
void fill_color(int x1,int y1,int x2,int y2,int color,int page,int status);

#endif
