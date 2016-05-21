#include <pthread.h>
#include <stdlib.h>
#include "calcthread.c"

int main(void)
{
  pthread_t pth;
  
  struct Cube *cube;
  cube = (struct Cube *) malloc(sizeof(struct Cube));
  cube->positions = 0x00053977;
  cube->orientations = 0;

  pthread_create(&pth, NULL, calc_thread, (void *) cube);

  pthread_join(pth, NULL);
  //pthread_cancel(pth);
  

  //new_version();

  return 0;
}
