#include "CannonBullet.h"

// ******** CannonBullet Class Implementation ********
CannonBullet::CannonBullet(int x, int y, unsigned char selection) : Renderable(x,y) {
    this->selection = selection;
    this->offset = false;
};
CannonBullet::~CannonBullet() { };

int CannonBullet::getOffset(){
    return offset;
};
unsigned char CannonBullet::getSelection(){
    return selection;
};
void CannonBullet::setOffset(int offset){
    this->offset = offset;
};
void CannonBullet::setSelection(unsigned char selection){
    this->selection = selection;
};
void CannonBullet::render(char* fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    int x = this->getX();
    int y = this->getY();

    switch (selection){
        case false:
            x -= offset/1.5;
            break;
        case 1:
            x -= offset/2;
            break;
        case 2:
            break;
        case 3:
            x += offset/2;
            break;
        case 4:
            x += offset/1.5;
            break;
        default:
            break;
    }
    y -= offset;

    bresenham(x-7, y  , x  , y-7,true,fbp,vinfo,finfo);
    bresenham(x  , y-7, x+7, y  ,true,fbp,vinfo,finfo);
    bresenham(x+7, y  , x  , y+7,true,fbp,vinfo,finfo);
    bresenham(x  , y+7, x-7, y  ,true,fbp,vinfo,finfo);

	rasterScan(x-7, y-7, x+7, y+7, 1, fbp, vinfo, finfo);

    offset++;
};
bool CannonBullet::checkIfShot(class Plane& plane){
    int x = this->getX();
    int y = this->getY();

    switch (selection){
        case false:
            x -= offset/1.5;
            break;
        case 1:
            x -= offset/2;
            break;
        case 2:
            break;
        case 3:
            x += offset/2;
            break;
        case 4:
            x += offset/1.5;
            break;
        default:
            break;
    }
    y -= offset;

    int bullet_x_max = x + 7;
    int bullet_x_min = x - 7;
    int bullet_y_min = y - 7;

    int plane_x_max = plane.getX() + plane.getOffsetX() + 50 + 25;
    int plane_x_min = plane.getX() + plane.getOffsetX() + 50 - 80;
    int plane_y_max = plane.getY() + plane.getOffsetY() + 41;

    if ((bullet_x_max <= plane_x_max) && (bullet_x_max >= plane_x_min) && (bullet_y_min <= plane_y_max)){
        return true;
    }
    if ((bullet_x_min <= plane_x_max) && (bullet_x_min >= plane_x_min) && (bullet_y_min <= plane_y_max)){
        return true;
    }
    return false;
};
