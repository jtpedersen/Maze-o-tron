#include "Maker.h"
#include "Grid.h"

#include <vector>

class SideWinderMaker : public Maker {
public:
  SideWinderMaker(const Grid&);
  virtual ~SideWinderMaker();
  /// return the grid such that it can be rendered
  virtual const Grid& getGrid() const;
  /// take one step with whe algorithm
  virtual void step();
  /// can any mopre steps be taken
  virtual bool isDone() const;
  virtual int currentIdx() const;
  virtual void setGrid(const Grid&);
private:
  Grid grid;
  std::vector<Cell*> run;
  int idx; /*!< the current index of cell */
};
