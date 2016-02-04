#ifndef COLORIZER_H_
#define COLORIZER_H_

#include <QColor> 

class SimpleColorizer {
 public:
  QColor getColorForCell(const int, const int cur) const;
};

#endif /* !COLORIZER_H_ */
