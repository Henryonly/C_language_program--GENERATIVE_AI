#ifndef _pregi_h_
#define _pregi_h_

int register_picture(int page);
void register_color_change_mouse(int i,int page);
int check_law(char *input,int page);
int check_password(char *arr1,char *arr2,int page);
int check_password1(char *arr1,char *arr2,int page);
void text_register(char *arr1,char *arr2);
void color_change_back_mouse(int i,int page);
void back_register_color(int i,int page);
int page_test();
int page_chat2();
int page_exit();
void clean_chat1();
void clean_chat2();

#endif
