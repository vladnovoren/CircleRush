#ifndef CIRCLE_PHYSICAL_SHAPE_HPP
#define CIRCLE_PHYSICAL_SHAPE_HPP

#include "BasePhysicalShape.hpp"
#include "Primitives.hpp"

class CirclePhysicalShape : public BasePhysicalShape, public FloatCircle {
 public:
  CirclePhysicalShape();
  CirclePhysicalShape(const FloatCircle& circle);
  ~CirclePhysicalShape() = default;

};

#endif /* CirclePhysicalShape.hpp */
