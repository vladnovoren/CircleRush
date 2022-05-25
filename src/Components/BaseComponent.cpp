#include "BaseComponent.hpp"

BaseComponent::~BaseComponent() {}

size_t CompId(const ComponentType type) {
  return static_cast<size_t>(type);
}
