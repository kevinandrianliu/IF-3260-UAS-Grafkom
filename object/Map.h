#ifndef __MAP_HPP__
#define __MAP_HPP__
#include "../util/class_util.h"
#include "../util/func_util.h"
#include <iostream>
#include <fstream>

using namespace std;

class Map : public Renderable {
    public:
        Map(int x, int y, int map_id);
        ~Map();

        int getMapId();
        void setMapId(int map_id);

        void render(char* fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
    private:
        int map_id;
};

#endif