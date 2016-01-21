#include <Grid.h>
#include <Cell.h>
#include <BinTreeMaker.h>

#include <iterator>
#include <iostream>
#include <cassert>

int main(int argc, char *argv[]) {

  Grid grid(3,3);
  BinTreeMaker maker(grid);
  while(!maker.isDone()) {
    maker.step();
    std::cout << maker.getGrid() << std::endl;
  }
  return 0;
}
