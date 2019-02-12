#ifndef __PLANE_HPP__
#define __PLANE_HPP__
#include "../util/class_util.h"
#include "../util/func_util.h"

using namespace std;

class Plane : public Renderable {
    public:
        Plane(int x, int y, int offset);
        virtual ~Plane();

        int getOffset();
        void setOffset(int offset);

        void move(struct fb_var_screeninfo vinfo);
        void render(char* fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
    private:
        int offset;
		char way;
};

class PlanePiece : public Plane {
    public:
        PlanePiece(int x, int y, int offset);
        ~PlanePiece();

        void render(char* fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
};

#endif
