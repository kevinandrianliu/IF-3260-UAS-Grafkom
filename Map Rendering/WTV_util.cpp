#include "WTV_util.h"

#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>

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

void bresenham(int x0, int y0, int x1, int y1, struct RGB rgb, char * framebuffer, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    
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
        if (y0 > y1){
            int x_temp;
            int y_temp;

            x_temp = x0;
            y_temp = y0;
            x0 = x1;
            y0 = y1;
            x1 = x_temp;
            y1 = y_temp;
        }

        for (int y = y0; y <= y1; y++){
            pixel_color(x1, y, framebuffer, vinfo, finfo, rgb);
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
                    pixel_color(x, y, framebuffer, vinfo, finfo, rgb);

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
                    pixel_color(x, y, framebuffer, vinfo, finfo, rgb);

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
                    pixel_color(x, y, framebuffer, vinfo, finfo, rgb);

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
                    pixel_color(x, y, framebuffer, vinfo, finfo, rgb);

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

void pixel_color(int x, int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo, struct RGB rgb){
    long int location = (x + vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y - 1 + vinfo.yoffset) * finfo.line_length;

    *(fbp + location) = rgb.b;         // blue
    *(fbp + location + 1) = rgb.g;     // green
    *(fbp + location + 2) = rgb.r;     // red
    *(fbp + location + 3) = 0;
}

vector<Object *> read_file(){
    ifstream fileInput;
    fileInput.open("./map.txt");
    int x0, y0;
    string line;
    Object *object = nullptr;
    vector<Object *> object_vector;

    if (fileInput.is_open())
    {
        while ( getline (fileInput,line) )
        {
            fileInput >> x0 >> y0;
            //scout << x0;
            if ((x0 == 9999) && (y0 == 9999)){
                if (object != nullptr){
                    object_vector.push_back(object);
                    object = nullptr;
                }
            } else {
                if (object == nullptr){
                    object = new Object();
                }
                object->addPoint(new Point(x0+50,y0+50));
            }
            //cout << line << '\n';
        }
        fileInput.close();
    } else {
        cout << "Unable to open file";
    }

    cout << object_vector.size() << endl;
    return object_vector;
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

// void rasterScan(int x_min, int y_min, int x_max, int y_max, char colorful, char * fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
// 	char fill_flag = 0;  // 0 = Don't fill, 1 = Fill
//     long int mem_location;

//     // Assumes x is not filled from the top or bottom of screen
//     for (int j = y_min; j <= y_max; j++){
//         for (int i = x_min; i <= x_max; i++){
//             mem_location = (i + vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (j + vinfo.yoffset) * finfo.line_length;

//             if ((*(fbp + mem_location) || *(fbp + mem_location + 1) || *(fbp + mem_location + 2)) == 0x00){
//                 if (fill_flag){
//                     if (colorful){
//                         pixel_color(fbp,mem_location,(i % 255),(j % 255), ((j-i) % 255));
//                     } else {
//                         pixel_color(fbp,mem_location,255,255,255);
//                     }
//                 }
//             } else {
//                 if (checkPixelAround(i, j, fbp, vinfo, finfo)){
//                     if (fill_flag) {
//                         if (colorful){
//                             pixel_color(fbp,mem_location,(i % 255),(j % 255), ((j-i) % 255));
//                         } else {
//                             pixel_color(fbp,mem_location,255,255,255);
//                         }
//                     }

//                     fill_flag = !(fill_flag);
//                 }
//             }
//         }
//     }
// }
