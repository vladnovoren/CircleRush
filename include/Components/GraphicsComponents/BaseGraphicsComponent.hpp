#ifndef BASE_GRAPHICS_COMPONENT_HPP
#define BASE_GRAPHICS_COMPONENT_HPP

#include "BaseComponent.hpp"
#include "GraphicsSystem.hpp"

enum class GraphicsComponentType {
  CIRCLE
};

class BaseGraphicsComponent : public BaseComponent {
 public:
  BaseGraphicsComponent() = default;
  virtual ~BaseGraphicsComponent() = 0;

  virtual void Draw() = 0;

};

#endif /* BaseGraphicsComponent.hpp */
