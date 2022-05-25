#ifndef PRIMITIVES_HPP
#define PRIMITIVES_HPP

#include "Vector2.hpp"

template<typename T>
struct Rect {
  Vector2<T> position_;
  Vector2<T> size_;

  Rect() = default;

  Rect(const Vector2<T>& position, const Vector2<T>& size):
    position_(position), size_(size) {}

  Rect(const T& position_x, const T& position_y,
       const T& width, const T& height):
    position_(position_x, position_y), size_(width, height) {}

  Rect(const Rect& other_copy) :
    position_(other_copy.position_), size_(other_copy.size_) {}

  template<typename OtherT>
  Rect(const Rect<OtherT>& other_copy) :
    position_(other_copy.position_), size_(other_copy.size_) {}
  
  Rect(Rect&& other_move) :
    position_(other_move.position_), size_(other_move.size_) {}
  
  template<typename OtherT>
  Rect(Rect<OtherT>&& other_move) :
    position_(other_move.position_), size_(other_move.size_) {}
  
  Rect& operator=(const Rect& other_copy) {
    if (this == &other_copy) {
      return *this;
    }

    position_ = other_copy.position_;
    size_ = other_copy.size_;

    return *this;
  }

  template<typename OtherT>
  Rect& operator=(const Rect<OtherT>& other_copy) {
    position_ = other_copy.position_;
    size_ = other_copy.size_;
    
    return *this;
  }

  Rect& operator=(Rect&& other_move) {
    if (this == &other_move) {
      return *this;
    }

    position_ = other_move.position_;
    size_ = other_move.size_;

    return *this;
  }

  template<typename OtherT>
  Rect& operator=(Rect<OtherT>&& other_move) {
    position_ = other_move.position_;
    size_ = other_move.size_;

    return *this;
  }

  bool IsPointInRect(const Vector2<T>& point) const {
    return position_.x < point.x && point.x < position_.x + size_.x &&
           position_.y < point.y && point.y < position_.y + size_.y;
  }
};

template<typename T>
struct Circle {
  Vector2<T> center_;
  T radius_;

  Circle() {}

  Circle(const Vector2<T>& center, const T radius) :
    center_(center), radius_(radius) {}

  Circle(const T center_x, const T center_y, const T radius) :
    Circle(Vector2<T>(center_x, center_y), radius) {}

  Circle(const Circle& other_copy) :
    center_(other_copy.center_), radius_(other_copy.radius_) {}
  
  template<typename OtherT>
  Circle(const Circle<OtherT>& other_copy) :
    center_(other_copy.center_), radius_(other_copy.radius_) {}
  
  Circle(Circle&& other_move) :
    center_(other_move.center_), radius_(other_move.radius_) {}
  
  template<typename OtherT>
  Circle(Circle<OtherT>&& other_move) :
    center_(other_move.center_), radius_(other_move.radius_) {}

  Circle& operator=(const Circle& other_copy) {
    if (this == &other_copy) {
      return *this;
    }

    center_ = other_copy.center_;
    radius_ = other_copy.radius_;

    return *this;
  }

  template<typename OtherT>
  Circle& operator=(const Circle<OtherT>& other_copy) {
    center_ = other_copy.center_;
    radius_ = other_copy.radius_;

    return *this;
  }

  Circle& operator=(Circle&& other_move) {
    if (this == &other_move) {
      return *this;
    }

    center_ = other_move.center_;
    radius_ = other_move.radius_;

    return *this;
  }

  template<typename OtherT>
  Circle& operator=(Circle<OtherT>&& other_move) {
    center_ = other_move.center_;
    radius_ = other_move.radius_;

    return *this;
  }

  bool IsPointInside(const T x, const T y) const {
    return (center_.x_ - x) * (center_.x_ - x) +
           (center_.y_ - y) * (center_.y_ - y) <=
            radius_ * radius_;
  }

  bool IsPointInside(const Vector2<T>& point) const {
    return IsPointInside(point.x_, point.y_);
  }

};

using IntRect   = Rect<int>;
using UIntRect  = Rect<unsigned int>;
using FloatRect = Rect<float>;

using IntCircle   = Circle<int>;
using UIntCircle  = Circle<unsigned int>;
using FloatCircle = Circle<float>;

#endif /* Primitives.hpp */
