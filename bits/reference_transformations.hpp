#pragma once

namespace std {

	template <typename T>
	struct is_reference;

	template <class T>
	struct remove_reference { typedef T type; };

	template <class T>
	struct remove_reference<T&> { typedef T type; };

	template <class T>
	struct remove_reference<T&&> { typedef T type; };
}