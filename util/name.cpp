#include "name.h"

void render_a(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    long int location;

    //16x20
    for (int j = 0; j < 4; j++) {
        if (j + y >= vinfo.yres)
            break;
        for (int i = 4; i < 12; i++) {
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
    for (int j = 8; j < 12; j++) {
        if (j + y >= vinfo.yres)
            break;
        for (int i = 4; i < 12; i++) {
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
    for (int j = 4; j < 20; j++){
        if (j + y >= vinfo.yres)
            break;
        for (int i = 0; i < 4; i++){
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
    for (int j = 4; j < 20; j++){
        if (j + y >= vinfo.yres)
            break;
        for (int i = 12; i < 16; i++){
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
}
void render_b(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
	    long int location;
    int xx, yy;   
    for (yy = y; yy < y+4; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+16; xx++) {
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
	    
        }
    }
    for (yy = y+4; yy < y+8; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+4; xx++) {
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
	for (xx = x+16; xx < x+20; xx++) {
        if (yy >= vinfo.yres)
            break;
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }	
    for (yy = y+8; yy < y+12; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+16; xx++) {
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
    for (yy = y+12; yy < y+16; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+4; xx++) {   
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
	for (xx = x+16; xx < x+20; xx++) {
        if (yy >= vinfo.yres)
            break;
        location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
        pixel_color(fbp, location, b, g, r);
        }
    }
    for (yy = y+16; yy < y+20; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+16; xx++) { 
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }

}

void render_c(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    long int location;

    for (int j = 0; j < 4; j++){
        if (j + y >= vinfo.yres)
            break;
        for (int i = 4; i < 16; i++){
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
    for (int j = 4; j < 16; j++){
        if (j + y >= vinfo.yres)
            break;
        for (int i = 0; i < 4; i++){
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
    for (int j = 16; j < 20; j++){
        if (j + y >= vinfo.yres)
            break;
        for (int i = 4; i < 16; i++){
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
}

void render_d(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
	    long int location;
    int xx,yy;    
    for (yy = y; yy < y+20; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+4; xx++) {
	       location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
    for (yy = y; yy < y+4; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+12; xx++) {
	       location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
    for (yy = y+16; yy < y+20; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+12; xx++) {
	       location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
    for (yy = y+4; yy < y+16; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x+12; xx < x+16; xx++) {
	       location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
    

}
void render_e(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    long int location;

    for (int j = 0; j < 20; j++){
        if (j + y >= vinfo.yres)
            break;
        for (int i = 0; i < 4; i++){
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
    for (int i = 4; i < 16; i++){
        for (int j = 0; j < 4; j++){
            if (j + y >= vinfo.yres)
                break;
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
        for (int j = 16; j < 20; j++){
            if (j + y >= vinfo.yres)
                break;
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
    for (int j = 8; j < 12; j++){
        if (j + y >= vinfo.yres)
            break;
        for (int i = 4; i < 12; i++){
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
}
void render_f(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
	long int location;
    int xx, yy;

    for (yy = y; yy < y+20; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+4; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);
        }
    }

    for (yy = y; yy < y+4; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+16; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }
    for (yy = y+8; yy < y+12; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+12; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);
        }
    }

}
void render_g(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    long int location;

    for (int j = 0; j < 4; j++){
        if (j + y >= vinfo.yres)
            break;
        for (int i = 4; i < 16; i++){
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
    for (int j = 4; j < 16; j++){
        if (j + y >= vinfo.yres)
            break;
        for (int i = 0; i < 4; i++){
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
    for (int j = 16; j < 20; j++){
        if (j + y >= vinfo.yres)
            break;
        for (int i = 4; i < 16; i++){
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
    for (int j = 8; j < 16; j++){
        if (j + y >= vinfo.yres)
            break;
        for (int i = 12; i < 16; i++){
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
    for (int j = 8; j < 12; j++){
        if (j + y >= vinfo.yres)
            break;
        for (int i = 8; i < 12; i++){
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
}

void render_h(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    long int location;
    int xx, yy;

    for (yy = y; yy < y+20; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+4; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }

    for (yy = y; yy < y+20; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x+12; xx < x+16; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }

    for (yy = y+8; yy < y+12; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x+4; xx < x+12; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }
}

void render_i(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
	long int location;
    int xx, yy;

    for (yy = y; yy < y+20; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+4; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }

}
void render_j(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    long int location;

    for (int j = 0; j < 16; j++){
        if (j + y >= vinfo.yres)
            break;
        for (int i = 12; i < 16; i++){
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
    for (int j = 16; j < 20; j++){
        if (j + y >= vinfo.yres)
            break;
        for (int i = 4; i < 12; i++){
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
    for (int j = 12; j < 16; j++){
        if (j + y >= vinfo.yres)
            break;
        for (int i = 0; i < 4; i++){
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
}
void render_k(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
	    long int location;
    int xx,yy;  
    for (yy = y; yy < y+20; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+4; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        } 
    }
    for (yy = y; yy < y+4; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x+12; xx < x+16; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }
    for (yy = y+4; yy < y+8; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x+8; xx < x+12; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }

    for (yy = y+8; yy < y+12; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+8; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }

    for (yy = y+12; yy < y+16; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x+8; xx < x+12; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }
    for (yy = y+16; yy < y+20; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x+12; xx < x+16; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }

 

}
void render_l(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
	long int location;
    int xx, yy;

    for (yy = y; yy < y+20; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+4; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }

    for (yy = y+16; yy < y+20; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+12; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);
    
        }
    }

}

void render_m(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
	    long int location;
    int xx,yy;    
    for (yy = y; yy < y+20; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+4; xx++) {
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
	for (xx = x+17; xx < x+20; xx++) {
        if (yy >= vinfo.yres)
            break;
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
    for (yy = y+4; yy < y+8; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x+4; xx < x+8; xx++) {
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
	for (xx = x+12; xx < x+16; xx++) {
        if (yy >= vinfo.yres)
            break;
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
    for (yy = y+8; yy < y+12; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x+8; xx < x+12; xx++) {
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }

}
void render_n(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
	long int location;
    int xx, yy;

    for (yy = y; yy < y+20; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+4; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }

    for (yy = y; yy < y+20; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x+12; xx < x+16; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }

    for (yy = y+8; yy < y+12; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x+4; xx < x+8; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }
    for (yy = y+12; yy < y+16; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x+8; xx < x+12; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }


}
void render_o(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    long int location;
    int i, j;

    //Mengikuti ukuran karakter 16x20 pixel

    for (i = 4; i < 12; i++) {
        for (j = 0; j < 4; j++) {
            if ((j + y) >= vinfo.yres)
                break;
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                               (y+j+vinfo.yoffset) * finfo.line_length;
        pixel_color(fbp, location, b, g, r);
        }
        for (j = 16; j < 20; j++) {
            if ((j + y) >= vinfo.yres)
                break;
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                               (y+j+vinfo.yoffset) * finfo.line_length;
        pixel_color(fbp, location, b, g, r);
        }
    }
    for (j=4; j<16; j++) {
        if ((j + y) >= vinfo.yres)
                break;
        for (i = 0; i < 4; i++) {
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                               (y+j+vinfo.yoffset) * finfo.line_length;
        pixel_color(fbp, location, b, g, r);
        }
        for (i = 12; i < 16; i++) {
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                               (y+j+vinfo.yoffset) * finfo.line_length;
        pixel_color(fbp, location, b, g, r);
        }
    }
}
void render_p(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
	    long int location;
    int xx, yy;

    for (yy = y; yy < y+20; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+4; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }

    for (yy = y; yy < y+4; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+12; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }

    for (yy = y+4; yy < y+8; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x+12; xx < x+16; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }
    for (yy = y+8; yy < y+12; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+12; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }

}
void render_r(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
	long int location;
    int xx, yy;

    for (yy = y; yy < y+20; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+4; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }

    for (yy = y; yy < y+4; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+12; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }

    for (yy = y+4; yy < y+8; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x+12; xx < x+16; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }
    for (yy = y+8; yy < y+12; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+12; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }
    for (yy = y+12; yy < y+16; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x+8; xx < x+12; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }
    for (yy = y+16; yy < y+20; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x+12; xx < x+16; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }


}
void render_s(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    long int location;
    int i, j;

    //Mengikuti ukuran karakter 16x20 pixel

    for (j = 0; j < 4; j++) {
        if ((j + y) >= vinfo.yres)
            break;
        for (i = 4; i < 16; i++) {
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                               (y+j+vinfo.yoffset) * finfo.line_length;
        pixel_color(fbp, location, b, g, r);
        }
    }
    for (j=4; j<8; j++) {
        if ((j + y) >= vinfo.yres)
            break;
        for (i = 0; i < 4; i++) {
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                               (y+j+vinfo.yoffset) * finfo.line_length;
        pixel_color(fbp, location, b, g, r);
        }
    }
    for (j=8; j<12; j++) {
        if ((j + y) >= vinfo.yres)
            break;
        for (i = 4; i < 12; i++) {
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                               (y+j+vinfo.yoffset) * finfo.line_length;
        pixel_color(fbp, location, b, g, r);
        }
    }
    for (j=12; j<16; j++) {
        if ((j + y) >= vinfo.yres)
            break;
        for (i = 12; i < 16; i++) {
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                               (y+j+vinfo.yoffset) * finfo.line_length;
        pixel_color(fbp, location, b, g, r);
        }
    }
    for (j=16; j<20; j++) {
        if ((j + y) >= vinfo.yres)
            break;
        for (i = 0; i < 12; i++) {
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                               (y+j+vinfo.yoffset) * finfo.line_length;
        pixel_color(fbp, location, b, g, r);
        }
    }
}
void render_t(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    long int location;
    int i, j;

    //Mengikuti ukuran karakter 16x20 pixel
    for (j = 0; j < 4; j++) {
        if ((j + y) >= vinfo.yres)
            break;
        for (i = 0; i < 12; i++) {
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                               (y+j+vinfo.yoffset) * finfo.line_length;
        pixel_color(fbp, location, b, g, r);
        }
    }
    for (j=4; j<20; j++) {
        if ((j + y) >= vinfo.yres)
            break;
        for (i = 4; i < 8; i++) {
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                               (y+j+vinfo.yoffset) * finfo.line_length;
        pixel_color(fbp, location, b, g, r);
        }
    }
}
void render_u(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
	long int location;
    int xx, yy;

    for (yy = y; yy < y+20; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+4; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }

    for (yy = y; yy < y+20; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x+12; xx < x+16; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }

    for (yy = y+16; yy < y+20; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+16; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }

}
//draw V letter
void render_v(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo) {

    long int location;
    int xx, yy;

    for (yy = y; yy < y+16; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+4; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }

    for (yy = y; yy < y+16; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x+12; xx < x+16; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }

    for (yy = y+12; yy < y+16; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+16; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }
    for (yy = y+16; yy < y+20; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x+4; xx < x+12; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }

}
void render_w(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    long int location;
    int i, j;

    //Mengikuti ukuran karakter 20x20 pixel

    for (j=0; j<16; j++) {
        for (i = 0; i < 4; i++) {
			if (j + y >= vinfo.yres)
		        break;
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                               (y+j+vinfo.yoffset) * finfo.line_length;
        pixel_color(fbp, location, b, g, r);
        }
        for (i = 16; i < 20; i++) {
			if (j + y >= vinfo.yres)
		        break;
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                               (y+j+vinfo.yoffset) * finfo.line_length;
        pixel_color(fbp, location, b, g, r);
        }
    }
    for (j = 8; j < 16; j++) {
        for (i = 8; i < 12; i++) {
			if (j + y >= vinfo.yres)
		        break;
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                               (y+j+vinfo.yoffset) * finfo.line_length;
        pixel_color(fbp, location, b, g, r);
        }
    }
    for (j = 16; j < 20; j++) {
        for (i = 4; i < 8; i++) {
			if (j + y >= vinfo.yres)
		        break;
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                               (y+j+vinfo.yoffset) * finfo.line_length;
        pixel_color(fbp, location, b, g, r);
        }
    }
    for (j = 16; j < 20; j++) {
        for (i = 12; i < 16; i++) {
			if (j + y >= vinfo.yres)
		        break;
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                               (y+j+vinfo.yoffset) * finfo.line_length;
        pixel_color(fbp, location, b, g, r);
        }
    }
}
void render_y(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
	long int location;
    int xx, yy;

    for (yy = y; yy < y+12; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+4; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }

    for (yy = y; yy < y+12; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x+8; xx < x+12; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }

    for (yy = y+8; yy < y+12; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+12; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }
    for (yy = y+8; yy < y+20; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x+4; xx < x+8; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }

}

void render_kotak(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
	long int location;
	int xx, yy;
	for (yy = y+4; yy < y+12; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x+4; xx < x+12; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }
}

void nama( int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    
    int b = 0;
    int g = 0;
    int r = 200;

    render_s(346, y, b, g, r, fbp, vinfo, finfo);
    render_i(366, y, b, g, r, fbp, vinfo, finfo);
    render_d(376, y, b, g, r, fbp, vinfo, finfo);
    render_e(396, y, b, g, r, fbp, vinfo, finfo);
    render_r(416, y, b, g, r, fbp, vinfo, finfo);
}
    
void yora(int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){

    int b = 0;
    int g = 220;
    int r = 220;

    render_kotak(80, y, 255, 255, 255, fbp, vinfo, finfo);
    render_d(106, y, b, g, r, fbp, vinfo, finfo);
    render_i(126, y, b, g, r, fbp, vinfo, finfo);
    render_n(136, y, b, g, r, fbp, vinfo, finfo);
    render_d(156, y, b, g, r, fbp, vinfo, finfo);
    render_a(176, y, b, g, r, fbp, vinfo, finfo);
    render_y(204, y, b, g, r, fbp, vinfo, finfo);
    render_o(220, y, b, g, r, fbp, vinfo, finfo);
    render_r(240, y, b, g, r, fbp, vinfo, finfo);
    render_a(260, y, b, g, r, fbp, vinfo, finfo);
    render_i(288, y, b, g, r, fbp, vinfo, finfo);
    render_s(296, y, b, g, r, fbp, vinfo, finfo);
    render_l(316, y, b, g, r, fbp, vinfo, finfo);
    render_a(332, y, b, g, r, fbp, vinfo, finfo);
    render_m(352, y, b, g, r, fbp, vinfo, finfo);
    render_i(376, y, b, g, r, fbp, vinfo, finfo);
    //render_strip(400, y, 150, 150, 150, fbp, vinfo, finfo);
    render_p(620, y, b, g, r, fbp, vinfo, finfo);
    render_a(640, y, b, g, r, fbp, vinfo, finfo);
    render_d(660, y, b, g, r, fbp, vinfo, finfo);
    render_a(680, y, b, g, r, fbp, vinfo, finfo);
    render_n(700, y, b, g, r, fbp, vinfo, finfo);
    render_g(720, y, b, g, r, fbp, vinfo, finfo);
}

void tere(int y,char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){

    int b = 200;
    int g = 0;
    int r = 100;

    render_kotak(80, y, 255, 255, 255, fbp, vinfo, finfo);
    render_t(106, y, b, g, r, fbp, vinfo, finfo);
    render_e(126, y, b, g, r, fbp, vinfo, finfo);
    render_r(146, y, b, g, r, fbp, vinfo, finfo);
    render_e(166, y, b, g, r, fbp, vinfo, finfo);
    render_s(186, y, b, g, r, fbp, vinfo, finfo);
    render_a(206, y, b, g, r, fbp, vinfo, finfo);
    //render_strip(520, y, 150, 150, 150, fbp, vinfo, finfo);
    render_p(556, y, b, g, r, fbp, vinfo, finfo);
    render_e(576, y, b, g, r, fbp, vinfo, finfo);
    render_k(596, y, b, g, r, fbp, vinfo, finfo);
    render_a(616, y, b, g, r, fbp, vinfo, finfo);
    render_n(636, y, b, g, r, fbp, vinfo, finfo);
    render_b(656, y, b, g, r, fbp, vinfo, finfo);
    render_a(680, y, b, g, r, fbp, vinfo, finfo);
    render_r(700, y, b, g, r, fbp, vinfo, finfo);
    render_u(720, y, b, g, r, fbp, vinfo, finfo);
}

void bella(int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo) {

    int b = 0;
    int g = 100;
    int r = 200;

    render_kotak(80, y, 255, 255, 255, fbp, vinfo, finfo);    

    render_b(106, y, b, g, r, fbp, vinfo, finfo);
    render_e(106+25, y, b, g, r, fbp, vinfo, finfo);
    render_l(106+45, y, b, g, r, fbp, vinfo, finfo);
    render_l(106+60, y, b, g, r, fbp, vinfo, finfo);
    render_a(106+75, y, b, g, r, fbp, vinfo, finfo);

    render_d(106+105, y, b, g, r, fbp, vinfo, finfo);
    render_e(106+125, y, b, g, r, fbp, vinfo, finfo);
    render_s(106+145, y, b, g, r, fbp, vinfo, finfo);
    render_t(106+165, y, b, g, r, fbp, vinfo, finfo);
    render_i(106+185, y, b, g, r, fbp, vinfo, finfo);
    render_a(106+195, y, b, g, r, fbp, vinfo, finfo);
    render_n(106+215, y, b, g, r, fbp, vinfo, finfo);
    render_a(106+235, y, b, g, r, fbp, vinfo, finfo);

    render_j(106+265, y, b, g, r, fbp, vinfo, finfo);

    //render_strip(580, y, 150, 150, 150, fbp, vinfo, finfo);

    render_j(605, y, b, g, r, fbp, vinfo, finfo);
    render_a(625, y, b, g, r, fbp, vinfo, finfo);
    render_k(645, y, b, g, r, fbp, vinfo, finfo);
    render_a(665, y, b, g, r, fbp, vinfo, finfo);
    render_r(685, y, b, g, r, fbp, vinfo, finfo);
    render_t(705, y, b, g, r, fbp, vinfo, finfo);
    render_a(720, y, b, g, r, fbp, vinfo, finfo);
}

void kevin_a(int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo) {

    int b = 0;
    int g = 200;
    int r = 0;

    render_kotak(80, y, 255, 255, 255, fbp, vinfo, finfo);    

    render_k(106, y, b, g, r, fbp, vinfo, finfo);
    render_e(106+25, y, b, g, r, fbp, vinfo, finfo);
    render_v(106+45, y, b, g, r, fbp, vinfo, finfo);
    render_i(106+65, y, b, g, r, fbp, vinfo, finfo);
    render_n(106+75, y, b, g, r, fbp, vinfo, finfo);

    render_a(106+105, y, b, g, r, fbp, vinfo, finfo);
    render_n(106+125, y, b, g, r, fbp, vinfo, finfo);
    render_d(106+145, y, b, g, r, fbp, vinfo, finfo);
    render_r(106+165, y, b, g, r, fbp, vinfo, finfo);
    render_i(106+185, y, b, g, r, fbp, vinfo, finfo);
    render_a(106+195, y, b, g, r, fbp, vinfo, finfo);
    render_n(106+215, y, b, g, r, fbp, vinfo, finfo);

    render_l(106+255, y, b, g, r, fbp, vinfo, finfo);

    //render_strip(540, y, 150, 150, 150, fbp, vinfo, finfo);

    render_t(560, y, b, g, r, fbp, vinfo, finfo);
    render_a(580, y, b, g, r, fbp, vinfo, finfo);
    render_n(600, y, b, g, r, fbp, vinfo, finfo);
    render_g(620, y, b, g, r, fbp, vinfo, finfo);
    render_e(640, y, b, g, r, fbp, vinfo, finfo);
    render_r(660, y, b, g, r, fbp, vinfo, finfo);
    render_a(680, y, b, g, r, fbp, vinfo, finfo);
    render_n(700, y, b, g, r, fbp, vinfo, finfo);
    render_g(720, y, b, g, r, fbp, vinfo, finfo);
}

void kevin_f(int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo) {

    int b = 200;
    int g = 0;
    int r = 0;

    render_kotak(80, y, 255, 255, 255, fbp, vinfo, finfo);    

    render_k(106, y, b, g, r, fbp, vinfo, finfo);
    render_e(106+25, y, b, g, r, fbp, vinfo, finfo);
    render_v(106+45, y, b, g, r, fbp, vinfo, finfo);
    render_i(106+65, y, b, g, r, fbp, vinfo, finfo);
    render_n(106+75, y, b, g, r, fbp, vinfo, finfo);

    render_f(106+105, y, b, g, r, fbp, vinfo, finfo);
    render_e(106+125, y, b, g, r, fbp, vinfo, finfo);
    render_r(106+145, y, b, g, r, fbp, vinfo, finfo);
    render_n(106+165, y, b, g, r, fbp, vinfo, finfo);
    render_a(106+185, y, b, g, r, fbp, vinfo, finfo);
    render_l(106+205, y, b, g, r, fbp, vinfo, finfo);
    render_d(106+220, y, b, g, r, fbp, vinfo, finfo);
    render_y(106+240, y, b, g, r, fbp, vinfo, finfo);
    

    //render_strip(580, y, 150, 150, 150, fbp, vinfo, finfo);

    render_j(605, y, b, g, r, fbp, vinfo, finfo);
    render_a(625, y, b, g, r, fbp, vinfo, finfo);
    render_k(645, y, b, g, r, fbp, vinfo, finfo);
    render_a(665, y, b, g, r, fbp, vinfo, finfo);
    render_r(685, y, b, g, r, fbp, vinfo, finfo);
    render_t(705, y, b, g, r, fbp, vinfo, finfo);
    render_a(720, y, b, g, r, fbp, vinfo, finfo);
}

void fildah(int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    int b = 200;
    int g = 100;
    int r = 0;

    render_kotak(80, y, 255, 255, 255, fbp, vinfo, finfo);    

    render_f(106, y, b, g, r, fbp, vinfo, finfo);
    render_i(106+20, y, b, g, r, fbp, vinfo, finfo);
    render_l(106+30, y, b, g, r, fbp, vinfo, finfo);
    render_d(106+45, y, b, g, r, fbp, vinfo, finfo);
    render_a(106+65, y, b, g, r, fbp, vinfo, finfo);
    render_h(106+85, y, b, g, r, fbp, vinfo, finfo);

    render_a(106+115, y, b, g, r, fbp, vinfo, finfo);
    render_n(106+135, y, b, g, r, fbp, vinfo, finfo);
    render_a(106+155, y, b, g, r, fbp, vinfo, finfo);
    render_n(106+175, y, b, g, r, fbp, vinfo, finfo);
    render_d(106+195, y, b, g, r, fbp, vinfo, finfo);
    render_a(106+215, y, b, g, r, fbp, vinfo, finfo);

    render_m(600, y, b, g, r, fbp, vinfo, finfo);
    render_a(625, y, b, g, r, fbp, vinfo, finfo);
    render_g(645, y, b, g, r, fbp, vinfo, finfo);
    render_e(665, y, b, g, r, fbp, vinfo, finfo);
    render_t(685, y, b, g, r, fbp, vinfo, finfo);
    render_a(700, y, b, g, r, fbp, vinfo, finfo);
    render_n(720, y, b, g, r, fbp, vinfo, finfo);

}

void richard(int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    int b = 200;
    int g = 50;
    int r = 200;

    render_kotak(80, y, 255, 255, 255, fbp, vinfo, finfo);    

    render_r(106, y, b, g, r, fbp, vinfo, finfo);
    render_i(106+20, y, b, g, r, fbp, vinfo, finfo);
    render_c(106+30, y, b, g, r, fbp, vinfo, finfo);
    render_h(106+50, y, b, g, r, fbp, vinfo, finfo);
    render_a(106+70, y, b, g, r, fbp, vinfo, finfo);
    render_r(106+90, y, b, g, r, fbp, vinfo, finfo);
    render_d(106+110, y, b, g, r, fbp, vinfo, finfo);

    render_m(106+140, y, b, g, r, fbp, vinfo, finfo);
    render_a(106+165, y, b, g, r, fbp, vinfo, finfo);
    render_t(106+185, y, b, g, r, fbp, vinfo, finfo);
    render_t(106+200, y, b, g, r, fbp, vinfo, finfo);
    render_h(106+215, y, b, g, r, fbp, vinfo, finfo);
    render_e(106+235, y, b, g, r, fbp, vinfo, finfo);
    render_w(106+255, y, b, g, r, fbp, vinfo, finfo);

    render_b(595, y, b, g, r, fbp, vinfo, finfo);
    render_a(620, y, b, g, r, fbp, vinfo, finfo);
    render_n(640, y, b, g, r, fbp, vinfo, finfo);
    render_d(660, y, b, g, r, fbp, vinfo, finfo);
    render_u(680, y, b, g, r, fbp, vinfo, finfo);
    render_n(700, y, b, g, r, fbp, vinfo, finfo);
    render_g(720, y, b, g, r, fbp, vinfo, finfo);
}
