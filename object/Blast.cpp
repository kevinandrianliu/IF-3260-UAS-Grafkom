#include "Blast.h"

// ******** Blast Class Implementation ********
Blast::Blast(int x, int y, int size) : Renderable(x,y){
    this->size = size;
};
Blast::~Blast() { };

int Blast::getSize(){
    return size;
};
void Blast::setSize(int size){
    this->size = size;
};

void Blast::render(char* fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    int x = this->getX();
    int y = this->getY();

    int outert = 51;
    int outerd = 39;
    int outerx = 35;
    int innerl = 21;
    int inners = 8;
    
    for (int i = 0; i <= size; i++) {
        int ott = i;
        int otd = outerd*i/outert;
        int otx = outerx*i/outert;
        int inl = innerl*i/outert;
        int ins = inners*i/outert;

        bresenham(x - ins, y - inl, x, y - ott, true, fbp, vinfo, finfo); //Atas
        bresenham(x + ins, y - inl, x, y - ott, true, fbp, vinfo, finfo);

        bresenham(x - ins, y - inl, x - otx, y - otd, true, fbp, vinfo, finfo); //Barat Laut
        bresenham(x - inl, y - ins, x - otx, y - otd, true, fbp, vinfo, finfo);

        bresenham(x - inl, y - ins, x - ott, y, true, fbp, vinfo, finfo); //Barat
        bresenham(x - inl, y + ins, x - ott, y, true, fbp, vinfo, finfo);

        bresenham(x - inl, y + ins, x - otx, y + otd, true, fbp, vinfo, finfo); //Barat Daya
        bresenham(x - ins, y + inl, x - otx, y + otd, true, fbp, vinfo, finfo);

        bresenham(x - ins, y + inl, x, y + ott, true, fbp, vinfo, finfo); //Selatan
        bresenham(x + ins, y + inl, x, y + ott, true, fbp, vinfo, finfo);

        bresenham(x + ins, y - inl, x + otx, y - otd, true, fbp, vinfo, finfo); //Timur Laut
        bresenham(x + inl, y - ins, x + otx, y - otd, true, fbp, vinfo, finfo);

        bresenham(x + inl, y - ins, x + ott, y, true, fbp, vinfo, finfo); //Timur
        bresenham(x + inl, y + ins, x + ott, y, true, fbp, vinfo, finfo);

        bresenham(x + inl, y + ins, x + otx, y + otd, true, fbp, vinfo, finfo); //Tenggara
        bresenham(x + ins, y + inl, x + otx, y + otd, true, fbp, vinfo, finfo);
    }
};
