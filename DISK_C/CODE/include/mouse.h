#ifndef _mouse_h_
#define _mouse_h_

void mouseinit(int page);
void mouse_drawing(int x,int y,int page);
void mread(int *nx,int *ny,int *nbuttons);
void newmouse(int *nx,int *ny,int *nbuttons,int page);
void save_bk_mou(int nx,int ny);
void clrmous(int nx,int ny,int page);
void drawmous(int nx,int ny,int page);
void UpdateMouse(int forceRefresh,int page); 
int mouse_press(int x1,int y1,int x2,int y2);
void memory_mouse(int x,int y,int page);
void truly_clean_mouse(int x,int y,int page);
int get_pixel_color(int x, int y, int page);

#endif
