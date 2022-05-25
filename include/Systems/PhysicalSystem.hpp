#ifndef PHYSICAL_SYSTEM_HPP
#define PHYSICAL_SYSTEM_HPP

#include "CoordSystem.hpp"

class PhysicalSystem {
 public:
  PhysicalSystem& GetInstance();

 private:
  PhysicalSystem();

};


#endif /* PhysicalSystem.hpp */
