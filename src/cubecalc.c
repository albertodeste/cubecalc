#include <pthread.h>
#include <stdlib.h>
#include "calcthread.c"
#include "neo4j.c"

int main(void)
{
  pthread_t pth;
  
  struct Cube *cube;
  cube = (struct Cube *) malloc(sizeof(struct Cube));
  cube->positions = malloc(4);
  cube->orientations = malloc(2);
  *cube->positions = 0x00053977;
  *cube->orientations = 0;
  
  //pthread_create(&pth, NULL, calc_thread, (void *) cube);

  int id = run_query("MERGE (c:Cube:Solved {positions:\"53977\", orientations:\"0\"}) RETURN id(c)");
  printf("%d\n", id);
  //pthread_join(pth, NULL);
  //pthread_cancel(pth);

	//prova(cube->positions, cube->orientations);
	//double_t_double_t(cube->positions, cube->orientations);
	//printf("%l %lu\n", *cube->positions, *cube->orientations);
	//effe(cube->positions, cube->orientations);
	//printf("%lu %d\n",*cube->positions, *cube->orientations);
  
  return 0;
}
