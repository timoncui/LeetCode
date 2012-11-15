#include <functional>

namespace jcui {
namespace algorithm {

// Return first location where comp(a, b) is not true.
template<class ForwardIterator1, class ForwardIterator2, class Compare>
ForwardIterator1 lower_bound(ForwardIterator1 begin1,
			     ForwardIterator1 end1,
			     ForwardIterator2 begin2,
			     ForwardIterator2 end2,
			     Compare comp) {
  int len = end1 - begin1;
  while (len > 0) {
    int half = len >> 1;
    ForwardIterator1 m1 = begin1 + half;
    ForwardIterator2 m2 = begin2 + half;
    if (comp(*m1, *m2)) {
      begin1 = m1 + 1;
      begin2 = m2 + 1;
      len -= (half + 1);
    } else {
      len = half;
    }
  }
  return begin1;
}

// Return min_x max(inc[x], dec[x]) where inc and dec are non-decreasing and non-increasing   
template<class T, class ForwardIterator1, class ForwardIterator2> 
T min_max(ForwardIterator1 inc_begin,
	  ForwardIterator1 inc_end,
	  ForwardIterator2 dec_begin,
	  ForwardIterator2 dec_end,
	  T default_value) {
  int len = inc_end - inc_begin;
  if (len == 0) return default_value;
  ForwardIterator1 it = lower_bound(inc_begin, inc_end, dec_begin, dec_end, std::less<T>());
  if (it == inc_begin) return *inc_begin;
  if (it == inc_end) return *(dec_begin + len - 1);
  return min(*it, *(dec_begin + (it - inc_begin - 1)));
}


} // namespace algorithm
} // namespace jcui
