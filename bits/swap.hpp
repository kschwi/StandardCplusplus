#pragma once

#include <iterator>

#undef swap

namespace std
{

template <class T>
void swap(T &a, T &b)
{
	T temp(a);
	a = b;
	b = temp;
}

template <class ForwardIterator1, class ForwardIterator2>
_UCXXEXPORT
	ForwardIterator2
	swap_ranges(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2)
{
	while (first1 != last1)
	{
		iter_swap(first1, first2);
		++first1;
		++first2;
	}
	return first2;
}

template <class ForwardIterator1, class ForwardIterator2>
void
iter_swap(ForwardIterator1 a, ForwardIterator2 b)
{
	typename iterator_traits<ForwardIterator1>::value_type temp(*a);
	*a = *b;
	*b = temp;
}
}