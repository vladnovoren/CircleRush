#include "NumericalType.hpp"
#include <cstdio>

int main() {
  NumericalType<int> x(1);
  int y = x;
  x = 2;
  x += 1;
  return 0;
}
