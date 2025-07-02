
#ifndef _Bezier_h_
#define _Bezier_h_

struct Vec2
{
	double x, y;
};

void ellipse_(int centerx, int centery, int a, int b, int color, int page, int offsetx, int offsety);
int get_n(int color, int* k, int i, int page);
void fill_1(int color, int page);
void fill(int x, int y, int color, int page, int status);
void Bezier(int color, const unsigned int length, int page, int* x, int* y, int status);

#endif 
