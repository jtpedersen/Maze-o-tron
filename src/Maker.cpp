#include "Maker.h"
#include "Cell.h"

void AbstractMaker::setGrid(const Grid& g) {
  grid_ = g;
  initGrid();
}

Grid& AbstractMaker::grid() {
  return grid_;
}

const Grid& AbstractMaker::grid() const {
  return grid_;
}

void AbstractMaker::initGrid() {

}
