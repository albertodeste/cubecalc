#include <pthread.h>
#include <stdlib.h>
#include "calcthread.c"

int main(void)
{
  pthread_t pth;
  
  struct Cube *cube;
  cube = (struct Cube *) malloc(sizeof(struct Cube));
  cube->positions = malloc(4);
  cube->orientations = malloc(2);
  *cube->positions = 0x00053977;
  *cube->orientations = 0;
  
 // pthread_create(&pth, NULL, calc_thread, (void *) cube);

  pthread_join(pth, NULL);
  pthread_cancel(pth);

	//prova(cube->positions, cube->orientations);
	//double_t_double_t(cube->positions, cube->orientations);
	//printf("%l %lu\n", *cube->positions, *cube->orientations);
	//effe(cube->positions, cube->orientations);
	//printf("%lu %d\n",*cube->positions, *cube->orientations);
  
  return 0;
}
