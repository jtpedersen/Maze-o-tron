#include "Grid.h"
#include "util.h"

#include <iterator>
#include <iostream>

static void binTree(Grid& grid) {
  
  auto NW = [] (const Cell& c) {
    std::vector<Cell*> ls;
    Cell *ns[] = { c.N, c.E};
    for (auto n : ns) {
      if (n) {
	ls.push_back(n);
      }
      return ls;
    }
  };

  for (auto c: grid.cells) {
    auto nws = NW(c);
    if (nws.size() < 1)
      continue;
    auto linkTo = *select_randomly(begin(nws), end(nws));
    std::cout << "link" << c << " --- " << *linkTo << std::endl;
    c.link(linkTo);
  }
}

int main(int argc, char *argv[]) {
 
  auto grid = new Grid(10,10);

  std::cout << *grid << std::endl;
  binTree(*grid);
  std::cout << *grid << std::endl;

  return 0;
}
