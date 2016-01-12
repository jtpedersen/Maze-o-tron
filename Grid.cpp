#include "Grid.h"
#include "util.h"

#include <cassert>

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

Cell* Grid::get(int x, int y) {
  if (x >=w || x < 0 || y >= h || y < 0)
    return nullptr;
  Cell* c = & (cells[y*w+x]);
  assert(c->x() == x);
  assert(c->y() == y);
  return c;
}

Cell* Grid::randomCell() {
  return & (*select_randomly(begin(cells), end(cells)));
}
