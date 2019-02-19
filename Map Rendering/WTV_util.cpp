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
            long int mem_location = (x1 + vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y + vinfo.yoffset) * finfo.line_length;

            pixel_color(framebuffer,mem_location,rgb.b,rgb.g,rgb.r);
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

                    pixel_color(framebuffer,mem_location,rgb.b,rgb.g,rgb.r);

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

                    pixel_color(framebuffer,mem_location,rgb.b,rgb.g,rgb.r);

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

                    pixel_color(framebuffer,mem_location,rgb.b,rgb.g,rgb.r);

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

                    pixel_color(framebuffer,mem_location,rgb.b,rgb.g,rgb.r);

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

void pixel_color(char *fbp, long int location, int b, int g, int r){
    *(fbp + location) = b;         // blue
    *(fbp + location + 1) = g;     // green
    *(fbp + location + 2) = r;     // red
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
                object->addPoint(new Point(x0+50,y0+200));
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