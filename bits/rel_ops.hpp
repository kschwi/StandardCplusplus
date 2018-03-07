#pragma once

namespace std {

namespace rel_ops {
	template<class T> inline bool operator!=(const T& x, const T& y){
		return !(x == y);
	}

	template<class T> inline bool operator> (const T& x, const T& y){
		return ( y < x);
	}

	template<class T> inline bool operator<=(const T& x, const T& y){
		return !( y < x );
	}

	template<class T> inline bool operator>=(const T& x, const T& y){
		return !(x < y);
	}
}

}