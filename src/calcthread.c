#include "moves.c"

struct Cube
{
  unsigned long positions;
  unsigned short orientations;
};

//Maximum level of recursions to attempt (must become 18)
static char const REC_LEVELS = 7;

void rec(unsigned long positions, unsigned short orientations, char level, FILE *file, char last);

void *calc_thread(void *arg)
{
  struct Cube *cube;
  cube = (struct Cube *)arg;

  FILE * file = fopen("file.cube", "wb");

  rec(cube->positions, cube->orientations, 1, file, 0);

  return NULL;
}

void rec(unsigned long positions, unsigned short orientations, char level, FILE *file, char last)
{
  if (level > REC_LEVELS)
  {
    return;
  }
  
  if(last != MOVE_U)
  {//U moves set
    positions = move_u(positions, orientations);
  
    //fprintf(file, "%lu%lu", positions, orientations);

    rec(positions, orientations, level + 1, file, MOVE_U);

    positions = move_u(positions, orientations);

    //fprintf(file, "%lu%s", positions, orientations);

    rec(positions, orientations, level + 1, file, MOVE_U);

    positions = move_u(positions, orientations);

    //fprintf(file, "%lu%s", positions, orientations);

    rec(positions, orientations, level + 1, file, MOVE_U);

    positions = move_u(positions, orientations);
  }
  if(last != MOVE_D)
  {//D moves set
    positions = move_d(positions, orientations);
  
    //fprintf(file, "%lu%s", positions, orientations);

    rec(positions, orientations, level + 1, file, MOVE_D);

    positions = move_d(positions, orientations);

    //fprintf(file, "%lu%s", positions, orientations);

    rec(positions, orientations, level + 1, file, MOVE_D);

    positions = move_d(positions, orientations);

    //fprintf(file, "%lu%s", positions, orientations);

    rec(positions, orientations, level + 1, file, MOVE_D);

    positions = move_d(positions, orientations);
  }
    
    if(last != MOVE_R)
  {//U moves set
    positions = move_r(positions, orientations);
  
    //fprintf(file, "%lu%s", positions, orientations);

    rec(positions, orientations, level + 1, file, MOVE_R);

    positions = move_r(positions, orientations);

    //fprintf(file, "%lu%s", positions, orientations);

    rec(positions, orientations, level + 1, file, MOVE_R);

    positions = move_r(positions, orientations);

    //fprintf(file, "%lu%s", positions, orientations);

    rec(positions, orientations, level + 1, file, MOVE_R);

    positions = move_r(positions, orientations);
  }
    
    if(last != MOVE_L)
  {//U moves set
    positions = move_l(positions, orientations);
  
    //fprintf(file, "%lu%s", positions, orientations);

    rec(positions, orientations, level + 1, file, MOVE_L);

    positions = move_l(positions, orientations);

    //fprintf(file, "%lu%s", positions, orientations);

    rec(positions, orientations, level + 1, file, MOVE_L);

    positions = move_l(positions, orientations);

    //fprintf(file, "%lu%s", positions, orientations);

    rec(positions, orientations, level + 1, file, MOVE_L);

    positions = move_l(positions, orientations);
  }
    
    if(last != MOVE_F)
  {//U moves set
    positions = move_f(positions, orientations);
  
    //fprintf(file, "%lu%s", positions, orientations);

    rec(positions, orientations, level + 1, file, MOVE_F);

    positions = move_f(positions, orientations);

    //fprintf(file, "%lu%s", positions, orientations);

    rec(positions, orientations, level + 1, file, MOVE_F);

    positions = move_f(positions, orientations);

    //fprintf(file, "%lu%s", positions, orientations);

    rec(positions, orientations, level + 1, file, MOVE_F);

    positions = move_f(positions, orientations);
  }
    
    if(last != MOVE_B)
  {//U moves set
    positions = move_b(positions, orientations);
  
    //fprintf(file, "%lu%s", positions, orientations);

    rec(positions, orientations, level + 1, file, MOVE_B);

    positions = move_b(positions, orientations);

    //fprintf(file, "%lu%s", positions, orientations);

    rec(positions, orientations, level + 1, file, MOVE_B);

    positions = move_b(positions, orientations);

    //fprintf(file, "%lu%s", positions, orientations);

    rec(positions, orientations, level + 1, file, MOVE_B);

    positions = move_b(positions, orientations);
  }
}
