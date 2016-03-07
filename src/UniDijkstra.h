#ifndef UNIDIJKSTRA_H_
#define UNIDIJKSTRA_H_

#include "Maker.h"
/**
 * a uniformly weigted dijkstr
 */
class UniDijkstra : public AbstractMaker {
 public:
  explicit UniDijkstra(int source);
  virtual ~UniDijkstra() = default;
  /// take one step with whe algorithm
  virtual void step() override;
  /// can any mopre steps be taken
  virtual bool isDone() const override;

  virtual int currentIdx() const override;
 private:
  std::set<int> frontier;
  std::set<int> visited;
  std::map<int, int> dists;

};

#endif /* !UNIDIJKSTRA_H_ */
