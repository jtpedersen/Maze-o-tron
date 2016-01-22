#include "BinTreeMaker.h"
#include "util.h"
#include "Cell.h"

#include <iostream>
#include <cassert>

BinTreeMaker::BinTreeMaker(const Grid& grid)
  : grid(grid), idx(0) {

}

BinTreeMaker::~BinTreeMaker() {

}

const Grid& BinTreeMaker::getGrid() const {
  return grid;
}

bool BinTreeMaker::isDone() const {
  return idx >= grid.size();
}

void BinTreeMaker::step() {
  Cell *c = grid.get(idx++);
  std::vector<int> ls;
  if (c->W >= 0)
    ls.push_back(c->W);
  if (c->N >= 0)
    ls.push_back(c->N);
  
  if (ls.empty()) 
    return;
  
  auto linkTo = *select_randomly(begin(ls), end(ls));
  c->link(linkTo);

  assert(grid.contains(c->idx()));
  assert(grid.contains(linkTo));
  assert( (linkTo == c->W) || (linkTo == c->N));
  assert(c->linked(linkTo));
  assert(grid.linked(linkTo,c->idx()));

}


