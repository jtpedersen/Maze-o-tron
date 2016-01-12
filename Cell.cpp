#include "Cell.h"

Cell::Cell(int x, int y)
  : x_(x), y_(y) {
}

size_t Cell::hash() const {
  return static_cast<size_t>(y_) << 32 | static_cast<size_t>(x_);
}

bool Cell::operator<(const Cell &other) const {
  if (y_ == other.y_)
    return x_ < other.y_;
  return y_ < other.y_;
}

void Cell::link(Cell& other) {
  if (edges.find(other) != edges.end())
    return;
  edges.insert(other);
  other.link(*this);
}

void Cell::unlink(Cell& other) {
  auto it = edges.find(other);
  if ( it == edges.end())
    return;
  edges.erase(it);
  other.unlink(*this);
}

std::vector<Cell*> Cell::neighbors() const {
  std::vector<Cell*> ls;
  Cell *ns[] = { N, E, S, W};

  for (auto n : ns) {
    if (n) {
      ls.push_back(n);
    }
  }
  return ls;
}

int Cell::x() const {
  return x_;
}
int Cell::y() const {
  return y_;
}

