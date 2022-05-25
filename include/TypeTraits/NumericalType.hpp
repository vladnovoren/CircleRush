#ifndef NUMERICAL_TYPE_HPP
#define NUMERICAL_TYPE_HPP

template<typename T>
struct NumericalType {

// constructors & assignment

  NumericalType() = default;

  NumericalType(const T value) : value_(value) {}

  template<typename OtherT>
  NumericalType(const OtherT value) : value_(value) {}

  NumericalType(const NumericalType& other_copy) :
    value_(other_copy.value_) {}
  
  template<typename OtherT>
  NumericalType(const NumericalType<OtherT>& other_copy) :
    value_(other_copy.value_) {}

  NumericalType& operator=(const NumericalType& other_copy) {
    value_ = other_copy.value_;

    return *this;
  }

  template<typename OtherT>
  NumericalType& operator=(const NumericalType<OtherT>& other_copy) {
    value_ = other_copy.value_;

    return *this;
  }

// operators
  NumericalType& operator+=(const NumericalType& other) {
    value_ += other.value_;
  }

  template<typename OtherT>
  NumericalType& operator+=(const NumericalType<OtherT>& other) {
    value_ += other.value_;
  }

  NumericalType& operator-=(const NumericalType& other) {
    value_ -= other.value_;
  }

  template<typename OtherT>
  NumericalType& operator-=(const NumericalType<OtherT>& other) {
    value_ -= other.value_;
  }

  NumericalType& operator*=(const NumericalType& other) {
    value_ *= other;
  }

  template<typename OtherT>
  NumericalType& operator*=(const NumericalType<OtherT>& other) {
    value_ *= other;
  }

  NumericalType& operator/=(const NumericalType& other) {
    value_ /= other;
  }

  template<typename OtherT>
  NumericalType& operator/=(const NumericalType<OtherT>& other) {
    value_ /= other;
  }

  NumericalType operator-() const {
    return NumericalType(-value_);
  }

  operator T() const {
    return value_;
  }

  T value_;

};

#endif /* NumericalType.hpp */
