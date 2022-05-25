#include "GraphicsSystem.hpp"

void GraphicsSystem::DrawPoint(const int x, const int y, const ColorBGRA& color) {
  buffer[y][x] = color.GetIntColor();
}

void GraphicsSystem::DrawPoint(const Vector2i& point, const ColorBGRA& color) {
  DrawPoint(point.x_, point.y_, color);
}

void GraphicsSystem::DrawCircle(const IntCircle& circle, const ColorBGRA& color) {
  Vector2i r_r_v(circle.radius_, circle.radius_);
  Vector2i left_up = circle.center_ - r_r_v;
  Vector2i right_down = circle.center_ + r_r_v;

  for (int y = left_up.y_; y < right_down.y_; ++y) {
    for (int x = left_up.x_; x < right_down.x_; ++x) {
      if (circle.IsPointInside(x, y)) {
        DrawPoint(x, y, color);
      }
    }
  }
}
