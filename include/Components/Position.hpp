#ifndef POSITION_HPP
#define POSITION_HPP

#include "BaseComponent.hpp"
#include "Vector2.hpp"

class Position : public BaseComponent, public Vector2f {
 public:
  Position() = default;
  ~Position() = default;

};
 
#endif /* Position.hpp */
