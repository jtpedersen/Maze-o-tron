#include "BinTreeMaker.h"
#include "util.h"

#include <iostream>
#include <cassert>

BinTreeMaker::BinTreeMaker(Grid grid)
  : grid(grid), idx(0) {

}

const Grid& BinTreeMaker::getGrid() const {
  return grid;
}

bool BinTreeMaker::isDone() const {
  return idx >= grid.size();
}

void BinTreeMaker::step() {
  // Cell *c = grid.get(idx++);
  // std::vector<Cell*> ls;
  // if (c->W)
  //   ls.push_back(c->W);
  // if (c->N)
  //   ls.push_back(c->N);
  
  // if (ls.empty()) 
  //   return;
  
  // Cell *linkTo = *select_randomly(begin(ls), end(ls));
  // c->link(linkTo);
  // assert(grid.contains(c));
  // assert(grid.contains(c->N));
  // assert(grid.contains(c->W));
  // assert(grid.contains(linkTo));
  // assert( (linkTo == c->W) || (linkTo == c->N));
  // assert(c->linked(linkTo));
  // assert(linkTo->linked(c));

  // std::cout << idx  << "--" << ls.size() << "\n";
  // std::cout << "LINK:" << *c << " <--> " << *linkTo  << "\n";
  grid.dumpEdges();
}


