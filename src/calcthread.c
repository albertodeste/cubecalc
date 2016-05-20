#include "moves.c"

struct calc_thread_args 
{
  char * cube_positions;
  char * cube_orientations;
};

//Maximum level of recursions to attempt (must become 18)
static int const REC_LEVELS = 14;

void rec(char *positions, char *orientations, int level, FILE *file, int last);

void *calc_thread(void *arg)
{
  struct calc_thread_args *cube;
  cube = (struct calc_thread_args *)arg;

  FILE * file = fopen("file.cube", "w");

  rec(cube->cube_positions, cube->cube_orientations, 1, file, 0);

  return NULL;
}

void rec(char *positions, char *orientations, int level, FILE *file, int last)
{
  if (level > REC_LEVELS)
  {
    return;
  }
  
  if(last != MOVE_U)
  {//U moves set
    move_u(positions, orientations);
  
    fprintf(file, "%s%s", positions, orientations);

    rec(positions, orientations, level + 1, file, MOVE_U);

    move_u(positions, orientations);

    fprintf(file, "%s%s", positions, orientations);

    rec(positions, orientations, level + 1, file, MOVE_U);

    move_u(positions, orientations);

    fprintf(file, "%s%s", positions, orientations);

    rec(positions, orientations, level + 1, file, MOVE_U);

    move_u(positions, orientations);
  }
  if(last != MOVE_D)
  {//D moves set
    move_d(positions, orientations);
  
    fprintf(file, "%s%s", positions, orientations);

    rec(positions, orientations, level + 1, file, MOVE_D);

    move_d(positions, orientations);

    fprintf(file, "%s%s", positions, orientations);

    rec(positions, orientations, level + 1, file, MOVE_D);

    move_d(positions, orientations);

    fprintf(file, "%s%s", positions, orientations);

    rec(positions, orientations, level + 1, file, MOVE_D);

    move_d(positions, orientations);
  }
}
