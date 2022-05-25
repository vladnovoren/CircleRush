#include "Vector2.hpp"

int main() {
  Vector2i vec1(1, 2);
  Vector2f vec2 = vec1;
  vec2.Print();
  Vector2i vec3 = vec1;
  vec3 = vec1;
  vec3 = vec2;
  return 0;
}