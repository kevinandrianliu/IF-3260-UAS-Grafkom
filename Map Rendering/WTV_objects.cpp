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

int View::getXMin(){ return x_min; };
int View::getYMin(){ return y_min; };
int View::getXMax(){ return x_max; };
int View::getYMax(){ return y_max; };
void View::setXMin(int x_min){ this->x_min = x_min; };
void View::setYMin(int y_min){ this->y_min = y_min; };
void View::setXMax(int x_max){ this->x_max = x_max; };
void View::setYMax(int y_max){ this->y_max = y_max; };

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
    
};

Object::~Object(){
    while (point_vector.size() > 0){
        point_vector.erase(point_vector.begin());
    }
};

void Object::addPoint(Point * p){
    point_vector.push_back(p);
};

void Object::printPoints(){
    for (vector<Point *>::iterator it = point_vector.begin(); it != point_vector.end(); it++){
        cout << (*it)->getX() << ", " << (*it)->getY() << endl;
    }
};

void Object::render_to_view(View * view, View * window, View * clip, char * fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    int x_offset = (*view).getXMin() - (*window).getXMin();

    int size = point_vector.size();
    int i = 1;
    struct RGB rgb;
    rgb.r = rgb.b = rgb.g = 255;
    int x_min = 999999;
    int y_min = 999999;
    int x_max = -999999;
    int y_max = -999999;
    while (i < size){
        int x1 = point_vector[i-1]->getX() * ((*view).getXMax() - (*view).getXMin()) / ((*clip).getXMax() - (*clip).getXMin()) + x_offset;
        int y1 = point_vector[i-1]->getY() * ((*view).getXMax() - (*view).getXMin()) / ((*clip).getXMax() - (*clip).getXMin());
        int x2 = point_vector[i]->getX() * ((*view).getXMax() - (*view).getXMin()) / ((*clip).getXMax() - (*clip).getXMin()) + x_offset;
        int y2 = point_vector[i]->getY() * ((*view).getXMax() - (*view).getXMin()) / ((*clip).getXMax() - (*clip).getXMin());

        bresenham(x1, y1, x2, y2, rgb, fbp, vinfo, finfo);
        if((x1 < x_min)&&(x1 < x2)){x_min = x1;}
        else if((x2 < x_min)&&(x2 < x1)){x_min = x2;}
        else {}

        if((y1 < y_min)&&(y1 < y2)){y_min = y1;}
        else if((y2 < y_min)&&(y2 < y1)){y_min = y2;}
        else {}

        if((x1 > x_max)&&(x1 > x2)){x_max = x1;}
        else if((x2 > x_max)&&(x2 > x1)){x_max = x2;}
        else {}

        if((y1 > y_max)&&(y1 > y2)){y_max = y1;}
        else if((y2 > y_max)&&(y2 > y1)){y_max = y2;}
        else {}

        i++;
    }
    rasterScan(x_min, y_min, x_max, y_max, 0, fbp, vinfo, finfo);
};

void Object::render(char * fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    int size = point_vector.size();
    int i = 1;
    struct RGB rgb;
    rgb.r = rgb.b = rgb.g = 255;
	int x_min = 999999;
	int y_min = 999999;
	int x_max = -999999;
	int y_max = -999999;
    while (i < size){
        int x1 = point_vector[i-1]->getX();
        int y1 = point_vector[i-1]->getY();
        int x2 = point_vector[i]->getX();
        int y2 = point_vector[i]->getY();

        bresenham(x1, y1, x2, y2, rgb, fbp, vinfo, finfo);
		if((x1 < x_min)&&(x1 < x2)){x_min = x1;}
		else if((x2 < x_min)&&(x2 < x1)){x_min = x2;}
		else {}

		if((y1 < y_min)&&(y1 < y2)){y_min = y1;}
		else if((y2 < y_min)&&(y2 < y1)){y_min = y2;}
		else {}

		if((x1 > x_max)&&(x1 > x2)){x_max = x1;}
		else if((x2 > x_max)&&(x2 > x1)){x_max = x2;}
		else {}

		if((y1 > y_max)&&(y1 > y2)){y_max = y1;}
		else if((y2 > y_max)&&(y2 > y1)){y_max = y2;}
		else {}

        i++;
    }
    rasterScan(x_min, y_min, x_max, y_max, 0, fbp, vinfo, finfo);
};
