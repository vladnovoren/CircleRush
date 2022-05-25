#ifndef ANGULAR_VELOCITY_HPP
#define ANGULAR_VELOCITY_HPP

#include "BaseComponent.hpp"
#include "NumericalType.hpp"
#include "Vector2.hpp"

class AngularVelocity : public BaseComponent, public NumericalType<float> {
 public:
  AngularVelocity() = default;
  ~AngularVelocity() = default;

};

#endif /* AngularVelocity.hpp */
