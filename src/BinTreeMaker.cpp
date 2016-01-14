#include "BinTreeMaker.h"
#include "util.h"

#include <iostream>

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
  auto c = grid.get(idx++);
  std::vector<Cell*> ls;
  if (c->W)
    ls.push_back(c->W);
  if (c->S)
    ls.push_back(c->S);
  
  if (ls.empty()) 
    return;
  auto linkTo = *select_randomly(begin(ls), end(ls));
  c->link(linkTo);
  std::cout << idx  << "--" << ls.size() << " : " << *linkTo <<  "\n";
}


