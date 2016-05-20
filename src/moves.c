#include <stdio.h>

static int const MOVE_U = 1;
static int const MOVE_R = 2;
static int const MOVE_F = 3;
static int const MOVE_L = 4;
static int const MOVE_B = 5;
static int const MOVE_D = 6;

unsigned long move_u(unsigned long p, char * orientations){
    return ((p >> 3) & 07000000) | ((p >> 3) & 0700000) | ((p >> 3) & 070000) | ((p << 9) & 070000000) | (p & 00007777);
}

unsigned long move_r(unsigned long p, char * orientations){
    return ((p << 3) & 07000000) | ((p >> 12) & 0700) | ((p >> 3) & 070) | ((p << 12) & 0700000) | (p & 070077007);
}

unsigned long move_l(unsigned long p, char * orientations){
    return ((p >> 9) & 070000) | ((p >> 12) & 07) | ((p << 9) & 07000) | ((p << 12) & 070000000) | (p & 07700770);
}

unsigned long move_f(unsigned long p, char * orientations){
    return ((p << 3) & 0700000) | ((p >> 12) & 070) | ((p >> 3) & 07) | ((p << 12) & 07000) | (p & 077007700);
}

unsigned long move_b(unsigned long p, char * orientations){
    return ((p << 3) & 070000000) | ((p >> 12) & 07000) | ((p >> 3) & 0700) | ((p << 12) & 07000000) | (p & 00770077);
}

unsigned long move_d(unsigned long p, char * orientations){
    return ((p >> 3) & 0700) | ((p >> 3) & 070) | ((p >> 3) & 07) | ((p << 9) & 07000) | (p & 077770000);
}        

/*void move_u(char * positions, char * orientations)
{
    //corners
    char tmp = positions[3];
    positions[3] = positions[2];
    positions[2] = positions[1];
    positions[1] = positions[0];
    positions[0] = tmp;
    //edges
    tmp = positions[11];
    positions[11] = positions[10];
    positions[10] = positions[9];
    positions[9] = positions[8];
    positions[8] = tmp;

    //corners
    tmp = orientations[3];
    orientations[3] = orientations[2];
    orientations[2] = orientations[1];
    orientations[1] = orientations[0];
    orientations[0] = tmp;
    //edges
    tmp = orientations[11];
    orientations[11] = orientations[10];
    orientations[10] = orientations[9];
    orientations[9] = orientations[8];
    orientations[8] = tmp;

}

void move_d(char *positions, char *orientations)
{
    //corners
    char tmp = positions[7];
    positions[7] = positions[6];
    positions[6] = positions[5];
    positions[5] = positions[4];
    positions[4] = tmp;
    //edges
    tmp = positions[19];
    positions[19] = positions[18];
    positions[18] = positions[17];
    positions[17] = positions[16];
    positions[16] = tmp;
    
    //corners
    tmp = orientations[7];
    orientations[7] = orientations[6];
    orientations[6] = orientations[5];
    orientations[5] = orientations[4];
    orientations[4] = tmp;
    //edges
    tmp = orientations[19];
    orientations[19] = orientations[18];
    orientations[18] = orientations[17];
    orientations[17] = orientations[16];
    orientations[16] = tmp;
}

void move_r(char *positions, char *orientations)
{
    //corners
    char tmp = positions[2];
    positions[2] = positions[6];
    positions[6] = positions[5];
    positions[5] = positions[1];
    positions[1] = tmp;
    //edges
    tmp = positions[9];
    positions[9] = positions[13];
    positions[13] = positions[17];
    positions[17] = positions[12];
    positions[12] = tmp;
    
    //corners
    tmp = orientations[2];
    orientations[2] = ((orientations[6] + 2) % 3) + 3;
    orientations[6] = ((orientations[5] + 1) % 3) + 3;
    orientations[5] = ((orientations[1] + 2) % 3) + 3;
    orientations[1] = ((tmp + 1) % 3) + 3;
    //edges
    tmp = orientations[9];
    orientations[9] = ((orientations[13] + 1) % 2) + 2;
    orientations[13] = ((orientations[17] + 1) % 2) + 2;
    orientations[17] = ((orientations[12] + 1) % 2) + 2;
    orientations[12] = ((tmp + 1) % 2) + 2;
}

void move_l(char *positions, char *orientations)
{
    //corners
    char tmp = positions[0];
    positions[0] = positions[4];
    positions[4] = positions[7];
    positions[7] = positions[3];
    positions[3] = tmp;
    //edges
    tmp = positions[11];
    positions[11] = positions[15];
    positions[15] = positions[19];
    positions[19] = positions[14];
    positions[14] = tmp;
    
    //corners
    tmp = orientations[0];
    orientations[0] = ((orientations[4] + 2) % 3) + 3;
    orientations[4] = ((orientations[7] + 1) % 3) + 3;
    orientations[7] = ((orientations[3] + 2) % 3) + 3;
    orientations[3] = ((tmp + 1) % 3) + 3;
    //edges
    tmp = orientations[11];
    orientations[11] = ((orientations[15] + 1) % 2) + 2;
    orientations[15] = ((orientations[19] + 1) % 2) + 2;
    orientations[19] = ((orientations[14] + 1) % 2) + 2;
    orientations[14] = ((tmp + 1) % 2) + 2;
}

void move_f(char *positions, char *orientations)
{
    //corners
    char tmp = positions[3];
    positions[3] = positions[7];
    positions[7] = positions[6];
    positions[6] = positions[2];
    positions[2] = tmp;
    //edges
    tmp = positions[10];
    positions[10] = positions[14];
    positions[14] = positions[18];
    positions[18] = positions[13];
    positions[13] = tmp;
    
    //corners
    tmp = orientations[3];
    orientations[3] = ((orientations[7] + 2) % 3) + 3;
    orientations[7] = ((orientations[6] + 1) % 3) + 3;
    orientations[6] = ((orientations[2] + 2) % 3) + 3;
    orientations[2] = ((tmp + 1) % 3) + 3;
    //edges
    tmp = orientations[10];
    orientations[10] = ((orientations[14] + 2) % 2) + 2;
    orientations[14] = ((orientations[18] + 2) % 2) + 2;
    orientations[18] = ((orientations[13] + 2) % 2) + 2;
    orientations[13] = ((tmp + 2) % 2) + 2;
}

void move_b(char *positions, char *orientations)
{
    //corners
    char tmp = positions[1];
    positions[1] = positions[5];
    positions[5] = positions[4];
    positions[4] = positions[0];
    positions[0] = tmp;
    //edges
    tmp = positions[8];
    positions[8] = positions[12];
    positions[12] = positions[16];
    positions[16] = positions[15];
    positions[15] = tmp;
    
    //corners
    tmp = orientations[1];
    orientations[1] = ((orientations[5] + 2) % 3) + 3;
    orientations[5] = ((orientations[4] + 1) % 3) + 3;
    orientations[4] = ((orientations[0] + 2) % 3) + 3;
    orientations[0] = ((tmp + 1) % 3) + 3;
    //edges
    tmp = orientations[8];
    orientations[8] = ((orientations[12] + 2) % 2) + 2;
    orientations[12] = ((orientations[16] + 2) % 2) + 2;
    orientations[16] = ((orientations[15] + 2) % 2) + 2;
    orientations[15] = ((tmp + 2) % 2) + 2;
}*/