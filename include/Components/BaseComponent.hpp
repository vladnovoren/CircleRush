#ifndef BASE_COMPONENT_HPP
#define BASE_COMPONENT_HPP

#include <cstddef>

class BaseComponent {
 public:
  virtual ~BaseComponent() = 0;

};

enum class ComponentType {
  POSITION,
  LINEAR_VELOCITY,
  ANGULAR_VELOCITY,
  ROTATION_CENTER,
  RADIUS,
  CIRCLE_GRAPHICS_COMPONENT,

  COMPONENTS_CNT

};

size_t CompId(const ComponentType type);

#endif /* BaseComponent.hpp */
