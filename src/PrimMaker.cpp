#include "PrimMaker.h"
#include "util.h"
#include "Cell.h"
#include "Set.h"

#include <iostream>
#include <algorithm>
#include <cassert>

PrimMaker::PrimMaker() {
  set = Set(grid().size());
  for (int i = 0; i < grid().size(); i++) {
	auto c = grid().get(i);
    if (c->N >= 0)
      edges.emplace_back(std::make_pair(i, c->N));
    if (c->W >= 0)
      edges.emplace_back(std::make_pair(i, c->W));
  }

  std::random_device rd;
  std::mt19937 g(rd());
 
  std::shuffle(edges.begin(), edges.end(), g);
  std::cout << "Shuffled " << edges.size() << " edges"  << "\n";
}

PrimMaker::~PrimMaker() {
}

bool PrimMaker::isDone() const {
  return idx >= edges.size();
}


int PrimMaker::currentIdx() const {
  return idx;
}

void PrimMaker::step() {
  if (isDone()) return;
  auto e = edges[idx++];
  
  auto a = set.find(e.first);
  auto b = set.find(e.second);

  //  std::cout << a << " -- " << b  << "\n";
  if (a == b) return;

  set.link(a,b);
  grid().addEdge(e.first, e.second);
  grid().addEdge(e.second, e.first);
  //  std::cout << "addEdge: " << e.first << "<--> " << e.second  << "\n";
}


