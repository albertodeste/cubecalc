#include <stdlib.h>
#include <stdio.h>
#include "cube.c"

int main(void)
{
  struct Cube *cube = createCube(0, 0, 0);
  *cube->positions = 0x057799;
  *cube->orientations = 0;
  char moves[6] = {0,0,0,0,0,0};

  //Creating file
  FILE *file = fopen("2x2.cube", "w+");
  fclose(file);

  //Opening file for writing as byte
  file = fopen("2x2.cube", "r+");
  //fseek(file, 0, SEEK_SET);

  fwrite(cube->positions, 1, 3, file);

  fclose(file);

  return 0;
}

