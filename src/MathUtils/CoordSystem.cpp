#include "CoordSystem.hpp"
#include "Primitives.hpp"

CoordSystem::CoordSystem(const Vector2i &p_center,
                         const IntRanges& x_ranges, const IntRanges& y_ranges,
                         const double ppu)
    : p_center_(p_center),
      x_ranges_(x_ranges), y_ranges_(y_ranges),
      ppu_(ppu) {}

int CoordSystem::RealToPixelLen(const double len) const {
  return len * ppu_;
}

Vector2i CoordSystem::RealToPixelVector(const Vector2f& vector) const {
  return Vector2i(ppu_ * vector.x_, -ppu_ * vector.y_);
}

Vector2i CoordSystem::RealToPixelPoint(const Vector2f &point) const {
  return p_center_ + RealToPixelVector(point);
}

IntCircle CoordSystem::RealToPixelCircle(const FloatCircle& circle) const {
  return IntCircle(RealToPixelPoint(circle.center_), RealToPixelLen(circle.radius_));
}