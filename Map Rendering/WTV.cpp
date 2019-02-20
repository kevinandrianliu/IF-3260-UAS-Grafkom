#include <thread>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <linux/fb.h>
#include <linux/input.h>
#include <cerrno>
#include <fcntl.h>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <fstream>
#include <ctime>

#include "WTV_objects.h"
#include "WTV_util.h"

using namespace std;

#define X_MIN_CLIP 55
#define Y_MIN_CLIP 35
#define X_MAX_CLIP 505
#define Y_MAX_CLIP 485

char key_press = 0x00;

void userInput(int fd){
    ssize_t n;
    struct input_event ev;

    while(1){
        n = read(fd, &ev, sizeof ev);
        if (n == (ssize_t)-1) {
            if (errno == EINTR)
                continue;
            else
                break;
        } else if (n != sizeof ev) {
            errno = EIO;
            break;
        }
        if (ev.type == EV_KEY && ev.value == 1){
            key_press = ev.code;
            if (ev.code == KEY_ESC){
                break;
            }
        }
    }
}

int main(int argc, char** argv){
    int fbfd;
    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;
    long int screensize;
    char *fbp;

    fbfd = open("/dev/fb0", O_RDWR);
    if (fbfd == -1) {
        // Framebuffer can't be opened
        exit(1);
    }

    if (ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo) == -1) {
        // Error reading fixed screen information
        exit(2);
    }

    if (ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo) == -1) {
        // Error reading variable screen information
        exit(3);
    }

    // Calculating the screen size in bytes
    screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;

    // Map the framebuffer into memory
    fbp = (char *) mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);
    if ((int)fbp == -1) {
        // Mapping failed
        exit(4);
    }

    const char *dev = "/dev/input/event4";
    int fd = open(dev, O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Cannot open %s: %s.\n", dev, strerror(errno));
        return EXIT_FAILURE;
    }

    thread inputter (userInput,fd);

    struct RGB rgb;
    rgb.r = 255;
    rgb.g = 0;
    rgb.b = 0;
    View *view = new View(555,35,1235,715,rgb);     // 70, 45, 410, 470 Jangan dihapus

    View *clip = new View(55,35,505,485,rgb);
    vector<Object *> object_vector = read_file();

    key_press = 0x00;
    clear_screen(1366,762,fbp,vinfo,finfo);
    for (std::vector<Object *>::iterator it = object_vector.begin(); it != object_vector.end(); it++){
        (*it)->render(fbp,vinfo,finfo);
        (*it)->render_to_view(view,new View(55,35,505,485,rgb),clip,fbp,vinfo,finfo);
    }
    view->render(fbp,vinfo,finfo);
    clip->render(fbp,vinfo,finfo);

    while (key_press != KEY_ESC){
        if (key_press != 0x00){
            clear_screen(1366,762,fbp,vinfo,finfo);
            switch (key_press){
                case KEY_LEFT:
                    if (clip->getXMin() > X_MIN_CLIP){
                        clip->setXMin(clip->getXMin() - 5);
                        clip->setXMax(clip->getXMax() - 5);
                    }
                    break;
                case KEY_RIGHT:
                    if (clip->getXMax() < X_MAX_CLIP){
                        clip->setXMin(clip->getXMin() + 5);
                        clip->setXMax(clip->getXMax() + 5);
                    }
                    break;
                case KEY_UP:
                    if (clip->getYMin() > Y_MIN_CLIP){
                        clip->setYMin(clip->getYMin() - 5);
                        clip->setYMax(clip->getYMax() - 5);
                    }
                    break;
                case KEY_DOWN:
                    if (clip->getYMax() < Y_MAX_CLIP){
                        clip->setYMin(clip->getYMin() + 5);
                        clip->setYMax(clip->getYMax() + 5);
                    }
                    break;
                case KEY_MINUS:
                    if (clip->getXMax() - clip->getXMin() > 50){
                        clip->setXMax(clip->getXMax() - 5);
                        clip->setYMax(clip->getYMax() - 5);
                    }
                    break;
                case KEY_EQUAL:
                    if (clip->getXMax() < X_MAX_CLIP){
                        clip->setXMax(clip->getXMax() + 5);
                        clip->setYMax(clip->getYMax() + 5);
                    }
                    break;
            }
            for (std::vector<Object *>::iterator it = object_vector.begin(); it != object_vector.end(); it++){
               (*it)->render(fbp,vinfo,finfo);
               (*it)->render_to_view(view,new View(55,35,505,485,rgb),clip,fbp,vinfo,finfo);
            }
            view->render(fbp,vinfo,finfo);
            clip->render(fbp,vinfo,finfo);
            key_press = 0x00;
        }
    }

    inputter.join();

    delete(view);
    delete(clip);

    while (object_vector.size() > 0){
        object_vector.erase(object_vector.begin());
    }

    munmap(fbp, screensize);
    close(fbfd);
    return 0;
}
