#ifndef MAKERFACTORY_H_
#define MAKERFACTORY_H_

#include "RecursiveBacktrackerMaker.h"
#include "Colorizer.h"

#include <memory>

class MakeFactory {
public:
  virtual std::shared_ptr<Maker> maker() = 0;
  virtual std::shared_ptr<Colorizer> colorizer() = 0;
};

class AbstractMakerFactory : public MakeFactory {
public:
  virtual std::shared_ptr<Maker> maker() { return maker_; }
  virtual std::shared_ptr<Colorizer> colorizer()  { return colorizer_; }
protected:
  std::shared_ptr<Maker> maker_;
  std::shared_ptr<Colorizer> colorizer_;
};

class RecursiveBacktrackerMakerFactory : public AbstractMakerFactory {
public:
RecursiveBacktrackerMakerFactory() {
    auto rbtm = std::make_shared<RecursiveBacktrackerMaker>();
    colorizer_ = std::make_shared<RecursiveBacktrackerColorizer>(rbtm);
    maker_ = rbtm;
  }
};



#endif /* !MAKERFACTORY_H_ */
