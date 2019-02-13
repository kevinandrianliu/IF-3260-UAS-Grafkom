#ifndef __CANNONBULLET_HPP__
#define __CANNONBULLET_HPP__
#include "Plane.h"
#include "PlaneBullet.h"

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
        bool checkCollision(class PlaneBullet& bullet);
    private:
        int offset;
        unsigned char selection;
};

#endif
