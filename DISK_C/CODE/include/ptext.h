
#ifndef _ptext_h_
#define _ptext_h_

#define USER 0
#define ROBOT 1

#define WORDWIDTH 32
#define TEXTWIDTH 704
#define TEXTWORD 22

#define ELLIPSEA 50
#define ELLIPSEB 55

#define FILL_STATUS 0
#define NONFILL_STATUS 1//bug?可能需要第三个标志位，不然会不会如果没有呈现，就大水漫灌了? 
#define NONNONFILL_STATUS 2

void robot_avatar(int x,int y,int page);
void user_avatar(int x,int y,int page);
void text_rectangle(int ROM,int mode,int page,int y,int sum,int status);
void draw_final0(char *diaplay,int height,int y,int page,int status);
void draw_final1(char *diaplay,int height,int y,int page,int status);

#endif
