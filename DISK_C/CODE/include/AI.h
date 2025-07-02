
#ifndef _AI_h
#define _AI_h

#define ROBOT_ROLE 0
#define USER_ROLE 1

void entrance(int page,int* keyboard,int status,int* input_counter);
int text_height(char input[51][421]);
int text_jushu(char input[51][421]);
int text_position(int height,int pianyi);
int display_text(char input[51][421],int pianyi,int page,int keyboard);
int pianyiliang(int sum_height,int height,int keyboard);

#endif
