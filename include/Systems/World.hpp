#ifndef WORLD_HPP
#define WORLD_HPP

#include "CoordSystem.hpp"
#include "Engine.h"

class World {
 public:
  static World& GetInstance();
  
  const CoordSystem& GetCoordSystem() const;

 private:
  World();

  CoordSystem coord_system_;

};

#endif /* World.hpp */