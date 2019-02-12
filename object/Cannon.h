#ifndef __CANNON_HPP__
#define __CANNON_HPP__
#include "../util/class_util.h"
#include "../util/func_util.h"

using namespace std;

class Cannon : public Renderable {
    public:
        Cannon(int x, int y, int radius);
        ~Cannon();

        int getRadius();
        void setRadius(int radius);

        void render(char* fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
    private:
        int radius;
};

#endif
