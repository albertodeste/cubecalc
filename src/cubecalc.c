#include <pthread.h>
#include <stdlib.h>
#include "neo4j.c"
#include "cube.c"
#include "calcthread.c"

int main(void)
{
  pthread_t pth[9];
  char query[200];
  
  int solvedCubeId = run_query("CREATE (c:Cube:Solved {positions:\"53977\", orientations:\"0\"}) RETURN id(c)");

  int i;
  char *moves[9] = {"U", "U2", "Ui", "R", "R2", "Ri", "F", "F2", "Fi"}; 
  char movesId[3] = {MOVE_U, MOVE_R, MOVE_F};
  for(i = 0; i < 9; i++)
  {
    struct Cube *cube = createCube(0x00053977, 0, solvedCubeId);  
    
    switch(i){
      case 0:
        move_u(cube->positions, cube->orientations);
        break;
      case 1:
        move_u(cube->positions, cube->orientations);
        move_u(cube->positions, cube->orientations);
        break;
      case 2:
        move_u(cube->positions, cube->orientations);
        move_u(cube->positions, cube->orientations);
        move_u(cube->positions, cube->orientations);
        break;
      case 3:
        move_r(cube->positions, cube->orientations);
        break;
      case 4:
        move_r(cube->positions, cube->orientations);
        move_r(cube->positions, cube->orientations);
        break;
      case 5:
        move_r(cube->positions, cube->orientations);
        move_r(cube->positions, cube->orientations);
        move_r(cube->positions, cube->orientations);
        break;
      case 6:
        move_f(cube->positions, cube->orientations);
        break;
      case 7:
        move_f(cube->positions, cube->orientations);
        move_f(cube->positions, cube->orientations);
        break;
      case 8:
        move_f(cube->positions, cube->orientations);
        move_f(cube->positions, cube->orientations);
        move_f(cube->positions, cube->orientations);
        break;
    } 

    sprintf(query, "MATCH (o) WHERE id(o) = %d WITH o CREATE (c:Cube {positions:%lu, orientations:%hu})<-[:%s]-(o) RETURN id(c)", cube->lastId, *cube->positions, *cube->orientations, moves[i]);

    cube->lastId = run_query(query);
    cube->lastMove = movesId[i/3];

    pthread_create(&pth[i], NULL, calc_thread, (void *) cube);
  }


  //TODO refactor
  pthread_join(pth[0], NULL);
  pthread_join(pth[1], NULL);
  pthread_join(pth[2], NULL);
  pthread_join(pth[3], NULL);
  pthread_join(pth[4], NULL);
  pthread_join(pth[5], NULL);
  pthread_join(pth[6], NULL);
  pthread_join(pth[7], NULL);
  pthread_join(pth[8], NULL);

  //pthread_cancel(pth);
  
  return 0;
}
