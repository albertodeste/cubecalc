#include "moves.c"

//Choose if the result should be written to file or into database
static char const WRITE_TO_FILE = 0;

//Maximum level of recursions to attempt (must become 18 for 3x3, 12 for 2x2)
static char const REC_LEVELS = 5;

static char const MOVES_STATES[3] = {' ', '2', 'i'};
static char const MOVE_FORMAT[4] = "%c%c";

void rec(unsigned long *positions, unsigned short *orientations, char level, FILE *file, char last, int lastId);

void *calc_thread(void *arg)
{
  struct Cube *cube;
  cube = (struct Cube *)arg;

  FILE * file = fopen("file.cube", "wb");

  rec(cube->positions, cube->orientations, 1, file, cube->lastMove, cube->lastId);

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
  char move[4]; 
  int index;

  if(last != MOVE_U)
  {//U moves set
    move_u(positions, orientations);
 
    for(index = 0; index < 3; index++)
    {
      sprintf(move, "%c%c", 'U', MOVES_STATES[index]);
      id = persist(file, positions, orientations, lastId, move);
      rec(positions, orientations, level + 1, file, MOVE_U, id);
      move_u(positions, orientations);
    }
  }

  if(last != MOVE_R)
  {//R moves set
    move_r(positions, orientations);
 
    for(index = 0; index < 3; index++)
    {
      sprintf(move, "%c%c", 'R', MOVES_STATES[index]);
      id = persist(file, positions, orientations, lastId, move);
      rec(positions, orientations, level + 1, file, MOVE_R, id);
      move_r(positions, orientations);
    }
  }  

  if(last != MOVE_F)
  {//F moves set
    move_f(positions, orientations);
    
    for(index = 0; index < 3; index++)
    {
      sprintf(move, "%c%c", 'F', MOVES_STATES[index]);
      id = persist(file, positions, orientations, lastId, move);
      rec(positions, orientations, level + 1, file, MOVE_F, id);
      move_f(positions, orientations);
    }  
  } 
/*
  if(last != MOVE_B)
  {//B moves set
    move_b(positions, orientations);
    
    for(index = 0; index < 3; index++)
    {
      sprintf(move, "%c%c", 'B', MOVES_STATES[index]);
      id = persist(file, positions, orientations, lastId, move);
      rec(positions, orientations, level + 1, file, MOVE_B, id);
      move_b(positions, orientations);
    }
  }

  if(last != MOVE_L)
  {//L moves set
    move_l(positions, orientations);
    
    for(index = 0; index < 3; index++)
    {
      sprintf(move, "%c%c", 'L', MOVES_STATES[index]);
      id = persist(file, positions, orientations, lastId, move);
      rec(positions, orientations, level + 1, file, MOVE_L, id);
      move_l(positions, orientations);
    }
  }

  if(last != MOVE_D)
  {//D moves set
    move_d(positions, orientations);
    
    for(index = 0; index < 3; index++)
    {
      sprintf(move, "%c%c", 'D', MOVES_STATES[index]);
      id = persist(file, positions, orientations, lastId, move);
      rec(positions, orientations, level + 1, file, MOVE_D, id);
      move_d(positions, orientations);
    }
  }
*/
}
