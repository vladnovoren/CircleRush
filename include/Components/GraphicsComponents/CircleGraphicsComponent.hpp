#ifndef CIRCLE_GRAPHICS_COMPONENT_HPP
#define CIRCLE_GRAPHICS_COMPONENT_HPP

#include "BaseGraphicsComponent.hpp"
#include "Primitives.hpp"
#include "Color.hpp"

class CircleGraphicsComponent : public BaseGraphicsComponent {
 public:
  CircleGraphicsComponent() = default;
  CircleGraphicsComponent(const FloatCircle& circle, const ColorBGRA& color);
  ~CircleGraphicsComponent() = default;

  void Draw() override;

  FloatCircle circle_;
  ColorBGRA color_;

};

#endif /* CircleGraphicsComponent.hpp */
