#ifndef __PLANE_HPP__
#define __PLANE_HPP__
#include "../util/class_util.h"
#include "../util/func_util.h"

using namespace std;

class Plane : public Renderable {
    public:
        Plane(int x, int y, int offset_x, int offset_y);
        virtual ~Plane();

        int getOffsetX();
        void setOffsetX(int offset_x);
	int getOffsetY();
        void setOffsetY(int offset_y);

        void move(struct fb_var_screeninfo vinfo);
	void moveUp(struct fb_var_screeninfo vinfo);
	void moveDown(struct fb_var_screeninfo vinfo);
        void render(char* fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
    private:
        int offset_x;
	int offset_y;
	char way;
};

class PlanePiece : public Plane {
    public:
        PlanePiece(int x, int y, int offset_x, int offset_y);
        ~PlanePiece();

        void render(char* fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
};

#endif
