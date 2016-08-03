struct Cube
{
  unsigned long *positions;
  unsigned short *orientations;
  unsigned int lastId;
  char lastMove;
};

struct Cube * createCube(unsigned long positions, unsigned long orientations, unsigned int lastId)
{
  struct Cube *cube;
  cube = (struct Cube *) malloc(sizeof(struct Cube));
  cube->positions = malloc(4);
  cube->orientations = malloc(2);
  *cube->positions = 0x00053977;
  *cube->orientations = 0;
  cube->lastId = lastId;
  cube->lastMove = 0;
  return cube;
}
