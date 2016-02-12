#include "SideWinderMaker.h"
#include "Cell.h"
#include "util.h"

#include <iostream>
#include <cassert>

SideWinderMaker::SideWinderMaker(const Grid& grid)
  : grid(grid), idx(0) {
}

SideWinderMaker::~SideWinderMaker() {}

const Grid& SideWinderMaker::getGrid() const {
  return grid;
}
void SideWinderMaker::setGrid(const Grid& g) { grid = g;}
bool SideWinderMaker::isDone() const {
  return idx >= grid.size();
}

int SideWinderMaker::currentIdx() const {
  return idx;
}

void SideWinderMaker::step() {
  Cell *c = grid.get(idx++);
  if ( c->idx() == (grid.size()-1) ) // can not carve from last cell
    return;
  if (c->y() < (grid.h()-1)) 	// only add to run if possible to carve
    run.push_back(c);
  
  bool canGoEast = c->x() < (grid.w()-1);
  bool carveEast = run.empty() || (canGoEast && flipCoin());
  
  if ( carveEast) {
    c->link(c->E);
  } else {
    auto s = *(select_randomly(begin(run), end(run)));
    s->link(s->S);
    run.clear();
  }
}
