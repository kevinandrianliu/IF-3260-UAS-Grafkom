#ifndef __WTV_OBJECTS_HPP__
#define __WTV_OBJECTS_HPP__

#include <vector>

using namespace std;

struct RGB {
    char r;
    char g;
    char b;
};

class View {
    public:
        View(int x_min, int y_min, int x_max, int y_max, struct RGB rgb);
        ~View();

        int getXMin();
        int getYMin();
        int getXMax();
        int getYMax();
        void setXMin(int x_min);
        void setYMin(int y_min);
        void setXMax(int x_max);
        void setYMax(int y_max);

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
        void render_to_view(View * view, View * window, View * clip, char * framebuffer, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
        void render(char * fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
    
        vector<Point *> point_vector;
};

#endif