#include "objects.h"
#include "util/func_util.h"

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

    int plane_x_max = plane.getX() + plane.getOffset() + 50 + 25;
    int plane_x_min = plane.getX() + plane.getOffset() + 50 - 80;
    int plane_y_max = plane.getY() + 41;

    if ((bullet_x_max <= plane_x_max) && (bullet_x_max >= plane_x_min) && (bullet_y_min <= plane_y_max)){
        return true;
    }
    if ((bullet_x_min <= plane_x_max) && (bullet_x_min >= plane_x_min) && (bullet_y_min <= plane_y_max)){
        return true;
    }
    return false;
};
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


// ******** Plane Class Implementation ********
Plane::Plane(int x, int y, int offset) : Renderable(x,y){
    this->offset = offset;
};
Plane::~Plane() { };

int Plane::getOffset(){
    return offset;
};
void Plane::setOffset(int offset){
    this->offset = offset;
};

void Plane::move(struct fb_var_screeninfo vinfo){
    offset++;

    if (offset > vinfo.xres + 25){
        offset %= vinfo.xres;
    }
};
void Plane::render(char* fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    int x0 = this->getX() + offset;
    int y0 = this->getY();
/*
    int x1 = x0 + 50;
    int y1 = y0;

    bresenham(x0   , y0   , x1   , y1   ,false,fbp,vinfo,finfo);//lurus atas
    bresenham(x0-9 , y0+26, x1-47, y1+26,false,fbp,vinfo,finfo);//lurus bawah
    bresenham(x0+25, y0+26, x1   , y1+26,false,fbp,vinfo,finfo);//lurus bawah
    bresenham(x0+52, y0+11, x1+23, y1+11,false,fbp,vinfo,finfo);//lurus tengah
    bresenham(x0+52, y0+11, x1-15, y1   ,false,fbp,vinfo,finfo);//runcing
    bresenham(x0+50, y0+26, x1+25, y1+13,false,fbp,vinfo,finfo);//runcing
    bresenham(x0+50, y0   , x1+25, y1+13,false,fbp,vinfo,finfo);//runcing
    bresenham(x0+10, y0+15, x1-10, y1+15,false,fbp,vinfo,finfo);//tambahan bawah
    bresenham(x0+9 , y0+15, x1-50, y1+41,false,fbp,vinfo,finfo);//sayap
    bresenham(x0+40, y0+15, x1-50, y1+41,false,fbp,vinfo,finfo);//sayap
    bresenham(x0   , y0   , x1-80, y1-15,false,fbp,vinfo,finfo);//ekor
    bresenham(x0-10, y0+25, x1-80, y1-15,false,fbp,vinfo,finfo);//ekor
*/

	bresenham(x0, y0, x0 + 15, y0,false,fbp,vinfo,finfo);
	bresenham(x0 + 15, y0, x0+21, y0-6, false,fbp,vinfo,finfo);
	bresenham(x0+21, y0-6, x0+41, y0-6, false,fbp,vinfo,finfo);
	bresenham(x0+41, y0-6, x0+41, y0, false,fbp,vinfo,finfo);
	bresenham(x0+41, y0, x0+50, y0, false,fbp,vinfo,finfo);
    bresenham(x0+50, y0, x0 + 50, y0+20,false,fbp,vinfo,finfo);
    bresenham(x0+50, y0+20,x0+41, y0+30,false,fbp,vinfo,finfo);
	bresenham(x0+25, y0+30, x0+41, y0+30,false,fbp,vinfo,finfo);
	bresenham(x0+25, y0+30, x0+20, y0+36,false,fbp,vinfo,finfo);
	bresenham(x0, y0+36, x0+20, y0+36,false,fbp,vinfo,finfo);
	bresenham(x0, y0+30, x0, y0+36,false,fbp,vinfo,finfo);
	bresenham(x0, y0+30, x0-9, y0+30,false,fbp,vinfo,finfo);
    bresenham(x0-9, y0+10, x0-9, y0+30,false,fbp,vinfo,finfo);
    bresenham(x0, y0, x0-9, y0+10,false,fbp,vinfo,finfo);
    
	rasterScan(x0-9, y0-6, x0+50, y0+36, 1,fbp,vinfo,finfo);

	bresenham(x0, y0+30, x0+5, y0+24,false,fbp,vinfo,finfo);
	bresenham(x0+25, y0+24, x0+5, y0+24,false,fbp,vinfo,finfo);
	bresenham(x0+25, y0+24, x0+25, y0+30,false,fbp,vinfo,finfo);
	bresenham(x0+35, y0, x0+41, y0-6,false,fbp,vinfo,finfo);

	bresenham(x0+41, y0+10, x0+50, y0,false,fbp,vinfo,finfo);
	bresenham(x0+41, y0+10, x0-9, y0+10,false,fbp,vinfo,finfo);
	bresenham(x0+41, y0+10, x0+41, y0+30,false,fbp,vinfo,finfo);
	
	bresenham(x0+20, y0+30, x0+25, y0+24,false,fbp,vinfo,finfo);
	bresenham(x0+20, y0+30, x0+20, y0+36,false,fbp,vinfo,finfo);
	bresenham(x0+20, y0+30, x0, y0+30,false,fbp,vinfo,finfo);

};
// ******** PlanePiece Class Implementation ********
PlanePiece::PlanePiece(int x, int y, int offset) : Plane(x,y,offset) { };
PlanePiece::~PlanePiece() { };

void PlanePiece::render(char* fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    int x0 = this->getX() + this->getOffset();
    int y0 = this->getY();


    int x1 = x0 + 50;
    int y1 = y0;
/*
    bresenham(x0+35, y0   , x1   , y1   ,0,fbp,vinfo,finfo);//lurus atas
    bresenham(x0+50, y0+26, x1   , y1+26,0,fbp,vinfo,finfo);//lurus bawah
    bresenham(x0+52, y0+11, x1+23, y1+11,0,fbp,vinfo,finfo);//lurus tengah
    bresenham(x0+52, y0+11, x1-15, y1   ,0,fbp,vinfo,finfo);//runcing
    bresenham(x0+50, y0+26, x1+25, y1+13,0,fbp,vinfo,finfo);//runcing
    bresenham(x0+50, y0   , x1+25, y1+13,0,fbp,vinfo,finfo);//runcing
    bresenham(x0+50, y0+30, x0+35, y0   ,0,fbp,vinfo,finfo);//runcing
*/

	bresenham(x0, y0, x0+50, y0, false,fbp,vinfo,finfo);
    bresenham(x0+50, y0, x0 + 50, y0+20,false,fbp,vinfo,finfo);
    bresenham(x0+50, y0+20,x0+41, y0+30,false,fbp,vinfo,finfo);
	bresenham(x0+41, y0+30, x0-9, y0+30,false,fbp,vinfo,finfo);
    bresenham(x0-9, y0+10, x0-9, y0+30,false,fbp,vinfo,finfo);
    bresenham(x0, y0, x0-9, y0+10,false,fbp,vinfo,finfo);

	rasterScan(x0-9, y0, x0+50, y0+30, 1,fbp,vinfo,finfo);

	bresenham(x0+41, y0+10, x0+50, y0,false,fbp,vinfo,finfo);
	bresenham(x0+41, y0+10, x0-9, y0+10,false,fbp,vinfo,finfo);
	bresenham(x0+41, y0+10, x0+41, y0+30,false,fbp,vinfo,finfo);


/*
    x0 -= 20;
    x1 -= 20;

    bresenham(x0   , y0   , x1   , y1   ,0,fbp,vinfo,finfo);//lurus atas
    bresenham(x0-9 , y0+26, x1-47, y1+26,0,fbp,vinfo,finfo);//lurus bawah
    bresenham(x0+25, y0+26, x1   , y1+26,0,fbp,vinfo,finfo);//lurus bawah
    bresenham(x0   , y0   , x0-9 , y0+26,0,fbp,vinfo,finfo);//
    bresenham(x1   , y1   , x1   , y1+26,0,fbp,vinfo,finfo);//
    bresenham(x0+10, y0+15, x1-10, y1+15,0,fbp,vinfo,finfo);//tambahan bawah
    bresenham(x0+9 , y0+15, x1-50, y1+41,0,fbp,vinfo,finfo);//sayap
    bresenham(x0+40, y0+15, x1-50, y1+41,0,fbp,vinfo,finfo);//sayap
*/

	bresenham(x0+60, y0+10, x0+80, y0+10, false,fbp,vinfo,finfo);
    bresenham(x0+80, y0+10, x0+80, y0+20,false,fbp,vinfo,finfo);
    bresenham(x0+80, y0+20,x0+74, y0+26,false,fbp,vinfo,finfo);
	bresenham(x0+74, y0+26, x0+54, y0+26,false,fbp,vinfo,finfo);
    bresenham(x0+54, y0+26, x0+54, y0+16,false,fbp,vinfo,finfo);
    bresenham(x0+54, y0+16, x0+60, y0+10,false,fbp,vinfo,finfo);

	rasterScan(x0+54, y0+10, x0+80, y0+26, 1,fbp,vinfo,finfo);

	bresenham(x0+74, y0+16, x0+80, y0+10, false,fbp,vinfo,finfo);
    bresenham(x0+74, y0+16, x0+54, y0+16,false,fbp,vinfo,finfo);
    bresenham(x0+74, y0+16,x0+74, y0+26,false,fbp,vinfo,finfo);
/*
    x0 -= 10;
    x1 -= 10;

    bresenham(x0   , y0   , x0-10, y0+25,0,fbp,vinfo,finfo);//ekor
    bresenham(x0   , y0   , x1-80, y1-15,0,fbp,vinfo,finfo);//ekor
    bresenham(x0-10, y0+25, x1-80, y1-15,0,fbp,vinfo,finfo);//ekor
*/

	bresenham(x0-30, y0+15, x0-20, y0+20, false,fbp,vinfo,finfo);
    bresenham(x0-20, y0+20, x0-20, y0+30,false,fbp,vinfo,finfo);
    bresenham(x0-20, y0+30, x0-30, y0+35,false,fbp,vinfo,finfo);
	bresenham(x0-40, y0+30, x0-30, y0+35,false,fbp,vinfo,finfo);
    bresenham(x0-40, y0+20, x0-40, y0+30, false,fbp,vinfo,finfo);
    bresenham(x0-30, y0+15, x0-40, y0+20,false,fbp,vinfo,finfo);

	rasterScan(x0-40, y0+15, x0-20, y0+35, 1,fbp,vinfo,finfo);

	bresenham(x0-30, y0+15, x0-30, y0+25,false,fbp,vinfo,finfo);
    bresenham(x0-30, y0+25, x0-20, y0+30,false,fbp,vinfo,finfo);
    bresenham(x0-30, y0+25, x0-40, y0+30,false,fbp,vinfo,finfo);
};

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
