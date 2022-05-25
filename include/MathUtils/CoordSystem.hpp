#ifndef COORD_SYSTEM_HPP
#define COORD_SYSTEM_HPP

#include "Vector2.hpp"
#include "Ranges.hpp"
#include "Engine.h"
#include "Primitives.hpp"

struct CoordSystem {
  CoordSystem(const Vector2i& p_center,
              const IntRanges& x_ranges, const IntRanges& y_ranges,
              const double ppu);

  int       RealToPixelLen(const double len) const;
  Vector2i  RealToPixelVector(const Vector2f& vector) const;
  Vector2i  RealToPixelPoint(const Vector2f& point) const;
  IntCircle RealToPixelCircle(const FloatCircle& circle) const;

  Vector2i    p_center_;

  IntRanges x_ranges_;
  IntRanges y_ranges_;

  double ppu_;

};

#endif /* CoordSystem.hpp */
