#include "Cannon.h"

// ******** Cannon Class Implementation ********
Cannon::Cannon(int x, int y, int radius, char turret_selection) : Renderable(x,y){
    this->radius = radius;
    this->turret_selection = turret_selection;
};
Cannon::~Cannon() { };

int Cannon::getRadius(){
    return radius;
};
char Cannon::getTurretSelection(){
    return turret_selection;
};
void Cannon::setRadius(int radius){
    this->radius = radius;
};
void Cannon::setTurretSelection(char turret_selection){
    this->turret_selection = turret_selection;
};

void Cannon::render(char* fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    int x = this->getX();
    int y = this->getY();

    halfcircleBres(x,y,radius,fbp,vinfo,finfo);
    bresenham(x-radius, y, x+radius, y,false,fbp,vinfo,finfo);

    switch (turret_selection){
        case 0:
            bresenham(307,450,335,495,0,fbp,vinfo,finfo);
            bresenham(298,462,307,450,0,fbp,vinfo,finfo);
            bresenham(298,462,327,510,0,fbp,vinfo,finfo);
            break;
        case 1:
            bresenham(352,424,365,460,0,fbp,vinfo,finfo);
            bresenham(337,430,352,424,0,fbp,vinfo,finfo);
            bresenham(337,430,352,468,0,fbp,vinfo,finfo);
            break;
        case 2:
            bresenham(392,415,392,450,0,fbp,vinfo,finfo);
            bresenham(392,415,407,415,0,fbp,vinfo,finfo);
            bresenham(407,415,407,450,0,fbp,vinfo,finfo);
            break;
        case 3:
            bresenham(448,424,435,460,0,fbp,vinfo,finfo);
            bresenham(463,430,448,424,0,fbp,vinfo,finfo);
            bresenham(463,430,448,468,0,fbp,vinfo,finfo);
            break;
        case 4:
            bresenham(493,450,465,479,0,fbp,vinfo,finfo);
            bresenham(503,469,493,450,0,fbp,vinfo,finfo);
            bresenham(502,462,473,493,0,fbp,vinfo,finfo);
            break;
    }
};
