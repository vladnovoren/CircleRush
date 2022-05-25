#include "PhysicalSystem.hpp"
#include "World.hpp"

PhysicalSystem& PhysicalSystem::GetInstance() {
  static PhysicalSystem instance;
  return instance;
}

PhysicalSystem::PhysicalSystem() {
}

void PhysicalSystem::CheckFlying() {
  Entity& flying = EntityManager::GetInstance().GetFlying();
  const CoordSystem& coord_system = World::GetInstance().GetCoordSystem();
  if (!coord_system.IsCircleInside((*flying.GetGraphicsComponent())->circle_)) {
    EntityManager::GetInstance().InitFlying();
  }
}

bool PhysicalSystem::Step(const double dt) {
  if (CollideAll()) {
    return true;
  }
  CheckFlying();
  MoveAll(dt);
  return false;
}

bool PhysicalSystem::CollideAll() {
  EntityManager& manager = EntityManager::GetInstance();

  FloatCircle flying_circle = (*manager.GetFlying().GetGraphicsComponent())->circle_;
  FloatCircle a_circle = (*manager.GetSpinning()[0].GetGraphicsComponent())->circle_;
  FloatCircle b_circle = (*manager.GetSpinning()[1].GetGraphicsComponent())->circle_;

  if (CirclesIntersect(flying_circle, a_circle) ||
      CirclesIntersect(flying_circle, b_circle)) {
    return true;
  }

  return false;
}

void PhysicalSystem::MoveAll(const double dt) {
  EntityManager& entity_manager = EntityManager::GetInstance();

  std::vector<Entity>& spinnings = entity_manager.GetSpinning();
  Entity& flying = entity_manager.GetFlying();

  for (auto& spinning : spinnings) {
    Vector2f position = (*spinning.GetPosition())->value_;
    Vector2f center = (*spinning.GetRotationCenter())->value_;
    Vector2f linear_vel = position - center;
    linear_vel.Rotate(-M_PI / 2);
    linear_vel *= (*spinning.GetAngularVelocity())->value_;
    (*spinning.GetLinearVelocity())->value_ = linear_vel;
    (*spinning.GetPosition())->value_ += (*spinning.GetLinearVelocity())->value_ * dt;

    (*spinning.GetGraphicsComponent())->circle_.center_ = (*spinning.GetPosition())->value_;
  }

  (*flying.GetPosition())->value_ += (*flying.GetLinearVelocity())->value_ * dt;
  (*flying.GetGraphicsComponent())->circle_.center_ = (*flying.GetPosition())->value_;
}

bool PhysicalSystem::CirclesIntersect(const FloatCircle &a, const FloatCircle &b) {
  return (a.center_ - b.center_).Length() < a.radius_ + b.radius_;
}

void PhysicalSystem::ChangeDirOne(Entity& ent) {
  (*ent.GetAngularVelocity())->value_ *= -1;
}

void PhysicalSystem::ChangeDir() {
  std::vector<Entity>& flying = EntityManager::GetInstance().GetSpinning();
  ChangeDirOne(flying[0]);
  ChangeDirOne(flying[1]);
}