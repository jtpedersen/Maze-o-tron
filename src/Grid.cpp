#include "Grid.h"
#include "util.h"

#include <cassert>
#include <sstream>

Grid::Grid(int w, int h): w(w), h(h) {
  for (int j = 0; j < h; j++) {
    for (int i = 0; i < w; i++) {
      cells.emplace_back( Cell{i,j} );
    }
  }

  for (int j = 0; j < h; j++) {
    for (int i = 0; i < w; i++) {
      auto c = get(i,j);
      c->N = get(i,j-1);
      c->E = get(i+1,j); 
      c->S = get(i,j+1);
      c->W = get(i-1,j);
    }
  }
}
// TODO: c++ trick to const cast to same function
Cell* Grid::get(int x, int y) {
  if (x >=w || x < 0 || y >= h || y < 0)
    return nullptr;
  auto* c = & (cells[y*w+x]);
  assert(c->x() == x);
  assert(c->y() == y);
  return c;
}

const Cell* Grid::get(int x, int y) const {
  if (x >=w || x < 0 || y >= h || y < 0)
    return nullptr;
  auto* c = & (cells[y*w+x]);
  assert(c->x() == x);
  assert(c->y() == y);
  return c;
}


Cell* Grid::randomCell() {
  return & (*select_randomly(begin(cells), end(cells)));
}


std::ostream& operator<<(std::ostream& os, const Grid& g) {
  std::stringstream ss;
  ss << "+";
  for (int i = 0; i < g.w; i++) {
    ss << "---+";
  }
  os << ss.str() << std::endl;

  for (int j = 0; j < g.h; j++) {
    std::stringstream top;
    std::stringstream bottom;
    top << "|";
    bottom << "+";
    for (int i = 0; i < g.w; i++) {
      auto c = g.get(i, j);
      top << "   " << ( c->linked(c->E) ? " " : "|");
      bottom << ( c->linked(c->S) ? "   " : "---") << "+";
    }
    os << top.str() << std::endl;
    os << bottom.str() << std::endl;

  }

  return os;
}
