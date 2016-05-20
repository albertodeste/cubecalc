#include <pthread.h>
#include <stdlib.h>
#include "calcthread.c"

int main(void)
{
  pthread_t pth;
  
  char positions [21]= { 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 0};
  char orientations [21] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0};

  struct calc_thread_args *cube;
  cube = (struct calc_thread_args *) malloc(sizeof(struct calc_thread_args));
  cube->cube_positions = &positions[0];
  cube->cube_orientations = &orientations[0];

  pthread_create(&pth, NULL, calc_thread, (void *) cube);

  pthread_join(pth, NULL);
  //pthread_cancel(pth);

  return 0;
}
