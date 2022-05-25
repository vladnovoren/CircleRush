#ifndef GRAPHICS_SYSTEM_HPP
#define GRAPHICS_SYSTEM_HPP

#include "Engine.h"
#include "Vector2.hpp"
#include "Color.hpp"
#include "Primitives.hpp"

class GraphicsSystem {
 public:
  GraphicsSystem();
  ~GraphicsSystem();

  static inline void DrawPoint(const int x, const int y, const ColorBGRA& color);
  static inline void DrawPoint(const Vector2i& point, const ColorBGRA& color);

  static void DrawCircle(const IntCircle& circle, const ColorBGRA& color);

 private:

};

#endif /* GraphicsSystem.hpp */
