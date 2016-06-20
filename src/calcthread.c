#include "moves.c"

struct Cube
{
  unsigned long *positions;
  unsigned short *orientations;
};

//Maximum level of recursions to attempt (must become 18 for 3x3, 12 for 2x2)
static char const REC_LEVELS = 10;

void rec(unsigned long *positions, unsigned short *orientations, char level, FILE *file, char last);

void *calc_thread(void *arg)
{
  struct Cube *cube;
  cube = (struct Cube *)arg;

  FILE * file = fopen("file.cube", "wb");

  rec(cube->positions, cube->orientations, 1, file, 0);

  fclose(file);

  return NULL;
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

void rec(unsigned long *positions, unsigned short *orientations, char level, FILE *file, char last)
{
  if (level > REC_LEVELS)
  {
    return;
  }

  if(last != MOVE_U)
  {//U moves set
    move_u(positions, orientations);
  
    fwrite(positions, 1, 3, file);
    fwrite(orientations, 1, 2, file);

    rec(positions, orientations, level + 1, file, MOVE_U);

    move_u(positions, orientations);

    fwrite(positions, 1, 3, file);
    fwrite(orientations, 1, 2, file);

    rec(positions, orientations, level + 1, file, MOVE_U);

    move_u(positions, orientations);

    fwrite(positions, 1, 3, file);
    fwrite(orientations, 1, 2, file);

    rec(positions, orientations, level + 1, file, MOVE_U);

    move_u(positions, orientations);
  }

  if(last != MOVE_R)
  {//U moves set
    move_r(positions, orientations);
  
    fwrite(positions, 1, 3, file);
    fwrite(orientations, 1, 2, file);

    rec(positions, orientations, level + 1, file, MOVE_R);

    move_r(positions, orientations);

    fwrite(positions, 1, 3, file);
    fwrite(orientations, 1, 2, file);

    rec(positions, orientations, level + 1, file, MOVE_R);

    move_r(positions, orientations);

    fwrite(positions, 1, 3, file);
    fwrite(orientations, 1, 2, file);

    rec(positions, orientations, level + 1, file, MOVE_R);

    move_r(positions, orientations);
  }  

  if(last != MOVE_F)
  {//U moves set
    move_f(positions, orientations);
  
    fwrite(positions, 1, 3, file);
    fwrite(orientations, 1, 2, file);

    rec(positions, orientations, level + 1, file, MOVE_F);

    move_f(positions, orientations);

    fwrite(positions, 1, 3, file);
    fwrite(orientations, 1, 2, file);

    rec(positions, orientations, level + 1, file, MOVE_F);

    move_f(positions, orientations);

    fwrite(positions, 1, 3, file);
    fwrite(orientations, 1, 2, file);

    rec(positions, orientations, level + 1, file, MOVE_F);

    move_f(positions, orientations);
  } 
/*
  if(last != MOVE_B)
  {//U moves set
    move_b(positions, orientations);
  
    fwrite(positions, 1, 3, file);
    fwrite(orientations, 1, 2, file);

    rec(positions, orientations, level + 1, file, MOVE_B);

    move_b(positions, orientations);

    fwrite(positions, 1, 3, file);
    fwrite(orientations, 1, 2, file);

    rec(positions, orientations, level + 1, file, MOVE_B);

    move_b(positions, orientations);

    fwrite(positions, 1, 3, file);
    fwrite(orientations, 1, 2, file);

    rec(positions, orientations, level + 1, file, MOVE_B);

    move_b(positions, orientations);
  }

  if(last != MOVE_L)
  {//U moves set
    move_l(positions, orientations);
  
    fwrite(positions, 1, 3, file);
    fwrite(orientations, 1, 2, file);

    rec(positions, orientations, level + 1, file, MOVE_L);

    move_l(positions, orientations);

    fwrite(positions, 1, 3, file);
    fwrite(orientations, 1, 2, file);

    rec(positions, orientations, level + 1, file, MOVE_L);

    move_l(positions, orientations);

    fwrite(positions, 1, 3, file);
    fwrite(orientations, 1, 2, file);

    rec(positions, orientations, level + 1, file, MOVE_L);

    move_l(positions, orientations);
  }

  if(last != MOVE_D)
  {//D moves set
    move_d(positions, orientations);
  
    fwrite(positions, 1, 3, file);
    fwrite(orientations, 1, 2, file);

    rec(positions, orientations, level + 1, file, MOVE_D);

    move_d(positions, orientations);

    fwrite(positions, 1, 3, file);
    fwrite(orientations, 1, 2, file);

    rec(positions, orientations, level + 1, file, MOVE_D);

    move_d(positions, orientations);

    fwrite(positions, 1, 3, file);
    fwrite(orientations, 1, 2, file);

    rec(positions, orientations, level + 1, file, MOVE_D);

    move_d(positions, orientations);
  }
*/
}
