#ifndef __CLASS_UTIL_HPP__
#define __CLASS_UTIL_HPP__
#include <linux/fb.h>
#include <iostream>

using namespace std;

class Renderable {
    public:
        Renderable(int x, int y);
        virtual ~Renderable();
        int getX();
        int getY();
        void setX(int x);
        void setY(int y);

        virtual void render(char* fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo) = 0;

    private:
        int x;
        int y;
};

#endif