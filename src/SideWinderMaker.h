#include "Maker.h"
#include "Grid.h"

#include <vector>

class SideWinderMaker : public AbstractMaker {
public:
  virtual ~SideWinderMaker();
  /// take one step with whe algorithm
  virtual void step();
  /// can any mopre steps be taken
  virtual bool isDone() const;
  int currentIdx() const;
private:
  std::vector<Cell*> run;
  int idx = 0; /*!< the current index of cell */
};
