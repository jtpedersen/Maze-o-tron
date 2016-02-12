#ifndef BINTREEMAKER_H_
#define BINTREEMAKER_H_

#include "Maker.h"
#include "Grid.h"

class BinTreeMaker : public Maker {
public:
  BinTreeMaker(const Grid&);
  virtual ~BinTreeMaker();
  /// return the grid such that it can be rendered
  virtual const Grid& getGrid() const;
  /// take one step with whe algorithm
  virtual void step();
  /// can any mopre steps be taken
  virtual bool isDone() const;
  virtual void setGrid(const Grid&);

  virtual int currentIdx() const;
private:
  Grid grid;

  int idx; /*!< the current index of cell */
};

#endif /* !BINTREEMAKER_H_ */
