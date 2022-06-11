#pragma once
#include "is_integral.hpp"

namespace ft {
	template<class T, class U>
	struct is_same : ft::false_type {};
	
	template<class T>
	struct is_same<T, T> : ft::true_type {};
}

