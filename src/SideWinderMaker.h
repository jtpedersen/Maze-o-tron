#include "Maker.h"
#include "Grid.h"

#include <vector>

class SideWinderMaker : public AbstractMaker {
public:
  virtual ~SideWinderMaker() = default;
  /// take one step with whe algorithm
  virtual void step() override;
  /// can any mopre steps be taken
  virtual bool isDone() const override;
  virtual int currentIdx() const override;
private:
  std::vector<Cell*> run;
  int idx = 0; /*!< the current index of cell */
};
