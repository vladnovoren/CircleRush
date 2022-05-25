#include "PhysicalSystem.hpp"

PhysicalSystem& PhysicalSystem::GetInstance() {
  static PhysicalSystem instance;
  return instance;
}

PhysicalSystem::PhysicalSystem() {
}
