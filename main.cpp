#include <cerrno>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <linux/fb.h>
#include <linux/input.h>
#include <unistd.h>
#include <iostream>
#include <vector>
#include <thread>
#include <cstdlib>
#include <ctime>
#include <cstring>

#include "util/func_util.h"
#include "object/CannonBullet.h"
#include "object/PlaneBullet.h"
#include "object/Blast.h"
#include "object/Plane.h"
#include "object/Cannon.h"

using namespace std;

bool flagShoot = false;
unsigned short bullet_selection;

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
            if((ev.value == 1) && (!(flagShoot)) && (ev.code > 1) && (ev.code < 7)){
                flagShoot = true;
                bullet_selection = ev.code;
            }
        }
    }
}

void clear_screen(char * framebuffer, unsigned int x_size, unsigned int y_size, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    long int mem_location;

    for (int y = 0; y < y_size; y++){
        for (int x = 0; x < x_size; x++){
            mem_location = (x + vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y + vinfo.yoffset) * finfo.line_length;

            *(framebuffer + mem_location) = 0;
            *(framebuffer + mem_location + 1) = 0;
            *(framebuffer + mem_location + 2) = 0;
            *(framebuffer + mem_location + 3) = 0;
        }
    }
}

void draw_life(int life, char colorful, char * fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo) {
	int x_offset = 20;
	int y_offset = 20;
	bresenham(x_offset, y_offset,    x_offset,        y_offset+10, false,fbp,vinfo,finfo);
	bresenham(x_offset, y_offset,    x_offset+30*life, y_offset, false,fbp,vinfo,finfo);
	bresenham(x_offset, y_offset+10, x_offset+30*life, y_offset+10, false,fbp,vinfo,finfo);
	bresenham(x_offset+30*life, y_offset, x_offset+30*life, y_offset+10, false,fbp,vinfo,finfo);

	rasterScan(x_offset, y_offset, x_offset+30*life, y_offset+10, colorful, fbp, vinfo, finfo);
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

    const char *dev = "/dev/input/event2";
    int fd = open(dev, O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Cannot open %s: %s.\n", dev, strerror(errno));
        return EXIT_FAILURE;
    }

    thread inputter (userInput,fd);

    // **** Declares all variable needed for drawing framebuffer ****
    vector<CannonBullet *> bullets_vector_list;   // std::vector to store all bullets fired
    Plane *(plane_object) = new Plane(40,100,0);           // plane object
    Cannon *(cannon_object) = new Cannon(400,530,80);
    PlaneBullet *(plane_bullet_object) = nullptr;

    // **** Uses to determine whether to shoot a bullet from plane
    srand(time(0));

    struct timespec delay;      // delay variable
    delay.tv_sec = 0;
    delay.tv_nsec = 10000000;
	int life = 2;

    bool plane_shot_flag = false;
	int cannonShot = 0;

	while (life > 0) {

        if (plane_bullet_object == nullptr){
            if (rand() % 100 == 4){
                plane_bullet_object = new PlaneBullet(plane_object->getX() + plane_object->getOffset(),plane_object->getY(), plane_object->getX() + plane_object->getOffset(), plane_object->getY());
            }
        } else {
			//plane_bullet_object->move(*cannon_object);
			plane_bullet_object->move();
		    plane_bullet_object->render(fbp,vinfo,finfo);
        }

        clear_screen(fbp,800,600,vinfo,finfo);
		draw_life(life, 0, fbp,vinfo,finfo);

        // **** Cannon Object Handling ****
        cannon_object->render(fbp,vinfo,finfo);

        if (not(plane_shot_flag)){
            // **** Plane Object Handling ****
            plane_object->render(fbp,vinfo,finfo);
            plane_object->move(vinfo);

            // **** CannonBullet Objects Handling ****
            int vector_idx = 0;
            for (int i = 0; i < bullets_vector_list.size(); i++){
                if (350 - bullets_vector_list[i]->getOffset() <= 0){
                    bullets_vector_list.erase(bullets_vector_list.begin() + vector_idx);
                } else {
                    bullets_vector_list[i]->render(fbp,vinfo,finfo);
                    vector_idx++;

                    if (bullets_vector_list[i]->checkIfShot(*plane_object)){
                        plane_shot_flag = true;
                    }
                }
            }
            if (flagShoot){
                switch(bullet_selection-2){
                    case 0:
                        bullets_vector_list.push_back(new CannonBullet(302,456,bullet_selection-2));
                        break;
                    case 1:
                        bullets_vector_list.push_back(new CannonBullet(344,427,bullet_selection-2));
                        break;
                    case 2:
                        bullets_vector_list.push_back(new CannonBullet(400,415,bullet_selection-2));
                        break;
                    case 3:
                        bullets_vector_list.push_back(new CannonBullet(455,427,bullet_selection-2));
                        break;
                    case 4:
                        bullets_vector_list.push_back(new CannonBullet(498,460,bullet_selection-2));
                        break;
                }
                flagShoot = false;
            }

            // *** PlaneBullet Object Handling
            if (plane_bullet_object != nullptr) {
				if (plane_bullet_object->checkIfCollide(*cannon_object)){
					life--;
					delete plane_bullet_object;
					plane_bullet_object = nullptr;
				} else if (plane_bullet_object->getY() > 500) {
					delete plane_bullet_object;
					plane_bullet_object = nullptr;
				}
            }
        } else {
            int blast_size = 1;
            Blast *(blast_object) = new Blast(60 + plane_object->getOffset(), 100, blast_size);

            while (blast_size < 51){
                blast_object->render(fbp,vinfo,finfo);
                blast_size++;
                blast_object->setSize(blast_size);
                nanosleep(&delay,NULL);
            }
            delete blast_object;

            PlanePiece *(plane_piece_object) = new PlanePiece(70,100,plane_object->getOffset());
            while (plane_piece_object->getY() < 500){
                clear_screen(fbp,800,600,vinfo,finfo);

                plane_piece_object->render(fbp,vinfo,finfo);
                plane_piece_object->setY(plane_piece_object->getY() + 1);

                cannon_object->render(fbp,vinfo,finfo);

                nanosleep(&delay,NULL);

            };

            delete plane_piece_object;

            break;
        }

        // Delay needed to make flawless drawing
        nanosleep(&delay,NULL);
    }

    delete plane_object;
    delete cannon_object;

    while (bullets_vector_list.size() > 0){
        bullets_vector_list.erase(bullets_vector_list.begin());
    }

    munmap(fbp, screensize);
    close(fbfd);

    while(1);

    return 0;
}
