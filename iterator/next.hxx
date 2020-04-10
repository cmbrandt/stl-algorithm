// next.hxx

#ifndef NEXT_HXX
#define NEXT_HXX

#include <iterator>
#include "advance.hxx"


namespace nag {

  template <class I> // I models InputIterator
  inline I next(I i, typename std::iterator_traits<I>::difference_type n = 1 )
  {
    nag::advance(i, n);
    return i;
  }

} // namespace cmb


#endif