#include "Cell.h"
#include "Grid.h"

#include <iostream>

Cell::Cell(Grid* grid, int x, int y)
  : grid(grid), x_(x), y_(y) {

  if (y > 0)
    N = grid->idx(x, y-1);
  if (x < grid->w() - 1)
    E = grid->idx(x+1, y);
  if (y < grid->h() -1)
    S = grid->idx(x, y+1);
  if ( x_ > 0)
    W = grid->idx(x-1, y);
}

int Cell::idx() const{
  return grid->idx(x_, y_);
}
bool Cell::valid() const{
  return x_ >=0 && y_ >= 0;
}

void Cell::setGrid(Grid* g) {
  this->grid = g;
}
// size_t Cell::hash() const {
//   auto h = static_cast<size_t>(y_) << 32 | static_cast<size_t>(x_);
//   std::cout << h  << "\n";
//   return h;
// }

bool Cell::operator<(const Cell &other) const {
  if (y_ == other.y_)
    return x_ < other.y_;
  return y_ < other.y_;
}

bool Cell::linked(const int other) const {
  return grid->linked(idx(), other);
}

void Cell::link(const int other) {
  grid->addEdge(idx(), other);
  grid->addEdge(other, idx());
}

void Cell::unlink(int other) {
  grid->removeEdge(idx(), other);
  grid->removeEdge(other, idx());
}


// std::vector<Cell*> Cell::neighbors() const {
//   std::vector<Cell*> ls;
//   Cell *ns[] = { N, E, S, W};
//   for (auto n : ns) {
//     if (n) {
//       ls.push_back(n);
//     }
//   }
//   return ls;
// }

int Cell::x() const {
  return x_;
}
int Cell::y() const {
  return y_;
}

std::ostream& operator<<(std::ostream& os, const Cell& c) {
  os << "Cell(" << c.x() << ", " << c.y() << ")";
  return os;
}
