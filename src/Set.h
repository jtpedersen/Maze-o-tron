#ifndef SET_H_
#define SET_H_
#include <vector>

class Set {
 public:
  Set(int cnt = 0);
  int find(int);
  void link(int, int);
  void dump() const;
  int size() const;
 private:
  std::vector<int> parents;
  std::vector<int> ranks;
};

#endif /* !SET_H_ */
