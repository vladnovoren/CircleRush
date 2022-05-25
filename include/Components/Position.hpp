#ifndef POSITION_HPP
#define POSITION_HPP

#include "BaseComponent.hpp"
#include "Vector2.hpp"

class Position : public BaseComponent {
 public:
  Position() = default;
  ~Position() = default;

  Vector2f value_;
};
 
#endif /* Position.hpp */
