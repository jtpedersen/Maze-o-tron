#ifndef MAKER_H_
#define MAKER_H_
/// Maker of mazes

class Grid;
class Maker {
public:
  /// return the grid such that it can be rendered
  virtual const Grid& getGrid() const = 0;
  /// take one step with whe algorithm
  virtual void step() = 0;
  /// can any mopre steps be taken
  virtual bool isDone() const = 0;
};

#endif /* !MAKER_H_ */
