#ifndef CELL_H_
#define CELL_H_

#include <functional>
#include <set>
#include <vector>

class Cell {
public:

  Cell(int x, int yxo);
  bool operator<(const Cell &other) const;
  size_t hash() const;
  void link(Cell& other);
  void unlink(Cell& other);
  std::vector<Cell*> neighbors() const;

  int x() const;
  int y() const;

  Cell *N = nullptr;
  Cell *E = nullptr;
  Cell *S = nullptr;
  Cell *W = nullptr;

private:
  int x_,y_; /*!< position */
  std::set<Cell> edges;

  
};

namespace std {
    template <>
        class hash<Cell>{
        public :
        size_t operator()(const Cell &c ) const{
	  return c.hash();
        }
    };
}

#endif /* !CELL_H_ */
