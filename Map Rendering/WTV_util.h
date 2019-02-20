#ifndef __WTV_UTIL_HPP__
#define __WTV_UTIL_HPP__

#include <linux/fb.h>
#include <fstream>

#include "WTV_objects.h"

using namespace std;

void clear_screen(unsigned int x_size, unsigned int y_size, char * framebuffer, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
void bresenham(int x0, int y0, int x1, int y1, struct RGB color, char * framebuffer, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
void pixel_color(int x, int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo, struct RGB rgb);
vector<Object *> read_file();
char checkPixelAround(int x, int y, char * fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
void rasterScan(int x_min, int y_min, int x_max, int y_max, char colorful, char * fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);

#endif
