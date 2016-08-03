#include "moves.c"

struct Cube
{
  unsigned long *positions;
  unsigned short *orientations;
  unsigned int lastId;
};

//Choose if the result should be written to file or into database
static char const WRITE_TO_FILE = 0;

//Maximum level of recursions to attempt (must become 18 for 3x3, 12 for 2x2)
static char const REC_LEVELS = 5;

void rec(unsigned long *positions, unsigned short *orientations, char level, FILE *file, char last, int lastId);

void *calc_thread(void *arg)
{
  struct Cube *cube;
  cube = (struct Cube *)arg;

  FILE * file = fopen("file.cube", "wb");

  rec(cube->positions, cube->orientations, 1, file, 0, cube->lastId);

  fclose(file);

  return NULL;
}

int persist(FILE *file, unsigned long *positions, unsigned short *orientations, int lastId, char* move)
{
  int result = -1;
  if(WRITE_TO_FILE)
  {
    fwrite(positions, 1, 3, file);
    fwrite(orientations, 1, 2, file);
  } 
  else
  {
    char query[200];
    sprintf(query, "MATCH (o) WHERE id(o) = %d WITH o CREATE (c:Cube {positions:%lu, orientations:%hu})<-[:%s]-(o) RETURN id(c)", lastId, *positions, *orientations, move);
    result = run_query(query);
  }
  return result;
}

void rec(unsigned long *positions, unsigned short *orientations, char level, FILE *file, char last, int lastId)
{
  if (level > REC_LEVELS)
  {
    return;
  }
  
  int id = -1;

  if(last != MOVE_U)
  {//U moves set
    move_u(positions, orientations);
 
    id = persist(file, positions, orientations, lastId, "U");

    rec(positions, orientations, level + 1, file, MOVE_U, id);

    move_u(positions, orientations);

    id = persist(file, positions, orientations, lastId, "U2");

    rec(positions, orientations, level + 1, file, MOVE_U, id);

    move_u(positions, orientations);

    id = persist(file, positions, orientations, lastId, "Ui");

    rec(positions, orientations, level + 1, file, MOVE_U, id);

    move_u(positions, orientations);
  }

  if(last != MOVE_R)
  {//R moves set
    move_r(positions, orientations);
  
    id = persist(file, positions, orientations, lastId, "R");

    rec(positions, orientations, level + 1, file, MOVE_R, id);

    move_r(positions, orientations);

    id = persist(file, positions, orientations, lastId, "R2");

    rec(positions, orientations, level + 1, file, MOVE_R, id);

    move_r(positions, orientations);

    id = persist(file, positions, orientations, lastId, "Ri");

    rec(positions, orientations, level + 1, file, MOVE_R, id);

    move_r(positions, orientations);
  }  

  if(last != MOVE_F)
  {//F moves set
    move_f(positions, orientations);
  
    id = persist(file, positions, orientations, lastId, "F");

    rec(positions, orientations, level + 1, file, MOVE_F, id);

    move_f(positions, orientations);

    id = persist(file, positions, orientations, lastId, "F2");

    rec(positions, orientations, level + 1, file, MOVE_F, id);

    move_f(positions, orientations);

    id = persist(file, positions, orientations, lastId, "Fi");

    rec(positions, orientations, level + 1, file, MOVE_F, id);

    move_f(positions, orientations);
  } 
/*
  if(last != MOVE_B)
  {//B moves set
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
  {//L moves set
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
