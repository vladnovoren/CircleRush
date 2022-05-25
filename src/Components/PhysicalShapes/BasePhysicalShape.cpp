#include "BasePhysicalShape.hpp"

BasePhysicalShape::BasePhysicalShape(const PhysicalShapeType type)
    : type_(type) {}

PhysicalShapeType BasePhysicalShape::Type() const {
  return type_;
}
