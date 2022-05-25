#include "Entity.hpp"

Entity::Entity() {
}

Entity::~Entity() {
  for (size_t i = 0; i < CompId(ComponentType::COMPONENTS_CNT); ++i) {
    delete components_[i];
  }
}

BaseComponent** Entity::GetComponent(const ComponentType type) {
  return components_ + CompId(type);
}

Position** Entity::GetPosition() {
  return (Position**)(GetComponent(ComponentType::POSITION));
}

LinearVelocity** Entity::GetLinearVelocity() {
  return (LinearVelocity**)(GetComponent(ComponentType::LINEAR_VELOCITY));
}

AngularVelocity** Entity::GetAngularVelocity() {
  return (AngularVelocity**)(GetComponent(ComponentType::ANGULAR_VELOCITY));
}

RotationCenter** Entity::GetRotationCenter() {
  return (RotationCenter**)(GetComponent(ComponentType::ROTATION_CENTER));
}

Radius** Entity::GetRadius() {
  return (Radius**)(GetComponent(ComponentType::RADIUS));
}

CircleGraphicsComponent** Entity::GetGraphicsComponent() {
  return reinterpret_cast<CircleGraphicsComponent**>(GetComponent(ComponentType::CIRCLE_GRAPHICS_COMPONENT));
}

