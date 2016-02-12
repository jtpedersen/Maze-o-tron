#include "RecursiveBacktrackerMaker.h"
#include "Cell.h"
#include "util.h"

#include <iostream>
#include <algorithm>

RecursiveBacktrackerMaker::~RecursiveBacktrackerMaker() {}

bool RecursiveBacktrackerMaker::isDone() const {
  return visited.size() == static_cast<unsigned int>(grid().size());
}

int RecursiveBacktrackerMaker::currentIdx() const {
  return idx;
}

bool RecursiveBacktrackerMaker::canditate(int idx) const {
  if (idx < 0)
    return false;
  return ! hasVisited(idx);
}

bool RecursiveBacktrackerMaker::hasVisited(int idx) const {
  return visited.end() != visited.find(idx);
}

void RecursiveBacktrackerMaker::step() {
  auto c = grid().get(idx);
  std::vector<int> ls { c->N, c->E, c->S, c->W};
  ls.erase(std::remove_if(begin(ls), end(ls), 
			  [this] (const int& i) {return !this->canditate(i);}),
	   end(ls));

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
