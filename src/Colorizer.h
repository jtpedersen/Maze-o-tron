#ifndef COLORIZER_H_
#define COLORIZER_H_

#include <QColor>
#include <memory>

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
  RecursiveBacktrackerColorizer(std::shared_ptr<RecursiveBacktrackerMaker>);
  virtual QColor getColorForCell(const int) const;
 private:
  std::shared_ptr<RecursiveBacktrackerMaker> rbm;
};

#endif /* !COLORIZER_H_ */
