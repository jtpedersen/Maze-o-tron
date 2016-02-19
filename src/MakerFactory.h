#ifndef MAKERFACTORY_H_
#define MAKERFACTORY_H_

#include "Colorizer.h"

#include <Maker.h>
#include <RecursiveBacktrackerMaker.h>
#include <BinTreeMaker.h>
#include <PrimMaker.h>
#include <SideWinderMaker.h>

#include <memory>

class MakerFactory {
 public:
  virtual ~MakerFactory() = default;
  virtual std::shared_ptr<Maker> maker() = 0;
  virtual std::shared_ptr<Colorizer> colorizer() = 0;
  static std::unique_ptr<MakerFactory> byName(QString name);
};

class AbstractMakerFactory : public MakerFactory {
 public:
  virtual ~AbstractMakerFactory() = default;
  virtual std::shared_ptr<Maker> maker() { return maker_; }
  virtual std::shared_ptr<Colorizer> colorizer()  { return colorizer_; }
 protected:
  std::shared_ptr<Maker> maker_;
  std::shared_ptr<Colorizer> colorizer_;
};

class RecursiveBacktrackerMakerFactory : public AbstractMakerFactory {
 public:
  virtual ~RecursiveBacktrackerMakerFactory() = default;
  RecursiveBacktrackerMakerFactory() {
    auto rbtm = std::make_shared<RecursiveBacktrackerMaker>();
    colorizer_ = std::make_shared<RecursiveBacktrackerColorizer>(rbtm);
    maker_ = std::shared_ptr<Maker>(rbtm);
  }
};

class PrimFactory : public AbstractMakerFactory {
 public:
  ~PrimFactory() = default;
  PrimFactory() {
    auto raw = std::make_shared<PrimMaker>();
    maker_ = std::shared_ptr<Maker>(raw);
    colorizer_ = std::make_shared<SimpleColorizer>(maker_);
  }
};

class BinTreeFactory : public AbstractMakerFactory {
 public:
  ~BinTreeFactory() = default;
  BinTreeFactory() {
    auto raw = std::make_shared<BinTreeMaker>();
    maker_ = std::shared_ptr<Maker>(raw);
    colorizer_ = std::make_shared<SimpleColorizer>(maker_);
  }
};

class SideWinderFactory : public AbstractMakerFactory {
 public:
  ~SideWinderFactory() = default;
  SideWinderFactory() {
    auto raw = std::make_shared<SideWinderMaker>();
    maker_ = std::shared_ptr<Maker>(raw);
    colorizer_ = std::make_shared<SimpleColorizer>(maker_);
  }
};

#endif /* !MAKERFACTORY_H_ */

