#include "WTV_objects.h"
#include "WTV_util.h"
#include <iostream>

using namespace std;

View::View(int x_min, int y_min, int x_max, int y_max, struct RGB rgb){
    this->x_min = x_min;
    this->y_min = y_min;
    this->x_max = x_max;
    this->y_max = y_max;
    this->rgb = rgb;
};
View::~View() { };

void View::render(char * framebuffer, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    bresenham(x_min, y_min, x_max, y_min, rgb, framebuffer, vinfo, finfo);
    bresenham(x_max, y_min, x_max, y_max, rgb, framebuffer, vinfo, finfo);
    bresenham(x_max, y_max, x_min, y_max, rgb, framebuffer, vinfo, finfo);
    bresenham(x_min, y_min, x_min, y_max, rgb, framebuffer, vinfo, finfo);
};

Point::Point(int x, int y){
    this->x = x;
    this->y = y;
};

int Point::getX(){
    return x;
};
int Point::getY(){
    return y;
};
void Point::setX(int x){
    this->x = x;
};
void Point::setY(int y){
    this->y = y;
}

Object::Object(){
    this->point_vector = new vector<Point *>();
};

Object::~Object(){
    while (point_vector->size() > 0){
        point_vector->erase(point_vector->begin());
    }

    delete(point_vector);
};

void Object::addPoint(Point * p){
    point_vector->push_back(p);
}

void Object::printPoints(){
    for (vector<Point *>::iterator it = point_vector->begin(); it != point_vector->end(); it++){
        cout << (*it)->getX() << ", " << (*it)->getY() << endl;
    }
}