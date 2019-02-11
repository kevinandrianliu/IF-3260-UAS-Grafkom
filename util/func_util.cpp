#include "func_util.h"
#include <cmath>

using namespace std;

void clear_screen(unsigned int x_size, unsigned int y_size, char * framebuffer, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    long int mem_location;

    for (int y = 0; y < y_size; y++){
        for (int x = 0; x < x_size; x++){
            mem_location = (x + vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y + vinfo.yoffset) * finfo.line_length;

            *(framebuffer + mem_location) = 0;
            *(framebuffer + mem_location + 1) = 0;
            *(framebuffer + mem_location + 2) = 0;
            *(framebuffer + mem_location + 3) = 0;
        }
    }
}

void bresenham(int x0, int y0, int x1, int y1, char colorful, char * framebuffer, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    
    // Swaps the points if first point is on the right of second point
    if (x0 > x1){
        int x_temp;
        int y_temp;

        x_temp = x0;
        y_temp = y0;
        x0 = x1;
        y0 = y1;
        x1 = x_temp;
        y1 = y_temp;
    }

    // Checks if the points make vertical line
    if ((x1 - x0) == 0){
        for (int y = y0; y <= y1; y++){
            long int mem_location = (x1 + vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y + vinfo.yoffset) * finfo.line_length;

            if (colorful){
                pixel_color(framebuffer,mem_location,(x1 % 255),(y % 255), ((y-x1) % 255));
            } else {
                pixel_color(framebuffer,mem_location,255,255,255);
            }
        }
    } else {
        float gradien = (y1 - y0)/(x1 - x0);
        if ((abs(gradien) >= 0) && (abs(gradien) <= 1)){
        // Line made are close to x-axis
            int y = y0;
            int eps = 0;

            if (y1 >= y0){
                int dx = x1 - x0;
                int dy = y1 - y0;
                for (int x = x0; x <= x1; x++){
                    long int mem_location = (x + vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y + vinfo.yoffset) * finfo.line_length;

                    if (colorful){
                        pixel_color(framebuffer,mem_location,(x % 255),(y % 255), ((y-x) % 255));
                    } else {
                        pixel_color(framebuffer,mem_location,255,255,255);
                    }

                    eps += dy;
                    if ((eps << 1) >= dx){
                        y++;
                        eps -= dx;
                    }
                }
            } else {    //y1 < y0
                int dx = x1 - x0;
                int dy = y0 - y1;
                for (int x = x0; x <= x1; x++){
                    long int mem_location = (x + vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y + vinfo.yoffset) * finfo.line_length;

                    if (colorful){
                        pixel_color(framebuffer,mem_location,(x % 255),(y % 255), ((y-x) % 255));
                    } else {
                        pixel_color(framebuffer,mem_location,255,255,255);
                    }

                    eps += dy;
                    if ((eps << 1) >= dx){
                        y--;
                        eps -= dx;
                    }
                }
            }
        } else {
        // Line made are close to y-axis
            int x = x0;
            int eps = 0;

            if (y1 >= y0){
                int dx = x1 - x0;
                int dy = y1 - y0;

                for (int y = y0; y <= y1; y++){
                    long int mem_location = (x + vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y + vinfo.yoffset) * finfo.line_length;

                    if (colorful){
                        pixel_color(framebuffer,mem_location,(x % 255),(y % 255), ((y-x) % 255));
                    } else {
                        pixel_color(framebuffer,mem_location,255,255,255);
                    }

                    eps += dx;
                    if ((eps << 1) >= dy){
                        x++;
                        eps -= dy;
                    }
                }
            } else {    //y1 < y0
                int dx = x1 - x0;
                int dy = y0 - y1;

                for (int y = y0; y >= y1; y--){
                    long int mem_location = (x + vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y + vinfo.yoffset) * finfo.line_length;

                    if (colorful){
                        pixel_color(framebuffer,mem_location,(x % 255),(y % 255), ((y-x) % 255));
                    } else {
                        pixel_color(framebuffer,mem_location,255,255,255);
                    }

                    eps += dx;
                    if ((eps << 1) >= dy){
                        x++;
                        eps -= dy;
                    }
                }
            }
        }
    }
}

// Function to put pixels 
// at subsequence points 
void drawCircle(int xc, int yc, int x, int y, char * framebuffer, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo) 
{
    long int memory_location;

    memory_location = (xc + x + vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yc - y + vinfo.yoffset) * finfo.line_length;
    pixel_color(framebuffer, memory_location, 255, 255, 255);

    memory_location = (xc - x + vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yc - y + vinfo.yoffset) * finfo.line_length;
    pixel_color(framebuffer, memory_location, 255, 255, 255);

    memory_location = (xc + y + vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yc - x + vinfo.yoffset) * finfo.line_length;
    pixel_color(framebuffer, memory_location, 255, 255, 255);

    memory_location = (xc - y + vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yc - x + vinfo.yoffset) * finfo.line_length;
    pixel_color(framebuffer, memory_location, 255, 255, 255);
}
  
// Function for circle-generation 
// using Bresenham's algorithm 
void halfcircleBres(int xc, int yc, int r, char * framebuffer, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo) 
{ 
    int x = 0, y = r; 
    int d = 3 - 2 * r; 
    drawCircle(xc, yc, x, y, framebuffer, vinfo, finfo); 
    while (y >= x) 
    { 
        // for each pixel we will 
        // draw all eight pixels 
          
        x++; 
  
        // check for decision parameter 
        // and correspondingly  
        // update d, x, y 
        if (d > 0) 
        { 
            y--;  
            d = d + 4 * (x - y) + 10; 
        } 
        else {d = d + 4 * x + 6;} 
        drawCircle(xc, yc, x, y, framebuffer, vinfo, finfo); 
    }
}

void pixel_color(char *fbp, long int location, int b, int g, int r){
    *(fbp + location) = b;         // blue
    *(fbp + location + 1) = g;     // green
    *(fbp + location + 2) = r;     // red
    *(fbp + location + 3) = 0;
}

char checkPixelAround(int x, int y, char * fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    long int mem_location;
    int max_x;

    char pixel_up = false;
    char pixel_down = false;

    for (int i = x-1; i < x + 2; i++){
        if (!(pixel_up)){
            mem_location = (i + vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y - 1 + vinfo.yoffset) * finfo.line_length;
            if ((*(fbp + mem_location) || *(fbp + mem_location + 1) || *(fbp + mem_location + 2)) > 0x00){
                pixel_up = true;
            }
        }
        if (!(pixel_down)){
            mem_location = (i + vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y + 1 + vinfo.yoffset) * finfo.line_length;
            if ((*(fbp + mem_location) || *(fbp + mem_location + 1) || *(fbp + mem_location + 2)) > 0x00){
                pixel_down = true;
            }
        }
    }

    return (pixel_up && pixel_down);
}

void rasterScan(int x_min, int y_min, int x_max, int y_max, char colorful, char * fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
	char fill_flag = 0;  // 0 = Don't fill, 1 = Fill
    long int mem_location;

    // Assumes x is not filled from the top or bottom of screen
    for (int j = y_min; j <= y_max; j++){
        for (int i = x_min; i <= x_max; i++){
            mem_location = (i + vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (j + vinfo.yoffset) * finfo.line_length;

            if ((*(fbp + mem_location) || *(fbp + mem_location + 1) || *(fbp + mem_location + 2)) == 0x00){
                if (fill_flag){
                    if (colorful){
                        pixel_color(fbp,mem_location,(i % 255),(j % 255), ((j-i) % 255));
                    } else {
                        pixel_color(fbp,mem_location,255,255,255);
                    }
                }
            } else {
                if (checkPixelAround(i, j, fbp, vinfo, finfo)){
                    if (fill_flag) {
                        if (colorful){
                            pixel_color(fbp,mem_location,(i % 255),(j % 255), ((j-i) % 255));
                        } else {
                            pixel_color(fbp,mem_location,255,255,255);
                        }
                    }

                    fill_flag = !(fill_flag);
                }
            }
        }
    }
}
