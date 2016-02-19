#include "Set.h"
#include <cassert>
#include <iostream>


Set::Set(int n) {
  for (int i = 0; i < n; i++) {
    parents.push_back(i);
    ranks.push_back(0);
  }
}

int Set::size() const {
  return parents.size();
}

int Set::find(int i) {
  assert(i < parents.size());
  if (parents[i] != i)
    parents[i] = find(parents[i]);
  return parents[i];
}


void Set::link(int a, int b) {
  auto arep = find(a);
  auto brep = find(b);
  if (arep == brep) return;
  
  if (ranks[arep] < ranks[brep]) {
    parents[brep] = arep;
  } else {
    parents[arep] = brep;
    if (ranks[arep] == ranks[brep]) {
      ranks[arep]++;
    }
  }
}

void Set::dump() const{
  std::cout << "DUMP"  << "\n";
  for (int i = 0; i < parents.size(); i++) {
    std::cout << i << "->" << parents[i] << "(" << ranks[i] << ")" << std::endl;
  }
}
