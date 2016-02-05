#include "RecursiveBacktrackerMaker.h"
#include "Cell.h"
#include "util.h"

#include <iostream>
#include <cassert>

RecursiveBacktrackerMaker::RecursiveBacktrackerMaker(const Grid& grid)
   : grid(grid)
{
  stack.push_back(0);
  visited.insert(0);
}

RecursiveBacktrackerMaker::~RecursiveBacktrackerMaker() {}

const Grid& RecursiveBacktrackerMaker::getGrid() const {
  return grid;
}

bool RecursiveBacktrackerMaker::isDone() const {
  return visited.size() == static_cast<unsigned int>(grid.size());
}

int RecursiveBacktrackerMaker::currentIdx() const {
  return idx;
}

bool RecursiveBacktrackerMaker::canditate(int idx) const {
  if (idx < 0)
    return false;
  return visited.end() == visited.find(idx);
}

void RecursiveBacktrackerMaker::step() {
  auto c = grid.get(idx);
  std::vector<int> ls;
  int dirs[] = { c->N, c->E, c->S, c->W};
  for (const auto& d: dirs)
    if (canditate(d))
      ls.push_back(d);

  if (ls.empty()) {
    idx = stack.back();
    stack.pop_back();
    return;
  }

  idx = *(select_randomly(begin(ls), end(ls)));
  c->link(idx);
  visited.insert(idx);
  stack.push_back(idx);

}