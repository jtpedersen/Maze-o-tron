#ifndef PRIMMAKER_H_
#define PRIMMAKER_H_

#include "Maker.h"
#include "Grid.h"
#include "Set.h"

#include <utility>

class PrimMaker : public Maker {
public:
  PrimMaker(const Grid&);
  virtual ~PrimMaker();
  /// return the grid such that it can be rendered
  virtual const Grid& getGrid() const;
  /// take one step with whe algorithm
  virtual void step();
  /// can any mopre steps be taken
  virtual bool isDone() const;

  virtual int currentIdx() const;
private:
  Grid grid;
  Set set;
  std::vector< std::pair<int,int>> edges;
  int idx; /*!< the current index of cell */
};


#endif /* !PRIMMAKER_H_ */
