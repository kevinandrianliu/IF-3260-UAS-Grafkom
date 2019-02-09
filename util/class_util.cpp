#include "class_util.h"

using namespace std;

// ******** Renderable class implementation ********
Renderable::Renderable(int x, int y){
    this->x = x;
    this->y = y;
}
Renderable::~Renderable() { };

int Renderable::getX(){
    return x;
};
int Renderable::getY(){
    return y;
};
void Renderable::setX(int x){
    this->x = x;
};
void Renderable::setY(int y){
    this->y = y;
};