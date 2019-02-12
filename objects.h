#ifndef __OBJECTS_HPP__
#define __OBJECTS_HPP__
#include "util/class_util.h"

using namespace std;

class CannonBullet : public Renderable {
    public:
        CannonBullet(int x, int y, unsigned char selection);
        ~CannonBullet();

        int getOffset();
        unsigned char getSelection();
        void setOffset(int offset);
        void setSelection(unsigned char selection);

        void render(char* fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
        bool checkIfShot(class Plane& plane);
    private:
        int offset;
        unsigned char selection;
};

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
};

class PlanePiece : public Plane {
    public:
        PlanePiece(int x, int y, int offset_x, int offset_y);
        ~PlanePiece();

        void render(char* fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
};

class Blast : public Renderable {
    public:
        Blast(int x, int y, int size);
        ~Blast();

        int getSize();
        void setSize(int size);

        void render(char* fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);

    private:
        int size;
};

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
