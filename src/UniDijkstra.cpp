#include "UniDijkstra.h"
#include "util.h"

UniDijkstra::UniDijkstra(int src) {
  frontier.emplace(src);
  dists[src] = 0;
}

void UniDijkstra::step()
{
  if (isDone()) return;
  auto next = *select_randomly(begin(frontier), end(frontier));
  visited.emplace(next);
  auto c = grid().get(next);
  std::vector<int> ls { c->N, c->E, c->S, c->W};
  auto d = dists[next];
  for(auto c: ls) {
    if (c >= 0 && ( visited.count(c) == 0)) {
      dists[c] = 1 + d;
      frontier.emplace(c);
 
    }
  }
}
bool UniDijkstra::isDone() const
{
  return frontier.empty();
}


int UniDijkstra::currentIdx() const {
  return 0;
}

