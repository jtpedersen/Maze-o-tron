#include "Cell.h"

#include <iostream>

Cell::Cell(const Grid& grid, int x, int y)
  : grid(grid), idx_(grid.idx(x,y)), x_(x), y_(y) {
}

Cell::Cell(Grid& grid)
  : Cell(grid, -1, -1) {
}


size_t Cell::hash() const {
  auto h = static_cast<size_t>(y_) << 32 | static_cast<size_t>(x_);
  std::cout << h  << "\n";
  return h;
}

bool Cell::operator<(const Cell &other) const {
  if (y_ == other.y_)
    return x_ < other.y_;
  return y_ < other.y_;
}

bool Cell::linked(int other) const {
  if (other < 0) return false;
  return edges.find(other) != edges.cend();
}

void Cell::link(int other) {
  if (linked(other))
    return;
  
  edges.insert(other);
  //std::cout << "link" << *this << this << " --- " << *other << other << std::endl;
  other->link(_idx);

}

void Cell::unlink(int other) {
  if (!other) return;
  auto it = edges.find(other);
  if ( it == edges.end())
    return;
  edges.erase(it);
  other->unlink(this);
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

const std::set<Cell*>& Cell::getEdges() const {
  return edges;
}

std::ostream& operator<<(std::ostream& os, const Cell& c) {
  os << "Cell(" << c.x() << ", " << c.y() << ")";
  return os;
}
