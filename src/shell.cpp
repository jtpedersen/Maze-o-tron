#include <Grid.h>
#include <Cell.h>
#include <BinTreeMaker.h>

#include <UniDijkstra.h>


#include <iterator>
#include <iostream>
#include <cassert>
#include <chrono>

using Clock = std::chrono::high_resolution_clock;
using Ms = std::chrono::milliseconds;

void runDijkstra(const Grid& grid) {
  int cnt = 10;
  double sum = 0;
  for (int i = 0; i < cnt; i++) {

    UniDijkstra d(0);
    d.setGrid(grid);

    auto start = Clock::now();
    while( !d.isDone()) d.step();
    auto dur = Clock::now() - start;
    auto time = std::chrono::duration_cast< Ms >(dur).count();
    sum += time;
    std::cout << "It took " << time << "ms" << std::endl;
  }

  std::cout << "========================================\nAverage: " << (sum/cnt) << std::endl;

}

int main(int argc, char *argv[]) {
  int w = 3, h = 3;
  bool verbose = false;
  bool silent = false;
  if (argc > 1)
    w = h = atoi(argv[1]);

  if (argc > 2)
    h = atoi(argv[2]);
  
  if (argc > 3) {
    verbose = argv[3][0] == 'v';
    silent = argv[3][0] == 's';
  }
  
  Grid grid(w,h);
  BinTreeMaker maker;
  maker.setGrid(grid);
  
  while(!maker.isDone()) {
    if (verbose)
      std::cout << maker.grid() << std::endl;
    maker.step();
  }
  if (!silent) 
    std::cout << maker.grid() << std::endl;
  runDijkstra(maker.grid());
  return 0;
}
