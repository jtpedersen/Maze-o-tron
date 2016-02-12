#ifndef GRID_H_
#define GRID_H_

#include <map>
#include <set>
#include <vector>

class Cell;

class Grid {

public:
  Grid(int w = 0, int h = 0);
  
  Cell* get(const int idx);
  Cell* get(const int x, const int y);
  const Cell* get(const int idx) const;
  const std::vector<Cell>& getCells() const;
  
  Cell* randomCell();

  void addEdge(const int a, const int b);
  void removeEdge(const int a, const int b);

  bool linked(const int a, const int b) const;
  bool contains(const int idx) const; 

  int edgeCount();
  void dumpEdges();

  // rectangular
  int size() const;
  int idx(const int x, const int y) const;
  int w() const;
  int h() const;

  friend std::ostream& operator<<(std::ostream& os, const Grid& g);
 private:
  void swap(Grid& a, Grid b);
  int w_,h_;
  std::vector<Cell> cells;
  std::map<int, std::set<int>> edges;
};

std::ostream& operator<<(std::ostream& os, const Grid& g);
#endif /* !GRID_H_ */
