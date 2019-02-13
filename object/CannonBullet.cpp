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
bool CannonBullet::checkCollision(class PlaneBullet& bullet)
{
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

    int bullet_plane_width = bullet.getX();
    int bullet_plane_height = bullet.getY();

    int x_min_star_box = x - 7;
    int y_min_star_box = y - 7;
    int x_max_star_box = x + 7;
    int y_max_star_box = y + 7;

    int x0_plane_bullet_coordinates[4] = {
        bullet_plane_width-7,
        bullet_plane_width,
        bullet_plane_width+7,
        bullet_plane_width
    };
    int y0_plane_bullet_coordinates[4] = {
        bullet_plane_height,
        bullet_plane_height-7,
        bullet_plane_height,
        bullet_plane_height+7
    };
    int x1_plane_bullet_coordinates[4] = {
        bullet_plane_width,
        bullet_plane_width+7,
        bullet_plane_width,
        bullet_plane_width-7
    };
    int y1_plane_bullet_coordinates[4] = {
        bullet_plane_height-7,
        bullet_plane_height,
        bullet_plane_height+7,
        bullet_plane_height
    };

    for (int i = 0; i < 4; i++){
        if (checkIfIntersect(x_min_star_box,y_min_star_box,x_min_star_box,y_max_star_box,x0_plane_bullet_coordinates[i],y0_plane_bullet_coordinates[i],x1_plane_bullet_coordinates[i],y1_plane_bullet_coordinates[i]))
            return true;
        if (checkIfIntersect(x_min_star_box,y_max_star_box,x_max_star_box,y_max_star_box,x0_plane_bullet_coordinates[i],y0_plane_bullet_coordinates[i],x1_plane_bullet_coordinates[i],y1_plane_bullet_coordinates[i]))
            return true;
        if (checkIfIntersect(x_max_star_box,y_max_star_box,x_max_star_box,y_min_star_box,x0_plane_bullet_coordinates[i],y0_plane_bullet_coordinates[i],x1_plane_bullet_coordinates[i],y1_plane_bullet_coordinates[i]))
            return true;
        if (checkIfIntersect(x_max_star_box,y_min_star_box,x_min_star_box,y_min_star_box,x0_plane_bullet_coordinates[i],y0_plane_bullet_coordinates[i],x1_plane_bullet_coordinates[i],y1_plane_bullet_coordinates[i]))
            return true;
    }

    return false;
};

