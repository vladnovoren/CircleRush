#ifndef ENTITY_MANAGER_HPP
#define ENTITY_MANAGER_HPP

#include <vector>
#include "Entity.hpp"
#include "Engine.h"
#include <cassert>

class EntityManager {
 public:
  static EntityManager& GetInstance();

  std::vector<Entity>& GetSpinning();

  Entity& GetFlying();

  void InitFlying();

  void Draw();

  size_t Score() const;

 private:
  EntityManager();

 private:
  std::vector<Entity> spinning_;
  Entity flying_;

  size_t score_ = 0;

};

#endif /* EntityManager.hpp */
