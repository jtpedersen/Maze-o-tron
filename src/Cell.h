#ifndef CELL_H_
#define CELL_H_

#include <functional>
#include <set>
#include <vector>

class Grid;

class Cell {
public:
  Cell(Grid* g, int x, int y);
  Cell(Grid g, int x, int y);
  ///  Cell(const Cell& o);
  bool operator<(const Cell &other) const;

  std::vector<int> neighbors() const;

  int idx() const;
  bool valid() const;
  void setGrid(Grid *);
  /* conviniece to access the edges in Grid */
  bool linked(const int other) const;
  void link(const int other);
  void unlink(const int other);
  
  /* specific for rectangular grid */
  int x() const;
  int y() const;

  int N = -1;
  int E = -1;
  int S = -1;
  int W = -1;

private:
  Grid* grid;
  int x_,y_; /*!< position in rectangular grid*/
};

std::ostream& operator<<(std::ostream& os, const Cell& c);

#endif /* !CELL_H_ */
