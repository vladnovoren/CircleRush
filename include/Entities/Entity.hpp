#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "Position.hpp"
#include "LinearVelocity.hpp"
#include "AngularVelocity.hpp"
#include "RotationCenter.hpp"
#include "BasePhysicalShape.hpp"
#include "BaseComponent.hpp"
#include <vector>

class Entity {
 public:
  BaseComponent* GetComponent(const ComponentType type) const;

  Position* GetPosition() const;

  LinearVelocity* GetLinearVelocity() const;

  AngularVelocity* GetAngularVelocity() const;

  RotationCenter* GetRotationCenter() const;

  BasePhysicalShape* GetBasePhysicalShape() const;

 private:
  BaseComponent* components_[static_cast<size_t>(ComponentType::COMPONENTS_CNT)];

};

#endif /* Entity.hpp */
