#ifndef GRID_H_
#define GRID_H_

#include <vector>
#include "Cell.h"

class Grid {

public:
  Grid(int w, int h);

  Cell* get(int idx);
  const Cell* get(int idx) const;

  Cell* get(int x, int y);
  const Cell* get(int x, int y) const;

  Cell* randomCell();

  int size() const;
  int w() const;
  int h() const;

  std::vector<Cell> cells;

  int edgeCount();
  void dumpEdges();

  bool contains(const Cell* c) const;

 private:
  int w_,h_;

};

std::ostream& operator<<(std::ostream& os, const Grid& g);
#endif /* !GRID_H_ */
