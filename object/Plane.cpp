#include "Plane.h"

// ******** Plane Class Implementation ********
Plane::Plane(int x, int y, int offset) : Renderable(x,y){
    this->offset = offset;
	way = 1;
};
Plane::~Plane() { };

int Plane::getOffset(){
    return offset;
};
void Plane::setOffset(int offset){
    this->offset = offset;
};

void Plane::move(struct fb_var_screeninfo vinfo){
	if (way) {
    	offset++;
		if (offset > vinfo.xres - 100){
        	offset--;
			way = 0;
	    }
	} else {
		offset--;
		if (offset < 0){
        	offset++;
			way = 1;
	    }
	}
};
void Plane::render(char* fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    int x0 = this->getX() + offset;
    int y0 = this->getY();

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
