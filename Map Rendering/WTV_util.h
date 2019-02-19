#ifndef __WTV_UTIL_HPP__
#define __WTV_UTIL_HPP__

#include <linux/fb.h>
#include <fstream>

#include "WTV_objects.h"

using namespace std;

void clear_screen(unsigned int x_size, unsigned int y_size, char * framebuffer, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
void bresenham(int x0, int y0, int x1, int y1, struct RGB color, char * framebuffer, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
void pixel_color(char *fbp, long int location, int b, int g, int r);
vector<Object *> read_file();

#endif