#include "CircleGraphicsComponent.hpp"
#include "World.hpp"

CircleGraphicsComponent::CircleGraphicsComponent(const FloatCircle& circle, const ColorBGRA& color) :
    circle_(circle), color_(color) {}

void CircleGraphicsComponent::Draw() {
  const CoordSystem& coord_system = World::GetInstance().GetCoordSystem();
  GraphicsSystem::DrawCircle(coord_system.RealToPixelCircle(circle_), color_);
}