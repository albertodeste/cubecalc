#include <stdio.h>

static int const MOVE_U = 1;
static int const MOVE_R = 2;
static int const MOVE_F = 3;
static int const MOVE_L = 4;
static int const MOVE_B = 5;
static int const MOVE_D = 6;

void move_u(char * positions, char * orientations)
{
  char tmp = positions[3];
  positions[3] = positions[2];
  positions[2] = positions[1];
  positions[1] = positions[0];
  positions[0] = tmp;
}

void move_d(char *positions, char *orientations)
{
  char tmp = positions[7];
  positions[7] = positions[6];
  positions[6] = positions[5];
  positions[5] = positions[4];
  positions[4] = tmp;
}
