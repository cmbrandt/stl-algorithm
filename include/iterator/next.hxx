// next.hxx

#ifndef NEXT_HXX
#define NEXT_HXX

#include <iterator>
#include "advance.hxx"


namespace cmb {


  template <class I> // I models InputIterator
  constexpr inline I
  next(I it, typename std::iterator_traits<I>::difference_type n = 1 )
  {
    cmb::advance(it, n);
    return it;
  }


} // namespace cmb


#endif