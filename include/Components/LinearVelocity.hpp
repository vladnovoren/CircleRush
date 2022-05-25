#ifndef LINEAR_VELOCITY_HPP
#define LINEAR_VELOCITY_HPP

#include "BaseComponent.hpp"
#include <Vector2.hpp>

class LinearVelocity : public BaseComponent, public Vector2f {
 public:
  LinearVelocity() = default;
  ~LinearVelocity() = default;

};

#endif /* LinearVelocity.hpp */
