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

bool CoordSystem::IsCircleInside(const FloatCircle& circle) const {
  IntCircle int_circle = RealToPixelCircle(circle);

  Vector2i r_r_v(int_circle.radius_, int_circle.radius_);

  Vector2i l_u = int_circle.center_ - r_r_v;
  Vector2i r_d = int_circle.center_ + r_r_v;

  return l_u.x_ > x_ranges_.min_ && r_d.x_ < x_ranges_.max_ &&
         l_u.y_ > y_ranges_.min_ && r_d.y_ < y_ranges_.max_;
}