#ifndef LINEAR_VELOCITY_HPP
#define LINEAR_VELOCITY_HPP

#include "BaseComponent.hpp"
#include <Vector2.hpp>

class LinearVelocity : public BaseComponent {
 public:
  LinearVelocity() = default;
  ~LinearVelocity() = default;

  Vector2f value_;
};

#endif /* LinearVelocity.hpp */
