#ifndef __BLAST_HPP__
#define __BLAST_HPP__
#include "../util/func_util.h"
#include "../util/class_util.h"

using namespace std;

class Blast : public Renderable {
    public:
        Blast(int x, int y, int size);
        ~Blast();

        int getSize();
        void setSize(int size);

        void render(char* fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);

    private:
        int size;
};

#endif
