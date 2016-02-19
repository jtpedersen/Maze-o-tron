#include "Colorizer.h"
#include "RecursiveBacktrackerMaker.h"
#include "Cell.h"
#include "Set.h"
#include "PrimMaker.h"

static const QColor current(255,0,0);
static const QColor done(255,255,255);
static const QColor pristine(255,150,255);


SimpleColorizer::SimpleColorizer(std::weak_ptr<Maker> m)
  : maker(m) {}

QColor SimpleColorizer::getColorForCell(const int i) const {
  int cur = 0;
  if (auto spt = maker.lock()) 
    cur = spt->currentIdx();
  if (cur == i) {
    return current;
  } else if ( i < cur ) { 	// visited
    return done;
  } else {
    return pristine;
  }
}

RecursiveBacktrackerColorizer::RecursiveBacktrackerColorizer(std::weak_ptr<RecursiveBacktrackerMaker> rbm)
  : rbm(rbm) {};

QColor RecursiveBacktrackerColorizer::getColorForCell(const int idx) const {
  auto spt = rbm.lock();
  if (!spt) return pristine;
  if (spt->idx == idx) return current;
  return spt->hasVisited(idx) ? done : pristine;
}

PrimColorizer::PrimColorizer(std::weak_ptr<PrimMaker> pm) 
  : pm(pm) {
}

QColor PrimColorizer::getColorForCell(const int idx) const {
  if (auto spt = pm.lock()) {
    if (colors.isEmpty()) {
      for (int i = 0 ; i < spt->set.size(); i++) {
	colors << QColor::fromHsv(qrand()%360, qrand()%128, 100 + qrand()%155);
      }
    }
    return colors[spt->set.find(idx)];    
  }
  return pristine;
}
