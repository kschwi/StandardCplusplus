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

// const-volatile modifications.

/// remove_const
template <typename _Tp>
struct remove_const
{
	typedef _Tp type;
};

template <typename _Tp>
struct remove_const<_Tp const>
{
	typedef _Tp type;
};

/// remove_volatile
template <typename _Tp>
struct remove_volatile
{
	typedef _Tp type;
};

template <typename _Tp>
struct remove_volatile<_Tp volatile>
{
	typedef _Tp type;
};

/// remove_cv
template <typename _Tp>
struct remove_cv
{
	typedef typename remove_const<typename remove_volatile<_Tp>::type>::type type;
};

// A conditional expression, but for types. If true, first, if false, second.
// Primary template.
/// conditional
template <bool _Cond, typename _Iftrue, typename _Iffalse>
struct conditional
{
	typedef _Iftrue type;
};

// Partial specialization for false.
template <typename _Iftrue, typename _Iffalse>
struct conditional<false, _Iftrue, _Iffalse>
{
	typedef _Iffalse type;
};

/// is_same
template<class T, class U>
struct is_same : std::false_type {};
 
template<class T>
struct is_same<T, T> : std::true_type {};

/// is_integral
template <class I>
class __is_integer
{
public:
	typedef false_type value;
};

template <>
class __is_integer<unsigned int>
{
public:
	typedef true_type value;
};

template <>
class __is_integer<signed int>
{
public:
	typedef true_type value;
};

template <>
class __is_integer<short unsigned int>
{
public:
	typedef true_type value;
};

template <>
class __is_integer<short signed int>
{
public:
	typedef true_type value;
};

template <>
class __is_integer<char>
{
public:
	typedef true_type value;
};

template <>
class __is_integer<signed char>
{
public:
	typedef true_type value;
};

template <>
class __is_integer<unsigned char>
{
public:
	typedef true_type value;
};

template <>
class __is_integer<long unsigned int>
{
public:
	typedef true_type value;
};

template <>
class __is_integer<long signed int>
{
public:
	typedef true_type value;
};

namespace detail {

	template <class _Tp> struct __libcpp_is_integral                     : public false_type {};
	template <>          struct __libcpp_is_integral<bool>               : public true_type {};
	template <>          struct __libcpp_is_integral<char>               : public true_type {};
	template <>          struct __libcpp_is_integral<signed char>        : public true_type {};
	template <>          struct __libcpp_is_integral<unsigned char>      : public true_type {};
	template <>          struct __libcpp_is_integral<wchar_t>            : public true_type {};
	template <>          struct __libcpp_is_integral<char16_t>           : public true_type {};
	template <>          struct __libcpp_is_integral<char32_t>           : public true_type {};
	template <>          struct __libcpp_is_integral<short>              : public true_type {};
	template <>          struct __libcpp_is_integral<unsigned short>     : public true_type {};
	template <>          struct __libcpp_is_integral<int>                : public true_type {};
	template <>          struct __libcpp_is_integral<unsigned int>       : public true_type {};
	template <>          struct __libcpp_is_integral<long>               : public true_type {};
	template <>          struct __libcpp_is_integral<unsigned long>      : public true_type {};
	template <>          struct __libcpp_is_integral<long long>          : public true_type {};
	template <> struct __libcpp_is_integral<unsigned long long> : public true_type {};

} // detail

template<typename T>
struct is_integral: detail::__libcpp_is_integral<typename remove_cv<T>::type> {};

}