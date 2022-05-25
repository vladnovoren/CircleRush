#ifndef RANGES_HPP
#define RANGES_HPP

template<typename T>
struct Ranges {
  T min_ = 0;
  T max_ = 0;

  Ranges() {}

  Ranges(const T min, const T max) :
    min_(min), max_(max) {
  }
};

using FloatRanges = Ranges<float>;
using IntRanges   = Ranges<int>;
using UIntRanges  = Ranges<unsigned>;

#endif /* ranges.hpp */
