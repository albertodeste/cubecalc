#include <pthread.h>
#include <stdlib.h>
#include "calcthread.c"

void new_version()
{
  FILE *f = fopen("res.hex", "wb");
  //Setup as solved cube
  unsigned long p = 0x00053977;
  unsigned short o = 0;
  printf("Solved cube: %ld - %d\n", p, o);
  fwrite(&p, 1, 3, f);
  //Execute a R move
  p = ((p << 3) & 07000000) | ((p >> 12) & 0700) | ((p >> 3) & 070) | ((p << 12) & 0700000) | (p & 070077007);
  //TODO update o using mod solution
  printf("R: %ld - %d\n", p, o);
    p = 0x00053977;
    //Execute front move
    p = ((p << 3) & 0700000) | ((p >> 12) & 070) | ((p >> 3) & 07) | ((p << 12) & 07000) | (p & 077007700);
    printf("F: %ld - %d\n", p, o);
    
    p = 0x00053977;
    //Execute left move
    p = ((p >> 9) & 070000) | ((p >> 12) & 07) | ((p << 9) & 07000) | ((p << 12) & 070000000) | (p & 07700770);
    printf("L: %ld - %d\n", p, o);
    
    p = 0x00053977;
    //Execute back move
    p = ((p << 3) & 070000000) | ((p >> 12) & 07000) | ((p >> 3) & 0700) | ((p << 12) & 07000000) | (p & 00770077);
    printf("B: %ld - %d\n", p, o);
    
    p = 0x00053977;
    //Execute up move
    p = ((p >> 3) & 07000000) | ((p >> 3) & 0700000) | ((p >> 3) & 070000) | ((p << 9) & 070000000) | (p & 00007777);
    printf("U: %ld - %d\n", p, o);
    
    p = 0x00053977;
    //Execute down move
    p = ((p >> 3) & 0700) | ((p >> 3) & 070) | ((p >> 3) & 07) | ((p << 9) & 07000) | (p & 077770000);
    printf("D: %ld - %d\n", p, o);
    
  fwrite(&p, 1, 3, f);
  fwrite(&o, 1, 2, f);
  fclose(f);
}

int main(void)
{
  pthread_t pth;
  
  char positions [21]= { 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 0};
  char orientations [21] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0};
    unsigned long solved = 0x00053977;

  struct calc_thread_args *cube;
  cube = (struct calc_thread_args *) malloc(sizeof(struct calc_thread_args));
  cube->cube_positions = &positions[0];
    cube->cube_positions_long = solved;
  cube->cube_orientations = &orientations[0];

  pthread_create(&pth, NULL, calc_thread, (void *) cube);

  pthread_join(pth, NULL);
  //pthread_cancel(pth);
  

  //new_version();

  return 0;
}
