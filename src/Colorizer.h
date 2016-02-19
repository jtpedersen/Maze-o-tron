#ifndef COLORIZER_H_
#define COLORIZER_H_

#include <QColor>
#include <memory>

class Colorizer {
 public:
  virtual ~Colorizer() = default;
  virtual QColor getColorForCell(const int) const = 0;
};

class Maker;
class SimpleColorizer : public Colorizer{
 public:
  SimpleColorizer(std::weak_ptr<Maker> );
  virtual QColor getColorForCell(const int) const override;
 private:
  std::weak_ptr<Maker> maker;
};

class RecursiveBacktrackerMaker;
class RecursiveBacktrackerColorizer : public Colorizer {
 public:
  RecursiveBacktrackerColorizer(std::weak_ptr<RecursiveBacktrackerMaker>);
  virtual QColor getColorForCell(const int) const override;
 private:
  std::weak_ptr<RecursiveBacktrackerMaker> rbm;
};

class PrimMaker;
class PrimColorizer : public Colorizer {
 public:
  PrimColorizer(std::weak_ptr<PrimMaker>);
  virtual QColor getColorForCell(const int) const override;
 private:
  mutable QList<QColor> colors;
  std::weak_ptr<PrimMaker> pm;
};


#endif /* !COLORIZER_H_ */
