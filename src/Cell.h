#ifndef CELL_H_
#define CELL_H_

#include "Grid.h"

#include <functional>
#include <set>
#include <vector>

class Cell {
public:
  Cell(const Grid&);
  Cell(const Grid&, int x, int y);
  bool operator<(const Cell &other) const;

  std::vector<int> neighbors() const;

  int idx() const;
  /// when contucted without an id it is invalid, id < 0
  bool valid() const;
  
  /* specific for rectangular grid */
  int x() const;
  int y() const;

  int N = -1;
  int E = -1;
  int S = -1;
  int W = -1;
  
  
private:
  int x_,y_; /*!< position in rectangular grid*/
  int idx_; /*!< index in grid, used for edges */
  Grid& grid;
};

std::ostream& operator<<(std::ostream& os, const Cell& c);

#endif /* !CELL_H_ */
