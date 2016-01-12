#ifndef GRID_H_
#define GRID_H_

#include <vector>
#include "Cell.h"

class Grid {
public:
  Grid(int w, int h);
  Cell* get(int x, int y);
  Cell* randomCell();
private:
  std::vector<Cell> cells;
  int w,h;

};

#endif /* !GRID_H_ */
