#ifndef COLORIZER_H_
#define COLORIZER_H_

#include <QColor> 

class Colorizer {
 public:
  virtual ~Colorizer() {};
  virtual QColor getColorForCell(const int) const = 0;
};

class Maker;
class SimpleColorizer : public Colorizer{
 public:
  SimpleColorizer(Maker *);
  virtual QColor getColorForCell(const int) const;
 private:
  Maker* maker;
};

class RecursiveBacktrackerMaker;
class RecursiveBacktrackerColorizer : public Colorizer {
 public:
  RecursiveBacktrackerColorizer(RecursiveBacktrackerMaker*);
  virtual QColor getColorForCell(const int) const;
 private:
  RecursiveBacktrackerMaker* rbm = nullptr;
};

#endif /* !COLORIZER_H_ */
