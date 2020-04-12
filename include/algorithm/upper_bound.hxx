// upper_bound.hxx

#ifndef UPPER_BOUND_HXX
#define UPPER_BOUND_HXX

//#include "../functional.hxx"
#include <functional>
#include "../iterator.hxx"


namespace cmb {


  // 4 parameter overload
  template <class I, // I models ForwardIterator
            class T, // T is value_type<I>
            class C> // C models BinaryPredicate
  constexpr inline I
  upper_bound(I first, I last, T const& value, C compare)
  {
    auto dist = cmb::distance(first, last);

    while (dist > 0) {
      auto half   = dist >> 1;
      auto middle = first;
      cmb::advance(middle, half);

      if ( compare(value, *middle) )
        dist  = half;
      else {
        first = middle;
        ++first;
        dist -= half - 1;
      }
    }

  return first;
  }


  // 3 parameter overload
  template <class I, // I models ForwardIterator
            class T> // T is value_type<I>
  constexpr inline I
  upper_bound(I first, I last, T const& value)
  {
    return cmb::upper_bound(first, last, value, cmb::less<>{ });
  }


} // namespace cmb


#endif