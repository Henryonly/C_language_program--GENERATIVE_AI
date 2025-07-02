#ifndef _allo_h_
#define _allo_h_

void allo(int* x,int* y,float* k,int page,int* posi,int* p0,int* xy0,int* judge);

void put_picture_car1(int* posi,int* judge,int page,int color);//×ó 
void put_picture_car2(int* posi,int* judge,int page,int color);//ÓÒ 

void put_picture_boy(int* posi,int* judge,int page,int color);

void put_picture_dog1(int* posi,int* judge,int page,int color);//ÓÒ 
void put_picture_dog2(int* posi,int* judge,int page,int color);//×ó 

void put_picture_dog1_fill(int* posi,int* judge,int page,int color);//ÓÒ 
void put_picture_dog2_fill(int* posi,int* judge,int page,int color);

void put_picture_fish1(int* posi,int* judge,int page,int color);//×ó 
void put_picture_fish2(int* posi,int* judge,int page,int color);//ÓÒ 

void put_picture_mountain(int* posi,int* judge,int page,int color);
void put_picture_water(int* posi,int* judge,int page,int color);
void put_picture_cloud(int* posi,int* judge,int page,int color);

void secure(int* posi); 


#endif
