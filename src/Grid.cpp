#include "Grid.h"
#include "util.h"

#include <cassert>
#include <sstream>
#include <iostream>

Grid::Grid(int w, int h): w_(w), h_(h) {
  for (int j = 0; j < h_; j++) {
    for (int i = 0; i < w_; i++) {
      cells.emplace_back( Cell{i,j} );
    }
  }

  for (int j = 0; j < h_; j++) {
    for (int i = 0; i < w_; i++) {
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
  if (x >=w_ || x < 0 || y >= h_ || y < 0)
    return nullptr;
  auto c = get(y * w_ + x);
  assert(c->x() == x);
  assert(c->y() == y);
  return c;
}

const Cell* Grid::get(int x, int y) const {
  if (x >=w_ || x < 0 || y >= h_ || y < 0)
    return nullptr;
  auto c = get(y * w_ + x);
  assert(c->x() == x);
  assert(c->y() == y);
  return c;
}

Cell* Grid::get(int idx) {
  assert(idx>=0);
  assert(idx < size());
  return & (cells[idx]);
}

const Cell* Grid::get(int idx) const {
  assert(idx>=0);
  assert(idx < size());
  return & (cells[idx]);
}


Cell* Grid::randomCell() {
  return & (*select_randomly(begin(cells), end(cells)));
}

int Grid::edgeCount() {
  int cnt = 0;
  for (auto c: cells)
    cnt += c.getEdges().size();
  return cnt;
}

void Grid::dumpEdges() {
  for (auto a: cells) {
    std::cout << a << ":\n";
    for (auto b : a.getEdges()) 
      std::cout << "\t" << *b << "\n";
  }
}

bool Grid::contains(const Cell* c) const {
    for(auto& p: cells) {
      auto *ptr = &p;
      if (ptr == c)
	return true;
    }
    return false;
}

int Grid::size() const {
  return w_*h_;
}
int Grid::w() const {
  return w_;
}
int Grid::h() const {
  return h_;
}

std::ostream& operator<<(std::ostream& os, const Grid& g) {
  std::stringstream ss;
  ss << "+";
  for (int i = 0; i < g.w(); i++) {
    ss << "---+";
  }
  os << ss.str() << std::endl;

  for (int j = 0; j < g.h(); j++) {
    std::stringstream top;
    std::stringstream bottom;
    top << "|";
    bottom << "+";
    for (int i = 0; i < g.w(); i++) {
      auto c = g.get(i, j);
      top << "   " << ( c->linked(c->E) ? " " : "|");
      bottom << ( c->linked(c->S) ? "   " : "---") << "+";
    }
    os << top.str() << std::endl;
    os << bottom.str() << std::endl;

  }

  return os;
}
