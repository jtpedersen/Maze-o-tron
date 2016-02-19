#ifndef MAKER_H_
#define MAKER_H_
/// Maker of mazes

#include "Grid.h"

class Maker {
public:
  virtual ~Maker() = default;
  /// take one step with whe algorithm
  virtual void step() = 0;
  /// can any mopre steps be taken
  virtual bool isDone() const = 0;
  /// Set a grid to work on ( Maker must copy )
  virtual void setGrid(const Grid&) = 0;
  /// return the grid such that it can be rendered
  virtual Grid& grid() = 0;
  virtual const Grid& grid() const =0;
  /// get the curret position, for algorims where it makes sense
  virtual int currentIdx() const =0;
};



class AbstractMaker : public Maker {
public:
  virtual ~AbstractMaker() = default;
  /// Set a grid to work on ( Maker must copy )
  virtual void setGrid(const Grid&) override;
  /// return the grid such that it can be rendered
  virtual Grid& grid() override;
  virtual const Grid& grid() const override;
protected:
  Grid grid_;
};

#endif /* !MAKER_H_ */
