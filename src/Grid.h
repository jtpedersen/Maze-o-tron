#ifndef GRID_H_
#define GRID_H_

#include <multimap>
class Cell;

class Grid {

public:
  Grid(int w, int h);
  ~Grid(); // TODO: free the mallocs

  Cell& get(int idx);
  Cell& randomCell();

  int size() const;

  void addEdge(int a, int b);
  bool contains(int idx) const; 

  int edgeCount();
  void dumpEdges();

  // rectangular
  int idx(int x, int y);
  int w() const;
  int h() const;

 private:
  int w_,h_;
  Cell *cells;
  std::multimap<int, int> edges;

};


std::ostream& operator<<(std::ostream& os, const Grid& g);
#endif /* !GRID_H_ */
