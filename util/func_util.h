#ifndef __FUNC_UTIL_HPP__
#define __FUNC_UTIL_HPP__

#include <linux/fb.h>

using namespace std;

void clear_screen(unsigned int x_size, unsigned int y_size, char * framebuffer, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);

void bresenham(int x0, int y0, int x1, int y1, char colorful, char * framebuffer, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);

void drawCircle(int xc, int yc, int x, int y, char * framebuffer, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
void halfcircleBres(int xc, int yc, int r, char * framebuffer, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);

void pixel_color(char *fbp, long int location, int b, int g, int r);
#endif