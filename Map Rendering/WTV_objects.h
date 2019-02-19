#ifndef __WTV_OBJECTS_HPP__
#define __WTV_OBJECTS_HPP__

#include <vector>
#include "WTV_util.h"

using namespace std;

class View {
    public:
        View(int x_min, int y_min, int x_max, int y_max, struct RGB rgb);
        ~View();

        void render(char * framebuffer, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
    private:
        int x_min;
        int y_min;
        int x_max;
        int y_max;
        struct RGB rgb;
};

class Point {
    public:
        Point(int x, int y);
        ~Point();

        int getX();
        int getY();
        void setX(int x);
        void setY(int y);

    private:
        int x;
        int y;

};

class Object {
    public:
        Object();
        ~Object();

        void addPoint(Point * p);
        void printPoints();
    private:
        vector<Point *> *point_vector;
};

#endif