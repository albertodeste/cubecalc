#include <stdio.h>

static char const MOVE_U = 1;
static char const MOVE_R = 2;
static char const MOVE_F = 3;
static char const MOVE_L = 4;
static char const MOVE_B = 5;
static char const MOVE_D = 6;

//TODO needs edges moves

//0x60a977
// 1 --+0--> 2 --+0--> 3 --+0--> 4 --+0--> 1
void move_u(unsigned long *p, unsigned short *o){
    *p = (((*p) >> 3) & 07770000) | (((*p) << 9) & 070000000) | ((*p) & 07777);
    *o = (((*o) >> 2) & 0x3f00) | (((*o) << 6) & 0xc000) | ((*o) & 0xff);
}

//0x0b386f
// 3 --+2--> 2 --+1--> 6 --+2--> 7 --+1--> 3
void move_r(unsigned long *p, unsigned short *o){
    *p = (((*p) << 3) & 07000000) | (((*p) >> 12) & 0700) | (((*p) >> 3) & 070) | (((*p) << 12) & 0700000) | ((*p) & 070077007);
    *o = (((((*o) << 2) & 0x3000) + 0x2000) % 0x3000) | (((((*o) >> 8) & 0x30) + 0x10 ) % 0x30) | (((((*o) >> 2) & 0xc) + 0x8) % 0xc) | (((((*o) << 8) & 0xc00) + 0x400) % 0xc00) | ((*o) & 0xc3c3);
}

//0x850f73
// 1 --+2--> 4 --+1--> 8 --+2--> 5 --+1--> 1
void move_l(unsigned long *p, unsigned short *o){
    *p = (((*p) >> 9) & 070000) | (((*p) >> 12) & 07) | (((*p) << 9) & 07000) | (((*p) << 12) & 070000000) | ((*p) & 07700770);
    *o = (((((*o) >> 6) & 0x300) + 0x200) % 0x300) | (((((*o) >> 8) & 0x3) + 0x1) % 0x3) | (((((*o) << 6) & 0xc0) + 0x80) % 0xc0) | (((((*o) << 8) & 0xc000) + 0x4000) % 0xc000) | ((*o) & 0x3c3c);
}

//0x05f956
// 4 --+2--> 3 --+1--> 7 --+2--> 8 --+1--> 4
void move_f(unsigned long *p, unsigned short *o){
    *p = (((*p) << 3) & 0700000) | (((*p) >> 12) & 070) | (((*p) >> 3) & 07) | (((*p) << 12) & 070000) | ((*p) & 077007700);
    *o = (((((*o) << 2) & 0xc00) + 0x800) % 0xc00) | (((((*o) >> 8) & 0xc) + 0x4) % 0xc) | (((((*o) >> 2) & 0x3) + 0x2) % 0x3) | (((((*o) << 8) & 0x300) + 0x100) % 0x300) | ((*o) & 0xf0f0);
}

//0x353137
// 2 --+2--> 1 --+1--> 5 --+2--> 6 --+1--> 2
void move_b(unsigned long *p, unsigned short *o){
    *p = (((*p) << 3) & 070000000) | (((*p) >> 12) & 07000) | (((*p) >> 3) & 0700) | (((*p) << 12) & 07000000) | ((*p) & 0770077);
    *o = (((((*o) << 2) & 0xc000) + 0x8000) % 0xc000) | (((((*o) >> 8) & 0xc0) + 0x40) % 0xc0) | (((((*o) >> 2) & 0x30) + 0x20) % 0x30) | (((((*o) << 8) & 0x3000) + 0x1000) % 0x3000) | ((*o) & 0x0f0f);
}

//0x053f2e
// 5 --+0--> 6 --+0--> 7 --+0--> 8 --+0--> 5
void move_d(unsigned long *p, unsigned short *o){
    *p = (((*p) >> 3) & 0777) | (((*p) << 9) & 07000) | ((*p) & 077770000);
    *o = (((*o) >> 2) & 0x3f) | (((*o) << 6) & 0xc0) | ((*o) & 0xff00);
} 

void sexyMove(unsigned long *positions, unsigned short *orientations){
	move_r(positions, orientations);
        move_u(positions, orientations);
        move_r(positions, orientations);
        move_r(positions, orientations);
        move_r(positions, orientations);
        move_u(positions, orientations);
        move_u(positions, orientations);
        move_u(positions, orientations);
}

void prova(unsigned long *positions, unsigned short *orientations){
        sexyMove(positions, orientations);
        sexyMove(positions, orientations);
        sexyMove(positions, orientations);
        sexyMove(positions, orientations);
        sexyMove(positions, orientations);
        sexyMove(positions, orientations);
}

void effe(unsigned long *p, unsigned short *o){
	move_f(p,o);
	move_f(p,o);
	move_f(p,o);
	move_f(p,o);
}

void bi(unsigned long *p, unsigned short *o){
	move_b(p,o);
	move_b(p,o);
	move_b(p,o);
	move_b(p,o);
}

void double_t_double_t(unsigned long *p, unsigned short *o){
	move_r(p,o);
	move_r(p,o);
	move_u(p,o);
	move_r(p,o);
	move_r(p,o);
	move_u(p,o);
	move_u(p,o);
	move_f(p,o);
	move_f(p,o);
	move_u(p,o);
	move_f(p,o);
	move_f(p,o);
	move_b(p,o);
	move_b(p,o);
	move_u(p,o);
	move_b(p,o);
	move_b(p,o);
	move_u(p,o);
	move_u(p,o);
	move_r(p,o);
	move_r(p,o);
	move_u(p,o);
	move_r(p,o);
	move_r(p,o);
	move_u(p,o);
	move_u(p,o);
	move_d(p,o);
	move_d(p,o);
}