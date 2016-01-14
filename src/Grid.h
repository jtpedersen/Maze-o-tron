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
  std::vector<Cell> cells;

  int edgeCount();
  int w,h;


  


};

std::ostream& operator<<(std::ostream& os, const Grid& g);
#endif /* !GRID_H_ */
