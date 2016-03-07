#include "MakerFactory.h"

std::unique_ptr<MakerFactory> MakerFactory::byName(QString name) {
  if (name == "BinaryTree") {
    return std::make_unique<BinTreeFactory>();
  } else if (name == "SideWinder") {
    return std::make_unique<SideWinderFactory>();
  } else if (name == "RecursiveBacktracker") {
    return std::make_unique<RecursiveBacktrackerMakerFactory>();
  } else if (name == "Prims") {
    return std::make_unique<PrimFactory>();
  } else if (name == "Dijkstra") {
    return std::make_unique<PrimFactory>();
  } else {
    Q_ASSERT(false);
  }
}


std::shared_ptr<Maker> AbstractMakerFactory::maker() {
  return maker_; 
}

std::shared_ptr<Colorizer> AbstractMakerFactory::colorizer() {
  return colorizer_;
}

RecursiveBacktrackerMakerFactory::RecursiveBacktrackerMakerFactory() {
  auto rbtm = std::make_shared<RecursiveBacktrackerMaker>();
  colorizer_ = std::make_shared<RecursiveBacktrackerColorizer>(rbtm);
  maker_ = std::shared_ptr<Maker>(rbtm);
}

PrimFactory::PrimFactory() {
  auto raw = std::make_shared<PrimMaker>();
  maker_ = std::shared_ptr<Maker>(raw);
  colorizer_ = std::make_shared<PrimColorizer>(raw);
}

BinTreeFactory::BinTreeFactory() {
  auto raw = std::make_shared<BinTreeMaker>();
  maker_ = std::shared_ptr<Maker>(raw);
  colorizer_ = std::make_shared<SimpleColorizer>(maker_);
}

SideWinderFactory::SideWinderFactory() {
  auto raw = std::make_shared<SideWinderMaker>();
  maker_ = std::shared_ptr<Maker>(raw);
  colorizer_ = std::make_shared<SimpleColorizer>(maker_);
}

DijkstraFactory::DijkstraFactory() {
  auto raw = std::make_shared<UniDijkstra>(0);
  maker_ = std::shared_ptr<Maker>(raw);
  colorizer_ = std::make_shared<SimpleColorizer>(maker_);
}
