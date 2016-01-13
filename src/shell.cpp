#include "Grid.h"
#include "util.h"

#include <iterator>
#include <iostream>
#include <cassert>

static void binTree(Grid& grid) {
  auto NW = [] (const Cell& c) {
    std::vector<Cell*> ls;
    if (c.E)
      ls.push_back(c.E);
    if (c.N)
      ls.push_back(c.N);
    return ls;
  };

  for (auto c: grid.cells) {
    auto nws = c.neighbors(); //NW(c);
    for(auto nc: nws)
      std::cout << nc << std::endl;
    auto linkTo = *select_randomly(begin(nws), end(nws));
    std::cout << "link" << c << " --- " << *linkTo << std::endl;
    c.link(linkTo);
    std::cout << grid.edgeCount() << "\n";

    assert(c.linked(linkTo));
    assert(linkTo->linked(&c));
  }
}

int main(int argc, char *argv[]) {
 
  Grid grid(3,3);
  std::cout << "******************************************************************************************" << std::endl;
  std::cout << grid << std::endl;
  auto c = grid.get(1,1);
  c->link( c->S);
  //  binTree(grid);
  std::cout << grid << std::endl;
  return 0;
}
