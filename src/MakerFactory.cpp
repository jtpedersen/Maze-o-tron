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
    } else {
      Q_ASSERT(false);
    }
  }
