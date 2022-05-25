#ifndef ROTATION_CENTER_HPP
#define ROTATION_CENTER_HPP

#include "BaseComponent.hpp"
#include "Vector2.hpp"

class RotationCenter : public BaseComponent {
 public:
  RotationCenter() = default;
  ~RotationCenter() = default;

  Vector2f value_;
};

#endif /* RotationCenter.hpp */
