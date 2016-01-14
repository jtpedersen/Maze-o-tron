#include "Grid.h"
#include <BinTreeMaker.h>

#include <iterator>
#include <iostream>
#include <cassert>

// static void binTree(Grid& grid) {
//   auto NW = [] (const Cell& c) {
//     std::vector<Cell*> ls;
//     if (c.E)
//       ls.push_back(c.E);
//     if (c.N)
//       ls.push_back(c.N);
//     return ls;
//   };

//   for (auto& c: grid.cells) {
//     auto nws = NW(c);
//     if (nws.empty()) continue;
//     auto linkTo = *select_randomly(begin(nws), end(nws));

//     c.link(linkTo);
//     //    std::cout << "link " << c << " --- " << *linkTo << std::endl;
//     // std::cout << grid.edgeCount() << "\n";
//     assert(c.linked(linkTo));
//     assert(linkTo->linked(&c));
//   }
// }

int main(int argc, char *argv[]) {

  Grid grid(3,3);
  BinTreeMaker maker(grid);
  while(!maker.isDone()) {
    maker.step();
    std::cout << maker.getGrid() << std::endl;
  }
  return 0;
}
