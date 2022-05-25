#ifndef COLOR_HPP
#define COLOR_HPP

#include <cstddef>
#include <cstdint>

using ColorCompT = uint8_t;
using ColorT = uint32_t;

struct ColorBGRA {
  ColorCompT b_ = 0;
  ColorCompT g_ = 0;
  ColorCompT r_ = 0;
  ColorCompT a_ = 0;

  ColorBGRA() = default;

  ColorBGRA(const ColorCompT b, const ColorCompT g, const ColorCompT r, const ColorCompT a);

  ColorT GetIntColor() const;

};

#endif /* Color.hpp */
