#include "Map.h"

Map::Map(int x, int y, int map_id) : Renderable(x,y){
	this->map_id = map_id;	
};
Map::~Map(){};

int Map::getMapId(){
	return map_id;
};
void Map::setMapId(int map_id){
	this->map_id = map_id;
};

void Map::render(char* fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    int sisi;
    int x0, y0, x1, y1;
    int xmin, ymin;
    int xmax, ymax;
    string nomap = to_string(map_id);

    ifstream fileInput;
    string filepath = "map/" + nomap + ".txt";
    fileInput.open(filepath);

    if(fileInput){
        fileInput >> sisi;
        //cout << "sisi " << sisi;
        for (int i=0; i<sisi; i++){
      	    fileInput >> x0 >> y0 >> x1 >> y1;
      	    bresenham(x0,y0,x1,y1,false,fbp,vinfo,finfo);
        };
        fileInput >> xmin >> ymin;
        fileInput >> xmax >> ymax;
        //cout << "xmin" << xmin << "ymax" << ymax;	
    
        fileInput.close();
    }

    else cout << "Unable to open file";
};