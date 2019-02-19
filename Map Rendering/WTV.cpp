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

bool flagShoot = false;
char turret_selection = 2;

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
        if (ev.type == EV_KEY && ev.value >= 0 && ev.value <= 2){
            if ((ev.value == 1) && (!(flagShoot))){
                if ((ev.code  == KEY_LEFT) && (turret_selection > 0)){
                    turret_selection--;
                } else if ((ev.code == KEY_RIGHT) && (turret_selection < 4)){
                    turret_selection++;
                } else if ((ev.code == KEY_Z)) {
                    flagShoot = true;
                    break;
                }
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

    View *view = new View(783,162,1283,662,rgb);
    vector<Object *> object_vector = read_file();

    cout << object_vector.size() << endl;

    struct timespec time;
    time.tv_sec = 0;
    time.tv_nsec = 50000000L;

    clear_screen(1366,762,fbp,vinfo,finfo);

    int i = 0;

    for (std::vector<Object *>::iterator it = object_vector.begin(); it != object_vector.end(); it++){
       (*it)->render(fbp,vinfo,finfo);
       //(*it)->printPoints();
       i++;
       nanosleep(&time,NULL);
    }

    //view->render(fbp,vinfo,finfo);

    while (!(flagShoot));

    inputter.join();

    delete(view);

    while (object_vector.size() > 0){
        object_vector.erase(object_vector.begin());
    }

    munmap(fbp, screensize);
    close(fbfd);
    return 0;
}