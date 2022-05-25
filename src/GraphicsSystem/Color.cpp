#include "Color.hpp"

ColorBGRA::ColorBGRA(const ColorCompT b, const ColorCompT g, const ColorCompT r, const ColorCompT a) :
  b_(b), g_(g), r_(r), a_(a) {}

ColorT ColorBGRA::GetIntColor() const {
  ColorCompT color[4] = {b_, g_, r_, a_};
  return *reinterpret_cast<ColorT*>(color);
}
