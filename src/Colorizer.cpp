#include "Colorizer.h"
#include "RecursiveBacktrackerMaker.h"

static const QColor current(255,0,0);
static const QColor done(255,255,255);
static const QColor pristine(255,150,255);

SimpleColorizer::SimpleColorizer(Maker *m)
  : maker(m) {}

QColor SimpleColorizer::getColorForCell(const int i) const {
  if (maker->currentIdx() == i) {
    return current;
  } else if ( i < maker->currentIdx() ) { 	// visited
    return done;
  } else {
    return pristine;
  }
}

RecursiveBacktrackerColorizer::RecursiveBacktrackerColorizer(std::shared_ptr<RecursiveBacktrackerMaker> rbm)
  : rbm(rbm) {};

QColor RecursiveBacktrackerColorizer::getColorForCell(const int idx) const {
  if (rbm->idx == idx) return current;
  return rbm->hasVisited(idx) ? done : pristine;
}
