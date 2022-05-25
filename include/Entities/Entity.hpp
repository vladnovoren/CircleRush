#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "Position.hpp"
#include "LinearVelocity.hpp"
#include "AngularVelocity.hpp"
#include "RotationCenter.hpp"
#include "BaseComponent.hpp"
#include "Radius.hpp"
#include "CircleGraphicsComponent.hpp"
#include <vector>

class Entity {
 public:
  Entity();
  ~Entity();

  BaseComponent** GetComponent(const ComponentType type);

  Position** GetPosition();

  LinearVelocity** GetLinearVelocity();

  AngularVelocity** GetAngularVelocity();

  RotationCenter** GetRotationCenter();

  Radius** GetRadius();

  CircleGraphicsComponent** GetGraphicsComponent();

 private:
  BaseComponent* components_[static_cast<size_t>(ComponentType::COMPONENTS_CNT)] = {};

};

#endif /* Entity.hpp */
