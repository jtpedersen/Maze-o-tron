#ifndef BINTREEMAKER_H_
#define BINTREEMAKER_H_

#include "Maker.h"
#include "Grid.h"

class BinTreeMaker : public AbstractMaker {
public:
  virtual ~BinTreeMaker();
  /// take one step with whe algorithm
  virtual void step();
  /// can any mopre steps be taken
  virtual bool isDone() const;

  int currentIdx() const;
private:
  int idx = 0; /*!< the current index of cell */
};

#endif /* !BINTREEMAKER_H_ */
