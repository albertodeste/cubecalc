#include <stdio.h>

static char const MOVE_U = 1;
static char const MOVE_R = 2;
static char const MOVE_F = 3;
static char const MOVE_L = 4;
static char const MOVE_B = 5;
static char const MOVE_D = 6;

unsigned long move_u(unsigned long p, unsigned short orientations){
    return ((p >> 3) & 07000000) | ((p >> 3) & 0700000) | ((p >> 3) & 070000) | ((p << 9) & 070000000) | (p & 00007777);
}

unsigned long move_r(unsigned long p, unsigned short orientations){
    return ((p << 3) & 07000000) | ((p >> 12) & 0700) | ((p >> 3) & 070) | ((p << 12) & 0700000) | (p & 070077007);
}

unsigned long move_l(unsigned long p, unsigned short orientations){
    return ((p >> 9) & 070000) | ((p >> 12) & 07) | ((p << 9) & 07000) | ((p << 12) & 070000000) | (p & 07700770);
}

unsigned long move_f(unsigned long p, unsigned short orientations){
    return ((p << 3) & 0700000) | ((p >> 12) & 070) | ((p >> 3) & 07) | ((p << 12) & 07000) | (p & 077007700);
}

unsigned long move_b(unsigned long p, unsigned short orientations){
    return ((p << 3) & 070000000) | ((p >> 12) & 07000) | ((p >> 3) & 0700) | ((p << 12) & 07000000) | (p & 00770077);
}

unsigned long move_d(unsigned long p, unsigned short orientations){
    return ((p >> 3) & 0700) | ((p >> 3) & 070) | ((p >> 3) & 07) | ((p << 9) & 07000) | (p & 077770000);
}        
