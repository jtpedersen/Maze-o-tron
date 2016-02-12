#ifndef RECURSIVEBACKTRACKERMAKER_H_
#define RECURSIVEBACKTRACKERMAKER_H_

#include "Maker.h"
#include "Grid.h"
#include <set>
#include <vector>

class RecursiveBacktrackerMaker : public AbstractMaker {
 public:
  virtual ~RecursiveBacktrackerMaker();
  /// take one step with whe algorithm
  virtual void step();
  /// can any mopre steps be taken
  virtual bool isDone() const;

  int currentIdx() const;

  bool hasVisited(int idx) const;

  
 private:
  std::set<int> visited;
  std::vector<int> stack;
  int idx = 0; /*!< the current index of cell */

  bool canditate(int idx) const;
  friend class RecursiveBacktrackerColorizer;
  
};

#endif /* !RECURSIVEBACKTRACKERMAKER_H_ */
