#ifndef SET_H_
#define SET_H_
#include <vector>

class Set {
 public:
  Set(int cnt);
  int find(int);
  void link(int, int);
  void dump() const;
 private:
  std::vector<int> parents;
  std::vector<int> ranks;
};

#endif /* !SET_H_ */
