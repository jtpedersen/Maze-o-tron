#include "Grid.h"
#include "Cell.h"
#include "util.h"

#include <cassert>
#include <sstream>
#include <iostream>

Grid::Grid(int w, int h): w_(w), h_(h) {
  for (int j = 0; j < h_; j++) {
    for (int i = 0; i < w_; i++) {
      cells.emplace_back( Cell{this, i,j} );
    }
  }
}

Cell* Grid::get(const int idx)  {
  if (idx < 0 || idx >= size())
    return nullptr;
  auto ptr = & (cells[idx]);
  ptr->setGrid(this);
  return ptr;
}

const Cell* Grid::get(const int idx) const {
  if (idx < 0 || idx >= size())
    return nullptr;
  auto ptr = const_cast<Cell*> (& (cells[idx]));
  ptr->setGrid(const_cast<Grid*>(this));
  return ptr;
}

Cell* Grid::get(const int x, const int y) {
  return get(idx(x,y));
}

const std::vector<Cell>& Grid::getCells() const {
  return cells;
}

Cell* Grid::randomCell() {
  return & (*select_randomly(begin(cells), end(cells)));
}

int Grid::edgeCount() {
  int cnt = 0;
  for(auto& e: edges) 
    cnt += (e.second).size();
  return cnt;
}

void Grid::dumpEdges() {
  for(auto& e: edges) {
    std::cout << e.first << "->\n";
    for (auto& v :(e.second))
      std::cout << "\t" << v << std::endl;
  }
}

bool Grid::contains(const int idx) const {
  if (idx < 0 || idx >= size())
    return false;
  return cells[idx].valid();
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

int Grid::idx(const int x, const int y) const {
  return y * w_ + x;
}

void Grid::addEdge(const int a, const int b) {
  edges[a].insert(b);
}
void Grid::removeEdge(const int a, const int b) {

}
bool Grid::linked(const int a, const int b) const {
  auto it = edges.find(a);
  if (it == edges.end())
    return false;
  auto out = (*it).second;
  return out.count(b) > 0;
}

bool Grid::linked(const Cell* a, const int b) const {
  return linked(a->idx(), b);
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
      auto idx = g.idx(i, j);
      auto c = g.get( idx);
      top << "   " << ( g.linked(c, c->E) ? " " : "|");
      bottom << ( g.linked(c,c->S) ? "   " : "---") << "+";
    }
    os << top.str() << std::endl;
    os << bottom.str() << std::endl;

  }

  return os;
}
