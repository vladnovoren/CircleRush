#include "CirclePhysicalShape.hpp"

CirclePhysicalShape::CirclePhysicalShape() :
    BasePhysicalShape(PhysicalShapeType::CIRCLE) {}

CirclePhysicalShape::CirclePhysicalShape(const FloatCircle& circle) :
    BasePhysicalShape(PhysicalShapeType::CIRCLE), FloatCircle(circle) {}
