#include "PlaneBullet.h"

// ******** PlaneBullet Class Implementation ********
PlaneBullet::PlaneBullet(int x, int y, int x_origin, int y_origin) : Renderable(x,y){
    this->x_origin = x_origin;
    this->y_origin = y_origin;
};
PlaneBullet::~PlaneBullet() { };

void PlaneBullet::move(){
//void PlaneBullet::move(class Cannon& cannon){
    //int new_x_pos = this->getX() + 1;

    //this->setX(new_x_pos);
    this->setY(this->getY()+ 1);
    //this->setY(equation(cannon,new_x_pos));
};
void PlaneBullet::render(char* fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    int x = this->getX();
    int y = this->getY();

    bresenham(x-7, y  , x  , y-7,true,fbp,vinfo,finfo);
    bresenham(x  , y-7, x+7, y  ,true,fbp,vinfo,finfo);
    bresenham(x+7, y  , x  , y+7,true,fbp,vinfo,finfo);
    bresenham(x  , y+7, x-7, y  ,true,fbp,vinfo,finfo);
	rasterScan(x-7, y-7, x+7, y+7, false, fbp, vinfo, finfo);
};
bool PlaneBullet::checkIfCollide(class Cannon& cannon){
    int x_min = cannon.getX() - cannon.getRadius();
    int y_min = cannon.getY() - cannon.getRadius();
    int x_max = cannon.getX() + cannon.getRadius();;
    int y_max = cannon.getY();

    int plane_bullet_x_pos = this->getX();
    int plane_bullet_y_pos = this->getY();

    if (plane_bullet_x_pos >= x_min && plane_bullet_x_pos <= x_max && plane_bullet_y_pos >= y_min && plane_bullet_y_pos <= y_max){
        return true;
    }
    return false;
};

/*
int PlaneBullet::equation(class Cannon& cannon, int x){
    int cannon_x_pos = cannon.getX();
    int cannon_y_pos = cannon.getY();

    return ((x * (cannon_y_pos - y_origin) - x_origin * cannon_y_pos + y_origin * cannon_x_pos) / (cannon_x_pos - x_origin));
};*/
