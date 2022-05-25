#include "Entity.hpp"

BaseComponent* Entity::GetComponent(const ComponentType type) const {
  return components_[CompId(type)];
}

Position* Entity::GetPosition() const {
  return reinterpret_cast<Position*>(GetComponent(ComponentType::POSITION));
}

LinearVelocity* Entity::GetLinearVelocity() const {
  return reinterpret_cast<LinearVelocity*>(GetComponent(ComponentType::LINEAR_VELOCITY));
}

AngularVelocity* Entity::GetAngularVelocity() const {
  return reinterpret_cast<AngularVelocity*>(GetComponent(ComponentType::ANGULAR_VELOCITY));
}

RotationCenter* Entity::GetRotationCenter() const {
  return reinterpret_cast<RotationCenter*>(GetComponent(ComponentType::ROTATION_CENTER));
}
