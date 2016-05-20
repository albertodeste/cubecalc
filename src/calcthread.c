#include "moves.c"

struct calc_thread_args 
{
  char * cube_positions;
  char * cube_orientations;
};

//Maximum level of recursions to attempt (must become 18)
static int const REC_LEVELS = 7;

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
    
    if(last != MOVE_R)
  {//U moves set
    move_r(positions, orientations);
  
    fprintf(file, "%s%s", positions, orientations);

    rec(positions, orientations, level + 1, file, MOVE_R);

    move_r(positions, orientations);

    fprintf(file, "%s%s", positions, orientations);

    rec(positions, orientations, level + 1, file, MOVE_R);

    move_r(positions, orientations);

    fprintf(file, "%s%s", positions, orientations);

    rec(positions, orientations, level + 1, file, MOVE_R);

    move_r(positions, orientations);
  }
    
    if(last != MOVE_L)
  {//U moves set
    move_l(positions, orientations);
  
    fprintf(file, "%s%s", positions, orientations);

    rec(positions, orientations, level + 1, file, MOVE_L);

    move_l(positions, orientations);

    fprintf(file, "%s%s", positions, orientations);

    rec(positions, orientations, level + 1, file, MOVE_L);

    move_l(positions, orientations);

    fprintf(file, "%s%s", positions, orientations);

    rec(positions, orientations, level + 1, file, MOVE_L);

    move_l(positions, orientations);
  }
    
    if(last != MOVE_F)
  {//U moves set
    move_f(positions, orientations);
  
    fprintf(file, "%s%s", positions, orientations);

    rec(positions, orientations, level + 1, file, MOVE_F);

    move_f(positions, orientations);

    fprintf(file, "%s%s", positions, orientations);

    rec(positions, orientations, level + 1, file, MOVE_F);

    move_f(positions, orientations);

    fprintf(file, "%s%s", positions, orientations);

    rec(positions, orientations, level + 1, file, MOVE_F);

    move_f(positions, orientations);
  }
    
    if(last != MOVE_B)
  {//U moves set
    move_b(positions, orientations);
  
    fprintf(file, "%s%s", positions, orientations);

    rec(positions, orientations, level + 1, file, MOVE_B);

    move_b(positions, orientations);

    fprintf(file, "%s%s", positions, orientations);

    rec(positions, orientations, level + 1, file, MOVE_B);

    move_b(positions, orientations);

    fprintf(file, "%s%s", positions, orientations);

    rec(positions, orientations, level + 1, file, MOVE_B);

    move_b(positions, orientations);
  }
}
