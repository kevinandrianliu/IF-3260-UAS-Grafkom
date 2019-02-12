#ifndef __OBJECTS_HPP__
#define __OBJECTS_HPP__
#include "../util/class_util.h"
#include "Cannon.h"

using namespace std;

class PlaneBullet : public Renderable {
    public:
        PlaneBullet(int x, int y, int x_origin, int y_origin);
        ~PlaneBullet();

        void move();
        void render(char* fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
        bool checkIfCollide(class Cannon& cannon);
    private:
        //int equation(class Cannon& cannon, int x);

        int x_origin;
        int y_origin;
};

#endif
