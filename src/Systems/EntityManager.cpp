#include "EntityManager.hpp"

EntityManager& EntityManager::GetInstance() {
  static EntityManager instance;
  return instance;
}

void EntityManager::InitFlying() {
  float r = 15;

  (**flying_.GetPosition()).value_ = Vector2f(20, SCREEN_HEIGHT / 2);

  (**flying_.GetLinearVelocity()).value_ = Vector2f(r, 0) * 10;
  (**flying_.GetRadius()).value_ = r;
  (**flying_.GetGraphicsComponent()).circle_.center_ = (**flying_.GetPosition()).value_;

  ++score_;
}

EntityManager::EntityManager() : spinning_(2) {
  float r = 15;
  float R = 100;
  float omega = 2 * M_PI / 3;

  RotationCenter* rot_center_1 = new RotationCenter();
  RotationCenter* rot_center_2 = new RotationCenter();
  rot_center_2->value_ = rot_center_1->value_ = Vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);;

  Position* pos_1 = new Position();
  pos_1->value_ = rot_center_1->value_ - Vector2f(R, 0);
  Position* pos_2 = new Position();
  pos_2->value_ = rot_center_2->value_ + Vector2f(R, 0);

  AngularVelocity* ang_vel_1 = new AngularVelocity();
  AngularVelocity* ang_vel_2 = new AngularVelocity();
  ang_vel_1->value_ = ang_vel_2->value_ = omega;

  LinearVelocity* lin_vel_1 = new LinearVelocity();
  LinearVelocity* lin_vel_2 = new LinearVelocity();

  Radius* radius_1 = new Radius();
  Radius* radius_2 = new Radius();
  radius_1->value_ = radius_2->value_ = r;

  CircleGraphicsComponent* graph_1 = new CircleGraphicsComponent();
  graph_1->circle_ = FloatCircle(pos_1->value_, r);
  graph_1->color_ = ColorBGRA(255, 255, 255, 0);

  CircleGraphicsComponent* graph_2 = new CircleGraphicsComponent();
  graph_2->circle_ = FloatCircle(pos_2->value_, r);
  graph_2->color_ = ColorBGRA(255, 255, 255, 0);

  *(spinning_[0].GetRotationCenter()) = rot_center_1;
  *(spinning_[0].GetPosition()) = pos_1;
  *(spinning_[0].GetAngularVelocity()) = ang_vel_1;
  *(spinning_[0].GetLinearVelocity()) = lin_vel_1;
  *(spinning_[0].GetRadius()) = radius_1;
  *(spinning_[0].GetGraphicsComponent()) = graph_1;

  *(spinning_[1].GetRotationCenter()) = rot_center_2;
  *(spinning_[1].GetPosition()) = pos_2;
  *(spinning_[1].GetAngularVelocity()) = ang_vel_2;
  *(spinning_[1].GetLinearVelocity()) = lin_vel_2;
  *(spinning_[1].GetRadius()) = radius_2;
  *(spinning_[1].GetGraphicsComponent()) = graph_2;

  Position* pos_f = new Position();
  pos_f->value_ = Vector2f(20, SCREEN_HEIGHT / 2);

  LinearVelocity* lin_vel_f = new LinearVelocity();
  lin_vel_f->value_ = Vector2f(10 * r, 0);

  Radius* radius_f = new Radius();
  radius_f->value_ = r;

  CircleGraphicsComponent* graph_f = new CircleGraphicsComponent();
  graph_f->circle_ = FloatCircle(pos_f->value_, r);
  graph_f->color_ = ColorBGRA(0, 0, 255, 0);

  *(flying_.GetPosition()) = pos_f;
  *(flying_.GetLinearVelocity()) = lin_vel_f;
  *(flying_.GetRadius()) = radius_f;
  *(flying_.GetGraphicsComponent()) = graph_f;
}

std::vector<Entity>& EntityManager::GetSpinning() {
  return spinning_;
}

Entity& EntityManager::GetFlying() {
  return flying_;
}

void EntityManager::Draw() {
  for (size_t i = 0; i < 2; ++i) {
    (*spinning_[i].GetGraphicsComponent())->Draw();
  }
  (*flying_.GetGraphicsComponent())->Draw();
}

size_t EntityManager::Score() const {
  return score_;
}