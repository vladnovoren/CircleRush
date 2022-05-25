#include "World.hpp"

World& World::GetInstance() {
  static World world;
  return world;
}

const CoordSystem& World::GetCoordSystem() const {
  return coord_system_;
}

World::World() :
    coord_system_(
      Vector2i(0, SCREEN_HEIGHT),
      IntRanges(0, SCREEN_WIDTH),
      IntRanges(0, SCREEN_HEIGHT),
      1
    ) {
}