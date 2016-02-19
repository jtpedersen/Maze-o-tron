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
  virtual std::shared_ptr<Maker> maker() override;
  virtual std::shared_ptr<Colorizer> colorizer() override;
 protected:
  std::shared_ptr<Maker> maker_;
  std::shared_ptr<Colorizer> colorizer_;
};

class RecursiveBacktrackerMakerFactory : public AbstractMakerFactory {
 public:
  virtual ~RecursiveBacktrackerMakerFactory() = default;
  RecursiveBacktrackerMakerFactory();
};

class PrimFactory : public AbstractMakerFactory {
 public:
  ~PrimFactory() = default;
  PrimFactory();
};

class BinTreeFactory : public AbstractMakerFactory {
 public:
  ~BinTreeFactory() = default;
  BinTreeFactory();
};

class SideWinderFactory : public AbstractMakerFactory {
 public:
  ~SideWinderFactory() = default;
  SideWinderFactory();
};

#endif /* !MAKERFACTORY_H_ */

