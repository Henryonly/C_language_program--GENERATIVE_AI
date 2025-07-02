
#ifndef _hz_h_
#define _hz_h_

//以下头文件如总头文件中已包含则不用，在hz.c中包括头文件即可
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<graphics.h>
#include<math.h>
#include<bios.h>
#include<conio.h>
#include<dos.h>
#include<mouse.h>
#include<input.h>
#include<draw.h>
#include<color.h>
#include<xiezi.h>
#include<English.h>

#define NUM0 0x5230
#define NUM1 0x4f31
#define NUM2 0x5032
#define NUM3 0x5133
#define NUM4 0x4134
#define NUM5 0x4c35
#define NUM6 0x4d36
#define NUM7 0x4737
#define NUM8 0x4838
#define NUM9 0x4939
#define F2 0x3c00
#define F3 0x3d00
#define F4 0x3e00
#define F5 0x3f00
#define F6 0x4000
#define F7 0x4100
#define F8 0x4200
#define F9 0x4300
#define F10 0x4400
#define F1 0x3b00
#define ENTER 0x1c0d
#define BACK 0x0e08
#define ESC 0x011b
#define UP 0x4800
#define DOWN 0x5000
#define RIGHT 0x4d00
#define LEFT 0x4b00
#define ONE 0x0231
#define TWO 0x0332
#define THREE 0x0433
#define FOUR 0x0534
#define FIVE 0x0635
#define SIX 0x0736
#define SEVEN 0x0837
#define EIGHT 0x0938
#define NINE 0x0a39
#define ZERO 0x0b30
#define DELETE 0x5300
#define SPACE 0x3920

#define LASTLINE 0x1a5b
#define NEXTLINE 0x1b5d

#define FIRST 0x0231
#define SECOND 0x0332
#define THIRD 0x0433
#define FOURTH 0x0534

#define MAXPY 8
#define FAIL 0
#define SUCCESS 1

#define KEY_A 0x1e61
#define KEY_D 0x2064

int input_method(int x, int y, char *str, int value, char *py, int page, int* choose, int *keyboard, int* pianyi,char* inputinput,int* input_counter);
char *itostr(int a,char *s);
void pyFrm(int x1,int y1,int x2,int y2,int page);
void memory_hz(int x,int y,int color[201][41],int page);
void clean_hz(int x,int y,int color[201][41],int page);

#endif
