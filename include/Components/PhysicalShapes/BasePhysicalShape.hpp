#ifndef BASE_PHYSICAL_SHAPE_HPP
#define BASE_PHYSICAL_SHAPE_HPP

#include "BaseComponent.hpp"

enum class PhysicalShapeType {
  CIRCLE
};

class BasePhysicalShape : public BaseComponent {
 public:
  BasePhysicalShape() = default;

  BasePhysicalShape(const PhysicalShapeType type);

  PhysicalShapeType Type() const;

 private:
  PhysicalShapeType type_;

};

#endif /* BasePhysicalShape.hpp */
