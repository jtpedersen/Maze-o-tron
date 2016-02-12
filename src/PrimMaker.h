#ifndef PRIMMAKER_H_
#define PRIMMAKER_H_

#include "Maker.h"
#include "Grid.h"
#include "Set.h"

#include <utility>

class PrimMaker : public AbstractMaker {
public:
  PrimMaker();
  virtual ~PrimMaker();
  /// take one step with whe algorithm
  virtual void step();
  /// can any mopre steps be taken
  virtual bool isDone() const;
  int currentIdx() const;
private:
  Set set;
  std::vector< std::pair<int,int>> edges;
  int idx; /*!< the current index of cell */
};


#endif /* !PRIMMAKER_H_ */
