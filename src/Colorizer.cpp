#include "Colorizer.h"

QColor SimpleColorizer::getColorForCell(const int i, const int cur) const {
  if (cur == i) {
    return QColor(255,0,0);
  } else if ( i < cur) { 	// visited
    return QColor(255,255,150);
  } else {
    return QColor(255,150,255);
  }
}
