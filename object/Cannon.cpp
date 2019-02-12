#include "Cannon.h"

// ******** Cannon Class Implementation ********
Cannon::Cannon(int x, int y, int radius) : Renderable(x,y){
    this->radius = radius;
};
Cannon::~Cannon() { };

int Cannon::getRadius(){
    return radius;
};
void Cannon::setRadius(int radius){
    this->radius = radius;
};

void Cannon::render(char* fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    int x = this->getX();
    int y = this->getY();

    halfcircleBres(x,y,radius,fbp,vinfo,finfo);
    bresenham(x-radius, y, x+radius, y,false,fbp,vinfo,finfo);
};
