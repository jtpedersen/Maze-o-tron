#include "UniDijkstra.h"
#include "util.h"

#include <vector>

UniDijkstra::UniDijkstra(int src) {
  frontier.push_back(src);
  dists[src] = 0;
}

void UniDijkstra::step()
{
  if (isDone()) return;
  auto it = select_randomly(begin(frontier), end(frontier));
  auto next = *it;
  frontier.erase(it);
  visited.emplace(next);
  auto c = grid().get(next);
  std::array<int, 4> ls { c->N, c->E, c->S, c->W};
  const auto d = dists[next];
  for(auto c: ls) {
    if (c < 0) continue;
    if ( visited.count(c) > 0) continue;
    if (!grid().linked(next, c)) continue;
    dists[c] = 1 + d;
    frontier.push_back(c);
  }
}
bool UniDijkstra::isDone() const
{
  return frontier.empty();
}


int UniDijkstra::currentIdx() const {
  return 0;
}

int UniDijkstra::dist(int cell) {
  return dists[cell];
}
