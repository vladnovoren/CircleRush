#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include <iostream>
#include <cmath>

template<typename T>
class Vector2 {
 public:
// constructors
  Vector2() {}

  Vector2(T x, T y) : x_(x), y_(y) {
  }

  Vector2(const Vector2& other_copy) :
    x_(other_copy.x_), y_(other_copy.y_) {}

  template<typename OtherT>
  Vector2(const Vector2<OtherT>& other_copy) :
    x_(other_copy.x_), y_(other_copy.y_) {}
  
  Vector2(Vector2&& other_move) :
    x_(other_move.x_), y_(other_move.y_) {
  }

  template<typename OtherT>
  Vector2(Vector2<OtherT>&& other_move) :
    x_(other_move.x_), y_(other_move.y_) {
  }

  Vector2& operator=(const Vector2& other_copy) {
    if (this == &other_copy) {
      return *this;
    }

    x_ = other_copy.x_;
    y_ = other_copy.y_;

    return *this;
  }

  template<typename OtherT>
  Vector2& operator=(const Vector2<OtherT>& other_copy) {
    x_ = other_copy.x_;
    y_ = other_copy.y_;

    return *this;
  }

  Vector2& operator=(Vector2&& other_move) {
    if (this == &other_move) {
      return *this;
    }

    x_ = other_move.x_;
    y_ = other_move.y_;

    return *this;
  }

  template<typename OtherT>
  Vector2& operator=(Vector2<OtherT>&& other_move) {
    x_ = other_move.x_;
    y_ = other_move.y_;

    return *this;
  }

  ~Vector2() {}

  double Length() const {
    return sqrt(x_ * x_ + y_ * y_);
  }

  Vector2 GetProjection(const Vector2& direction) {
    Vector2 dir_normalized = direction;
    dir_normalized.Normalize();
    return dir_normalized * (*this * dir_normalized);
  }

  void Normalize() {
    double length = Length();
    if (length) {
      x_ /= length;
      y_ /= length;
    }
  }

  void Resize(double new_length) {
    Normalize();
    (*this) *= new_length;
  }

  void Reflect(const Vector2& normal) {
    (*this) = 2 * (normal * *this) * normal - (*this);
  }

  double Angle() const {
    return atan2(y_, x_);
  }

  void Rotate(const double d_phi) {
    double length = Length();
    double angle = Angle() + d_phi;
    x_ = cos(angle) * length;
    y_ = sin(angle) * length;
  }

  template<typename OtherT>
  Vector2& operator+=(const Vector2<OtherT>& right) {
    x_ += right.x_;
    y_ += right.y_;
    return *this;
  }

  template<typename OtherT>
  Vector2& operator-=(const Vector2<OtherT>& right) {
    x_ -= right.x_;
    y_ -= right.y_;
    return *this;
  }

  template<typename OtherT>
  Vector2& operator*=(const OtherT scalar) {
    x_ *= scalar;
    y_ *= scalar;
    return *this;
  }

  Vector2 operator-() const {
    return Vector2(-x_, -y_);
  }

  bool operator==(const Vector2& right) const {
    return x_ == right.x_ && y_ == right.y_;
  }

  template<typename OtherT>
  Vector2 operator+(const Vector2<OtherT>& right) const {
    return Vector2(
      x_ + right.x_,
      y_ + right.y_
    );
  }

  template<typename OtherT>
  Vector2 operator-(const Vector2<OtherT>& right) const {
    return Vector2(
      x_ - right.x_,
      y_ - right.y_
    );
  }

  Vector2 operator * (const double scalar) const {
    return Vector2(
      x_ * scalar,
      y_ * scalar
    );
  }

  double operator*(const Vector2& right) const {
    return x_ * right.x_ +
           y_ * right.y_;
  }

  void Print() const {
    std::cout << "x: " << x_ << ", y: " << y_ << '\n';
  }

 public:
  T x_ = 0;
  T y_ = 0;
  
};

template<typename T>
Vector2<T> operator * (const double scalar, const Vector2<T>& vector) {
  Vector2<T> res = vector;
  res *= scalar;
  return res;
}

template<typename T>
double Vector2Cos(const Vector2<T>& first, const Vector2<T>& second) {
  T numerator = first * second;
  if (!numerator)
    return 0;
  return numerator / (first.Length() * second.Length());
}

template<typename T>
double Vector2Sin(const Vector2<T>& first, const Vector2<T>& second) {
  T cos = Vector2Cos(first, second);
  return sqrt(1 - cos * cos);
}

typedef Vector2<double> Vector2d;
typedef Vector2<float> Vector2f;
typedef Vector2<int> Vector2i;

#endif /* Vector2.hpp */
