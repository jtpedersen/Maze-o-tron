#include <Grid.h>
#include <Cell.h>
#include <BinTreeMaker.h>

#include <iterator>
#include <iostream>
#include <cassert>

int main(int argc, char *argv[]) {
  int w = 3, h = 3;
  bool verbose = false;
  if (argc > 1)
    w = h = atoi(argv[1]);

  if (argc > 2)
    h = atoi(argv[2]);
  
  if (argc > 3)
    verbose = true;
  
  Grid grid(w,h);
  BinTreeMaker maker(grid);
  while(!maker.isDone()) {
    if (verbose)
      std::cout << maker.getGrid() << std::endl;
    maker.step();
  }
  std::cout << maker.getGrid() << std::endl;
  return 0;
}
