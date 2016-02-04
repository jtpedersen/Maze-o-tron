#include "util.h"


bool flipCoin() {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  static std::uniform_int_distribution<> coin(0,1);
  return 0 == coin(gen);
}
