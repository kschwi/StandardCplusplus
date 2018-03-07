#pragma once

namespace std {

/// void_t
template< class... >
using void_t = void;


/// Integral constant
template <class T, T v>
struct integral_constant
{
	static constexpr T value = v;
	typedef T value_type;
	typedef integral_constant type; // using injected-class-name
	constexpr operator value_type() const noexcept { return value; }
	constexpr value_type operator()() const noexcept { return value; } //since c++14
};

template <bool B>
using bool_constant = integral_constant<bool, B>;

/// typedef for true_type
typedef bool_constant<true> true_type;

/// typedef for false_type
typedef bool_constant<false> false_type;

/// is_lvalue_reference
template <typename>
struct is_lvalue_reference : public false_type
{
};

template <typename _Tp>
struct is_lvalue_reference<_Tp &> : public true_type
{
};

/// is_rvalue_reference
template <typename>
struct is_rvalue_reference : public false_type
{
};

template <typename _Tp>
struct is_rvalue_reference<_Tp &&> : public true_type
{
};

}