#ifndef PHYSICAL_SYSTEM_HPP
#define PHYSICAL_SYSTEM_HPP

#include "CoordSystem.hpp"
#include "EntityManager.hpp"

class PhysicalSystem {
 public:
  static PhysicalSystem& GetInstance();

  bool Step(const double dt);

  void CheckFlying();

  bool CollideAll();
  void MoveAll(const double dt);

  bool CirclesIntersect(const FloatCircle& a, const FloatCircle& b);

  void ChangeDirOne(Entity& ent);

  void ChangeDir();

 private:
  PhysicalSystem();

};

#endif /* PhysicalSystem.hpp */
